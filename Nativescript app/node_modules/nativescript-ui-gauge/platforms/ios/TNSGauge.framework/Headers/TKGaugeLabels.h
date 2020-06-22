//
//  TKGaugeLabels.h
//  TelerikUI
//
//  Copyright (c) 2015 г. Telerik. All rights reserved.
//

@class TKGaugeScale;
@class TKRange;

/**
 @enum TKGaugeLabelsPosition
 @discussion Defines the position of the gauge labels. Inner or outer the scale line. 
 */
typedef NS_ENUM(NSInteger, TKGaugeLabelsPosition)
{
    /**
     Labels are positioned on the inside of the scale line.
     */
    TKGaugeLabelsPositionInner,
    
    /**
     Labels are positioned on the outside of the scale line.
     */
    TKGaugeLabelsPositionOuter
};

/**
A class representing the labels in TKGaugeScale.
 */
@interface TKGaugeLabels : NSObject

/**
 Determines whether the labels are hidden.
 */
@property (nonatomic) BOOL hidden;

/**
 Defines the font of TKGaugeScale labels.
 */
@property (nonatomic, strong, nullable) UIFont* font;

/**
 The label's text color.
 */
@property (nonatomic, strong, nullable) UIColor* color;

/**
Labels offset by the scale line.
 */
@property (nonatomic) CGFloat offset;

/**
 Defines a text formatter that preserves the labelFormat property.
 */
@property (nonatomic, strong, nullable) NSFormatter* formatter;

/**
Defines the string formatter that will affect all the scale labels.
 */
@property (nonatomic, strong, nullable) NSString *labelFormat;

/**
Labels count.
 */
@property (nonatomic) NSInteger count;

/**
 Defines the position of the gauge labels. Inner or outer the scale line.
 */
@property (nonatomic) TKGaugeLabelsPosition position;

@end
