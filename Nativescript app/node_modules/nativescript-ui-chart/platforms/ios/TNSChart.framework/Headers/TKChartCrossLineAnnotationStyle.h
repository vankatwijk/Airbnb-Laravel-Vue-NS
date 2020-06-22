//
//  TKChartLineAnnotationStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAnnotationStyle.h"

@class TKChartPaletteItem;
@class TKShape;
@class TKFill;
@class TKStroke;

/**
 The orientation of line annotation.
 */
typedef NS_OPTIONS(NSInteger, TKChartCrossLineAnnotationOrientation) {
    /**
     Horizontal annotation orientation.
     */
    TKChartCrossLineAnnotationOrientationHorizontal = 1 << 0,
    /**
     Vertical annotation orientation.
     */
    TKChartCrossLineAnnotationOrientationVertical   = 1 << 1,
};

/**
 This class contains style properties applicable for cross line annotations.
 */
@interface TKChartCrossLineAnnotationStyle : TKChartAnnotationStyle

/**
 The annotioatn orientation.
 */
@property (nonatomic, assign) TKChartCrossLineAnnotationOrientation orientation;

/**
 The vertical line stroke.
 */
@property (nonatomic, strong) TKStroke * __nullable verticalLineStroke;

/**
 The horizontal line stroke.
 */
@property (nonatomic, strong) TKStroke * __nullable horizontalLineStroke;

/**
 The shaped used for drawing the data points. It is supported for line, area and scatter series.
 By default, it is a circle with a size of 6 px on scatter series and nil (no shape) for line and area.
 */
@property (nonatomic, strong) TKShape * __nullable pointShape;

/**
 The point shape insets.
 **/
@property (nonatomic, assign) UIEdgeInsets pointShapeInsets;

/**
 The shape fill.
 */
@property (nonatomic, strong) TKFill * __nullable pointShapeFill;

/**
 The shape stroke.
 */
@property (nonatomic, strong) TKStroke * __nullable pointShapeStroke;

/**
 The line inset.
 */
@property (nonatomic, assign) UIEdgeInsets insets;

@end
