//
//  TKAxis.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKRange;
@class TKChartSeries;
@class TKChartAxisStyle;
@class TKStyleSheet;
@class TKChartAxisRender;
@class TKChartRender;
@class TKChart;
@protocol TKChartData;


/**
 @enum TKChartAxisPosition
 @discussion Defines the position of the axis relative to the chart.
 */
typedef NS_ENUM(NSInteger, TKChartAxisPosition) {
    /**
     The axis should be positioned at the left side of the chart.
     */
    TKChartAxisPositionLeft,
    /**
     The axis shuld be positioned at the right side of the chart.
     */
    TKChartAxisPositionRight,
    /**
     The axis should be positioned at the top side of the chart.
     */
    TKChartAxisPositionTop,
    /**
     The axis should be positioned at the bottom side of the chart.
     */
    TKChartAxisPositionBottom,
};

/**
 @enum TKChartAxisPlotMode
 @discussion Defines how data points are plotted by an axis.
 */
typedef NS_ENUM(NSInteger, TKChartAxisPlotMode)
{
    /**
     Points are plotted over each tick.
     */
    TKChartAxisPlotModeOnTicks,
    /**
     Points are plotted in the middle of the range, defined between each two ticks.
     */
    TKChartAxisPlotModeBetweenTicks
};

/**
 Represents a single axis of the chart.
 
 <img src="../docs/images/chart-axes-types003.png">
 
 @see [Working with Axis](Chart-Axes-Axes)
 
 @discussion TKChart renders its points in a coordinate system defined by its axes. To do this axes specify the minimum and maximum values that can be presented on the plot area. There are a few different types of axes that can be used with TKChart. They include: numeric, date/time and categorical. You can assign each axis to different series and you can show multiple axes in chart. Axes contain various properties to control their position, style and behavior. All chart axes subclass from TKChartAxis.
 
 - Use TKChartNumericAxis to present numeric values.
 - Use TKChartDateTimeAxis to present date/time values.
 - Use TKChartCategoryAxis to present categorical values.
 
 */
@interface TKChartAxis : NSObject

/**
 @name Appearance
 */

/**
 Defines the axis style.
 */
@property (nonatomic, strong) TKChartAxisStyle * __nonnull style;

/**
 Determines the position of the axis.
 
 @discussion The axis positions are defined as follows:
 
     typedef enum TKChartAxisPosition {
     TKChartAxisPositionLeft,    // The axis should be positioned at the left side of the chart.
     TKChartAxisPositionRight,   // The axis shuld be positioned at the right side of the chart.
     TKChartAxisPositionTop,     // The axis should be positioned at the top side of the chart.
     TKChartAxisPositionBottom,  // The axis should be positioned at the bottom side of the chart.
     } TKChartAxisPosition;
 
 */
@property (nonatomic, assign) TKChartAxisPosition position;

/**
 This dictionary represents key-value pairs of the wished positions to be rendered ticks and labels
 and the respective color of the axis from the previous tick to the given tick.
 */
@property (nonatomic, strong) NSDictionary*  __nullable customLabels;

/**
 Returns YES for vertical axis and NO for horizontal ones.
 */
@property (nonatomic, readonly) BOOL isVertical;

/**
 Defines how data points are plotted by an axis.
 
 @discussion The axis plot modes are defined as follows:
 
     typedef enum TKChartAxisPlotMode {
     TKChartAxisPlotModeOnTicks,        // Points are plotted in the middle of the range, defined between each two ticks.
     TKChartAxisPlotModeBetweenTicks,   // Points are plotted over each tick.
     } TKChartAxisPlotMode;
 
 */
@property (nonatomic, assign, readonly) TKChartAxisPlotMode plotMode;

/**
 The axis title (in plain text).
 */
@property (nonatomic, copy) NSString * __nullable title;

/**
 The axis attributed title (if needed).
 */
@property (nonatomic, strong) NSAttributedString * __nullable attributedTitle;

/**
 Defines a text format. If the label formatter is not nil, it preserves this property.
 */
@property (nonatomic, copy) NSString*  __nullable labelFormat;

/**
 Defines a text formatter that preserves the labelFormat property.
 */
@property (nonatomic, strong) NSFormatter * __nullable labelFormatter;

/**
 Determines whether the axis is hidden or visible in chart.
 */
@property (nonatomic, assign) BOOL hidden;

/**
 @name Ranges
 */

/**
 The axis range.
 */
@property (nonatomic, strong) TKRange * __nonnull range;

/**
 The currently visible range.
 */
@property (nonatomic, strong, readonly) TKRange * __nonnull visibleRange;

/**
 * Returns the tick count for this axis.
 */
@property (nonatomic, readonly) NSUInteger majorTickCount;

/**
 @name Pan & Zoom
 */

/**
 Allows panning and zooming of series by this axis.
 */
@property (nonatomic) BOOL allowZoom;

/**
 The zoom level of the axis.
 */
@property (nonatomic) double zoom;

/**
 If set, defines the allowed zoom range.
 */
@property (nonatomic) TKRange * __nonnull zoomRange;

/**
 Allows panning and zooming of series by this axis.
 */
@property (nonatomic) BOOL allowPan;

/**
 The pan level of the axis.
 */
@property (nonatomic) double pan;

/**
 A normalized pan value in range between [0;1] 
 */
@property (nonatomic) double normalizedPan;

/**
 @name Initialization
 */

/**
 Initializes the axis with range.
 @param range The range that represents the span of the axis.
 */
- (instancetype __nonnull)initWithRange:(TKRange* __nonnull)range;

/**
 Initializes the axis with its minimum and maximum range.
 @param minimum The minimum value that specifies the start of the range.
 @param maximum The maximum value that specifies the end of the range.
 */
- (instancetype __nonnull)initWithMinimum:(id __nonnull)minimum andMaximum:(id __nonnull)maximum;

/**
 Initializes the axis with its minimum, maximum and position.
 @param minimum The minimum value that specifies the start of the range.
 @param maximum The maximum value that specifies the end of the range.
 @param position The position value that specifies where to place the axis (left, right, top or bottom side)
 */
- (instancetype __nonnull)initWithMinimum:(id __nonnull)minimum andMaximum:(id __nonnull)maximum position:(TKChartAxisPosition)position;

/**
 Returns the numeric representation of a value specific for this axis.
 @param value The value which is converted to.
 @return The numeric representation of the value.
 */
- (double)numericValue:(id __nonnull)value;

/**
 Returns the tick's value at a specific index.
 @param index The index.
 @return A value representing the value at this index.
 */
- (id __nullable)tickValue:(NSInteger)index;

/**
 Formats a value to string
 @param value The value
 */
- (NSString* __nullable)formatValue:(id __nonnull)value;

/**
 Pans the axis to specific data point.
 @param dataPoint the data point the axis will be panned to.
 */
- (void)panToDataPoint:(id<TKChartData> __nonnull)dataPoint;

/**
 Creates a renderer for the partical axis.
 @param chart The chart.
 */
- (TKChartAxisRender * __nonnull)renderForChart:(TKChart * __nonnull)chart;

@end
