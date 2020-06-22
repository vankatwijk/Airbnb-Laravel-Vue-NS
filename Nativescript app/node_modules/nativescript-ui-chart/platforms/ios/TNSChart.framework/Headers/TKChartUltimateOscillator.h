//
//  TKChartUltimateOscillator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Ultimate Volume oscillator.
 */
@interface TKChartUltimateOscillator : TKChartFinancialIndicator

/**
 The short period used to calculate the indicator's value. Default value is 7.
 */
@property (nonatomic) NSUInteger shortPeriod;

/**
 The middle period used to calculate the indicator's value. Default value is 14.
 */
@property (nonatomic) NSUInteger middlePeriod;

/**
 The long period used to calculate the indicator's value. Default value is 28.
 */
@property (nonatomic) NSUInteger longPeriod;

@end
