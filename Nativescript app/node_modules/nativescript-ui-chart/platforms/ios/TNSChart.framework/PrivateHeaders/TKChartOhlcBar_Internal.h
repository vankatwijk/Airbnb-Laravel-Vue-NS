//
//  TKChartOhlcBar_TKChartOhlcBar_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartOhlcBar.h"

@interface TKChartOhlcBar ()

@property (nonatomic) CGFloat groupIndex;

@property (nonatomic) TKChartSeries *series;

@property (nonatomic) NSUInteger dataIndex;

- (void)drawInContext:(CGContextRef)ctx;

@end
