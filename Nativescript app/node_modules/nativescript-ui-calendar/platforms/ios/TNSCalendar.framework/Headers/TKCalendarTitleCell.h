//
//  TKCalendarTitleCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarCell.h"

/**
 *  @discussion A calendar cell used to present titles in TKCalendar.
 */
@interface TKCalendarTitleCell : TKCalendarCell

/**
 *  Attaches the cell with its owner and a text.
 *
 *  @param owner The cell owner, an instance of TKCalendar.
 *  @param text  The cell text.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner withText:(NSString* __nullable)text;

@end
