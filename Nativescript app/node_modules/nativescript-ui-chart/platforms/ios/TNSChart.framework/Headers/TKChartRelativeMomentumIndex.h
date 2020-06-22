//
//  TKChartRelativeMomentumIndex.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Relative Momenum Index indicator.
 */
@interface TKChartRelativeMomentumIndex : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated. Default value is 14.
 */
@property (nonatomic) NSUInteger period;

/**
 The momentum period used to calculate the indicator's value. Default value is 4.
 */
@property (nonatomic) NSUInteger momentum;

@end
