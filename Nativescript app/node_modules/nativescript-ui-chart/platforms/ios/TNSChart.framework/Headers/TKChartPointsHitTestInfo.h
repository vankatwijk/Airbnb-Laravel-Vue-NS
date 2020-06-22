//
//  TKChartPointsHitTestInfo.h
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKChartSeries;

@interface TKChartPointsHitTestInfo : NSObject

@property (nonatomic) CGPoint *points;

@property (nonatomic, weak) TKChartSeries *series;

- (instancetype)initWithSeries:(TKChartSeries*)series points:(CGPoint*)points;

@end
