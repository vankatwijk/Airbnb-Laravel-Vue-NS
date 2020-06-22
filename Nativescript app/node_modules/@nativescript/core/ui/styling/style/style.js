Object.defineProperty(exports, "__esModule", { value: true });
var observable_1 = require("../../../data/observable");
var trace_1 = require("../../../trace");
var Style = (function (_super) {
    __extends(Style, _super);
    function Style(ownerView) {
        var _this = _super.call(this) || this;
        _this.unscopedCssVariables = new Map();
        _this.scopedCssVariables = new Map();
        if (ownerView.constructor.toString().indexOf("[native code]") !== -1) {
            _this.viewRef = ownerView;
        }
        else {
            _this.viewRef = new WeakRef(ownerView);
        }
        return _this;
    }
    Style.prototype.setScopedCssVariable = function (varName, value) {
        this.scopedCssVariables.set(varName, value);
    };
    Style.prototype.setUnscopedCssVariable = function (varName, value) {
        this.unscopedCssVariables.set(varName, value);
    };
    Style.prototype.getCssVariable = function (varName) {
        var view = this.view;
        if (!view) {
            return null;
        }
        if (this.unscopedCssVariables.has(varName)) {
            return this.unscopedCssVariables.get(varName);
        }
        if (this.scopedCssVariables.has(varName)) {
            return this.scopedCssVariables.get(varName);
        }
        if (!view.parent || !view.parent.style) {
            return null;
        }
        return view.parent.style.getCssVariable(varName);
    };
    Style.prototype.resetScopedCssVariables = function () {
        this.scopedCssVariables.clear();
    };
    Style.prototype.resetUnscopedCssVariables = function () {
        this.unscopedCssVariables.clear();
    };
    Style.prototype.toString = function () {
        var view = this.viewRef.get();
        if (!view) {
            trace_1.write("toString() of Style cannot execute correctly because \".viewRef\" is cleared", trace_1.categories.Animation, trace_1.messageType.warn);
            return "";
        }
        return view + ".style";
    };
    Object.defineProperty(Style.prototype, "view", {
        get: function () {
            if (this.viewRef) {
                return this.viewRef.get();
            }
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    return Style;
}(observable_1.Observable));
exports.Style = Style;
Style.prototype.PropertyBag = (function () {
    function class_1() {
    }
    return class_1;
}());
//# sourceMappingURL=style.js.map