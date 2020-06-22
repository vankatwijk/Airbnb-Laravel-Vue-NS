//
//  TKCalendarMonthView.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKCalendar;
@class TKCalendarYearPresenter;
@class TKCalYearViewStyle;

/**
 @discussion A month view rendered by using a core graphics.
 */
@interface TKCalendarMonthView : UIView

/**
 Returns the date for this cell.
 */
@property (nonatomic, strong, readonly) NSDate* __nonnull date;

/**
 Attaches an owner and date to the view.
 
 @param owner     The view owner, an instance of TKCalendar.
 @param presenter The view presenter, an instance of TKCalendarYearPresenter.
 @param year      The year.
 @param month     The month.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner presenter:(TKCalendarYearPresenter* __nonnull)presenter withYear:(NSInteger)year andMonth:(NSInteger)month;

@end
