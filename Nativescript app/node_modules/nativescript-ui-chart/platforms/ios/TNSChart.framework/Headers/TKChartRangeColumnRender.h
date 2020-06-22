//
//  TKChartRangeColumnRender.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKChartSeriesRender.h"

@interface TKChartRangeColumnRender : TKChartSeriesRender

@property (nonatomic) CGFloat tickWidth;

@property (nonatomic, strong) NSMutableArray *groups;

@property (nonatomic, strong, readonly) NSArray *bands;

@end
