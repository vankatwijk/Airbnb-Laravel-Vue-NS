//
//  TKChartDonutSeries.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartPieSeries.h"

/**
 Represents a TKChart donut series.
*/
@interface TKChartDonutSeries : TKChartPieSeries

/**
 The inner radius of the donut series. A non-zero radius produces a donut chart. It is measured in logical coordinates between 0 and 1.
 */
@property (nonatomic, assign) CGFloat innerRadius;

@end
