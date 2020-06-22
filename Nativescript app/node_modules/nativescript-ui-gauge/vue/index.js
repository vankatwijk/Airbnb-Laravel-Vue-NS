Object.defineProperty(exports, "__esModule", { value: true });
var __1 = require("./..");
var observable_array_1 = require("tns-core-modules/data/observable-array");
var RadGaugePlugin = {
    install: function (Vue) {
        Vue.registerElement("RadRadialGauge", function () { return __1.RadRadialGauge; });
        Vue.registerElement("RadialScale", function () { return __1.RadialScale; });
        Vue.registerElement("ScaleStyle", function () { return __1.ScaleStyle; });
        Vue.registerElement("RadialBarIndicator", function () { return __1.RadialBarIndicator; });
        Vue.registerElement("BarIndicatorStyle", function () { return __1.BarIndicatorStyle; });
        Vue.registerElement("RadialNeedle", function () { return __1.RadialNeedle; });
        Vue.registerElement("TitleStyle", function () { return __1.TitleStyle; });
        Vue.registerElement("SubtitleStyle", function () { return __1.SubtitleStyle; });
        Vue.registerElement("NeedleStyle", function () { return __1.NeedleStyle; });
        Vue.directive("tkRadialGaugeScales", {
            inserted: function (el) {
                var scale = el._nativeView;
                var gauge = el.parentNode._nativeView;
                if (gauge.scales) {
                    gauge.scales.push(scale);
                }
                else {
                    gauge.scales = new observable_array_1.ObservableArray([scale]);
                }
            }
        });
        Vue.directive("tkRadialScaleIndicators", {
            inserted: function (el) {
                var barIndicator = el._nativeView;
                var scale = el.parentNode._nativeView;
                if (scale.indicators) {
                    scale.indicators.push(barIndicator);
                }
                else {
                    scale.indicators = new observable_array_1.ObservableArray([barIndicator]);
                }
            }
        });
        Vue.directive("tkRadialBarIndicatorStyle", {
            inserted: function (el) {
                el.parentNode._nativeView.indicatorStyle = el._nativeView;
            }
        });
        Vue.directive("tkRadialGaugeTitleStyle", {
            inserted: function (el) {
                el.parentNode._nativeView.titleStyle = el._nativeView;
            }
        });
        Vue.directive("tkRadialGaugeSubtitleStyle", {
            inserted: function (el) {
                el.parentNode._nativeView.subtitleStyle = el._nativeView;
            }
        });
        Vue.directive("tkRadialNeedleStyle", {
            inserted: function (el) {
                el.parentNode._nativeView.needleStyle = el._nativeView;
            }
        });
        Vue.directive("tkRadialScaleStyle", {
            inserted: function (el) {
                el.parentNode._nativeView.scaleStyle = el._nativeView;
            }
        });
    }
};
exports.default = RadGaugePlugin;
