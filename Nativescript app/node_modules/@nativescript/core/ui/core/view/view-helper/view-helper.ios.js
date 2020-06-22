function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var view_helper_common_1 = require("./view-helper-common");
var utils_1 = require("../../../../utils/utils");
var trace_1 = require("../../../../trace");
__export(require("./view-helper-common"));
var majorVersion = utils_1.ios.MajorVersion;
var ios;
(function (ios) {
    ios.traitCollectionColorAppearanceChangedEvent = "traitCollectionColorAppearanceChanged";
    function getParentWithViewController(view) {
        while (view && !view.viewController) {
            view = view.parent;
        }
        return view;
    }
    ios.getParentWithViewController = getParentWithViewController;
    function updateAutoAdjustScrollInsets(controller, owner) {
        if (majorVersion <= 10) {
            owner._automaticallyAdjustsScrollViewInsets = false;
            controller.automaticallyAdjustsScrollViewInsets = false;
        }
    }
    ios.updateAutoAdjustScrollInsets = updateAutoAdjustScrollInsets;
    function updateConstraints(controller, owner) {
        if (majorVersion <= 10) {
            var layoutGuide = initLayoutGuide(controller);
            controller.view.safeAreaLayoutGuide = layoutGuide;
        }
    }
    ios.updateConstraints = updateConstraints;
    function initLayoutGuide(controller) {
        var rootView = controller.view;
        var layoutGuide = UILayoutGuide.alloc().init();
        rootView.addLayoutGuide(layoutGuide);
        NSLayoutConstraint.activateConstraints([
            layoutGuide.topAnchor.constraintEqualToAnchor(controller.topLayoutGuide.bottomAnchor),
            layoutGuide.bottomAnchor.constraintEqualToAnchor(controller.bottomLayoutGuide.topAnchor),
            layoutGuide.leadingAnchor.constraintEqualToAnchor(rootView.leadingAnchor),
            layoutGuide.trailingAnchor.constraintEqualToAnchor(rootView.trailingAnchor)
        ]);
        return layoutGuide;
    }
    function layoutView(controller, owner) {
        var layoutGuide = controller.view.safeAreaLayoutGuide;
        if (!layoutGuide) {
            trace_1.write("safeAreaLayoutGuide during layout of " + owner + ". Creating fallback constraints, but layout might be wrong.", trace_1.categories.Layout, trace_1.messageType.error);
            layoutGuide = initLayoutGuide(controller);
        }
        var safeArea = layoutGuide.layoutFrame;
        var position = ios.getPositionFromFrame(safeArea);
        var safeAreaSize = safeArea.size;
        var hasChildViewControllers = controller.childViewControllers.count > 0;
        if (hasChildViewControllers) {
            var fullscreen = controller.view.frame;
            position = ios.getPositionFromFrame(fullscreen);
        }
        var safeAreaWidth = utils_1.layout.round(utils_1.layout.toDevicePixels(safeAreaSize.width));
        var safeAreaHeight = utils_1.layout.round(utils_1.layout.toDevicePixels(safeAreaSize.height));
        var widthSpec = utils_1.layout.makeMeasureSpec(safeAreaWidth, utils_1.layout.EXACTLY);
        var heightSpec = utils_1.layout.makeMeasureSpec(safeAreaHeight, utils_1.layout.EXACTLY);
        view_helper_common_1.ViewHelper.measureChild(null, owner, widthSpec, heightSpec);
        view_helper_common_1.ViewHelper.layoutChild(null, owner, position.left, position.top, position.right, position.bottom);
        if (owner.parent) {
            owner.parent._layoutParent();
        }
    }
    ios.layoutView = layoutView;
    function getPositionFromFrame(frame) {
        var left = utils_1.layout.round(utils_1.layout.toDevicePixels(frame.origin.x));
        var top = utils_1.layout.round(utils_1.layout.toDevicePixels(frame.origin.y));
        var right = utils_1.layout.round(utils_1.layout.toDevicePixels(frame.origin.x + frame.size.width));
        var bottom = utils_1.layout.round(utils_1.layout.toDevicePixels(frame.origin.y + frame.size.height));
        return { left: left, right: right, top: top, bottom: bottom };
    }
    ios.getPositionFromFrame = getPositionFromFrame;
    function getFrameFromPosition(position, insets) {
        insets = insets || { left: 0, top: 0, right: 0, bottom: 0 };
        var left = utils_1.layout.toDeviceIndependentPixels(position.left + insets.left);
        var top = utils_1.layout.toDeviceIndependentPixels(position.top + insets.top);
        var width = utils_1.layout.toDeviceIndependentPixels(position.right - position.left - insets.left - insets.right);
        var height = utils_1.layout.toDeviceIndependentPixels(position.bottom - position.top - insets.top - insets.bottom);
        return CGRectMake(left, top, width, height);
    }
    ios.getFrameFromPosition = getFrameFromPosition;
    function shrinkToSafeArea(view, frame) {
        var insets = view.getSafeAreaInsets();
        if (insets.left || insets.top) {
            var position = ios.getPositionFromFrame(frame);
            var adjustedFrame = ios.getFrameFromPosition(position, insets);
            if (trace_1.isEnabled()) {
                trace_1.write(this + " :shrinkToSafeArea: " + JSON.stringify(ios.getPositionFromFrame(adjustedFrame)), trace_1.categories.Layout);
            }
            return adjustedFrame;
        }
        return null;
    }
    ios.shrinkToSafeArea = shrinkToSafeArea;
    function expandBeyondSafeArea(view, frame) {
        var availableSpace = getAvailableSpaceFromParent(view, frame);
        var safeArea = availableSpace.safeArea;
        var fullscreen = availableSpace.fullscreen;
        var inWindow = availableSpace.inWindow;
        var position = ios.getPositionFromFrame(frame);
        var safeAreaPosition = ios.getPositionFromFrame(safeArea);
        var fullscreenPosition = ios.getPositionFromFrame(fullscreen);
        var inWindowPosition = ios.getPositionFromFrame(inWindow);
        var adjustedPosition = position;
        if (position.left && inWindowPosition.left <= safeAreaPosition.left) {
            adjustedPosition.left = fullscreenPosition.left;
        }
        if (position.top && inWindowPosition.top <= safeAreaPosition.top) {
            adjustedPosition.top = fullscreenPosition.top;
        }
        if (inWindowPosition.right < fullscreenPosition.right && inWindowPosition.right >= safeAreaPosition.right + fullscreenPosition.left) {
            adjustedPosition.right += fullscreenPosition.right - inWindowPosition.right;
        }
        if (inWindowPosition.bottom < fullscreenPosition.bottom && inWindowPosition.bottom >= safeAreaPosition.bottom + fullscreenPosition.top) {
            adjustedPosition.bottom += fullscreenPosition.bottom - inWindowPosition.bottom;
        }
        var adjustedFrame = CGRectMake(utils_1.layout.toDeviceIndependentPixels(adjustedPosition.left), utils_1.layout.toDeviceIndependentPixels(adjustedPosition.top), utils_1.layout.toDeviceIndependentPixels(adjustedPosition.right - adjustedPosition.left), utils_1.layout.toDeviceIndependentPixels(adjustedPosition.bottom - adjustedPosition.top));
        if (trace_1.isEnabled()) {
            trace_1.write(view + " :expandBeyondSafeArea: " + JSON.stringify(ios.getPositionFromFrame(adjustedFrame)), trace_1.categories.Layout);
        }
        return adjustedFrame;
    }
    ios.expandBeyondSafeArea = expandBeyondSafeArea;
    function getAvailableSpaceFromParent(view, frame) {
        if (!view) {
            return;
        }
        var scrollView = null;
        var viewControllerView = null;
        if (view.viewController) {
            viewControllerView = view.viewController.view;
        }
        else {
            var parent_1 = view.parent;
            while (parent_1 && !parent_1.viewController && !(parent_1.nativeViewProtected instanceof UIScrollView)) {
                parent_1 = parent_1.parent;
            }
            if (parent_1.nativeViewProtected instanceof UIScrollView) {
                scrollView = parent_1.nativeViewProtected;
            }
            else if (parent_1.viewController) {
                viewControllerView = parent_1.viewController.view;
            }
        }
        var fullscreen = null;
        var safeArea = null;
        if (viewControllerView) {
            safeArea = viewControllerView.safeAreaLayoutGuide.layoutFrame;
            fullscreen = viewControllerView.frame;
        }
        else if (scrollView) {
            var insets = scrollView.safeAreaInsets;
            safeArea = CGRectMake(insets.left, insets.top, scrollView.contentSize.width - insets.left - insets.right, scrollView.contentSize.height - insets.top - insets.bottom);
            fullscreen = CGRectMake(0, 0, scrollView.contentSize.width, scrollView.contentSize.height);
        }
        var locationInWindow = view.getLocationInWindow();
        var inWindowLeft = locationInWindow.x;
        var inWindowTop = locationInWindow.y;
        if (scrollView) {
            inWindowLeft += scrollView.contentOffset.x;
            inWindowTop += scrollView.contentOffset.y;
        }
        var inWindow = CGRectMake(inWindowLeft, inWindowTop, frame.size.width, frame.size.height);
        return { safeArea: safeArea, fullscreen: fullscreen, inWindow: inWindow };
    }
    var UILayoutViewController = (function (_super) {
        __extends(UILayoutViewController, _super);
        function UILayoutViewController() {
            return _super !== null && _super.apply(this, arguments) || this;
        }
        UILayoutViewController.initWithOwner = function (owner) {
            var controller = UILayoutViewController.new();
            controller.owner = owner;
            return controller;
        };
        UILayoutViewController.prototype.viewDidLoad = function () {
            _super.prototype.viewDidLoad.call(this);
            this.extendedLayoutIncludesOpaqueBars = true;
        };
        UILayoutViewController.prototype.viewWillLayoutSubviews = function () {
            _super.prototype.viewWillLayoutSubviews.call(this);
            var owner = this.owner.get();
            if (owner) {
                updateConstraints(this, owner);
            }
        };
        UILayoutViewController.prototype.viewDidLayoutSubviews = function () {
            _super.prototype.viewDidLayoutSubviews.call(this);
            var owner = this.owner.get();
            if (owner) {
                if (majorVersion >= 11) {
                    var tabViewItem = owner.parent;
                    var tabView = tabViewItem && tabViewItem.parent;
                    var parent_2 = tabView && tabView.parent;
                    while (parent_2 && !parent_2.nativeViewProtected) {
                        parent_2 = parent_2.parent;
                    }
                    if (parent_2) {
                        var parentPageInsetsTop = parent_2.nativeViewProtected.safeAreaInsets.top;
                        var currentInsetsTop = this.view.safeAreaInsets.top;
                        var additionalInsetsTop = Math.max(parentPageInsetsTop - currentInsetsTop, 0);
                        var parentPageInsetsBottom = parent_2.nativeViewProtected.safeAreaInsets.bottom;
                        var currentInsetsBottom = this.view.safeAreaInsets.bottom;
                        var additionalInsetsBottom = Math.max(parentPageInsetsBottom - currentInsetsBottom, 0);
                        if (additionalInsetsTop > 0 || additionalInsetsBottom > 0) {
                            var additionalInsets = new UIEdgeInsets({ top: additionalInsetsTop, left: 0, bottom: additionalInsetsBottom, right: 0 });
                            this.additionalSafeAreaInsets = additionalInsets;
                        }
                    }
                }
                layoutView(this, owner);
            }
        };
        UILayoutViewController.prototype.viewWillAppear = function (animated) {
            _super.prototype.viewWillAppear.call(this, animated);
            var owner = this.owner.get();
            if (!owner) {
                return;
            }
            updateAutoAdjustScrollInsets(this, owner);
            if (!owner.parent) {
                owner.callLoaded();
            }
        };
        UILayoutViewController.prototype.viewDidDisappear = function (animated) {
            _super.prototype.viewDidDisappear.call(this, animated);
            var owner = this.owner.get();
            if (owner && !owner.parent) {
                owner.callUnloaded();
            }
        };
        UILayoutViewController.prototype.traitCollectionDidChange = function (previousTraitCollection) {
            _super.prototype.traitCollectionDidChange.call(this, previousTraitCollection);
            if (majorVersion >= 13) {
                var owner = this.owner.get();
                if (owner &&
                    this.traitCollection.hasDifferentColorAppearanceComparedToTraitCollection &&
                    this.traitCollection.hasDifferentColorAppearanceComparedToTraitCollection(previousTraitCollection)) {
                    owner.notify({ eventName: ios.traitCollectionColorAppearanceChangedEvent, object: owner });
                }
            }
        };
        return UILayoutViewController;
    }(UIViewController));
    ios.UILayoutViewController = UILayoutViewController;
    var UIAdaptivePresentationControllerDelegateImp = (function (_super) {
        __extends(UIAdaptivePresentationControllerDelegateImp, _super);
        function UIAdaptivePresentationControllerDelegateImp() {
            return _super !== null && _super.apply(this, arguments) || this;
        }
        UIAdaptivePresentationControllerDelegateImp.initWithOwnerAndCallback = function (owner, whenClosedCallback) {
            var instance = _super.new.call(this);
            instance.owner = owner;
            instance.closedCallback = whenClosedCallback;
            return instance;
        };
        UIAdaptivePresentationControllerDelegateImp.prototype.presentationControllerDidDismiss = function (presentationController) {
            var owner = this.owner.get();
            if (owner && typeof this.closedCallback === "function") {
                this.closedCallback();
            }
        };
        UIAdaptivePresentationControllerDelegateImp.ObjCProtocols = [UIAdaptivePresentationControllerDelegate];
        return UIAdaptivePresentationControllerDelegateImp;
    }(NSObject));
    ios.UIAdaptivePresentationControllerDelegateImp = UIAdaptivePresentationControllerDelegateImp;
    var UIPopoverPresentationControllerDelegateImp = (function (_super) {
        __extends(UIPopoverPresentationControllerDelegateImp, _super);
        function UIPopoverPresentationControllerDelegateImp() {
            return _super !== null && _super.apply(this, arguments) || this;
        }
        UIPopoverPresentationControllerDelegateImp.initWithOwnerAndCallback = function (owner, whenClosedCallback) {
            var instance = _super.new.call(this);
            instance.owner = owner;
            instance.closedCallback = whenClosedCallback;
            return instance;
        };
        UIPopoverPresentationControllerDelegateImp.prototype.popoverPresentationControllerDidDismissPopover = function (popoverPresentationController) {
            var owner = this.owner.get();
            if (owner && typeof this.closedCallback === "function") {
                this.closedCallback();
            }
        };
        UIPopoverPresentationControllerDelegateImp.ObjCProtocols = [UIPopoverPresentationControllerDelegate];
        return UIPopoverPresentationControllerDelegateImp;
    }(NSObject));
    ios.UIPopoverPresentationControllerDelegateImp = UIPopoverPresentationControllerDelegateImp;
})(ios = exports.ios || (exports.ios = {}));
//# sourceMappingURL=view-helper.ios.js.map