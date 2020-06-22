Object.defineProperty(exports, "__esModule", { value: true });
exports.MODE_SHIFT = 30;
exports.MODE_MASK = 0x3 << exports.MODE_SHIFT;
exports.UNSPECIFIED = 0 << exports.MODE_SHIFT;
exports.EXACTLY = 1 << exports.MODE_SHIFT;
exports.AT_MOST = 2 << exports.MODE_SHIFT;
exports.MEASURED_HEIGHT_STATE_SHIFT = 0x00000010;
exports.MEASURED_STATE_TOO_SMALL = 0x01000000;
exports.MEASURED_STATE_MASK = 0xff000000;
exports.MEASURED_SIZE_MASK = 0x00ffffff;
function getMode(mode) {
    switch (mode) {
        case exports.EXACTLY:
            return "Exact";
        case exports.AT_MOST:
            return "AtMost";
        default:
            return "Unspecified";
    }
}
exports.getMode = getMode;
function getMeasureSpecMode(spec) {
    return (spec & exports.MODE_MASK);
}
exports.getMeasureSpecMode = getMeasureSpecMode;
function getMeasureSpecSize(spec) {
    return (spec & ~exports.MODE_MASK);
}
exports.getMeasureSpecSize = getMeasureSpecSize;
function measureSpecToString(measureSpec) {
    var mode = getMeasureSpecMode(measureSpec);
    var size = getMeasureSpecSize(measureSpec);
    var text = "MeasureSpec: ";
    if (mode === exports.UNSPECIFIED) {
        text += "UNSPECIFIED ";
    }
    else if (mode === exports.EXACTLY) {
        text += "EXACTLY ";
    }
    else if (mode === exports.AT_MOST) {
        text += "AT_MOST ";
    }
    text += size;
    return text;
}
exports.measureSpecToString = measureSpecToString;
function round(value) {
    var res = Math.floor(value + 0.5);
    if (res !== 0) {
        return res;
    }
    else if (value === 0) {
        return 0;
    }
    else if (value > 0) {
        return 1;
    }
    return -1;
}
exports.round = round;
//# sourceMappingURL=layout-helper-common.js.map