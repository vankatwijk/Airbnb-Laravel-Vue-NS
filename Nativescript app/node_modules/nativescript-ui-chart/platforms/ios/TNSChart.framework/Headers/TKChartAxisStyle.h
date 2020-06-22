//
//  TKChartAxisStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

@class TKChartAxisTickStyle;
@class TKChartAxisTitleStyle;
@class TKChartAxisLabelStyle;
@class TKChartAxisMajorTickStyle;
@class TKStroke;
@class TKFill;

/**
 @enum TKChartAxisClippingMode
 @discussion Defines an enum that determines how the labels/ticks are shown on the axis.
 */
typedef NS_ENUM(NSInteger, TKChartAxisClippingMode)
{
    /**
     All ticks/labels are visible.
     */
    TKChartAxisClippingModeVisible,
    /**
     All ticks/labels are hidden.
     */
    TKChartAxisClippingModeHidden
};

/**
 Defines axis' style
 */
@interface TKChartAxisStyle : TKStyleNode

/**
 The axis line stroke.
 */
@property (nonatomic, strong) TKStroke *lineStroke;

/**
 The location of the axis line from the bounds of the chart. By default is calculated automatically.
 */
@property (nonatomic, strong) NSNumber *lineLocation;

/**
 Defines whether the axis line is hidden.
 */
@property (nonatomic, assign) BOOL lineHidden;

/**
 The axis background fill.
 */
@property (nonatomic, strong) TKFill *backgroundFill;

/**
 The axis label style.
 */
@property (nonatomic, strong, readonly) TKChartAxisLabelStyle *labelStyle;

/**
 The appaerance of the axis' title.
 */
@property (nonatomic, strong, readonly) TKChartAxisTitleStyle *titleStyle;

/**
 The appaerance of the major ticks.
 */
@property (nonatomic, strong, readonly) TKChartAxisMajorTickStyle *majorTickStyle;

/**
 The appaerance of the minor ticks.
 */
@property (nonatomic, strong, readonly) TKChartAxisTickStyle *minorTickStyle;

@end
