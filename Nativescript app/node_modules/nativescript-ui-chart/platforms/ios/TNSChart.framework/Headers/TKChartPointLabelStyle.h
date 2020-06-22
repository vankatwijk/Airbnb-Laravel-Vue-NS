//
//  TKChartPointLabelStyle.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartLabelStyle.h"

/**
 @enum TKChartPointLabelLayoutMode
 @discussion Represents an enum that defines how point labels should be laid out.
 */
typedef NS_ENUM(NSUInteger, TKChartPointLabelLayoutMode)
{
    /**
     Point labels layout is defined by the developer.
     */
    TKChartPointLabelLayoutModeManual,
    
    /**
     Point labels layout is determined automatically.
     */
    TKChartPointLabelLayoutModeAuto
};

/**
 @enum TKChartPointLabelClipMode
 @discussion Represents an enum that defines if point labels should be clipped when out of bounds.
 */
typedef NS_ENUM(NSUInteger, TKChartPointLabelClipMode)
{
    /**
     Point labels will be clipped when outside of the plot area bounds
     */
    TKChartPointLabelClipModeHidden,
    
    /**
     Plot labels will stay visible even if outside of the plot area
     */
    TKChartPointLabelClipModeVisible
};

/**
 @enum TKChartPointLabelOrientation
 @discussion Represents an enum that defines point label's text orientation.
 */
typedef NS_ENUM(NSUInteger, TKChartPointLabelOrientation)
{
    /**
     Point labels text orientation will be vertical
     */
    TKChartPointLabelOrientationVertical,
    
    /**
     Point labels text orientation will be horizontal
     */
    TKChartPointLabelOrientationHorizontal
};

/**
 Represents a point label style.
 */
@interface TKChartPointLabelStyle : TKChartLabelStyle

/**
 The point label's offset from the corresponding data point.
 */
@property (nonatomic) UIOffset labelOffset;

/**
 Corner radius for point label's rect.
 */
@property (nonatomic) CGFloat cornerRadius;

/**
 Layout mode for a point label.
 */
@property (nonatomic) TKChartPointLabelLayoutMode layoutMode;

/**
 Clip mode for a point label.
 */
@property (nonatomic) TKChartPointLabelClipMode clipMode;

/**
 Point label's text alignment.
 */
@property (nonatomic) NSTextAlignment textAlignment;

/**
 Point label's text orientation.
 */
@property (nonatomic) TKChartPointLabelOrientation textOrientation;

/**
 Blur radius for point label's text shadow.
 */
@property (nonatomic) CGFloat blurRadius;

/**
 Formatter for point label's text.
 */
@property (nonatomic, strong) NSFormatter * __nullable formatter;

/**
 String formatter for point label.
 */
@property (nonatomic, copy) NSString * __nullable stringFormat;


@end
