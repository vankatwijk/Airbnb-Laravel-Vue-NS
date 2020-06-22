//
//  TKChartFinancialRender.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartSeriesRender.h"

@interface TKChartOhlcRender : TKChartSeriesRender

@property (nonatomic, strong) NSMutableArray *groups;

@property (nonatomic) CGFloat gapLength;

@property (nonatomic) CGFloat interitemSpacings;

@property (nonatomic) CGFloat tickWidth;

@property (nonatomic) CGFloat interitemSpacing;

@property (nonatomic) CGFloat barWidth;

@end
