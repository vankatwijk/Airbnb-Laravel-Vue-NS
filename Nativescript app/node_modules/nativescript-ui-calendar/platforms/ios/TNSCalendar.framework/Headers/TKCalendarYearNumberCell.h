//
//  TKCalendarYearNumberCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarCell.h"

/**
 * @enum TKCalendarYearNumberState
 * @discussion Represents an enum that defines the year number cell state.
 */
typedef NS_OPTIONS(NSInteger, TKCalendarYearNumberState) {
    
    /**
     *  The year is selected.
     */
    TKCalendarYearNumberStateSelected  = 1 << 0,
    
    /**
     *  The year is disabled (it is outside of the selectable range)
     */
    TKCalendarYearNumberStateDisabled  = 1 << 1,
};

/**
 @discussion A calendar cell used to present year numbers.
 */
@interface TKCalendarYearNumberCell : TKCalendarCell

/**
 *  The cell state.
 *  @discussion The available cell states are specified below:
 
 typedef enum TKCalendarYearNumberState {
 TKCalendarYearNumberStateSelected  // The year is selected
 TKCalendarYearNumberStateDisabled  // The year is disabled (it is outside of the selectable range)
 } TKCalendarYearNumberState
 
 */
@property (nonatomic) TKCalendarYearNumberState state;

/**
 Returns the date for this cell.
 */
@property (nonatomic, strong, readonly) NSDate* __nonnull date;

/**
 Attaches an owner and date to the cell.
 
 @param owner The owner, an instance of TKCalendar.
 @param date  The date for the cell.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner withDate:(NSDate* __nonnull)date;

@end
