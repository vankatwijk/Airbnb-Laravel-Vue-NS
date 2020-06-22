function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var tab_content_item_common_1 = require("./tab-content-item-common");
__export(require("./tab-content-item-common"));
var TabContentItem = (function (_super) {
    __extends(TabContentItem, _super);
    function TabContentItem() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    TabContentItem.prototype.setViewController = function (controller, nativeView) {
        this.__controller = controller;
        this.setNativeView(nativeView);
    };
    TabContentItem.prototype.disposeNativeView = function () {
        this.__controller = undefined;
        this.setNativeView(undefined);
    };
    return TabContentItem;
}(tab_content_item_common_1.TabContentItemBase));
exports.TabContentItem = TabContentItem;
//# sourceMappingURL=tab-content-item.ios.js.map