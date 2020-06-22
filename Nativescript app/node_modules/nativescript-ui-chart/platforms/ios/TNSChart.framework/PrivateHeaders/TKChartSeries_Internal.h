//
//  TKChartSeries_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeries.h"
#import "TKChartDataView.h"
#import "TKChartLegendView_Internal.h"

@class TKChartPaletteItem;
@class TKChartSeriesStyle;
@class TKStyleSheet;

/**
 An extension of the TKChartSeries class.
 */
@interface TKChartSeries () <TKChartLegendItemProviderDelegate>

/**
 Defines axis plot mode for this series.
 @param axis The axis.
 */
+ (void)setAxisPlotMode:(TKChartAxis*)axis;

/**
 The style sheet of the series.
 */
@property (nonatomic, strong) TKStyleSheet *styleSheet;

/**
 Defines the index of the series.
 @param index The index.
 */
- (void)setIndex:(NSUInteger)index;

- (TKChartPaletteItem *)defaultPaletteItem;

- (NSInteger)firstVisiblePointIndex;

/**
 Creates axis for the series.
 @param axes The currently added axis.
 @param isYAxis Determines whether the axis is a y-axis.git 
 */
- (TKChartAxis *)axisForSeriesIn:(NSArray *)axes forYAxis:(BOOL)isYAxis;

- (void)initializeAxis:(TKChartAxis*)axis ofType:(TKChartAxisType)type;

- (void)applyStyleForChart:(TKChart *)chart legendItem:(TKChartLegendItem *)legendItem;

/**
 Defines the series items for specific keys.
 @discussion You could set your own classes as data values by specifying their keys
 
 [series setItems:array forKeys:@{@"dataXValue":@"id", @"dataYvalue":@"salary"}];
 
 @param items The items that supply data for the series.
 @param keys The items key path.
 */
- (void)setItems:(NSArray *)items forKeys:(NSDictionary *)keys;

- (id)getMaxForKey:(NSString *)key;

- (id)getMinForKey:(NSString *)key;

- (void)clearSelectedPoints;

- (void)selectPointAtIndex:(NSInteger)index;

- (void)deselectPointAtIndex:(NSInteger)index;

- (NSArray *)selectedPoints;

- (NSArray *)selectedIndexes;

- (void)setIsSelected:(BOOL)isSelected;

- (BOOL)hasMultiplePalettes;

- (void)reloadData;

/**
 The series' data view.
 */
@property (nonatomic, strong) TKChartDataView *dataView;

@end
