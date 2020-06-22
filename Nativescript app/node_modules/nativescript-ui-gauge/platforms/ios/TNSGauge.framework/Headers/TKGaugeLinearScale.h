//
//  TKGaugeLinearScale.h
//  TelerikUI
//
//  Created by wfmac on 9/20/15.
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TKGaugeScale.h"

/**
 Linear TKGaugeScale.
 */
@interface TKGaugeLinearScale : TKGaugeScale

/**
 Represents the start point of the scale from 0 to 1.
 */
@property (nonatomic) CGFloat startPoint;

/**
 Represents the end point of the scale from 0 to 1.
 */
@property (nonatomic) CGFloat endPoint;

/**
 Represents the offset of the scale starting from top to bottom.
 */
@property (nonatomic) CGFloat offset;

@end
