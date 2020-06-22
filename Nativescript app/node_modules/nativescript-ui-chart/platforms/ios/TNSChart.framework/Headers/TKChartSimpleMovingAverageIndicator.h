//
//  TKChartSimpleMovingAverageIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"
/**
 Represents Simple Moving Average indicator.
 */
@interface TKChartSimpleMovingAverageIndicator : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated. Default value is 5.
 */
@property (nonatomic) NSUInteger period;

@end
