Object.defineProperty(exports, "__esModule", { value: true });
var ios;
(function (ios) {
    function getActualHeight(view) {
        throw new Error("Not implemented for Android");
    }
    ios.getActualHeight = getActualHeight;
    function getStatusBarHeight(viewController) {
        throw new Error("Not implemented for Android");
    }
    ios.getStatusBarHeight = getStatusBarHeight;
    function _layoutRootView(rootView, parentBounds) {
        throw new Error("Not implemented for Android");
    }
    ios._layoutRootView = _layoutRootView;
})(ios = exports.ios || (exports.ios = {}));
//# sourceMappingURL=utils.android.js.map