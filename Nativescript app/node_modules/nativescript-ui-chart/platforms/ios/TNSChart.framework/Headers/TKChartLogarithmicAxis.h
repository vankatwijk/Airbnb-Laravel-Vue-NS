//
//  TKChartLogarithmicAxis.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKChartNumericAxis.h"

/**
 The logarithmic axis of TKChart.
 
 @see [Working with Logarithmic Axis](chart-axes-logarithmic)
 
 @discussion TKChart uses Linear axes to display values that cover several orders of magnitude in a more manageable way.
 
 */
@interface TKChartLogarithmicAxis : TKChartNumericAxis

/**
 Logarithmic base
 */
@property (nonatomic, strong) NSNumber *logarithmBase;

/**
 Exponent step
 */
@property (nonatomic, assign) NSNumber *exponentStep;

@end
