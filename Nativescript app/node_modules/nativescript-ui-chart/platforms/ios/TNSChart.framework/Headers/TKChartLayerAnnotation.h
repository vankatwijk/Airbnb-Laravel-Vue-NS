//
//  TKChartLayerAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartPointAnnotation.h"

@class TKChartAxis;

/**
 Represents an annotation that contains a layer.
 */
@interface TKChartLayerAnnotation : TKChartPointAnnotation

/**
 Initializes the annotation with a layer.
 @param layer The layer to display with this annotation.
 @param xValue The X coordinate of the annotation.
 @param yValue The Y coordinate of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (instancetype __nonnull)initWithLayer:(CALayer* __nonnull)layer X:(id  __nonnull)xValue Y:(id  __nonnull)yValue forSeries:(TKChartSeries* __nonnull)series;

/**
 Initializes the annotation with a layer.
 @param layer The layer to display with this annotation.
 @param point The location of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (instancetype __nonnull)initWithLayer:(CALayer *  __nonnull)layer point:(id<TKChartData>  __nonnull)point forSeries:(TKChartSeries *  __nonnull)series;

/**
 Initializes the annotation with a layer.
 @param layer The layer to display with this annotation.
 @param xValue The X coordinate of the annotation.
 @param yValue The Y coordinate of the annotation.
 @param xAxis The X TKChartAxis instance to use with the X coordinate.
 @param yAxis The Y TKChartAxis instance to use with the Y coordinate.
 */
- (instancetype __nonnull)initWithLayer:(CALayer* __nonnull)layer X:(id  __nonnull)xValue Y:(id  __nonnull)yValue forXAxis:(TKChartAxis* __nonnull)xAxis forYAxis:(TKChartAxis* __nonnull)yAxis;

/**
 Initializes the annotation with a layer.
 @param layer The layer to display with this annotation.
 @param point The location of the annotation. 
 @param xAxis The X TKChartAxis instance to use with the X coordinate.
 @param yAxis The Y TKChartAxis instance to use with the Y coordinate.
 */
- (instancetype __nonnull)initWithLayer:(CALayer *  __nonnull)layer point:(id<TKChartData>  __nonnull)point forXAxis:(TKChartAxis* __nonnull)xAxis forYAxis:(TKChartAxis* __nonnull)yAxis;
/**
 Initializes the annotation with a layer.
 @param layer The layer to display with this annotation.
 */
- (instancetype __nonnull)initWithLayer:(CALayer *  __nonnull)layer;

/**
 The annotation layer.
 */
@property (nonatomic, strong) CALayer *  __nonnull layer;

@end
