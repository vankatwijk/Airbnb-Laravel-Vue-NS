//
//  TKChartPanZoomGestureRecognizer.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKChart;

/**
 @discussion A pan zoom gesture recognizer for TKChart.
 */
@interface TKChartPanZoomGestureRecognizer : UIGestureRecognizer

/**
 The associated TKChart instance.
 */
@property (nonatomic, weak, readonly, nullable) TKChart *chart;

/**
 Initializes the gesture recognizer with a chart.
 @param chart The chart that owns the gesture recognizer.
 */
- (instancetype __nonnull)initWithChart:(TKChart * __nonnull)chart;

@end
