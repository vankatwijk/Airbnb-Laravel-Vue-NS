//
//  TKChartLegendStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

@class TKFill;
@class TKStroke;

/**
 * @enum TKChartLegendPosition
 * @discussion Defines the different places where the legend can be positioned.
 */
typedef NS_ENUM(NSInteger, TKChartLegendPosition)
{
    /** 
     The legend is positioned at the left side of the chart.
     */
    TKChartLegendPositionLeft,
    
    /**
     The legend is positioned at the right side of the chart.
     */
    TKChartLegendPositionRight,
    
    /**
     The legend is positioned at the top side of the chart.
     */
    TKChartLegendPositionTop,
    
    /**
     The legend is positioned at the bottom side of the chart.
     */
    TKChartLegendPositionBottom,
    
    /**
     The legend is floating. You should set the offset and offsetOrigin properties when using this option.
     */
    TKChartLegendPositionFloating
    
};

/**
 * @enum TKChartLegendOffsetOrigin
 * @discussion Defines the offset origin.
 */
typedef NS_ENUM(NSInteger, TKChartLegendOffsetOrigin)
{
    /**
     The offset is relative to the top left corner.
     */
    TKChartLegendOffsetOriginTopLeft,
    
    /**
     The offset is relative to the top right corner.
     */
    TKChartLegendOffsetOriginTopRight,
    
    /**
     The offset is relative to the bottom left corner.
     */
    TKChartLegendOffsetOriginBottomLeft,
    
    /**
     The offset is relative to the bottom right corner.
     */
    TKChartLegendOffsetOriginBottomRight
    
};

/**
 * @discussion Represents the layout style of a legend.
 */
@interface TKChartLegendStyle : TKStyleNode

/**
 The position of the legend.

 @discussion The legend positions are defined as follows:

    typedef enum TKChartLegendPosition {
        TKChartLegendPositionLeft,      // The legend is positioned at the left side of the chart.
        TKChartLegendPositionRight,     // The legend is positioned at the right side of the chart.
        TKChartLegendPositionTop,       // The legend is positioned at the top side of the chart.
        TKChartLegendPositionBottom,    // The legend is positioned at the bottom side of the chart.
        TKChartLegendPositionFloating   // The legend is floating. You should set the offset and offsetOrigin properties when using this option.
    } TKChartLegendPosition;

 */
@property (nonatomic, assign) TKChartLegendPosition position;

/**
 The offset at which to place the legend, according to the specified offsetOrigin.
 */
@property (nonatomic, assign) UIOffset offset;

/**
 The starting point for the offset property.

 @discussion The legend offset origins are defined as follows:
 
    typedef enum TKChartLegendOffsetOrigin {
        TKChartLegendOffsetOriginTopLeft,       // The offset is relative to the top left corner.
        TKChartLegendOffsetOriginTopRight,      // The offset is relative to the top right corner.
        TKChartLegendOffsetOriginBottomLeft,    // The offset is relative to the bottom left corner.
        TKChartLegendOffsetOriginBottomRight    // The offset is relative to the bottom right corner.
    } TKChartLegendOffsetOrigin;

 */
@property (nonatomic, assign) TKChartLegendOffsetOrigin offsetOrigin;

/**
 The fill color to be used as a background.
 @return An instance of UIColor representing the fill color.
 */
@property (nonatomic, strong) TKFill *  __nullable fill;

/**
 The stroke color to be used for the legend frame.
 @return An instance of UIColor representing the stroke color.
 */
@property (nonatomic, strong) TKStroke * __nullable stroke;

/**
 The insets to be applied on the legend view.
 */
@property (nonatomic) UIEdgeInsets insets;

@end
