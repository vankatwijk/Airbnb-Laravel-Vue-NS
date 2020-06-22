//
//  TKCalMonthCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKCalendarCellStyle;
@class TKCalendar;

/**
 *  @discussion Represents a base class for cells used in TKCalendar.
 */
@interface TKCalendarCell : UIView

/**
 *  A label used to display the cell text.
 */
@property (nonatomic, strong, readonly) UILabel * __nonnull label;

/**
 *  An instance of TKCalendar, the owner of this object.
 */
@property (nonatomic, weak) TKCalendar* __nullable owner;

/**
 *  Returns the cell style. Use the style property to customize the visual appearance of TKCalendarCell.
 */
- (TKCalendarCellStyle* __nonnull)style;

/**
 *  Updates the visual appearance of the cell based on its content.
 */
- (void)updateVisuals;

/**
 Applies the style specified by its argument to the cell.
 
 @param state the state that defines the style to apply
 .
 */
- (void)applyStyleForState:(NSInteger)state;

@end
