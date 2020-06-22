"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var content_view_1 = require("tns-core-modules/ui/content-view");
var text_view_1 = require("tns-core-modules/ui/text-view");
var PreviousNextView = (function (_super) {
    __extends(PreviousNextView, _super);
    function PreviousNextView() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    PreviousNextView.prototype.createNativeView = function () {
        return IQPreviousNextView.new();
    };
    return PreviousNextView;
}(content_view_1.ContentView));
exports.PreviousNextView = PreviousNextView;
var TextViewWithHint = (function (_super) {
    __extends(TextViewWithHint, _super);
    function TextViewWithHint() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    TextViewWithHint.prototype.createNativeView = function () {
        var view = IQTextView.new();
        this.nativeView = view;
        view.placeholder = this.hint;
        return view;
    };
    return TextViewWithHint;
}(text_view_1.TextView));
exports.TextViewWithHint = TextViewWithHint;
