//
//  TKGeometry.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#ifndef TKGEOMETRY_H_
#define TKGEOMETRY_H_

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGGeometry.h>
#include <CoreGraphics/CGPath.h>

/**
 Defines the different algorithms for distance calculation
 */
typedef enum TKPointDistanceType {
    /**
     Distance by X-coordinate
     */
    TKPointDistanceTypeX,
    /**
     Distance by Y-coordinate
     */
    TKPointDistanceTypeY,
    /**
     Distance by Point algorithm
     */
    TKPointDistanceTypeXY,
    /**
     Distance by Point Squard algorithm
     */
    TKPointDistanceTypeXYSquared
} TKPointDistanceType;

/**
 Represents a line segment.
 */
typedef struct {
    CGPoint start;
    CGPoint end;
} TKLineSegment;

/**
 Creates a line segment between two points.
 @param start The start point.
 @param end The end point.
 */
TKLineSegment TKLineSegmentMake(CGPoint start, CGPoint end);

/**
 Add a line segment to a path.
 @param path The path.
 @param line The line.
 */
void TKPathAddLineSegment(CGMutablePathRef path, TKLineSegment line);

/**
 @enum TKPointPosition
 Represents a point position acording to TKLineSegment.
 */
typedef enum TKPointPosition {
    TKPointPositionAboveLine,
    TKPointPositionBelowLine,
    TKPointPositionOnLine
} TKPointPosition;

/**
 Determines whether rect contains a point
 */
bool TKRectContainsPointWithDistanceType(CGRect rect, CGPoint point, TKPointDistanceType type);

/**
 Determines whether path contains a point
 */
bool TKPathContainsPointWithDistanceType(CGPathRef path, CGPoint point, TKPointDistanceType type);

/**
 Determines whether the position is above or on a line.
 @param position The position.
 */
bool TKPointPositionIsAboveOrOnLine(TKPointPosition position);

/**
 Determines whether the position is below or on a line.
 * @param position The position.
 */
bool TKPointPositionIsBelowOrOnLine(TKPointPosition position);

/**
 Returns the position of a point according to a line.
 @param point The point.
 @param line The line.
 */
TKPointPosition TKPointGetPosition(CGPoint point, TKLineSegment line);

/**
 @enum TKLineSegmentPosition
 Represents an enum that gives information regarding the relation between two lines.
 */
typedef enum TKLineSegmentPosition {
    TKLineSegmentPositionAboveLine,
    TKLineSegmentPositionBelowLine,
    TKLineSegmentPositionIntersected,
    TKLineSegmentPositionCoincidence
} TKLineSegmentPosition;

/**
 Determines the position of a line according to a baseline.
 @param line The line.
 @param baseline The baseline.
 */
TKLineSegmentPosition TKLineSegementGetPosition(TKLineSegment line, TKLineSegment baseline);

/**
 Represents a cubic bezier curve.
 */
typedef struct {
    CGPoint start;
    CGPoint controlPoint1;
    CGPoint controlPoint2;
    CGPoint end;
} TKBezierCubicCurve;

/*
 Rounds a CGPoint instance
 @param point The point
 */
CGPoint TKPointRound(CGPoint point);

/**
 Add a bezier curve to a path.
 @param path The path.
 @param curve The curve.
 */
void TKPathAddBezierCubicCurve(CGMutablePathRef path, TKBezierCubicCurve curve);

/**
 Creates a Cubic Bezier Curve.
 @param start The start point.
 @param controlPoint1 The first control point.
 @param constrolPoint2 The second control point.
 @param end The end point.
 */
TKBezierCubicCurve TKCubicBezierCurveMake(CGPoint start, CGPoint controlPoint1, CGPoint constrolPoint2, CGPoint end);

/**
 Returns the intersection point of two lines if they intersect.
 @param line1 The first line.
 @param line2 The second line.
 @param intersection The result.
 @return A boolean value that determines whether the lines are intersected.
 */
bool TKLineSegmentIntersection(TKLineSegment line1, TKLineSegment line2, CGPoint* intersection);

/**
 Returns the intersection points of a bezier curve with a line.
 @param curve The cubic bezier curve.
 @param line The line segment.
 @param count The number of intersection points.
 @return An array of intersection points.
 */
CGPoint* TKPathBezierCurveIntersectionWithLine(TKBezierCubicCurve curve, TKLineSegment line, size_t* count);

/**
 Determines the distance between two points.
 @param point1 The first point.
 @param point2 The second point.
 */
CGFloat TKGetDistanceBetweenPointsSquared(CGPoint point1, CGPoint point2);

/**
 Determines the distance between two points.
 @param point1 The first point.
 @param point2 The second point.
 */
CGFloat TKGetDistanceBetweenPoints(CGPoint point1, CGPoint point2);

/**
 Determines the distance between point accoring to distance type algorithm
 */
CGFloat TKGetDistanceWithTypeBetweenPoints(CGPoint point1, CGPoint point2, TKPointDistanceType type);

/**
 Determines the distance between point and line accoring to distance type algorithm
 */
CGFloat TKDistanceWithTypeFromPointToLine(CGPoint point, CGPoint lineA, CGPoint lineB, TKPointDistanceType type);

/**
 Returns the squared distance between a point and a line
 @param point The point.
 @param lineA The first point defining the line.
 @param lineB The second point defining the line.
 @return squared The distance between the point and the line.
 */
CGFloat TKDistanceFromPointToLineSquared(CGPoint point, CGPoint lineA, CGPoint lineB);

/**
 Creates a mutable path from points.
 @param points The array of points.
 @param count The array count.
 */
CGMutablePathRef TKPathCreateMutableLineFromPoints(CGPoint *points, size_t count);

/**
 Creates a spline path from points.
 @param points The array of points.
 @param count The array count.
 */
CGMutablePathRef TKPathCreateMutableSplineFromPoints(CGPoint *points, size_t count);

/**
 Subdivides a path to a subpaths splitted by the line
 @param path The path
 @param baseline The line
 */
CGPathRef TKPathSubdivide(CGPathRef path, TKLineSegment baseline);

/**
 Releases a path. Avoids static analyser warnings.
 @param path The path to be released
 */
void TKReleasePath(CGPathRef path);

#endif
