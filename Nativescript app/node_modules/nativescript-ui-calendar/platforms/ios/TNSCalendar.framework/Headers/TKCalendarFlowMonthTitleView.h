//
//  TKCalendarFlowMonthTitleView.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKCalendarTitleCell;
@class TKCalendar;

/**
 @discussion A title cell used in flow view in TKCalendar.
 */
@interface TKCalendarFlowMonthTitleView : UICollectionReusableView

/**
 Returns the contained calendar cell instance.
 */
@property (nonatomic, strong, readonly) TKCalendarTitleCell* __nonnull view;

/**
 Attaches an owner and text to this cell.
 *
 @param owner The owner, an instance of TKCalendar.
 @param text  The text for the cell.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner withText:(NSString* __nullable)text;

@end
