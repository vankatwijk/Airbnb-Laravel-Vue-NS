//
//  TKCalendarFlowDayCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKCalendarDayCell;
@class TKCalendar;

/**
 @discussion A single date whithin a flow view in TKCalendar
 */
@interface TKCalendarFlowDayCell : UICollectionViewCell

/**
 Returns the contained calendar cell instance.
 */
@property (nonatomic, strong, readonly) TKCalendarDayCell* __nonnull view;

/**
 Attaches an owner and date to this cell.
 
 @param owner The owner, an instance of TKCalendar.
 @param date  The date for the cell.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner withDate:(NSDate* __nonnull)date;

@end
