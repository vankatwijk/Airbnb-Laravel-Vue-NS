//
//  TKGaugeScale.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKFill;
@class TKStroke;
@class TKGauge;
@class TKRange;
@class TKGaugeLine;
@class TKGaugeTicks;
@class TKGaugeLabels;
@class TKGaugeSegment;
@class TKGaugeIndicator;

/**
 Represents the view of the gauge's scale.
 */
@interface TKGaugeScale : CALayer

/**
 Represents the instance of TKGauge that owns this scale.
 */
@property (nonatomic, weak, null_unspecified) TKGauge* owner;

/**
 Defines the minimum and maximum value of the scale.
 */
@property (nonatomic, strong, nonnull) TKRange* range;

/**
 Defines the scale fill.
 */
@property (nonatomic, strong, nullable) TKFill* fill;

/**
Defines the scale stroke.
 */
@property (nonatomic, strong, nullable) TKStroke* stroke;

/**
Instance representing the ticks of the scale.
 */
@property (nonatomic, strong, readonly, nonnull) TKGaugeTicks* ticks;

/**
 Instance representing the labels of the scale.
 */
@property (nonatomic, strong, readonly, nonnull) TKGaugeLabels* labels;

/**
 Contains all the segments added to the scale.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray<TKGaugeSegment *>* segments;

/**
 Contains all the indicators added to the scale.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray<__kindof TKGaugeIndicator *>* indicators;

/**
 Initializes scale with TKRange.
 @param range TKRange instance that defines the minumum and maximum value of the scale.
 */
- (instancetype __nonnull)initWithRange:(TKRange* __nonnull)range;

/**
 Initializes scale with minimum and maximum value.
 @param minimum The minimum value of the scale.
 @param maximum The maximum value of the scale.
 */
- (instancetype __nonnull)initWithMinimum:(id __nonnull)minimum maximum:(id __nonnull)maximum;

/**
 Returns the value for given coordinates on the screen.
 @param point The coordinates of the value to be returned.
 */
- (CGFloat)valueForPoint:(CGPoint)point;

/**
 Returns the screen coordinates of a given value
 @param value The value.
 */
- (CGFloat)locationForValue:(CGFloat)value;

/**
 Returns the text representation for a given value.
 @param value The value.
 */
- (NSString* __nonnull)textForValue:(CGFloat)value;

- (CGFloat)denormalize:(CGFloat)value;

/**
Adds segment to the scale.
@param segment The segment to be added.
 */
- (void)addSegment:(TKGaugeSegment* __nonnull)segment;

/**
 Removes segment from the scale.
 @param segment The segment to be removed.
 */
- (void)removeSegment:(TKGaugeSegment* __nonnull)segment;

/**
 Removes segment from the scale by given index.
 @param index The index of the segment to be removed.
 */
- (void)removeSegmentAtIndex:(int)index;

/**
 Inserts segment to the scale at given index.
 @param segment The segment to be added.
 @param index The index for the segment to be insert at.
 */
- (void)insertSegment:(TKGaugeSegment* __nonnull)segment atIndex:(int)index;

/**
 Returns segment from the scale by given index.
 @param index The index of the segment to be returned.
 */
- (TKGaugeSegment* __nullable)segmentAtIndex:(int)index;

/**
 Removes all segments from the scale.
 */
- (void)removeAllSegments;

/**
 Adds indicator to the scale.
 @param indicator The indicator to be added.
 */
- (void)addIndicator:(TKGaugeIndicator* __nonnull) indicator;

/**
 Removes indicator from the scale.
 @param indicator The indicator to be removed.
 */
- (void)removeIndicator:(TKGaugeIndicator* __nonnull) indicator;

/**
 Removes indicator from the scale by given index.
 @param index The index of the indicator to be removed.
 */
- (void)removeIndicatorAtIndex:(int)index;

/**
 Inserts indicator to the scale at given index.
 @param indicator The indicator to be added.
 @param index The index for the indicator to be insert at.
 */
- (void)insertIndicator:(TKGaugeIndicator* __nonnull)indicator atIndex:(int)index;

/**
 Returns indicator from the scale by given index.
 @param index The index of the indicator to be returned.
 */
- (TKGaugeIndicator* __nullable)indicatorAtIndex:(int)index;

/**
 Removes all indicators from the scale.
 */
- (void)removeAllIndicators;

@end
