//
//  TKCalendarDayViewTimeLine.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

@class TKCalendarDayViewEventsView;

/**
 @discussion A decoration view that displays the time line in the TKCalendarDayViewventsView collection view.
 */
@interface TKCalendarDayViewTimeLine : UICollectionReusableView

/**
 The TKCalendarDayViewEventsView that contains the time line.
 */
@property (nonatomic, weak, readonly) TKCalendarDayViewEventsView * owner;

@end

/**
 @discussion Manages the layout-related attributes for a time line item in a TKCalendarDayViewventsView collection view. 
 */
@interface TKCalendarDayViewTimeLineLayoutAttributes : UICollectionViewLayoutAttributes

/**
 The TKCalendarDayViewEventsView that contains the time line.
 */
@property (nonatomic, weak, readonly) TKCalendarDayViewEventsView * owner;

/**
 Initializes a new instance of the TKCalendarDayViewTimeLineLayoutAttributes.
 
 @param decorationViewKind The identifier of the decoration view.
 @param indexPath The index path of the decoration view.
 @param owner The TKCalendarDayViewEventsView that contains the decoration view.
 */
+ (instancetype)layoutAttributesForDecorationViewOfKind:(NSString *)decorationViewKind withIndexPath:(NSIndexPath *)indexPath withOwner: (TKCalendarDayViewEventsView *)owner;

@end
