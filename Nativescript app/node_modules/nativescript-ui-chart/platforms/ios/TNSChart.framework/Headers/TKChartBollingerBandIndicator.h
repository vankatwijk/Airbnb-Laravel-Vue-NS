//
//  TKChartBollingerBandIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartBandIndicator.h"

/**
 Represents Bollinger Bands indicator.
 */
@interface TKChartBollingerBandIndicator : TKChartBandIndicator

/**
 The period for which the indicator will be calculated. Default value is 5.
 */
@property (nonatomic) NSUInteger period;

/**
 A width multiplier used to calculate the indicator's value. Default value is 2.
 */
@property (nonatomic) NSUInteger width;

@end
