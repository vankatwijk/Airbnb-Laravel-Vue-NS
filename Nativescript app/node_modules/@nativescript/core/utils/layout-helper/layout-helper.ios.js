function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var layout_helper_common_1 = require("./layout-helper-common");
__export(require("./layout-helper-common"));
var mainScreenScale;
function makeMeasureSpec(size, mode) {
    return (Math.round(Math.max(0, size)) & ~layout_helper_common_1.MODE_MASK) | (mode & layout_helper_common_1.MODE_MASK);
}
exports.makeMeasureSpec = makeMeasureSpec;
function getDisplayDensity() {
    return mainScreenScale;
}
exports.getDisplayDensity = getDisplayDensity;
function toDevicePixels(value) {
    return value * mainScreenScale;
}
exports.toDevicePixels = toDevicePixels;
function toDeviceIndependentPixels(value) {
    return value / mainScreenScale;
}
exports.toDeviceIndependentPixels = toDeviceIndependentPixels;
function measureNativeView(nativeView, width, widthMode, height, heightMode) {
    var view = nativeView;
    var nativeSize = view.sizeThatFits({
        width: widthMode === 0 ? Number.POSITIVE_INFINITY : toDeviceIndependentPixels(width),
        height: heightMode === 0 ? Number.POSITIVE_INFINITY : toDeviceIndependentPixels(height)
    });
    nativeSize.width = layout_helper_common_1.round(toDevicePixels(nativeSize.width));
    nativeSize.height = layout_helper_common_1.round(toDevicePixels(nativeSize.height));
    return nativeSize;
}
exports.measureNativeView = measureNativeView;
mainScreenScale = UIScreen.mainScreen.scale;
//# sourceMappingURL=layout-helper.ios.js.map