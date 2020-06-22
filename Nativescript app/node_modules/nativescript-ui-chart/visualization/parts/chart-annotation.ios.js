Object.defineProperty(exports, "__esModule", { value: true });
var annotationModule = require("./chart-annotation.common");
var color_1 = require("tns-core-modules/color");
var chart_public_enum_1 = require("../../misc/chart-public-enum");
var utils_1 = require("tns-core-modules/utils/utils");
var ChartGridLineAnnotation = /** @class */ (function (_super) {
    __extends(ChartGridLineAnnotation, _super);
    function ChartGridLineAnnotation() {
        var _this = _super.call(this) || this;
        _this._ios = TKChartGridLineAnnotation.new();
        _this._ios.style.stroke = TKStroke.strokeWithColor(new color_1.Color("Black").ios);
        return _this;
    }
    Object.defineProperty(ChartGridLineAnnotation.prototype, "ios", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    ChartGridLineAnnotation.prototype.update = function () {
        if (this.owner && this.owner.nativeView) {
            this.owner.nativeView.updateAnnotations();
        }
    };
    ChartGridLineAnnotation.prototype.onOwnerChanged = function () {
        if (!this.axisId) {
            console.log("WARNING: axisId property is mandatory for any annotation.");
            return;
        }
        if (!this.owner) {
            return;
        }
        var forAxis = this.owner.getAxisByID(this.axisId);
        if (forAxis) {
            this._ios.axis = forAxis.ios;
        }
        this.update();
    };
    ChartGridLineAnnotation.prototype.onValueChanged = function (oldValue, newValue) {
        if (newValue) {
            this._ios.value = newValue;
            this.update();
        }
    };
    ChartGridLineAnnotation.prototype.onAxisIdChanged = function (oldValue, newValue) {
        if (newValue && this.owner) {
            var forAxis = this.owner.getAxisByID(this.axisId);
            if (forAxis) {
                this._ios.axis = forAxis.ios;
                this.update();
            }
        }
    };
    ChartGridLineAnnotation.prototype.onZPositionChanged = function (oldValue, newValue) {
        switch (newValue) {
            case chart_public_enum_1.ChartAnnotationZPosition.BelowSeries:
                this._ios.zPosition = 0 /* BelowSeries */;
                break;
            case chart_public_enum_1.ChartAnnotationZPosition.AboveSeries:
                this._ios.zPosition = 1 /* AboveSeries */;
                break;
        }
    };
    ChartGridLineAnnotation.prototype.onHiddenChanged = function (oldValue, newValue) {
        this._ios.hidden = newValue;
        this.update();
    };
    ChartGridLineAnnotation.prototype.onStrokeWidthChanged = function (oldValue, newValue) {
        if (!isNaN(+newValue)) {
            this._ios.style.stroke.width = utils_1.layout.toDeviceIndependentPixels(newValue);
            this.update();
        }
    };
    ChartGridLineAnnotation.prototype.onStrokeColorChanged = function (oldValue, newValue) {
        if (newValue) {
            this._ios.style.stroke.color = newValue.ios;
            this.update();
        }
    };
    ChartGridLineAnnotation.prototype.onStrokeDashPatternChanged = function (oldValue, newValue) {
        if (newValue) {
            var array = JSON.parse("[" + newValue + "]");
            if (array instanceof Array) {
                var nativeSource = NSMutableArray.new();
                var item = void 0, name_1, value = void 0;
                for (var i = 0; i < array.length; i++) {
                    item = array[i];
                    nativeSource.addObject(item);
                }
                this._ios.style.stroke.dashPattern = nativeSource;
                this.update();
            }
        }
    };
    return ChartGridLineAnnotation;
}(annotationModule.ChartGridLineAnnotation));
exports.ChartGridLineAnnotation = ChartGridLineAnnotation;
var ChartPlotBandAnnotation = /** @class */ (function (_super) {
    __extends(ChartPlotBandAnnotation, _super);
    function ChartPlotBandAnnotation() {
        var _this = _super.call(this) || this;
        _this._ios = TKChartBandAnnotation.new();
        _this._ios.style.stroke = TKStroke.strokeWithColor(new color_1.Color("Black").ios);
        return _this;
    }
    Object.defineProperty(ChartPlotBandAnnotation.prototype, "ios", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    ChartPlotBandAnnotation.prototype.update = function () {
        if (this.owner && this.owner.nativeView) {
            this.owner.nativeView.updateAnnotations();
        }
    };
    ChartPlotBandAnnotation.prototype.onOwnerChanged = function () {
        if (!this.axisId) {
            console.log("WARNING: axisId property is mandatory for any annotation.");
            return;
        }
        if (!this.owner) {
            return;
        }
        var forAxis = this.owner.getAxisByID(this.axisId);
        if (forAxis) {
            this._ios.axis = forAxis.ios;
            this.update();
        }
    };
    ChartPlotBandAnnotation.prototype.onMinValueChanged = function (oldValue, newValue) {
        if (this.ios.range) {
            this.ios.range.minimum = newValue;
        }
        else {
            this.ios.range = TKRange.rangeWithMinimumAndMaximum(newValue, (this.maxValue !== undefined) ? this.maxValue : newValue);
        }
        this.update();
    };
    ChartPlotBandAnnotation.prototype.onMaxValueChanged = function (oldValue, newValue) {
        if (this.ios.range) {
            this.ios.range.maximum = newValue;
        }
        else {
            this.ios.range = TKRange.rangeWithMinimumAndMaximum((this.minValue !== undefined) ? this.minValue : newValue, newValue);
        }
        this.update();
    };
    ChartPlotBandAnnotation.prototype.onFillColorChanged = function (oldValue, newValue) {
        if (newValue) {
            this._ios.style.fill = TKSolidFill.solidFillWithColor(newValue.ios);
            this.update();
        }
    };
    ChartPlotBandAnnotation.prototype.onAxisIdChanged = function (oldValue, newValue) {
        if (newValue && this.owner) {
            var forAxis = this.owner.getAxisByID(this.axisId);
            if (forAxis) {
                this._ios.axis = forAxis.ios;
                this.update();
            }
        }
    };
    ChartPlotBandAnnotation.prototype.onZPositionChanged = function (oldValue, newValue) {
        if (newValue) {
            switch (newValue) {
                case chart_public_enum_1.ChartAnnotationZPosition.BelowSeries:
                    this._ios.zPosition = 0 /* BelowSeries */;
                    break;
                case chart_public_enum_1.ChartAnnotationZPosition.AboveSeries:
                    this._ios.zPosition = 1 /* AboveSeries */;
                    break;
            }
            this.update();
        }
    };
    ChartPlotBandAnnotation.prototype.onHiddenChanged = function (oldValue, newValue) {
        this._ios.hidden = newValue;
        this.update();
    };
    ChartPlotBandAnnotation.prototype.onStrokeWidthChanged = function (oldValue, newValue) {
        if (!isNaN(+newValue)) {
            this._ios.style.stroke.width = newValue;
            this.update();
        }
    };
    ChartPlotBandAnnotation.prototype.onStrokeColorChanged = function (oldValue, newValue) {
        if (newValue) {
            this._ios.style.stroke.color = newValue.ios;
            this.update();
        }
    };
    ChartPlotBandAnnotation.prototype.onStrokeDashPatternChanged = function (oldValue, newValue) {
        if (newValue) {
            var array = JSON.parse("[" + newValue + "]");
            if (array instanceof Array) {
                var nativeSource = NSMutableArray.new();
                var item = void 0, name_2, value = void 0;
                for (var i = 0; i < array.length; i++) {
                    item = array[i];
                    nativeSource.addObject(item);
                }
                this._ios.style.stroke.dashPattern = nativeSource;
                this.update();
            }
        }
    };
    return ChartPlotBandAnnotation;
}(annotationModule.ChartPlotBandAnnotation));
exports.ChartPlotBandAnnotation = ChartPlotBandAnnotation;
