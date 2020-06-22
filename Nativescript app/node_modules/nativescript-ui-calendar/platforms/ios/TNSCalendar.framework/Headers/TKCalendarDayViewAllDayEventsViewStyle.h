//
//  TKCalendarDayViewAllDayEventsViewStyle.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

/**
 @discussion A class that defines layout parameters for TKCalendarDayViewAllDayEventsView.
 */
@interface TKCalendarDayViewAllDayEventsViewStyle : TKStyleNode

/**
 Specifies the max number of event columns.
 */
@property (nonatomic) NSInteger eventsPerRow;

/**
 The spacing between event rows.
 */
@property (nonatomic) CGFloat lineSpacing;

/**
 The spacing between events in a row.
 */
@property (nonatomic) CGFloat itemSpacing;

/**
 The event cell height.
 */
@property (nonatomic) CGFloat eventHeight;

/**
 The maximum visible rows in the events view.
 */
@property (nonatomic) CGFloat maxVisibleLines;

/**
 The events view margins.
 */
@property (nonatomic) UIEdgeInsets eventsViewInsets;

/**
 The all-day label margins.
 */
@property (nonatomic) UIEdgeInsets labelInsets;

/**
 The all-day label width.
 */
@property (nonatomic) CGFloat labelWidth;


@end
