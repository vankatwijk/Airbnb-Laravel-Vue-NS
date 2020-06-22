//
//  TKChartChaikinOscillator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Chaikign Oscillator.
 */
@interface TKChartChaikinOscillator : TKChartFinancialIndicator

/**
 The short period used to calculate the indicator's value. Default value is 3.
 */
@property (nonatomic) NSUInteger shortPeriod;

/**
 The long period used to calculate the indicator's value. Default value is 10.
 */
@property (nonatomic) NSUInteger longPeriod;

@end
