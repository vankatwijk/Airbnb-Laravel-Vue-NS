function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
var layout_helper_common_1 = require("./layout-helper-common");
var native_helper_1 = require("../native-helper");
__export(require("./layout-helper-common"));
var density;
var sdkVersion;
var useOldMeasureSpec = false;
function makeMeasureSpec(size, mode) {
    if (sdkVersion === undefined) {
        sdkVersion = native_helper_1.ad.getApplicationContext().getApplicationInfo().targetSdkVersion;
        useOldMeasureSpec = sdkVersion <= android.os.Build.VERSION_CODES.JELLY_BEAN_MR1;
    }
    if (useOldMeasureSpec) {
        return size + mode;
    }
    return (size & ~layout_helper_common_1.MODE_MASK) | (mode & layout_helper_common_1.MODE_MASK);
}
exports.makeMeasureSpec = makeMeasureSpec;
function getDisplayDensity() {
    if (density === undefined) {
        density = native_helper_1.ad.getResources().getDisplayMetrics().density;
    }
    return density;
}
exports.getDisplayDensity = getDisplayDensity;
function toDevicePixels(value) {
    return value * getDisplayDensity();
}
exports.toDevicePixels = toDevicePixels;
function toDeviceIndependentPixels(value) {
    return value / getDisplayDensity();
}
exports.toDeviceIndependentPixels = toDeviceIndependentPixels;
function measureNativeView(nativeView, width, widthMode, height, heightMode) {
    var view = nativeView;
    view.measure(makeMeasureSpec(width, widthMode), makeMeasureSpec(height, heightMode));
    return {
        width: view.getMeasuredWidth(),
        height: view.getMeasuredHeight()
    };
}
exports.measureNativeView = measureNativeView;
//# sourceMappingURL=layout-helper.android.js.map