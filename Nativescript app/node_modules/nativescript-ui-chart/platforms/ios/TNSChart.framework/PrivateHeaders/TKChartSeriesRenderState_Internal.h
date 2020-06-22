//
//  TKChartSeriesRenderState_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeriesRenderState.h"

@class TKMutableArray;

@interface TKChartSeriesRenderState ()

- (void)setIndex:(NSUInteger)index;
- (void)setPoints:(TKMutableArray*)points;
- (void)setOldPoints:(TKMutableArray*)oldPoints;

@end
