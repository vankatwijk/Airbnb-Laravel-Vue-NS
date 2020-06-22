//
//  TKCalendarMonthNameCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarCell.h"

@class TKCalendarDayCellStyle;

/**
 * @enum TKCalendarMonthNameState
 * @discussion Represents an enum that defines the month name cell state.
 */
typedef NS_OPTIONS(NSInteger, TKCalendarMonthNameState) {
    
    /**
     *  The month is selected.
     */
    TKCalendarMonthNameStateSelected  = 1 << 0,
    
    /**
     *  The month is disabled (it is outside of the selectable range)
     */
    TKCalendarMonthNameStateDisabled  = 1 << 1,
};

/**
 @discussion A calendar cell used to present month names.
 */
@interface TKCalendarMonthNameCell : TKCalendarCell

/**
 *  The cell state.
 *  @discussion The available cell states are specified below:
 
 typedef enum TKCalendarMonthNameState {
 TKCalendarMonthNameStateSelected  // The month is selected
 TKCalendarMonthNameStateDisabled  // The month is disabled (it is outside of the selectable range)
 } TKCalendarYearNumberState
 
 */
@property (nonatomic) TKCalendarMonthNameState state;

/**
 Returns the date for this cell.
 */
@property (nonatomic, readonly, strong) NSDate* __nonnull date;

/**
 Attaches an owner and date to the cell.
 
 @param owner The owner, an instance of TKCalendar.
 @param date  The date for the cell.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner withDate:(NSDate* __nonnull)date;

@end
