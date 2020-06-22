//
//  TKChartDetrendedPriceOscillator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Detrended Price oscillator.
 */
@interface TKChartDetrendedPriceOscillator : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated. Default value is 20.
 */
@property (nonatomic) NSUInteger period;

@end
