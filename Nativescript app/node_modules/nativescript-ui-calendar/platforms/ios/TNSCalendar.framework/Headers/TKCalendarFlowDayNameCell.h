//
//  TKCalendarFlowDayNameCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKCalendarDayNameCell;
@class TKCalendar;

/**
 @discussion A day name cell used in flow view in TKCalendar.
 */
@interface TKCalendarFlowDayNameCell : UICollectionViewCell

/**
 Returns the contained calendar cell instance.
 */
@property (nonatomic, strong, readonly) TKCalendarDayNameCell* __nonnull view;

/**
 Attaches an owner and day offset with the cell.

 @param owner The cell owner, an instance of TKCalendar.
 @param index The zero based day name offset.
 */
- (void)attachWithCalendar:(TKCalendar* __nonnull)owner withDayOffset:(NSInteger)index;

@end
