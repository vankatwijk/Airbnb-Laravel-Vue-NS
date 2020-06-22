//
//  TKChartBandAnnotationStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartGridLineAnnotationStyle.h"

@class TKFill;

/**
 A style for band annotation
 */
@interface TKChartBandAnnotationStyle : TKChartGridLineAnnotationStyle

/**
 The vertical band fill.
 */
@property (nonatomic, strong) TKFill * __nullable fill;

@end
