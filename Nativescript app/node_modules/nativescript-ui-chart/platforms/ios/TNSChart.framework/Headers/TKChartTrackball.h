//
//  TKChartTrackball.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKChart;
@class TKChartTrackballLineAnnotation;
@class TKChartTrackballTooltipAnnotation;
@class TKChartSeries;
@class TKChartDataPoint;

/**
  The trackball snapping modes.
 */
typedef NS_ENUM(NSInteger, TKChartTrackballSnapMode) {
    
    /**
     Only the closest point is selected.
     */
    TKChartTrackballSnapModeClosestPoint,
    /**
     All points within the specified range are selected.
     */
    TKChartTrackballSnapModeAllClosestPoints
    
};

/**
  The trackball orientation modes.
 */
typedef NS_ENUM(NSInteger, TKChartTrackballOrientation) {
    
    /**
     The trackball searches for points with equal x coordinates.
    */
    TKChartTrackballOrientationHorizontal,
    
    /**
     The trackball searches for points with equal y coordinates.
     */
    TKChartTrackballOrientationVertical
    
};

/**
 The trackball hide modes.
 */
typedef NS_ENUM(NSInteger, TKChartTrackballHideMode) {
    
    /**
     The trackball will hide when the touch event finishes.
     */
    TKChartTrackballHideModeOnTouchUp,
    
    /**
     The trackball will hide when a second touch event occurs.
     */
    TKChartTrackballHideModeOnSecondTouch
};


/**
 The trackball used in TKChart.
 */
@interface TKChartTrackball : NSObject

/**
 Initializes the trackball with a TKChart instance.
 @param chart The chart which owns this annotation.
 */
- (instancetype __nonnull)initWithChart:(TKChart* __nonnull)chart;

/**
 Displayes the trackball by specifying a plot area coordinates.
 @param point The point where the trackball should locate.
 */
- (void)showAtPoint:(CGPoint)point;

/**
 Hides the trackball.
 */
- (void)hide;

/**
 Returns a value indicating whether the trackball is currently visible (read-only).
 */
@property (nonatomic, readonly) BOOL isVisible;

/**
 Returns the line annotation used to present the trackball (read-only).
 */
@property (nonatomic, strong, readonly) TKChartTrackballLineAnnotation * __nonnull line;

/**
 Returns the tooltip annotation used to present the trackball (read-only).
 */
@property (nonatomic, strong, readonly) TKChartTrackballTooltipAnnotation * __nonnull tooltip;

/**
 Gets or sets the trackball snap mode.
 
 @discussion The available snap modes are specified below:
 
 typedef enum {
     TKChartTrackballSnapModeClosestPoint,     // Only the closest point is selected
     TKChartTrackballSnapModeAllClosestPoints, // All points within the specified range are selected
 } TKChartTrackballSnapMode;
 
 */
@property (nonatomic, assign) TKChartTrackballSnapMode snapMode;

/**
 The trackball orientation.
 
 @discussion The available orientation modes are specified below:
 
 typedef enum {
     TKChartTrackballOrientationHorizontal, // The trackball will search for points with equal x coordinates.
     TKChartTrackballOrientationVertical,   // The trackball will search for points with equal y coordinates.
 } TKChartTrackballOrientation;
 
 */
@property (nonatomic, assign) TKChartTrackballOrientation orientation;


/**
  Default is 0.5. Time in seconds the fingers must be held down for the gesture to be recognized
 */
@property (nonatomic, assign) CGFloat minimumPressDuration;

/**
 The trackball hide mode.
 
 @discussion The available hide modes are specified below:
 
 typedef enum {
    TKChartTrackballHideOnTouchUp,
    TKChartTrackballHideOnSecondTouch
 } TKChartTrackballHideMode

 */
@property (nonatomic, assign) TKChartTrackballHideMode hideMode;

/**
 If set to a nonzero value the trackball will show only when the touch event occured in the specified distance to an actual point in chart.
 */
@property (nonatomic, assign) CGFloat marginForHitDetection;

@end
