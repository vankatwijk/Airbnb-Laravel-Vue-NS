"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var content_view_1 = require("tns-core-modules/ui/content-view");
var text_view_1 = require("tns-core-modules/ui/text-view");
var PreviousNextView = (function (_super) {
    __extends(PreviousNextView, _super);
    function PreviousNextView() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return PreviousNextView;
}(content_view_1.ContentView));
exports.PreviousNextView = PreviousNextView;
var TextViewWithHint = (function (_super) {
    __extends(TextViewWithHint, _super);
    function TextViewWithHint() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return TextViewWithHint;
}(text_view_1.TextView));
exports.TextViewWithHint = TextViewWithHint;
