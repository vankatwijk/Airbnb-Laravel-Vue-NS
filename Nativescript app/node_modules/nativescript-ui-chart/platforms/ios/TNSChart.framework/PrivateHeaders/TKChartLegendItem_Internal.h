//
//  TKChartLegendItem.h
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartLegendItem.h"

@class TKChart;
@class TKStyleSheet;
@class TKChartLegendView;

@interface TKChartLegendItem ()

@property (nonatomic, weak) TKChartLegendView *ownerView;

@property (nonatomic, strong) TKStyleSheet *styleSheet;

@end

