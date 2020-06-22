Object.defineProperty(exports, "__esModule", { value: true });
var utils_1 = require("../../../../utils/utils");
var trace_1 = require("../../../../trace");
var ViewHelper = (function () {
    function ViewHelper() {
    }
    ViewHelper.measureChild = function (parent, child, widthMeasureSpec, heightMeasureSpec) {
        var measureWidth = 0;
        var measureHeight = 0;
        if (child && !child.isCollapsed) {
            var widthSpec = parent ? parent._currentWidthMeasureSpec : widthMeasureSpec;
            var heightSpec = parent ? parent._currentHeightMeasureSpec : heightMeasureSpec;
            var width = utils_1.layout.getMeasureSpecSize(widthSpec);
            var widthMode = utils_1.layout.getMeasureSpecMode(widthSpec);
            var height = utils_1.layout.getMeasureSpecSize(heightSpec);
            var heightMode = utils_1.layout.getMeasureSpecMode(heightSpec);
            child._updateEffectiveLayoutValues(width, widthMode, height, heightMode);
            var style = child.style;
            var horizontalMargins = child.effectiveMarginLeft + child.effectiveMarginRight;
            var verticalMargins = child.effectiveMarginTop + child.effectiveMarginBottom;
            var childWidthMeasureSpec = ViewHelper.getMeasureSpec(widthMeasureSpec, horizontalMargins, child.effectiveWidth, style.horizontalAlignment === "stretch");
            var childHeightMeasureSpec = ViewHelper.getMeasureSpec(heightMeasureSpec, verticalMargins, child.effectiveHeight, style.verticalAlignment === "stretch");
            if (trace_1.isEnabled()) {
                trace_1.write(child.parent + " :measureChild: " + child + " " + utils_1.layout.measureSpecToString(childWidthMeasureSpec) + ", " + utils_1.layout.measureSpecToString(childHeightMeasureSpec) + "}", trace_1.categories.Layout);
            }
            child.measure(childWidthMeasureSpec, childHeightMeasureSpec);
            measureWidth = Math.round(child.getMeasuredWidth() + horizontalMargins);
            measureHeight = Math.round(child.getMeasuredHeight() + verticalMargins);
        }
        return { measuredWidth: measureWidth, measuredHeight: measureHeight };
    };
    ViewHelper.layoutChild = function (parent, child, left, top, right, bottom, setFrame) {
        if (setFrame === void 0) { setFrame = true; }
        if (!child || child.isCollapsed) {
            return;
        }
        var childStyle = child.style;
        var childTop;
        var childLeft;
        var childWidth = child.getMeasuredWidth();
        var childHeight = child.getMeasuredHeight();
        var effectiveMarginTop = child.effectiveMarginTop;
        var effectiveMarginBottom = child.effectiveMarginBottom;
        var vAlignment;
        if (child.effectiveHeight >= 0 && childStyle.verticalAlignment === "stretch") {
            vAlignment = "middle";
        }
        else {
            vAlignment = childStyle.verticalAlignment;
        }
        switch (vAlignment) {
            case "top":
                childTop = top + effectiveMarginTop;
                break;
            case "middle":
                childTop = top + (bottom - top - childHeight + (effectiveMarginTop - effectiveMarginBottom)) / 2;
                break;
            case "bottom":
                childTop = bottom - childHeight - effectiveMarginBottom;
                break;
            case "stretch":
            default:
                childTop = top + effectiveMarginTop;
                childHeight = bottom - top - (effectiveMarginTop + effectiveMarginBottom);
                break;
        }
        var effectiveMarginLeft = child.effectiveMarginLeft;
        var effectiveMarginRight = child.effectiveMarginRight;
        var hAlignment;
        if (child.effectiveWidth >= 0 && childStyle.horizontalAlignment === "stretch") {
            hAlignment = "center";
        }
        else {
            hAlignment = childStyle.horizontalAlignment;
        }
        switch (hAlignment) {
            case "left":
                childLeft = left + effectiveMarginLeft;
                break;
            case "center":
                childLeft = left + (right - left - childWidth + (effectiveMarginLeft - effectiveMarginRight)) / 2;
                break;
            case "right":
                childLeft = right - childWidth - effectiveMarginRight;
                break;
            case "stretch":
            default:
                childLeft = left + effectiveMarginLeft;
                childWidth = right - left - (effectiveMarginLeft + effectiveMarginRight);
                break;
        }
        var childRight = Math.round(childLeft + childWidth);
        var childBottom = Math.round(childTop + childHeight);
        childLeft = Math.round(childLeft);
        childTop = Math.round(childTop);
        if (trace_1.isEnabled()) {
            trace_1.write(child.parent + " :layoutChild: " + child + " " + childLeft + ", " + childTop + ", " + childRight + ", " + childBottom, trace_1.categories.Layout);
        }
        child.layout(childLeft, childTop, childRight, childBottom, setFrame);
    };
    ViewHelper.resolveSizeAndState = function (size, specSize, specMode, childMeasuredState) {
        var result = size;
        switch (specMode) {
            case utils_1.layout.UNSPECIFIED:
                result = Math.ceil(size);
                break;
            case utils_1.layout.AT_MOST:
                if (specSize < size) {
                    result = Math.ceil(specSize) | utils_1.layout.MEASURED_STATE_TOO_SMALL;
                }
                break;
            case utils_1.layout.EXACTLY:
                result = Math.ceil(specSize);
                break;
        }
        return result | (childMeasuredState & utils_1.layout.MEASURED_STATE_MASK);
    };
    ViewHelper.combineMeasuredStates = function (curState, newState) {
        return curState | newState;
    };
    ViewHelper.getMeasureSpec = function (parentSpec, margins, childLength, stretched) {
        var parentLength = utils_1.layout.getMeasureSpecSize(parentSpec);
        var parentSpecMode = utils_1.layout.getMeasureSpecMode(parentSpec);
        var resultSize;
        var resultMode;
        if (childLength >= 0) {
            resultSize = parentSpecMode === utils_1.layout.UNSPECIFIED ? childLength : Math.min(parentLength, childLength);
            resultMode = utils_1.layout.EXACTLY;
        }
        else {
            switch (parentSpecMode) {
                case utils_1.layout.EXACTLY:
                    resultSize = Math.max(0, parentLength - margins);
                    resultMode = stretched ? utils_1.layout.EXACTLY : utils_1.layout.AT_MOST;
                    break;
                case utils_1.layout.AT_MOST:
                    resultSize = Math.max(0, parentLength - margins);
                    resultMode = utils_1.layout.AT_MOST;
                    break;
                case utils_1.layout.UNSPECIFIED:
                    resultSize = 0;
                    resultMode = utils_1.layout.UNSPECIFIED;
                    break;
            }
        }
        return utils_1.layout.makeMeasureSpec(resultSize, resultMode);
    };
    return ViewHelper;
}());
exports.ViewHelper = ViewHelper;
//# sourceMappingURL=view-helper-common.js.map