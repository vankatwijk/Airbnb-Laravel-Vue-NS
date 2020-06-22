Object.defineProperty(exports, "__esModule", { value: true });
var chart_public_enum_1 = require("./chart-public-enum");
function convertToAndroidPaletteMode(nsMode) {
    if (!nsMode) {
        return null;
    }
    if (chart_public_enum_1.ChartSeriesPaletteMode.Item === nsMode) {
        return com.telerik.widget.palettes.ChartSeriesPaletteMode.ITEM;
    }
    else if (chart_public_enum_1.ChartSeriesPaletteMode.Series === nsMode) {
        return com.telerik.widget.palettes.ChartSeriesPaletteMode.SERIES;
    }
    return null;
}
exports.convertToAndroidPaletteMode = convertToAndroidPaletteMode;
function convertToIOSPaletteMode(nsMode) {
    if (!nsMode) {
        return null;
    }
    if (chart_public_enum_1.ChartSeriesPaletteMode.Item === nsMode) {
        return 1 /* UseItemIndex */;
    }
    else if (chart_public_enum_1.ChartSeriesPaletteMode.Series === nsMode) {
        return 0 /* UseSeriesIndex */;
    }
    return null;
}
exports.convertToIOSPaletteMode = convertToIOSPaletteMode;
