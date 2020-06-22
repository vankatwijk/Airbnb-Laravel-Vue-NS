//
//  OhlcCandlestickBar.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartVisualPoint.h"

@class TKChartSeries;
@class TKChart;
@class TKChartSeriesRender;
@class TKChartFinancialDataPoint;

/**
 @discussion A visual point rendered by TKChart OHLC series.
 */
@interface TKChartOhlcBar : TKChartVisualPoint

/**
 Offest from ohlc high point to open point.
 */
@property (nonatomic) CGFloat openValue;

/**
 Offest from ohlc high point to close close point.
 */
@property (nonatomic) CGFloat closeValue;

/**
 Offest from ohlc cener to low value.
 */
@property (nonatomic) CGFloat lowValue;

/**
 OHLC bar's width.
 */
@property (nonatomic) CGFloat bodyWidth;

/**
 Offest from ohlc cener to high value.
 */
@property (nonatomic) CGFloat highValue;

/**
 Initiates TKChartOhlcBar.
 @param data Financial data point.
 @param index Data point's index.
 @param series Series that contains the point.
 @param render The series render.
 */
- (instancetype)initWithPoint:(TKChartFinancialDataPoint*)data
            atIndex:(NSInteger)index
             series:(TKChartSeries*)series
             render:(TKChartSeriesRender*)render;

- (void)drawInContext:(CGContextRef)ctx;

@end
