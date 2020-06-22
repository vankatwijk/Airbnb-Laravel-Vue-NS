//
//  TKCalendarYearViewController.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendar.h"

@class TKCalendarMonthViewController;

@protocol TKCalendarYearViewControllerDelegate <NSObject>

- (void)navigatedToMonthViewController:(TKCalendarMonthViewController* __nonnull)monthViewController;

@end

/**
 @discussion A view controller containing TKCalendar in year view mode. Use this controller to create iOS 7 calendar style user experience.
 */
@interface TKCalendarYearViewController : UIViewController <TKCalendarDelegate>

/**
 */
@property (nonatomic, strong) id<TKCalendarYearViewControllerDelegate> __nullable delegate;

/**
 The today button used in the navigation bar for this view controller.
 */
@property (nonatomic, strong, readonly) UIBarButtonItem* __nonnull todayButton;

/**
 The calendar view contained in this view controller.
 */
@property (nonatomic, strong, readonly) TKCalendar* __nonnull contentView;

/**
 Returns the frame which represents the currently selected month (read-only).
 */
@property (nonatomic, readonly) CGRect selectedItemRect;

@end
