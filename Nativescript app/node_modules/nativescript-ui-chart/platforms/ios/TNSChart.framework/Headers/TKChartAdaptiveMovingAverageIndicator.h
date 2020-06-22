//
//  TKChartAdaptiveMovingAverageIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Adaptive Moving Average indicator.
 */
@interface TKChartAdaptiveMovingAverageIndicator : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated. Default value is 10.
 */
@property (nonatomic) NSUInteger period;

/**
 Indicator's slow period that will be used for the calculations. Default values is 30.
 */
@property (nonatomic) NSUInteger slowPerod;

/**
 Indicator's fast period that will be used for the calculations. Default value is 2.
 */
@property (nonatomic) NSUInteger fastPeriod;

@end
