//
//  TKGaugeSegment.h
//  TelerikUI
//
//  Copyright (c) 2015 г. Telerik. All rights reserved.
//

@class TKRange;
@class TKFill;
@class TKStroke;
@class TKGaugeScale;
@class TKGaugeIndicator;

/**
 @enum TKGaugeSegmentCap
 @discussion Defines weather the sides of the segment will be rounded or edgy.
 */
typedef NS_ENUM(NSInteger, TKGaugeSegmentCap)
{
    /**
     Sets the cap of the segment rounded.
     */
    TKGaugeSegmentCapRound,
    /**
     Sets the cap of the segment edgy.
     */
    TKGaugeSegmentCapEdge
};

/**
 Represents the view of a TKGaugeSegment.
 */
@interface TKGaugeSegment : CALayer

/**
 Allows interaction with the segment and changing its value.
 */
@property (nonatomic) BOOL allowTouch;

/**
 The scale that owns this segment.
 */
@property (nonatomic, weak, nullable) TKGaugeScale* owner;

/**
 An object representing the minimum and maximum value of the segment.
 */
@property (nonatomic, strong, nonnull) TKRange* range;

/**
 Represents the segment's fill.
 */
@property (nonatomic, strong, nullable) TKFill* fill;

/**
 Represents the segment's stroke.
 */
@property (nonatomic, strong, nullable) TKStroke* stroke;

/**
 Represents the segment's width on the left/upper side.
 */
@property (nonatomic) CGFloat width;

/**
 Represents the segment's width on the right/bottom side.
 */
@property (nonatomic) CGFloat width2;

/**
 Represents the location of the segment from bottom to top. The value could be from 0 to 1.
 */
@property (nonatomic) CGFloat location;

/**
 Defines weather the cap of the segment is round or edge.
 */
@property (nonatomic) TKGaugeSegmentCap cap;

/**
 Initializes segment with TKRange.
 @param range TKRange object definind the minimum and maximum value of the segment.
 */
- (instancetype __nonnull)initWithRange:(TKRange* __nonnull)range;

/**
 Initializes segment with minimum and maximum value.
 @param minimum The minimum value of the segment.
 @param maximum The maximum value of the segment.
 */
- (instancetype __nonnull)initWithMinimum:(id __nonnull)minimum maximum:(id __nonnull)maximum;

/**
 This method changes the range of the segment through animation.
 @param value The new range to be set.
 @param duration The duration of the animation.
 @param functionName The media timing function to be uset with the animation.
 */
- (void)setRangeAnimated:(TKRange* __nonnull)value withDuration:(CGFloat)duration mediaTimingFunction:(NSString* __nonnull)functionName;

@end
