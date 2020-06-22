//
//  TKCalendarView.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TNSCore/TKView.h"

@class TKDateRange;
@class TKTheme;
@class TKCalendarCell;
@class TKCalendarDayCell;
@class TKCalendar;

/**
 @enum TKCalendarViewMode
 @discussion Defines the view mode of the calendar component.
 */
typedef NS_ENUM(NSInteger, TKCalendarViewMode)
{
    /**
     A single week will be presented in calendar component.
     */
    TKCalendarViewModeWeek,
    
    /**
     A single month will be presented in calendar component.
     */
    TKCalendarViewModeMonth,
    
    /**
     A list of month names will be presented in calendar component.
     */
    TKCalendarViewModeMonthNames,
    
    /**
     A list with years, months and dates will be presented in calendar component.
     */
    TKCalendarViewModeYear,
    
    /**
     A list with year numbers will be presented in calendar component.
     */
    TKCalendarViewModeYearNumbers,
    
    /**
     A continious list with months will be presented in calendar component.
     */
    TKCalendarViewModeFlow,
    
    /**
     A single week with information for selected day events will be presented in calendar component.
     */
    TKCalendarViewModeDay
};

/**
 @enum TKCalendarSelectionMode
 @discussion Defines the selection mode of the calendar component.
 */
typedef NS_ENUM(NSInteger, TKCalendarSelectionMode) {
    
    /**
     No selection is allowed.
     */
    TKCalendarSelectionModeNone,
    
    /**
     A single date can be selected by tapping on it.
     */
    TKCalendarSelectionModeSingle,
    
    /**
     Multiple dates can be selected with a tap. A second tap will deselect a selected date.
     */
    TKCalendarSelectionModeMultiple,
    
    /**
     Range of dates can be se selected by using a swipe gesture.
     */
    TKCalendarSelectionModeRange,
    
};

/**
 @enum TKCalendarCellType
 @discussion Defines the cell types used in calendar component.
 */
typedef NS_ENUM(NSInteger, TKCalendarCellType) {
    
    /**
     A cell responsible for presenting a date.
     */
    TKCalendarCellTypeDay,
    
    /**
     A cell responsible for presenting a week day name.
     */
    TKCalendarCellTypeDayName,
    
    /**
     A cell responsible for presenting a week number.
     */
    TKCalendarCellTypeWeekNumber,
    
    /**
     A cell responsible for presenting a title.
     */
    TKCalendarCellTypeTitle,
    
    /**
     A cell responsible for presenting a month name.
     */
    TKCalendarCellTypeMonthName,
    
    /**
     A cell responsible for presenting a year number.
     */
    TKCalendarCellTypeYearNumber,
};

/**
 @discussion The TKCalendarEventProtocol protocol is adopted by an object that represents a single event in TKCalendar. Its default implementation is TKCalendarEvent
 */
@protocol TKCalendarEventProtocol <NSObject>

/**
 The start time for the event.
 */
@property (nonatomic, strong) NSDate * __nonnull startDate;

/**
 The end time for the event.
 */
@property (nonatomic, strong) NSDate * __nonnull endDate;

/**
 The event title.
 */
@property (nonatomic, strong) NSString * __nullable title;

/**
 The event details.
 */
@property (nonatomic, strong) NSString * __nullable detail;

/**
 Defines the event color.
 */
@property (nonatomic, strong) UIColor * __nullable eventColor;

/**
 Indicates whether the event is an all day event or not.
 */
@property (nonatomic, getter = isAllDay) BOOL allDay;

@end

/**
 @discussion The methods declared by the TKCalendarDelegate protocol allow the adopting delegate to respond to messages from the TKCalendar class and thus respond to, and in some affect, operations such as selection, navigation and customizing the visual appearance.
 */
@protocol TKCalendarDelegate <NSObject>

@optional

/**
 Returns a boolean value indicating whether the specified date can be selected.
 
 @param calendar The calendar component instance requesting this information.
 @param date The date which is about to be selected.
 
 @return YES if the date can be selected.
 */
- (BOOL)calendar:(TKCalendar* __nonnull)calendar shouldSelectDate:(NSDate* __nonnull)date;

/**
 Called after selecting a date.
 
 @param calendar The calendar component for which the selection occurred.
 @param date The date that was selected.
 */
- (void)calendar:(TKCalendar* __nonnull)calendar didSelectDate:(NSDate* __nonnull)date;

/**
 Called after deselecting a date.
 
 @param calendar The calendar component for which the selection change occurred.
 @param date The date that was deselected.
 */
- (void)calendar:(TKCalendar * __nonnull)calendar didDeselectedDate:(NSDate * __nonnull)date;

/**
 *  Called before navigating to specific date.
 *
 *  @param calendar The calendar component where navigation occurs.
 *  @param date     The date which is about to be displayed.
 */
- (void)calendar:(TKCalendar* __nonnull)calendar willNavigateToDate:(NSDate * __nonnull)date;

/**
 *  Called after navigating to specific date.
 *
 *  @param calendar The calendar component where navigation occurred.
 *  @param date     The date that was displayed.
 */
- (void)calendar:(TKCalendar* __nonnull)calendar didNavigateToDate:(NSDate* __nonnull)date;

/**
 Called after view mode has changed.
 *
 @param calendar The calendar component for which the view mode was changed.
 @param previousViewMode The previous view mode.
 @param viewMode The actual view mode.
 */
- (void)calendar:(TKCalendar * __nonnull)calendar didChangedViewModeFrom:(TKCalendarViewMode)previousViewMode to:(TKCalendarViewMode)viewMode;

/**
 Returns an instance of TKCalendarCell specific for the requested cell type.
 
 @param calendar The calendar instance requesting this information.
 @param cellType The cell type which determines the TKCalendarCell instance.
 *
 @return An instance of TKCalendarCell if the cell should be customized, nil otherwise.
 */
-   (TKCalendarCell* __nullable)calendar:(TKCalendar* __nonnull)calendar viewForCellOfKind:(TKCalendarCellType)cellType;

/**
 *  Called when a cell needs to update its visual state.
 *
 *  @param calendar The calendar component where the cell state was changed.
 *  @param cell     The cell that has changed its state.
 */
- (void)calendar:(TKCalendar * __nonnull)calendar updateVisualsForCell:(TKCalendarCell* __nonnull)cell;

/**
 *  Called when a cell has been tapped.
 *
 *  @param calendar The calendar component where the cell was tapped.
 *  @param cell     The cell that was tapped.
 */
- (void)calendar:(TKCalendar * __nonnull)calendar didTapCell:(TKCalendarDayCell* __nonnull)cell;

/**
 Called when a cell needs to display a shape for event.
 
 @param calendar The calendar component where the event shapeis requested.
 @param event The event.
 */
- (TKShape* __nullable)calendar:(TKCalendar * __nonnull)calendar shapeForEvent:(id<TKCalendarEventProtocol> __nonnull)event;

/**
 Called when a cell needs to display text for event.
 
 @param calendar The calendar component where the event shapeis requested.
 @param event The event.
 */
- (NSString* __nullable)calendar:(TKCalendar *__nonnull)calendar textForEvent:(id<TKCalendarEventProtocol> __nonnull)event;

@end


/**
 @discussion The TKCalendarDataSource protocol is adopted by an object that mediates the application's data model for a TKCalendar object.
 The data source provides the calendar object with events.
 */
@protocol TKCalendarDataSource <NSObject>

@optional

/**
 Returns an array with events for specific date.
 
 @param calendar The calendar instance requesting this information.Otkca
 @param date The date for which to retrieve events.
 
 @return An array containing instances of objects adopting the TKCalendarEventProtocol protocol.
 */
- (NSArray* __nullable)calendar:(TKCalendar* __nonnull)calendar eventsForDate:(NSDate* __nonnull)date;

/**
 *  Asks the data source for an array of objects adopting the TKCalendarEventProtocol protocol with a callback.
 *
 *  @param calendar       The calendar instance requesting this information.
 *  @param startDate      The start date for which to retrieve events.
 *  @param endDate        The end date for wihich to retrieve events.
 *  @param eventsCallback The callback block that should be called after retrieving all events for the specified period.
 */
- (void)calendar:(TKCalendar* __nonnull)calendar eventsFromDate:(NSDate* __nonnull)startDate toDate:(NSDate* __nonnull)endDate withCallback:(void (^ __nullable)(NSArray* __nullable events))eventsCallback;

@end



/**
 @discussion The TKCalendarPresenter protocol is adopted by an object that displays the calendar component in specific view mode.
 */
@protocol TKCalendarPresenter <NSObject>

/**
 Called when the presenter should update its content. (e.g. navigation has occurred)
 
 @param reset Determines whether all visual elements should be reset.
 */
- (void)update:(BOOL)reset;

/**
 Called when the presenter should update all states. (e.g. a different date was selected)
 
 @param lastSelected The last selected date.
 */
- (void)updateState:(NSDate* __nonnull)lastSelected;

/**
 The presenter should navigate one screen forward based on its context. Do not call this method directly, use TKCalendar.navigateForward instead.
 
 @param animated Specifies whether to use animation when navigating.
 *
 @return YES if navigation was scuccessfull.
 */
- (BOOL)navigateForward:(BOOL)animated;

/**
 The presenter should navigate one screen backward based on its context. Do not call this method directly, use TKCalendar.navigateBack instead.
 
 @param animated Specifies whether to use animation when navigating.
 
 @return YES if navigation was scuccessfull.
 */
- (BOOL)navigateBack:(BOOL)animated;

/**
 The presenter should navigate to specific date. Do not call this method directly, use TKCalendar.navigateTodate:animated: instead.
 *
 @param date The date to which the presenter should navigate.
 @param animated Specifies whether to use animation when navigating.
 */
- (void)navigateToDate:(NSDate* __nonnull)date animated:(BOOL)animated;

/**
 Returns a date based on the provided coordinates.
 
 @param pt The coordinates for the requested date.
 
 @return An instance of NSDate if successful, nil otherwise.
 */
- (NSDate* __nullable)dateFromPoint:(CGPoint)pt;

@end



/**
 @discussion TKCalendar is a highly customizable calendar component with year, month and week views. Different transition effects are available when switching between calendar screens and view modes. The API allows customizing almost every aspect of the visual appearance by using custom cells and styles.
 */
@interface TKCalendar : TKView

/**
 A delegate for styling the calendar component and receiving notifications.
 */
@property (nonatomic, weak, nullable) id<TKCalendarDelegate> delegate;

/**
 A data-source delegate used to provide events for calendar cells.
 */
@property (nonatomic, weak, nullable) id<TKCalendarDataSource> dataSource;

/**
 The minimal date that will be visible when navigating between calendar screens.
 */
@property (nonatomic, strong, nullable) NSDate* minDate;

/**
 The maximal date that will be visible when navigating between calendar screens.
 */
@property (nonatomic, strong, nullable) NSDate* maxDate;

/**
 The currently selected date. Use this property when the selectionMode is set to a single selection.
 */
@property (nonatomic, strong, nullable) NSDate* selectedDate;

/**
 An array of selected dates. Use this property when the selectionMode is set to allow selecting multiple dates.
 */
@property (nonatomic, strong, nullable) NSArray* selectedDates;

/**
 A date range. Use this property when the selectionMode is set to a range.
 */
@property (nonatomic, strong, nullable) TKDateRange* selectedDatesRange;

/**
 Defines the current selction mode.
 
 @discussion The available selection modes are specified below:
 
 typedef enum {
 TKCalendarSelectionModeNone,       // no selection is allowed
 TKCalendarSelectionModeSingle,     // a single date can be selected
 TKCalendarSelectionModeMultiple,   // the user can select different dates by tapping on them. A second tap will deselect the date
 TKCalendarSelectionModeRange,      // the user can select a range between two dates by using a swipe gesture
 } TKCalendarSelectionMode;
 
 */
@property (nonatomic) TKCalendarSelectionMode selectionMode;

/**
 The calendar that will be used when handling dates within the component.
 */
@property (nonatomic, strong) NSCalendar* __nonnull calendar;

/**
 The locale which determines month and week days text representation.
 */
@property (nonatomic, strong) NSLocale * __nullable locale;

/**
 Defines the calendar view mode.
 
 @discussion The available view modes are specified below:
 
 typedef enum {
 TKCalendarViewModeWeek,            // the calendar component displays a single week
 TKCalendarViewModeMonth,           // the calendar component displays a single month with its dates
 TKCalendarViewModeMonthNames,      // the calendar component displays a list with month names
 TKCalendarViewModeYear,            // the calendar component displays years with months and dates
 TKCalendarViewModeYearNumbers,     // the calendar component displays a list with year numbers
 TKCalendarViewModeFlow,            // the calendar component displays a continious list with months
 } TKCalendarViewMode;
 
 */
@property (nonatomic) TKCalendarViewMode viewMode;

/**
 Defines whether a pinch gesture is enabled to switch between month, month names and year numbers view modes.
 */
@property (nonatomic) BOOL allowPinchZoom;

/**
 The calendar theme. Currenlty there are two themes available: the default one and an ipad theme.
 */
@property (nonatomic, strong) TKTheme * __nonnull theme;

/**
 Returns the presenter that is responsible for displaying the calendar in the selected view mode
 
 @return An instance of a class that implements TKCalendarPresenter.
 */
@property (nonatomic, strong, readonly) id<TKCalendarPresenter> __nonnull presenter;

/**
 Returns the date that is currently displayed in calendar.
 
 @return An instance of NSDate.
 */
@property (nonatomic, strong, readonly) NSDate* __nonnull displayedDate;

/**
 Returns the version of the calendar.
 */
+ (NSString* __nonnull)versionString;

/**
 Creates a date by specifying its year, month and day. The calendar argument is optional. If it is nil, the current calendar will be used.
 
 @param year     The year.
 @param month    The month.
 @param day      The day.
 @param calendar The calendar to be used when creating this date. The current calendar will be used if this argument is nil.
 
 @return An instance of NSDate if successfull.
 */
+ (NSDate* __nonnull)dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day withCalendar:(NSCalendar* __nullable)calendar;

/**
 Compares two dates by using only the specified components. Nonspecified components will be ignored.
 
 @param date1      The first date to compare.
 @param date2      The second date to compare.
 @param components The components to be used when comparing the two dates.
 @param calendar   The calendar to be used when comparing the two dates. The current calendar will be used if this argument is nil.
 
 @return YES if the dates are equal. NO otherwise.
 */
+ (BOOL)isDate:(NSDate* __nonnull)date1 equalToDate:(NSDate* __nonnull)date2 withComponents:(NSCalendarUnit)components withCalendar:(NSCalendar* __nullable)calendar;

/**
 Navigates to the next screen in current view mode context.
 
 @param animated Defines whether to use animation when navigating.
 */
- (void)navigateForward:(BOOL)animated;

/**
 Navigates to the previous screen in the current view mode context.
 
 @param animated Defines whether to use animation when navigating.
 */
- (void)navigateBack:(BOOL)animated;

/**
 Navigates to the specified date.
 
 @param date     The date that should be visible in calendar.
 @param animated Defines whether to use animation when navigating.
 */
- (void)navigateToDate:(NSDate* __nonnull)date animated:(BOOL)animated;

/**
 Clears calendar's selection.
 */
- (void)clearSelection;

/**
 Reloads all events in the calendar and resets the selection.
 */
- (void)reloadData;

/**
 Returns the events for a specific date.
 
 @param date The date.
 
 @return An array with events if scuccessfull.
 */
- (NSArray* __nonnull)eventsForDate:(NSDate* __nonnull)date;

@end
