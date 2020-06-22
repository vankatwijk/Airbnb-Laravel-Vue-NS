function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var color_1 = require("../../color");
var properties_1 = require("../core/properties");
var view_1 = require("../core/view");
__export(require("../core/view"));
var HtmlViewBase = (function (_super) {
    __extends(HtmlViewBase, _super);
    function HtmlViewBase() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    HtmlViewBase = __decorate([
        view_1.CSSType("HtmlView")
    ], HtmlViewBase);
    return HtmlViewBase;
}(view_1.View));
exports.HtmlViewBase = HtmlViewBase;
HtmlViewBase.prototype.recycleNativeView = "auto";
exports.htmlProperty = new view_1.Property({ name: "html", defaultValue: "", affectsLayout: true });
exports.htmlProperty.register(HtmlViewBase);
exports.linkColorProperty = new properties_1.CssProperty({
    name: "linkColor",
    cssName: "link-color",
    equalityComparer: color_1.Color.equals,
    valueConverter: function (value) { return new color_1.Color(value); },
});
exports.linkColorProperty.register(properties_1.Style);
//# sourceMappingURL=html-view-common.js.map