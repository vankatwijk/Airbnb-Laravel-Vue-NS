
//
//  TKChartSeriesRender.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartRender.h"

@class TKChartAxis;
@class TKChartSeries;
@class TKChartVisualPoint;
@class TKMutableArray;
@class TKChartSelectionInfo;

@protocol TKChartData;

/**
 @discussion Represents a class that renders stacked series.
 */
@interface TKChartSeriesRender : TKChartRender

/**
 The series associated with this render.
 */
@property (nonatomic, strong, readonly) NSArray * __nonnull series;

/**
 Returns the render states for all associated series
 */
@property (nonatomic, strong, readonly) TKMutableArray * __nonnull seriesRenderStates;

/**
 Returns The location of numeric value representation
 @param numericValue The numeric value
 @param axis The axis
 @param bounds The bounds
 @return The location of numeric value representation
 */
+ (CGFloat)locationOfValue:(double)numericValue forAxis:(TKChartAxis* __nonnull)axis inRect:(CGRect)bounds;

/**
 Initializes the TKChartSeriesRender object.
 @param chart The chart associated with this render.
 @param series The stacked series.
 */
- (instancetype __nonnull)initWithChart:(TKChart * __nonnull)chart forSeries:(NSArray* __nonnull)series;

/**
 Adds a series to render.
  @param series The series that should be added.
 */
- (BOOL)addSeries:(TKChartSeries* __nonnull)series;

/**
 Determines whether a series is compatible with TKChartSeriesRender.
 @param series The series to test with.
 */
- (BOOL)isCompatibleWithSeries:(TKChartSeries* __nonnull)series;

/**
 Returns an x-coordinate of the x-numeric value for specific series.
 @param numericValue The numeric value.
 @param series The series.
 */
- (double)locationOfXNumericValue:(double)numericValue inSeries:(TKChartSeries* __nonnull)series;

/**
 Returns a y-coordinate of the y-numeric value for specific series.
 @param numericValue The numeric value.
 @param series The series.
 */
- (double)locationOfYNumericValue:(double)numericValue inSeries:(TKChartSeries* __nonnull)series;

/**
 Returns the location of a data point
 @param data The data point to locate
 @param series The series to which the specified data point is associated
 */
- (CGPoint)locationOfPoint:(id<TKChartData> __nonnull)data inSeries:(TKChartSeries* __nonnull)series;

/**
 Returns a visual point based on the provided information.
 @param point The data point that should be converted.
 @param index The data point index.
 @param series The series which contains this point.
 @return An instance of TKChartVisualPoint if successfull.
 */
- (TKChartVisualPoint* __nonnull)pointFromData:(id<TKChartData> __nonnull)point pointIndex:(NSUInteger)index inSeries:(TKChartSeries * __nonnull)series;

/**
 Creates a visual point based on the provided information.
 @param data The data point that should be converted.
 @param index The data point index.
 @param series The series which contains this point.
 @return The instance of the newly created TKChartVisualPoint.
 */
- (TKChartVisualPoint* __nonnull)createVisualPoint:(id<TKChartData> __nonnull)data pointIndex:(NSInteger)index inSeries:(TKChartSeries * __nonnull)series;

/**
 Does a hit point test.
 @param point The point to test with.
 @return A TKChartSelectionInfo object containing information about the hit point found. Returns nil when no hit test found.
 */
- (TKChartSelectionInfo * __nonnull)hitTestForPoint:(CGPoint)point;

/**
 This method is being called by TKChart when the selection is about to change.
 @param series The series that is currently selected.
 @param pointIndex The point index of the currently selected point.
 */
- (void)selectionWillChangeForSeries:(TKChartSeries* __nonnull)series andPoint:(NSInteger)pointIndex;

@end
