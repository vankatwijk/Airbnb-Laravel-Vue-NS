//
//  TKChartBarSeries.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeries.h"

/**
 Represents TKChart bar series.
*/
@interface TKChartBarSeries : TKChartSeries

/**
 The value which controls the distance between bar groups as percent. Note that the value should be between 0 and 1, where a value of 0 means that a bar would take the entire space between two ticks, while a value of 1 means the bar will have zero width as all the space should appear as a gap. Default is 0.25f.
*/
@property (nonatomic, assign) CGFloat gapLength;

/**
 Value for maximum possible bar height in TKChartBarSeries.
 */
@property (nonatomic, strong) NSNumber * __nullable maxBarHeight;

/**
 Value for minimum bar height in TKChartBarSeries.
 */
@property (nonatomic, strong) NSNumber * __nullable minBarHeight;

/**
 Determines whether clustering is allowed when arranging non-stacked series
 */
@property (nonatomic, assign) BOOL allowClustering;

@end
