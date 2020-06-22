//
//  TKChartAnnotationRender.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartRender.h"
#import "TKChartAnnotation.h"

@class TKChart;
@class TKChartAnnotation;

@interface TKChartAnnotationRenderBase : TKChartRender

@property (nonatomic, weak) NSArray *annotations;

@property (nonatomic, assign) TKChartAnnotationZPosition annotationPosition;

- (instancetype)initWithChart:(TKChart*)chart annotations:(NSArray*)annotations;

- (BOOL)annotationIsVisible:(TKChartAnnotation*)annotation;

@end
