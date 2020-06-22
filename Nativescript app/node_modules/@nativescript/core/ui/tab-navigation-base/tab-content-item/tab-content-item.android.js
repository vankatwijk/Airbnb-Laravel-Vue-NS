function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var grid_layout_1 = require("../../layouts/grid-layout");
var tab_content_item_common_1 = require("./tab-content-item-common");
var view_1 = require("../../core/view");
__export(require("./tab-content-item-common"));
var TabContentItem = (function (_super) {
    __extends(TabContentItem, _super);
    function TabContentItem() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    Object.defineProperty(TabContentItem.prototype, "_hasFragments", {
        get: function () {
            return true;
        },
        enumerable: true,
        configurable: true
    });
    TabContentItem.prototype.createNativeView = function () {
        var layout = new org.nativescript.widgets.GridLayout(this._context);
        layout.addRow(new org.nativescript.widgets.ItemSpec(1, org.nativescript.widgets.GridUnitType.star));
        return layout;
    };
    TabContentItem.prototype.initNativeView = function () {
        _super.prototype.initNativeView.call(this);
    };
    TabContentItem.prototype._addViewToNativeVisualTree = function (child, atIndex) {
        if (this.nativeViewProtected && child.nativeViewProtected) {
            grid_layout_1.GridLayout.setRow(child, 0);
        }
        return _super.prototype._addViewToNativeVisualTree.call(this, child, atIndex);
    };
    TabContentItem.prototype.disposeNativeView = function () {
        _super.prototype.disposeNativeView.call(this);
        this.canBeLoaded = false;
    };
    TabContentItem.prototype._getChildFragmentManager = function () {
        var tabView = this.parent;
        var tabFragment = null;
        var fragmentManager = tabView._getFragmentManager();
        if (typeof this.index === "undefined") {
            view_1.traceWrite("Current TabContentItem index is not set", tab_content_item_common_1.traceCategory, view_1.traceMessageType.error);
        }
        for (var _i = 0, _a = fragmentManager.getFragments().toArray(); _i < _a.length; _i++) {
            var fragment = _a[_i];
            if (fragment.index === this.index) {
                tabFragment = fragment;
                break;
            }
        }
        if (!tabFragment) {
            return tabView._getRootFragmentManager();
        }
        return tabFragment.getChildFragmentManager();
    };
    return TabContentItem;
}(tab_content_item_common_1.TabContentItemBase));
exports.TabContentItem = TabContentItem;
//# sourceMappingURL=tab-content-item.android.js.map