//
//  TKChartLegendView_Internal.h
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartLegendView.h"

@interface TKChartLegendView()

@property (nonatomic, strong) TKStyleSheet *styleSheet;

@end

/**
 @discussion This protocol is implemented by all series and provides items for the legend.
 */
@protocol TKChartLegendItemProviderDelegate <NSObject>

/**
 Determines the number of items for a particular chart.
 @param chart The chart for which the method call is performed.
 @return The count of legend items for the series in the specified chart.
 */
- (NSUInteger)legendItemCountForChart:(TKChart *)chart;

/**
 Provides a legend item for the series in a specified chart.
 @discussion The legend asks all series first about the count of legend items they will provide and then gets this count of items.
 @param chart The chart for which the legend item is requested.
 @param index The index of the requested legend item.
 @return legend The item at the specified index.
 */
- (TKChartLegendItem *)legendItemForChart:(TKChart *)chart atIndex:(NSUInteger)index;

@end

