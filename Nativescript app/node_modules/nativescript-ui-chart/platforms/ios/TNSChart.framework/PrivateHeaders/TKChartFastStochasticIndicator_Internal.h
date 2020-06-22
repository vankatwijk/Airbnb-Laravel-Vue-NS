//
//  TKChartFastStochasticIndicator_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFastStochasticIndicator.h"

@interface TKChartFastStochasticIndicator ()

- (double)signalLineForDataAtIndex:(NSUInteger)dataIndex percentK:(double)percentK period:(NSUInteger)signalPeriod;

- (double)percentKForDataAtIndex:(NSUInteger)dataIndex smoothPeriod:(NSUInteger)smoothPeriod;

@end
