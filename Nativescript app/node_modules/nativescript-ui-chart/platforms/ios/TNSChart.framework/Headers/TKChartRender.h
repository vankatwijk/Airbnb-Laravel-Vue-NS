//
//  TKChartRender.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKChart;

/**
 @discussion The base rendering layer of TKChart series.
 */
@interface TKChartRender : CALayer

/**
 Returns the chart associated with the renderer (read-only).
 */
@property (nonatomic, weak, readonly, null_unspecified) TKChart* chart;

/**
 Initializes the render with chart.
 @param chart the chart to associate with.
 */
- (instancetype __nonnull)initWithChart:(TKChart* __nonnull)chart;

/**
 This method is called when the render should update its visual state.
 */
- (void)update;

/**
 This method is called when the render should initialize its content.
 */
- (void)setup;

@end
