//
//  TKChartForceIndex.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Force Index indicator.
 */
@interface TKChartForceIndexIndicator : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated. Default value is 13.
 */
@property (nonatomic) NSUInteger period;

@end
