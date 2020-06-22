//
//  TKCalendarMonthCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKCalendar;
@class TKCalendarMonthView;
@class TKCalendarYearPresenter;

/**
 @discussion A month within a year view in TKCalendar.
 */
@interface TKCalendarMonthCell : UICollectionViewCell

/**
 Returns the contained calendar cell instance.
 */
@property (nonatomic, strong, readonly) TKCalendarMonthView* __nonnull monthView;

/**
 Attaches an owner and date to this cell.
 
 @param owner        The owner, an instance of TKCalendar.
 @param presenter    The year presenter for the cell.
 @param year         The presented year.
 @param month        The presented month.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner presenter:(TKCalendarYearPresenter* __nonnull)presenter withYear:(NSInteger)year andMonth:(NSInteger)month;

@end
