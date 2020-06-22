function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var application_common_1 = require("./application-common");
__export(require("./application-common"));
var builder_1 = require("../ui/builder");
var system_classes_1 = require("../css/system-classes");
var view_helper_1 = require("../ui/core/view/view-helper");
var platform_1 = require("../platform/platform");
var profiling_1 = require("../profiling");
var utils_1 = require("../utils/utils");
var IOS_PLATFORM = "ios";
var getVisibleViewController = utils_1.ios.getVisibleViewController;
var majorVersion = utils_1.ios.MajorVersion;
var Responder = UIResponder.extend({
    get window() {
        return iosApp ? iosApp.window : undefined;
    },
    set window(setWindow) {
    }
}, {
    protocols: [UIApplicationDelegate]
});
var NotificationObserver = (function (_super) {
    __extends(NotificationObserver, _super);
    function NotificationObserver() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    NotificationObserver.initWithCallback = function (onReceiveCallback) {
        var observer = _super.new.call(this);
        observer._onReceiveCallback = onReceiveCallback;
        return observer;
    };
    NotificationObserver.prototype.onReceive = function (notification) {
        this._onReceiveCallback(notification);
    };
    NotificationObserver.ObjCExposedMethods = {
        "onReceive": { returns: interop.types.void, params: [NSNotification] }
    };
    return NotificationObserver;
}(NSObject));
var displayedOnce = false;
var displayedLinkTarget;
var displayedLink;
var CADisplayLinkTarget = (function (_super) {
    __extends(CADisplayLinkTarget, _super);
    function CADisplayLinkTarget() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    CADisplayLinkTarget.prototype.onDisplayed = function (link) {
        link.invalidate();
        var ios = UIApplication.sharedApplication;
        var object = iosApp;
        displayedOnce = true;
        application_common_1.notify({ eventName: application_common_1.displayedEvent, object: object, ios: ios });
        displayedLinkTarget = null;
        displayedLink = null;
    };
    CADisplayLinkTarget.ObjCExposedMethods = {
        "onDisplayed": { returns: interop.types.void, params: [CADisplayLink] }
    };
    return CADisplayLinkTarget;
}(NSObject));
var iOSApplication = (function () {
    function iOSApplication() {
        this._backgroundColor = (majorVersion <= 12 || !UIColor.systemBackgroundColor) ? UIColor.whiteColor : UIColor.systemBackgroundColor;
        this._observers = new Array();
        this.addNotificationObserver(UIApplicationDidFinishLaunchingNotification, this.didFinishLaunchingWithOptions.bind(this));
        this.addNotificationObserver(UIApplicationDidBecomeActiveNotification, this.didBecomeActive.bind(this));
        this.addNotificationObserver(UIApplicationDidEnterBackgroundNotification, this.didEnterBackground.bind(this));
        this.addNotificationObserver(UIApplicationWillTerminateNotification, this.willTerminate.bind(this));
        this.addNotificationObserver(UIApplicationDidReceiveMemoryWarningNotification, this.didReceiveMemoryWarning.bind(this));
        this.addNotificationObserver(UIApplicationDidChangeStatusBarOrientationNotification, this.didChangeStatusBarOrientation.bind(this));
    }
    Object.defineProperty(iOSApplication.prototype, "orientation", {
        get: function () {
            if (!this._orientation) {
                var statusBarOrientation = UIApplication.sharedApplication.statusBarOrientation;
                this._orientation = this.getOrientationValue(statusBarOrientation);
            }
            return this._orientation;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(iOSApplication.prototype, "rootController", {
        get: function () {
            return this._window.rootViewController;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(iOSApplication.prototype, "systemAppearance", {
        get: function () {
            if (majorVersion <= 11) {
                return null;
            }
            if (!this._systemAppearance) {
                var userInterfaceStyle = this.rootController.traitCollection.userInterfaceStyle;
                this._systemAppearance = getSystemAppearanceValue(userInterfaceStyle);
            }
            return this._systemAppearance;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(iOSApplication.prototype, "nativeApp", {
        get: function () {
            return UIApplication.sharedApplication;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(iOSApplication.prototype, "window", {
        get: function () {
            return this._window;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(iOSApplication.prototype, "delegate", {
        get: function () {
            return this._delegate;
        },
        set: function (value) {
            if (this._delegate !== value) {
                this._delegate = value;
            }
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(iOSApplication.prototype, "rootView", {
        get: function () {
            return this._rootView;
        },
        enumerable: true,
        configurable: true
    });
    iOSApplication.prototype.addNotificationObserver = function (notificationName, onReceiveCallback) {
        var observer = NotificationObserver.initWithCallback(onReceiveCallback);
        NSNotificationCenter.defaultCenter.addObserverSelectorNameObject(observer, "onReceive", notificationName, null);
        this._observers.push(observer);
        return observer;
    };
    iOSApplication.prototype.removeNotificationObserver = function (observer, notificationName) {
        var index = this._observers.indexOf(observer);
        if (index >= 0) {
            this._observers.splice(index, 1);
            NSNotificationCenter.defaultCenter.removeObserverNameObject(observer, notificationName, null);
        }
    };
    iOSApplication.prototype.didFinishLaunchingWithOptions = function (notification) {
        if (!displayedOnce) {
            displayedLinkTarget = CADisplayLinkTarget.new();
            displayedLink = CADisplayLink.displayLinkWithTargetSelector(displayedLinkTarget, "onDisplayed");
            displayedLink.addToRunLoopForMode(NSRunLoop.mainRunLoop, NSDefaultRunLoopMode);
            displayedLink.addToRunLoopForMode(NSRunLoop.mainRunLoop, UITrackingRunLoopMode);
        }
        this._window = UIWindow.alloc().initWithFrame(UIScreen.mainScreen.bounds);
        this._window.backgroundColor = this._backgroundColor;
        this.notifyAppStarted(notification);
    };
    iOSApplication.prototype.notifyAppStarted = function (notification) {
        var args = {
            eventName: application_common_1.launchEvent,
            object: this,
            ios: notification && notification.userInfo && notification.userInfo.objectForKey("UIApplicationLaunchOptionsLocalNotificationKey") || null
        };
        application_common_1.notify(args);
        application_common_1.notify({ eventName: "loadAppCss", object: this, cssFile: application_common_1.getCssFileName() });
        if (this._window) {
            this.setWindowContent(args.root);
        }
        else {
            this._window = UIApplication.sharedApplication.delegate.window;
        }
    };
    iOSApplication.prototype.didBecomeActive = function (notification) {
        var ios = UIApplication.sharedApplication;
        var object = this;
        application_common_1.notify({ eventName: application_common_1.resumeEvent, object: object, ios: ios });
        var rootView = this._rootView;
        if (rootView && !rootView.isLoaded) {
            rootView.callLoaded();
        }
    };
    iOSApplication.prototype.didEnterBackground = function (notification) {
        application_common_1.notify({ eventName: application_common_1.suspendEvent, object: this, ios: UIApplication.sharedApplication });
        var rootView = this._rootView;
        if (rootView && rootView.isLoaded) {
            rootView.callUnloaded();
        }
    };
    iOSApplication.prototype.willTerminate = function (notification) {
        application_common_1.notify({ eventName: application_common_1.exitEvent, object: this, ios: UIApplication.sharedApplication });
        var rootView = this._rootView;
        if (rootView && rootView.isLoaded) {
            rootView.callUnloaded();
        }
    };
    iOSApplication.prototype.didChangeStatusBarOrientation = function (notification) {
        var statusBarOrientation = UIApplication.sharedApplication.statusBarOrientation;
        var newOrientation = this.getOrientationValue(statusBarOrientation);
        if (this._orientation !== newOrientation) {
            this._orientation = newOrientation;
            application_common_1.orientationChanged(getRootView(), newOrientation);
            application_common_1.notify({
                eventName: application_common_1.orientationChangedEvent,
                ios: this,
                newValue: this._orientation,
                object: this
            });
        }
    };
    iOSApplication.prototype.didReceiveMemoryWarning = function (notification) {
        application_common_1.notify({ eventName: application_common_1.lowMemoryEvent, object: this, ios: UIApplication.sharedApplication });
    };
    iOSApplication.prototype.getOrientationValue = function (orientation) {
        switch (orientation) {
            case 3:
            case 4:
                return "landscape";
            case 2:
            case 1:
                return "portrait";
            case 0:
                return "unknown";
        }
    };
    iOSApplication.prototype._onLivesync = function (context) {
        var isAppRootModuleChanged = context && context.path && context.path.includes(getMainEntry().moduleName) && context.type !== "style";
        if (isAppRootModuleChanged || (this._rootView && !this._rootView._onLivesync(context))) {
            this.setWindowContent();
        }
    };
    iOSApplication.prototype.setWindowContent = function (view) {
        var _this = this;
        if (this._rootView) {
            this._rootView._onRootViewReset();
        }
        var rootView = createRootView(view);
        var controller = getViewController(rootView);
        this._rootView = rootView;
        rootView._setupAsRootView({});
        setViewControllerView(rootView);
        var haveController = this._window.rootViewController !== null;
        this._window.rootViewController = controller;
        setRootViewsSystemAppearanceCssClass(rootView);
        if (!haveController) {
            this._window.makeKeyAndVisible();
        }
        rootView.on(view_helper_1.ios.traitCollectionColorAppearanceChangedEvent, function () {
            var userInterfaceStyle = controller.traitCollection.userInterfaceStyle;
            var newSystemAppearance = getSystemAppearanceValue(userInterfaceStyle);
            if (_this._systemAppearance !== newSystemAppearance) {
                _this._systemAppearance = newSystemAppearance;
                application_common_1.systemAppearanceChanged(rootView, newSystemAppearance);
                application_common_1.notify({
                    eventName: application_common_1.systemAppearanceChangedEvent,
                    ios: _this,
                    newValue: _this._systemAppearance,
                    object: _this
                });
            }
        });
    };
    __decorate([
        profiling_1.profile
    ], iOSApplication.prototype, "didFinishLaunchingWithOptions", null);
    __decorate([
        profiling_1.profile
    ], iOSApplication.prototype, "didBecomeActive", null);
    return iOSApplication;
}());
exports.iOSApplication = iOSApplication;
var iosApp = new iOSApplication();
exports.ios = iosApp;
application_common_1.setApplication(iosApp);
global.__onLiveSyncCore = function (context) {
    iosApp._onLivesync(context);
};
var mainEntry;
function createRootView(v) {
    var rootView = v;
    if (!rootView) {
        if (!mainEntry) {
            throw new Error("Main entry is missing. App cannot be started. Verify app bootstrap.");
        }
        else {
            rootView = builder_1.Builder.createViewFromEntry(mainEntry);
        }
    }
    setRootViewsCssClasses(rootView);
    return rootView;
}
function getMainEntry() {
    return mainEntry;
}
exports.getMainEntry = getMainEntry;
function getRootView() {
    return iosApp.rootView;
}
exports.getRootView = getRootView;
var started = false;
function run(entry) {
    var _this = this;
    mainEntry = typeof entry === "string" ? { moduleName: entry } : entry;
    started = true;
    if (!iosApp.nativeApp) {
        UIApplicationMain(0, null, null, iosApp && iosApp.delegate ? NSStringFromClass(iosApp.delegate) : NSStringFromClass(Responder));
    }
    else {
        var rootView = createRootView();
        if (rootView) {
            var window_1 = iosApp.nativeApp.keyWindow || (iosApp.nativeApp.windows.count > 0 && iosApp.nativeApp.windows[0]);
            if (window_1) {
                var rootController = window_1.rootViewController;
                if (rootController) {
                    var controller_1 = getViewController(rootView);
                    rootView._setupAsRootView({});
                    var embedderDelegate = NativeScriptEmbedder.sharedInstance().delegate;
                    if (embedderDelegate) {
                        embedderDelegate.presentNativeScriptApp(controller_1);
                    }
                    else {
                        var visibleVC = getVisibleViewController(rootController);
                        visibleVC.presentViewControllerAnimatedCompletion(controller_1, true, null);
                    }
                    setRootViewsSystemAppearanceCssClass(rootView);
                    rootView.on(view_helper_1.ios.traitCollectionColorAppearanceChangedEvent, function () {
                        var userInterfaceStyle = controller_1.traitCollection.userInterfaceStyle;
                        var newSystemAppearance = getSystemAppearanceValue(userInterfaceStyle);
                        if (_this._systemAppearance !== newSystemAppearance) {
                            _this._systemAppearance = newSystemAppearance;
                            application_common_1.notify({
                                eventName: application_common_1.systemAppearanceChangedEvent,
                                ios: _this,
                                newValue: _this._systemAppearance,
                                object: _this
                            });
                        }
                    });
                    iosApp.notifyAppStarted();
                }
            }
        }
    }
}
exports.run = run;
function addCss(cssText, attributeScoped) {
    application_common_1.notify({ eventName: "cssChanged", object: iosApp, cssText: cssText });
    if (!attributeScoped) {
        var rootView = getRootView();
        if (rootView) {
            rootView._onCssStateChange();
        }
    }
}
exports.addCss = addCss;
function _resetRootView(entry) {
    mainEntry = typeof entry === "string" ? { moduleName: entry } : entry;
    iosApp.setWindowContent();
}
exports._resetRootView = _resetRootView;
function getNativeApplication() {
    return iosApp.nativeApp;
}
exports.getNativeApplication = getNativeApplication;
function getSystemAppearanceValue(userInterfaceStyle) {
    switch (userInterfaceStyle) {
        case 2:
            return "dark";
        case 1:
        case 0:
            return "light";
    }
}
function getViewController(rootView) {
    var viewController = rootView.viewController || rootView.ios;
    if (!(viewController instanceof UIViewController)) {
        viewController = view_helper_1.ios.UILayoutViewController.initWithOwner(new WeakRef(rootView));
        rootView.viewController = viewController;
    }
    return viewController;
}
function setViewControllerView(view) {
    var viewController = view.viewController || view.ios;
    var nativeView = view.ios || view.nativeViewProtected;
    if (!nativeView || !viewController) {
        throw new Error("Root should be either UIViewController or UIView");
    }
    if (viewController instanceof view_helper_1.ios.UILayoutViewController) {
        viewController.view.addSubview(nativeView);
    }
}
function setRootViewsCssClasses(rootView) {
    var deviceType = platform_1.device.deviceType.toLowerCase();
    system_classes_1.pushToSystemCssClasses("" + system_classes_1.CLASS_PREFIX + IOS_PLATFORM);
    system_classes_1.pushToSystemCssClasses("" + system_classes_1.CLASS_PREFIX + deviceType);
    system_classes_1.pushToSystemCssClasses("" + system_classes_1.CLASS_PREFIX + iosApp.orientation);
    rootView.cssClasses.add(system_classes_1.ROOT_VIEW_CSS_CLASS);
    var rootViewCssClasses = system_classes_1.getSystemCssClasses();
    rootViewCssClasses.forEach(function (c) { return rootView.cssClasses.add(c); });
}
function setRootViewsSystemAppearanceCssClass(rootView) {
    if (majorVersion >= 13) {
        var systemAppearanceCssClass = "" + system_classes_1.CLASS_PREFIX + iosApp.systemAppearance;
        system_classes_1.pushToSystemCssClasses(systemAppearanceCssClass);
        rootView.cssClasses.add(systemAppearanceCssClass);
    }
}
function orientation() {
    return iosApp.orientation;
}
exports.orientation = orientation;
function systemAppearance() {
    return iosApp.systemAppearance;
}
exports.systemAppearance = systemAppearance;
global.__onLiveSync = function __onLiveSync(context) {
    if (!started) {
        return;
    }
    var rootView = getRootView();
    application_common_1.livesync(rootView, context);
};
//# sourceMappingURL=application.ios.js.map