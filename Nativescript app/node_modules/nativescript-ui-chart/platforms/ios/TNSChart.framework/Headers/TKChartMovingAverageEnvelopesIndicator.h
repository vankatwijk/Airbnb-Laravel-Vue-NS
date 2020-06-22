//
//  TKChartMovingAverageEnvelopesIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartBandIndicator.h"

/**
 Represents Moving Average Envelopes indicator.
 */
@interface TKChartMovingAverageEnvelopesIndicator : TKChartBandIndicator

/**
 The period for which the indicator will be calculated. Default value is 20.
 */
@property (nonatomic) NSUInteger period;

/**
 The ratio above and below the moving average. Default value is 0.01.
 */
@property (nonatomic) CGFloat envelopesPercentage;

@end
