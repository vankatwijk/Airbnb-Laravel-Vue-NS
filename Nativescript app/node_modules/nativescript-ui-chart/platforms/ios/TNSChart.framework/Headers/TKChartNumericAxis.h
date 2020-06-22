//
//  TKNumericAxis.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAxis.h"

/**
 Defines the label's display mode in TKChartNumericAxis.
 */
typedef NS_ENUM(NSInteger, TKChartNumericAxisLabelDisplayMode) {
    /**
     Labels show ticks values.
     */
    TKChartNumericAxisLabelDisplayModeValue,
    /**
     Labels show ticks values in percentage.
     */
    TKChartNumericAxisLabelDisplayModePercentage,
};

/**
 The numeric axis of TKChart.

 <img src="../docs/images/chart-axes-numeric002.png">
 
 @see [Working with Numeric Axis](chart-axes-numeric)
 
 @discussion TKChart uses Linear axes to plot data containing numerical values. Valid only in the context of Cartesian Area, this axis is created by default when you add Bar, Line, Area and Scatter series.
 
 */
@interface TKChartNumericAxis : TKChartAxis

/**
 The display mode of labels. By default, it is TKChartNumericAxisLabelDisplayModeValue.
 */
@property (nonatomic, assign) TKChartNumericAxisLabelDisplayMode labelDisplayMode;

/**
 The major tick mark frequency.
 */
@property (nonatomic, strong) NSNumber * __nullable majorTickInterval;

/**
 The minor tick mark frequency.
 */
@property (nonatomic, strong) NSNumber * __nullable minorTickInterval;

/**
 The value to which the series data is aligned to.
 */
@property (nonatomic, strong) NSNumber * __nullable baseline;

/**
 The value where the axis will be crossed by the other axis.
 */
@property (nonatomic, strong) NSNumber * __nullable offset;

@end
