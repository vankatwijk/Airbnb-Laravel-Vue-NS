//
//  TKCalendarDayCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarCell.h"

@class TKCalendarDayCellStyle;
@protocol TKCalendarEventProtocol;

/**
 * @enum TKCalendarDayState
 * @discussion Represents an enum that defines the date cell state.
 */
typedef NS_OPTIONS(NSInteger, TKCalendarDayState) {
    
    /**
     *  The date is today.
     */
    TKCalendarDayStateToday            = 1 << 0,
    
    /**
     *  The date represents a weekend.
     */
    TKCalendarDayStateWeekend          = 1 << 1,
    
    /**
     *  The date is contained within the currently presented month.
     */
    TKCalendarDayStateCurrentMonth     = 1 << 2,
    
    /**
     *  The date is contained within the currently presented year.
     */
    TKCalendarDayStateCurrentYear      = 1 << 3,
    
    /**
     *  The date is selected.
     */
    TKCalendarDayStateSelected         = 1 << 4,
    
    /**
     *  The date is the first date in a range selection.
     */
    TKCalendarDayStateFirstInSelection = 1 << 5,
    
    /**
     *  The date is the last date in a range selection.
     */
    TKCalendarDayStateLastInSelection  = 1 << 6,
    
    /**
     *  The date is a mid date in a range selection.
     */
    TKCalendarDayStateMidInSelection   = 1 << 7,
    
    /**
     * The date is outside of the selectable range and cannot be selected
     */
    TKCalendarDayStateDisabled         = 1 << 8,
    
};

/**
 *  @discussion A calendar cell used to present dates in TKCalendar.
 */
@interface TKCalendarDayCell : TKCalendarCell

/**
 *  The cell state.
 *  @discussion The available cell states are specified below:
 
 typedef enum TKCalendarDayState {
 TKCalendarDayStateToday            // The date is today
 TKCalendarDayStateWeekend          // The date represents a weekend.
 TKCalendarDayStateCurrentMonth     // The date is contained within the currently presented month.
 TKCalendarDayStateCurrentYear      // The date is contained within the currently presented year.
 TKCalendarDayStateSelected         // The date is selected.
 TKCalendarDayStateFirstInSelection // The date is the first date in a range selection.
 TKCalendarDayStateLastInSelection  // The date is the last date in a range selection.
 TKCalendarDayStateMidInSelection   // The date is a mid date in a range selection.
 TKCalendarDayStateDisabled         // The date is outside of the selectable range and cannot be selected
 } TKCalendarDayState

 */
@property (nonatomic) TKCalendarDayState state;

/**
 *  Attaches a date and owner to the cell.
 *
 *  @param owner The owner for this cell, an instance of TKCalendar.
 *  @param date  The date that will be presented by this cell.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner withDate:(NSDate* __nonnull)date;

/**
 *  Returns the cell style. Use the style property to customize the visual appearance of TKCalendarCell.
 */
- (TKCalendarDayCellStyle* __nonnull)style;

/**
 *  Returns the date represented by this cell.
 */
@property (nonatomic, strong, readonly) NSDate* __nonnull date;

/**
 *  Returns an array containing all events for this cell.
 */
@property (nonatomic, strong, readonly) NSArray* __nonnull events;

/**
 * Called to draw the events specific for this cell.
 *
 * @param context The graphics context to use when drawing events.
 * @param rect The rectangle to draw.
 */
- (void)drawEvents:(CGContextRef __nonnull)context rect:(CGRect)rect;

/**
 * Returns the state based on the specified date.
 *
 * @param date The date which state is requested.
 */
- (TKCalendarDayState)stateForDate:(NSDate* __nonnull)date;

/**
 * Returns the text that should be displayed for the specified event.
 *
 * @param event The event which text is requested.
 */
- (NSString* __nullable)textForEvent:(id<TKCalendarEventProtocol> __nonnull)event;

/**
 * Returns the text attributes for the specified event.
 *
 * @param event The event which attributes are requested.
 */
- (NSDictionary* __nullable)textAttributesForEvent:(id<TKCalendarEventProtocol> __nonnull)event;

@end
