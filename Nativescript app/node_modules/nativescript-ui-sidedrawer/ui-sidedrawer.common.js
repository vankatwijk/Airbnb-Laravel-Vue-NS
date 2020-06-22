Object.defineProperty(exports, "__esModule", { value: true });
var view_1 = require("tns-core-modules/ui/core/view");
var colorModule = require("tns-core-modules/color");
exports.FadeTransitionString = "fadetransition";
exports.PushTransitionString = "pushtransition";
exports.RevealTransitionString = "revealtransition";
exports.ReverseSlideOutTransitionString = "reverseslideouttransition";
exports.ScaleDownPusherTransitionString = "scaledownpushertransition";
exports.ScaleUpTransitionString = "scaleuptransition";
exports.SlideAlongTransitionString = "slidealongtransition";
exports.SlideInOnTopTransitionString = "slideinontoptransition";
var SideDrawerLocation;
(function (SideDrawerLocation) {
    SideDrawerLocation["Left"] = "Left";
    SideDrawerLocation["Right"] = "Right";
    SideDrawerLocation["Top"] = "Top";
    SideDrawerLocation["Bottom"] = "Bottom";
})(SideDrawerLocation = exports.SideDrawerLocation || (exports.SideDrawerLocation = {}));
var DrawerTransitionBase = /** @class */ (function () {
    function DrawerTransitionBase() {
    }
    DrawerTransitionBase.prototype.getNativeContent = function () {
        return undefined;
    };
    return DrawerTransitionBase;
}());
exports.DrawerTransitionBase = DrawerTransitionBase;
var DrawerStateChangingEventArgs = /** @class */ (function () {
    function DrawerStateChangingEventArgs() {
    }
    return DrawerStateChangingEventArgs;
}());
exports.DrawerStateChangingEventArgs = DrawerStateChangingEventArgs;
var DrawerStateChangedEventArgs = /** @class */ (function () {
    function DrawerStateChangedEventArgs() {
    }
    return DrawerStateChangedEventArgs;
}());
exports.DrawerStateChangedEventArgs = DrawerStateChangedEventArgs;
var RadSideDrawer = /** @class */ (function (_super) {
    __extends(RadSideDrawer, _super);
    function RadSideDrawer() {
        var _this = _super !== null && _super.apply(this, arguments) || this;
        _this.shadowColor = RadSideDrawer_1.shadowColorProperty.defaultValue;
        return _this;
    }
    RadSideDrawer_1 = RadSideDrawer;
    RadSideDrawer.prototype.onGesturesEnabledPropertyChanged = function (oldValue, newValue) {
        this._onGesturesEnabledChanged(oldValue, newValue);
    };
    RadSideDrawer.prototype.onAllowEdgeSwipePropertyChanged = function (oldValue, newValue) {
        this._onAllowEdgeSwipeChanged(oldValue, newValue);
    };
    RadSideDrawer.prototype.onDrawerTransitionChanged = function (oldValue, newValue) {
        this._onDrawerTransitionChanged(oldValue, newValue);
    };
    RadSideDrawer.prototype.onDrawerContentSizeChanged = function (oldValue, newValue) {
        this._onDrawerContentSizeChanged(oldValue, newValue);
    };
    RadSideDrawer.prototype.onDrawerLocationPropertyChanged = function (oldValue, newValue) {
        this._onDrawerLocationChanged(oldValue, newValue);
    };
    RadSideDrawer.prototype.onShadowColorPropertyChanged = function (oldValue, newValue) {
        this._onShadowColorChanged(oldValue, newValue);
    };
    RadSideDrawer.prototype._onMainContentPropertyChanged = function (oldValue, newValue) {
        this._onMainContentChanged(oldValue, newValue);
    };
    RadSideDrawer.prototype._onDrawerContentPropertyChanged = function (oldValue, newValue) {
        this._onDrawerContentChanged(oldValue, newValue);
    };
    RadSideDrawer.prototype._onMainContentChanged = function (oldValue, newValue) {
        if (oldValue) {
            this._removeView(oldValue);
        }
        if (newValue) {
            this._addView(newValue);
        }
    };
    RadSideDrawer.prototype._onDrawerContentChanged = function (oldValue, newValue) {
        if (oldValue) {
            this._removeView(oldValue);
        }
        if (newValue) {
            this._addView(newValue);
        }
    };
    RadSideDrawer.prototype._onDrawerLocationChanged = function (oldValue, newValue) { };
    RadSideDrawer.prototype._onShadowColorChanged = function (oldValue, newValue) { };
    RadSideDrawer.prototype._onDrawerTransitionChanged = function (oldValue, newValue) { };
    RadSideDrawer.prototype._onDrawerContentSizeChanged = function (oldValue, newValue) { };
    RadSideDrawer.prototype._onGesturesEnabledChanged = function (oldValue, newValue) { };
    RadSideDrawer.prototype._onAllowEdgeSwipeChanged = function (oldValue, newValue) { };
    RadSideDrawer.prototype.showDrawer = function () {
    };
    RadSideDrawer.prototype.closeDrawer = function () {
    };
    RadSideDrawer.prototype.getIsOpen = function () {
        var androidIsOpen = false;
        var iosIsOpen = false;
        if (this.android) {
            androidIsOpen = this.android.getIsOpen();
        }
        if (this.ios) {
            iosIsOpen = this.ios.defaultSideDrawer.isVisible;
        }
        var result = androidIsOpen || iosIsOpen;
        if (result) {
            return result;
        }
        return false;
    };
    Object.defineProperty(RadSideDrawer.prototype, "_isRootView", {
        get: function () {
            return this.page ? false : true;
        },
        enumerable: true,
        configurable: true
    });
    RadSideDrawer.prototype.toggleDrawerState = function () {
        if (this.getIsOpen()) {
            this.closeDrawer();
        }
        else {
            this.showDrawer();
        }
    };
    Object.defineProperty(RadSideDrawer.prototype, "_childrenCount", {
        get: function () {
            var count = 0;
            if (this.drawerContent) {
                count++;
            }
            if (this.mainContent) {
                count++;
            }
            return count;
        },
        enumerable: true,
        configurable: true
    });
    RadSideDrawer.prototype.eachChildView = function (callback) {
        var mainContent = this.mainContent;
        if (mainContent) {
            callback(mainContent);
        }
        var drawerContent = this.drawerContent;
        if (drawerContent) {
            callback(drawerContent);
        }
    };
    var RadSideDrawer_1;
    RadSideDrawer.drawerOpeningEvent = "drawerOpening";
    RadSideDrawer.drawerOpenedEvent = "drawerOpened";
    RadSideDrawer.drawerClosingEvent = "drawerClosing";
    RadSideDrawer.drawerClosedEvent = "drawerClosed";
    RadSideDrawer.drawerPanEvent = "drawerPan";
    RadSideDrawer.gesturesEnabledProperty = new view_1.Property({
        name: "gesturesEnabled",
        defaultValue: true,
        valueConverter: view_1.booleanConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.onGesturesEnabledPropertyChanged(oldValue, newValue);
        },
    });
    RadSideDrawer.allowEdgeSwipeProperty = new view_1.Property({
        name: "allowEdgeSwipe",
        defaultValue: true,
        valueConverter: view_1.booleanConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.onAllowEdgeSwipePropertyChanged(oldValue, newValue);
        },
    });
    RadSideDrawer.drawerTransitionProperty = new view_1.Property({
        name: "drawerTransition",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onDrawerTransitionChanged(oldValue, newValue);
        },
    });
    RadSideDrawer.drawerContentSizeProperty = new view_1.Property({
        name: "drawerContentSize",
        defaultValue: 280,
        valueConverter: parseInt,
        valueChanged: function (target, oldValue, newValue) {
            target.onDrawerContentSizeChanged(oldValue, newValue);
        },
    });
    RadSideDrawer.drawerLocationProperty = new view_1.Property({
        name: "drawerLocation",
        defaultValue: SideDrawerLocation.Left,
        valueConverter: function (value) { return SideDrawerLocation[value]; },
        valueChanged: function (target, oldValue, newValue) {
            target.onDrawerLocationPropertyChanged(oldValue, newValue);
        },
    });
    RadSideDrawer.shadowColorProperty = new view_1.Property({
        name: "shadowColor",
        defaultValue: new colorModule.Color("#000000"),
        valueConverter: function (value) { return new colorModule.Color(value); },
        valueChanged: function (target, oldValue, newValue) {
            target.onShadowColorPropertyChanged(oldValue, newValue);
        },
    });
    RadSideDrawer.mainContentProperty = new view_1.Property({
        name: "mainContent",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target._onMainContentPropertyChanged(oldValue, newValue);
        },
    });
    RadSideDrawer.drawerContentProperty = new view_1.Property({
        name: "drawerContent",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target._onDrawerContentPropertyChanged(oldValue, newValue);
        },
    });
    RadSideDrawer = RadSideDrawer_1 = __decorate([
        view_1.CSSType("RadSideDrawer")
    ], RadSideDrawer);
    return RadSideDrawer;
}(view_1.ContainerView));
exports.RadSideDrawer = RadSideDrawer;
RadSideDrawer.gesturesEnabledProperty.register(RadSideDrawer);
RadSideDrawer.allowEdgeSwipeProperty.register(RadSideDrawer);
RadSideDrawer.drawerTransitionProperty.register(RadSideDrawer);
RadSideDrawer.drawerContentSizeProperty.register(RadSideDrawer);
RadSideDrawer.drawerLocationProperty.register(RadSideDrawer);
RadSideDrawer.shadowColorProperty.register(RadSideDrawer);
RadSideDrawer.mainContentProperty.register(RadSideDrawer);
RadSideDrawer.drawerContentProperty.register(RadSideDrawer);
