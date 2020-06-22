//
//  TKChartEaseOfMovementIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents Ease Of Movement indicator.
 */
@interface TKChartEaseOfMovementIndicator : TKChartFinancialIndicator

/**
 The period for which the indicator will be calculated. Default value is 20.
 */
@property (nonatomic) NSUInteger period;

@end
