//
//  TKChartFastStochasticIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartSignalLineIndicator.h"

/**
 Represents Fast Stochastic indicator.
 */
@interface TKChartFastStochasticIndicator : TKChartSignalLineIndicator

/**
 The period used to calculate the indicator's signal line. Default value is 3.
 */
@property (nonatomic) NSUInteger signalPeriod;

/**
 The period for which the indicator will be calculated. Default value is 14.
 */
@property (nonatomic) NSUInteger period;

@end
