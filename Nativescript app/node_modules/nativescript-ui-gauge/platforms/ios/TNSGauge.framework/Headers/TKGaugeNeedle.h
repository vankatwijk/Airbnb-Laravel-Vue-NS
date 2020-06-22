//
//  TKGaugeNeedle.h
//  TelerikUI
//
//  Copyright (c) 2015 г. Telerik. All rights reserved.
//

#import "TKGaugeIndicator.h"

@class TKFill;
@class TKStroke;

/**
 Represents a needle indicator used in linear and radial gauges.
 */
@interface TKGaugeNeedle : TKGaugeIndicator

/**
 Defines the needle length. The needle length is calculated in normalized coordinates between 0 and 1.
 */
@property (nonatomic) CGFloat length;

/**
 Defines the bottom width of the needle.
 */
@property (nonatomic) CGFloat width;

/**
 Defines the top width of the needle.
 */
@property (nonatomic) CGFloat topWidth;

/**
 Defines the needle center radius.
 */
@property (nonatomic) CGFloat circleRadius;

/**
 Defines the needle center inner radius.
 */
@property (nonatomic) CGFloat circleInnerRadius;

/**
 Defines an offset to be added to the needle bottom.
 */
@property (nonatomic) CGFloat offset;

/**
  Defines the needle circle fill.
 */
@property (nonatomic, strong, nullable) TKFill *circleFill;

/**
 Defines the needle circle stroke.
 */
@property (nonatomic, strong, nullable) TKStroke *circleStroke;

/**
 Initializes scale with a value.
 @param value The needle value.
 */
- (instancetype __nonnull)initWithValue:(CGFloat)value;

/**
 Initializes scale with a value and length.
 @param value The needle value.
 @param length The needle length. The needle length is calculated in normalized coordinates between 0 and 1.
 */
- (instancetype __nonnull)initWithValue:(CGFloat)value length:(CGFloat)length;

/**
 Sets the needle value using animation.
 @param value The needle value.
 @param duration The animation duration.
 @param functionName The name of the easing function to be used.
 */
- (void)setValueAnimated:(CGFloat)value withDuration:(CGFloat)duration mediaTimingFunction:(NSString* __nonnull)functionName;

@end
