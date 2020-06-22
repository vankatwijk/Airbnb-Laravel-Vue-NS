//
//  TKChartDataView.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAxis.h"
#import "TKCollection.h"

@class TKRange;
@protocol TKChartData;

typedef NS_OPTIONS(NSInteger, TKChartAxisType) {
    TKChartAxisTypeX = TKChartAxisPositionLeft | TKChartAxisPositionRight,
    TKChartAxisTypeY = TKChartAxisPositionTop | TKChartAxisPositionBottom,
    TKChartAxisTypeNone
};

typedef NS_ENUM(NSInteger, TKChartDataPointNulls){
    TKChartDataPointNullsNil,
    TKChartDataPointNullsZero,
    TKChartDataPointNullsInterpolate
};

/**
 Representd a class that manipulates data points of TKChartSeries.
 */
@interface TKChartDataView : NSObject<TKCollection>

/**
 * Initializes a data-view with items.
 * @param items The array of items that obeys the TKChartData protocol.
 */
- (instancetype)initWithItems:(NSArray*)items;

/**
 * Initializes series with items.
 * @param items The array of items that obeys the TKChartData protocol.
 * @param keys The dictionary to describe the binding between items properites and properties of the TKChartData protocol.
 */
- (instancetype)initWithItems:(NSArray*)items forKeys:(NSDictionary *)keys;

@property (nonatomic) TKChartDataPointNulls dataPointNulls;

- (BOOL)isEmpty:(NSInteger)dataIndex;

- (void)transformNulls:(id<TKChartData>(^)(id<TKChartData>))handler;

//- (void)filterWithCount:(NSInteger)count algorithm:(NSString *)algo;

/**
 Returns an id<TKChartData> data point at the given index.
 @param dataIndex The data point index.
*/
- (id<TKChartData>)dataPointAtIndex:(NSUInteger)dataIndex;

/**
 Performs a filter operation over the items in the data-view using a delegated method.
 @param handler A handler used for filtering
 */
- (void)filter:(BOOL(^)(id<TKChartData>))handler;

/**
 Performs a sorting operation over the items in the data-view using a comparator delegate.
 @param cmptr A comparator
 */
- (void)sort:(NSComparator)cmptr;

/**
 Performs a sorting operation over the items in the data-view using a key value name.
 @param key The sorted key.
 @param ascending The ascending direction.
 */
- (void)sortWithKey:(NSString*)key ascending:(BOOL)ascending;

/**
 Performs a delegated action over the sorted and filtered data-view or over all items when sorting or filtering are not applied.
 @param handler The handler used to evaluate the points inside the view.
 */
- (id)evaluate:(id(^)(id<TKChartData>, NSUInteger index, id accumulator))handler;

/**
 Transfroms a data point from one to another using a delegated method.
 @param handler The handler transformed to.
 */
- (void)transform:(id<TKChartData>(^)(id<TKChartData>))handler;

/**
 Returns the items collection associated with this data view.
 */
- (NSArray*)items;

/**
 Returns the data points collection associated with this data view with applied sorting and filtering operations.
 */
- (NSArray *)dataPoints;

/**
 Reload the items collection associated with this data view, clear applied filtering and sorting operations.
 */
- (void)reloadData;

- (BOOL)isSorted;

@end
