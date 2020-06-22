//
//  TKChartCommodityChannelIndex.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Commodity Channel Index indicator.
 */
@interface TKChartCommodityChannelIndex : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated. Default value is 20.
 */
@property (nonatomic) NSUInteger period;

@end
