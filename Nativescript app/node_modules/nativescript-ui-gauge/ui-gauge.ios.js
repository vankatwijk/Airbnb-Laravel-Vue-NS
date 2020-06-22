Object.defineProperty(exports, "__esModule", { value: true });
var commonModule = require("./ui-gauge.common");
var ui_gauge_common_1 = require("./ui-gauge.common");
exports.knownCollections = ui_gauge_common_1.knownCollections;
var RadRadialGauge = /** @class */ (function (_super) {
    __extends(RadRadialGauge, _super);
    function RadRadialGauge() {
        var _this = _super.call(this) || this;
        _this._ios = TKRadialGauge.alloc().init();
        return _this;
    }
    RadRadialGauge.prototype.createNativeView = function () {
        return this._nativeView;
    };
    Object.defineProperty(RadRadialGauge.prototype, "_nativeView", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadRadialGauge.prototype, "nativeObject", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    return RadRadialGauge;
}(commonModule.RadRadialGauge));
exports.RadRadialGauge = RadRadialGauge;
////////////// TITLE STYLE
var TitleStyle = /** @class */ (function (_super) {
    __extends(TitleStyle, _super);
    function TitleStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    TitleStyle.prototype._onTextSizePropertyChanged = function (oldValue, newValue) {
        if (this.shouldUpdateNativeObject()) {
            this.owner._nativeView.labelTitle.font = UIFont.systemFontOfSize(newValue);
        }
    };
    TitleStyle.prototype._onTextColorPropertyChanged = function (oldValue, newValue) {
        if (this.shouldUpdateNativeObject() && newValue) {
            this.owner._nativeView.labelTitle.textColor = newValue.ios;
        }
    };
    TitleStyle.prototype._onHorizontalOffsetPropertyChanged = function (oldValue, newValue) {
        if (this.shouldUpdateNativeObject()) {
            this.owner._nativeView.labelTitleOffset = CGPointMake(newValue, this.owner._nativeView.labelTitleOffset.y);
        }
    };
    TitleStyle.prototype._onVerticalOffsetPropertyChanged = function (oldValue, newValue) {
        if (this.shouldUpdateNativeObject()) {
            this.owner._nativeView.labelTitleOffset = CGPointMake(this.owner._nativeView.labelTitleOffset.x, newValue);
        }
    };
    return TitleStyle;
}(commonModule.TitleStyle));
exports.TitleStyle = TitleStyle;
/////////////// SUBTITLE STYLE
var SubtitleStyle = /** @class */ (function (_super) {
    __extends(SubtitleStyle, _super);
    function SubtitleStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    SubtitleStyle.prototype._onTextSizePropertyChanged = function (oldValue, newValue) {
        if (this.shouldUpdateNativeObject()) {
            this.owner._nativeView.labelSubtitle.font = UIFont.systemFontOfSize(newValue);
        }
    };
    SubtitleStyle.prototype._onTextColorPropertyChanged = function (oldValue, newValue) {
        if (this.shouldUpdateNativeObject() && newValue) {
            this.owner._nativeView.labelSubtitle.textColor = newValue.ios;
        }
    };
    SubtitleStyle.prototype._onHorizontalOffsetPropertyChanged = function (oldValue, newValue) {
        if (this.shouldUpdateNativeObject()) {
            this.owner._nativeView.labelSubtitleOffset = CGPointMake(newValue, this.owner._nativeView.labelSubtitleOffset.y);
        }
    };
    SubtitleStyle.prototype._onVerticalOffsetPropertyChanged = function (oldValue, newValue) {
        if (this.shouldUpdateNativeObject()) {
            this.owner._nativeView.labelSubtitleOffset = CGPointMake(this.owner._nativeView.labelSubtitleOffset.x, newValue);
        }
    };
    return SubtitleStyle;
}(commonModule.SubtitleStyle));
exports.SubtitleStyle = SubtitleStyle;
////////////////// SCALES
var RadialScale = /** @class */ (function (_super) {
    __extends(RadialScale, _super);
    function RadialScale() {
        var _this = _super.call(this) || this;
        _this._ios = TKGaugeRadialScale.alloc().init();
        return _this;
    }
    Object.defineProperty(RadialScale.prototype, "ios", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadialScale.prototype, "_nativeView", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadialScale.prototype, "nativeObject", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    RadialScale.prototype._onStartAnglePropertyChanged = function (oldValue, newValue) {
        if (!this.ios) {
            return;
        }
        this.ios.startAngle = this.degreesToRadians(newValue);
        if (this.sweepAngle) {
            this.ios.endAngle = this.degreesToRadians(newValue + this.sweepAngle);
        }
    };
    RadialScale.prototype._onSweepAnglePropertyChanged = function (oldValue, newValue) {
        if (!this.ios) {
            return;
        }
        this.ios.endAngle = this.degreesToRadians(newValue + this.startAngle);
    };
    RadialScale.prototype._onRadiusPropertyChanged = function (oldValue, newValue) {
        if (!this.ios) {
            return;
        }
        this.ios.radius = newValue;
    };
    RadialScale.prototype.degreesToRadians = function (degrees) {
        return degrees * Math.PI / 180;
    };
    return RadialScale;
}(commonModule.RadialScale));
exports.RadialScale = RadialScale;
/////////////////////// SCALE STYLES
var ScaleStyle = /** @class */ (function (_super) {
    __extends(ScaleStyle, _super);
    function ScaleStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    ScaleStyle.prototype._onLineColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        this.owner.ios.stroke = TKStroke.strokeWithColorWidth(newValue.ios, this.owner.ios.stroke.width);
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onLineThicknessPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.stroke = TKStroke.strokeWithColorWidth(this.owner.ios.stroke.color, newValue);
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onTicksVisiblePropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.ticks.hidden = !newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onMajorTicksCountPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.ticks.majorTicksCount = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onMinorTicksCountPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.ticks.minorTicksCount = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onТicksOffsetPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.ticks.offset = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onTicksLayoutModePropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        if (newValue === commonModule.GaugeScaleLayoutMode.Inner) {
            this.owner.ios.ticks.position = 0 /* Inner */;
        }
        else if (newValue === commonModule.GaugeScaleLayoutMode.Outer) {
            this.owner.ios.ticks.position = 1 /* Outer */;
        }
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onMajorTicksWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.ticks.majorTicksWidth = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onMinorTicksWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.ticks.minorTicksWidth = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onMajorTicksLengthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.ticks.majorTicksLength = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onMinorTicksLengthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.ticks.minorTicksLength = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onMajorTicksStrokeColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        var strokeWidth = this.owner.ios.ticks.majorTicksStroke.width ? this.owner.ios.ticks.majorTicksStroke.width : 0;
        this.owner.ios.ticks.majorTicksStroke = TKStroke.strokeWithColorWidth(newValue.ios, strokeWidth);
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onМinorTicksStrokeColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        var strokeWidth = this.owner.ios.ticks.minorTicksStroke.width ? this.owner.ios.ticks.minorTicksStroke.width : 0;
        this.owner.ios.ticks.minorTicksStroke = TKStroke.strokeWithColorWidth(newValue.ios, strokeWidth);
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onMajorTicksFillColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        this.owner.ios.ticks.majorTicksFill = TKSolidFill.solidFillWithColor(newValue.ios);
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onMinorTicksFillColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        this.owner.ios.ticks.minorTicksFill = TKSolidFill.solidFillWithColor(newValue.ios);
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onМajorTicksStrokeWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        if (this.majorTicksStrokeColor) {
            this.owner.ios.ticks.majorTicksStroke = TKStroke.strokeWithColorWidth(this.majorTicksStrokeColor.ios, newValue);
        }
        else {
            this.owner.ios.ticks.majorTicksStroke = TKStroke.alloc().init();
            this.owner.ios.ticks.majorTicksStroke.width = newValue;
        }
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onМinorTicksStrokeWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        if (this.minorTicksStrokeColor) {
            this.owner.ios.ticks.minorTicksStroke = TKStroke.strokeWithColorWidth(this.minorTicksStrokeColor.ios, newValue);
        }
        else {
            this.owner.ios.ticks.minorTicksStroke = TKStroke.alloc().init();
            this.owner.ios.ticks.minorTicksStroke.width = newValue;
        }
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onLabelsVisiblePropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.labels.hidden = !newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onLabelsCountPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.labels.count = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onLabelsLayoutModePropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        if (newValue === commonModule.GaugeScaleLayoutMode.Inner) {
            this.owner.ios.labels.position = 0 /* TKGaugeLabelsPositionInner */;
        }
        else if (newValue === commonModule.GaugeScaleLayoutMode.Outer) {
            this.owner.ios.labels.position = 1 /* TKGaugeLabelsPositionOuter */;
        }
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onLabelsOffsetPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.labels.offset = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onLabelsSizePropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.labels.font = UIFont.systemFontOfSize(newValue);
        this.owner.ios.setNeedsDisplay();
    };
    ScaleStyle.prototype._onLabelsColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        this.owner.ios.labels.color = newValue.ios;
        this.owner.ios.setNeedsDisplay();
    };
    return ScaleStyle;
}(commonModule.ScaleStyle));
exports.ScaleStyle = ScaleStyle;
//////////////////////////// NEEDLE STYLES
var NeedleStyle = /** @class */ (function (_super) {
    __extends(NeedleStyle, _super);
    function NeedleStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    NeedleStyle.prototype._onLengthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.length = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onBottomWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.width = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onTopWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.topWidth = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onCircleRadiusPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.circleRadius = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onCircleInnerRadiusPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.circleInnerRadius = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onOffsetPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.offset = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onCircleFillColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        this.owner.ios.circleFill = TKSolidFill.solidFillWithColor(newValue.ios);
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onCircleStrokeColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        var strokeWidth = this.circleStrokeWidth ? this.circleStrokeWidth : 0;
        this.owner.ios.circleStroke = TKStroke.strokeWithColorWidth(newValue.ios, strokeWidth);
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onCircleStrokeWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        if (this.circleStrokeColor) {
            this.owner.ios.circleStroke = TKStroke.strokeWithColorWidth(this.circleStrokeColor.ios, newValue);
        }
        else {
            this.owner.ios.circleStroke = TKStroke.alloc().init();
            this.owner.ios.circleStroke.width = newValue;
        }
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onFillColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        this.owner.ios.fill = TKSolidFill.solidFillWithColor(newValue.ios);
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onStrokeColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        var strokeWidth = this.strokeWidth ? this.strokeWidth : 0;
        this.owner.ios.stroke = TKStroke.strokeWithColorWidth(newValue.ios, strokeWidth);
        this.owner.ios.setNeedsDisplay();
    };
    NeedleStyle.prototype._onStrokeWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        if (this.strokeColor) {
            this.owner.ios.stroke = TKStroke.strokeWithColorWidth(this.strokeColor.ios, newValue);
        }
        else {
            this.owner.ios.stroke = TKStroke.alloc().init();
            this.owner.ios.stroke.width = newValue;
        }
        this.owner.ios.setNeedsDisplay();
    };
    return NeedleStyle;
}(commonModule.NeedleStyle));
exports.NeedleStyle = NeedleStyle;
/////////////////////////// BAR INDICATOR STYLE
var BarIndicatorStyle = /** @class */ (function (_super) {
    __extends(BarIndicatorStyle, _super);
    function BarIndicatorStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    BarIndicatorStyle.prototype._onCapPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        if (newValue === commonModule.GaugeIndicatorCapMode.Edge) {
            this.owner.ios.cap = 1 /* Edge */;
        }
        else if (newValue === commonModule.GaugeIndicatorCapMode.Round) {
            this.owner.ios.cap = 0 /* Round */;
        }
        this.owner.ios.setNeedsDisplay();
    };
    BarIndicatorStyle.prototype._onBarWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        this.owner.ios.width = newValue;
        this.owner.ios.width2 = newValue;
        this.owner.ios.setNeedsDisplay();
    };
    BarIndicatorStyle.prototype._onFillColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        this.owner.ios.fill = TKSolidFill.solidFillWithColor(newValue.ios);
        this.owner.ios.setNeedsDisplay();
    };
    BarIndicatorStyle.prototype._onStrokeColorPropertyChanged = function (oldValue, newValue) {
        if (!this.owner || !newValue) {
            return;
        }
        var strokeWidth = this.strokeWidth ? this.strokeWidth : 0;
        this.owner.ios.stroke = TKStroke.strokeWithColorWidth(newValue.ios, strokeWidth);
        this.owner.ios.setNeedsDisplay();
    };
    BarIndicatorStyle.prototype._onStrokeWidthPropertyChanged = function (oldValue, newValue) {
        if (!this.owner) {
            return;
        }
        if (this.strokeColor) {
            this.owner.ios.stroke = TKStroke.strokeWithColorWidth(this.strokeColor.ios, newValue);
        }
        else {
            this.owner.ios.stroke = TKStroke.alloc().init();
            this.owner.ios.stroke.width = newValue;
        }
        this.owner.ios.setNeedsDisplay();
    };
    return BarIndicatorStyle;
}(commonModule.BarIndicatorStyle));
exports.BarIndicatorStyle = BarIndicatorStyle;
/////////////////////////// INDICATORS
var RadialNeedle = /** @class */ (function (_super) {
    __extends(RadialNeedle, _super);
    function RadialNeedle() {
        var _this = _super.call(this) || this;
        _this._ios = TKGaugeNeedle.alloc().init();
        return _this;
    }
    Object.defineProperty(RadialNeedle.prototype, "ios", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadialNeedle.prototype, "nativeObject", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadialNeedle.prototype, "_nativeView", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    RadialNeedle.prototype._onValuePropertyChanged = function (oldValue, newValue) {
        if (!this._ios) {
            return;
        }
        if (this.isAnimated) {
            var duration = this.animationDuration ? (this.animationDuration / 1000) : 1;
            this._ios.setValueAnimatedWithDurationMediaTimingFunction(newValue, duration, undefined);
        }
        else {
            this._ios.value = newValue;
        }
    };
    return RadialNeedle;
}(commonModule.RadialNeedle));
exports.RadialNeedle = RadialNeedle;
var RadialBarIndicator = /** @class */ (function (_super) {
    __extends(RadialBarIndicator, _super);
    function RadialBarIndicator() {
        var _this = _super.call(this) || this;
        _this._ios = TKGaugeSegment.alloc().init();
        return _this;
    }
    Object.defineProperty(RadialBarIndicator.prototype, "ios", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadialBarIndicator.prototype, "nativeObject", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadialBarIndicator.prototype, "_nativeView", {
        get: function () {
            return this._ios;
        },
        enumerable: true,
        configurable: true
    });
    return RadialBarIndicator;
}(commonModule.RadialBarIndicator));
exports.RadialBarIndicator = RadialBarIndicator;
