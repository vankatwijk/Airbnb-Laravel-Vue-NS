//
//  TKCalendarAllDayView.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TKCalendar.h"
#import "TKCalendarDayViewAllDayEventsViewStyle.h"

@class TKCalendarDayView;

/**
 @discussion View that displays the all-day events in TKCalendarDayView view.
 */
@interface TKCalendarDayViewAllDayEventsView : UIView

/**
 The collection view that displays the events.
 */
@property (nonatomic, strong, readonly, nonnull) UICollectionView * eventsView;

/**
 The all-day label.
 */
@property (nonatomic, strong, readonly, nonnull) UIView * labelView;

/**
 The date displayed by the TKCalendarDayView.
 */
@property (nonatomic, weak, readonly, nullable) NSDate * date;

/**
 The collection of all-day events displayed in the TKCalendarDayView.
 */
@property (nonatomic, weak, readonly, nullable) NSArray<id<TKCalendarEventProtocol>> * events;

/**
 Provides settings to customize the layout of the TKCalendarDayViewAllDayEventsView.
*/
@property (nonatomic, strong, readonly, nonnull) TKCalendarDayViewAllDayEventsViewStyle * style;

/**
 Updates the displayed events data.
 
 @param events The all-day events that will be displayed in the eventsView.
 @param date The displayed date.
 */
- (void)attachWithEvents:(NSArray<id<TKCalendarEventProtocol>> * __nullable)events forDate:(NSDate * __nullable)date;

/**
 Creates the label.
 
 @returns The label view.
 */
- (UIView * __nonnull)createLabelView;

/**
 Creates the collection view that displays the events.
 
 @returns The events view.
 */
- (UICollectionView * __nonnull)createEventsView;

/**
 Call this method to apply any changes that affect the layout of the events view.
 */
- (void)updateLayout;

@end
