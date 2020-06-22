//
//  TKCalendarBasePresenter.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarPresenterBase.h"

@class TKCalendarMonthPresenterStyle;
@class TKCalendarDayCell;
@class TKCalendarMonthPresenter;
@class TKCalendarInlineView;
@class TKCalendarInlineViewTableViewCell;

/**
 @enum TKCalendarInlineEventsViewMode
 @discussion Defines the view mode for day evnets view which appears when tapping on a day cell in month presenter.
 */
typedef NS_ENUM(NSInteger, TKCalendarInlineEventsViewMode)
{
    /**
     Do not show day events list when tapping on a date cell. This is the default value.
     */
    TKCalendarInlineEventsViewModeNone,
    
    /**
     Show day events list in an inline view.
     */
    TKCalendarInlineEventsViewModeInline,
    
    /**
     Show day events in a popover view. Available for iPad user interface idiom.
     */
    TKCalendarInlineEventsViewModePopover,
};

/**
 @discussion The methods declared by the TKCalendarMonthPresenterDelegate protocol allow the adopting delegate to handle notifications specific for month presenter.
 */
@protocol TKCalendarMonthPresenterDelegate <TKCalendarPresenterDelegate>

@optional

/**
 Called when the month presenter has shown its inline events view.
 *
 @param presenter The presenter in which this event occurred.
 @param cell The cell which events will be displayed.
 */
- (void)monthPresenter:(TKCalendarMonthPresenter* __nonnull)presenter inlineEventsViewDidShowForCell:(TKCalendarDayCell* __nonnull)cell;

/**
 Called when the inline events view was hidden.
 *
 @param presenter The presenter in which this event occurred.
 @param cell The cell which events were displayed in the events view.
 */
- (void)monthPresenter:(TKCalendarMonthPresenter* __nonnull)presenter inlineEventsViewDidHideForCell:(TKCalendarDayCell* __nonnull)cell;

/**
 Called when a new event was selected in the inline events view.
 *
 @param presenter The presenter in which this event occurred.
 @param event The event that was selected.
 */
- (void)monthPresenter:(TKCalendarMonthPresenter* __nonnull)presenter inlineEventSelected:(id<TKCalendarEventProtocol> __nonnull)event;

/**
 Called when new cell for inline event is created.
 *
 @param presenter The presenter in which this event occurred.
 @param cell The cell which events were displayed in the events view.
 */
- (void)monthPresenter:(TKCalendarMonthPresenter* __nonnull)presenter updateVisualsForInlineEventCell:(TKCalendarInlineViewTableViewCell* __nonnull)cell;

@end

/**
 *@discussion A calendar presenter responsible for rendering TKCalendar in month view mode.
 */
@interface TKCalendarMonthPresenter : TKCalendarPresenterBase

/**
 Determines whether the month header (containing title and day names) should be sticky when navigating to a different month.
 */
@property (nonatomic) BOOL headerIsSticky;

/**
 Determines whether the month name should be hidden.
 */
@property (nonatomic) BOOL titleHidden;

/**
 Determines whether week numbers should be hidden.
 */
@property (nonatomic) BOOL weekNumbersHidden;

/**
 Determines whether day names should be hidden.
 */
@property (nonatomic) BOOL dayNamesHidden;

/**
 Determines whether weekends should be hidden.
 */
@property (nonatomic) BOOL weekendsHidden;

/**
 Determines whether equal week number should be used.
 If this property is set to NO, the month presenter will calculate its row count based on the displayed month.
 */
@property (nonatomic) BOOL equalWeekNumber;

/**
 Defines the view mode for day evnets view which appears when tapping on a day cell in month presenter.
 
 @discussion The available view modes are specified below:
 
 typedef enum {
 TKCalendarInlineEventsViewModeNone,         // Do not show day events list when tapping on a date cell. This is the default value.
 TKCalendarInlineEventsViewModeInline,       // Show day events list in an inline view.
 TKCalendarInlineEventsViewModePopover,      // Show day events in a popover view. Available for iPad user interface idiom.
 } TKCalendarInlineEventsViewMode;
 */
@property (nonatomic) TKCalendarInlineEventsViewMode inlineEventsViewMode;

/**
 Returns the events view responsible for presenting events when inline events are enabled.
 */
@property (nonatomic, strong) TKCalendarInlineView * __nonnull inlineEventsView;

/**
 Returns the presenter style. Use the style properties to customize the visual appearance of TKCalendar in month view.
 */
@property (nonatomic, strong, readonly) TKCalendarMonthPresenterStyle* __nonnull style;

/**
 Returns a view which contains date cells.
 */
@property (nonatomic, strong, readonly) UIView* __nonnull contentView;

/**
 Returns the header view which contains month name and week day names.
 */
@property (nonatomic, strong, readonly) UIView* __nonnull headerView;

/**
 *  Returns an instance of TKCalendar, the owner of this presenter class.
 */
@property (nonatomic, weak, readonly) TKCalendar* __nullable owner;

/**
 Returns a date at specific row and column
 
 @param row The row.
 @param col The column.
 
 @return An instance of NSDate if successfull.
 */

- (NSDate* __nonnull)dateForRow:(NSInteger)row col:(NSInteger)col;

/**
 Updates only the inline event view of the calendar.
 **/

-(void) updateInlineView;

/**
 Returns the cell responsible for presenting the specified date (if it is currently displayed).
 
 @param date The date.
 
 @return An instance of TKCalendarDayCell which represents the date if successfull.
 */
- (TKCalendarDayCell* __nullable)cellForDate:(NSDate* __nonnull)date;

/**
 Shows a new view containing all events for specific date.
 
 @param cell The cell that requested the inline view.
 @param animated Defines whether to use animation when showing the inline evnets list.
 */
- (void)showInlineEventsForCell:(TKCalendarDayCell* __nonnull)cell animated:(BOOL)animated;

/**
 Hides the inline events view if it is visible.

 @param animated Defines whether to use animation when hiding the inline evnets list.
 */
- (void)hideInlineEvents:(BOOL)animated;

/**
 Creates a cell based on the specified cell type.
 
 @param cellType The type of the cell that is requested.
 */
- (TKCalendarCell* __nonnull)createCellWithType:(TKCalendarCellType)cellType;

@end
