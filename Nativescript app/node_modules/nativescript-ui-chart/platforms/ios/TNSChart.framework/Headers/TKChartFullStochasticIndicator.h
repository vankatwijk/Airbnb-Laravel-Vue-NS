//
//  TKChartFullStochasticIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartSlowStochasticIndicator.h"
/**
 Represents Full Stochastic indicator. Doesn't have any specific properties.
 */
@interface TKChartFullStochasticIndicator : TKChartSlowStochasticIndicator

/**
 The smoothing period used to calculate the indicator's value. Default value is 3.
 */
@property (nonatomic) NSUInteger smoothPeriod;

@end
