Object.defineProperty(exports, "__esModule", { value: true });
var view_1 = require("../../core/view");
var content_view_1 = require("../../content-view");
exports.traceCategory = "TabView";
var TabContentItemBase = (function (_super) {
    __extends(TabContentItemBase, _super);
    function TabContentItemBase() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    TabContentItemBase.prototype.eachChild = function (callback) {
        if (this.content) {
            callback(this.content);
        }
    };
    TabContentItemBase.prototype.loadView = function (view) {
        var tabView = this.parent;
        if (tabView && tabView.items) {
            if (this.canBeLoaded) {
                _super.prototype.loadView.call(this, view);
            }
        }
    };
    TabContentItemBase = __decorate([
        view_1.CSSType("TabContentItem")
    ], TabContentItemBase);
    return TabContentItemBase;
}(content_view_1.ContentView));
exports.TabContentItemBase = TabContentItemBase;
//# sourceMappingURL=tab-content-item-common.js.map