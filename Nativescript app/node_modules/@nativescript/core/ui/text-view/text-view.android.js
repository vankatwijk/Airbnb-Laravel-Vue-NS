function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var text_view_common_1 = require("./text-view-common");
var editable_text_base_1 = require("../editable-text-base");
__export(require("../text-base"));
var TextView = (function (_super) {
    __extends(TextView, _super);
    function TextView() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    TextView.prototype._configureEditText = function (editText) {
        editText.setInputType(android.text.InputType.TYPE_CLASS_TEXT | android.text.InputType.TYPE_TEXT_VARIATION_NORMAL | android.text.InputType.TYPE_TEXT_FLAG_CAP_SENTENCES | android.text.InputType.TYPE_TEXT_FLAG_MULTI_LINE | android.text.InputType.TYPE_TEXT_FLAG_NO_SUGGESTIONS);
        editText.setGravity(android.view.Gravity.TOP | android.view.Gravity.START);
    };
    TextView.prototype.resetNativeView = function () {
        _super.prototype.resetNativeView.call(this);
        this.nativeTextViewProtected.setGravity(android.view.Gravity.TOP | android.view.Gravity.START);
    };
    TextView.prototype[text_view_common_1.maxLinesProperty.getDefault] = function () {
        return 0;
    };
    TextView.prototype[text_view_common_1.maxLinesProperty.setNative] = function (value) {
        if (value <= 0) {
            this.nativeTextViewProtected.setMaxLines(Number.MAX_VALUE);
            return;
        }
        this.nativeTextViewProtected.setMaxLines(value);
    };
    TextView = __decorate([
        editable_text_base_1.CSSType("TextView")
    ], TextView);
    return TextView;
}(text_view_common_1.TextViewBase));
exports.TextView = TextView;
TextView.prototype.recycleNativeView = "auto";
//# sourceMappingURL=text-view.android.js.map