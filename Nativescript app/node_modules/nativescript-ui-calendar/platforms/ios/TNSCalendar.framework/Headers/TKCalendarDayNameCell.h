//
//  TKCalendarDayNameCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarCell.h"

/**
 *  @discussion A calendar cell used to present week day names in TKCalendar.
 */
@interface TKCalendarDayNameCell : TKCalendarCell

/**
 *  Attaches a day offset and owner to the cell.
 *
 *  @param owner The owner for this cell, an instance of TKCalendar.
 *  @param index The 0 based day index that specifies the week day for the cell.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner withDayOffset:(NSInteger)index;

@end
