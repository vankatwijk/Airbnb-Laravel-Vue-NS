//
//  TKChartMovingAverageConvergenceDivergenceIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartSignalLineIndicator.h"

/**
 Represents Moving Average Convergence Divergence indicator.
 */
@interface TKChartMACDIndicator : TKChartSignalLineIndicator

/**
 The short period for which to compute the indicator. Default value is 12.
 */
@property (nonatomic) NSUInteger shortPeriod;

/**
 The long period for which to compute the indicator. Default value is 26.
 */
@property (nonatomic) NSUInteger longPeriod;

/**
 The period used to calculate the signal line. Default value is 9.
 */
@property (nonatomic) NSUInteger signalPeriod;

@end
