Object.defineProperty(exports, "__esModule", { value: true });
var editable_text_base_1 = require("../editable-text-base");
var text_base_1 = require("../text-base");
var TextViewBase = (function (_super) {
    __extends(TextViewBase, _super);
    function TextViewBase() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return TextViewBase;
}(editable_text_base_1.EditableTextBase));
exports.TextViewBase = TextViewBase;
exports.maxLinesProperty = new text_base_1.Property({ name: "maxLines", valueConverter: parseInt });
exports.maxLinesProperty.register(editable_text_base_1.EditableTextBase);
//# sourceMappingURL=text-view-common.js.map