//
//  TKChartFinancialIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartSeries.h"

/**
 @discussion Represents a base class for all TKChart indicators. It is a grouping container for data points of given types.
 */
@interface TKChartFinancialIndicator : TKChartSeries

/**
 The financial series that the indicator is initiated with.
 */
@property (nonatomic, strong) TKChartSeries * __nonnull series;

/**
 If distance between hit and line is bigger, the selection is cleared. By default, it is 25 pixels.
 */
@property (nonatomic) CGFloat marginForHitDetection;

/**
 Initializes the indicator with financial series.
 @param series The financial series that contain financial data points.
 */
- (instancetype __nonnull)initWithSeries:(TKChartSeries * __nonnull)series;

@end
