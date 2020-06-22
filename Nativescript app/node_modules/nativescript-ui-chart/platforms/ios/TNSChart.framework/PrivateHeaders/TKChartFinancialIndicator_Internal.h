//
//  TKChartFinancialIndicator_TKChartFinancialIndicator_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartFinancialIndicator.h"

@interface TKChartFinancialIndicator ()

@property (nonatomic, strong) NSNumber *minY;

@property (nonatomic, strong) NSNumber *maxY;

@property (nonatomic) BOOL isCalculated;

- (id<TKChartData>)processPoint:(id<TKChartData>)dataPoint index:(NSUInteger)dataIndex;

- (void)addProcessedPoint:(id<TKChartData>)dataPoint atIndex:(NSInteger)index;

- (id)getProcessedPointAtIndex:(NSInteger)index;

- (void)calculateData;

- (NSUInteger)firstVisibleIndex;

- (NSUInteger)lastVisibleIndex;

- (void)resetCache;

@end
