//
//  TKCalendarAllDayViewCell.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TKCalendar.h"
#import "TKCalendarDayView.h"
#import "TKCalendarDayViewAllDayEventCellStyle.h"

/**
 @discussion A TKCalendarDayViewAllDayEventCell object presents the content for a single event displayed in the TKCalendarDayViewAllDayEventsView eventsView collection view.
 */
@interface TKCalendarDayViewAllDayEventCell : UICollectionViewCell <TKCalendarDayViewEventCellProtocol>

/**
 The label that displays the title of the event.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel * label;

/**
 The displayed event.
 */
@property (nonatomic, weak, readonly, nullable) id<TKCalendarEventProtocol> event;

/**
 Provides settings to customize the appearance of the cell.
 */
@property (nonatomic, strong, readonly, nonnull) TKCalendarDayViewAllDayEventCellStyle * style;

/**
 Updates the displayed event.
 
 @param event The events that will be displayed.
 */
- (void)attachWithEvent:(id<TKCalendarEventProtocol> __nonnull)event;

@end
