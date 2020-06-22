//
//  TKChartColumnRender_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartColumnRender.h"

@class TKBasicAnimation;
@class TKChartBarColumnBand;
@class TKChartSeriesRenderState;
@class TKChartStackedLayoutInfo;

@interface TKChartColumnRender ()
{
@protected
    CGFloat _tickWidth;
    CGPoint _offset;
    CGPoint _negativeOffset;
    CGFloat _maximum;
    NSMutableArray *_groups;
}

@property (nonatomic) CGFloat lastSeriesCount;

- (void)initGroups;

- (void)addBarColumnBandForLayoutInfo:(TKChartStackedLayoutInfo*)info
                           groupIndex:(NSUInteger)groupIndex
                          seriesIndex:(NSUInteger)seriesIndex
                            dataIndex:(NSUInteger)dataIndex
                             baseline:(CGPoint)baseline
                         inDictionary:(NSMutableArray*)array;

- (CGPoint)baselineForSeries:(TKChartSeries*)series;
- (TKChartStackedLayoutInfo *)stackLayoutInfoForSeries:(TKChartSeries *)series;

@end
