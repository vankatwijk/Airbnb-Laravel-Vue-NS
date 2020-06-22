Object.defineProperty(exports, "__esModule", { value: true });
var core_1 = require("@angular/core");
var __1 = require("./..");
var page_1 = require("tns-core-modules/ui/page");
var element_registry_1 = require("nativescript-angular/element-registry");
var sideDrawerModule = require("./..");
var TKDRAWERCONTENT = "TKDrawerContent";
var TKMAINCONTENT = "TKMainContent";
/**
* This is the SideDrawer component. It separates your mobile app's screen
* into a main part and a menu part whereby the menu part is shown upon a swipe
* gesture using a transition effect.
*/
var RadSideDrawerComponent = /** @class */ (function () {
    function RadSideDrawerComponent(elementRef, page, viewContainer) {
        this.elementRef = elementRef;
        this.page = page;
        this.viewContainer = viewContainer;
        this.sideDrawerMovedToPage = false;
        this.drawerOpening = new core_1.EventEmitter();
        this.drawerOpen = new core_1.EventEmitter();
        this.drawerClosing = new core_1.EventEmitter();
        this.drawerClosed = new core_1.EventEmitter();
        this.sideDrawer = this.elementRef.nativeElement;
    }
    Object.defineProperty(RadSideDrawerComponent.prototype, "transition", {
        /**
          * [Deprecated: Please use the 'drawerTransition' property instead].
          */
        set: function (transition) {
            this.sideDrawer.drawerTransition = transition;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawerComponent.prototype, "nativeElement", {
        get: function () {
            return this.sideDrawer;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawerComponent.prototype, "drawerContentSize", {
        /**
          * Defines either the width or the height
          * of the menu pane depending on the location of the SideDrawer.
          * Top or Bottom - height, Right or Left - width.
          */
        set: function (value) {
            this._drawerContentSize = value;
            this.updateContentSize();
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawerComponent.prototype, "gesturesEnabled", {
        set: function (value) {
            this._gesturesEnabled = value;
            this.updateGesturesEnabled();
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawerComponent.prototype, "drawerTransition", {
        set: function (value) {
            this._drawerTransition = value;
            this.updateDrawerTransition();
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawerComponent.prototype, "drawerLocation", {
        set: function (value) {
            this._drawerLocation = value;
            this.updateDrawerLocation();
        },
        enumerable: true,
        configurable: true
    });
    RadSideDrawerComponent.prototype.updateDrawerLocation = function () {
        this.sideDrawer.drawerLocation = this._drawerLocation;
    };
    RadSideDrawerComponent.prototype.updateDrawerTransition = function () {
        this.sideDrawer.drawerTransition = this._drawerTransition;
    };
    RadSideDrawerComponent.prototype.updateGesturesEnabled = function () {
        this.sideDrawer.gesturesEnabled = this._gesturesEnabled;
    };
    RadSideDrawerComponent.prototype.updateContentSize = function () {
        this.sideDrawer.drawerContentSize = this._drawerContentSize;
    };
    __decorate([
        core_1.Output(),
        __metadata("design:type", core_1.EventEmitter)
    ], RadSideDrawerComponent.prototype, "drawerOpening", void 0);
    __decorate([
        core_1.Output(),
        __metadata("design:type", core_1.EventEmitter)
    ], RadSideDrawerComponent.prototype, "drawerOpen", void 0);
    __decorate([
        core_1.Output(),
        __metadata("design:type", core_1.EventEmitter)
    ], RadSideDrawerComponent.prototype, "drawerClosing", void 0);
    __decorate([
        core_1.Output(),
        __metadata("design:type", core_1.EventEmitter)
    ], RadSideDrawerComponent.prototype, "drawerClosed", void 0);
    __decorate([
        core_1.Input(),
        __metadata("design:type", sideDrawerModule.DrawerTransitionBase),
        __metadata("design:paramtypes", [sideDrawerModule.DrawerTransitionBase])
    ], RadSideDrawerComponent.prototype, "transition", null);
    RadSideDrawerComponent = __decorate([
        core_1.Component({
            selector: 'RadSideDrawer',
            template: "<ng-content></ng-content>"
        }),
        __param(0, core_1.Inject(core_1.ElementRef)),
        __param(1, core_1.Inject(page_1.Page)),
        __param(2, core_1.Inject(core_1.ViewContainerRef)),
        __metadata("design:paramtypes", [core_1.ElementRef,
            page_1.Page,
            core_1.ViewContainerRef])
    ], RadSideDrawerComponent);
    return RadSideDrawerComponent;
}());
exports.RadSideDrawerComponent = RadSideDrawerComponent;
/**
 * Directive identifying the drawer content.
 */
var TKDrawerContentDirective = /** @class */ (function () {
    function TKDrawerContentDirective(_elementRef) {
        this._elementRef = _elementRef;
        this._elementRef.nativeElement.id = TKDRAWERCONTENT;
    }
    TKDrawerContentDirective = __decorate([
        core_1.Directive({
            selector: "[tkDrawerContent]"
        }),
        __param(0, core_1.Inject(core_1.ElementRef)),
        __metadata("design:paramtypes", [core_1.ElementRef])
    ], TKDrawerContentDirective);
    return TKDrawerContentDirective;
}());
exports.TKDrawerContentDirective = TKDrawerContentDirective;
/**
 * Directive identifying the main content.
 */
var TKMainContentDirective = /** @class */ (function () {
    function TKMainContentDirective(_elementRef) {
        this._elementRef = _elementRef;
        this._elementRef.nativeElement.id = TKMAINCONTENT;
    }
    TKMainContentDirective = __decorate([
        core_1.Directive({
            selector: "[tkMainContent]"
        }),
        __param(0, core_1.Inject(core_1.ElementRef)),
        __metadata("design:paramtypes", [core_1.ElementRef])
    ], TKMainContentDirective);
    return TKMainContentDirective;
}());
exports.TKMainContentDirective = TKMainContentDirective;
var sideDrawerMeta = {
    insertChild: function (parent, child) {
        var drawer = parent;
        var childView = child;
        if (childView.id === TKMAINCONTENT) {
            drawer.mainContent = childView;
        }
        if (childView.id === TKDRAWERCONTENT) {
            drawer.drawerContent = childView;
        }
    },
    removeChild: function (parent, child) {
        var drawer = parent;
        var childView = child;
        if (childView.id === TKMAINCONTENT) {
            drawer.mainContent = null;
        }
        if (childView.id === TKDRAWERCONTENT) {
            drawer.drawerContent = null;
        }
    },
};
/**
 * Directives identifying the RadSideDrawer.
 */
exports.SIDEDRAWER_DIRECTIVES = [RadSideDrawerComponent, TKDrawerContentDirective, TKMainContentDirective];
element_registry_1.registerElement("RadSideDrawer", function () { return __1.RadSideDrawer; }, sideDrawerMeta);
/**
 * NgModule containing all of the RadSideDrawer directives.
 */
var NativeScriptUISideDrawerModule = /** @class */ (function () {
    function NativeScriptUISideDrawerModule() {
    }
    NativeScriptUISideDrawerModule = __decorate([
        core_1.NgModule({
            declarations: [exports.SIDEDRAWER_DIRECTIVES],
            exports: [exports.SIDEDRAWER_DIRECTIVES]
        })
    ], NativeScriptUISideDrawerModule);
    return NativeScriptUISideDrawerModule;
}());
exports.NativeScriptUISideDrawerModule = NativeScriptUISideDrawerModule;
