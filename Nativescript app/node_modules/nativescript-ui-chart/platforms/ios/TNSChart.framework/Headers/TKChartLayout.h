//
//  TKChartLayout.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartCrossedAxisLayout.h"
#import "TNSCore/TKCoreLayout.h"

@class TKChart;
@class TKChartAxisView;
@class TKChartPlotView;
@class TKCoreStackLayout;

/**
 Defines the chart layout.
 */
@interface TKChartLayout : NSObject<TKCoreLayout>

/**
 Defines the layout's alignment mode.
 */
@property TKCoreLayoutAlignmentMode alignmentMode;

/**
 Defines the layout's stretch mode.
 */
@property TKCoreLayoutStretchMode stretchMode;

/**
 The left axes of the chart.
 */
@property (nonatomic, strong, readonly) TKCoreStackLayout *leftAxes;

/**
 The right axes of the chart.
 */
@property (nonatomic, strong, readonly) TKCoreStackLayout *rightAxes;

/**
 The top axes of the chart.
 */
@property (nonatomic, strong, readonly) TKCoreStackLayout *topAxes;

/**
 The bottom axes of the chart.
 */
@property (nonatomic, strong, readonly) TKCoreStackLayout *bottomAxes;

/**
 The crossed axes of the chart.
 */
@property (nonatomic, strong, readonly) TKChartCrossedAxisLayout *crossedAxes;

/**
 The chart's plot view.
 */
@property (nonatomic, strong) TKChartPlotView *plotView;

/**
 Adds an axis to the layout.
 @param axisView The axis.
 @param baselineAxisView The baselines axis.
 */
- (void)addAxis:(TKChartAxisView*)axisView withBaselineAxis:(TKChartAxisView*)baselineAxisView;

/**
 Initializes the layout with its view.
 @param chart The chart.
 */
- (instancetype)initWithChart:(TKChart*)chart;

/**
 Adds an axis to the left of the layout.
 @param axis The axis.
 */
- (BOOL)addLeftAxis:(TKChartAxisView*)axis;

/**
 Adds an axis to the right of the layout.
 @param axis The axis.
 */
- (BOOL)addRightAxis:(TKChartAxisView*)axis;

/**
 Adds an axis to the top of the layout.
 @param axis The axis.
 */
- (BOOL)addTopAxis:(TKChartAxisView*)axis;

/**
 Adds an axis to the bottom of the layout.
 @param axis The axis.
 */
- (BOOL)addBottomAxis:(TKChartAxisView*)axis;

/**
 Removes all axes from the layout.
 */
- (void)removeAllAxes;

- (void)setNeedsDisplayAxes;

@end
