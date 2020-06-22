//
//  TKCalendarInlineView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKView.h"

@class TKCalendarDayCell;
@class TKCalendarMonthPresenter;

/**
 *@discussion A view responsible for displaying a list with inline evnets specific for a day cell in TKCalendarMonthPresenter.
 */
@interface TKCalendarInlineView : TKView <UITableViewDataSource, UITableViewDelegate>

/**
 The month presenter owner of this view.
 */
@property (nonatomic, weak) TKCalendarMonthPresenter * __nullable owner;

/**
 The table view contained in this view.
 */
@property (nonatomic, strong, readonly) UITableView * __nonnull tableView;

/**
 The day cell that is currently displayed.
 */
@property (nonatomic, weak) TKCalendarDayCell * __nullable dayCell;

/**
 The desired width when using in a popover controller.
 */
@property (nonatomic, assign) CGFloat desiredWidthInPopoverMode;

/**
 Determines the maximum height for the event list view.
 */
@property (nonatomic, assign) CGFloat maxHeight;

/**
 Determines the evnent row height.
 */
@property (nonatomic, assign) CGFloat rowHeight;

/**
 Determines whether the view height is fixed. 
 If yes, the view height is determined by the value of the maxHeight property.
 If not, the view height is determined by the events count.
 */
@property (nonatomic, assign) BOOL fixedHeight;

@end
