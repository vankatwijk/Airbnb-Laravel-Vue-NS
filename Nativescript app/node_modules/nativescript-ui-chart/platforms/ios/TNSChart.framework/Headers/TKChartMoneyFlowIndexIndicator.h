//
//  TKChartMoneyFlowIndex.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Money Flow Index indicator.
 */
@interface TKChartMoneyFlowIndexIndicator : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated. Default Value is 14.
 */
@property (nonatomic) NSUInteger period;

@end
