//
//  TKDateTimeAxis.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartCategoryAxis.h"

/**
 @enum TKDateTimeIntervalUnit determines the label frequency inside TKDateTimeAxis.
 */
typedef NS_ENUM(NSInteger, TKChartDateTimeAxisIntervalUnit) {
    /**
     The majorTickInterval is measured in seconds.
     */
    TKChartDateTimeAxisIntervalUnitSeconds,
    /**
     The majorTickInterval is measured in minutes.
     */
    TKChartDateTimeAxisIntervalUnitMinutes,
    /**
     The majorTickInterval is measured in hours.
     */
    TKChartDateTimeAxisIntervalUnitHours,
    /**
     The majorTickInterval is measured in days.
     */
    TKChartDateTimeAxisIntervalUnitDays,
    /**
     The majorTickInterval is measured in weeks.
     */
    TKChartDateTimeAxisIntervalUnitWeeks,
    /**
     The majorTickInterval is measured in months.
     */
    TKChartDateTimeAxisIntervalUnitMonths,
    /**
     The majorTickInterval is measured in years.
     */
    TKChartDateTimeAxisIntervalUnitYears,
    /**
     The majorTickInterval is measured in ticks.
     */
    TKChartDateTimeAxisIntervalUnitCustom
   
};

/**
 The date-time axis of TKChart.

 <img src="../docs/images/chart-axes-datetime002.png">
 
 @see [Working with Date/Time Axis](chart-axes-datetime)
 
 @discussion The TKChartDateTimeAxis categorical axis is an axis with NSDate values sorted chronologically. It also allows definition of categories based on specific date time components – year, month, day etc. For example, if data values fall in the range of one year, the points can be plotted in categories for each month. If data values fall in the range of one month, the values can be categorized by days. It also introduces several important properties:
 
 - majorTickInterval - Defines an interval among major axis ticks
 
 - baseline - Contains a value, which defines how the series data should be aligned to. (For example: The TKChartBarSeries might render its bars up and down side depending on wether its value is greater or less than the baseline value.)
 
 - offset - Determines a axis value where the axis is crossed with another axis
 */
@interface TKChartDateTimeAxis : TKChartAxis

/**
 The major tick mark frequency.
 The interpretation of the value for this property is determined by the majorTickIntervalUnit property.
 */
@property (nonatomic) NSTimeInterval majorTickInterval;

/**
 The major tick mark frequency using predefined values for a period.

 @discussion The date/time interval units are defined as follows:

    typedef enum {
        TKChartDateTimeAxisIntervalUnitSeconds,     // The majorTickInterval is measured in seconds.
        TKChartDateTimeAxisIntervalUnitMinutes,     // The majorTickInterval is measured in minutes.
        TKChartDateTimeAxisIntervalUnitHours,       // The majorTickInterval is measured in hours.
        TKChartDateTimeAxisIntervalUnitDays,        // The majorTickInterval is measured in days.
        TKChartDateTimeAxisIntervalUnitWeeks,       // The majorTickInterval is measured in weeks.
        TKChartDateTimeAxisIntervalUnitMonths,      // The majorTickInterval is measured in months.
        TKChartDateTimeAxisIntervalUnitYears,       // The majorTickInterval is measured in years.
        TKChartDateTimeAxisIntervalUnitCustom       // The majorTickInterval is measured in ticks.
    } TKChartDateTimeAxisIntervalUnit;

 */
@property (nonatomic) TKChartDateTimeAxisIntervalUnit majorTickIntervalUnit;

@property (nonatomic) TKChartDateTimeAxisIntervalUnit minorTickIntervalUnit;

/**
 The value to which the series data is aligned to.
 */
@property (nonatomic, strong) NSDate * __nullable baseline;

/**
 The value where the axis will be crossed by the other.
 */
@property (nonatomic, strong) NSDate * __nullable offset;

/**
 The plot mode of the axis.
 @param plotMode The plot mode.
 */
- (void)setPlotMode:(TKChartAxisPlotMode)plotMode;

/**
 Sets the tick count for this axis.
 @param tickCount The number of ticks to be displayed
 */
- (void)setMajorTickCount:(NSInteger)tickCount;

/**
 Initializes a new axis with minimum and maximum date.
 @param minDate The minimum date that specifies the start of the range.
 @param maxDate The maximum date that specifies the end of the rangee.
 */
- (instancetype __nonnull)initWithMinimumDate:(NSDate* __nonnull)minDate andMaximumDate:(NSDate* __nonnull)maxDate;

@end
