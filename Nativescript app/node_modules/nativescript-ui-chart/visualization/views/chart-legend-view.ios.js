Object.defineProperty(exports, "__esModule", { value: true });
var legendViewCommonModule = require("./chart-legend-view.common");
var commonModule = require("../../ui-chart.common");
var utilsModule = require("tns-core-modules/utils/utils");
var chart_public_enum_1 = require("../../misc/chart-public-enum");
////////////////////////////////////////////////////////////////////////
// RadLegendView
////////////////////////////////////////////////////////////////////////
var RadLegendView = /** @class */ (function (_super) {
    __extends(RadLegendView, _super);
    function RadLegendView() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    RadLegendView.prototype[legendViewCommonModule.RadLegendView.positionProperty.setNative] = function (newValue) {
        this.updateLegendView(this._chart);
    };
    RadLegendView.prototype[legendViewCommonModule.RadLegendView.verticalOffsetProperty.setNative] = function (newValue) {
        this.updateLegendView(this._chart);
    };
    RadLegendView.prototype[legendViewCommonModule.RadLegendView.horizontalOffsetProperty.setNative] = function (newValue) {
        this.updateLegendView(this._chart);
    };
    RadLegendView.prototype[legendViewCommonModule.RadLegendView.offsetOriginProperty.setNative] = function (newValue) {
        this.updateLegendView(this._chart);
    };
    RadLegendView.prototype[legendViewCommonModule.RadLegendView.titleProperty.setNative] = function (newValue) {
        this.updateLegendView(this._chart);
    };
    RadLegendView.prototype[legendViewCommonModule.RadLegendView.titleSizeProperty.setNative] = function (newValue) {
        this.updateLegendView(this._chart);
    };
    RadLegendView.prototype[legendViewCommonModule.RadLegendView.titleColorProperty.setNative] = function (newValue) {
        this.updateLegendView(this._chart);
    };
    RadLegendView.prototype.updateLegendPosition = function (chartView) {
        if (!this.position) {
            return;
        }
        switch (this.position) {
            case chart_public_enum_1.ChartLegendPosition.Left:
                chartView.ios.legend.style.position = 0 /* Left */;
                break;
            case chart_public_enum_1.ChartLegendPosition.Right:
                chartView.ios.legend.style.position = 1 /* Right */;
                break;
            case chart_public_enum_1.ChartLegendPosition.Top:
                chartView.ios.legend.style.position = 2 /* Top */;
                break;
            case chart_public_enum_1.ChartLegendPosition.Bottom:
                chartView.ios.legend.style.position = 3 /* Bottom */;
                break;
            case chart_public_enum_1.ChartLegendPosition.Floating:
                chartView.ios.legend.style.position = 4 /* Floating */;
                break;
        }
        if (this.position === chart_public_enum_1.ChartLegendPosition.Floating) {
            switch (this.offsetOrigin) {
                case chart_public_enum_1.ChartLegendOffsetOrigin.TopLeft:
                    chartView.ios.legend.style.offsetOrigin = 0 /* TopLeft */;
                    break;
                case chart_public_enum_1.ChartLegendOffsetOrigin.TopRight:
                    chartView.ios.legend.style.offsetOrigin = 1 /* TopRight */;
                    break;
                case chart_public_enum_1.ChartLegendOffsetOrigin.BottomLeft:
                    chartView.ios.legend.style.offsetOrigin = 2 /* BottomLeft */;
                    break;
                case chart_public_enum_1.ChartLegendOffsetOrigin.BottomRight:
                    chartView.ios.legend.style.offsetOrigin = 3 /* BottomRight */;
                    break;
                default:
                    chartView.ios.legend.style.offsetOrigin = 0 /* TopLeft */;
            }
            chartView.ios.legend.style.offset = {
                horizontal: (isNaN(this.horizontalOffset)) ? 0 : this.horizontalOffset,
                vertical: (isNaN(this.verticalOffset)) ? 0 : this.verticalOffset
            };
        }
        chartView.ios.setNeedsLayout();
    };
    RadLegendView.prototype.updateLegendView = function (chartView) {
        if (!(chartView)) {
            return;
        }
        if (!(chartView instanceof commonModule.RadChartBase)) {
            return;
        }
        if (!this._chart) {
            this._chart = chartView;
        }
        chartView.nativeView.legend.hidden = false;
        if (this.position) {
            this.updateLegendPosition(chartView);
        }
        if (this.title) {
            chartView.nativeView.legend.titleLabel.text = this.title;
            chartView.nativeView.legend.titleLabel.lineBreakMode = 0 /* ByWordWrapping */;
            chartView.nativeView.legend.showTitle = true;
        }
        if (this.titleColor !== undefined) {
            chartView.nativeView.legend.titleLabel.textColor = this.titleColor.ios;
        }
        if (this.titleSize !== undefined && !isNaN(this.titleSize)) {
            var currentFontName = chartView.nativeView.legend.titleLabel.font.fontName;
            var nativeSize = utilsModule.layout.toDevicePixels(this.titleSize);
            if (currentFontName) {
                chartView.nativeView.legend.titleLabel.font = UIFont.fontWithNameSize(currentFontName, nativeSize);
            }
            else {
                chartView.nativeView.legend.titleLabel.font = UIFont.systemFontOfSize(nativeSize);
            }
        }
        chartView.nativeView.legend.allowSelection = this.enableSelection;
        chartView.updateChart();
    };
    return RadLegendView;
}(legendViewCommonModule.RadLegendView));
exports.RadLegendView = RadLegendView;
