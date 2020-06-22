Object.defineProperty(exports, "__esModule", { value: true });
var frame_common_1 = require("./frame-common");
var transition_1 = require("../transition/transition");
var flip_transition_1 = require("../transition/flip-transition");
var animation_1 = require("../animation");
var lazy_1 = require("../../utils/lazy");
var trace_1 = require("../../trace");
var defaultInterpolator = lazy_1.default(function () { return new android.view.animation.AccelerateDecelerateInterpolator(); });
var animFadeIn = 17432576;
var animFadeOut = 17432577;
exports.waitingQueue = new Map();
exports.completedEntries = new Map();
var TransitionListener;
var AnimationListener;
function _setAndroidFragmentTransitions(animated, navigationTransition, currentEntry, newEntry, frameId, fragmentTransaction, isNestedDefaultTransition) {
    var currentFragment = currentEntry ? currentEntry.fragment : null;
    var newFragment = newEntry.fragment;
    var entries = exports.waitingQueue.get(frameId);
    if (entries && entries.size > 0) {
        throw new Error("Calling navigation before previous navigation finish.");
    }
    allowTransitionOverlap(currentFragment);
    allowTransitionOverlap(newFragment);
    var name = "";
    var transition;
    if (navigationTransition) {
        transition = navigationTransition.instance;
        name = navigationTransition.name ? navigationTransition.name.toLowerCase() : "";
    }
    if (!animated) {
        name = "none";
    }
    else if (transition) {
        name = "custom";
    }
    else if (name.indexOf("slide") !== 0 && name !== "fade" && name.indexOf("flip") !== 0 && name.indexOf("explode") !== 0) {
        name = "default";
    }
    var currentFragmentNeedsDifferentAnimation = false;
    if (currentEntry) {
        _updateTransitions(currentEntry);
        if (currentEntry.transitionName !== name ||
            currentEntry.transition !== transition || isNestedDefaultTransition) {
            clearExitAndReenterTransitions(currentEntry, true);
            currentFragmentNeedsDifferentAnimation = true;
        }
    }
    if (name === "none") {
        var noTransition = new NoTransition(0, null);
        if (isNestedDefaultTransition) {
            fragmentTransaction.setCustomAnimations(animFadeIn, animFadeOut);
            setupAllAnimation(newEntry, noTransition);
            setupNewFragmentCustomTransition({ duration: 0, curve: null }, newEntry, noTransition);
        }
        else {
            setupNewFragmentCustomTransition({ duration: 0, curve: null }, newEntry, noTransition);
        }
        newEntry.isNestedDefaultTransition = isNestedDefaultTransition;
        if (currentFragmentNeedsDifferentAnimation) {
            setupCurrentFragmentCustomTransition({ duration: 0, curve: null }, currentEntry, noTransition);
        }
    }
    else if (name === "custom") {
        setupNewFragmentCustomTransition({ duration: transition.getDuration(), curve: transition.getCurve() }, newEntry, transition);
        if (currentFragmentNeedsDifferentAnimation) {
            setupCurrentFragmentCustomTransition({ duration: transition.getDuration(), curve: transition.getCurve() }, currentEntry, transition);
        }
    }
    else if (name === "default") {
        setupNewFragmentFadeTransition({ duration: 150, curve: null }, newEntry);
        if (currentFragmentNeedsDifferentAnimation) {
            setupCurrentFragmentFadeTransition({ duration: 150, curve: null }, currentEntry);
        }
    }
    else if (name.indexOf("slide") === 0) {
        setupNewFragmentSlideTransition(navigationTransition, newEntry, name);
        if (currentFragmentNeedsDifferentAnimation) {
            setupCurrentFragmentSlideTransition(navigationTransition, currentEntry, name);
        }
    }
    else if (name === "fade") {
        setupNewFragmentFadeTransition(navigationTransition, newEntry);
        if (currentFragmentNeedsDifferentAnimation) {
            setupCurrentFragmentFadeTransition(navigationTransition, currentEntry);
        }
    }
    else if (name === "explode") {
        setupNewFragmentExplodeTransition(navigationTransition, newEntry);
        if (currentFragmentNeedsDifferentAnimation) {
            setupCurrentFragmentExplodeTransition(navigationTransition, currentEntry);
        }
    }
    else if (name.indexOf("flip") === 0) {
        var direction = name.substr("flip".length) || "right";
        var flipTransition = new flip_transition_1.FlipTransition(direction, navigationTransition.duration, navigationTransition.curve);
        setupNewFragmentCustomTransition(navigationTransition, newEntry, flipTransition);
        if (currentFragmentNeedsDifferentAnimation) {
            setupCurrentFragmentCustomTransition(navigationTransition, currentEntry, flipTransition);
        }
    }
    newEntry.transitionName = name;
    if (currentEntry) {
        currentEntry.transitionName = name;
        if (name === "custom") {
            currentEntry.transition = transition;
        }
    }
    printTransitions(currentEntry);
    printTransitions(newEntry);
}
exports._setAndroidFragmentTransitions = _setAndroidFragmentTransitions;
function setupAllAnimation(entry, transition) {
    setupExitAndPopEnterAnimation(entry, transition);
    var listener = getAnimationListener();
    var enterAnimator = transition.createAndroidAnimator(transition_1.AndroidTransitionType.enter);
    enterAnimator.transitionType = transition_1.AndroidTransitionType.enter;
    enterAnimator.entry = entry;
    enterAnimator.addListener(listener);
    entry.enterAnimator = enterAnimator;
    var popExitAnimator = transition.createAndroidAnimator(transition_1.AndroidTransitionType.popExit);
    popExitAnimator.transitionType = transition_1.AndroidTransitionType.popExit;
    popExitAnimator.entry = entry;
    popExitAnimator.addListener(listener);
    entry.popExitAnimator = popExitAnimator;
}
function setupExitAndPopEnterAnimation(entry, transition) {
    var listener = getAnimationListener();
    clearAnimationListener(entry.exitAnimator, listener);
    clearAnimationListener(entry.popEnterAnimator, listener);
    var exitAnimator = transition.createAndroidAnimator(transition_1.AndroidTransitionType.exit);
    exitAnimator.transitionType = transition_1.AndroidTransitionType.exit;
    exitAnimator.entry = entry;
    exitAnimator.addListener(listener);
    entry.exitAnimator = exitAnimator;
    var popEnterAnimator = transition.createAndroidAnimator(transition_1.AndroidTransitionType.popEnter);
    popEnterAnimator.transitionType = transition_1.AndroidTransitionType.popEnter;
    popEnterAnimator.entry = entry;
    popEnterAnimator.addListener(listener);
    entry.popEnterAnimator = popEnterAnimator;
}
function getAnimationListener() {
    if (!AnimationListener) {
        var AnimationListenerImpl = (function (_super) {
            __extends(AnimationListenerImpl, _super);
            function AnimationListenerImpl() {
                var _this = _super.call(this) || this;
                return global.__native(_this);
            }
            AnimationListenerImpl.prototype.onAnimationStart = function (animator) {
                var entry = animator.entry;
                addToWaitingQueue(entry);
                if (trace_1.isEnabled()) {
                    trace_1.write("START " + animator.transitionType + " for " + entry.fragmentTag, trace_1.categories.Transition);
                }
            };
            AnimationListenerImpl.prototype.onAnimationRepeat = function (animator) {
                if (trace_1.isEnabled()) {
                    trace_1.write("REPEAT " + animator.transitionType + " for " + animator.entry.fragmentTag, trace_1.categories.Transition);
                }
            };
            AnimationListenerImpl.prototype.onAnimationEnd = function (animator) {
                if (trace_1.isEnabled()) {
                    trace_1.write("END " + animator.transitionType + " for " + animator.entry.fragmentTag, trace_1.categories.Transition);
                }
                transitionOrAnimationCompleted(animator.entry);
            };
            AnimationListenerImpl.prototype.onAnimationCancel = function (animator) {
                if (trace_1.isEnabled()) {
                    trace_1.write("CANCEL " + animator.transitionType + " for " + animator.entry.fragmentTag, trace_1.categories.Transition);
                }
            };
            AnimationListenerImpl = __decorate([
                Interfaces([android.animation.Animator.AnimatorListener])
            ], AnimationListenerImpl);
            return AnimationListenerImpl;
        }(java.lang.Object));
        AnimationListener = new AnimationListenerImpl();
    }
    return AnimationListener;
}
function clearAnimationListener(animator, listener) {
    if (!animator) {
        return;
    }
    animator.removeListener(listener);
    if (animator.entry && trace_1.isEnabled()) {
        var entry = animator.entry;
        trace_1.write("Clear " + animator.transitionType + " - " + entry.transition + " for " + entry.fragmentTag, trace_1.categories.Transition);
    }
    animator.entry = null;
}
function _getAnimatedEntries(frameId) {
    return exports.waitingQueue.get(frameId);
}
exports._getAnimatedEntries = _getAnimatedEntries;
function _updateTransitions(entry) {
    var fragment = entry.fragment;
    var enterTransitionListener = entry.enterTransitionListener;
    if (enterTransitionListener && fragment) {
        fragment.setEnterTransition(enterTransitionListener.transition);
    }
    var exitTransitionListener = entry.exitTransitionListener;
    if (exitTransitionListener && fragment) {
        fragment.setExitTransition(exitTransitionListener.transition);
    }
    var reenterTransitionListener = entry.reenterTransitionListener;
    if (reenterTransitionListener && fragment) {
        fragment.setReenterTransition(reenterTransitionListener.transition);
    }
    var returnTransitionListener = entry.returnTransitionListener;
    if (returnTransitionListener && fragment) {
        fragment.setReturnTransition(returnTransitionListener.transition);
    }
}
exports._updateTransitions = _updateTransitions;
function _reverseTransitions(previousEntry, currentEntry) {
    var previousFragment = previousEntry.fragment;
    var currentFragment = currentEntry.fragment;
    var transitionUsed = false;
    var returnTransitionListener = currentEntry.returnTransitionListener;
    if (returnTransitionListener) {
        transitionUsed = true;
        currentFragment.setExitTransition(returnTransitionListener.transition);
    }
    else {
        currentFragment.setExitTransition(null);
    }
    var reenterTransitionListener = previousEntry.reenterTransitionListener;
    if (reenterTransitionListener) {
        transitionUsed = true;
        previousFragment.setEnterTransition(reenterTransitionListener.transition);
    }
    else {
        previousFragment.setEnterTransition(null);
    }
    return transitionUsed;
}
exports._reverseTransitions = _reverseTransitions;
function getTransitionListener(entry, transition) {
    if (!TransitionListener) {
        var TransitionListenerImpl = (function (_super) {
            __extends(TransitionListenerImpl, _super);
            function TransitionListenerImpl(entry, transition) {
                var _this = _super.call(this) || this;
                _this.entry = entry;
                _this.transition = transition;
                return global.__native(_this);
            }
            TransitionListenerImpl.prototype.onTransitionStart = function (transition) {
                var entry = this.entry;
                addToWaitingQueue(entry);
                if (trace_1.isEnabled()) {
                    trace_1.write("START " + toShortString(transition) + " transition for " + entry.fragmentTag, trace_1.categories.Transition);
                }
            };
            TransitionListenerImpl.prototype.onTransitionEnd = function (transition) {
                var entry = this.entry;
                if (trace_1.isEnabled()) {
                    trace_1.write("END " + toShortString(transition) + " transition for " + entry.fragmentTag, trace_1.categories.Transition);
                }
                transitionOrAnimationCompleted(entry);
            };
            TransitionListenerImpl.prototype.onTransitionResume = function (transition) {
                if (trace_1.isEnabled()) {
                    var fragment = this.entry.fragmentTag;
                    trace_1.write("RESUME " + toShortString(transition) + " transition for " + fragment, trace_1.categories.Transition);
                }
            };
            TransitionListenerImpl.prototype.onTransitionPause = function (transition) {
                if (trace_1.isEnabled()) {
                    trace_1.write("PAUSE " + toShortString(transition) + " transition for " + this.entry.fragmentTag, trace_1.categories.Transition);
                }
            };
            TransitionListenerImpl.prototype.onTransitionCancel = function (transition) {
                if (trace_1.isEnabled()) {
                    trace_1.write("CANCEL " + toShortString(transition) + " transition for " + this.entry.fragmentTag, trace_1.categories.Transition);
                }
            };
            TransitionListenerImpl = __decorate([
                Interfaces([androidx.transition.Transition.TransitionListener])
            ], TransitionListenerImpl);
            return TransitionListenerImpl;
        }(java.lang.Object));
        TransitionListener = TransitionListenerImpl;
    }
    return new TransitionListener(entry, transition);
}
function addToWaitingQueue(entry) {
    var frameId = entry.frameId;
    var entries = exports.waitingQueue.get(frameId);
    if (!entries) {
        entries = new Set();
        exports.waitingQueue.set(frameId, entries);
    }
    entries.add(entry);
}
function clearExitAndReenterTransitions(entry, removeListener) {
    var fragment = entry.fragment;
    var exitListener = entry.exitTransitionListener;
    if (exitListener) {
        var exitTransition = fragment.getExitTransition();
        if (exitTransition) {
            if (removeListener) {
                exitTransition.removeListener(exitListener);
            }
            fragment.setExitTransition(null);
            if (trace_1.isEnabled()) {
                trace_1.write("Cleared Exit " + exitTransition.getClass().getSimpleName() + " transition for " + fragment, trace_1.categories.Transition);
            }
        }
        if (removeListener) {
            entry.exitTransitionListener = null;
        }
    }
    var reenterListener = entry.reenterTransitionListener;
    if (reenterListener) {
        var reenterTransition = fragment.getReenterTransition();
        if (reenterTransition) {
            if (removeListener) {
                reenterTransition.removeListener(reenterListener);
            }
            fragment.setReenterTransition(null);
            if (trace_1.isEnabled()) {
                trace_1.write("Cleared Reenter " + reenterTransition.getClass().getSimpleName() + " transition for " + fragment, trace_1.categories.Transition);
            }
        }
        if (removeListener) {
            entry.reenterTransitionListener = null;
        }
    }
}
function _clearFragment(entry) {
    clearEntry(entry, false);
}
exports._clearFragment = _clearFragment;
function _clearEntry(entry) {
    clearEntry(entry, true);
}
exports._clearEntry = _clearEntry;
function clearEntry(entry, removeListener) {
    clearExitAndReenterTransitions(entry, removeListener);
    var fragment = entry.fragment;
    var enterListener = entry.enterTransitionListener;
    if (enterListener) {
        var enterTransition = fragment.getEnterTransition();
        if (enterTransition) {
            if (removeListener) {
                enterTransition.removeListener(enterListener);
            }
            fragment.setEnterTransition(null);
            if (trace_1.isEnabled()) {
                trace_1.write("Cleared Enter " + enterTransition.getClass().getSimpleName() + " transition for " + fragment, trace_1.categories.Transition);
            }
        }
        if (removeListener) {
            entry.enterTransitionListener = null;
        }
    }
    var returnListener = entry.returnTransitionListener;
    if (returnListener) {
        var returnTransition = fragment.getReturnTransition();
        if (returnTransition) {
            if (removeListener) {
                returnTransition.removeListener(returnListener);
            }
            fragment.setReturnTransition(null);
            if (trace_1.isEnabled()) {
                trace_1.write("Cleared Return " + returnTransition.getClass().getSimpleName() + " transition for " + fragment, trace_1.categories.Transition);
            }
        }
        if (removeListener) {
            entry.returnTransitionListener = null;
        }
    }
}
function allowTransitionOverlap(fragment) {
    if (fragment) {
        fragment.setAllowEnterTransitionOverlap(true);
        fragment.setAllowReturnTransitionOverlap(true);
    }
}
function setEnterTransition(navigationTransition, entry, transition) {
    setUpNativeTransition(navigationTransition, transition);
    var listener = addNativeTransitionListener(entry, transition);
    entry.enterTransitionListener = listener;
    var fragment = entry.fragment;
    fragment.setEnterTransition(transition);
}
function setExitTransition(navigationTransition, entry, transition) {
    setUpNativeTransition(navigationTransition, transition);
    var listener = addNativeTransitionListener(entry, transition);
    entry.exitTransitionListener = listener;
    var fragment = entry.fragment;
    fragment.setExitTransition(transition);
}
function setReenterTransition(navigationTransition, entry, transition) {
    setUpNativeTransition(navigationTransition, transition);
    var listener = addNativeTransitionListener(entry, transition);
    entry.reenterTransitionListener = listener;
    var fragment = entry.fragment;
    fragment.setReenterTransition(transition);
}
function setReturnTransition(navigationTransition, entry, transition) {
    setUpNativeTransition(navigationTransition, transition);
    var listener = addNativeTransitionListener(entry, transition);
    entry.returnTransitionListener = listener;
    var fragment = entry.fragment;
    fragment.setReturnTransition(transition);
}
function setupNewFragmentSlideTransition(navTransition, entry, name) {
    setupCurrentFragmentSlideTransition(navTransition, entry, name);
    var direction = name.substr("slide".length) || "left";
    switch (direction) {
        case "left":
            setEnterTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.RIGHT));
            setReturnTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.RIGHT));
            break;
        case "right":
            setEnterTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.LEFT));
            setReturnTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.LEFT));
            break;
        case "top":
            setEnterTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.BOTTOM));
            setReturnTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.BOTTOM));
            break;
        case "bottom":
            setEnterTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.TOP));
            setReturnTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.TOP));
            break;
    }
}
function setupCurrentFragmentSlideTransition(navTransition, entry, name) {
    var direction = name.substr("slide".length) || "left";
    switch (direction) {
        case "left":
            setExitTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.LEFT));
            setReenterTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.LEFT));
            break;
        case "right":
            setExitTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.RIGHT));
            setReenterTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.RIGHT));
            break;
        case "top":
            setExitTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.TOP));
            setReenterTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.TOP));
            break;
        case "bottom":
            setExitTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.BOTTOM));
            setReenterTransition(navTransition, entry, new androidx.transition.Slide(android.view.Gravity.BOTTOM));
            break;
    }
}
function setupCurrentFragmentCustomTransition(navTransition, entry, transition) {
    var exitAnimator = transition.createAndroidAnimator(transition_1.AndroidTransitionType.exit);
    var exitTransition = new org.nativescript.widgets.CustomTransition(exitAnimator, transition.constructor.name + transition_1.AndroidTransitionType.exit.toString());
    setExitTransition(navTransition, entry, exitTransition);
    var reenterAnimator = transition.createAndroidAnimator(transition_1.AndroidTransitionType.popEnter);
    var reenterTransition = new org.nativescript.widgets.CustomTransition(reenterAnimator, transition.constructor.name + transition_1.AndroidTransitionType.popEnter.toString());
    setReenterTransition(navTransition, entry, reenterTransition);
}
function setupNewFragmentCustomTransition(navTransition, entry, transition) {
    setupCurrentFragmentCustomTransition(navTransition, entry, transition);
    var enterAnimator = transition.createAndroidAnimator(transition_1.AndroidTransitionType.enter);
    var enterTransition = new org.nativescript.widgets.CustomTransition(enterAnimator, transition.constructor.name + transition_1.AndroidTransitionType.enter.toString());
    setEnterTransition(navTransition, entry, enterTransition);
    var returnAnimator = transition.createAndroidAnimator(transition_1.AndroidTransitionType.popExit);
    var returnTransition = new org.nativescript.widgets.CustomTransition(returnAnimator, transition.constructor.name + transition_1.AndroidTransitionType.popExit.toString());
    setReturnTransition(navTransition, entry, returnTransition);
}
function setupNewFragmentFadeTransition(navTransition, entry) {
    setupCurrentFragmentFadeTransition(navTransition, entry);
    var fadeInEnter = new androidx.transition.Fade(androidx.transition.Fade.IN);
    setEnterTransition(navTransition, entry, fadeInEnter);
    var fadeOutReturn = new androidx.transition.Fade(androidx.transition.Fade.OUT);
    setReturnTransition(navTransition, entry, fadeOutReturn);
}
function setupCurrentFragmentFadeTransition(navTransition, entry) {
    var fadeOutExit = new androidx.transition.Fade(androidx.transition.Fade.OUT);
    setExitTransition(navTransition, entry, fadeOutExit);
    var fadeInReenter = new androidx.transition.Fade(androidx.transition.Fade.IN);
    setReenterTransition(navTransition, entry, fadeInReenter);
}
function setupCurrentFragmentExplodeTransition(navTransition, entry) {
    setExitTransition(navTransition, entry, new androidx.transition.Explode());
    setReenterTransition(navTransition, entry, new androidx.transition.Explode());
}
function setupNewFragmentExplodeTransition(navTransition, entry) {
    setupCurrentFragmentExplodeTransition(navTransition, entry);
    setEnterTransition(navTransition, entry, new androidx.transition.Explode());
    setReturnTransition(navTransition, entry, new androidx.transition.Explode());
}
function setUpNativeTransition(navigationTransition, nativeTransition) {
    if (navigationTransition.duration) {
        nativeTransition.setDuration(navigationTransition.duration);
    }
    var interpolator = navigationTransition.curve ? animation_1._resolveAnimationCurve(navigationTransition.curve) : defaultInterpolator();
    nativeTransition.setInterpolator(interpolator);
}
function addNativeTransitionListener(entry, nativeTransition) {
    var listener = getTransitionListener(entry, nativeTransition);
    nativeTransition.addListener(listener);
    return listener;
}
exports.addNativeTransitionListener = addNativeTransitionListener;
function transitionOrAnimationCompleted(entry) {
    var frameId = entry.frameId;
    var entries = exports.waitingQueue.get(frameId);
    if (!entries) {
        return;
    }
    entries.delete(entry);
    if (entries.size === 0) {
        var frame_1 = entry.resolvedPage.frame;
        var previousCompletedAnimationEntry = exports.completedEntries.get(frameId);
        exports.completedEntries.delete(frameId);
        exports.waitingQueue.delete(frameId);
        var navigationContext_1 = frame_1._executingContext || { navigationType: frame_common_1.NavigationType.back };
        var current_1 = frame_1.isCurrent(entry) ? previousCompletedAnimationEntry : entry;
        current_1 = current_1 || entry;
        if (current_1) {
            setTimeout(function () { return frame_1.setCurrent(current_1, navigationContext_1.navigationType); });
        }
    }
    else {
        exports.completedEntries.set(frameId, entry);
    }
}
function toShortString(nativeTransition) {
    return nativeTransition.getClass().getSimpleName() + "@" + nativeTransition.hashCode().toString(16);
}
function printTransitions(entry) {
    if (entry && trace_1.isEnabled()) {
        var result = entry.fragmentTag + " Transitions:";
        if (entry.transitionName) {
            result += "transitionName=" + entry.transitionName + ", ";
        }
        var fragment = entry.fragment;
        result += "" + (fragment.getEnterTransition() ? " enter=" + toShortString(fragment.getEnterTransition()) : "");
        result += "" + (fragment.getExitTransition() ? " exit=" + toShortString(fragment.getExitTransition()) : "");
        result += "" + (fragment.getReenterTransition() ? " popEnter=" + toShortString(fragment.getReenterTransition()) : "");
        result += "" + (fragment.getReturnTransition() ? " popExit=" + toShortString(fragment.getReturnTransition()) : "");
        trace_1.write(result, trace_1.categories.Transition);
    }
}
function javaObjectArray() {
    var params = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        params[_i] = arguments[_i];
    }
    var nativeArray = Array.create(java.lang.Object, params.length);
    params.forEach(function (value, i) { return nativeArray[i] = value; });
    return nativeArray;
}
function createDummyZeroDurationAnimator(duration) {
    var animatorSet = new android.animation.AnimatorSet();
    var objectAnimators = Array.create(android.animation.Animator, 1);
    var values = Array.create("float", 2);
    values[0] = 0.0;
    values[1] = 1.0;
    var animator = android.animation.ObjectAnimator.ofFloat(null, "alpha", values);
    animator.setDuration(duration);
    objectAnimators[0] = animator;
    animatorSet.playTogether(objectAnimators);
    return animatorSet;
}
var NoTransition = (function (_super) {
    __extends(NoTransition, _super);
    function NoTransition() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    NoTransition.prototype.createAndroidAnimator = function (transitionType) {
        return createDummyZeroDurationAnimator(this.getDuration());
    };
    return NoTransition;
}(transition_1.Transition));
//# sourceMappingURL=fragment.transitions.android.js.map