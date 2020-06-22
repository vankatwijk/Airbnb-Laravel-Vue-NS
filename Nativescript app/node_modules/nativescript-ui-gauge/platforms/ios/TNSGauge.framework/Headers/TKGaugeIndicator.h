//
//  TKGaugeIndicator.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKFill;
@class TKStroke;
@class TKGaugeScale;

/**
 A base class for indicators that belong to TKGaugeScale.
 */
@interface TKGaugeIndicator : CALayer

/**
 The scale that owns the indicator.
 */
@property (nonatomic, weak, null_unspecified) TKGaugeScale* owner;

/**
 The indicator value. It determines its position on the scale.
 */
@property (nonatomic) CGFloat value;

/**
 Defines the indicators' fill.
 */
@property (nonatomic, strong, nullable) TKFill* fill;

/**
 Defines the indicators' stroke.
 */
@property (nonatomic, strong, nullable) TKStroke* stroke;

/**
 Allows interaction with the segment and changing its value.
 */
@property (nonatomic) BOOL allowTouch;

@end
