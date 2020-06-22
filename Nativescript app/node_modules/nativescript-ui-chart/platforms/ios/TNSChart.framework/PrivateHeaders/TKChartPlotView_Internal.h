//
//  TKChartPlotView_Internal.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TKChartPlotView.h"

@interface TKChartPlotView ()

/**
 Returns the annotation layer presenting annotations below series
 */
@property (nonatomic, strong, readonly) TKChartAnnotationRender* belowAnnotationLayer;

/**
 Returns the annotation layer presenting annotations below series
 */
@property (nonatomic, strong, readonly) TKChartAnnotationRender* aboveAnnotationLayer;

@property (nonatomic) BOOL skipTap;

/**
 Reloads the chart series.
 */
- (void)reloadSeries;

/**
 Attaches a series render to the chart render layers.
 @param series The series attached to te plot view.
 */
- (void)attachSeries:(TKChartSeries *)series;

/**
 Detaches a series render from the chart render layers.
 @param series The series to be detached.
 */
- (void)detachSeries:(TKChartSeries *)series;

/**
 Suspends all updates.
 */
- (void)beginUpdates;

/**
 Resumes and performs all updates.
 */
- (void)endUpdates;

/**
 Removes all series renders.
 */
- (void)removeAllSeriesRenders;

/**
 Updates all renders on next layout.
 */
- (void)updateRendersOnNextLayout;

/**
 Performs the selection procedure against the provided selection info.
 */

- (void)performSelection:(TKChartSelectionInfo*) info;

@end
