//
//  TKAxisTitleStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartLabelStyle.h"

/**
 * @enum TKChartAxisTitleAlignment
 * @discussion Represents the title alignment of an axis.
 */
typedef NS_ENUM(NSInteger, TKChartAxisTitleAlignment) {
    /**
     Aligns the title at the axis center.
     */
    TKChartAxisTitleAlignmentCenter,
    /**
     Aligns the title at the left or at the top.
     */
    TKChartAxisTitleAlignmentLeftOrTop,
    /**
     Aligns the title at the right or at the bottom.
     */
    TKChartAxisTitleAlignmentRightOrBottom
};

/**
 * @discussion Represents a class that defines the appearance of the axis title.
 */
@interface TKChartAxisTitleStyle : TKChartLabelStyle

/**
 The title alignment in relation to its superview.
 
 @discussion The axis title alignments are defined as follows:
 
    typedef enum {
        TKChartAxisTitleAlignmentCenter,        // Aligns the title at the axis center.
        TKChartAxisTitleAlignmentLeftOrTop,     // Aligns the title at the left or at the top.
        TKChartAxisTitleAlignmentRightOrBottom, // Aligns the title at the right or at the bottom.
    } TKChartAxisTitleAlignment;

 */
@property (nonatomic, assign) TKChartAxisTitleAlignment alignment;

/**
 The angle used to rotate the title text.
 */
@property (nonatomic, assign) CGFloat rotationAngle;

/**
 Title's offset from axis labels.
 */
@property (nonatomic) CGFloat textOffset;

@end
