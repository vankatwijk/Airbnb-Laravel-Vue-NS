//
//  TKChartRateOfChangeIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Rate Of Change indicator.
 */
@interface TKChartRateOfChangeIndicator : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated.
 */
@property (nonatomic) NSUInteger period;

@end
