//
//  TKGaugeLinear.h
//  TelerikUI
//
//  Copyright (c) 2015 г. Telerik. All rights reserved.
//

#import "TKGauge.h"

@class TKGaugeLinearScale;

/**
 @enum TKLinearGaugeOrientation
 @discussion Defines the orientation of TKLinearGauge.
 */
typedef NS_ENUM(NSInteger, TKLinearGaugeOrientation)
{
    /**
     Orientation can be horizontal.
     */
    TKLinearGaugeOrientationHorizontal,
    /**
     Orientation can be vertical.
     */
    TKLinearGaugeOrientationVertical
};

/**
 @enum TKLinearGaugeLabelPosition
 @discussion Defines the position of TKLinearGauge's label.
 */
typedef NS_ENUM(NSInteger, TKLinearGaugeLabelPosition)
{
    /**
     If the gauge orientation is set to horizontal then the label's position could be top.
     If the gauge orientation is set to vertical then the label's position could be left.
     */
    TKLinearGaugeLabelPositionTopOrLeft,
    /**
     If the gauge orientation is set to horizontal then the label's position could be bottom.
     If the gauge orientation is set to vertical then the label's position could be right.
     */
    TKLinearGaugeLabelPositionBottomOrRight
};

/**
 Linear TKGauge.
 */
@interface TKLinearGauge : TKGauge

/**
Defines the orientation of TKLinearGauge.
 */
@property (nonatomic) TKLinearGaugeOrientation orientation;

/**
 Defines the label position in TKLinearGauge.
 */
@property (nonatomic) TKLinearGaugeLabelPosition labelPosition;

/**
 Defines the label orientation in TKLinearGauge.
 */
@property (nonatomic) TKLinearGaugeOrientation labelOrientation;

/**
 Defines the spacing between labelTitle and labelSubtitle.
 */
@property (nonatomic) CGFloat labelSpacing;

@end
