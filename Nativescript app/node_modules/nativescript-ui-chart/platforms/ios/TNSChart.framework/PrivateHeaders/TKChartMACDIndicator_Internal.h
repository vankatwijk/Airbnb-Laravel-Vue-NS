//
//  TKChartMACDIndicator_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartMACDIndicator.h"

@interface TKChartMACDIndicator ()

- (double)simpleMovingAverageForDataAtIndex:(NSInteger)dataIndex period:(NSInteger)period;

- (double)exponentialMovingAverageForDataAtIndex:(NSInteger)dataIndex period:(NSInteger)period;

- (double)simpleAverageOfIndicatorForDataAtIndex:(NSInteger)dataIndex withIndicatorValue:(double)currentValue;

- (double)signalLineForDataAtIndex:(NSInteger)dataIndex ema:(double)prevEma indicatorValue:(double)indicatorValue;

@end
