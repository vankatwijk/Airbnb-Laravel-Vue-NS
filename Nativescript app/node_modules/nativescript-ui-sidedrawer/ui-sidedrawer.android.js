function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
__export(require("./ui-sidedrawer.common"));
var commonModule = require("./ui-sidedrawer.common");
var utils = require("tns-core-modules/utils/utils");
var SideDrawerChangeListener;
function initializeListeners() {
    if (!SideDrawerChangeListener) {
        var SideDrawerChangeListenerImpl = /** @class */ (function (_super) {
            __extends(SideDrawerChangeListenerImpl, _super);
            function SideDrawerChangeListenerImpl(owner) {
                var _this = _super.call(this) || this;
                _this.owner = owner;
                return global.__native(_this);
            }
            SideDrawerChangeListenerImpl.prototype.onDrawerOpening = function (drawer) {
                if (!this.owner) {
                    return false;
                }
                if (this.owner.hasListeners(commonModule.RadSideDrawer.drawerOpeningEvent)) {
                    var args = {
                        eventName: commonModule.RadSideDrawer.drawerOpeningEvent,
                        object: this.owner,
                        returnValue: false
                    };
                    this.owner.notify(args);
                    if (args.returnValue) {
                        return args.returnValue;
                    }
                }
                return false;
            };
            SideDrawerChangeListenerImpl.prototype.onDrawerOpened = function (drawer) {
                if (!this.owner) {
                    return;
                }
                if (this.owner.hasListeners(commonModule.RadSideDrawer.drawerOpenedEvent)) {
                    var args = {
                        eventName: commonModule.RadSideDrawer.drawerOpenedEvent,
                        object: this.owner
                    };
                    this.owner.notify(args);
                }
            };
            SideDrawerChangeListenerImpl.prototype.onDrawerClosing = function (drawer) {
                if (!this.owner) {
                    return false;
                }
                if (this.owner.hasListeners(commonModule.RadSideDrawer.drawerClosingEvent)) {
                    var args = {
                        eventName: commonModule.RadSideDrawer.drawerClosingEvent,
                        object: this.owner,
                        returnValue: false
                    };
                    this.owner.notify(args);
                    if (args.returnValue) {
                        return args.returnValue;
                    }
                }
                return false;
            };
            SideDrawerChangeListenerImpl.prototype.onDrawerClosed = function (drawer) {
                if (!this.owner) {
                    return;
                }
                if (this.owner.hasListeners(commonModule.RadSideDrawer.drawerClosedEvent)) {
                    var args = {
                        eventName: commonModule.RadSideDrawer.drawerClosedEvent,
                        object: this.owner
                    };
                    this.owner.notify(args);
                }
            };
            SideDrawerChangeListenerImpl.prototype.onDrawerPan = function (drawer) {
                if (!this.owner) {
                    return;
                }
                if (this.owner.hasListeners(commonModule.RadSideDrawer.drawerPanEvent)) {
                    var args = {
                        eventName: commonModule.RadSideDrawer.drawerPanEvent,
                        object: this.owner
                    };
                    this.owner.notify(args);
                }
            };
            SideDrawerChangeListenerImpl = __decorate([
                Interfaces([com.telerik.android.primitives.widget.sidedrawer.DrawerChangeListener]),
                __metadata("design:paramtypes", [RadSideDrawer])
            ], SideDrawerChangeListenerImpl);
            return SideDrawerChangeListenerImpl;
        }(java.lang.Object));
        SideDrawerChangeListener = SideDrawerChangeListenerImpl;
    }
}
var RadSideDrawer = /** @class */ (function (_super) {
    __extends(RadSideDrawer, _super);
    function RadSideDrawer() {
        var _this = _super !== null && _super.apply(this, arguments) || this;
        _this._androidViewId = -1;
        return _this;
    }
    Object.defineProperty(RadSideDrawer.prototype, "_nativeView", {
        get: function () {
            return this._android;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawer.prototype, "_page", {
        get: function () {
            var page;
            if (this.page) {
                page = this.page;
            }
            else {
                page = this.mainContent.nativeView;
            }
            return page;
        },
        enumerable: true,
        configurable: true
    });
    RadSideDrawer.prototype.onUnloaded = function () {
        _super.prototype.onUnloaded.call(this);
        if (this._mainContentNativeView) {
            var lp = this._mainContentNativeView.getLayoutParams();
            lp.topMargin = 0;
            this._mainContentNativeView.setLayoutParams(lp);
        }
        if (this._page && this._page.actionBar) {
            this._page.actionBar.nativeView.removeOnLayoutChangeListener(this.layoutChangeFunction);
        }
    };
    RadSideDrawer.prototype.onBackPressed = function () {
        var currentView = this.mainContent;
        if (currentView && this._isRootView) {
            return currentView.onBackPressed();
        }
        return false;
    };
    RadSideDrawer.prototype._addViewToNativeVisualTree = function (child) {
        if (this._android && child.android) {
            if (this.mainContent === child) {
                this._android.setMainContent(child.nativeView);
                return true;
            }
            if (this.drawerContent === child) {
                this._android.setDrawerContent(child.nativeView);
                return true;
            }
        }
        return false;
    };
    RadSideDrawer.prototype._removeViewFromNativeVisualTree = function (child) {
        if (this._android && child.android) {
            // TODO: Remove listener
            if (this.mainContent === child) {
                this._android.setMainContent(null);
                child._isAddedToNativeVisualTree = false;
            }
            if (this.drawerContent === child) {
                this._android.setDrawerContent(null);
                child._isAddedToNativeVisualTree = false;
            }
        }
    };
    RadSideDrawer.prototype.initDrawer = function () {
        initializeListeners();
        this._android = new com.telerik.android.primitives.widget.sidedrawer.RadSideDrawer(this._context);
        this._android._drawerChangeListener = new SideDrawerChangeListener(this);
        this._android.addChangeListener(this._android._drawerChangeListener);
    };
    RadSideDrawer.prototype.createNativeView = function () {
        if (this._page) {
            this._page.on("navigatingFrom", this.onNavigatingFrom, this);
        }
        this.initDrawer();
        this._android.setDrawerSize(utils.layout.getDisplayDensity() * this.drawerContentSize);
        this._android.setIsLocked(!this.gesturesEnabled);
        this._android.setAllowEdgeSwipe(this.allowEdgeSwipe);
        if (this.drawerTransition) {
            this._android.setDrawerTransition(this.drawerTransition.getNativeContent());
        }
        if (this.drawerLocation) {
            this.setDrawerLocation(this.drawerLocation);
        }
        return this._android;
    };
    RadSideDrawer.prototype.initNativeView = function () {
        _super.prototype.initNativeView.call(this);
        if (this._androidViewId < 0) {
            this._androidViewId = android.view.View.generateViewId();
        }
        this._nativeView.setId(this._androidViewId);
    };
    RadSideDrawer.prototype.disposeNativeView = function () {
        if (this._page) {
            this._page.off("navigatingFrom", this.onNavigatingFrom, this);
        }
        if (this._android._drawerChangeListener) {
            this._android._drawerChangeListener.owner = null;
        }
    };
    RadSideDrawer.prototype.onNavigatingFrom = function (args) {
        if (this.getIsOpen()) {
            this.closeDrawer();
        }
    };
    Object.defineProperty(RadSideDrawer.prototype, "android", {
        get: function () {
            return this._android;
        },
        enumerable: true,
        configurable: true
    });
    RadSideDrawer.prototype._onGesturesEnabledChanged = function (oldValue, newValue) {
        var value = newValue;
        if (!this.android) {
            return;
        }
        this.android.setIsLocked(!value);
    };
    RadSideDrawer.prototype._onAllowEdgeSwipeChanged = function (oldValue, newValue) {
        var value = newValue;
        if (!this.android) {
            return;
        }
        this.android.setAllowEdgeSwipe(value);
    };
    RadSideDrawer.prototype._onDrawerContentSizeChanged = function (oldValue, newValue) {
        if (!this.android) {
            return;
        }
        if (newValue) {
            this.android.setDrawerSize(utils.layout.getDisplayDensity() * newValue);
        }
    };
    RadSideDrawer.prototype._onDrawerTransitionChanged = function (oldValue, newValue) {
        if (!newValue) {
            return;
        }
        var finalVal;
        if (typeof newValue === "string") {
            switch (newValue.toLowerCase()) {
                case commonModule.FadeTransitionString: {
                    finalVal = new FadeTransition();
                    break;
                }
                case commonModule.PushTransitionString: {
                    finalVal = new PushTransition();
                    break;
                }
                case commonModule.RevealTransitionString: {
                    finalVal = new RevealTransition();
                    break;
                }
                case commonModule.ReverseSlideOutTransitionString: {
                    finalVal = new ReverseSlideOutTransition();
                    break;
                }
                case commonModule.ScaleDownPusherTransitionString: {
                    finalVal = new ScaleDownPusherTransition();
                    break;
                }
                case commonModule.ScaleUpTransitionString: {
                    finalVal = new ScaleUpTransition();
                    break;
                }
                case commonModule.SlideAlongTransitionString: {
                    finalVal = new SlideAlongTransition();
                    break;
                }
                case commonModule.SlideInOnTopTransitionString: {
                    finalVal = new SlideInOnTopTransition();
                    break;
                }
                default: {
                    console.log("Error: Not supported value (" + newValue + ") set to 'drawerTransition'");
                    finalVal = new SlideInOnTopTransition();
                    break;
                }
            }
            if (this.drawerTransition !== finalVal) {
                this.drawerTransition = finalVal;
                return;
            }
        }
        else {
            finalVal = newValue;
        }
        if (this.android) {
            this.android.setDrawerTransition(finalVal.getNativeContent());
        }
    };
    RadSideDrawer.prototype._onShadowColorChanged = function (oldValue, newValue) {
        if (!this.android) {
            return;
        }
        var nativeColor = newValue ? newValue.android : RadSideDrawer.shadowColorProperty.defaultValue.android;
        this.android.resolveFadeLayer().view().setBackgroundColor(nativeColor);
    };
    RadSideDrawer.prototype._onDrawerLocationChanged = function (oldValue, newValue) {
        _super.prototype._onDrawerLocationChanged.call(this, oldValue, newValue);
        if (!this.android) {
            return;
        }
        if (!newValue) {
            return;
        }
        this.setDrawerLocation(newValue);
    };
    RadSideDrawer.prototype.setDrawerLocation = function (newLocation) {
        switch (newLocation) {
            case commonModule.SideDrawerLocation.Left:
                this.android.setDrawerLocation(com.telerik.android.primitives.widget.sidedrawer.DrawerLocation.LEFT);
                break;
            case commonModule.SideDrawerLocation.Right:
                this.android.setDrawerLocation(com.telerik.android.primitives.widget.sidedrawer.DrawerLocation.RIGHT);
                break;
            case commonModule.SideDrawerLocation.Top:
                this.android.setDrawerLocation(com.telerik.android.primitives.widget.sidedrawer.DrawerLocation.TOP);
                break;
            case commonModule.SideDrawerLocation.Bottom:
                this.android.setDrawerLocation(com.telerik.android.primitives.widget.sidedrawer.DrawerLocation.BOTTOM);
                break;
        }
    };
    RadSideDrawer.prototype.closeDrawer = function () {
        if (this.android) {
            this.android.setIsOpen(false);
            _super.prototype.closeDrawer.call(this);
        }
    };
    RadSideDrawer.prototype.showDrawer = function () {
        if (this._android) {
            this._android.setIsOpen(true);
            _super.prototype.showDrawer.call(this);
        }
    };
    return RadSideDrawer;
}(commonModule.RadSideDrawer));
exports.RadSideDrawer = RadSideDrawer;
var DrawerTransitionBase = /** @class */ (function () {
    function DrawerTransitionBase() {
    }
    DrawerTransitionBase.prototype.getNativeContent = function () {
        return undefined;
    };
    return DrawerTransitionBase;
}());
exports.DrawerTransitionBase = DrawerTransitionBase;
var FadeTransition = /** @class */ (function (_super) {
    __extends(FadeTransition, _super);
    function FadeTransition() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    FadeTransition.prototype.getNativeContent = function () {
        return new com.telerik.android.primitives.widget.sidedrawer.transitions.FadeTransition();
    };
    return FadeTransition;
}(DrawerTransitionBase));
exports.FadeTransition = FadeTransition;
var PushTransition = /** @class */ (function (_super) {
    __extends(PushTransition, _super);
    function PushTransition() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    PushTransition.prototype.getNativeContent = function () {
        return new com.telerik.android.primitives.widget.sidedrawer.transitions.PushTransition();
    };
    return PushTransition;
}(DrawerTransitionBase));
exports.PushTransition = PushTransition;
var RevealTransition = /** @class */ (function (_super) {
    __extends(RevealTransition, _super);
    function RevealTransition() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    RevealTransition.prototype.getNativeContent = function () {
        return new com.telerik.android.primitives.widget.sidedrawer.transitions.RevealTransition();
    };
    return RevealTransition;
}(DrawerTransitionBase));
exports.RevealTransition = RevealTransition;
var ReverseSlideOutTransition = /** @class */ (function (_super) {
    __extends(ReverseSlideOutTransition, _super);
    function ReverseSlideOutTransition() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    ReverseSlideOutTransition.prototype.getNativeContent = function () {
        return new com.telerik.android.primitives.widget.sidedrawer.transitions.ReverseSlideOutTransition();
    };
    return ReverseSlideOutTransition;
}(DrawerTransitionBase));
exports.ReverseSlideOutTransition = ReverseSlideOutTransition;
var ScaleDownPusherTransition = /** @class */ (function (_super) {
    __extends(ScaleDownPusherTransition, _super);
    function ScaleDownPusherTransition() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    ScaleDownPusherTransition.prototype.getNativeContent = function () {
        return new com.telerik.android.primitives.widget.sidedrawer.transitions.ScaleDownPusherTransition();
    };
    return ScaleDownPusherTransition;
}(DrawerTransitionBase));
exports.ScaleDownPusherTransition = ScaleDownPusherTransition;
var ScaleUpTransition = /** @class */ (function (_super) {
    __extends(ScaleUpTransition, _super);
    function ScaleUpTransition() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    ScaleUpTransition.prototype.getNativeContent = function () {
        return new com.telerik.android.primitives.widget.sidedrawer.transitions.ScaleUpTransition();
    };
    return ScaleUpTransition;
}(DrawerTransitionBase));
exports.ScaleUpTransition = ScaleUpTransition;
var SlideAlongTransition = /** @class */ (function (_super) {
    __extends(SlideAlongTransition, _super);
    function SlideAlongTransition() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    SlideAlongTransition.prototype.getNativeContent = function () {
        return new com.telerik.android.primitives.widget.sidedrawer.transitions.SlideAlongTransition();
    };
    return SlideAlongTransition;
}(DrawerTransitionBase));
exports.SlideAlongTransition = SlideAlongTransition;
var SlideInOnTopTransition = /** @class */ (function (_super) {
    __extends(SlideInOnTopTransition, _super);
    function SlideInOnTopTransition() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    SlideInOnTopTransition.prototype.getNativeContent = function () {
        return new com.telerik.android.primitives.widget.sidedrawer.transitions.SlideInOnTopTransition();
    };
    return SlideInOnTopTransition;
}(DrawerTransitionBase));
exports.SlideInOnTopTransition = SlideInOnTopTransition;
