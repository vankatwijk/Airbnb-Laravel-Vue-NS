//
//  TKChartLineRender_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartLineRender.h"
#import "TKChartPaletteItem.h"
#import "TKChartLineSeries.h"
#import "TKGeometry.h"

@interface TKChartLineRender ()

- (void)drawLineSeriesPath:(CGPathRef)path
                  baseline:(TKLineSegment)baseline
                    series:(TKChartSeries*)series
               seriesIndex:(NSInteger)seriesIndex
                   pallete:(TKChartPaletteItem*)pallete
                 inContext:(CGContextRef)context;

- (CGFloat)baselineOfSeries:(TKChartSeries*)series;

- (void)drawSeriesInContext:(CGContextRef)context;

@end
