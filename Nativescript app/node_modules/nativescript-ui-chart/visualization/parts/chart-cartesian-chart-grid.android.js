Object.defineProperty(exports, "__esModule", { value: true });
var cartesianChartGridModule = require("./chart-cartesian-chart-grid.common");
var utilsModule = require("tns-core-modules/utils/utils");
var RadCartesianChartGrid = /** @class */ (function (_super) {
    __extends(RadCartesianChartGrid, _super);
    function RadCartesianChartGrid() {
        var _this = _super.call(this) || this;
        _this._android = new com.telerik.widget.chart.visualization.cartesianChart.CartesianChartGrid();
        _this._android.setCanApplyPalette(false);
        return _this;
    }
    RadCartesianChartGrid.prototype.onVerticalLinesVisibleChanged = function (oldValue, newValue) {
        if (newValue === true) {
            if (this.horizontalLinesVisible === true) {
                this._android.setMajorLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.XY);
            }
            else {
                this._android.setMajorLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.X);
            }
        }
        else {
            if (this.horizontalLinesVisible === true) {
                this._android.setMajorLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.Y);
            }
            else {
                this._android.setMajorLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.NONE);
            }
        }
    };
    RadCartesianChartGrid.prototype.onHorizontalLinesVisibleChanged = function (oldValue, newValue) {
        if (newValue === true) {
            if (this.verticalLinesVisible === true) {
                this._android.setMajorLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.XY);
            }
            else {
                this._android.setMajorLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.Y);
            }
        }
        else {
            if (this.verticalLinesVisible === true) {
                this._android.setMajorLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.X);
            }
            else {
                this._android.setMajorLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.NONE);
            }
        }
    };
    RadCartesianChartGrid.prototype.onHorizontalStripLinesVisibleChanged = function (oldValue, newValue) {
        if (newValue === true) {
            if (this.verticalStripLinesVisible === true) {
                this._android.setStripLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.XY);
            }
            else {
                this._android.setStripLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.Y);
            }
        }
        else {
            if (this.verticalStripLinesVisible === true) {
                this._android.setStripLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.X);
            }
            else {
                this._android.setStripLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.NONE);
            }
        }
    };
    RadCartesianChartGrid.prototype.onVerticalStripLinesVisibleChanged = function (oldValue, newValue) {
        if (newValue === true) {
            if (this.horizontalStripLinesVisible === true) {
                this._android.setStripLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.XY);
            }
            else {
                this._android.setStripLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.X);
            }
        }
        else {
            if (this.horizontalStripLinesVisible === true) {
                this._android.setStripLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.Y);
            }
            else {
                this._android.setStripLinesVisibility(com.telerik.widget.chart.visualization.cartesianChart.GridLineVisibility.NONE);
            }
        }
    };
    RadCartesianChartGrid.prototype.onVerticalStrokeColorChanged = function (oldValue, newValue) {
        if (newValue) {
            if (newValue instanceof Array) {
                this._android.setVerticalLineColor(newValue[0].android);
            }
            else {
                this._android.setVerticalLineColor(newValue.android);
            }
            this._android.requestRender();
        }
    };
    RadCartesianChartGrid.prototype.onHorizontalStrokeColorChanged = function (oldValue, newValue) {
        if (newValue) {
            if (newValue instanceof Array) {
                this._android.setLineColor(newValue[0].android);
            }
            else {
                this._android.setLineColor(newValue.android);
            }
            this._android.requestRender();
        }
    };
    RadCartesianChartGrid.prototype.onHorizontalStrokeWidthChanged = function (oldValue, newValue) {
        if (!isNaN(+newValue)) {
            this._android.setLineThickness(newValue * utilsModule.layout.getDisplayDensity());
            this._android.requestRender();
        }
    };
    RadCartesianChartGrid.prototype.onVerticalStrokeWidthChanged = function (oldValue, newValue) {
        if (!isNaN(+newValue)) {
            this._android.setVerticalLineThickness(newValue * utilsModule.layout.getDisplayDensity());
            this._android.requestRender();
        }
    };
    RadCartesianChartGrid.prototype.onVerticalStripLineColorChanged = function (oldValue, newValue) {
        if (!newValue) {
            return;
        }
        this._android.getXStripeBrushes().clear();
        if (newValue instanceof Array) {
            for (var i = 0; i < newValue.length; i++) {
                var stripePaint = new android.graphics.Paint();
                stripePaint.setStyle(android.graphics.Paint.Style.FILL);
                stripePaint.setColor(newValue[i].android);
                this._android.getXStripeBrushes().add(stripePaint);
            }
        }
        else {
            var stripePaint = new android.graphics.Paint();
            stripePaint.setStyle(android.graphics.Paint.Style.FILL);
            stripePaint.setColor(newValue.android);
            this._android.getXStripeBrushes().add(stripePaint);
        }
        this._android.requestRender();
    };
    RadCartesianChartGrid.prototype.onHorizontalStripLineColorChanged = function (oldValue, newValue) {
        if (!newValue) {
            return;
        }
        this._android.getYStripeBrushes().clear();
        if (newValue instanceof Array) {
            for (var i = 0; i < newValue.length; i++) {
                var stripePaint = new android.graphics.Paint();
                stripePaint.setStyle(android.graphics.Paint.Style.FILL);
                stripePaint.setColor(newValue[i].android);
                this._android.getYStripeBrushes().add(stripePaint);
            }
        }
        else {
            var stripePaint = new android.graphics.Paint();
            stripePaint.setStyle(android.graphics.Paint.Style.FILL);
            stripePaint.setColor(newValue.android);
            this._android.getYStripeBrushes().add(stripePaint);
        }
        this._android.requestRender();
    };
    return RadCartesianChartGrid;
}(cartesianChartGridModule.RadCartesianChartGrid));
exports.RadCartesianChartGrid = RadCartesianChartGrid;
