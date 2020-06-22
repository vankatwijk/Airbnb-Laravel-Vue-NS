//
//  TKChartAreaRenderGeometry.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#ifndef TelerikUI_TKChartAreaRenderGeometry_h
#define TelerikUI_TKChartAreaRenderGeometry_h

#import "TKGeometry.h"

typedef enum TKChartAreaPathType {
    TKChartAreaPathTypeBelowBaseline,
    TKChartAreaPathTypeAboveBaseline
} TKChartAreaPathType;

typedef struct {
    TKChartAreaPathType type;
    CGPoint start;
    CGMutablePathRef path;
} TKChartAreaPath;

typedef TKChartAreaPath* TKChartAreaPathRef;

typedef struct {
    size_t count;
    TKChartAreaPathRef paths;
} TKChartArea;

/**
 Releases a chart area.
 @param area The area.
 */
void TKChartAreaRelease(TKChartArea area);

/**
 Releases an array of areas.
 @param areas The areas .
 @param count The areas' count.
 */
void TKChartAreaRefRelease(TKChartArea *areas, size_t count);

/**
 Creates a TKChartAreaPath.
 @param type The type of the area path.
 */
TKChartAreaPath TKChartAreaPathCreate(TKChartAreaPathType type);

/**
 Releases the chart area path.
 @param path The path.
 */
void TKChartAreaPathRelease(TKChartAreaPath path);

/**
 Creates an area path fill.
 @param path The line path.
 @param baseline The line.
 */
TKChartArea TKAreaPathFillCreate(CGPathRef path, TKLineSegment baseline);

#endif
