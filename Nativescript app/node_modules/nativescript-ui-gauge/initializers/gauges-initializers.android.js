Object.defineProperty(exports, "__esModule", { value: true });
var commonModule = require("../ui-gauge.common");
var observable_array_1 = require("tns-core-modules/data/observable-array");
var weakEvents = require("tns-core-modules/ui/core/weak-event-listener");
var RadGaugeValueMapper = /** @class */ (function () {
    function RadGaugeValueMapper() {
    }
    RadGaugeValueMapper.prototype.onTitleChanged = function (oldValue, newValue, gauge) {
        if (!gauge._nativeView) {
            return;
        }
        if (!newValue) {
            gauge._nativeView.getTitle().setText("");
            return;
        }
        gauge._nativeView.getTitle().setText(newValue);
    };
    RadGaugeValueMapper.prototype.onSubtitleChanged = function (oldValue, newValue, gauge) {
        if (!gauge._nativeView) {
            return;
        }
        if (!newValue) {
            gauge._nativeView.getSubtitle().setText("");
            return;
        }
        gauge._nativeView.getSubtitle().setText(newValue);
    };
    RadGaugeValueMapper.prototype.onTitleStyleChanged = function (oldValue, newValue, gauge) {
        var style = newValue;
        style.owner = gauge;
        if (!gauge._nativeView) {
            return;
        }
        this.applyTitleStyles(gauge);
    };
    RadGaugeValueMapper.prototype.onSubtitleStyleChanged = function (oldValue, newValue, gauge) {
        var style = newValue;
        style.owner = gauge;
        if (!gauge._nativeView) {
            return;
        }
        this.applySubtitleStyles(gauge);
    };
    RadGaugeValueMapper.prototype.updateNativeObject = function (gauge) {
        this.updateTitles(gauge);
        this.applyTitleStyles(gauge);
        this.applySubtitleStyles(gauge);
    };
    RadGaugeValueMapper.prototype.applySubtitleStyles = function (gauge) {
        if (!gauge.subtitleStyle) {
            return;
        }
        var style = gauge.subtitleStyle;
        if (style.textSize !== undefined) {
            gauge._nativeView.getSubtitle().setTextSize(style.textSize);
        }
        if (style.textColor !== undefined) {
            gauge._nativeView.getSubtitle().setTextColor(style.textColor.android);
        }
        if (style.horizontalOffset !== undefined) {
            gauge._nativeView.setSubtitleHorizontalOffset(style.horizontalOffset);
        }
        if (style.verticalOffset !== undefined) {
            gauge._nativeView.setSubtitleVerticalOffset(style.verticalOffset);
        }
    };
    RadGaugeValueMapper.prototype.applyTitleStyles = function (gauge) {
        if (!gauge.titleStyle) {
            return;
        }
        var style = gauge.titleStyle;
        if (style.textSize !== undefined) {
            gauge._nativeView.getTitle().setTextSize(style.textSize);
        }
        if (style.textColor !== undefined) {
            gauge._nativeView.getTitle().setTextColor(style.textColor.android);
        }
        if (style.horizontalOffset !== undefined) {
            gauge._nativeView.setTitleHorizontalOffset(style.horizontalOffset);
        }
        if (style.verticalOffset !== undefined) {
            gauge._nativeView.setTitleVerticalOffset(style.verticalOffset);
        }
    };
    RadGaugeValueMapper.prototype.updateTitles = function (gauge) {
        if (gauge.title) {
            gauge._nativeView.getTitle().setText(gauge.title);
        }
        if (gauge.subtitle) {
            gauge._nativeView.getSubtitle().setText(gauge.subtitle);
        }
    };
    return RadGaugeValueMapper;
}());
exports.RadGaugeValueMapper = RadGaugeValueMapper;
var GaugeScaleValueMapper = /** @class */ (function () {
    function GaugeScaleValueMapper() {
    }
    GaugeScaleValueMapper.prototype.onMinimumChanged = function (oldValue, newValue, scale) {
        if (!scale.android) {
            return;
        }
        scale.android.setMinimum(newValue);
    };
    GaugeScaleValueMapper.prototype.onMaximumChanged = function (oldValue, newValue, scale) {
        if (!scale.android) {
            return;
        }
        scale.android.setMaximum(newValue);
    };
    GaugeScaleValueMapper.prototype.onIndicatorsChange = function (oldValue, newValue, scale) {
        if (!scale.android) {
            return;
        }
        if (oldValue) {
            weakEvents.removeWeakEventListener(oldValue, observable_array_1.ObservableArray.changeEvent, scale.indicatorsCollectionChanged, scale);
        }
        if (newValue) {
            weakEvents.addWeakEventListener(newValue, observable_array_1.ObservableArray.changeEvent, scale.indicatorsCollectionChanged, scale);
        }
        this.reloadIndicators(scale);
    };
    GaugeScaleValueMapper.prototype.onScaleStyleChanged = function (oldValue, newValue, scale) {
        if (!scale.android) {
            return;
        }
        this.updateNativeStyle(newValue, scale);
    };
    GaugeScaleValueMapper.prototype.applyStylesToScale = function (style, scale) {
        if (style.lineColor !== undefined) {
            scale.android.setStrokeColor(style.lineColor.android);
        }
        if (style.lineThickness !== undefined) {
            if (style.lineThickness === 0) {
                scale.android.setLineVisible(false);
            }
            else {
                scale.android.setLineVisible(true);
            }
            scale.android.setStrokeWidth(style.lineThickness);
        }
        if (style.ticksVisible !== undefined) {
            scale.android.setTicksVisible(style.ticksVisible);
        }
        if (style.majorTicksCount !== undefined) {
            scale.android.setMajorTicksCount(style.majorTicksCount);
        }
        if (style.minorTicksCount !== undefined) {
            scale.android.setMinorTicksCount(style.minorTicksCount);
        }
        if (style.ticksOffset !== undefined) {
            scale.android.setTicksOffset(style.ticksOffset);
        }
        if (style.ticksLayoutMode !== undefined) {
            if (style.ticksLayoutMode === commonModule.GaugeScaleLayoutMode.Inner) {
                scale.android.setTicksLayoutMode(com.telerik.widget.scales.GaugeScaleTicksLayoutMode.INNER);
            }
            else if (style.ticksLayoutMode === commonModule.GaugeScaleLayoutMode.Outer) {
                scale.android.setTicksLayoutMode(com.telerik.widget.scales.GaugeScaleTicksLayoutMode.OUTER);
            }
        }
        if (style.minorTicksFillColor !== undefined) {
            scale.android.setMinorTicksFillColor(style.minorTicksFillColor.android);
        }
        if (style.minorTicksStrokeColor !== undefined) {
            scale.android.setMinorTicksStrokeColor(style.minorTicksStrokeColor.android);
        }
        if (style.minorTicksStrokeWidth !== undefined) {
            scale.android.getMinorTicksStrokePaint().setStrokeWidth(style.minorTicksStrokeWidth);
        }
        if (style.minorTicksWidth !== undefined) {
            scale.android.setMinorTicksWidth(style.minorTicksWidth);
        }
        if (style.minorTicksLength !== undefined) {
            scale.android.setMinorTicksLength(style.minorTicksLength);
        }
        if (style.majorTicksFillColor !== undefined) {
            scale.android.setMajorTicksFillColor(style.majorTicksFillColor.android);
        }
        if (style.majorTicksStrokeColor !== undefined) {
            scale.android.setMajorTicksStrokeColor(style.majorTicksStrokeColor.android);
        }
        if (style.majorTicksStrokeWidth !== undefined) {
            scale.android.getMajorTicksStrokePaint().setStrokeWidth(style.majorTicksStrokeWidth);
        }
        if (style.majorTicksWidth !== undefined) {
            scale.android.setMajorTicksWidth(style.majorTicksWidth);
        }
        if (style.majorTicksLength !== undefined) {
            scale.android.setMajorTicksLength(style.majorTicksLength);
        }
        if (style.labelsVisible !== undefined) {
            scale.android.setLabelsVisible(style.labelsVisible);
        }
        if (style.labelsCount !== undefined) {
            scale.android.setLabelsCount(style.labelsCount);
        }
        if (style.labelsLayoutMode !== undefined) {
            if (style.labelsLayoutMode === commonModule.GaugeScaleLayoutMode.Inner) {
                scale.android.setLabelsLayoutMode(com.telerik.widget.scales.GaugeScaleLabelsLayoutMode.INNER);
            }
            else if (style.labelsLayoutMode === commonModule.GaugeScaleLayoutMode.Outer) {
                scale.android.setLabelsLayoutMode(com.telerik.widget.scales.GaugeScaleLabelsLayoutMode.OUTER);
            }
        }
        if (style.labelsOffset !== undefined) {
            scale.android.setLabelsOffset(style.labelsOffset);
        }
        if (style.labelsSize !== undefined) {
            scale.android.getLabelsPaint().setTextSize(style.labelsSize);
        }
        if (style.labelsColor !== undefined) {
            scale.android.setLabelsColor(style.labelsColor.android);
        }
    };
    GaugeScaleValueMapper.prototype.reloadIndicators = function (scale) {
        var indicators = scale.indicators;
        for (var i = 0; i < indicators.length; i++) {
            var indicator = indicators.getItem(i);
            indicator.owner = scale;
            scale.android.addIndicator(indicator.android);
        }
    };
    GaugeScaleValueMapper.prototype.updateNativeObject = function (scale) {
        this.updateNativeMinimum(scale.minimum, scale);
        this.updateNativeMaximum(scale.maximum, scale);
        this.updateNativeStyle(scale.scaleStyle, scale);
        this.updateNativeIndicators(scale.indicators, scale);
    };
    GaugeScaleValueMapper.prototype.updateNativeMinimum = function (min, scale) {
        if (min !== undefined) {
            scale.android.setMinimum(min);
        }
    };
    GaugeScaleValueMapper.prototype.updateNativeMaximum = function (max, scale) {
        if (max !== undefined) {
            scale.android.setMaximum(max);
        }
    };
    GaugeScaleValueMapper.prototype.updateNativeIndicators = function (indicators, scale) {
        if (indicators !== undefined) {
            this.reloadIndicators(scale);
        }
    };
    GaugeScaleValueMapper.prototype.updateNativeStyle = function (style, scale) {
        // TODO this code repeats for ios and android => should reuse it.
        if (style === undefined) {
            return;
        }
        style.owner = scale;
        this.applyStylesToScale(style, scale);
    };
    return GaugeScaleValueMapper;
}());
exports.GaugeScaleValueMapper = GaugeScaleValueMapper;
var NeedleIndicatorValueMapper = /** @class */ (function () {
    function NeedleIndicatorValueMapper() {
    }
    NeedleIndicatorValueMapper.prototype.onNeedleStyleChanged = function (oldValue, newValue, needle) {
        if (!needle.android) {
            return;
        }
        this.applyStyles(newValue, needle);
    };
    NeedleIndicatorValueMapper.prototype.onIsAnimatedChanged = function (oldValue, newValue, indicator) {
        if (!indicator.android) {
            return;
        }
        this.updateIsAnimated(newValue, indicator);
    };
    NeedleIndicatorValueMapper.prototype.onAnimationDurationChanged = function (oldValue, newValue, indicator) {
        if (!indicator.android) {
            return;
        }
        this.updateAnimationDuration(newValue, indicator);
    };
    NeedleIndicatorValueMapper.prototype.updateNativeObject = function (needle) {
        this.applyStyles(needle.needleStyle, needle);
        this.updateIsAnimated(needle.isAnimated, needle);
        this.updateAnimationDuration(needle.animationDuration, needle);
    };
    NeedleIndicatorValueMapper.prototype.updateAnimationDuration = function (value, indicator) {
        if (value === undefined) {
            return;
        }
        indicator.android.setAnimationDuration(value);
    };
    NeedleIndicatorValueMapper.prototype.updateIsAnimated = function (value, indicator) {
        if (value === undefined) {
            return;
        }
        indicator.android.setAnimated(value);
    };
    NeedleIndicatorValueMapper.prototype.applyStyles = function (style, needle) {
        if (!style) {
            return;
        }
        style.owner = needle;
        if (style.length !== undefined) {
            needle.android.setLength(style.length);
        }
        if (style.bottomWidth !== undefined) {
            needle.android.setBottomWidth(style.bottomWidth);
        }
        if (style.topWidth !== undefined) {
            needle.android.setTopWidth(style.topWidth);
        }
        if (style.circleRadius !== undefined) {
            needle.android.setCircleRadius(style.circleRadius);
        }
        if (style.circleInnerRadius !== undefined) {
            needle.android.setCircleInnerRadius(style.circleInnerRadius);
        }
        if (style.offset !== undefined) {
            needle.android.setOffset(style.offset);
        }
        if (style.circleFillColor) {
            needle.android.setCircleFillColor(style.circleFillColor.android);
        }
        if (style.circleStrokeColor) {
            needle.android.setCircleStrokeColor(style.circleStrokeColor.android);
        }
        if (style.circleStrokeWidth !== undefined) {
            needle.android.setCircleStrokeWidth(style.circleStrokeWidth);
        }
        if (style.fillColor) {
            needle.android.setFillColor(style.fillColor.android);
        }
        if (style.strokeColor) {
            needle.android.setStrokeColor(style.strokeColor.android);
        }
        if (style.strokeWidth) {
            needle.android.setStrokeWidth(style.strokeWidth);
        }
    };
    return NeedleIndicatorValueMapper;
}());
exports.NeedleIndicatorValueMapper = NeedleIndicatorValueMapper;
var BarIndicatorValueMapper = /** @class */ (function () {
    function BarIndicatorValueMapper() {
    }
    BarIndicatorValueMapper.prototype.onMinimumValueChanged = function (oldValue, newValue, indicator) {
        if (!indicator.android) {
            return;
        }
        this.updateMinimum(newValue, indicator);
    };
    BarIndicatorValueMapper.prototype.onMaximumValueChanged = function (oldValue, newValue, indicator) {
        if (!indicator.android) {
            return;
        }
        this.updateMaximum(newValue, indicator);
    };
    BarIndicatorValueMapper.prototype.onIndicatorStyleChanged = function (oldValue, newValue, indicator) {
        if (!indicator.android) {
            return;
        }
        this.applyStyles(newValue, indicator);
    };
    BarIndicatorValueMapper.prototype.onLocationChanged = function (oldValue, newValue, indicator) {
        if (!indicator.android) {
            return;
        }
        this.updateLocation(newValue, indicator);
    };
    BarIndicatorValueMapper.prototype.onIsAnimatedChanged = function (oldValue, newValue, indicator) {
        if (!indicator.android) {
            return;
        }
        this.updateIsAnimated(newValue, indicator);
    };
    BarIndicatorValueMapper.prototype.onAnimationDurationChanged = function (oldValue, newValue, indicator) {
        if (!indicator.android) {
            return;
        }
        this.updateAnimationDuration(newValue, indicator);
    };
    BarIndicatorValueMapper.prototype.updateAnimationDuration = function (value, indicator) {
        if (value === undefined) {
            return;
        }
        indicator.android.setAnimationDuration(value);
    };
    BarIndicatorValueMapper.prototype.updateIsAnimated = function (value, indicator) {
        if (value === undefined) {
            return;
        }
        indicator.android.setAnimated(value);
    };
    BarIndicatorValueMapper.prototype.applyStyles = function (style, indicator) {
        if (!style) {
            return;
        }
        style.owner = indicator;
        if (style.cap) {
            if (style.cap === commonModule.GaugeIndicatorCapMode.Edge) {
                indicator.android.setCap(com.telerik.widget.indicators.GaugeBarIndicatorCapMode.EDGE);
            }
            else if (style.cap === commonModule.GaugeIndicatorCapMode.Round) {
                indicator.android.setCap(com.telerik.widget.indicators.GaugeBarIndicatorCapMode.ROUND);
            }
        }
        if (style.barWidth !== undefined) {
            indicator.android.setBarWidth(style.barWidth);
        }
        if (style.fillColor) {
            indicator.android.setFillColor(style.fillColor.android);
        }
        if (style.strokeColor) {
            indicator.android.setStrokeColor(style.strokeColor.android);
        }
        if (style.strokeWidth) {
            indicator.android.setStrokeWidth(style.strokeWidth);
        }
    };
    BarIndicatorValueMapper.prototype.updateMinimum = function (newMinimum, indicator) {
        if (newMinimum !== undefined) {
            indicator.android.setMinimum(newMinimum);
        }
    };
    BarIndicatorValueMapper.prototype.updateMaximum = function (newMaximum, indicator) {
        if (newMaximum !== undefined) {
            indicator.android.setMaximum(newMaximum);
        }
    };
    BarIndicatorValueMapper.prototype.updateLocation = function (newLocation, indicator) {
        if (newLocation !== undefined) {
            indicator.android.setLocation(newLocation);
        }
    };
    BarIndicatorValueMapper.prototype.updateNativeObject = function (barIndicator) {
        this.applyStyles(barIndicator.indicatorStyle, barIndicator);
        this.updateIsAnimated(barIndicator.isAnimated, barIndicator);
        this.updateAnimationDuration(barIndicator.animationDuration, barIndicator);
        this.updateLocation(barIndicator.location, barIndicator);
        this.updateMinimum(barIndicator.minimum, barIndicator);
        this.updateMaximum(barIndicator.maximum, barIndicator);
    };
    return BarIndicatorValueMapper;
}());
exports.BarIndicatorValueMapper = BarIndicatorValueMapper;
