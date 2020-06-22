//
//  TKChartPieRender.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeriesRender.h"

@class TKChartPieSeries;

@interface TKChartPieRender : TKChartSeriesRender

@property (nonatomic, assign) CGFloat rotationAngle;

@property (nonatomic, readonly) CGFloat outerRadius;

@property (nonatomic, readonly) CGFloat innerRadius;

+ (CGFloat)getRadius:(TKChartPieSeries*)series withSize:(CGSize)size;

@end
