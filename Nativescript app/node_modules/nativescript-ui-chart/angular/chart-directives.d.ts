import { ElementRef, OnInit } from '@angular/core';
import * as chartModule from './../';
export declare class SeriesComponentBase {
    protected _nativeSeries: chartModule.ChartSeries;
    readonly nativeSeries: chartModule.ChartSeries;
}
export declare class RadCartesianChartComponent {
    private _elementRef;
    protected _nativeChart: chartModule.RadCartesianChart;
    constructor(_elementRef: ElementRef);
    readonly nativeElement: chartModule.RadCartesianChart;
    readonly cartesianChart: chartModule.RadCartesianChart;
}
export declare class RadPieChartComponent {
    private _elementRef;
    protected _nativeChart: chartModule.RadPieChart;
    constructor(_elementRef: ElementRef);
    readonly nativeElement: chartModule.RadPieChart;
    readonly pieChart: chartModule.RadPieChart;
}
export declare class RadLegendViewDirective {
    constructor();
}
export declare class CategoricalAxisDirective {
    constructor();
}
export declare class LinearAxisDirective {
    constructor();
}
export declare class DateTimeCategoricalAxisDirective {
    constructor();
}
export declare class DateTimeContinuousAxisDirective {
    constructor();
}
export declare class LogarithmicAxisDirective {
    constructor();
}
export declare class LineSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class AreaSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class SplineSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class SplineAreaSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class BarSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class RangeBarSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class BubbleSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class ScatterBubbleSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class ScatterSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class PaletteDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class PieSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class DonutSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class CandlestickSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class OhlcSeriesDirective extends SeriesComponentBase {
    private _elementRef;
    constructor(_elementRef: ElementRef);
}
export declare class RadCartesianChartGridDirective {
    constructor();
}
export declare class ChartGridLineAnnotationDirective {
    constructor();
}
export declare class ChartPlotBandAnnotationDirective {
    constructor();
}
export declare class TrackballDirective {
    constructor();
}
export declare class PointLabelStyleDirective {
    constructor();
}
export declare class TKPieLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: PieSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKDonutLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: DonutSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKLineLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: LineSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKBarLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: BarSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKRangeBarLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RangeBarSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKAreaLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: AreaSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKSplineLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: SplineSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKSplineAreaLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: SplineAreaSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKBubbleLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: BubbleSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKScatterBubbleLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: ScatterBubbleSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCandlestickLabelStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: CandlestickSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKOhlcStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: OhlcSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKScatterStyleDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: ScatterSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCartesianGridDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadCartesianChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCartesianSeriesDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadCartesianChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKPieChartSeriesDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadPieChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCartesianPaletteDirective {
    private owner;
    private _elementRef;
    protected _nativePalette: chartModule.Palette;
    constructor(owner: RadCartesianChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
    readonly nativePalette: chartModule.Palette;
}
export declare class TKPiePaletteDirective {
    private owner;
    private _elementRef;
    protected _nativePalette: chartModule.Palette;
    constructor(owner: RadPieChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
    readonly nativePalette: chartModule.Palette;
}
export declare class TKCartesianPaletteEntryDirective {
    private owner;
    private _elementRef;
    constructor(owner: TKCartesianPaletteDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKPiePaletteEntryDirective {
    private owner;
    private _elementRef;
    constructor(owner: TKPiePaletteDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCartesianHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadCartesianChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCartesianVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadCartesianChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKLineVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: LineSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKLineHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: LineSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKBarVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: BarSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKBarHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: BarSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKRangeBarVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RangeBarSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKRangeBarHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RangeBarSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKAreaVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: AreaSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKAreaHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: AreaSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKSplineVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: SplineSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKSplineHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: SplineSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKSplineAreaVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: SplineAreaSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKSplineAreaHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: SplineAreaSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKBubbleVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: BubbleSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKBubbleHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: BubbleSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKScatterBubbleVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: ScatterBubbleSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKScatterBubbleHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: ScatterBubbleSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCandlestickVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: CandlestickSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCandlestickHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: CandlestickSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKOhlcVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: OhlcSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKOhlcHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: OhlcSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKScatterVerticalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: ScatterSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKScatterHorizontalAxisDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: ScatterSeriesDirective, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKPieLegendDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadPieChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCartesianLegendDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadCartesianChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCartesianTrackballDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadCartesianChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare class TKCartesianAnnotationsDirective implements OnInit {
    private owner;
    private _elementRef;
    constructor(owner: RadCartesianChartComponent, _elementRef: ElementRef);
    ngOnInit(): void;
}
export declare const CHART_DIRECTIVES: (typeof RadCartesianChartComponent | typeof RadPieChartComponent | typeof RadLegendViewDirective | typeof LineSeriesDirective | typeof AreaSeriesDirective | typeof SplineSeriesDirective | typeof SplineAreaSeriesDirective | typeof BarSeriesDirective | typeof RangeBarSeriesDirective | typeof BubbleSeriesDirective | typeof ScatterBubbleSeriesDirective | typeof ScatterSeriesDirective | typeof PaletteDirective | typeof PieSeriesDirective | typeof DonutSeriesDirective | typeof CandlestickSeriesDirective | typeof OhlcSeriesDirective | typeof TKPieLabelStyleDirective | typeof TKDonutLabelStyleDirective | typeof TKLineLabelStyleDirective | typeof TKBarLabelStyleDirective | typeof TKRangeBarLabelStyleDirective | typeof TKAreaLabelStyleDirective | typeof TKSplineLabelStyleDirective | typeof TKSplineAreaLabelStyleDirective | typeof TKBubbleLabelStyleDirective | typeof TKScatterBubbleLabelStyleDirective | typeof TKCandlestickLabelStyleDirective | typeof TKOhlcStyleDirective | typeof TKScatterStyleDirective | typeof TKCartesianGridDirective | typeof TKCartesianSeriesDirective | typeof TKPieChartSeriesDirective | typeof TKCartesianPaletteDirective | typeof TKPiePaletteDirective | typeof TKCartesianPaletteEntryDirective | typeof TKPiePaletteEntryDirective | typeof TKCartesianHorizontalAxisDirective | typeof TKCartesianVerticalAxisDirective | typeof TKLineVerticalAxisDirective | typeof TKLineHorizontalAxisDirective | typeof TKBarVerticalAxisDirective | typeof TKBarHorizontalAxisDirective | typeof TKRangeBarVerticalAxisDirective | typeof TKRangeBarHorizontalAxisDirective | typeof TKAreaVerticalAxisDirective | typeof TKAreaHorizontalAxisDirective | typeof TKSplineVerticalAxisDirective | typeof TKSplineHorizontalAxisDirective | typeof TKSplineAreaVerticalAxisDirective | typeof TKSplineAreaHorizontalAxisDirective | typeof TKBubbleVerticalAxisDirective | typeof TKBubbleHorizontalAxisDirective | typeof TKScatterBubbleVerticalAxisDirective | typeof TKScatterBubbleHorizontalAxisDirective | typeof TKCandlestickVerticalAxisDirective | typeof TKCandlestickHorizontalAxisDirective | typeof TKOhlcVerticalAxisDirective | typeof TKOhlcHorizontalAxisDirective | typeof TKScatterVerticalAxisDirective | typeof TKScatterHorizontalAxisDirective | typeof TKPieLegendDirective | typeof TKCartesianLegendDirective | typeof TKCartesianTrackballDirective | typeof TKCartesianAnnotationsDirective)[];
export declare class NativeScriptUIChartModule {
}
