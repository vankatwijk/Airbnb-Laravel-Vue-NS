//
//  TKCalendarMonthViewController_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//
#import "TKCalendarMonthViewController.h"

@class TKCalendarYearViewController;

@interface TKCalendarMonthViewController ()

/**
 The calendar view of the owner TKCalendarYearViewController.
 */
@property (nonatomic, weak) TKCalendarYearViewController *ownerController;

/**
 The selected date.
 */
@property (nonatomic, strong) NSDate *selectedDate;

@end