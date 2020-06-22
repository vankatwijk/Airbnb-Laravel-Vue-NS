Object.defineProperty(exports, "__esModule", { value: true });
require("../globals");
var observable_1 = require("../data/observable");
exports.Observable = observable_1.Observable;
var profiling_1 = require("../profiling");
var bindableResources = require("../ui/core/bindable/bindable-resources");
var system_classes_1 = require("../css/system-classes");
var enums_1 = require("../ui/enums/enums");
var events = new observable_1.Observable();
var launched = false;
function setLaunched() {
    launched = true;
    events.off("launch", setLaunched);
}
events.on("launch", setLaunched);
if (profiling_1.level() > 0) {
    events.on("displayed", function () {
        var duration = profiling_1.uptime();
        var end = profiling_1.time();
        var start = end - duration;
        profiling_1.trace("Displayed in " + duration.toFixed(2) + "ms", start, end);
    });
}
function hasLaunched() {
    return launched;
}
exports.hasLaunched = hasLaunched;
exports.launchEvent = "launch";
exports.suspendEvent = "suspend";
exports.displayedEvent = "displayed";
exports.resumeEvent = "resume";
exports.exitEvent = "exit";
exports.lowMemoryEvent = "lowMemory";
exports.uncaughtErrorEvent = "uncaughtError";
exports.discardedErrorEvent = "discardedError";
exports.orientationChangedEvent = "orientationChanged";
exports.systemAppearanceChangedEvent = "systemAppearanceChanged";
var ORIENTATION_CSS_CLASSES = [
    "" + system_classes_1.CLASS_PREFIX + enums_1.DeviceOrientation.portrait,
    "" + system_classes_1.CLASS_PREFIX + enums_1.DeviceOrientation.landscape,
    "" + system_classes_1.CLASS_PREFIX + enums_1.DeviceOrientation.unknown
];
var SYSTEM_APPEARANCE_CSS_CLASSES = [
    "" + system_classes_1.CLASS_PREFIX + enums_1.SystemAppearance.light,
    "" + system_classes_1.CLASS_PREFIX + enums_1.SystemAppearance.dark
];
var cssFile = "./app.css";
function getResources() {
    return bindableResources.get();
}
exports.getResources = getResources;
function setResources(res) {
    bindableResources.set(res);
}
exports.setResources = setResources;
exports.android = undefined;
exports.ios = undefined;
exports.on = events.on.bind(events);
exports.off = events.off.bind(events);
exports.notify = events.notify.bind(events);
exports.hasListeners = events.hasListeners.bind(events);
var app;
function setApplication(instance) {
    app = instance;
}
exports.setApplication = setApplication;
function livesync(rootView, context) {
    events.notify({ eventName: "livesync", object: app });
    var liveSyncCore = global.__onLiveSyncCore;
    var reapplyAppStyles = false;
    if (context && context.path) {
        var styleExtensions = ["css", "scss"];
        var appStylesFullFileName = getCssFileName();
        var appStylesFileName_1 = appStylesFullFileName.substring(0, appStylesFullFileName.lastIndexOf(".") + 1);
        reapplyAppStyles = styleExtensions.some(function (ext) { return context.path === appStylesFileName_1.concat(ext); });
    }
    if (rootView && reapplyAppStyles) {
        rootView._onCssStateChange();
    }
    else if (liveSyncCore) {
        liveSyncCore(context);
    }
}
exports.livesync = livesync;
function setCssFileName(cssFileName) {
    cssFile = cssFileName;
    events.notify({ eventName: "cssChanged", object: app, cssFile: cssFileName });
}
exports.setCssFileName = setCssFileName;
function getCssFileName() {
    return cssFile;
}
exports.getCssFileName = getCssFileName;
function loadAppCss() {
    try {
        events.notify({ eventName: "loadAppCss", object: app, cssFile: getCssFileName() });
    }
    catch (e) {
        throw new Error("The app CSS file " + getCssFileName() + " couldn't be loaded!");
    }
}
exports.loadAppCss = loadAppCss;
function addCssClass(rootView, cssClass) {
    system_classes_1.pushToSystemCssClasses(cssClass);
    rootView.cssClasses.add(cssClass);
}
function removeCssClass(rootView, cssClass) {
    system_classes_1.removeSystemCssClass(cssClass);
    rootView.cssClasses.delete(cssClass);
}
function increaseStyleScopeApplicationCssSelectorVersion(rootView) {
    var styleScope = rootView._styleScope || (rootView.currentPage && rootView.currentPage._styleScope);
    if (styleScope) {
        styleScope._increaseApplicationCssSelectorVersion();
    }
}
function applyCssClass(rootView, cssClasses, newCssClass) {
    if (!rootView.cssClasses.has(newCssClass)) {
        cssClasses.forEach(function (cssClass) { return removeCssClass(rootView, cssClass); });
        addCssClass(rootView, newCssClass);
        increaseStyleScopeApplicationCssSelectorVersion(rootView);
        rootView._onCssStateChange();
    }
}
function orientationChanged(rootView, newOrientation) {
    if (!rootView) {
        return;
    }
    var newOrientationCssClass = "" + system_classes_1.CLASS_PREFIX + newOrientation;
    applyCssClass(rootView, ORIENTATION_CSS_CLASSES, newOrientationCssClass);
    var rootModalViews = rootView._getRootModalViews();
    rootModalViews.forEach(function (rootModalView) {
        applyCssClass(rootModalView, ORIENTATION_CSS_CLASSES, newOrientationCssClass);
    });
}
exports.orientationChanged = orientationChanged;
function systemAppearanceChanged(rootView, newSystemAppearance) {
    if (!rootView) {
        return;
    }
    var newSystemAppearanceCssClass = "" + system_classes_1.CLASS_PREFIX + newSystemAppearance;
    applyCssClass(rootView, SYSTEM_APPEARANCE_CSS_CLASSES, newSystemAppearanceCssClass);
    var rootModalViews = rootView._getRootModalViews();
    rootModalViews.forEach(function (rootModalView) {
        applyCssClass(rootModalView, SYSTEM_APPEARANCE_CSS_CLASSES, newSystemAppearanceCssClass);
    });
}
exports.systemAppearanceChanged = systemAppearanceChanged;
global.__onUncaughtError = function (error) {
    events.notify({ eventName: exports.uncaughtErrorEvent, object: app, android: error, ios: error, error: error });
};
global.__onDiscardedError = function (error) {
    events.notify({ eventName: exports.discardedErrorEvent, object: app, error: error });
};
//# sourceMappingURL=application-common.js.map