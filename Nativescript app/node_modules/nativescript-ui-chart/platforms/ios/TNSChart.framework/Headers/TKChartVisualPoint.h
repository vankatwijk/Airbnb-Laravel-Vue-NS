//
//  TKChartVisualPoint.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKChartSeriesRender;

/**
 @discussion Represents a visual point rendered by TKChart cartesian series.
 */
@interface TKChartVisualPoint : NSObject<NSCopying, UIDynamicItem>

/**
 Returns a geometry point.
 */
@property (nonatomic, readonly) CGPoint CGPoint;

/**
 The x-coordinate of the visual point.
 */
@property (nonatomic) CGFloat x;

/**
 The y-coordinate of the visual point.
 */
@property (nonatomic) CGFloat y;

/**
 The scale factor of the visual point.
 */
@property (nonatomic) CGFloat scaleFactor;

/**
 The opacity of the visual point.
 */
@property (nonatomic) CGFloat opacity;

/**
 The center of the visual point.
 */
@property (nonatomic, readwrite) CGPoint center;

/**
 The bounds of the visual point. This property is required by the UIDynamicItem protocol that is used with UIKitDynamics.
 */
@property (nonatomic, readonly) CGRect bounds;

/**
 The affine transofmation matrix of the visual point. This property is required by the UIDynamicItem protocol that is used with UIKitDynamics.
 */
@property (nonatomic, readwrite) CGAffineTransform transform;

/**
 * The animator of the visual point used by UIKitDynamics animations.
 */
@property (nonatomic, strong) UIDynamicAnimator * __nullable animator;

/**
 Returns a double value associated wiht the point.
 */
@property (nonatomic, readonly) double doubleValue;

/**
 Initializes a visual point with its geometry point.
 @param point The point in screen coordinates.
 */
- (instancetype __nonnull)initWithPoint:(CGPoint)point;

@end
