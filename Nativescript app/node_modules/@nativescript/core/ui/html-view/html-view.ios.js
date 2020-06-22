function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var color_1 = require("../../color");
var font_1 = require("../styling/font");
var style_properties_1 = require("../styling/style-properties");
var html_view_common_1 = require("./html-view-common");
var utils_1 = require("../../utils/utils");
__export(require("./html-view-common"));
var majorVersion = utils_1.ios.MajorVersion;
var HtmlView = (function (_super) {
    __extends(HtmlView, _super);
    function HtmlView() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    HtmlView.prototype.createNativeView = function () {
        var view = UITextView.new();
        view.scrollEnabled = false;
        view.editable = false;
        view.selectable = true;
        view.userInteractionEnabled = true;
        view.dataDetectorTypes = -1;
        return view;
    };
    HtmlView.prototype.initNativeView = function () {
        _super.prototype.initNativeView.call(this);
        this.nativeViewProtected.textContainer.lineFragmentPadding = 0;
        this.nativeViewProtected.textContainerInset = UIEdgeInsets.zero;
    };
    Object.defineProperty(HtmlView.prototype, "ios", {
        get: function () {
            return this.nativeViewProtected;
        },
        enumerable: true,
        configurable: true
    });
    HtmlView.prototype.onMeasure = function (widthMeasureSpec, heightMeasureSpec) {
        var nativeView = this.nativeViewProtected;
        if (nativeView) {
            var width = html_view_common_1.layout.getMeasureSpecSize(widthMeasureSpec);
            var widthMode = html_view_common_1.layout.getMeasureSpecMode(widthMeasureSpec);
            var height = html_view_common_1.layout.getMeasureSpecSize(heightMeasureSpec);
            var heightMode = html_view_common_1.layout.getMeasureSpecMode(heightMeasureSpec);
            var desiredSize = html_view_common_1.layout.measureNativeView(nativeView, width, widthMode, height, heightMode);
            var labelWidth = widthMode === html_view_common_1.layout.AT_MOST ? Math.min(desiredSize.width, width) : desiredSize.width;
            var measureWidth = Math.max(labelWidth, this.effectiveMinWidth);
            var measureHeight = Math.max(desiredSize.height, this.effectiveMinHeight);
            var widthAndState = html_view_common_1.View.resolveSizeAndState(measureWidth, width, widthMode, 0);
            var heightAndState = html_view_common_1.View.resolveSizeAndState(measureHeight, height, heightMode, 0);
            this.setMeasuredDimension(widthAndState, heightAndState);
        }
    };
    HtmlView.prototype[html_view_common_1.htmlProperty.getDefault] = function () {
        return "";
    };
    HtmlView.prototype.renderWithStyles = function () {
        var _a;
        var html = this.currentHtml;
        var styles = [];
        if (this.nativeViewProtected.font) {
            styles.push("font-family: '" + this.nativeViewProtected.font.fontName + "';");
            styles.push("font-size: " + this.nativeViewProtected.font.pointSize + "px;");
        }
        if (this.nativeViewProtected.textColor) {
            var textColor = color_1.Color.fromIosColor(this.nativeViewProtected.textColor);
            styles.push("color: " + textColor.hex + ";");
        }
        if (styles.length > 0) {
            html += "<style>body {" + styles.join("") + "}</style>";
        }
        var htmlString = NSString.stringWithString(html + "");
        var nsData = htmlString.dataUsingEncoding(NSUnicodeStringEncoding);
        this.nativeViewProtected.attributedText = NSAttributedString.alloc().initWithDataOptionsDocumentAttributesError(nsData, (_a = {}, _a[NSDocumentTypeDocumentAttribute] = NSHTMLTextDocumentType, _a), null);
        if (majorVersion >= 13 && UIColor.labelColor) {
            this.nativeViewProtected.textColor = UIColor.labelColor;
        }
    };
    HtmlView.prototype[html_view_common_1.htmlProperty.setNative] = function (value) {
        this.currentHtml = value;
        this.renderWithStyles();
    };
    HtmlView.prototype[style_properties_1.colorProperty.getDefault] = function () {
        return this.nativeViewProtected.textColor;
    };
    HtmlView.prototype[style_properties_1.colorProperty.setNative] = function (value) {
        var color = value instanceof color_1.Color ? value.ios : value;
        this.nativeViewProtected.textColor = color;
        this.renderWithStyles();
    };
    HtmlView.prototype[html_view_common_1.linkColorProperty.getDefault] = function () {
        return this.nativeViewProtected.linkTextAttributes[NSForegroundColorAttributeName];
    };
    HtmlView.prototype[html_view_common_1.linkColorProperty.setNative] = function (value) {
        var color = value instanceof color_1.Color ? value.ios : value;
        var linkTextAttributes = NSDictionary.dictionaryWithObjectForKey(color, NSForegroundColorAttributeName);
        this.nativeViewProtected.linkTextAttributes = linkTextAttributes;
    };
    HtmlView.prototype[style_properties_1.fontInternalProperty.getDefault] = function () {
        return this.nativeViewProtected.font;
    };
    HtmlView.prototype[style_properties_1.fontInternalProperty.setNative] = function (value) {
        var font = value instanceof font_1.Font ? value.getUIFont(this.nativeViewProtected.font) : value;
        this.nativeViewProtected.font = font;
        this.renderWithStyles();
    };
    return HtmlView;
}(html_view_common_1.HtmlViewBase));
exports.HtmlView = HtmlView;
//# sourceMappingURL=html-view.ios.js.map