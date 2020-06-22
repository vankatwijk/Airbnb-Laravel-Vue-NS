//
//  TKChartWilliamsPercentIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Williams Percent indicator.
 */
@interface TKChartWilliamsPercentIndicator : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated. Default value is 14.
 */
@property (nonatomic) NSUInteger period;

@end
