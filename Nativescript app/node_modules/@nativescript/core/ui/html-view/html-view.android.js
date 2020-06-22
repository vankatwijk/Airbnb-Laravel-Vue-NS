function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var color_1 = require("../../color");
var font_1 = require("../styling/font");
var style_properties_1 = require("../styling/style-properties");
var html_view_common_1 = require("./html-view-common");
__export(require("./html-view-common"));
var HtmlView = (function (_super) {
    __extends(HtmlView, _super);
    function HtmlView() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    HtmlView.prototype.createNativeView = function () {
        return new android.widget.TextView(this._context);
    };
    HtmlView.prototype.initNativeView = function () {
        _super.prototype.initNativeView.call(this);
        var nativeView = this.nativeViewProtected;
        nativeView.setTextIsSelectable(true);
        nativeView.setLinksClickable(true);
        nativeView.setMovementMethod(android.text.method.LinkMovementMethod.getInstance());
    };
    HtmlView.prototype.resetNativeView = function () {
        _super.prototype.resetNativeView.call(this);
        this.nativeViewProtected.setAutoLinkMask(0);
    };
    HtmlView.prototype[html_view_common_1.htmlProperty.getDefault] = function () {
        return "";
    };
    HtmlView.prototype[html_view_common_1.htmlProperty.setNative] = function (value) {
        var mask = 15;
        if (value.search(/<a\s/i) >= 0) {
            mask = 0;
        }
        this.nativeViewProtected.setAutoLinkMask(mask);
        this.nativeViewProtected.setText(android.text.Html.fromHtml(value));
    };
    HtmlView.prototype[style_properties_1.colorProperty.getDefault] = function () {
        return this.nativeViewProtected.getTextColors();
    };
    HtmlView.prototype[style_properties_1.colorProperty.setNative] = function (value) {
        if (value instanceof color_1.Color) {
            this.nativeViewProtected.setTextColor(value.android);
        }
        else {
            this.nativeViewProtected.setTextColor(value);
        }
    };
    HtmlView.prototype[html_view_common_1.linkColorProperty.getDefault] = function () {
        return this.nativeViewProtected.getLinkTextColors();
    };
    HtmlView.prototype[html_view_common_1.linkColorProperty.setNative] = function (value) {
        var color = value instanceof color_1.Color ? value.android : value;
        if (value instanceof color_1.Color) {
            this.nativeViewProtected.setLinkTextColor(value.android);
        }
        else {
            this.nativeViewProtected.setLinkTextColor(value);
        }
    };
    HtmlView.prototype[style_properties_1.fontInternalProperty.getDefault] = function () {
        return this.nativeViewProtected.getTypeface();
    };
    HtmlView.prototype[style_properties_1.fontInternalProperty.setNative] = function (value) {
        var font = value instanceof font_1.Font ? value.getAndroidTypeface() : value;
        this.nativeViewProtected.setTypeface(font);
    };
    HtmlView.prototype[style_properties_1.fontSizeProperty.getDefault] = function () {
        return { nativeSize: this.nativeViewProtected.getTextSize() };
    };
    HtmlView.prototype[style_properties_1.fontSizeProperty.setNative] = function (value) {
        if (typeof value === "number") {
            this.nativeViewProtected.setTextSize(value);
        }
        else {
            this.nativeViewProtected.setTextSize(android.util.TypedValue.COMPLEX_UNIT_PX, value.nativeSize);
        }
    };
    return HtmlView;
}(html_view_common_1.HtmlViewBase));
exports.HtmlView = HtmlView;
//# sourceMappingURL=html-view.android.js.map