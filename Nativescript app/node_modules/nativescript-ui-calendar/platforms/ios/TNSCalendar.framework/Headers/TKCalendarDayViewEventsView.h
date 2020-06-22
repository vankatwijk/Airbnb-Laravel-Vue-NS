//
//  TKCalendarEventsCell.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TKCalendarDayViewEventsViewStyle.h"
#import "TKCalendar.h"

@class TKCalendarDayView;

/**
 @discussion Custom collection view that displays day events in TKCalendarDayView. The class should be initialized with TKCalendarDayViewEventsLayout that implements the logic required to arrange the events on a time line.
 */
@interface TKCalendarDayViewEventsView : UICollectionView 

/**
 The displayed events.
 */
@property (nonatomic, weak, readonly, nullable) NSArray<id<TKCalendarEventProtocol>> * events;

/**
 The displayed date.
 */
@property (nonatomic, weak, readonly, nullable) NSDate * date;

/**
 The calendar.
 */
@property (nonatomic, weak, readonly, nullable) NSCalendar * calendar;

/**
 Provides settings to customize the appearance of the TKCalendarDayViewEventsView.
 */
@property (nonatomic, strong, readonly, nonnull) TKCalendarDayViewEventsViewStyle * style;

/**
 The scale of the timeline used to modify the physical distance between hours. The user can change the scale with pinch gesture.
 */
@property (nonatomic) CGFloat zoom;

/**
 The start time of the time line in seconds.
 */
@property (nonatomic) NSTimeInterval startTime;

/**
 The end time of the time line in seconds.
 */
@property (nonatomic) NSTimeInterval endTime;

/**
 The time distance between separators in seconds.
 */
@property (nonatomic) NSTimeInterval interval;

/**
 Specifies whether the time line can be zoomed.
 */
@property (nonatomic) bool allowZoom;

/**
 The minimum zoom factor of the time line.
 */
@property (nonatomic) CGFloat minZoom;

/**
 The maximum zoom factor of the time line.
 */
@property (nonatomic) CGFloat maxZoom;

/**
 Updates the displayed events data.
 
 @param events The all-day events that will be displayed in the eventsView.
 @param date The displayed date.
 @param calendar The calendar.
 */
- (void)attachWithEvents:(NSArray<id<TKCalendarEventProtocol>> * __nullable)events forDate:(NSDate * __nullable)date withCalendar:(NSCalendar* __nonnull)calendar;

/**
 Returns the label text for specific time interval.
 
 @param interval The time interval in seconds that correspond to the time of the day.
 
 @returns The label.
 */
- (NSString * __nonnull)labelForTimeInterval:(NSTimeInterval)interval;

/**
 Returns the offset for the specified date components. The offset is between 0 and 1.
 
 @param components The date components used to provide information about the time of the day.
 
 @returns The offset.
 */
- (CGFloat)offsetForComponents:(NSDateComponents * __nonnull)components;

/**
 Returns the offset for the specified time. The offset is between 0 and 1.
 
 @param hour The hour of the day.
 @param minute The munite of the day.
 @param second The second of the day.
 
 @returns The offset.
 */
- (CGFloat)offsetForHour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second;

/**
 Calculates the height of the time line. This is not the height of the scrollable content.
 */
- (CGFloat)timeLineHeight;

/**
 Returns the number of time slots.
 */
- (CGFloat)slotsCount;

/**
 Returns the size of the time line labels.
 */
- (CGSize)labelSize;

/**
 Returns collection of all time line labels.
 */
- (NSArray<NSAttributedString *>* __nonnull)labels;

/**
 Call this method to apply any changes in the view style or settings.
 */
- (void)updateLayout;

//- (void)scrollToHour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second animated:(BOOL)animated;

@end
