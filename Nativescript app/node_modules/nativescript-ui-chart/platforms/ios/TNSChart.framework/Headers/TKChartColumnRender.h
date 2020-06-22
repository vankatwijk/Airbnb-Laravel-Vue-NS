//
//  TKChartColumnRender.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeriesRender.h"

@class TKMutableArray;

@interface TKChartColumnRender : TKChartSeriesRender

@property (nonatomic) CGFloat tickWidth;

@property (nonatomic) CGPoint offset;

@property (nonatomic) CGPoint negativeOffset;

@property (nonatomic) CGFloat maximum;

@property (nonatomic, strong) NSMutableArray *groups;

@property (nonatomic, strong, readonly) NSArray *bands;

@end
