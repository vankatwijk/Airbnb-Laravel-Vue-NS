//
//  TKChartAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKChart;
@class TKChartAxis;

/**
 @enum TKChartAnnotationZPosition
 @discussion The annotation's position according to the series.
 */
typedef NS_ENUM(NSInteger, TKChartAnnotationZPosition) {
    /**
     The annotation is rendered below the series (default).
     */
    TKChartAnnotationZPositionBelowSeries,
    /**
     The annotation is rendered above the series.
     */
    TKChartAnnotationZPositionAboveSeries
};

/**
  The base class for annotations.
 */
@interface TKChartAnnotation : NSObject

/**
 Lays out the annotation within the chart plot area.
 @param bounds The bounds of the chart plot area.
 @param chart The chart where this annotation will be rendered.
 @param layer The layer where this annotation will be rendered.
 */
- (void)layoutInRect:(CGRect)bounds forChart:(TKChart* __nullable)chart inLayer:(CALayer* __nonnull)layer;

/**
 Draws the annotation by using the specified drawing context.
 @param context The drawing context to use when rendering the annotation.
 */
- (void)drawInContext:(CGContextRef __nonnull)context;

/**
 Tells the annotation that it was added to the chart.
 @param chart The TKChart instance that owns this annotation.
 @param layer The layer where the annotation will be rendered.
 */
- (void)annotationWasAddedToChart:(TKChart* __nonnull)chart withLayer:(CALayer* __nonnull)layer;

/**
 Tells the annotation that it will be removed from the chart.
 @param chart The TKChart instance that owns this annotation.
 */
- (void)annotationWillBeRemovedFromChart:(TKChart* __nonnull)chart;

/**
 The axis coordinate of the specified value by using the specified bounds and axis.
 @param value The value to locate.
 @param axis The axis where the value is located.
 @param bounds The bounds of the plot area to use.
 @return A numeric value which specifies the axis coordinate.
 */
- (CGFloat)locationOfValue:(id __nonnull)value withAxis:(TKChartAxis* __nonnull)axis inBounds:(CGRect)bounds;

/**
 Indicates whether the annotation is visible.
 */
@property (nonatomic, assign) BOOL hidden;

/**
 Gets or sets a value which determines the z-order position of the annotation. 
 Every annotation can be positioned below or above the series collection. 

 @discussion The z-order modes are defined as follows:

typedef enum {
    TKChartAnnotationZPositionBelowSeries,  // The annotation is rendered below the series (default).
    TKChartAnnotationZPositionAboveSeries   // The annotation is rendered above the series.
} TKChartAnnotationZPosition;
 
 */
@property (nonatomic, assign) TKChartAnnotationZPosition zPosition;

@end
