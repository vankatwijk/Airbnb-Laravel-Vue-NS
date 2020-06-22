//
//  TKCalendarDayView.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TKCalendarDayCell.h"

@class TKCalendarDayViewAllDayEventsView;
@class TKCalendarDayViewEventsView;
@class TKCalendarDayViewPresenter;
@class TKCalendarDayView;

/**
 @discussion The TKCalendarDayViewEventCellProtocol protocol is adopted by a cell that represents an event in TKCalendarDayView.
 */
@protocol TKCalendarDayViewEventCellProtocol <NSObject>

@required

/**
 Event presented by the cell.
 */
@property (nonatomic, weak, readonly) id<TKCalendarEventProtocol> __nullable event;

/**
 Updates the cell event.
 
 @param event The event that will be presented.
 */
- (void)attachWithEvent:(id<TKCalendarEventProtocol> __nonnull)event;

@end


/**
 @discussion The TKCalendarDayViewDataSource protocol defines methods to create subviews in TKCalendarDayView.
 */
@protocol TKCalendarDayViewDataSource <NSObject>

/**
 Returns the number of events that are not marked as allDay. These events are used as a source for the TKCalendarDayViewEventsView. By default the count of TKCalendarDayView events property is returned.
 
 @param dayView The dayView that contains the TKCalendarDayViewEventsView.
 @param section The section.
 
 @return The number of events.
 */
- (NSInteger)dayView:(TKCalendarDayView * __nonnull)dayView numberOfEventsInSection:(NSInteger)section;

/**
 Returns the number of events marked as allDay. These events are used as a data source for the TKCalendarDayViewAllDayEventsView. By default the count of TKCalendar allDayEvents property is returned.
 
 @param dayView The dayView that contains the TKCalendarDayViewAllDayEventsView.
 @param section The section.
 
 @return The number of all-day events.
 */
- (NSInteger)dayView:(TKCalendarDayView * __nonnull)dayView numberOfAllDayEventsInSection:(NSInteger)section;

/**
 Returns UICollectionViewCell cell that will represent an event in the TKCalendarDayViewEventsView
 
 @param dayView The dayView that contains the TKCalendarDayViewEventsView.
 @param indexPath The NSIndexPath for the event inside the dayView.events collection.
 
 @return The event cell.
 */
- (__kindof UICollectionViewCell * __nonnull)dayView:(TKCalendarDayView * __nonnull)dayView eventCellForItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 Returns UICollectionViewCell cell that will represent an event in the TKCalendarDayViewAllDayEventsView
 
 @param dayView The dayView that contains the TKCalendarDayViewAllDayEventsView.
 @param indexPath The NSIndexPath for the event inside the dayView.allDayEvents collection.
 
 @return The all-day event cell.
 */
- (__kindof UICollectionViewCell * __nonnull)dayView:(TKCalendarDayView * __nonnull)dayView allDayEventCellForItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 Returns a TKCalendarDayViewAllDayEventsView that will display all-day events.
 
 @param dayView The parent TKCalendarDayView.
 
 @return The all-day events view.
 */
- (TKCalendarDayViewAllDayEventsView* __nonnull)createAllDayEventsViewInDayView:(TKCalendarDayView * __nonnull)dayView;

/**
 Returns TKCalendarDayViewEventsView that will display the events for this day that are not marked as all-day.
 
 @param dayView The parent TKCalendarDayView.
 
 @return The events view.
 */
- (TKCalendarDayViewEventsView* __nonnull)createEventsViewInDayView:(TKCalendarDayView * __nonnull)dayView;

/**
 This method can be used to update the visual style of an event cell.
 
 @param dayView The parent TKCalendarDayView.
 @param cell The cell.
 
 */
- (void)dayView:(TKCalendarDayView * __nonnull)dayView updateCell:(UICollectionViewCell * __nonnull)cell;

@end


/**
 @discussion The TKCalendarDayViewDelegate protocol defines methods that allow you handle selection of event cells and to customize the layout of the TKCalendarDayViewAllDayEventsView.
 */
@protocol TKCalendarDayViewDelegate <NSObject>

/**
 Tells the delegate that an event has been selected.
 
 @param dayView The TKCalendarDayView that is notifying of the selection.
 @param event The selected event.
 */
// TODO: make two methods? Additional parameters?
- (void)dayView:(TKCalendarDayView * __nonnull)dayView didSelectEvent:(id<TKCalendarEventProtocol> __nonnull)event;

/**
 Asks the delegate for the size of the TKCalendarDayViewAllDayEventsView.
 
 @param dayView The all-day events view's superview.
 
 @returns The width and height of the specified view. All values must be greater than 0.
 */
- (CGSize)allDayViewSizeInDayView:(TKCalendarDayView * __nonnull)dayView;

/**
 Asks the delegte for the size of the specified all-day event's cell.
 
 @param dayView The all-day events view's superview.
 @param layout The layout object requesting the information.
 @param indexPath The index path of the all-day event.
 
 @returns The width and height of the specified event. All values must be greater than 0.
 */
- (CGSize)dayView:(TKCalendarDayView * __nonnull)dayView allDaylayout:(UICollectionViewLayout *  __nonnull)layout sizeForItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 Asks the delegate for the margins of specified section's content.
 
 @param dayView The all-day events view's superview.
 @param layout The layout object requesting the information.
 @param section The index of the section.
 
 @returns The margins that will be applied to the section's content.
 */
- (UIEdgeInsets)dayView:(TKCalendarDayView * __nonnull)dayView allDaylayout:(UICollectionViewLayout * __nonnull)layout insetForSectionAtIndex:(NSInteger)section;

/**
 Asks the delegate for the spacing between successive rows/columns of a section.
 
 @param dayView The all-day events view's superview.
 @param layout The layout object requesting the information.
 @param section The index of the section.
 
 @returns The minimum spacing (measured in points) to be applied between successive lines in the section.
 */
- (CGFloat)dayView:(TKCalendarDayView * __nonnull)dayView allDaylayout:(UICollectionViewLayout * __nonnull)layout minimumLineSpacingForSectionAtIndex:(NSInteger)section;

/**
 Asks the delegate for the spacing between successive intems in a row/column of a section.
 
 @param dayView The all-day events view's superview.
 @param layout The layout object requesting the information.
 @param section The index of the section.
 
 @returns The minimum spacing (measured in points) to be applied between successive items in the lines of a section.
 */
- (CGFloat)dayView:(TKCalendarDayView * __nonnull)dayView allDaylayout:(UICollectionViewLayout * __nonnull)layout minimumInteritemSpacingForSectionAtIndex:(NSInteger)section;

@end


/**
 @discussion View that displays the events for a specific date in calendar day view mode.
 */
@interface TKCalendarDayView : UIView <UICollectionViewDelegateFlowLayout, UICollectionViewDataSource>

/**
 Returns the view that displays the all-day events.
 */
@property (nonatomic, strong, readonly, nonnull) TKCalendarDayViewAllDayEventsView* allDayEventsView;

/**
 Returns the view that displays events that are not marked as all-day.
 */
@property (nonatomic, strong, readonly, nonnull) TKCalendarDayViewEventsView* eventsView;

/**
 Returns a view that is displayed when no date is associated with the TKCalendarDayView.
 */
@property (nonatomic, strong, readonly, nonnull) UIView* emptyView;

/**
 Returns the date associated with the TKCalendarDayView. The events for this date are used as a source for the eventsView and allDayEventsView.
 */
@property (nonatomic, strong, readonly, nullable) NSDate* date;

/**
 The object responsible for providing the views required by a TKCalendarDayView view.
 */
@property (nonatomic, strong, nullable) id<TKCalendarDayViewDataSource> dataSource;

/**
 The object that acts as the delegate of the TKCalendarDayView view.
 */
@property (nonatomic, strong, nullable) id<TKCalendarDayViewDelegate> delegate;

/**
 Collection of events that are used as a source for the eventsView.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<id<TKCalendarEventProtocol>> * events;

/**
 Collection of events that are used as a source for the allDayView.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<id<TKCalendarEventProtocol>> * allDayEvents;

/**
 The calendar.
 */
@property (nonatomic, strong, readonly, nullable) NSCalendar* calendar;

/**
 Updates the data displayed in the day view.
 
 @param events The events that will be displayed in the day view.
 @param date The displayed date.
 @param calendar The calendar.
 */
- (void)attachWithEvents:(NSArray<id<TKCalendarEventProtocol>>* __nonnull)events forDate:(NSDate* __nonnull)date withCalendar:(NSCalendar * __nonnull)calendar;

@end

