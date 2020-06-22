//
//  TKCalendarMonthViewController.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendar.h"

/**
 @discussion A view controller containing TKCalendar in month view mode inside. This class is used internally.
 */
@interface TKCalendarMonthViewController : UIViewController

/**
 The calendar view contained in this view controller.
 */
@property (nonatomic, strong, readonly) TKCalendar* __nonnull contentView;

/**
 The today button used in the navigation bar for this view controller.
 */
@property (nonatomic, strong, readonly) UIBarButtonItem* __nonnull todayButton;

@end

