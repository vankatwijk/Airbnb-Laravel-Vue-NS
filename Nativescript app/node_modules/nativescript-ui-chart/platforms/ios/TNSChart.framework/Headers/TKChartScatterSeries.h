//
//  TKChartScatterSeries.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeries.h"

/**
 Represents scatter series. Check this [Guide](http://docs.telerik.com/devtools/ios/chart/series/scatter) for more information.
 */
@interface TKChartScatterSeries : TKChartSeries

/**
 If the distance between hit point is bigger, selection is cleared. By default, it is 8 pixels.
 */
@property (nonatomic, assign) CGFloat marginForHitDetection;

@end
