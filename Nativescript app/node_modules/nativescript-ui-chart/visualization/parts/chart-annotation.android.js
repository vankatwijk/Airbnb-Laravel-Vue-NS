Object.defineProperty(exports, "__esModule", { value: true });
var annotationModule = require("./chart-annotation.common");
var chartModule = require("../../");
var utilsModule = require("tns-core-modules/utils/utils");
var chart_public_enum_1 = require("../../misc/chart-public-enum");
var dateHelperModule = require("../../misc/chart-date-helper");
var floatType;
var getFloatType = function () {
    if (floatType) {
        return floatType;
    }
    floatType = java.lang.Float.class.getField("TYPE").get(null);
    return floatType;
};
var ChartGridLineAnnotation = /** @class */ (function (_super) {
    __extends(ChartGridLineAnnotation, _super);
    function ChartGridLineAnnotation() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    Object.defineProperty(ChartGridLineAnnotation.prototype, "android", {
        get: function () {
            return this._android;
        },
        enumerable: true,
        configurable: true
    });
    ChartGridLineAnnotation.prototype._init = function (owner) {
        this._owner = owner;
    };
    ChartGridLineAnnotation.prototype.createAnnotation = function () {
        if (!this.axisId) {
            console.log("ERROR: axisId property is mandatory for any annotation.");
            return;
        }
        if (!this._owner || !this._owner.androidView) {
            console.log("ERROR: You cannot create annotation if owner chart is not set and native instance is not created");
            return;
        }
        var forAxis = this._owner.getAxisByID(this.axisId);
        if (typeof (this.value) === "string") {
            if (forAxis instanceof chartModule.LinearAxis) {
                this._android = new com.telerik.widget.chart.visualization.annotations.cartesian.CartesianGridLineAnnotation(forAxis.android, new java.lang.Float(parseFloat(this.value)));
            }
            else {
                this._android = new com.telerik.widget.chart.visualization.annotations.cartesian.CartesianGridLineAnnotation(forAxis.android, new java.lang.String(this.value));
            }
        }
        else if (typeof (this.value) === "number") {
            if (forAxis instanceof chartModule.DateTimeContinuousAxis) {
                this._android = new com.telerik.widget.chart.visualization.annotations.cartesian.CartesianGridLineAnnotation(forAxis.android, dateHelperModule.getCalendarFromMilliseconds(this.value));
            }
            else {
                this._android = new com.telerik.widget.chart.visualization.annotations.cartesian.CartesianGridLineAnnotation(forAxis.android, new java.lang.Float(this.value));
            }
        }
        else {
            console.log("ERROR: Unsupported value type for annotation");
            return;
        }
        this._android.setVisible(this.hidden ? false : true);
        if (this.value) {
            this.updateValue();
        }
        else {
            console.log("WARNING: value property is mandatory for grid line annotation.");
        }
        if (this.zPosition) {
            switch (this.zPosition) {
                case chart_public_enum_1.ChartAnnotationZPosition.AboveSeries:
                    this._android.setZIndex(com.telerik.widget.chart.visualization.common.ChartSeries.SERIES_Z_INDEX + 100);
                    break;
                default: // ChartAnnotationZPosition.BelowSeries:
                    this._android.setZIndex(com.telerik.widget.chart.visualization.common.ChartSeries.SERIES_Z_INDEX - 100);
            }
        }
        if (this.strokeColor || !isNaN(+this.strokeWidth)) {
            var nvPalette = this._owner.androidView.getPalette().clone();
            var nvPaletteEntry = nvPalette.getEntry("CartesianGridLineAnnotation");
            this._android.setCanApplyPalette(false);
            if (this.strokeColor) {
                this._android.setStrokeColor(this.strokeColor.android);
            }
            else {
                this._android.setStrokeColor(nvPaletteEntry.getStroke());
            }
            if (!isNaN(+this.strokeWidth)) {
                this._android.setStrokeWidth(utilsModule.layout.toDevicePixels(this.strokeWidth));
            }
            else {
                this._android.setStrokeWidth(utilsModule.layout.toDevicePixels(2));
                // TODO: replace the statement above when bug with storke width getter of pallete entry is fixed
                // this._android.setStrokeWidth(nvPaletteEntry.getStrokeWidth())
            }
        }
        if (this.strokeDashPattern) {
            var array = JSON.parse("[" + this.strokeDashPattern + "]");
            var arrNative = java.lang.reflect.Array.newInstance(getFloatType(), array.length);
            for (var i = 0; i < array.length; ++i) {
                arrNative[i] = parseFloat(array[i]) * utilsModule.layout.getDisplayDensity();
            }
            var effect = new android.graphics.DashPathEffect(arrNative, 0);
            this._android.setStrokeEffect(effect);
        }
    };
    ChartGridLineAnnotation.prototype._onOwnerUICreated = function () {
        this.createAnnotation();
    };
    ChartGridLineAnnotation.prototype._createNative = function () {
        this.createAnnotation();
    };
    ChartGridLineAnnotation.prototype.onValueChanged = function (oldValue, newValue) {
        if (newValue) {
            if (this._android) {
                this.updateValue();
            }
            else if (this.owner) {
                // try to create annotations if value binding is set too late (Angular)
                this.owner.initializer.onAnnotationsPropertyChanged(null, null, this.owner);
            }
        }
    };
    ChartGridLineAnnotation.prototype.onAxisIdChanged = function (oldValue, newValue) {
        if (this._android && newValue) {
            var forAxis = this._owner.getAxisByID(newValue);
            this._android.setAxis(forAxis.android);
        }
    };
    ChartGridLineAnnotation.prototype.onZPositionChanged = function (oldValue, newValue) {
        if (!this._android) {
            return;
        }
        if (newValue) {
            switch (newValue) {
                case chart_public_enum_1.ChartAnnotationZPosition.AboveSeries:
                    this._android.setZIndex(com.telerik.widget.chart.visualization.common.ChartSeries.SERIES_Z_INDEX + 100);
                    break;
                default: // ChartAnnotationZPosition.BelowSeries:
                    this._android.setZIndex(com.telerik.widget.chart.visualization.common.ChartSeries.SERIES_Z_INDEX - 100);
            }
            this._android.requestLayout();
        }
    };
    ChartGridLineAnnotation.prototype.onHiddenChanged = function (oldValue, newValue) {
        if (this._android) {
            this._android.setVisible(newValue ? false : true);
        }
    };
    ChartGridLineAnnotation.prototype.onStrokeWidthChanged = function (oldValue, newValue) {
        if (this._android && !isNaN(+newValue)) {
            this._android.setStrokeWidth(newValue);
        }
    };
    ChartGridLineAnnotation.prototype.onStrokeColorChanged = function (oldValue, newValue) {
        if (this._android && newValue) {
            this._android.setStrokeColor(newValue.android);
        }
    };
    ChartGridLineAnnotation.prototype.onStrokeDashPatternChanged = function (oldValue, newValue) {
        if (this._android && newValue) {
            var array = JSON.parse("[" + newValue + "]");
            var arrNative = java.lang.reflect.Array.newInstance(getFloatType(), array.length);
            for (var i = 0; i < array.length; ++i) {
                arrNative[i] = parseFloat(array[i]) * utilsModule.layout.getDisplayDensity();
            }
            var effect = new android.graphics.DashPathEffect(arrNative, 0);
            this._android.setStrokeEffect(effect);
        }
    };
    ChartGridLineAnnotation.prototype.updateValue = function () {
        var forAxis = this._owner.getAxisByID(this.axisId);
        if (forAxis instanceof chartModule.DateTimeContinuousAxis) {
            this._android.setValue(dateHelperModule.getCalendarFromMilliseconds(new Number(this.value)));
        }
        else {
            if (this.value && !isNaN(this.value)) {
                this._android.setValue(new java.lang.Float(parseFloat(this.value)));
            }
            else {
                this._android.setValue(new java.lang.String(this.value));
            }
        }
    };
    return ChartGridLineAnnotation;
}(annotationModule.ChartGridLineAnnotation));
exports.ChartGridLineAnnotation = ChartGridLineAnnotation;
var ChartPlotBandAnnotation = /** @class */ (function (_super) {
    __extends(ChartPlotBandAnnotation, _super);
    function ChartPlotBandAnnotation() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    Object.defineProperty(ChartPlotBandAnnotation.prototype, "android", {
        get: function () {
            return this._android;
        },
        enumerable: true,
        configurable: true
    });
    ChartPlotBandAnnotation.prototype._init = function (owner) {
        this._owner = owner;
    };
    ChartPlotBandAnnotation.prototype.createAnnotation = function () {
        if (!this.axisId) {
            console.log("ERROR: axisId property is mandatory for any anotation.");
            return;
        }
        if (!this._owner || !this._owner.androidView) {
            console.log("ERROR: You cannot create annotation if owner chart is not set and native instance is not created");
            return;
        }
        var forAxis = this._owner.getAxisByID(this.axisId);
        if (typeof (this.minValue) === "string") {
            var currentMinValue = this.minValue;
            this._android = new com.telerik.widget.chart.visualization.annotations.cartesian.CartesianPlotBandAnnotation(forAxis.android, currentMinValue, this.maxValue);
        }
        else if (typeof (this.minValue) === "number") {
            this._android = new com.telerik.widget.chart.visualization.annotations.cartesian.CartesianPlotBandAnnotation(forAxis.android, java.lang.Float.valueOf(this.minValue), java.lang.Float.valueOf(this.maxValue));
        }
        else {
            console.log("ERROR: Unsupported value type for annotation");
            return;
        }
        this._android.setVisible(this.hidden ? false : true);
        if (this.minValue) {
            if (!isNaN(this.minValue)) {
                this._android.setFrom(new java.lang.Float(parseFloat(this.minValue)));
            }
            else {
                this._android.setFrom(new java.lang.String(this.minValue));
            }
        }
        else {
            console.log("WARNING: minValue is mandatory for band annotation");
        }
        if (this.maxValue) {
            if (!isNaN(this.maxValue)) {
                this._android.setTo(new java.lang.Float(parseFloat(this.maxValue)));
            }
            else {
                this._android.setTo(new java.lang.String(this.maxValue));
            }
        }
        else {
            console.log("WARNING: maxValue is mandatory for band annotation");
        }
        if (this.zPosition) {
            switch (this.zPosition) {
                case chart_public_enum_1.ChartAnnotationZPosition.AboveSeries:
                    this._android.setZIndex(com.telerik.widget.chart.visualization.common.ChartSeries.SERIES_Z_INDEX + 100);
                    break;
                default: // ChartAnnotationZPosition.BelowSeries:
                    this._android.setZIndex(com.telerik.widget.chart.visualization.common.ChartSeries.SERIES_Z_INDEX - 100);
            }
        }
        if (this.fillColor || this.strokeColor || !isNaN(this.strokeWidth)) {
            var nvPalette = this._owner.androidView.getPalette().clone();
            var nvPaletteEntry = nvPalette.getEntry("CartesianPlotBandAnnotation");
            this._android.setCanApplyPalette(false);
            if (this.fillColor) {
                this._android.setFillColor(this.fillColor.android);
            }
            else {
                this._android.setFillColor(nvPaletteEntry.getFill());
            }
            if (this.strokeColor) {
                this._android.setStrokeColor(this.strokeColor.android);
            }
            else {
                this._android.setStrokeColor(nvPaletteEntry.getStroke());
            }
            if (!isNaN(+this.strokeWidth)) {
                this._android.setStrokeWidth(this.strokeWidth * utilsModule.layout.getDisplayDensity());
            }
            else {
                this._android.setStrokeWidth(2 * utilsModule.layout.getDisplayDensity());
                // TODO: replace the statement above when bug with storke with getter of pallete entry is fixed
                // this._android.setStrokeWidth(nvPaletteEntry.getStrokeWidth())
            }
        }
        if (this.strokeDashPattern) {
            var array = JSON.parse("[" + this.strokeDashPattern + "]");
            var arrNative = java.lang.reflect.Array.newInstance(getFloatType(), array.length);
            for (var i = 0; i < array.length; ++i) {
                arrNative[i] = parseFloat(array[i]) * utilsModule.layout.getDisplayDensity();
            }
            var effect = new android.graphics.DashPathEffect(arrNative, 0);
            this._android.setStrokeEffect(effect);
        }
    };
    ChartPlotBandAnnotation.prototype._onOwnerUICreated = function () {
        this.createAnnotation();
    };
    ChartPlotBandAnnotation.prototype._createNative = function () {
        this.createAnnotation();
    };
    ChartPlotBandAnnotation.prototype.onMinValueChanged = function (oldValue, newValue) {
        if (this._android && newValue) {
            if (!isNaN(newValue)) {
                this._android.setFrom(new java.lang.Float(parseFloat(newValue)));
            }
            else {
                this._android.setFrom(new java.lang.String(newValue));
            }
        }
    };
    ChartPlotBandAnnotation.prototype.onMaxValueChanged = function (oldValue, newValue) {
        if (this._android && newValue) {
            if (!isNaN(newValue)) {
                this._android.setTo(new java.lang.Float(parseFloat(newValue)));
            }
            else {
                this._android.setTo(new java.lang.String(newValue));
            }
        }
    };
    ChartPlotBandAnnotation.prototype.onFillColorChanged = function (oldValue, newValue) {
        if (this._android && newValue) {
            this._android.setFillColor(newValue.android);
        }
    };
    ChartPlotBandAnnotation.prototype.onAxisIdChanged = function (oldValue, newValue) {
        if (this._android && newValue) {
            var forAxis = this._owner.getAxisByID(newValue);
            this._android.setAxis(forAxis.android);
        }
    };
    ChartPlotBandAnnotation.prototype.onZPositionChanged = function (oldValue, newValue) {
        if (!this._android) {
            return;
        }
        if (newValue) {
            switch (newValue) {
                case chart_public_enum_1.ChartAnnotationZPosition.AboveSeries:
                    this._android.setZIndex(com.telerik.widget.chart.visualization.common.ChartSeries.SERIES_Z_INDEX + 100);
                    break;
                default: // ChartAnnotationZPosition.BelowSeries:
                    this._android.setZIndex(com.telerik.widget.chart.visualization.common.ChartSeries.SERIES_Z_INDEX - 100);
            }
            this._android.requestLayout();
        }
    };
    ChartPlotBandAnnotation.prototype.onHiddenChanged = function (oldValue, newValue) {
        if (this._android) {
            this._android.setVisible(newValue ? false : true);
        }
    };
    ChartPlotBandAnnotation.prototype.onStrokeWidthChanged = function (oldValue, newValue) {
        if (this._android && !isNaN(+newValue)) {
            this._android.setStrokeWidth(newValue);
        }
    };
    ChartPlotBandAnnotation.prototype.onStrokeColorChanged = function (oldValue, newValue) {
        if (this._android && newValue) {
            this._android.setStrokeColor(newValue.android);
        }
    };
    ChartPlotBandAnnotation.prototype.onStrokeDashPatternChanged = function (oldValue, newValue) {
        if (this._android && newValue) {
            var array = JSON.parse("[" + newValue + "]");
            var arrNative = java.lang.reflect.Array.newInstance(getFloatType(), array.length);
            for (var i = 0; i < array.length; ++i) {
                arrNative[i] = parseFloat(array[i]) * utilsModule.layout.getDisplayDensity();
            }
            var effect = new android.graphics.DashPathEffect(arrNative, 0);
            this._android.setStrokeEffect(effect);
        }
    };
    return ChartPlotBandAnnotation;
}(annotationModule.ChartPlotBandAnnotation));
exports.ChartPlotBandAnnotation = ChartPlotBandAnnotation;
