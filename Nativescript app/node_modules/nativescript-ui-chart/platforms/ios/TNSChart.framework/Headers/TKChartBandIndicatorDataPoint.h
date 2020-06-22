//
//  TKChartBandIndicatorDataPoint.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartData.h"

@interface TKChartBandIndicatorDataPoint : NSObject <TKChartData>

+ (instancetype)dataPointWithX:(id)xValue Y:(id)yValue signalY:(id)signalYValue;

@property (nonatomic, strong) id dataXValue;

@property (nonatomic, strong) id dataYValue;

@property (nonatomic, strong) id signalYValue;

@end
