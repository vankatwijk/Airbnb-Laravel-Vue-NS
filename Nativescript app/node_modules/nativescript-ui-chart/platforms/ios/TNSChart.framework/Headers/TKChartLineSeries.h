//
//  TKChartLineSeries.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeries.h"

/**
 Represents TKChart line series.
*/
@interface TKChartLineSeries : TKChartSeries

/**
 If distance between hit and line is bigger, the selection is cleared. By default, it is 25 pixels.
 */
@property (nonatomic, assign) CGFloat marginForHitDetection;

/**
 Determines whether gaps should be displayed when there are nil values.
 */
@property (nonatomic) BOOL displayNilValuesAsGaps;

@end
