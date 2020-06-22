//
//  TKChartRapidAdaptiveVarianceIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Rapid Adaptive Variance indicator.
 */
@interface TKChartRapidAdaptiveVarianceIndicator : TKChartFinancialIndicator

/**
 The short period used to calculate the indicators value. Default value is 7.
 */
@property (nonatomic) NSUInteger shortPeriod;

/**
 The long period used to calculate the indicators value. Default value is 65.
 */
@property (nonatomic) NSUInteger longPeriod;

@end
