//
//  TKCalendarDayViewEventsViewCell.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TKCalendar.h"
#import "TKCalendarDayView.h"
#import "TKCalendarDayViewEventCellStyle.h"

/**
 @discussion A TKCalendarDayViewEventCell object presents the content for a single event displayed in the TKCalendarDayViewventsView collection view.
 */
@interface TKCalendarDayViewEventCell : UICollectionViewCell <TKCalendarDayViewEventCellProtocol>

/**
 Provides settings to customize the appearance of the cell.
 */
@property (nonatomic, strong, readonly, nonnull) TKCalendarDayViewEventCellStyle * style;

/**
 The displayed event.
 */
@property (nonatomic, weak, readonly, nullable) id<TKCalendarEventProtocol> event;

/**
 Updates the displayed event.
 
 @param event The events that will be displayed.
 */
- (void)attachWithEvent:(id<TKCalendarEventProtocol> __nonnull)event;

@end
