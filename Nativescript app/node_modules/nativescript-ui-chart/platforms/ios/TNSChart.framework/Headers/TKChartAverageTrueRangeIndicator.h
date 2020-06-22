//
//  TKChartAverageTrueRangeIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartTrueRangeIndicator.h"

/**
 Represents Average True Range indicator.
 */
@interface TKChartAverageTrueRangeIndicator : TKChartTrueRangeIndicator

/**
 The period for which the indicator will be calculated. Default value is 14.
 */
@property (nonatomic) NSUInteger period;

@end
