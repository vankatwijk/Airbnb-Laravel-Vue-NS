Object.defineProperty(exports, "__esModule", { value: true });
var layout_base_1 = require("../layouts/layout-base");
var properties_1 = require("../core/properties/properties");
var trace_1 = require("../../trace/trace");
var ProxyViewContainer = (function (_super) {
    __extends(ProxyViewContainer, _super);
    function ProxyViewContainer() {
        var _this = _super.call(this) || this;
        _this.proxiedLayoutProperties = new Set();
        _this.nativeViewProtected = undefined;
        return _this;
    }
    Object.defineProperty(ProxyViewContainer.prototype, "ios", {
        get: function () {
            return null;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(ProxyViewContainer.prototype, "android", {
        get: function () {
            return null;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(ProxyViewContainer.prototype, "isLayoutRequested", {
        get: function () {
            return false;
        },
        enumerable: true,
        configurable: true
    });
    ProxyViewContainer.prototype.createNativeView = function () {
        return undefined;
    };
    ProxyViewContainer.prototype._getNativeViewsCount = function () {
        var result = 0;
        this.eachChildView(function (cv) {
            result += cv._getNativeViewsCount();
            return true;
        });
        return result;
    };
    ProxyViewContainer.prototype._eachLayoutView = function (callback) {
        this.eachChildView(function (cv) {
            if (!cv.isCollapsed) {
                cv._eachLayoutView(callback);
            }
            return true;
        });
    };
    ProxyViewContainer.prototype._addViewToNativeVisualTree = function (child, atIndex) {
        var _this = this;
        if (layout_base_1.traceEnabled()) {
            layout_base_1.traceWrite("ProxyViewContainer._addViewToNativeVisualTree for a child " + child + " ViewContainer.parent: " + this.parent, layout_base_1.traceCategories.ViewHierarchy);
        }
        _super.prototype._addViewToNativeVisualTree.call(this, child);
        layoutProperties.forEach(function (propName) {
            var proxyPropName = makeProxyPropName(propName);
            child[proxyPropName] = child[propName];
            if (_this.proxiedLayoutProperties.has(propName)) {
                _this._applyLayoutPropertyToChild(child, propName, _this[propName]);
            }
        });
        var parent = this.parent;
        if (parent instanceof layout_base_1.View) {
            var baseIndex = 0;
            var insideIndex = 0;
            if (parent instanceof layout_base_1.LayoutBase) {
                baseIndex = parent._childIndexToNativeChildIndex(parent.getChildIndex(this));
            }
            if (atIndex !== undefined) {
                insideIndex = this._childIndexToNativeChildIndex(atIndex);
            }
            else {
                insideIndex = this._getNativeViewsCount();
            }
            if (layout_base_1.traceEnabled()) {
                layout_base_1.traceWrite("ProxyViewContainer._addViewToNativeVisualTree at: " + atIndex + " base: " + baseIndex + " additional: " + insideIndex, layout_base_1.traceCategories.ViewHierarchy);
            }
            return parent._addViewToNativeVisualTree(child, baseIndex + insideIndex);
        }
        return false;
    };
    ProxyViewContainer.prototype._removeViewFromNativeVisualTree = function (child) {
        if (layout_base_1.traceEnabled()) {
            layout_base_1.traceWrite("ProxyViewContainer._removeViewFromNativeVisualTree for a child " + child + " ViewContainer.parent: " + this.parent, layout_base_1.traceCategories.ViewHierarchy);
        }
        _super.prototype._removeViewFromNativeVisualTree.call(this, child);
        var parent = this.parent;
        if (parent instanceof layout_base_1.View) {
            return parent._removeViewFromNativeVisualTree(child);
        }
    };
    ProxyViewContainer.prototype._registerLayoutChild = function (child) {
        var parent = this.parent;
        if (parent instanceof layout_base_1.LayoutBase) {
            parent._registerLayoutChild(child);
        }
    };
    ProxyViewContainer.prototype._unregisterLayoutChild = function (child) {
        var parent = this.parent;
        if (parent instanceof layout_base_1.LayoutBase) {
            parent._unregisterLayoutChild(child);
        }
    };
    ProxyViewContainer.prototype._parentChanged = function (oldParent) {
        _super.prototype._parentChanged.call(this, oldParent);
        var addingToParent = this.parent && !oldParent;
        var newLayout = this.parent;
        var oldLayout = oldParent;
        if (addingToParent && newLayout instanceof layout_base_1.LayoutBase) {
            this.eachLayoutChild(function (child) {
                newLayout._registerLayoutChild(child);
                return true;
            });
        }
        else if (oldLayout instanceof layout_base_1.LayoutBase) {
            this.eachLayoutChild(function (child) {
                oldLayout._unregisterLayoutChild(child);
                return true;
            });
        }
    };
    ProxyViewContainer.prototype._changedLayoutProperty = function (propName, value) {
        var _this = this;
        var numChildren = this._getNativeViewsCount();
        if (numChildren > 1) {
            layout_base_1.traceWrite("ProxyViewContainer._changeLayoutProperty - you're setting '" + propName + "' for " + this + " with more than one child. Probably this is not what you want, consider wrapping it in a StackLayout ", layout_base_1.traceCategories.ViewHierarchy, trace_1.messageType.error);
        }
        this.eachLayoutChild(function (child) {
            _this._applyLayoutPropertyToChild(child, propName, value);
            return true;
        });
        this.proxiedLayoutProperties.add(propName);
    };
    ProxyViewContainer.prototype._applyLayoutPropertyToChild = function (child, propName, value) {
        var proxyPropName = makeProxyPropName(propName);
        if (proxyPropName in child) {
            if (child[propName] !== child[proxyPropName]) {
                if (layout_base_1.traceEnabled()) {
                    layout_base_1.traceWrite("ProxyViewContainer._applyLayoutPropertyToChild child " + child + " has its own value [" + child[propName] + "] for [" + propName + "]", layout_base_1.traceCategories.ViewHierarchy);
                }
                return;
            }
        }
        child[propName] = value;
        child[proxyPropName] = value;
    };
    ProxyViewContainer = __decorate([
        layout_base_1.CSSType("ProxyViewContainer")
    ], ProxyViewContainer);
    return ProxyViewContainer;
}(layout_base_1.LayoutBase));
exports.ProxyViewContainer = ProxyViewContainer;
var layoutProperties = [
    "left",
    "top",
    "dock",
    "flexDirection",
    "flexWrap",
    "justifyContent",
    "alignItems",
    "alignContent",
    "order",
    "flexGrow",
    "flexShrink",
    "flexWrapBefore",
    "alignSelf",
    "flexFlow",
    "flex",
    "column",
    "columnSpan",
    "col",
    "colSpan",
    "row",
    "rowSpan",
];
var _loop_1 = function (name_1) {
    var proxyProperty = new properties_1.Property({
        name: name_1,
        valueChanged: function (target, oldValue, value) {
            target._changedLayoutProperty(name_1, value);
        }
    });
    proxyProperty.register(ProxyViewContainer);
};
for (var _i = 0, layoutProperties_1 = layoutProperties; _i < layoutProperties_1.length; _i++) {
    var name_1 = layoutProperties_1[_i];
    _loop_1(name_1);
}
function makeProxyPropName(propName) {
    return "_proxy:" + propName;
}
//# sourceMappingURL=proxy-view-container.js.map