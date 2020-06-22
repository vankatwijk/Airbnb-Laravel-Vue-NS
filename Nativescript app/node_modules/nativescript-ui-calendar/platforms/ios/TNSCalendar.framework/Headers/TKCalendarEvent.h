//
//  TKCalendarEvent.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendar.h"

/**
 @discussion Represents an event used in TKCalendar class.
 */
@interface TKCalendarEvent : NSObject <TKCalendarEventProtocol>

/**
 The event id.
 */
@property (nonatomic, readonly) NSUInteger eventId;

/**
 The start time for the event.
 */
@property (nonatomic, strong) NSDate * __nonnull startDate;

/**
 The end time for the event.
 */
@property (nonatomic, strong) NSDate * __nonnull endDate;

/**
 The event title.
 */
@property (nonatomic, strong) NSString * __nullable title;

/**
 Defines the event color.
 */
@property (nonatomic, strong) UIColor * __nullable eventColor;

/**
 Indicates whether the event is an all day event or not.
 */
@property (nonatomic, getter = isAllDay) BOOL allDay;

/**
 The event location.
 */
@property (nonatomic, strong) NSString * __nullable location;

/**
 Additional information about the event.
 */
@property (nonatomic, strong) NSString * __nullable detail;

/**
 The event description.
 */
@property (nonatomic, strong) NSString * __nullable content;

@end
