//
//  TKChart_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChart.h"

@class TKCoreStackLayout;
@class TKCoreLayoutItem;
@class TKChartLayout;

@interface TKChart () {
    
@public
    TKChartPlotView *_plotAreaView;
    TKChartLegendView *_legendView;
    TKChartTitleView *_titleView;
    TKCoreStackLayout *_stack;
    TKCoreStackLayout *_innerStack;
    TKChartLayout *_chartLayout;
    TKCoreLayoutItem *_legendLayoutItem;
    TKCoreLayoutItem *_titleLayoutItem;
    NSMutableArray *_annotations;
    
}

@property (nonatomic, assign) BOOL useNewSelection;

@property (nonatomic) BOOL forceAutoAxis;

@property (nonatomic) BOOL shouldPanZoom;

- (void)setSelectedSeries:(NSInteger)seriesIndex andPoint:(NSInteger)pointIndex;

/**
 Removes all axes from the chart.
 */
- (void)removeAllAxes;

/**
 Removes all series from the chart.
 */
- (void)removeAllSeries;

- (TKShape *)shapeForSeries:(TKChartSeries*)series atIndex:(NSUInteger)index;

- (NSString*)formatAxisValue:(id)value atIndex:(NSUInteger)index inAxis:(TKChartAxis*)axis;

- (void)updateSeriesRenders;

@end