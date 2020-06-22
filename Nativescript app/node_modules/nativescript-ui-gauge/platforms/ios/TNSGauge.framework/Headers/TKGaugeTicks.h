//
//  TKGaugeTicks.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKFill;
@class TKStroke;
@class TKGaugeScale;

/**
 @enum TKGaugeTicksPosition
 @discussion Defines the position of the gauge ticks. Inner or outer the scale line. */
typedef NS_ENUM(NSInteger, TKGaugeTicksPosition)
{
    /**
     Ticks are inner the scale line.
     */
    TKGaugeTicksPositionInner,
    
    /**
     Ticks are outer the scale line.
     */
    TKGaugeTicksPositionOuter
};

/**
 A class representing the ticks in TKGaugeScale.
 */
@interface TKGaugeTicks : NSObject

/**
 Determines whether the ticks are hidden.
 */
@property (nonatomic) BOOL hidden;

/**
Defines the major ticks fill.
 */
@property (nonatomic, strong, nullable) TKFill* majorTicksFill;

/**
 Defines the major ticks stroke.
 */
@property (nonatomic, strong, nullable) TKStroke* majorTicksStroke;

/** 
 Defines the width of the major ticks. Its used if the ticks have fill set.
 */
@property (nonatomic) CGFloat majorTicksWidth;

/**
 Defines the width of the minor ticks. Its used if the ticks have fill set.
 */
@property (nonatomic) CGFloat minorTicksWidth;

/**
 Defines the minor ticks fill.
 */
@property (nonatomic, strong, nullable) TKFill *minorTicksFill;

/**
 Defines the minor ticks stroke.
 */
@property (nonatomic, strong, nullable) TKStroke *minorTicksStroke;

/**
 Ticks offset by the scale line.
 */
@property (nonatomic) CGFloat offset;

/**
Major ticks count.
 */
@property (nonatomic) int majorTicksCount;

/**
 Minor ticks count.
 */
@property (nonatomic) int minorTicksCount;

/**
Major ticks length.
 */
@property (nonatomic) CGFloat majorTicksLength;

/**
Minor ticks length.
 */
@property (nonatomic) CGFloat minorTicksLength;

/**
 Defines the position of the gauge ticks. Inner or outer the scale line.
 */
@property (nonatomic) TKGaugeTicksPosition position;

@end
