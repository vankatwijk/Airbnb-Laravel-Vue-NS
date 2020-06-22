//
//  TKChartBindingSource.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@protocol TKChartDataSource;

@interface TKChartBindingSource : NSObject<TKChartDataSource>

@property (nonatomic, readonly) NSArray* series;

/**
 Adds series to the binding source.
 */
- (void)addSeries:(TKChartSeries *)series;

/**
 Adds series to the binding source with data points.
 @param items The array of items that obeys the TKChartData protocol.
*/
- (void)addSeries:(TKChartSeries *)series withItems:(NSArray *)items;

/**
 Adds series to the binding source with items.
 @param items The array of items.
 @param keys The dictionary to describe the binding schema between items properties and properties of the TKChartData protocol.
 */
- (void)addSeries:(TKChartSeries *)series withItems:(NSArray *)items forKeys:(NSDictionary *)keys;

/**
 Removes series from the binding source.
 */
- (void)removeSeries:(TKChartSeries *)series;

/**
 Returns the lowest index whose corresponding array value is equal to a given object.
 */
- (NSInteger)indexOfSeries:(TKChartSeries *)series;

@end
