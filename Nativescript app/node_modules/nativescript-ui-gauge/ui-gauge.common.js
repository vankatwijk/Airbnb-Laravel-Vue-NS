Object.defineProperty(exports, "__esModule", { value: true });
var view_1 = require("tns-core-modules/ui/core/view");
var observable_array_1 = require("tns-core-modules/data/observable-array");
var gaugesInitializersImpl = require("./initializers/gauges-initializers");
var weakEvents = require("tns-core-modules/ui/core/weak-event-listener");
var color_1 = require("tns-core-modules/color");
var GaugeScaleLayoutMode;
(function (GaugeScaleLayoutMode) {
    GaugeScaleLayoutMode["Outer"] = "Outer";
    GaugeScaleLayoutMode["Inner"] = "Inner";
})(GaugeScaleLayoutMode = exports.GaugeScaleLayoutMode || (exports.GaugeScaleLayoutMode = {}));
var GaugeIndicatorCapMode;
(function (GaugeIndicatorCapMode) {
    GaugeIndicatorCapMode["Round"] = "Round";
    GaugeIndicatorCapMode["Edge"] = "Edge";
})(GaugeIndicatorCapMode = exports.GaugeIndicatorCapMode || (exports.GaugeIndicatorCapMode = {}));
/*
* Defines the known properties that are collections. This is used by the XML parser.
*/
var knownCollections;
(function (knownCollections) {
    knownCollections.scales = "scales";
    knownCollections.indicators = "indicators";
})(knownCollections = exports.knownCollections || (exports.knownCollections = {}));
///////////////////////////////////////////////////
var RadGauge = /** @class */ (function (_super) {
    __extends(RadGauge, _super);
    function RadGauge() {
        var _this = _super.call(this) || this;
        _this.on("bindingContextChange", _this.bindingContextChanged, _this);
        return _this;
    }
    RadGauge.prototype.onScalesPropertyChanged = function (oldValue, newValue) {
        this._onScalesPropertyChanged(oldValue, newValue);
    };
    RadGauge.prototype.onTitlePropertyChanged = function (oldValue, newValue) {
        this._onTitlePropertyChanged(oldValue, newValue);
    };
    RadGauge.prototype.onSubtitlePropertyChanged = function (oldValue, newValue) {
        this._onSubtitlePropertyChanged(oldValue, newValue);
    };
    RadGauge.prototype.onFillColorPropertyChanged = function (oldValue, newValue) {
        this._onFillColorPropertyChanged(oldValue, newValue);
    };
    RadGauge.prototype.bindingContextChanged = function (data) {
        if (this.scales) {
            for (var i = 0; i < this.scales.length; i++) {
                var scale = this.scales.getItem(i);
                scale.bindingContext = data.value;
                if (scale.indicators) {
                    for (var j = 0; j < scale.indicators.length; j++) {
                        var indicator = scale.indicators.getItem(j);
                        indicator.bindingContext = data.value;
                    }
                }
            }
        }
        if (this.titleStyle) {
            this.titleStyle.bindingContext = data.value;
        }
        if (this.subtitleStyle) {
            this.subtitleStyle.bindingContext = data.value;
        }
    };
    RadGauge.prototype._onScalesPropertyChanged = function (oldValue, newValue) {
        if (!this.nativeObject) {
            return;
        }
        if (oldValue) {
            for (var i = 0; i < oldValue.length; i++) {
                var scale = oldValue.getItem(i);
                scale.owner = undefined;
            }
            weakEvents.removeWeakEventListener(oldValue, observable_array_1.ObservableArray.changeEvent, this.scalesCollectionChanged, this);
        }
        if (newValue) {
            weakEvents.addWeakEventListener(newValue, observable_array_1.ObservableArray.changeEvent, this.scalesCollectionChanged, this);
        }
        this.reloadScales();
    };
    RadGauge.prototype.scalesCollectionChanged = function (eventData) {
        if (this && typeof this.reloadScales === "function") {
            this.reloadScales();
        }
    };
    RadGauge.prototype.reloadScales = function () {
        this.nativeObject.removeAllScales();
        for (var i = 0; i < this.scales.length; i++) {
            var scale = this.scales.getItem(i);
            scale.owner = this;
            this.nativeObject.addScale(scale.nativeObject);
        }
    };
    RadGauge.prototype.onTitleStylePropertyChanged = function (oldValue, newValue) {
        this._onTitleStylePropertyChanged(oldValue, newValue);
    };
    RadGauge.prototype.onSubtitleStylePropertyChanged = function (oldValue, newValue) {
        this._onSubtitleStylePropertyChanged(oldValue, newValue);
    };
    RadGauge.prototype._onTitlePropertyChanged = function (oldValue, newValue) {
        this.initializer.onTitleChanged(oldValue, newValue, this);
    };
    RadGauge.prototype._onSubtitlePropertyChanged = function (oldValue, newValue) {
        this.initializer.onSubtitleChanged(oldValue, newValue, this);
    };
    RadGauge.prototype._onFillColorPropertyChanged = function (oldValue, newValue) { };
    RadGauge.prototype._onTitleStylePropertyChanged = function (oldValue, newValue) {
        this.initializer.onTitleStyleChanged(oldValue, newValue, this);
    };
    RadGauge.prototype._onSubtitleStylePropertyChanged = function (oldValue, newValue) {
        this.initializer.onSubtitleStyleChanged(oldValue, newValue, this);
    };
    Object.defineProperty(RadGauge.prototype, "nativeObject", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadGauge.prototype, "_nativeView", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadGauge.prototype, "initializer", {
        get: function () {
            if (!this._initializer) {
                this._initializer = new gaugesInitializersImpl.RadGaugeValueMapper();
            }
            return this._initializer;
        },
        enumerable: true,
        configurable: true
    });
    RadGauge.prototype._addArrayFromBuilder = function (name, value) {
        if (name === "scales") {
            this.scales = new observable_array_1.ObservableArray(value);
        }
    };
    RadGauge.scalesProperty = new view_1.Property({
        name: "scales",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onScalesPropertyChanged(oldValue, newValue);
        },
    });
    RadGauge.titleProperty = new view_1.Property({
        name: "title",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onTitlePropertyChanged(oldValue, newValue);
        },
    });
    RadGauge.subtitleProperty = new view_1.Property({
        name: "subtitle",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onSubtitlePropertyChanged(oldValue, newValue);
        },
    });
    RadGauge.fillColorProperty = new view_1.Property({
        name: "fillColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onFillColorPropertyChanged(oldValue, newValue);
        },
    });
    RadGauge.titleStyleProperty = new view_1.Property({
        name: "titleStyle",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onTitleStylePropertyChanged(oldValue, newValue);
        },
    });
    RadGauge.subtitleStyleProperty = new view_1.Property({
        name: "subtitleStyle",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onSubtitleStylePropertyChanged(oldValue, newValue);
        },
    });
    return RadGauge;
}(view_1.View));
exports.RadGauge = RadGauge;
RadGauge.scalesProperty.register(RadGauge);
RadGauge.titleProperty.register(RadGauge);
RadGauge.subtitleProperty.register(RadGauge);
RadGauge.fillColorProperty.register(RadGauge);
RadGauge.titleStyleProperty.register(RadGauge);
RadGauge.subtitleStyleProperty.register(RadGauge);
////////////////////////////////////////////////////
var RadRadialGauge = /** @class */ (function (_super) {
    __extends(RadRadialGauge, _super);
    function RadRadialGauge() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return RadRadialGauge;
}(RadGauge));
exports.RadRadialGauge = RadRadialGauge;
///////////////////////////////////////////////////
var GaugeScale = /** @class */ (function (_super) {
    __extends(GaugeScale, _super);
    function GaugeScale() {
        var _this = _super.call(this) || this;
        _this.on("bindingContextChange", _this.bindingContextChanged, _this);
        return _this;
    }
    GaugeScale.prototype.bindingContextChanged = function (data) {
        if (this.scaleStyle) {
            this.scaleStyle.bindingContext = data.value;
        }
    };
    GaugeScale.prototype.onIndicatorsPropertyChanged = function (oldValue, newValue) {
        this._onIndicatorsPropertyChanged(oldValue, newValue);
    };
    GaugeScale.prototype.onMinimumPropertyChanged = function (oldValue, newValue) {
        this._onMinimumPropertyChanged(oldValue, newValue);
    };
    GaugeScale.prototype.onMaximumPropertyChanged = function (oldValue, newValue) {
        this._onMaximumPropertyChanged(oldValue, newValue);
    };
    GaugeScale.prototype.onScaleStylePropertyChanged = function (oldValue, newValue) {
        this._onScaleStylePropertyChanged(oldValue, newValue);
    };
    GaugeScale.prototype._onIndicatorsPropertyChanged = function (oldValue, newValue) {
        this.initializer.onIndicatorsChange(oldValue, newValue, this);
    };
    GaugeScale.prototype._onMinimumPropertyChanged = function (oldValue, newValue) {
        this.initializer.onMinimumChanged(oldValue, newValue, this);
    };
    GaugeScale.prototype._onMaximumPropertyChanged = function (oldValue, newValue) {
        this.initializer.onMaximumChanged(oldValue, newValue, this);
    };
    GaugeScale.prototype._onScaleStylePropertyChanged = function (oldValue, newValue) {
        this.initializer.onScaleStyleChanged(oldValue, newValue, this);
    };
    GaugeScale.prototype._addArrayFromBuilder = function (name, value) {
        if (name === "indicators") {
            this.indicators = new observable_array_1.ObservableArray(value);
        }
    };
    GaugeScale.prototype.indicatorsCollectionChanged = function (eventData) {
        if (this && this.initializer) {
            this.initializer.reloadIndicators(this);
        }
    };
    Object.defineProperty(GaugeScale.prototype, "android", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(GaugeScale.prototype, "ios", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(GaugeScale.prototype, "nativeObject", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(GaugeScale.prototype, "_nativeView", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(GaugeScale.prototype, "initializer", {
        get: function () {
            if (!this._initializer) {
                this._initializer = new gaugesInitializersImpl.GaugeScaleValueMapper();
            }
            return this._initializer;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(GaugeScale.prototype, "owner", {
        get: function () {
            return this._owner;
        },
        set: function (value) {
            this._owner = value;
        },
        enumerable: true,
        configurable: true
    });
    GaugeScale.indicatorsProperty = new view_1.Property({
        name: "indicators",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onIndicatorsPropertyChanged(oldValue, newValue);
        },
    });
    GaugeScale.minimumProperty = new view_1.Property({
        name: "minimum",
        defaultValue: 0,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMinimumPropertyChanged(oldValue, newValue);
        },
    });
    GaugeScale.maximumProperty = new view_1.Property({
        name: "maximum",
        defaultValue: 100,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMaximumPropertyChanged(oldValue, newValue);
        },
    });
    GaugeScale.scaleStyleProperty = new view_1.Property({
        name: "scaleStyle",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onScaleStylePropertyChanged(oldValue, newValue);
        },
    });
    return GaugeScale;
}(view_1.ViewBase));
exports.GaugeScale = GaugeScale;
GaugeScale.indicatorsProperty.register(GaugeScale);
GaugeScale.minimumProperty.register(GaugeScale);
GaugeScale.maximumProperty.register(GaugeScale);
GaugeScale.scaleStyleProperty.register(GaugeScale);
//////////////////////////////////////////////////////////
var RadialScale = /** @class */ (function (_super) {
    __extends(RadialScale, _super);
    function RadialScale() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    RadialScale.prototype.onStartAnglePropertyChanged = function (oldValue, newValue) {
        this._onStartAnglePropertyChanged(oldValue, newValue);
    };
    RadialScale.prototype.onSweepAnglePropertyChanged = function (oldValue, newValue) {
        this._onSweepAnglePropertyChanged(oldValue, newValue);
    };
    RadialScale.prototype.onRadiusPropertyChanged = function (oldValue, newValue) {
        this._onRadiusPropertyChanged(oldValue, newValue);
    };
    RadialScale.prototype._onStartAnglePropertyChanged = function (oldValue, newValue) { };
    RadialScale.prototype._onSweepAnglePropertyChanged = function (oldValue, newValue) { };
    RadialScale.prototype._onRadiusPropertyChanged = function (oldValue, newValue) { };
    RadialScale.startAngleProperty = new view_1.Property({
        name: "startAngle",
        defaultValue: 135,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onStartAnglePropertyChanged(oldValue, newValue);
        },
    });
    RadialScale.sweepAngleProperty = new view_1.Property({
        name: "sweepAngle",
        defaultValue: 270,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onSweepAnglePropertyChanged(oldValue, newValue);
        },
    });
    RadialScale.radiusProperty = new view_1.Property({
        name: "radius",
        defaultValue: 1,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onRadiusPropertyChanged(oldValue, newValue);
        },
    });
    return RadialScale;
}(GaugeScale));
exports.RadialScale = RadialScale;
RadialScale.startAngleProperty.register(RadialScale);
RadialScale.sweepAngleProperty.register(RadialScale);
RadialScale.radiusProperty.register(RadialScale);
/////////////////////////////////////////////////////////////
var GaugeIndicator = /** @class */ (function (_super) {
    __extends(GaugeIndicator, _super);
    function GaugeIndicator() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    Object.defineProperty(GaugeIndicator.prototype, "initializer", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    GaugeIndicator.prototype.onIsAnimatedPropertyChanged = function (oldValue, newValue) {
        this._onIsAnimatedPropertyChanged(oldValue, newValue);
    };
    GaugeIndicator.prototype.onAnimationDurationPropertyChanged = function (oldValue, newValue) {
        this._onAnimationDurationPropertyChanged(oldValue, newValue);
    };
    GaugeIndicator.prototype._onIsAnimatedPropertyChanged = function (oldValue, newValue) {
        this.initializer.onIsAnimatedChanged(oldValue, newValue, this);
    };
    GaugeIndicator.prototype._onAnimationDurationPropertyChanged = function (oldValue, newValue) {
        this.initializer.onAnimationDurationChanged(oldValue, newValue, this);
    };
    Object.defineProperty(GaugeIndicator.prototype, "ios", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(GaugeIndicator.prototype, "android", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(GaugeIndicator.prototype, "owner", {
        set: function (value) {
            this._owner = value;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(GaugeIndicator.prototype, "nativeObject", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(GaugeIndicator.prototype, "_nativeView", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    GaugeIndicator.isAnimatedProperty = new view_1.Property({
        name: "isAnimated",
        defaultValue: false,
        valueConverter: view_1.booleanConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.onIsAnimatedPropertyChanged(oldValue, newValue);
        },
    });
    GaugeIndicator.animationDurationProperty = new view_1.Property({
        name: "animationDuration",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onAnimationDurationPropertyChanged(oldValue, newValue);
        },
    });
    return GaugeIndicator;
}(view_1.ViewBase));
exports.GaugeIndicator = GaugeIndicator;
GaugeIndicator.isAnimatedProperty.register(GaugeIndicator);
GaugeIndicator.animationDurationProperty.register(GaugeIndicator);
///////////////////////////////////////////////////////////////
var RadialNeedle = /** @class */ (function (_super) {
    __extends(RadialNeedle, _super);
    function RadialNeedle() {
        var _this = _super.call(this) || this;
        _this.on("bindingContextChange", _this.bindingContextChanged, _this);
        return _this;
    }
    RadialNeedle.prototype.bindingContextChanged = function (data) {
        if (this.needleStyle) {
            this.needleStyle.bindingContext = data.value;
        }
    };
    RadialNeedle.prototype.onNeedleStylePropertyChanged = function (oldValue, newValue) {
        this._onNeedleStylePropertyChanged(oldValue, newValue);
    };
    RadialNeedle.prototype.onValuePropertyChanged = function (oldValue, newValue) {
        this._onValuePropertyChanged(oldValue, newValue);
    };
    RadialNeedle.prototype._onNeedleStylePropertyChanged = function (oldValue, newValue) {
        this.initializer.onNeedleStyleChanged(oldValue, newValue, this);
    };
    RadialNeedle.prototype._onValuePropertyChanged = function (oldValue, newValue) { };
    Object.defineProperty(RadialNeedle.prototype, "initializer", {
        get: function () {
            if (!this._initializer) {
                this._initializer = new gaugesInitializersImpl.NeedleIndicatorValueMapper();
            }
            return this._initializer;
        },
        enumerable: true,
        configurable: true
    });
    RadialNeedle.needleStyleProperty = new view_1.Property({
        name: "needleStyle",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onNeedleStylePropertyChanged(oldValue, newValue);
        },
    });
    RadialNeedle.valueProperty = new view_1.Property({
        name: "value",
        defaultValue: 0,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onValuePropertyChanged(oldValue, newValue);
        },
    });
    return RadialNeedle;
}(GaugeIndicator));
exports.RadialNeedle = RadialNeedle;
RadialNeedle.needleStyleProperty.register(RadialNeedle);
RadialNeedle.valueProperty.register(RadialNeedle);
/////////////////////////////////////////////////////////////
var BarIndicator = /** @class */ (function (_super) {
    __extends(BarIndicator, _super);
    function BarIndicator() {
        var _this = _super.call(this) || this;
        _this.on("bindingContextChange", _this.bindingContextChanged, _this);
        return _this;
    }
    BarIndicator.prototype.bindingContextChanged = function (data) {
        if (this.indicatorStyle) {
            this.indicatorStyle.bindingContext = data.value;
        }
    };
    BarIndicator.prototype.onIndicatorStylePropertyChanged = function (oldValue, newValue) {
        this._onIndicatorStyleChanged(oldValue, newValue);
    };
    BarIndicator.prototype.onMinimumPropertyChanged = function (oldValue, newValue) {
        this._onMinimumPropertyChanged(oldValue, newValue);
    };
    BarIndicator.prototype.onMaximumPropertyChanged = function (oldValue, newValue) {
        this._onMaximumPropertyChanged(oldValue, newValue);
    };
    BarIndicator.prototype.onLocationPropertyChanged = function (oldValue, newValue) {
        this._onLocationPropertyChanged(oldValue, newValue);
    };
    BarIndicator.prototype.onAnimationStartValueChanged = function (oldValue, newValue) {
        this._onAnimationStartValueChanged(oldValue, newValue);
    };
    BarIndicator.prototype._onIndicatorStyleChanged = function (oldValue, newValue) {
        this.initializer.onIndicatorStyleChanged(oldValue, newValue, this);
    };
    BarIndicator.prototype._onMinimumPropertyChanged = function (oldValue, newValue) {
        this.initializer.onMinimumValueChanged(oldValue, newValue, this);
    };
    BarIndicator.prototype._onMaximumPropertyChanged = function (oldValue, newValue) {
        this.initializer.onMaximumValueChanged(oldValue, newValue, this);
    };
    BarIndicator.prototype._onLocationPropertyChanged = function (oldValue, newValue) {
        this.initializer.onLocationChanged(oldValue, newValue, this);
    };
    BarIndicator.prototype._onAnimationStartValueChanged = function (oldValue, newValue) { };
    Object.defineProperty(BarIndicator.prototype, "initializer", {
        get: function () {
            if (!this._initializer) {
                this._initializer = new gaugesInitializersImpl.BarIndicatorValueMapper();
            }
            return this._initializer;
        },
        enumerable: true,
        configurable: true
    });
    BarIndicator.indicatorStyleProperty = new view_1.Property({
        name: "indicatorStyle",
        defaultValue: undefined,
        valueChanged: function (target, oldValue, newValue) {
            target.onIndicatorStylePropertyChanged(oldValue, newValue);
        },
    });
    BarIndicator.minimumProperty = new view_1.Property({
        name: "minimum",
        defaultValue: 0,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMinimumPropertyChanged(oldValue, newValue);
        },
    });
    BarIndicator.maximumProperty = new view_1.Property({
        name: "maximum",
        defaultValue: 0,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMaximumPropertyChanged(oldValue, newValue);
        },
    });
    BarIndicator.locationProperty = new view_1.Property({
        name: "location",
        defaultValue: 1,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onLocationPropertyChanged(oldValue, newValue);
        },
    });
    BarIndicator.animationStartValueProperty = new view_1.Property({
        name: "animationStartValue",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onAnimationStartValueChanged(oldValue, newValue);
        },
    });
    return BarIndicator;
}(GaugeIndicator));
exports.BarIndicator = BarIndicator;
BarIndicator.indicatorStyleProperty.register(BarIndicator);
BarIndicator.minimumProperty.register(BarIndicator);
BarIndicator.maximumProperty.register(BarIndicator);
BarIndicator.locationProperty.register(BarIndicator);
BarIndicator.animationStartValueProperty.register(BarIndicator);
/////////////////////////////////////////////////////////////////
var RadialBarIndicator = /** @class */ (function (_super) {
    __extends(RadialBarIndicator, _super);
    function RadialBarIndicator() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return RadialBarIndicator;
}(BarIndicator));
exports.RadialBarIndicator = RadialBarIndicator;
////////////////////////// STYLES
var GaugeStyleBase = /** @class */ (function (_super) {
    __extends(GaugeStyleBase, _super);
    function GaugeStyleBase() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    GaugeStyleBase.prototype.onFillColorPropertyChanged = function (oldValue, newValue) {
        this._onFillColorPropertyChanged(oldValue, newValue);
    };
    GaugeStyleBase.prototype.onStrokeColorPropertyChanged = function (oldValue, newValue) {
        this._onStrokeColorPropertyChanged(oldValue, newValue);
    };
    GaugeStyleBase.prototype.onStrokeWidthPropertyChanged = function (oldValue, newValue) {
        this._onStrokeWidthPropertyChanged(oldValue, newValue);
    };
    // TODO implement common setting of stroke and fill because of repetitive code;
    GaugeStyleBase.prototype._onFillColorPropertyChanged = function (oldValue, newValue) { };
    GaugeStyleBase.prototype._onStrokeColorPropertyChanged = function (oldValue, newValue) { };
    GaugeStyleBase.prototype._onStrokeWidthPropertyChanged = function (oldValue, newValue) { };
    Object.defineProperty(GaugeStyleBase.prototype, "owner", {
        get: function () {
            return this._owner;
        },
        set: function (value) {
            this._owner = value;
        },
        enumerable: true,
        configurable: true
    });
    GaugeStyleBase.prototype.shouldUpdateNativeObject = function () {
        if (!this.owner || !this.owner.nativeObject) {
            return false;
        }
        return true;
    };
    GaugeStyleBase.fillColorProperty = new view_1.Property({
        name: "fillColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onFillColorPropertyChanged(oldValue, newValue);
        },
    });
    GaugeStyleBase.strokeColorProperty = new view_1.Property({
        name: "strokeColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onStrokeColorPropertyChanged(oldValue, newValue);
        },
    });
    GaugeStyleBase.strokeWidthProperty = new view_1.Property({
        name: "strokeWidth",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onStrokeWidthPropertyChanged(oldValue, newValue);
        },
    });
    return GaugeStyleBase;
}(view_1.ViewBase));
exports.GaugeStyleBase = GaugeStyleBase;
GaugeStyleBase.fillColorProperty.register(GaugeStyleBase);
GaugeStyleBase.strokeColorProperty.register(GaugeStyleBase);
GaugeStyleBase.strokeWidthProperty.register(GaugeStyleBase);
//////////////////////////////////////////////////////////////////
var TitleStyle = /** @class */ (function (_super) {
    __extends(TitleStyle, _super);
    function TitleStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    TitleStyle.prototype.onTextSizePropertyChanged = function (oldValue, newValue) {
        this._onTextSizePropertyChanged(oldValue, newValue);
    };
    TitleStyle.prototype.onTextColorPropertyChanged = function (oldValue, newValue) {
        this._onTextColorPropertyChanged(oldValue, newValue);
    };
    TitleStyle.prototype.onHorizontalOffsetPropertyChanged = function (oldValue, newValue) {
        this._onHorizontalOffsetPropertyChanged(oldValue, newValue);
    };
    TitleStyle.prototype.onVerticalOffsetPropertyChanged = function (oldValue, newValue) {
        this._onVerticalOffsetPropertyChanged(oldValue, newValue);
    };
    TitleStyle.prototype._onTextSizePropertyChanged = function (oldValue, newValue) { };
    TitleStyle.prototype._onTextColorPropertyChanged = function (oldValue, newValue) { };
    TitleStyle.prototype._onHorizontalOffsetPropertyChanged = function (oldValue, newValue) { };
    TitleStyle.prototype._onVerticalOffsetPropertyChanged = function (oldValue, newValue) { };
    TitleStyle.textSizeProperty = new view_1.Property({
        name: "textSize",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onTextSizePropertyChanged(oldValue, newValue);
        },
    });
    TitleStyle.textColorProperty = new view_1.Property({
        name: "textColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onTextColorPropertyChanged(oldValue, newValue);
        },
    });
    TitleStyle.horizontalOffsetProperty = new view_1.Property({
        name: "horizontalOffset",
        defaultValue: 0,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onHorizontalOffsetPropertyChanged(oldValue, newValue);
        },
    });
    TitleStyle.verticalOffsetProperty = new view_1.Property({
        name: "verticalOffset",
        defaultValue: 0,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onVerticalOffsetPropertyChanged(oldValue, newValue);
        },
    });
    return TitleStyle;
}(GaugeStyleBase));
exports.TitleStyle = TitleStyle;
TitleStyle.textSizeProperty.register(TitleStyle);
TitleStyle.textColorProperty.register(TitleStyle);
TitleStyle.horizontalOffsetProperty.register(TitleStyle);
TitleStyle.verticalOffsetProperty.register(TitleStyle);
/////////////////////////////////////////////////////////////////////
var SubtitleStyle = /** @class */ (function (_super) {
    __extends(SubtitleStyle, _super);
    function SubtitleStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return SubtitleStyle;
}(TitleStyle));
exports.SubtitleStyle = SubtitleStyle;
var ScaleStyle = /** @class */ (function (_super) {
    __extends(ScaleStyle, _super);
    function ScaleStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    ScaleStyle.prototype.onLineColorPropertyChanged = function (oldValue, newValue) {
        this._onLineColorPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onLineColorPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onLineThicknessPropertyChanged = function (oldValue, newValue) {
        this._onLineThicknessPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onLineThicknessPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onTicksVisiblePropertyChanged = function (oldValue, newValue) {
        this._onTicksVisiblePropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onTicksVisiblePropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onMajorTicksCountPropertyChanged = function (oldValue, newValue) {
        this._onMajorTicksCountPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onMajorTicksCountPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onMinorTicksCountPropertyChanged = function (oldValue, newValue) {
        this._onMinorTicksCountPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onMinorTicksCountPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onТicksOffsetPropertyChanged = function (oldValue, newValue) {
        this._onТicksOffsetPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onТicksOffsetPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onTicksLayoutModePropertyChanged = function (oldValue, newValue) {
        this._onTicksLayoutModePropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onTicksLayoutModePropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onMajorTicksWidthPropertyChanged = function (oldValue, newValue) {
        this._onMajorTicksWidthPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onMajorTicksWidthPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onMinorTicksWidthPropertyChanged = function (oldValue, newValue) {
        this._onMinorTicksWidthPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onMinorTicksWidthPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onMajorTicksLengthPropertyChanged = function (oldValue, newValue) {
        this._onMajorTicksLengthPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onMajorTicksLengthPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onMinorTicksLengthPropertyChanged = function (oldValue, newValue) {
        this._onMinorTicksLengthPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onMinorTicksLengthPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onMajorTicksStrokeColorPropertyChanged = function (oldValue, newValue) {
        this._onMajorTicksStrokeColorPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onMajorTicksStrokeColorPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onМinorTicksStrokeColorPropertyChanged = function (oldValue, newValue) {
        this._onМinorTicksStrokeColorPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onМinorTicksStrokeColorPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onMajorTicksFillColorPropertyChanged = function (oldValue, newValue) {
        this._onMajorTicksFillColorPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onMajorTicksFillColorPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onMinorTicksFillColorPropertyChanged = function (oldValue, newValue) {
        this._onMinorTicksFillColorPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onMinorTicksFillColorPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onМajorTicksStrokeWidthPropertyChanged = function (oldValue, newValue) {
        this._onМajorTicksStrokeWidthPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onМajorTicksStrokeWidthPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onМinorTicksStrokeWidthPropertyChanged = function (oldValue, newValue) {
        this._onМinorTicksStrokeWidthPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onМinorTicksStrokeWidthPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onLabelsVisiblePropertyChanged = function (oldValue, newValue) {
        this._onLabelsVisiblePropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onLabelsVisiblePropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onLabelsCountPropertyChanged = function (oldValue, newValue) {
        this._onLabelsCountPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onLabelsCountPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onLabelsLayoutModePropertyChanged = function (oldValue, newValue) {
        this._onLabelsLayoutModePropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onLabelsLayoutModePropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onLabelsOffsetPropertyChanged = function (oldValue, newValue) {
        this._onLabelsOffsetPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onLabelsOffsetPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onLabelsSizePropertyChanged = function (oldValue, newValue) {
        this._onLabelsSizePropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onLabelsSizePropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.prototype.onLabelsColorPropertyChanged = function (oldValue, newValue) {
        this._onLabelsColorPropertyChanged(oldValue, newValue);
    };
    ScaleStyle.prototype._onLabelsColorPropertyChanged = function (oldValue, newValue) { };
    ScaleStyle.lineColorProperty = new view_1.Property({
        name: "lineColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onLineColorPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.lineThicknessProperty = new view_1.Property({
        name: "lineThickness",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onLineThicknessPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.ticksVisibleProperty = new view_1.Property({
        name: "ticksVisible",
        defaultValue: true,
        valueConverter: view_1.booleanConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.onTicksVisiblePropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.majorTicksCountProperty = new view_1.Property({
        name: "majorTicksCount",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMajorTicksCountPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.minorTicksCountProperty = new view_1.Property({
        name: "minorTicksCount",
        defaultValue: undefined,
        valueConverter: function (v) { return parseInt(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMinorTicksCountPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.ticksOffsetProperty = new view_1.Property({
        name: "ticksOffset",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onТicksOffsetPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.ticksLayoutModeProperty = new view_1.Property({
        name: "ticksLayoutMode",
        defaultValue: undefined,
        valueConverter: function (value) { return GaugeScaleLayoutMode[value]; },
        valueChanged: function (target, oldValue, newValue) {
            target.onTicksLayoutModePropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.majorTicksWidthProperty = new view_1.Property({
        name: "majorTicksWidth",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMajorTicksWidthPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.minorTicksWidthProperty = new view_1.Property({
        name: "minorTicksWidth",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMinorTicksWidthPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.majorTicksLengthProperty = new view_1.Property({
        name: "majorTicksLength",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMajorTicksLengthPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.minorTicksLengthProperty = new view_1.Property({
        name: "minorTicksLength",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMinorTicksLengthPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.majorTicksStrokeColorProperty = new view_1.Property({
        name: "majorTicksStrokeColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMajorTicksStrokeColorPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.minorTicksStrokeColorProperty = new view_1.Property({
        name: "minorTicksStrokeColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onМinorTicksStrokeColorPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.majorTicksFillColorProperty = new view_1.Property({
        name: "majorTicksFillColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMajorTicksFillColorPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.minorTicksFillColorProperty = new view_1.Property({
        name: "minorTicksFillColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onMinorTicksFillColorPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.majorTicksStrokeWidthProperty = new view_1.Property({
        name: "majorTicksStrokeWidth",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onМajorTicksStrokeWidthPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.minorTicksStrokeWidthProperty = new view_1.Property({
        name: "minorTicksStrokeWidth",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onМinorTicksStrokeWidthPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.labelsVisibleProperty = new view_1.Property({
        name: "labelsVisible",
        defaultValue: true,
        valueConverter: view_1.booleanConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.onLabelsVisiblePropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.labelsCountProperty = new view_1.Property({
        name: "labelsCount",
        defaultValue: undefined,
        valueConverter: function (v) { return parseInt(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onLabelsCountPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.labelsLayoutModeProperty = new view_1.Property({
        name: "labelsLayoutMode",
        defaultValue: GaugeScaleLayoutMode.Inner,
        valueConverter: function (value) { return GaugeScaleLayoutMode[value]; },
        valueChanged: function (target, oldValue, newValue) {
            target.onLabelsLayoutModePropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.labelsOffsetProperty = new view_1.Property({
        name: "labelsOffset",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onLabelsOffsetPropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.labelsSizeProperty = new view_1.Property({
        name: "labelsSize",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onLabelsSizePropertyChanged(oldValue, newValue);
        },
    });
    ScaleStyle.labelsColorProperty = new view_1.Property({
        name: "labelsColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onLabelsColorPropertyChanged(oldValue, newValue);
        },
    });
    return ScaleStyle;
}(GaugeStyleBase));
exports.ScaleStyle = ScaleStyle;
ScaleStyle.lineColorProperty.register(ScaleStyle);
ScaleStyle.lineThicknessProperty.register(ScaleStyle);
ScaleStyle.ticksVisibleProperty.register(ScaleStyle);
ScaleStyle.majorTicksCountProperty.register(ScaleStyle);
ScaleStyle.minorTicksCountProperty.register(ScaleStyle);
ScaleStyle.ticksOffsetProperty.register(ScaleStyle);
ScaleStyle.ticksLayoutModeProperty.register(ScaleStyle);
ScaleStyle.majorTicksWidthProperty.register(ScaleStyle);
ScaleStyle.minorTicksWidthProperty.register(ScaleStyle);
ScaleStyle.majorTicksLengthProperty.register(ScaleStyle);
ScaleStyle.minorTicksLengthProperty.register(ScaleStyle);
ScaleStyle.majorTicksStrokeColorProperty.register(ScaleStyle);
ScaleStyle.minorTicksStrokeColorProperty.register(ScaleStyle);
ScaleStyle.majorTicksFillColorProperty.register(ScaleStyle);
ScaleStyle.minorTicksFillColorProperty.register(ScaleStyle);
ScaleStyle.majorTicksStrokeWidthProperty.register(ScaleStyle);
ScaleStyle.minorTicksStrokeWidthProperty.register(ScaleStyle);
ScaleStyle.labelsVisibleProperty.register(ScaleStyle);
ScaleStyle.labelsCountProperty.register(ScaleStyle);
ScaleStyle.labelsLayoutModeProperty.register(ScaleStyle);
ScaleStyle.labelsOffsetProperty.register(ScaleStyle);
ScaleStyle.labelsSizeProperty.register(ScaleStyle);
ScaleStyle.labelsColorProperty.register(ScaleStyle);
//////////////////////////////////////////////////////
var IndicatorStyle = /** @class */ (function (_super) {
    __extends(IndicatorStyle, _super);
    function IndicatorStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return IndicatorStyle;
}(GaugeStyleBase));
exports.IndicatorStyle = IndicatorStyle;
//////////////////////////////////////////////////
var NeedleStyle = /** @class */ (function (_super) {
    __extends(NeedleStyle, _super);
    function NeedleStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    NeedleStyle.prototype.onLengthPropertyChanged = function (oldValue, newValue) {
        this._onLengthPropertyChanged(oldValue, newValue);
    };
    NeedleStyle.prototype._onLengthPropertyChanged = function (oldValue, newValue) { };
    NeedleStyle.prototype.onBottomWidthPropertyChanged = function (oldValue, newValue) {
        this._onBottomWidthPropertyChanged(oldValue, newValue);
    };
    NeedleStyle.prototype._onBottomWidthPropertyChanged = function (oldValue, newValue) { };
    NeedleStyle.prototype.onTopWidthPropertyChanged = function (oldValue, newValue) {
        this._onTopWidthPropertyChanged(oldValue, newValue);
    };
    NeedleStyle.prototype._onTopWidthPropertyChanged = function (oldValue, newValue) { };
    NeedleStyle.prototype.onCircleRadiusPropertyChanged = function (oldValue, newValue) {
        this._onCircleRadiusPropertyChanged(oldValue, newValue);
    };
    NeedleStyle.prototype._onCircleRadiusPropertyChanged = function (oldValue, newValue) { };
    NeedleStyle.prototype.onCircleInnerRadiusPropertyChanged = function (oldValue, newValue) {
        this._onCircleInnerRadiusPropertyChanged(oldValue, newValue);
    };
    NeedleStyle.prototype._onCircleInnerRadiusPropertyChanged = function (oldValue, newValue) { };
    NeedleStyle.prototype.onOffsetPropertyChanged = function (oldValue, newValue) {
        this._onOffsetPropertyChanged(oldValue, newValue);
    };
    NeedleStyle.prototype._onOffsetPropertyChanged = function (oldValue, newValue) { };
    NeedleStyle.prototype.onCircleFillColorPropertyChanged = function (oldValue, newValue) {
        this._onCircleFillColorPropertyChanged(oldValue, newValue);
    };
    NeedleStyle.prototype._onCircleFillColorPropertyChanged = function (oldValue, newValue) { };
    NeedleStyle.prototype.onCircleStrokeColorPropertyChanged = function (oldValue, newValue) {
        this._onCircleStrokeColorPropertyChanged(oldValue, newValue);
    };
    NeedleStyle.prototype._onCircleStrokeColorPropertyChanged = function (oldValue, newValue) { };
    NeedleStyle.prototype.onCircleStrokeWidthPropertyChanged = function (oldValue, newValue) {
        this._onCircleStrokeWidthPropertyChanged(oldValue, newValue);
    };
    NeedleStyle.prototype._onCircleStrokeWidthPropertyChanged = function (oldValue, newValue) { };
    NeedleStyle.lengthProperty = new view_1.Property({
        name: "length",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onLengthPropertyChanged(oldValue, newValue);
        },
    });
    NeedleStyle.bottomWidthProperty = new view_1.Property({
        name: "bottomWidth",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onBottomWidthPropertyChanged(oldValue, newValue);
        },
    });
    NeedleStyle.topWidthProperty = new view_1.Property({
        name: "topWidth",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onTopWidthPropertyChanged(oldValue, newValue);
        },
    });
    NeedleStyle.circleRadiusProperty = new view_1.Property({
        name: "circleRadius",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onCircleRadiusPropertyChanged(oldValue, newValue);
        },
    });
    NeedleStyle.circleInnerRadiusProperty = new view_1.Property({
        name: "circleInnerRadius",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onCircleInnerRadiusPropertyChanged(oldValue, newValue);
        },
    });
    NeedleStyle.offsetProperty = new view_1.Property({
        name: "offset",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onOffsetPropertyChanged(oldValue, newValue);
        },
    });
    NeedleStyle.circleFillColorProperty = new view_1.Property({
        name: "circleFillColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onCircleFillColorPropertyChanged(oldValue, newValue);
        },
    });
    NeedleStyle.circleStrokeColorProperty = new view_1.Property({
        name: "circleStrokeColor",
        defaultValue: undefined,
        equalityComparer: color_1.Color.equals,
        valueConverter: function (v) { return new color_1.Color(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onCircleStrokeColorPropertyChanged(oldValue, newValue);
        },
    });
    NeedleStyle.circleStrokeWidthProperty = new view_1.Property({
        name: "circleStrokeWidth",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onCircleStrokeWidthPropertyChanged(oldValue, newValue);
        },
    });
    return NeedleStyle;
}(IndicatorStyle));
exports.NeedleStyle = NeedleStyle;
NeedleStyle.lengthProperty.register(NeedleStyle);
NeedleStyle.bottomWidthProperty.register(NeedleStyle);
NeedleStyle.topWidthProperty.register(NeedleStyle);
NeedleStyle.circleRadiusProperty.register(NeedleStyle);
NeedleStyle.circleInnerRadiusProperty.register(NeedleStyle);
NeedleStyle.offsetProperty.register(NeedleStyle);
NeedleStyle.circleFillColorProperty.register(NeedleStyle);
NeedleStyle.circleStrokeColorProperty.register(NeedleStyle);
NeedleStyle.circleStrokeWidthProperty.register(NeedleStyle);
//////////////////////////////////////////////////////////////
var BarIndicatorStyle = /** @class */ (function (_super) {
    __extends(BarIndicatorStyle, _super);
    function BarIndicatorStyle() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    BarIndicatorStyle.prototype.onCapPropertyChanged = function (oldValue, newValue) {
        this._onCapPropertyChanged(oldValue, newValue);
    };
    BarIndicatorStyle.prototype._onCapPropertyChanged = function (oldValue, newValue) { };
    BarIndicatorStyle.prototype.onBarWidthPropertyChanged = function (oldValue, newValue) {
        this._onBarWidthPropertyChanged(oldValue, newValue);
    };
    BarIndicatorStyle.prototype._onBarWidthPropertyChanged = function (oldValue, newValue) { };
    BarIndicatorStyle.capProperty = new view_1.Property({
        name: "cap",
        defaultValue: undefined,
        valueConverter: function (value) { return GaugeIndicatorCapMode[value]; },
        valueChanged: function (target, oldValue, newValue) {
            target.onCapPropertyChanged(oldValue, newValue);
        },
    });
    BarIndicatorStyle.barWidthProperty = new view_1.Property({
        name: "barWidth",
        defaultValue: undefined,
        valueConverter: function (v) { return parseFloat(v); },
        valueChanged: function (target, oldValue, newValue) {
            target.onBarWidthPropertyChanged(oldValue, newValue);
        },
    });
    return BarIndicatorStyle;
}(IndicatorStyle));
exports.BarIndicatorStyle = BarIndicatorStyle;
BarIndicatorStyle.capProperty.register(BarIndicatorStyle);
BarIndicatorStyle.barWidthProperty.register(BarIndicatorStyle);
