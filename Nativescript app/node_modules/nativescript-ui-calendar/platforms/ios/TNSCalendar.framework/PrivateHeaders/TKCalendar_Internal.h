//
//  TKCalendarView_Internal.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendar.h"
#import "TKViewTransition.h"

@interface TKCalendar ()

- (NSInteger)daysInWeek;

- (NSInteger)weeksInMonth:(NSInteger)offset;

- (BOOL)isWeekend:(NSInteger)dayInWeek;

- (BOOL)isDate:(NSDate*)date1 equalToDate:(NSDate*)date2 withComponents:(NSCalendarUnit)components;

- (BOOL)isDateSelected:(NSDate*)date;

- (void)setViewMode:(TKCalendarViewMode)viewMode animate:(BOOL)animate direction:(TKViewTransitionDirection)direction interactive:(BOOL)interactive;

- (void)setDisplayedDate:(NSDate *)date update:(BOOL)shouldUpdate;

- (void)setSelectedDatesRange:(TKDateRange*)dateRange lastSelected:(NSDate*)lastDate;

- (BOOL)isValidDate:(NSDate*)date;

- (NSDate*)dateWithOffset:(NSInteger)days months:(NSInteger)months fromDate:(NSDate*)date;

- (void)update:(BOOL)reset;

@end