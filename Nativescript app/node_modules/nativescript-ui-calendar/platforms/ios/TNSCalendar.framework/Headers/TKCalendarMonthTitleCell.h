//
//  TKCalendarMonthTitleCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKCalendarTitleCell.h"

/**
 @enum TKCalendarMonthTitleCellLayoutMode
 @discussion Defines the layout mode in TKCalendarMonthTitleCell.
 */
typedef NS_OPTIONS(NSInteger, TKCalendarMonthTitleCellLayoutMode) {
    
    /**
     A month name and year number will be displayed.
     */
    TKCalendarMonthTitleCellLayoutModeMonth,
    
    /**
     A month name with previous and next buttons.
     */
    TKCalendarMonthTitleCellLayoutModeMonthWithButtons,
    
    /**
     A month name, year number and previous/next buttons.
     */
    TKCalendarMonthTitleCellLayoutModeMonthAndYearWithButtons
};

/**
 Represents a title cell used in TKCalendarMonthPresenter.
 */
@interface TKCalendarMonthTitleCell : TKCalendarTitleCell

/**
 The previous month button.
 */
@property (nonatomic, strong) UIButton * __nonnull previousMonthButton;

/**
 The next month button.
 */
@property (nonatomic, strong) UIButton * __nonnull nextMonthButton;

/**
 The previous year button.
 */
@property (nonatomic, strong) UIButton * __nonnull previousYearButton;

/**
 The previous year button.
 */
@property (nonatomic, strong) UIButton * __nonnull nextYearButton;

/**
 The year label.
 */
@property (nonatomic, strong, readonly) UILabel * __nonnull yearLabel;

/**
 The layout mode.
 
 @discussion The available layout modes are specified below:
 
 typedef enum {
    TKCalendarMonthTitleCellLayoutModeMonth,                  // A month name and year number will be displayed.
    TKCalendarMonthTitleCellLayoutModeMonthWithButtons        // A month name with previous and next buttons.
    TKCalendarMonthTitleCellLayoutModeMonthAndYearWithButotns // A month name, year number and previous/next buttons.
 } TKCalendarMonthTitleCellLayoutMode;
 */
@property (nonatomic) TKCalendarMonthTitleCellLayoutMode layoutMode;

@end
