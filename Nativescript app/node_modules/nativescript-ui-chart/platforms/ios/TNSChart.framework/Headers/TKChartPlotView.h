//
//  TKPlotView.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartRender.h"
#import "TNSCore/TKView.h"

@class TKChart;
@class TKChartSeriesRender;
@class TKChartGridRender;
@class TKChartSelectionInfo;
@class TKChartAnnotationRender;

/**
 * @discussion The TKChart plot area.
 */
@interface TKChartPlotView : TKView<UIGestureRecognizerDelegate>

/**
 The associated TKChart instance.
 */
@property (nonatomic, weak, readonly, null_unspecified) TKChart *chart;

/**
 Returns the plot view grid.
 */
@property (nonatomic, strong, readonly, nonnull) TKChartGridRender *grid;

/**
 The gesture recognizer responsible for pan/zoom gestures in chart.
 */
@property (nonatomic, strong, readonly, nonnull) UIGestureRecognizer *panZoomRecognizer;

/**
 The gesture recognizer responsible for a single finger rotation in chart.
 */
@property (nonatomic, strong, readonly, nonnull) UIGestureRecognizer *rotateOneFingerRecognizer;

/**
 The gesture recognizer responsible for two finger rotation in chart.
 */
@property (nonatomic, strong, readonly, nonnull) UIRotationGestureRecognizer *rotateTwoFingerRecognizer;

/**
 The gesture recognizer responsible for a long press in chart.
 */
@property (nonatomic, strong, readonly, nonnull) UILongPressGestureRecognizer *longPressRecognizer;

/**
 The gesture recognizer responsible for a double tap gesture (reset zoom) in chart.
 */
@property (nonatomic, strong, readonly, nonnull) UITapGestureRecognizer *doubleTapGestureRecognizer;

/**
 Determines whether a tap gesture will be handled by the chart to allow selection and trackball features.
 */
@property (nonatomic) BOOL handleTap;

/**
 Initializes the plot view with a chart.
 @param chart The chart that owns the plot view.
 */
- (instancetype __nonnull)initWithChart:(TKChart* __nonnull)chart;

/**
 Does a hit point test.
 @param point The underlying point in screen coordinates.
 @return A TKChartHitTestResult containing information about the hit point found. Returns nil on no hit test found.
 */
- (TKChartSelectionInfo * __nullable)hitTestForPoint:(CGPoint)point;

/**
 Returns a render responsible for rendering of specific series.
 @param series The series which render should be returned.
 @return An instance of TKChartSeriesRender if successfull.
 */
- (TKChartSeriesRender* __nullable)renderForSeries:(TKChartSeries* __nonnull)series;

@end
