//
//  TKChartRangeColumnRender_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKChartRangeColumnRender.h"

@class TKChartBarColumnBand;

@interface TKChartRangeColumnRender ()

- (void)initDraw;

- (void)initGroups;

- (TKChartBarColumnBand *)barColumnBandForSeries:(TKChartSeries *)series pointIndex:(NSInteger)pointIndex groupIndex:(NSInteger)groupIndex;

@end
