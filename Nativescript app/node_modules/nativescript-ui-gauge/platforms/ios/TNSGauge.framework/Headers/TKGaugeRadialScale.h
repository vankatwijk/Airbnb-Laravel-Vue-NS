//
//  TKGaugeRadialScale.h
//  TelerikUI
//
//  Created by wfmac on 9/20/15.
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TKGaugeScale.h"

/**
 Radial TKGaugeScale
 */
@interface TKGaugeRadialScale : TKGaugeScale

/**
 Defines the start angle of the scale in radians.
 */
@property (nonatomic) CGFloat startAngle;

/**
 Defines the end angle of the scale in radians.
 */
@property (nonatomic) CGFloat endAngle;

/**
 Defines the radius of the scale from 0 to 1.
 */
@property (nonatomic) CGFloat radius;

@end
