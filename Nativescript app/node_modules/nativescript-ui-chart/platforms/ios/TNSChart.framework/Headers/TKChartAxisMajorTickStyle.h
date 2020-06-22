//
//  TKChartAxisMajorTickStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAxisTickStyle.h"
#import "TKChartAxisStyle.h"

/**
 Represents a major tick style of an axis.
 */
@interface TKChartAxisMajorTickStyle : TKChartAxisTickStyle

/**
 The clipping mode of a tick at the minimum position in the axis. See TKChartAxisLabelStyle for TKChartAxisClippingMode description.
 */
@property (nonatomic, assign) TKChartAxisClippingMode minTickClippingMode;

/**
 The clipping mode of a tick at the maximum position in the axis. See TKChartAxisLabelStyle for TKChartAxisClippingMode description.
 */
@property (nonatomic, assign) TKChartAxisClippingMode maxTickClippingMode;

@end
