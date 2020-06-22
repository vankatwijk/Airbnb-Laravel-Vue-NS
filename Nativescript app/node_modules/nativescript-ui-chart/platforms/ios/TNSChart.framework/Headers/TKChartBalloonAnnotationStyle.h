//
//  TKChartBalloonAnnotationStyle.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartAnnotationStyle.h"

@class TKFill;
@class TKStroke;
@class TKShape;

/**
 The vertical alignment opitons available for a balloon annotation.
 */
typedef NS_ENUM(NSInteger, TKChartBalloonVerticalAlignment) {
    /**
     The balloon should appear vertically centered to the balloon location.
     */
    TKChartBalloonVerticalAlignmentCenter  = 0,
    
    /**
     The balloon should appear at the top of the balloon location.
     */
    TKChartBalloonVerticalAlignmentTop     = 1,
    
    /**
     The balloon should appear at the bottom of the balloon location.
     */
    TKChartBalloonVerticalAlignmentBottom  = 2,
    
};

/**
 The Horizontal alignment options available for a balloon annotation.
 */
typedef NS_ENUM(NSInteger, TKChartBalloonHorizontalAlignment) {
    /**
     The balloon should appear horizontally centered to the balloon location.
     */
    TKChartBalloonHorizontalAlignmentCenter = 0,
    /**
     The balloon should appear at the left of the balloon location.
     */
    TKChartBalloonHorizontalAlignmentLeft   = 1,
    
    /**
     The balloon should appear at the right of the balloon location.
     */
    TKChartBalloonHorizontalAlignmentRight  = 2,
    
};

/**
 The text orientation in a balloon annotation.
 */
typedef NS_ENUM(NSInteger, TKChartBalloonAnnotationTextOrientation) {
    /**
     Vertical orientation.
     */
    TKChartBalloonAnnotationTextOrientationVertical,
    /**
     Horizontal orientation.
     */
    TKChartBalloonAnnotationTextOrientationHorizontal,
    
};

/**
 This class contains style properties applicable in balloon annotations.
 */
@interface TKChartBalloonAnnotationStyle : TKChartAnnotationStyle

/**
 The view fill.
 */
@property (nonatomic, strong) TKFill * __nullable fill;

/**
 The view stroke.
 */
@property (nonatomic, strong) TKStroke * __nullable stroke;

/**
 The content's font.
 */
@property (nonatomic, strong) UIFont * __nullable font;

/**
 The content's text color.
 */
@property (nonatomic, strong) UIColor * __nullable textColor;

/**
 The text alignment.
 */
@property (nonatomic, assign) NSTextAlignment textAlignment;

/**
 The text orientation.
 */
@property (nonatomic, assign) TKChartBalloonAnnotationTextOrientation textOrientation;

/**
 The text insets. Use negative values to enlarge area.
 */
@property (nonatomic, assign) UIEdgeInsets insets;

/**
 The view vertical alignment.
 */
@property (nonatomic, assign) TKChartBalloonVerticalAlignment verticalAlign;

/**
 The view horizontal alginment.
 */
@property (nonatomic, assign) TKChartBalloonHorizontalAlignment horizontalAlign;

/**
 The distance between the ballooon and its location.
 */
@property (nonatomic, assign) CGFloat distanceFromPoint;

/**
 The arrow size.
 */
@property (nonatomic, assign) CGSize arrowSize;

/**
 The corner radius of a balloon.
 */
@property (nonatomic, assign) CGFloat cornerRadius;

@end
