//
//  TKChartPointAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartAnnotation.h"
#import "TKChartData.h"

@class TKChartAxis;
@class TKChartSeries;

/**
  Represents a base class for coordinate based annotations
 */
@interface TKChartPointAnnotation : TKChartAnnotation

/**
 Initializes the annotation by using coordinates.
 @param xValue The X coordinate of the annotation.
 @param yValue The Y coordinate of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (instancetype __nonnull)initWithX:(id  __nonnull)xValue Y:(id  __nonnull)yValue forSeries:(TKChartSeries*  __nonnull)series;

/**
 Initializes the annotation by using a data point and a series.
 @param point The location of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (instancetype __nonnull)initWithPoint:(id<TKChartData>  __nonnull)point forSeries:(TKChartSeries*  __nonnull)series;

/**
 Initializes the annotation by using coordinates and two axes.
 @param xValue The X coordinate of the annotation.
 @param yValue The Y coordinate of the annotation.
 @param xAxis The TKChartAxis instance to use with the X coordinate.
 @param yAxis The TKChartAxis instance to use with the Y coordinate.
 */
- (instancetype __nonnull)initWithX:(id  __nonnull)xValue Y:(id  __nonnull)yValue forXAxis:(TKChartAxis*  __nonnull)xAxis forYAxis:(TKChartAxis*  __nonnull)yAxis;

/**
 Initializes the annotation by using a data point and two axes.
 @param point The location of the annotation.
 @param xAxis The TKChartAxis instance to use with the X coordinate.
 @param yAxis The TKChartAxis instance to use with the Y coordinate.
 */
- (instancetype __nonnull)initWithPoint:(id<TKChartData>  __nonnull)point forXAxis:(TKChartAxis*  __nonnull)xAxis forYAxis:(TKChartAxis*  __nonnull)yAxis;

/**
 Returns the plot coordinates of this annotation whithin the specified bounds.
 @param bounds the bounds which define the final coordinates.
 @param chart the chart where this annotation belongs.
 */
- (CGPoint)locationInRect:(CGRect)bounds forChart:(TKChart* __nullable)chart;

/**
 The TKChartSeries associated with the annotation.
 */
@property (nonatomic, weak, nullable) TKChartSeries * series;

/**
 The X TKChartSeries associated with the annotation.
 */
@property (nonatomic, weak, nullable) TKChartAxis * xAxis;

/**
 The Y TKChartAxis associated with the annotation.
 */
@property (nonatomic, weak, nullable) TKChartAxis * yAxis;

/**
 The annotation position.
 */
@property (nonatomic, strong) id<TKChartData>  __nonnull position;

/**
 An offset which is applied to annotation coordinates when calling the locationInRect: method.
 */
@property (nonatomic, assign) UIOffset offset;

@end

