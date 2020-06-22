//
//  TKCalendarYearPresenter.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendar.h"

@class TKCalendarYearPresenterStyle;
@class TKCalendarYearPresenter;

/**
 @discussion Allows customization of the day cells in TKCalendar in year mode.
 */
@protocol TKCalendarYearPresenterDelegate <NSObject>

@optional

/**
 Iterates over the day cells in year mode and allows change of their background color.
 
 @param calendar The calendar where this event occurs.
 @param year The year number.
 @param month The month number.
 @param date The date number.
 @param rect The rect where background should be drawn.
 */
- (void) calendar:(TKCalendar* __nullable)calendar drawBackgroundForYear:(NSInteger)year month:(NSInteger)month date:(NSInteger)date inRect:(CGRect)rect;

/**
 Iterates over the day cells in year mode and allows usage of custom text attributes to draw the date number.
 
 @param calendar The calendar where this event occurs.
 @param year The year number.
 @param month The month number.
 @param date The date number.
 */
- (NSDictionary* __nullable)calendar:(TKCalendar* __nullable)calendar textAttributesForYear:(NSInteger)year month:(NSInteger)month date:(NSInteger)date;

/**
 Returns the text that should be used to represent the specified month.
 
 @param calendar The calendar where this event occurs.
 @param presenter The year presenter that is used to present content in TKCalendar.
 @param year The year number.
 @param month The month number.
 */
- (NSString* __nullable)calendar:(TKCalendar* __nullable)calendar yearPresenter:(TKCalendarYearPresenter* __nonnull)presenter textForYear:(NSInteger)year month:(NSInteger)month;

@end

/**
 @discussion A calendar presenter responsible for rendering TKCalendar in year view mode.
 */
@interface TKCalendarYearPresenter : UIView <TKCalendarPresenter>

/**
 Defines the number of columns.
 */
@property (nonatomic) NSInteger columns;

/**
 The class for the cell responsible for presenting a single month in TKCalendarYearPresenter. TKCalendarMonthCell by default.
 */
@property (nonatomic, strong) Class __nonnull monthCellClass;

/**
 The class for the view responsible for presenting a year title in TKCalendarYearPresenter. TKCalendarYearTitleView by default.
 */
@property (nonatomic, strong) Class __nonnull titleViewClass;

/**
 Returns the presenter style. Use the style properties to customize the visual appearance of TKCalendar in year view mode.
 */
@property (nonatomic, strong, readonly) TKCalendarYearPresenterStyle* __nonnull style;

/**
 Returns the collection view used by this presenter.
 */
@property (nonatomic, strong, readonly) UICollectionView* __nonnull collectionView;

/**
 The delegate allowing control over the appereance of the year view.
 */
@property (nonatomic, weak, nullable) id<TKCalendarYearPresenterDelegate> delegate;

@end
