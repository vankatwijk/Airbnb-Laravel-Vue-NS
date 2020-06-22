//
//  TKChartSignalLineIndicator.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represents a base class for all signal line indicators.
 */
@interface TKChartSignalLineIndicator : TKChartFinancialIndicator

@property (nonatomic, readonly) BOOL isSignalState;

@end
