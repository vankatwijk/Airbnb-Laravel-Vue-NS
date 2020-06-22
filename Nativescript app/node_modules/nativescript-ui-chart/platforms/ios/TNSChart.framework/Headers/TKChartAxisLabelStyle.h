//
//  TKChartAxisLabelStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartLabelStyle.h"
#import "TKChartAxisStyle.h"

/**
 * @enum TKChartAxisLabelFitMode
 * @discussion Determines the label fit mode of the TKChart axis labels.
 */
typedef NS_ENUM(NSInteger, TKChartAxisLabelFitMode) {
    /**
     Does not attempt to fit the axis labels.
     */
    TKChartAxisLabelFitModeNone,
    /**
     Arranges the axis labels on multiple lines, so that there are no two neighbour labels on the same line.
     */
    TKChartAxisLabelFitModeMultiline,
    /**
     Arranges the axis labels, so that they are rotated around their top left corner.
     */
    TKChartAxisLabelFitModeRotate
};

/**
 * @enum TKChartAxisLabelAlignment
 * @discussion Determines the axis label alignment.
 */
typedef NS_OPTIONS(NSInteger, TKChartAxisLabelAlignment) {
    /**
     Aligns all labels with the left of the axis.
     */
    TKChartAxisLabelAlignmentLeft               = 1 << 0,
    /**
     Aligns all labels with the right of the axis.
     */
    TKChartAxisLabelAlignmentRight              = 1 << 1,
    /**
     Aligns all labels with the top of the axis.
     */
    TKChartAxisLabelAlignmentTop                = 1 << 2,
    /**
     Aligns all labels with the bottom of the axis.
     */
    TKChartAxisLabelAlignmentBottom             = 1 << 3,
    /**
     Aligns all labels with the bottom of the axis.
     */
    TKChartAxisLabelAlignmentHorizontalCenter   = 1 << 4,
    /**
     Aligns all labels with the center of the axis.
     */
    TKChartAxisLabelAlignmentVerticalCenter     = 1 << 5,
};

/**
 * @discussion Represents the style class of the axis labels.
 */
@interface TKChartAxisLabelStyle : TKChartLabelStyle

/**
 The text offset.
 */
@property (nonatomic, assign) UIOffset textOffset;

/**
 The label alignment.

 @discussion The axis label alignments are defined as follows:
 
     typedef enum {
         TKChartAxisLabelAlignmentLeft               = 1 << 0,   // Aligns all labels with the left of the axis.
         TKChartAxisLabelAlignmentRight              = 1 << 1,   // Aligns all labels with the right of the axis.
         TKChartAxisLabelAlignmentTop                = 1 << 2,   // Aligns all labels with the top of the axis.
         TKChartAxisLabelAlignmentBottom             = 1 << 3,   // Aligns all labels with the bottom of the axis.
         TKChartAxisLabelAlignmentHorizontalCenter   = 1 << 4,   // Aligns all labels with the bottom of the axis.
         TKChartAxisLabelAlignmentVerticalCenter     = 1 << 5,   // Aligns all labels with the center of the axis.
     } TKChartAxisLabelAlignment;
 
 */
@property (nonatomic, assign) TKChartAxisLabelAlignment textAlignment;

/**
 The label fit mode.
 
 @discussion The axis label fit modes are defined as follows:

     typedef enum {
         TKChartAxisLabelFitModeNone,       // Does not attempt to fit the axis labels.
         TKChartAxisLabelFitModeMultiline,  // Arranges the axis labels on multiple lines, so that there are no two neighbour labels on the same line.
         TKChartAxisLabelFitModeRotate,     // Arranges the axis labels, so that they are rotated around their top left corner.
     } TKChartAxisLabelFitMode;

 */
@property (nonatomic, assign) TKChartAxisLabelFitMode fitMode;

/**
 The clipping mode of the label positioned at the lowest position in the axis.
 
 @discussion The clipping modes are defined as follows:

    typedef enum {
         TKChartAxisClippingModeVisible,     // All ticks/labes are visible.
         TKChartAxisClippingModeHidden,      // All ticks/labes are hidden.
     } TKChartAxisClippingMode;

 */
@property (nonatomic, assign) TKChartAxisClippingMode minLabelClippingMode;

/**
 The clipping mode of the label positioned at the highest position in the axis.
 
 @see minLabelClippingMode for clipping modes
 
 */
@property (nonatomic, assign) TKChartAxisClippingMode maxLabelClippingMode;

/**
 Determines whether to clip axis labels in plot area.
 */
@property (nonatomic) BOOL clipAxisLabels;

/**
 The text offset of the first label.
 */
@property (nonatomic, assign) UIOffset firstLabelTextOffset;

/**
 The text offset of the last label.
 */
@property (nonatomic) UIOffset lastLabelTextOffset;

/**
 The text alignment of the first label.
 
 @see textAlignment for text alignment modes
 
 */
@property (nonatomic, assign) TKChartAxisLabelAlignment firstLabelTextAlignment;

/**
 The text alignment of the last label.
 
 @see textAlignment for text alignment modes
 
 */
@property (nonatomic) TKChartAxisLabelAlignment lastLabelTextAlignment;

/**
 The label's rotation angle.
 */
@property (nonatomic) CGFloat rotationAngle;

@end
