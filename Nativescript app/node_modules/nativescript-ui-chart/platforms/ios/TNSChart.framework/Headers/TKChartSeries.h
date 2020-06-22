//
//  TKChartSeries.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKChart;
@class TKChartAxis;
@class TKChartStackInfo;
@class TKChartSeriesStyle;
@class TKChartDataView;
@class TKChartSeriesRender;

@protocol TKChartData;

/**
 * @enum TKChartSeriesSelection
 * @discussion Represents an enum that defines the selection mode of the series.
 */
typedef NS_ENUM(NSInteger, TKChartSeriesSelection) {
    /**
     Selection not set. The selection settings from the chart will be used instead.
     */
    TKChartSeriesSelectionNotSet,
    /**
     No selection.
     */
    TKChartSeriesSelectionNone,
    /**
     Selects a whole series.
     */
    TKChartSeriesSelectionSeries,
    /**
     Selects a data point.
     */
    TKChartSeriesSelectionDataPoint,
    /**
     Selects multiple data points.
     */
    TKChartSeriesSelectionDataPointMultiple
};


/**
 * @enum TKChartSeriesSelectionMode
 * @discussion Represents an enum that defines the selection mode of the series.
 */
typedef NS_ENUM(NSInteger, TKChartSeriesSelectionMode) {
    /**
     No selection.
     */
    TKChartSeriesSelectionModeNone,
    /**
     Selects a whole series.
     */
    TKChartSeriesSelectionModeSeries,
    /**
     Selects a data point.
     */
    TKChartSeriesSelectionModeDataPoint,
};

/**
 @enum TKChartSeriesSortMode
 @discussion Representes an enum that defines the sort options for the points.
 */
typedef NS_ENUM(NSInteger, TKChartSeriesSortMode) {
    
    /**
     Series points are presented as they appear in the items collection.
     */
    TKChartSeriesSortModeNone,
    
    /**
     Sorts series items by using the dataXValue property and the corresponding axis.
     */
    TKChartSeriesSortModeXAxis,
    
    /**
     Sorts series items by using the dataYValue property and the corresponding axis.
     */
    TKChartSeriesSortModeYAxis,
};

/**
 Represents a base class for all TKChart series. It is a grouping container for data points of given types. Different kinds of series
 represent different kinds of charts:
 
 - TKChartLineSeries - used to display line series
 - TKChartAreaSeries - used to display area series
 - TKChartPieSeries - used to display pie series
 - TKChartBarSeries - used to display bar series
 - TKChartColumnSeries - used to display column series
 - TKChartScatterSeries - used to display scatter series
 
 @see [Working with TKChartBarSeries](chart-series-bar)
 @see [Working with TKChartLineSeries](chart-series-line)
 @see [Working with TKChartColumnSeries](chart-series-column)
 @see [Working with TKChartPieSeries](chart-series-pie)
 @see [Working with TKChartScatterSeries](chart-series-scatter)
 @see [Working with TKChartAreaSeries](chart-series-area)
 
 */
@interface TKChartSeries : NSObject


/**
 @name Initialization & Data Setup
 */

/**
 Initializes the series with items.
 @param items The array of items that obeys the TKChartData protocol.
 */
- (instancetype __nonnull)initWithItems:(NSArray * __nonnull )items;

/**
 Initializes the series with items.
 @param items The array of items that obeys the TKChartData protocol.
 @param reuseIdentifier The unique identifier used when series are reused.
 */
- (instancetype __nonnull)initWithItems:(NSArray * __nullable )items reuseIdentifier:(NSString * __nonnull)reuseIdentifier;

/**
 Initializes the series with items with specific key value paths.
 @discussion You could use your own classes by specifying their keys as data values
 
 series = [TKChartSeries alloc] initWithItems:array forKeys:@{@"dataXValue":@"id", @"dataYvalue":@"salary"}];
 
 @param items The items that supply data for the series.
 @param keys The items key path.
 */
- (instancetype __nonnull)initWithItems:(NSArray * __nonnull)items forKeys:(NSDictionary * __nonnull)keys;

/**
 Initializes the series with items with specific key value paths.
 @param items The items that supply data for the series.
 @param keys The items key path.
 @param reuseIdentifier The unique identifier used when series are reused.
 */
- (instancetype __nonnull)initWithItems:(NSArray * __nonnull)items forKeys:(NSDictionary * __nonnull)keys reuseIdentifier:(NSString * __nonnull)reuseIdentifier;

/**
 * Initializes the series with items with specific key value paths for dataXValue and dataYValue.
 * @param items The items that supply data for the series.
 * @param xValueKey The key path to the dataXValue property.
 * @param yValueKey The key path to the dataYValue property.
 */
- (instancetype __nonnull)initWithItems:(NSArray * __nonnull)items xValueKey:(NSString* __nonnull)xValueKey yValueKey:(NSString* __nonnull)yValueKey;


/**
 The items collection associated with this series.
 */
@property (nonatomic, strong, readonly) NSArray * __nonnull items;

/**
 The series' visible data points related to series axes pan and zoom values.
 */
@property (nonatomic, strong, readonly) NSArray * __nonnull visiblePointsInternal;

/**
 The series stack information.
 */
@property (nonatomic, strong) TKChartStackInfo * __nullable stackInfo;

/**
 The series unique identifier.
 */
@property (nonatomic, readonly, copy) NSString * __nullable reuseIdentifier;

/**
 Prepares the series for being reused.
 */
- (void)prepareForReuse;

/**
 @name Styling & Appearance
 */

/**
 The series style.
 */
@property (nonatomic, strong, readonly) TKChartSeriesStyle * __nonnull style;

/**
 The series' selection mode of type TKChartSeriesSelectionMode
 
 @discussion The selection modes are defined as follows:
 
 typedef enum {
 TKChartSeriesSelectionModeNone,       // No selection.
 TKChartSeriesSelectionModeSeries,     // Selects a whole series.
 TKChartSeriesSelectionModeDataPoint,  // Selects a data point.
 } TKChartSeriesSelectionMode;
 
 */
@property (nonatomic, assign) TKChartSeriesSelectionMode selectionMode __attribute__((deprecated("Use the selection property instead.")));

/**
 The new selection mode. (Created to match the android selection behavior.)
 */
@property (nonatomic, assign) TKChartSeriesSelection selection;


/*
 Gets or sets a value indicating whether the series is selected.
 */
@property (nonatomic, assign, readonly) BOOL isSelected;

/**
 The series title. Used by the legend.
 */
@property (nonatomic, copy) NSString * __nullable title;


/**
 @name Axis setup
 */

/**
 The associated x-axis.
 */
@property (nonatomic, strong) TKChartAxis * __nullable xAxis;

/**
 The associated y-axis.
 */
@property (nonatomic, strong) TKChartAxis * __nullable yAxis;


/**
 @name Status
 */

/**
 The series tag. You can use it as a way to recognize a series.
 */
@property (nonatomic, assign) NSInteger tag;

/**
 The chart which owns this series.
 */
@property (nonatomic, weak) TKChart * __nullable chart;

/**
 The series index in a chart.
 @discussion Index represents the current order of the chart series. It is automatically assigned and refreshed as series get added and removed.
 */
@property (nonatomic, assign, readonly) NSUInteger index;

/*
 Gets or set a value indicating whether the series is visible.
 */
@property (nonatomic, assign) BOOL hidden;

/*
 Gets or sets a value indicating whether the series is visible in the legend.
 */
@property (nonatomic, assign) BOOL visibleInLegend;

/**
 Returns a list containing the visible points.
 */
@property (nonatomic, strong, readonly) NSArray * __nonnull visiblePoints;

/**
 The series' sort mode of type TKChartSeriesSortMode
 
 @discussion The sort modes are defined as follows:
 
 typedef enum {
 TKChartSeriesSortModeNone,  // Series points are presented as they appear in the items collection.
 TKChartSeriesSortModeXAxis, // Sorts series items by using the dataXValue property and the corresponding axis.
 TKChartSeriesSortModeYAxis, // Sorts series items by using the dataYValue property and the corresponding axis.
 } TKChartSeriesSortMode;
 
 */
@property (nonatomic, assign) TKChartSeriesSortMode sortMode;

/**
 Returns a list containing the visible points according to the specified axis.
 @param axis the axis.
 */
- (NSArray* __nonnull)visiblePointsForAxis:(TKChartAxis* __nonnull)axis;

/**
 Returns an id<TKChartData> data point at the given index.
 @param dataIndex The data point index.
 */
- (id<TKChartData> __nullable)dataPointAtIndex:(NSUInteger)dataIndex;

/**
 Creates a renderer for the partical series.
 @param chart The chart.
 */
- (TKChartSeriesRender * __nonnull)renderForChart:(TKChart * __nonnull)chart;


/**
 Returns trye if the point at the specified index is selected
 @param index The point index.
 */
- (BOOL)pointIsSelected:(NSInteger)index;

@end
