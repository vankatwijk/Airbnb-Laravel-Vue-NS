Object.defineProperty(exports, "__esModule", { value: true });
var commonModule = require("../ui-gauge.common");
var observable_array_1 = require("tns-core-modules/data/observable-array");
var weakEvents = require("tns-core-modules/ui/core/weak-event-listener");
var RadGaugeValueMapper = /** @class */ (function () {
    function RadGaugeValueMapper() {
    }
    RadGaugeValueMapper.prototype.updateNativeObject = function (arg) { };
    RadGaugeValueMapper.prototype.onTitleChanged = function (oldValue, newValue, gauge) {
        if (!newValue) {
            gauge._nativeView.labelTitle.text = "";
            return;
        }
        gauge._nativeView.labelTitle.text = newValue;
    };
    RadGaugeValueMapper.prototype.onSubtitleChanged = function (oldValue, newValue, gauge) {
        if (!newValue) {
            gauge._nativeView.labelSubtitle.text = "";
            return;
        }
        gauge._nativeView.labelSubtitle.text = newValue;
    };
    RadGaugeValueMapper.prototype.onTitleStyleChanged = function (oldValue, newValue, gauge) {
        var style = newValue;
        style.owner = gauge;
        gauge._nativeView.labelTitleOffset = CGPointMake(style.horizontalOffset, style.verticalOffset);
        if (style.textSize) {
            gauge._nativeView.labelTitle.font = UIFont.systemFontOfSize(style.textSize);
        }
        if (style.textColor) {
            gauge._nativeView.labelTitle.textColor = style.textColor.ios;
        }
    };
    RadGaugeValueMapper.prototype.onSubtitleStyleChanged = function (oldValue, newValue, gauge) {
        var style = newValue;
        style.owner = gauge;
        gauge._nativeView.labelSubtitleOffset = CGPointMake(style.horizontalOffset, style.verticalOffset);
        if (style.textSize) {
            gauge._nativeView.labelSubtitle.font = UIFont.systemFontOfSize(style.textSize);
        }
        if (style.textColor) {
            gauge._nativeView.labelSubtitle.textColor = style.textColor.ios;
        }
    };
    return RadGaugeValueMapper;
}());
exports.RadGaugeValueMapper = RadGaugeValueMapper;
var GaugeScaleValueMapper = /** @class */ (function () {
    function GaugeScaleValueMapper() {
    }
    GaugeScaleValueMapper.prototype.updateNativeObject = function (arg) { };
    GaugeScaleValueMapper.prototype.onMinimumChanged = function (oldValue, newValue, scale) {
        scale.ios.range.minimum = newValue;
    };
    GaugeScaleValueMapper.prototype.onMaximumChanged = function (oldValue, newValue, scale) {
        scale.ios.range.maximum = newValue;
    };
    GaugeScaleValueMapper.prototype.onIndicatorsChange = function (oldValue, newValue, scale) {
        if (oldValue) {
            weakEvents.removeWeakEventListener(oldValue, observable_array_1.ObservableArray.changeEvent, scale.indicatorsCollectionChanged, scale);
        }
        if (newValue) {
            weakEvents.addWeakEventListener(newValue, observable_array_1.ObservableArray.changeEvent, scale.indicatorsCollectionChanged, scale);
        }
        this.reloadIndicators(scale);
    };
    GaugeScaleValueMapper.prototype.reloadIndicators = function (scale) {
        scale.ios.removeAllIndicators();
        scale.ios.removeAllSegments();
        var indicators = scale.indicators;
        for (var i = 0; i < indicators.length; i++) {
            var indicator = indicators.getItem(i);
            if (indicator.ios.isKindOfClass(TKGaugeIndicator.class())) {
                scale.ios.addIndicator(indicator.ios);
            }
            else {
                scale.ios.addSegment(indicator.ios);
            }
        }
    };
    GaugeScaleValueMapper.prototype.onScaleStyleChanged = function (oldValue, newValue, scale) {
        // TODO this code repeats for ios and android => should reuse it.
        var style = newValue;
        style.owner = scale;
        this.applyStylesToScale(style, scale);
    };
    GaugeScaleValueMapper.prototype.applyStylesToScale = function (style, scale) {
        var strokeWidth = style.lineThickness ? style.lineThickness : scale.ios.stroke.width;
        if (style.lineColor) {
            scale.ios.stroke = TKStroke.strokeWithColorWidth(style.lineColor.ios, strokeWidth);
        }
        else if (style.lineThickness !== undefined) {
            scale.ios.stroke.width = style.lineThickness;
        }
        scale.ios.ticks.hidden = !style.ticksVisible;
        scale.ios.ticks.majorTicksCount = style.majorTicksCount !== undefined ? style.majorTicksCount : scale.ios.ticks.majorTicksCount;
        scale.ios.ticks.minorTicksCount = style.minorTicksCount !== undefined ? style.minorTicksCount : scale.ios.ticks.minorTicksCount;
        scale.ios.ticks.offset = style.ticksOffset !== undefined ? style.ticksOffset : scale.ios.ticks.offset;
        if (style.ticksLayoutMode) {
            var layoutMode = style.ticksLayoutMode;
            if (layoutMode === commonModule.GaugeScaleLayoutMode.Inner) {
                scale.ios.ticks.position = 0 /* Inner */;
            }
            else if (layoutMode === commonModule.GaugeScaleLayoutMode.Outer) {
                scale.ios.ticks.position = 1 /* Outer */;
            }
        }
        if (style.majorTicksFillColor) {
            scale.ios.ticks.majorTicksFill = TKSolidFill.solidFillWithColor(style.majorTicksFillColor.ios);
        }
        var didSetStrokeWidth;
        if (style.majorTicksStrokeColor) {
            scale.ios.ticks.majorTicksStroke = TKStroke.strokeWithColorWidth(style.majorTicksStrokeColor.ios, style.majorTicksStrokeWidth !== undefined ? style.majorTicksStrokeWidth : scale.ios.ticks.majorTicksStroke.width);
            didSetStrokeWidth = true;
        }
        if (!didSetStrokeWidth && style.majorTicksStrokeWidth !== undefined) {
            scale.ios.ticks.majorTicksStroke = TKStroke.strokeWithColorWidth(scale.ios.ticks.majorTicksStroke.color, style.majorTicksStrokeWidth);
        }
        scale.ios.ticks.majorTicksWidth = style.majorTicksWidth !== undefined ? style.majorTicksWidth : scale.ios.ticks.majorTicksWidth;
        scale.ios.ticks.majorTicksLength = style.majorTicksLength !== undefined ? style.majorTicksLength : scale.ios.ticks.majorTicksLength;
        if (style.minorTicksFillColor) {
            scale.ios.ticks.minorTicksFill = TKSolidFill.solidFillWithColor(style.minorTicksFillColor.ios);
        }
        didSetStrokeWidth = false;
        if (style.minorTicksStrokeColor) {
            scale.ios.ticks.minorTicksStroke = TKStroke.strokeWithColorWidth(style.minorTicksStrokeColor.ios, style.minorTicksStrokeWidth !== undefined ? style.minorTicksStrokeWidth : scale.ios.ticks.minorTicksStroke.width);
            didSetStrokeWidth = true;
        }
        if (!didSetStrokeWidth && style.minorTicksStrokeWidth !== undefined) {
            scale.ios.ticks.minorTicksStroke = TKStroke.strokeWithColorWidth(scale.ios.ticks.minorTicksStroke.color, style.minorTicksStrokeWidth);
        }
        scale.ios.ticks.minorTicksWidth = style.minorTicksWidth !== undefined ? style.minorTicksWidth : scale.ios.ticks.minorTicksWidth;
        scale.ios.ticks.minorTicksLength = style.minorTicksLength !== undefined ? style.minorTicksLength : scale.ios.ticks.minorTicksLength;
        scale.ios.labels.hidden = !style.labelsVisible;
        scale.ios.labels.count = style.labelsCount !== undefined ? style.labelsCount : scale.ios.labels.count;
        scale.ios.labels.offset = style.labelsOffset !== undefined ? style.labelsOffset : scale.ios.labels.offset;
        if (style.labelsLayoutMode) {
            var layoutMode = style.labelsLayoutMode;
            if (layoutMode === commonModule.GaugeScaleLayoutMode.Inner) {
                scale.ios.labels.position = 0 /* TKGaugeLabelsPositionInner */;
            }
            else if (layoutMode === commonModule.GaugeScaleLayoutMode.Outer) {
                scale.ios.labels.position = 1 /* TKGaugeLabelsPositionOuter */;
            }
        }
        scale.ios.labels.font = style.labelsSize !== undefined ? UIFont.systemFontOfSize(style.labelsSize) : scale.ios.labels.font;
        scale.ios.labels.color = style.labelsColor !== undefined ? style.labelsColor.ios : scale.ios.labels.color;
    };
    return GaugeScaleValueMapper;
}());
exports.GaugeScaleValueMapper = GaugeScaleValueMapper;
var NeedleIndicatorValueMapper = /** @class */ (function () {
    function NeedleIndicatorValueMapper() {
    }
    NeedleIndicatorValueMapper.prototype.updateNativeObject = function (arg) { };
    NeedleIndicatorValueMapper.prototype.onIsAnimatedChanged = function (oldValue, newValue, indicator) {
        // does not require native object change;
    };
    NeedleIndicatorValueMapper.prototype.onAnimationDurationChanged = function (oldValue, newValue, indicator) {
        // does not require native object change;
    };
    NeedleIndicatorValueMapper.prototype.onNeedleStyleChanged = function (oldValue, newValue, needle) {
        var style = newValue;
        style.owner = needle;
        this.mapProperty(style.length, needle.ios, "length");
        this.mapProperty(style.bottomWidth, needle.ios, "width");
        this.mapProperty(style.topWidth, needle.ios, "topWidth");
        this.mapProperty(style.circleRadius, needle.ios, "circleRadius");
        this.mapProperty(style.circleInnerRadius, needle.ios, "circleInnerRadius");
        this.mapProperty(style.offset, needle.ios, "offset");
        if (style.circleFillColor) {
            needle.ios.circleFill = TKSolidFill.solidFillWithColor(style.circleFillColor.ios);
        }
        if (style.circleStrokeColor) {
            var circleStrokeWidth = style.circleStrokeWidth ? style.circleStrokeWidth : 0;
            needle.ios.circleStroke = TKStroke.strokeWithColorWidth(style.circleStrokeColor.ios, circleStrokeWidth);
        }
        // TODO this might be reused;
        if (style.fillColor) {
            needle.ios.fill = TKSolidFill.solidFillWithColor(style.fillColor.ios);
        }
        if (style.strokeColor) {
            var strokeWidth = style.strokeWidth ? style.strokeWidth : 0;
            needle.ios.stroke = TKStroke.strokeWithColorWidth(style.strokeColor.ios, strokeWidth);
        }
    };
    NeedleIndicatorValueMapper.prototype.mapProperty = function (value, nativeObj, propertyName) {
        if (value !== undefined) {
            nativeObj[propertyName] = value;
        }
    };
    return NeedleIndicatorValueMapper;
}());
exports.NeedleIndicatorValueMapper = NeedleIndicatorValueMapper;
var BarIndicatorValueMapper = /** @class */ (function () {
    function BarIndicatorValueMapper() {
    }
    BarIndicatorValueMapper.prototype.updateNativeObject = function (arg) { };
    BarIndicatorValueMapper.prototype.onIsAnimatedChanged = function (oldValue, newValue, indicator) {
        // does not require native object change;
    };
    BarIndicatorValueMapper.prototype.onAnimationDurationChanged = function (oldValue, newValue, indicator) {
        // does not require native object change;
    };
    BarIndicatorValueMapper.prototype.onMinimumValueChanged = function (oldValue, newValue, indicator) {
        indicator.ios.range.minimum = newValue;
        indicator.ios.setNeedsDisplay();
    };
    BarIndicatorValueMapper.prototype.onMaximumValueChanged = function (oldValue, newValue, indicator) {
        if (indicator.isAnimated) {
            var startValue = indicator.animationStartValue !== undefined ? indicator.animationStartValue : indicator.minimum;
            var range = TKRange.rangeWithMinimumAndMaximum(startValue, indicator.maximum);
            var duration = indicator.animationDuration !== undefined ? (indicator.animationDuration / 1000) : 1;
            indicator.ios.setRangeAnimatedWithDurationMediaTimingFunction(range, duration, undefined);
        }
        else {
            indicator.ios.range.maximum = newValue;
            indicator.ios.setNeedsDisplay();
        }
    };
    BarIndicatorValueMapper.prototype.onIndicatorStyleChanged = function (oldValue, newValue, indicator) {
        var style = newValue;
        style.owner = indicator;
        // TODO this might be reused;
        if (style.fillColor) {
            indicator.ios.fill = TKSolidFill.solidFillWithColor(style.fillColor.ios);
        }
        if (style.strokeColor) {
            var strokeWidth = style.strokeWidth ? style.strokeWidth : 0;
            indicator.ios.stroke = TKStroke.strokeWithColorWidth(style.strokeColor.ios, strokeWidth);
        }
        if (style.cap === commonModule.GaugeIndicatorCapMode.Edge) {
            indicator.ios.cap = 1 /* Edge */;
        }
        else if (style.cap === commonModule.GaugeIndicatorCapMode.Round) {
            indicator.ios.cap = 0 /* Round */;
        }
        if (style.barWidth !== undefined) {
            indicator.ios.width = style.barWidth;
            indicator.ios.width2 = style.barWidth;
        }
    };
    BarIndicatorValueMapper.prototype.onLocationChanged = function (oldValue, newValue, indicator) {
        indicator.ios.location = newValue;
    };
    return BarIndicatorValueMapper;
}());
exports.BarIndicatorValueMapper = BarIndicatorValueMapper;
