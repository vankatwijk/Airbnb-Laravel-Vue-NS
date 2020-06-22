//
//  TKAxisTickStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

@class TKStroke;
@class TKFill;

/**
 Represents a class that defines the appearance of the ticks and thier labels.
 */

@interface TKChartAxisTickStyle : TKStyleNode

/**
 The tick stroke.
 */
@property (nonatomic, strong) TKStroke * __nullable ticksStroke;

/**
 The tick fill.
 */
@property (nonatomic, strong) TKFill * __nullable ticksFill;

/**
 The tick offset.
 */
@property (nonatomic, assign) CGFloat ticksOffset;

/**
 The tick padding.
 */
@property (nonatomic, assign) CGFloat ticksPadding;

/**
 The tick length.
 */
@property (nonatomic, assign) CGFloat ticksLength;

/**
 The tick width.
 */
@property (nonatomic, assign) CGFloat ticksWidth;

/**
 Defines whether the ticks are hidden.
 */
@property (nonatomic, assign) BOOL ticksHidden;

@end
