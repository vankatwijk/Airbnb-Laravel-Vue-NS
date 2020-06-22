//
//  TKChartOhlcRender_TKChartOhlcRender_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartOhlcRender.h"

@class TKChartSeries;
@class TKChartDataPoint;

@interface TKChartOhlcRender ()

@property (nonatomic) CGFloat barWidth;

- (void)drawBars:(NSArray *)bars inContext:(CGContextRef)ctx;

@end
