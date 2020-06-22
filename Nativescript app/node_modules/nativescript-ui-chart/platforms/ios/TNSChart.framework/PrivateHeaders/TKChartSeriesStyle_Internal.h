//
//  TKChartSeriesStyle_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeriesStyle.h"

typedef NS_OPTIONS(NSInteger, TKChartSeriesState) {
    TKChartSeriesStateSelected     = 1 << 3,
    TKChartSeriesStateBullish      = 1 << 4,
    TKChartSeriesStateBearish      = 1 << 5,
    TKChartSeriesStateSignal       = 1 << 6
};

typedef NS_OPTIONS(NSInteger, TKChartStackedItemState) {
    TKChartStackedItemStateFirst   = 1 << 0,
    TKChartStackedItemStateLast    = 1 << 1,
    TKChartStackedItemStateMiddle  = 1 << 2
};

@interface TKChartSeriesStyle ()

@end
