//
//  TKChartRangeDataPoint.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKChartData.h"

/**
 * @discussion Represents a data point used in range bar/column series in TKChart.
 */
@interface TKChartRangeDataPoint : NSObject <TKChartData>

/**
 Creates range data point for TKChartRangeColumnSeries.
 @param xValue Data point's x value.
 @param lowValue Data point's low value.
 @param highValue Data point's high value.
 */
+ (instancetype)dataPointWithX:(id)xValue low:(id)lowValue high:(id)highValue;

/**
 Creates range data point for TKChartRangeBarSeries.
 @param yValue Data point's y value.
 @param lowValue Data point's low value.
 @param highValue Data point's high value.
 */
+ (instancetype)dataPointWithY:(id)yValue low:(id)lowValue high:(id)highValue;

/**
 Data point's x value.
 */
@property (nonatomic, strong) id dataXValue;

/**
 Data point's y value.
 */
@property (nonatomic, strong) id dataYValue;

/**
 Data point's low value.
 */
@property (nonatomic, strong) id low;

/**
 Data point's high value.
 */
@property (nonatomic, strong) id high;

/**
 Creates range data point for TKChartRangeColumnSeries.
 @param xValue Data point's x value.
 @param lowValue Data point's low value.
 @param highValue Data point's high value.
 */
- (instancetype)initWithX:(id)xValue low:(id)lowValue high:(id)highValue;


/**
 Creates range data point for TKChartRangeBarSeries.
 @param yValue Data point's y value.
 @param lowValue Data point's low value.
 @param highValue Data point's high value.
 */
- (instancetype)initWithY:(id)yValue low:(id)lowValue high:(id)highValue;

@end
