//
//  TKCalendarDayViewEventsViewStyle.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

/**
 @discussion A class that represents KCalendarDayViewEventsView style.
 */
@interface TKCalendarDayViewEventsViewStyle : TKStyleNode

/**
 The bottom offset of the time line.
 */
@property (nonatomic) CGFloat bottomOffset;

/**
 The top offset of the time line.
 */
@property (nonatomic) CGFloat topOffset;

/**
 The time line labels left offset.
 */
@property (nonatomic) CGFloat labelOffset;

/**
 The spacing between the separator lines and the labels.
 */
@property (nonatomic) CGFloat separatorLeadingOffset;

/**
 The separators trailing offset.
 */
@property (nonatomic) CGFloat separatorTrailingOffset;

/**
 The text color of the labels.
 */
@property (nonatomic, nullable) UIColor * labelTextColor;

/**
 The text size of the labels.
 */
@property (nonatomic) CGFloat labelTextSize;

/**
 THe horizontal alignment of the time line labels.
 */
@property (nonatomic) NSTextAlignment labelTextAlignment;

/**
 The color of the separators.
 */
@property (nonatomic, nullable) UIColor * separatorColor;

/**
 The width of the separators.
 */
@property (nonatomic) CGFloat separatorWidth;

/**
 The physical spacing between separators for scale 1.
 */
@property (nonatomic) CGFloat separatorSpacing;

/**
 The minimum height of an event cell
 */
@property (nonatomic) CGFloat minEventHeight;

/**
 The spacing between events and labels.
 */
@property (nonatomic) CGFloat eventsLeadingOffset;

/**
 The events trailing offset.
 */
@property (nonatomic) CGFloat eventsTrailingOffset;

/**
 The horizontal spacing between stacked events.
 */
@property (nonatomic) CGFloat eventsSpacing;

/**
 Format the label time.
 */
@property (nonatomic, strong, nonnull) NSDateFormatter * labelFormatter;

@end


