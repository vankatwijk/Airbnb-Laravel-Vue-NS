//
//  TKChart.h
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//
#import "TNSCore/TKView.h"

@class TKChart;
@class TKChartAxis;
@class TKChartGridStyle;
@class TKChartLegendView;
@class TKChartLegendItem;
@class TKChartPaletteItem;
@class TKChartSelectionInfo;
@class TKChartSeries;
@class TKChartSeriesRenderState;
@class TKChartStyle;
@class TKChartTitleView;
@class TKMutableArray;
@class TKShape;
@class TKTheme;
@class TKChartVisualPoint;
@class TKChartAnnotation;
@class TKChartTrackball;
@class TKChartPointLabelRender;
@class TKChartPointLabel;
@class TKChartSeriesRender;
@class TKChartPlotView;

@protocol TKChartData;
@protocol TKChartDataSource;
@protocol TKChartDelegate;

/**
 @enum TKChartSelectionMode
 @discussion Represents an enum that defines whether a single or multiple items (series or points) can be selected in chart.
 */
typedef NS_ENUM(NSInteger, TKChartSelectionMode)
{
    /**
     Selection is disabled.
     */
    TKChartSelectionModeNone,
    /**
     Only a single item (series or point) can be selected at a time.
     */
    TKChartSelectionModeSingle,
    
    /**
     Multiple items can be selected.
     */
    TKChartSelectionModeMultiple
};

/**
 @enum TKChartZoomMode
 @discussion Represents an enum that defines whether the zoom should be symmetric to the middle point of the pinch or not.
 */
typedef NS_ENUM(NSInteger, TKChartZoomMode)
{
    /**
     The zoom is symmetric to the middle point of the pinch.
     */
    TKChartZoomModeSymmetric,
    
    /**
     The zoom is single sided.
     */
    TKChartZoomModeSingleSide
};

/**
 TKChart is a versatile charting component that offers great performance, drawing capabilities and intuitive object model. Thanks to the public API you can set up complex charts with stunning animations and appearance easily through code. TKChart supports various series types: bar, column, line, spline, area, pie, donut and scatter. These series can also be stacked where appropriate. Among its supported features are pan/zoom funcionality, multiple axes and animations that use CoreAnimations and UIKit dynamics.
  <img src="../docs/images/chart-overview001.png">
 
 @see [TKChart Overview](chart-overview)
 @see [Managing the data source](chart-populatingwithdata)
 @see [Custom Animations](chart-animations-custom)
 @see [Custom Animations with UIKit Dynamics](chart-animations-customuikitdynamics)
 @see [TKChart selection](chart-selection)
 @see [Customizing TKChart data appearance](chart-customdrawing)
 @see [Customization of data point appereance](chart-series-pointcustomization)
 */
@interface TKChart : TKView

/**
 @name Accessing Views and Styling
 */

/**
 Returns TKChart legend view.
 */
@property (nonatomic, strong, readonly, nonnull) TKChartLegendView* legend;

/**
 Returns TKChart title view.
 */
@property (nonatomic, strong, readonly, nonnull) TKChartTitleView* title;

/**
 Returns TKChart plot view.
 */
@property (nonatomic, strong, readonly, nonnull) TKChartPlotView* plotView;

/**
 Returns TKChart style.
 */
@property (nonatomic, strong, readonly, nonnull) TKChartGridStyle* gridStyle;

/**
 TKChart content insets relative to its view size.
*/
@property (nonatomic, assign) UIEdgeInsets insets;

/**
 The chart's plot view insets relative to size.
 */
@property (nonatomic) UIEdgeInsets plotViewInsets;

/**
 @return TKChart theme. The theme is used to style the chart when no palletes and custom styles are applied. The defaulf value is 
 */
@property (nonatomic, strong, nonnull) TKTheme* theme;

/**
 Determines whether a Double-tap gesture will be handled by the chart to reset the current Zoom and Pan values.
 */
@property (nonatomic, assign) BOOL handleDoubleTap;

/**
 Determines whether an inertia should be added when panning the chart.
 */
@property (nonatomic) BOOL allowPanDeceleration;

/**
 Determines the zoom mode of the chart.
 */
@property (nonatomic) TKChartZoomMode zoomMode;


/**
 @name Selection
 */

/**
 Returns a value indicating whether the user can select single or multiple series/data points.
 */

@property (nonatomic, assign) TKChartSelectionMode selectionMode __attribute__((deprecated("Use dataPointSelectionMode and seriesSelectionMode instead.")));

/**
 Returns a value that determines the data point selection mode.
 */
@property (nonatomic, assign) TKChartSelectionMode dataPointSelectionMode;

/**
 Returns a value that determines the series selection mode.
 */
@property (nonatomic, assign) TKChartSelectionMode seriesSelectionMode;

/**
 Returns the selected series.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray <__kindof TKChartSeries*>* selectedSeries;

/**
 Returns an array containing instances of TKChartSelectionInfo containing the selected points in the chart;
 */
@property (nonatomic, strong, readonly, nonnull) NSArray <__kindof TKChartSelectionInfo*>* selectedPoints;

/**
 Selects a series or data point depending on the series selectionMode property.
 @param info The selection information object.
 */
- (void)select:(TKChartSelectionInfo * __nullable)info;

/**
 Deselect a series or data point depending on the series selectionMode property.
 @param info The selection information object.
 */
- (void)deselect:(TKChartSelectionInfo * __nonnull)info;


/**
 @name Configuring TKChart Animations
 */

/**
 Determines whether TKChart allows animations.
 */
@property (nonatomic) BOOL allowAnimations;

/**
 Determines the animation duration. This value is used by default animations in TKChart.
 */
@property (nonatomic) CFTimeInterval animationDuration;

/**
 Causes the chart to animate its content. The allowAnimations property should be set to true before calling this method.
 You can customise TKChart animations by handling the chart:animationForSeries:withState:inRect: method of TKChartDelegate.
 */
- (void)animate;


/**
 @name Managing the Delegate and the Data Source
 */

/**
 A delegate for styling the chart and receiving notifications.
 */
@property (nonatomic, weak, nullable) id<TKChartDelegate> delegate;

/**
 Sets data-source delegate.
 @return The data-source delegate.
 */
@property (nonatomic, assign, nullable) id<TKChartDataSource> dataSource;


/**
 @name Configuring Axes
 */

/**
 TKChart main x-axis.
 */
@property (nonatomic, strong, nullable) TKChartAxis *xAxis;

/**
 TKChart y-Axis.
 */
@property (nonatomic, strong, nullable) TKChartAxis *yAxis;

/**
 An array that contains the axes of the chart.
 @return All axes of the chart.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray *axes;

/**
 Adds an axis to the chart.
 @param axis The axis that should be added to the chart.
 */
- (void)addAxis:(TKChartAxis* __nonnull)axis;

/**
 Removes an axis from the chart.
 @param axis The axis that should be removed from the chart.
 */
- (BOOL)removeAxis:(TKChartAxis* __nonnull)axis;


/**
 @name Configuring Series
 */

/**
 A read-only array of the TKChartSeries objecs displayed on the chart.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray <__kindof TKChartSeries* >* series;

/** 
 Adds a series to the chart.
 @param series The series that should be added to the chart.
 */
- (void)addSeries:(TKChartSeries * __nonnull)series;

/**
 Returns a reusable chart-view series object located by its identifier.
 @param identifier The string identifying the cell object to be reused. This parameter must not be nil.
 */
- (id __nullable)dequeueReusableSeriesWithIdentifier:(NSString * __nonnull)identifier;

/** 
 Removes the specified series from the chart.
 @param series The series that should be removed from the chart.
 */
- (void)removeSeries:(TKChartSeries* __nonnull)series;

/**
 Returns the chart's crosshair
 */
@property (nonatomic, strong, readonly, nonnull) TKChartTrackball *trackball;

/**
 Determines whether TKChart allows the trackball behavior.
 */
@property (nonatomic, assign) BOOL allowTrackball;


/**
 @name Configuring Annotations
 */

/**
 Returns the chart annotations
 */
@property (nonatomic, strong, readonly, nonnull) NSArray* annotations;

/**
 Adds annotation to the chart
 @param annotation The annotation that will be added.
 */
- (void)addAnnotation:(TKChartAnnotation * __nonnull)annotation;

/**
 Removes annotation from the chart
 @param annotation The annotation that will be removed.
 */
- (void)removeAnnotation:(TKChartAnnotation* __nonnull)annotation;

/**
 Removes all annotations from the chart
 */
- (void)removeAllAnnotations;

/**
 Forces annotations to update
 */
- (void)updateAnnotations;


/**
 @name Data manipulation
 */

/**
 Reloads the data-source and rebuilds the UI. Call this method to reload all the data that is used to construct the chart.
 */
- (void)reloadData;

/**
 Updates the UI only.
 */
- (void)update;

/**
 Updates the current series axis.
 */
- (void)replaceSeriesAxis:(TKChartSeries * __nonnull)series old:(TKChartAxis * __nullable)oldAxis new:(TKChartAxis * __nullable)newAxis vertical:(BOOL)isVertical;

/**
 Removes all series & axes from the chart.
 */
- (void)removeAllData;

/**
 Begins a series of method calls that insert, delete, or select dataPoints and series of the receiver.
 */
- (void)beginUpdates;

/**
 Concludes a series of method calls that insert, delete, select, or reload dataPoints and series of the receiver.
 */
- (void)endUpdates;


/**
 Returns the data point located at specified coordinates.
 @param point The point to be used for hit testing.
 */
- (TKChartSelectionInfo * __nullable)hitTestForPoint:(CGPoint)point;

/**
 Returns an array containing the visual point elements for a given series.
 Visual points can be modified only when animations are allowed.
 The animate method should be called to reflect all changes made in visual points.
 @param series The series that contains the requested points.
 */
- (NSArray <__kindof TKChartVisualPoint*>* __nullable)visualPointsForSeries:(TKChartSeries* __nonnull)series;

/**
 Returns a visual point element at a specific point index and series.
 Visual points can be modified only when animations are allowed.
 The animate method should be called to reflect all changes made in visual points.
 @param series The series that contains the requested point.
 @param dataPointIndex The point index of the requested point.
 */
- (TKChartVisualPoint* __nullable)visualPointForSeries:(TKChartSeries* __nonnull)series dataPointIndex:(NSInteger)dataPointIndex;

/**
 Returns a palette item that should be used to present specific series.
 @param series The series
 @param index The series index
 */
- (TKChartPaletteItem * __nullable)paletteItemForSeries:(TKChartSeries * __nonnull)series atIndex:(NSUInteger)index;

/**
 Returns a palette item that should be used to present specific point
 @param index The data point index
 @param series The series that contains the specified point.
 */
- (TKChartPaletteItem * __nullable)paletteItemForPoint:(NSUInteger)index inSeries:(TKChartSeries * __nonnull)series;

@end // TKChart



/**
 @discussion The TKChartDataSource protocol is adopted by an object that mediates the application's data model for a TKChart object.
 The data source provides the chart-view object with the information it needs to construct and modify a chart view.
 */
@protocol TKChartDataSource <NSObject>

@required
/**
 Asks the data-source to return the number of series in the chart.
 @param chart An object representing the chart requesting this information.
 */
- (NSUInteger)numberOfSeriesForChart:(TKChart * __nonnull)chart;

/**
 Asks the data-source to return a series for the chart at a particular index.
 @param index The index of the series.
 @param chart The TKChart instance requesting this information.
 */
- (TKChartSeries * __nonnull)seriesForChart:(TKChart * __nonnull)chart atIndex:(NSUInteger)index;

@optional

/**
 Asks the data-source to return the number of data point in series for the chart.
 @param seriesIndex The index of series.
 @param chart The object representing the chart requesting this information.
 */
- (NSUInteger)chart:(TKChart * __nonnull)chart numberOfDataPointsForSeriesAtIndex:(NSUInteger)seriesIndex;

/**
 Asks the data-source to return a data point from a specified series.
 @param seriesIndex The index of the series.
 @param dataIndex The index of data point.
 @param chart The TKChart instance requesting this information.
 */
- (id<TKChartData> __nonnull)chart:(TKChart * __nonnull)chart dataPointAtIndex:(NSUInteger)dataIndex forSeriesAtIndex:(NSUInteger)seriesIndex;

/**
 Asks the data-source to return an array of data points from a specified series.
 @param seriesIndex The series index.
 @param chart The TKChart instance requesting this information.
 */
- (NSArray * __nullable)chart:(TKChart * __nonnull)chart dataPointsForSeriesAtIndex:(NSUInteger)seriesIndex;

@end // TKChartDataSource

/**
 @discussion The methods declared by the TKChartDelegate protocol allow the adopting delegate to respond to messages from the TKChart class and thus respond to, and in some affect, operations such as panning, zooming and data animations.
 */
@protocol TKChartDelegate <NSObject>

@optional


/**
 @name Changing TKChart appearance
 */

/**
 Returns an instance of TKChartPaletteItem based on the specified series and index.
 @param chart The TKChart instance requesting this information.
 @param series The series of the palette item that is being requested.
 @param index The item index for the series.
 @return The instance of TKChartPaletteItem that contains style settings for specific series.
 */
- (TKChartPaletteItem * __nullable)chart:(TKChart * __nonnull)chart paletteItemForSeries:(TKChartSeries * __nonnull)series atIndex:(NSInteger)index;

/**
 Returns an instance of TKChartPaletteItem used to draw a single point in chart based on the point index and the series.
 @param chart  The TKChart instance requesting this information.
 @param index  The point index within the specified series.
 @param series The series where the point is contained.
 @return The instance of TKCahrtPaletteItem that contains style settings for specific point.
 */
- (TKChartPaletteItem * __nullable)chart:(TKChart * __nonnull)chart paletteItemForPoint:(NSUInteger)index inSeries:(TKChartSeries * __nonnull)series;

/**
 Returns a shape for a specified series and index.
 @param chart The TKChart instance requesting the shape.
 @param series The series of the palette item that is being requested.
 @param index The index of the series item.
 @return An instance of TKChartPaletteItem that contains style settings for a specific series.
 */
- (TKShape * __nullable)chart:(TKChart * __nonnull)chart shapeForSeries:(TKChartSeries * __nonnull)series atIndex:(NSUInteger)index;

/**
 Creates an animation for particular series.
 @param chart The TKChart instance requesting this information.
 @param series The series to which the animation will be applied.
 @param state The series' visual state.
 @param rect The viewport of the plot area.
 */
- (CAAnimation* __nullable)chart:(TKChart* __nonnull)chart animationForSeries:(TKChartSeries* __nonnull)series withState:(TKChartSeriesRenderState* __nonnull)state inRect:(CGRect)rect;

/**
 @name Handling TKChart notifications
 */

/**
 Called on selecting series.
 @param chart The TKChart for which the selection has occurred.
 @param series The series that is selected.
 */
- (void)chart:(TKChart *__nonnull)chart didSelectSeries:(TKChartSeries *__nonnull)series;

/**
 Called when a series is deselected.
 @param chart The TKChart for which the selection change has occurred.
 @param series The series that is deselected.
 */
- (void)chart:(TKChart *__nonnull)chart didDeselectSeries:(TKChartSeries *__nonnull)series;

/**
 Called on selecting a point.
 @param chart The TKChart for which the selection change has occurred.
 @param point The data point that is selected.
 @param series The series that contains the selected point.
 @param index The index of the data point within the series.
*/
- (void)chart:(TKChart *__nonnull)chart didSelectPoint:(id<TKChartData> __nonnull)point inSeries:(TKChartSeries *__nonnull)series atIndex:(NSInteger)index;

/**
 Called when a point is deselected.
 @param chart The TKChart for which the selection change has occurred.
 @param point The data point that is deselected.
 @param series The series that contains the selected point.
 @param index The index of the data point within the series.
 */
- (void)chart:(TKChart * __nonnull)chart didDeselectPoint:(id<TKChartData> __nonnull)point inSeries:(TKChartSeries * __nonnull)series atIndex:(NSInteger)index;

/**
 Tells the delegate when the chart view is about to start zooming the content.
 @param chart The TKChart instance displaying the content.
 */
- (void)chartWillZoom:(TKChart* __nonnull)chart;

/**
 Tells the delegate that the TKChart zoom factor changed.
 @param chart The TKChart instance displaying the content.
 */
- (void)chartDidZoom:(TKChart* __nonnull)chart;

/**
 *
 Tells the delegate when the TKChart is about to start panning the content.
 @param chart The TKChart instance displaying the content.
 */
- (void)chartWillPan:(TKChart* __nonnull)chart;

/**
 Tells the delegate that the TKChart pan factor changed.
 @param chart The TKChart instance displaying the content.
 */
- (void)chartDidPan:(TKChart* __nonnull)chart;

/**
 Called on trackball moved
 @param chart The TKChart for which the crosshair moved
 @param selection The array of TKChartSelectionInfo
 */
- (void)chart:(TKChart * __nonnull)chart trackballDidTrackSelection:(NSArray* __nonnull)selection;

/**
 Called when the trackball hides.
 @param chart The TKChart instance displaying the content. 
 @param selection The array of TKChartSelectionInfo
 */
- (void)chart:(TKChart* __nonnull)chart trackballDidHideSelection:(NSArray * __nonnull)selection;

/**
 Called when the trackball is about to be displayed to request a string representation for the corresponding data point.
 @param chart The TKChart instance displaying the content.
 @param point The TKChartData implementation for which to display the content.
 @param series The TKChartSeries instance displaying the content.
 */
- (NSString * __nullable)chart:(TKChart* __nonnull)chart trackballLabelForDatapoint: (id<TKChartData> __nonnull)point inSeries: (TKChartSeries * __nonnull)series;

/**
 Returns TKChartPointLabel for specific data point.
 @param chart The TKChart instance requesting the label.
 @param dataPoint The data point for which a label will be returned.
 @param propertyName The property name.
 @param series The series of the data point.
 @param dataIndex The index of the data point.
 @return TKChartPointLabel instance that will be rendered for the data point.
 */
- (TKChartPointLabel * __nullable)chart:(TKChart * __nonnull)chart labelForDataPoint:(id<TKChartData> __nonnull)dataPoint property:(NSString * __nullable)propertyName inSeries:(TKChartSeries * __nonnull)series atIndex:(NSUInteger)dataIndex;

/**
 Returns a string representing the specified point.
 @param chart The TKChart instance requesting this information.
 @param dataPoint The data point for which a label is being created.
 @param propertyName The property name.
 @param series The series of the data point.
 @param dataIndex The index of the data point.
 @return A string for the point label.
 */
- (NSString * __nullable)chart:(TKChart * __nonnull)chart textForLabelAtPoint:(id<TKChartData> __nonnull)dataPoint property:(NSString * __nullable)propertyName inSeries:(TKChartSeries * __nonnull)series atIndex:(NSUInteger)dataIndex;

/**
 Returns a string representing the specified tick value.
 @param chart The TKChart instance requesting this information.
 @param axis The axis.
 @param value The tick value.
 @param index The index of the tick value.
 */
- (NSString * __nullable)chart:(TKChart * __nonnull )chart textForAxis:(TKChartAxis* __nonnull)axis value:(id __nullable)value atIndex:(NSUInteger)index;

/**
 Returns an attributed string representing the specified tick value.
 @param chart The TKChart instance requesting this information.
 @param axis The axis.
 @param value The tick value.
 @param index The index of the tick value.
 */
- (NSAttributedString * __nullable)chart:(TKChart * __nonnull )chart attributedTextForAxis:(TKChartAxis * __nonnull)axis value:(id __nullable)value atIndex:(NSUInteger)index;

/**
 Returns a render for point labels.
 @param chart The TKChart instance requesting this information.
 @param series The series for which labels will be rendered.
 @param render The series render.
 @return TKChartPointLabelRender instance.
 */
- (TKChartPointLabelRender * __nullable)chart:(TKChart * __nonnull)chart pointLabelRenderForSeries:(TKChartSeries * __nonnull)series withRender:(TKChartSeriesRender * __nonnull)render;

/**
 Returns TKChartLegendItem instance for series.
 @param chart The TKChart instance requesting this information.
 @param series The series for which a legend item is requested.
 @param index The legend item's index.
 */
- (TKChartLegendItem * __nullable)chart:(TKChart * __nonnull)chart legendItemForSeries:(TKChartSeries * __nonnull)series atIndex:(NSUInteger)index;

/**
 Called when legend item's styles should be updated.
 @param chart The TKChart instance requesting this information.
 @param item The legend item that will be updated.
 @param series The legend item's series.
 @param index The legend item's index.
 */
- (void)chart:(TKChart * __nonnull)chart updateLegendItem:(TKChartLegendItem * __nonnull)item forSeries:(TKChartSeries * __nonnull )series atIndex:(NSUInteger)index;

/**
 Called when touch occured on a legend item.
 @param chart The TKChart instance where the event occured.
 @param legendItem The legendItem responsible for the event.
 */
- (void)chart:(TKChart* __nonnull)chart didTapOnLegendItem:(TKChartLegendItem* __nonnull)legendItem;

@end // TKChartDelegate
