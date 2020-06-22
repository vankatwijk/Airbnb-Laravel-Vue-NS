Object.defineProperty(exports, "__esModule", { value: true });
var observable_array_1 = require("tns-core-modules/data/observable-array");
var __1 = require("./..");
var RadChartPlugin = {
    install: function (Vue, options) {
        Vue.registerElement('RadCartesianChart', function () { return __1.RadCartesianChart; });
        Vue.registerElement('RadPieChart', function () { return __1.RadPieChart; });
        Vue.registerElement('RadLegendView', function () { return __1.RadLegendView; });
        Vue.registerElement('LineSeries', function () { return __1.LineSeries; });
        Vue.registerElement('PieSeries', function () { return __1.PieSeries; });
        Vue.registerElement('DonutSeries', function () { return __1.DonutSeries; });
        Vue.registerElement('AreaSeries', function () { return __1.AreaSeries; });
        Vue.registerElement('CategoricalAxis', function () { return __1.CategoricalAxis; });
        Vue.registerElement('LinearAxis', function () { return __1.LinearAxis; });
        Vue.registerElement('DateTimeCategoricalAxis', function () { return __1.DateTimeCategoricalAxis; });
        Vue.registerElement('SplineSeries', function () { return __1.SplineSeries; });
        Vue.registerElement('BarSeries', function () { return __1.BarSeries; });
        Vue.registerElement('RangeBarSeries', function () { return __1.RangeBarSeries; });
        Vue.registerElement('BubbleSeries', function () { return __1.BubbleSeries; });
        Vue.registerElement('ScatterBubbleSeries', function () { return __1.ScatterBubbleSeries; });
        Vue.registerElement('ScatterSeries', function () { return __1.ScatterSeries; });
        Vue.registerElement('OhlcSeries', function () { return __1.OhlcSeries; });
        Vue.registerElement('CandlestickSeries', function () { return __1.CandlestickSeries; });
        Vue.registerElement('RadCartesianChartGrid', function () { return __1.RadCartesianChartGrid; });
        Vue.registerElement('Palette', function () { return __1.Palette; });
        Vue.registerElement('PaletteEntry', function () { return __1.PaletteEntry; });
        Vue.registerElement('ChartGridLineAnnotation', function () { return __1.ChartGridLineAnnotation; });
        Vue.registerElement('ChartPlotBandAnnotation', function () { return __1.ChartPlotBandAnnotation; });
        Vue.registerElement('Trackball', function () { return __1.Trackball; });
        Vue.registerElement('PointLabelStyle', function () { return __1.PointLabelStyle; });
        Vue.registerElement('DateTimeContinuousAxis', function () { return __1.DateTimeContinuousAxis; });
        Vue.registerElement('LogarithmicAxis', function () { return __1.LogarithmicAxis; });
        Vue.registerElement('SplineAreaSeries', function () { return __1.SplineAreaSeries; });
        var setHorizontalAxis = {
            inserted: function (el) {
                el.parentNode._nativeView.horizontalAxis = el._nativeView;
            }
        };
        Vue.directive('tkCartesianHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkLineHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkBarHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkRangeBarHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkAreaHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkSplineHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkSplineAreaHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkBubbleHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkScatterBubbleHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkCandlestickHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkOhlcHorizontalAxis', setHorizontalAxis);
        Vue.directive('tkScatterHorizontalAxis', setHorizontalAxis);
        var setVerticalAxis = {
            inserted: function (el) {
                el.parentNode._nativeView.verticalAxis = el._nativeView;
            }
        };
        Vue.directive('tkCartesianVerticalAxis', setVerticalAxis);
        Vue.directive('tkLineVerticalAxis', setVerticalAxis);
        Vue.directive('tkBarVerticalAxis', setVerticalAxis);
        Vue.directive('tkRangeBarVerticalAxis', setVerticalAxis);
        Vue.directive('tkAreaVerticalAxis', setVerticalAxis);
        Vue.directive('tkSplineVerticalAxis', setVerticalAxis);
        Vue.directive('tkSplineAreaVerticalAxis', setVerticalAxis);
        Vue.directive('tkBubbleVerticalAxis', setVerticalAxis);
        Vue.directive('tkScatterBubbleVerticalAxis', setVerticalAxis);
        Vue.directive('tkCandlestickVerticalAxis', setVerticalAxis);
        Vue.directive('tkOhlcVerticalAxis', setVerticalAxis);
        Vue.directive('tkScatterVerticalAxis', setVerticalAxis);
        var setSeries = {
            inserted: function (el) {
                var series = el._nativeView;
                var chart = el.parentNode._nativeView;
                if (chart.series) {
                    chart.series.push(series);
                }
                else {
                    chart.series = new observable_array_1.ObservableArray([series]);
                }
            }
        };
        Vue.directive('tkCartesianSeries', setSeries);
        Vue.directive('tkPieSeries', setSeries);
        Vue.directive('tkCartesianGrid', {
            inserted: function (el) {
                el.parentNode._nativeView.grid = el._nativeView;
            }
        });
        var setPalette = {
            inserted: function (el) {
                var palette = el._nativeView;
                var chart = el.parentNode._nativeView;
                if (chart.palettes) {
                    chart.palettes.push(palette);
                }
                else {
                    chart.palettes = new observable_array_1.ObservableArray([palette]);
                }
                el.childNodes.forEach(function (entry) {
                    if (entry._nativeView.typeName === 'PaletteEntry') {
                        if (palette.entries) {
                            palette.entries.push(entry._nativeView);
                            palette.updateOwner();
                        }
                        else {
                            palette.entries = new observable_array_1.ObservableArray([entry._nativeView]);
                        }
                    }
                });
            }
        };
        Vue.directive('tkCartesianPalette', setPalette);
        Vue.directive('tkPiePalette', setPalette);
        var setEntry = {
            inserted: function (el) {
                var entry = el._nativeView;
                var palette = el.parentNode._nativeView;
                if (palette.entries) {
                    palette.entries.push(entry);
                    palette.updateOwner();
                }
                else {
                    palette.entries = new observable_array_1.ObservableArray([entry]);
                }
            }
        };
        Vue.directive('tkCartesianPaletteEntry', setEntry);
        Vue.directive('tkPiePaletteEntry', setEntry);
        Vue.directive('tkCartesianAnnotations', {
            inserted: function (el) {
                var annotation = el._nativeView;
                var chart = el.parentNode._nativeView;
                if (chart.annotations) {
                    chart.annotations.push(annotation);
                }
                else {
                    chart.annotations = new observable_array_1.ObservableArray([annotation]);
                }
            }
        });
        var setLabelStyle = {
            inserted: function (el) {
                el.parentNode._nativeView.labelStyle = el._nativeView;
            }
        };
        Vue.directive('tkPieLabelStyle', setLabelStyle);
        Vue.directive('tkDonutLabelStyle', setLabelStyle);
        Vue.directive('tkLineLabelStyle', setLabelStyle);
        Vue.directive('tkBarLabelStyle', setLabelStyle);
        Vue.directive('tkSplineAreaLabelStyle', setLabelStyle);
        Vue.directive('tkBubbleLabelStyle', setLabelStyle);
        Vue.directive('tkScatterBubbleLabelStyle', setLabelStyle);
        Vue.directive('tkCandlestickLabelStyle', setLabelStyle);
        Vue.directive('tkOhlcLabelStyle', setLabelStyle);
        Vue.directive('tkScatterLabelStyle', setLabelStyle);
        Vue.directive('tkRangeBarLabelStyle', setLabelStyle);
        Vue.directive('tkAreaLabelStyle', setLabelStyle);
        Vue.directive('tkSplineLabelStyle', setLabelStyle);
        var setLegend = {
            inserted: function (el) {
                el.parentNode._nativeView.legend = el._nativeView;
            }
        };
        Vue.directive('tkPieLegend', setLegend);
        Vue.directive('tkCartesianLegend', setLegend);
        Vue.directive('tkCartesianTrackball', {
            inserted: function (el) {
                el.parentNode._nativeView.trackball = el._nativeView;
            }
        });
    }
};
exports.default = RadChartPlugin;
