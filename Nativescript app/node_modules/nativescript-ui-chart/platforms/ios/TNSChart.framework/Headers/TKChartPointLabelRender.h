//
//  TKChartPointLabelLayout.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartData.h"
#import "TKChart.h"

@class TKChartPointLabel;
@class TKChartSeries;
@class TKChartSeriesRender;


/**
 Represents a base class for point label renders.
 */
@interface TKChartPointLabelRender : NSObject

/**
 The corresponding series render.
 */
@property (nonatomic, readonly, weak, null_unspecified) TKChartSeriesRender *render;


@property (nonatomic, readonly, weak, nullable) id<TKChartDelegate> chartDelegate;
/**
 Initializes the point label's render with corresponding series render.
 @param render The series render.
 */
- (instancetype __nonnull)initWithRender:(TKChartSeriesRender * __nonnull )render;

/**
 Renders point labels for a series.
 @param series The series for which point labels will be rendered.
 @param bounds The rect that point labels should be rendered into.
 @param ctx CGContext instance.
 */
- (void)renderPointLabelsForSeries:(TKChartSeries * __nonnull )series inRect:(CGRect)bounds context:(CGContextRef __nonnull )ctx;

/**
 Returns the coordinates of id<TKChartData> in specified rect.
 @param dataPoint id<TKChartData> instance which coordeinates will be returned.
 @param series The id<TKChartData> object series.
 @param rect The rect for which coordinates will be returned.
 */
- (CGPoint)locationForDataPoint:(id<TKChartData> __nonnull)dataPoint forSeries:(TKChartSeries * __nonnull )series inRect:(CGRect)rect;

/**
 Returns TKChartPointLabel instance.
 @param dataPoint The data point for which a label will be returned.
 @param propertyName The property name of the data point for which a point label will be created.
 @param series The data point's series.
 @param dataIndex Data point's index in the series.
 */
- (TKChartPointLabel * __nullable)labelForDataPoint:(id<TKChartData> __nonnull)dataPoint property:(NSString * __nullable)propertyName inSeries:(TKChartSeries * __nonnull)series atIndex:(NSUInteger)dataIndex;

/**
 Returns BOOL value showing if point is inside the bounds of given rectangle.
 @param point The point which will be tested.
 @param rect The given rectangle.
 */
- (BOOL)isPoint:(CGPoint)point insideRect:(CGRect)rect;

@end
