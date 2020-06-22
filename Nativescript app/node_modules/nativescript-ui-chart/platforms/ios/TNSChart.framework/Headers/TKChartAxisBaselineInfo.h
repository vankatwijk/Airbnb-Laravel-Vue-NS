//
//  TKChartAxisBaseline.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKChartAxisView;

/**
 The layout information for the baseline support of axes.
 */
@interface TKChartAxisBaselineInfo : NSObject

/**
 The axis.
 */
@property (nonatomic, strong, readonly) TKChartAxisView *axis;

/**
 The baseline axis.
 */
@property (nonatomic, strong, readonly) TKChartAxisView *baselineAxis;

/**
 Initializes the TKChartAxisBaseline.
 @param axisView The axis view.
 @param baselineAxisView The baseline axis view.
 */
- (instancetype)initWithAxis:(TKChartAxisView*)axisView baselineAxis:(TKChartAxisView*)baselineAxisView;

@end
