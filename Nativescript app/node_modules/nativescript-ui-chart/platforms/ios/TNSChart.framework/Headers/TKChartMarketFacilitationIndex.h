//
//  TKChartMarketFacilitationIndex.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

/**
 Represnts Market Facilitation Index indicator.
 */
@interface TKChartMarketFacilitationIndex : TKChartFinancialIndicator

/**
 The range multiplier that is used to calculate the indicator's value. Default value is 1000000.
 */
@property (nonatomic) NSUInteger range;

/**
 The value which controls the distance between bar groups as percent. Note that the value should be between 0 and 1,
 where a value of 0 means that a bar would take the entire space between two ticks, while a value of 1 means the bar will have
 * zero width as all the space should appear as gap.
 */
@property (nonatomic) CGFloat gapLength;

/**
 Value for maximum possible column width.
 */
@property (nonatomic, strong) NSNumber * __nullable maxColumnWidth;

/**
 Value for minimum column width.
 */
@property (nonatomic, strong) NSNumber * __nullable minColumnWidth;

@end
