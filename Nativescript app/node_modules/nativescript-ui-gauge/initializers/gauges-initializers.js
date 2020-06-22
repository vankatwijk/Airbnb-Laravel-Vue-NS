Object.defineProperty(exports, "__esModule", { value: true });
var RadGaugeValueMapper = /** @class */ (function () {
    function RadGaugeValueMapper() {
    }
    RadGaugeValueMapper.prototype.onTitleChanged = function (oldValue, newValue, gauge) {
    };
    RadGaugeValueMapper.prototype.onSubtitleChanged = function (oldValue, newValue, gauge) {
    };
    RadGaugeValueMapper.prototype.onTitleStyleChanged = function (oldValue, newValue, gauge) {
    };
    RadGaugeValueMapper.prototype.onSubtitleStyleChanged = function (oldValue, newValue, gauge) {
    };
    RadGaugeValueMapper.prototype.updateNativeObject = function (gauge) {
    };
    return RadGaugeValueMapper;
}());
exports.RadGaugeValueMapper = RadGaugeValueMapper;
var GaugeScaleValueMapper = /** @class */ (function () {
    function GaugeScaleValueMapper() {
    }
    GaugeScaleValueMapper.prototype.onMinimumChanged = function (oldValue, newValue, scale) {
    };
    GaugeScaleValueMapper.prototype.onMaximumChanged = function (oldValue, newValue, scale) {
    };
    GaugeScaleValueMapper.prototype.onIndicatorsChange = function (oldValue, newValue, scale) {
    };
    GaugeScaleValueMapper.prototype.onScaleStyleChanged = function (oldValue, newValue, scale) {
    };
    GaugeScaleValueMapper.prototype.reloadIndicators = function (scale) {
    };
    GaugeScaleValueMapper.prototype.updateNativeObject = function (scale) {
    };
    return GaugeScaleValueMapper;
}());
exports.GaugeScaleValueMapper = GaugeScaleValueMapper;
var NeedleIndicatorValueMapper = /** @class */ (function () {
    function NeedleIndicatorValueMapper() {
    }
    NeedleIndicatorValueMapper.prototype.onIsAnimatedChanged = function (oldValue, newValue, indicator) {
    };
    NeedleIndicatorValueMapper.prototype.onAnimationDurationChanged = function (oldValue, newValue, indicator) {
    };
    NeedleIndicatorValueMapper.prototype.onNeedleStyleChanged = function (oldValue, newValue, needle) {
    };
    NeedleIndicatorValueMapper.prototype.updateNativeObject = function (needle) {
    };
    return NeedleIndicatorValueMapper;
}());
exports.NeedleIndicatorValueMapper = NeedleIndicatorValueMapper;
var BarIndicatorValueMapper = /** @class */ (function () {
    function BarIndicatorValueMapper() {
    }
    BarIndicatorValueMapper.prototype.onIsAnimatedChanged = function (oldValue, newValue, indicator) {
    };
    BarIndicatorValueMapper.prototype.onAnimationDurationChanged = function (oldValue, newValue, indicator) {
    };
    BarIndicatorValueMapper.prototype.onMinimumValueChanged = function (oldValue, newValue, indicator) {
    };
    BarIndicatorValueMapper.prototype.onMaximumValueChanged = function (oldValue, newValue, indicator) {
    };
    BarIndicatorValueMapper.prototype.onIndicatorStyleChanged = function (oldValue, newValue, indicator) {
    };
    BarIndicatorValueMapper.prototype.onLocationChanged = function (oldValue, newValue, indicator) {
    };
    BarIndicatorValueMapper.prototype.updateNativeObject = function (barIndicator) {
    };
    return BarIndicatorValueMapper;
}());
exports.BarIndicatorValueMapper = BarIndicatorValueMapper;
