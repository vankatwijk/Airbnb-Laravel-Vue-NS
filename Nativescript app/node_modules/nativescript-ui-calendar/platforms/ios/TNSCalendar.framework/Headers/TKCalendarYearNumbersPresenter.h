//
//  TKCalendarYearNumbersPresenter.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarPresenterBase.h"

/**
 @discussion A calendar presenter responsible for rendering TKCalendar in year numbers view mode.
 */
@interface TKCalendarYearNumbersPresenter : TKCalendarPresenterBase

/**
 Defines the number of columns.
 */
@property (nonatomic) NSInteger columns;

/**
 Defines the number of rows.
 */
@property (nonatomic) NSInteger rows;

@end
