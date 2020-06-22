//
//  TKChartLegendItemStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKChartLabelStyle;
@class TKFill;
@class TKStroke;

/**
 @discussion Represents the layout style of a legend item.
 */
@interface TKChartLegendItemStyle : TKStyleNode

/**
 The label's style.
 */
@property (nonatomic, strong, readonly, nonnull) TKChartLabelStyle *labelStyle;

/**
 The fill color to be used as a background.
 @return An instance of UIColor representing the fill color.
 */
@property (nonatomic, strong) TKFill * __nullable fill;

/**
 The stroke color to be used for the legend frame.
 @return An instance of UIColor representing the stroke color.
 */
@property (nonatomic, strong) TKStroke * __nullable stroke;

/**
 Specifies the icon's size.
 */
@property (nonatomic, assign) CGSize iconSize;


@end
