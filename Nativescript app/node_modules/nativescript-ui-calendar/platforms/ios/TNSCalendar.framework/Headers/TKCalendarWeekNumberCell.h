//
//  TKCalendarWeekNumberCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarCell.h"

/**
 *  @discussion A calendar cell used to present week numbers
 */
@interface TKCalendarWeekNumberCell : TKCalendarCell

/**
 *  Attaches an owner and a week number to the cell.
 *
 *  @param owner      The cell owner, an instance of TKCalendar.
 *  @param weekNumber The week number within the year.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner withWeekNumber:(NSInteger)weekNumber;

@end
