Object.defineProperty(exports, "__esModule", { value: true });
var view_1 = require("tns-core-modules/ui/core/view");
var color_1 = require("tns-core-modules/color");
var RadCartesianChartGrid = /** @class */ (function (_super) {
    __extends(RadCartesianChartGrid, _super);
    function RadCartesianChartGrid() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    Object.defineProperty(RadCartesianChartGrid.prototype, "owner", {
        get: function () {
            return this._owner;
        },
        set: function (value) {
            this._owner = value;
            this.onOwnerChanged();
        },
        enumerable: true,
        configurable: true
    });
    RadCartesianChartGrid.prototype.applyGridStyle = function () {
    };
    RadCartesianChartGrid.prototype.onOwnerChanged = function () {
    };
    RadCartesianChartGrid.prototype.horizontalStripLinesVisibleChanged = function (oldValue, newValue) {
        this.onHorizontalStripLinesVisibleChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onHorizontalStripLinesVisibleChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.prototype.verticalStripLinesVisibleChanged = function (oldValue, newValue) {
        this.onVerticalStripLinesVisibleChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onVerticalStripLinesVisibleChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.prototype.verticalLinesVisibleChanged = function (oldValue, newValue) {
        this.onVerticalLinesVisibleChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onVerticalLinesVisibleChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.prototype.horizontalLinesVisibleChanged = function (oldValue, newValue) {
        this.onHorizontalLinesVisibleChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onHorizontalLinesVisibleChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.prototype.verticalStrokeColorChanged = function (oldValue, newValue) {
        this.onVerticalStrokeColorChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onVerticalStrokeColorChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.prototype.horizontalStrokeColorChanged = function (oldValue, newValue) {
        this.onHorizontalStrokeColorChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onHorizontalStrokeColorChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.prototype.horizontalStrokeWidthChanged = function (oldValue, newValue) {
        this.onHorizontalStrokeWidthChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onHorizontalStrokeWidthChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.prototype.verticalStrokeWidthChanged = function (oldValue, newValue) {
        this.onVerticalStrokeWidthChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onVerticalStrokeWidthChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.prototype.verticalStripLineColorChanged = function (oldValue, newValue) {
        this.onVerticalStripLineColorChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onVerticalStripLineColorChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.prototype.horizontalStripLineColorChanged = function (oldValue, newValue) {
        this.onHorizontalStripLineColorChanged(oldValue, newValue);
    };
    RadCartesianChartGrid.prototype.onHorizontalStripLineColorChanged = function (oldValue, newValue) {
    };
    RadCartesianChartGrid.horizontalStrokeColorProperty = new view_1.Property({
        name: "horizontalStrokeColor",
        defaultValue: undefined,
        valueConverter: stringColorsConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.horizontalStrokeColorChanged(oldValue, newValue);
        },
    });
    RadCartesianChartGrid.verticalStrokeColorProperty = new view_1.Property({
        name: "verticalStrokeColor",
        defaultValue: undefined,
        valueConverter: stringColorsConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.verticalStrokeColorChanged(oldValue, newValue);
        },
    });
    RadCartesianChartGrid.horizontalStrokeWidthProperty = new view_1.Property({
        name: "horizontalStrokeWidth",
        defaultValue: undefined,
        valueConverter: parseFloat,
        valueChanged: function (target, oldValue, newValue) {
            target.horizontalStrokeWidthChanged(oldValue, newValue);
        },
    });
    RadCartesianChartGrid.verticalStrokeWidthProperty = new view_1.Property({
        name: "verticalStrokeWidth",
        defaultValue: undefined,
        valueConverter: parseFloat,
        valueChanged: function (target, oldValue, newValue) {
            target.verticalStrokeWidthChanged(oldValue, newValue);
        },
    });
    RadCartesianChartGrid.verticalStripLineColorProperty = new view_1.Property({
        name: "verticalStripLineColor",
        defaultValue: undefined,
        valueConverter: stringColorsConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.verticalStripLineColorChanged(oldValue, newValue);
        },
    });
    RadCartesianChartGrid.horizontalStripLineColorProperty = new view_1.Property({
        name: "horizontalStripLineColor",
        defaultValue: undefined,
        valueConverter: stringColorsConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.horizontalStripLineColorChanged(oldValue, newValue);
        },
    });
    RadCartesianChartGrid.verticalLinesVisibleProperty = new view_1.Property({
        name: "verticalLinesVisible",
        defaultValue: undefined,
        valueConverter: view_1.booleanConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.verticalLinesVisibleChanged(oldValue, newValue);
        },
    });
    RadCartesianChartGrid.horizontalLinesVisibleProperty = new view_1.Property({
        name: "horizontalLinesVisible",
        defaultValue: undefined,
        valueConverter: view_1.booleanConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.horizontalLinesVisibleChanged(oldValue, newValue);
        },
    });
    RadCartesianChartGrid.verticalStripLinesVisibleProperty = new view_1.Property({
        name: "verticalStripLinesVisible",
        defaultValue: undefined,
        valueConverter: view_1.booleanConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.verticalStripLinesVisibleChanged(oldValue, newValue);
        },
    });
    RadCartesianChartGrid.horizontalStripLinesVisibleProperty = new view_1.Property({
        name: "horizontalStripLinesVisible",
        defaultValue: undefined,
        valueConverter: view_1.booleanConverter,
        valueChanged: function (target, oldValue, newValue) {
            target.horizontalStripLinesVisibleChanged(oldValue, newValue);
        },
    });
    return RadCartesianChartGrid;
}(view_1.ViewBase));
exports.RadCartesianChartGrid = RadCartesianChartGrid;
function stringColorsConverter(colorsText) {
    if (colorsText.indexOf(',') > -1) {
        var colorsArray = [];
        var colorsList = colorsText.split(',');
        for (var i = 0; i < colorsList.length; i++) {
            var color = new color_1.Color(colorsList[i].trim());
            colorsArray.push(color);
        }
        return colorsArray;
    }
    return new color_1.Color(colorsText);
}
exports.stringColorsConverter = stringColorsConverter;
RadCartesianChartGrid.horizontalStrokeColorProperty.register(RadCartesianChartGrid);
RadCartesianChartGrid.verticalStrokeColorProperty.register(RadCartesianChartGrid);
RadCartesianChartGrid.horizontalStrokeWidthProperty.register(RadCartesianChartGrid);
RadCartesianChartGrid.verticalStrokeWidthProperty.register(RadCartesianChartGrid);
RadCartesianChartGrid.verticalStripLineColorProperty.register(RadCartesianChartGrid);
RadCartesianChartGrid.horizontalStripLineColorProperty.register(RadCartesianChartGrid);
RadCartesianChartGrid.verticalLinesVisibleProperty.register(RadCartesianChartGrid);
RadCartesianChartGrid.horizontalLinesVisibleProperty.register(RadCartesianChartGrid);
RadCartesianChartGrid.verticalStripLinesVisibleProperty.register(RadCartesianChartGrid);
RadCartesianChartGrid.horizontalStripLinesVisibleProperty.register(RadCartesianChartGrid);
