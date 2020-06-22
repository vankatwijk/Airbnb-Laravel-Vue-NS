//
//  TKCalendarDayViewPresenter.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TKCalendarPresenterBase.h"

@class TKCalendarDayViewPresenterStyle;
@class TKCalendarDayView;


/**
 *@discussion A calendar presenter responsible for rendering TKCalendar in day view display mode.
 */
@interface TKCalendarDayViewPresenter : TKCalendarPresenterBase

/**
 Determines whether the month name should be hidden.
 */
@property (nonatomic) BOOL titleHidden;

/**
 Determines whether day names should be hidden.
 */
@property (nonatomic) BOOL dayNamesHidden;

/**
 Determines whether week view should be hidden.
 */
@property (nonatomic) BOOL weekHidden;

/**
 Determines whether week numbers should be hidden.
 */
@property (nonatomic) BOOL weekNumbersHidden;

/**
 Determines whether weekends should be hidden.
 */
@property (nonatomic) BOOL weekendsHidden;

/**
 Gets the presenter style. Use the style properties to customize the visual appearance of TKCalendar in day view.
 */
@property (nonatomic, strong, readonly) TKCalendarDayViewPresenterStyle* __nonnull style;

/**
 Gets the presenter title view.
 */
@property (nonatomic, strong, readonly) UIView* __nonnull titleView;

/**
 Gets the presenter view that holds day names.
 */
@property (nonatomic, strong, readonly) UIView* __nonnull dayNamesView;

/**
 Gets the presenter view that holds week days.
 */
@property (nonatomic, strong, readonly) UIView* __nonnull weekView;

/**
 Gets the presenter view that displays events on a time line for specific date.
 */
@property (nonatomic, strong, readonly) TKCalendarDayView* __nonnull dayView;

/**
 Gets an instance of TKCalendar, the owner of this presenter class.
 */
@property (nonatomic, weak, readonly) TKCalendar* __nullable owner;

/**
 Returns the cell responsible for presenting the specified date (if it is currently displayed).
 
 @param date The date.
 
 @return An instance of TKCalendarDayCell which represents the date if successfull.
 */
- (TKCalendarDayCell* __nullable)cellForDate:(NSDate* __nonnull)date;

/**
 Creates a cell based on the specified cell type.
 
 @param cellType The type of the cell that is requested.
 */
- (TKCalendarCell* __nonnull)createCellWithType:(TKCalendarCellType)cellType;

@end
