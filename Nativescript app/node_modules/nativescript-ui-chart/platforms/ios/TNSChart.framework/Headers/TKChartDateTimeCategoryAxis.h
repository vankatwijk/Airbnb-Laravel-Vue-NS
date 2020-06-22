//
//  TKChartDateTimeCategoryAxis.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKChartAxis.h"

#define TKCalendarUnitDate NSCalendarUnitDay|NSCalendarUnitMonth|NSCalendarUnitYear
#define TKCalendarUnitTime NSCalendarUnitHour|NSCalendarUnitMinute|NSCalendarUnitSecond

/**
 The date time category axis of TKChart.
 
 @see [Working with Date Time Category Axis](chart-axes-datetime-category)
 
 @discussion TKChart uses Categorical axes to plot discontinuous dates as categorical values. The axis is valid only in the context of Cartesian series. It also introduces several important properties:
 
 - dateComponent - Defines the time component that is used when creating date categories.
  
 - baseline - Contains a value, which defines how the series data should be aligned to. (For example: The TKChartBarSeries might render its bars up and down side depending on wether its value is greater or less than the baseline value.)
 
 - offset - Determines a axis value where the axis is crossed with another axis
 
 */
@interface TKChartDateTimeCategoryAxis : TKChartAxis

/**
 The major tick mark frequency.
 */
@property (nonatomic, readonly) NSUInteger majorTickInterval;

/**
 The minor tick mark frequency.
 */
@property (nonatomic, strong) NSNumber *minorTickInterval;

/**
 The value to which the series data is aligned to.
 */
@property (nonatomic, strong) NSDate* baseline;

/**
 The value where the axis will be crossed by the other.
 */
@property (nonatomic, assign) NSDate* offset;

/**
 Defines the time component that is used when creating date categories.
 */
@property (nonatomic) NSCalendarUnit dateComponent;

/**
 The axis categories.
 @return The array of associated categories.
 */
@property (nonatomic, strong, readonly) NSArray* categories;

/**
 Initializes a new axis with minimum and maximum date.
 @param minDate The minimum date that specifies the start of the range.
 @param maxDate The maximum date that specifies the end of the rangee.
 */
- (id)initWithMinimumDate:(NSDate*)minDate andMaximumDate:(NSDate*)maxDate;

/**
 The plot mode of the axis.
 @param plotMode The plot mode.
 */
- (void)setPlotMode:(TKChartAxisPlotMode)plotMode;

/**
 Removes all categories.
 */
- (void)removeAllCategories;

@end
