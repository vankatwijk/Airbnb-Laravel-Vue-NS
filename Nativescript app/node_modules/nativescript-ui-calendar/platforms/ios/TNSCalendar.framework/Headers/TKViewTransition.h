//
//  TKCalendarFXView.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//


@class TKViewTransition;


/**
 * @enum TKViewTransitionOrientation
 * @discussion Represents an enum that defines the available transition orientation options.
 */
typedef NS_ENUM(NSInteger, TKViewTransitionOrientation)
{
    /**
     *  The transition orientation is horizontal.
     */
    TKViewTransitionOrientationHorizontal,
    
    /**
     *  The transition orientation is vertical.
     */
    TKViewTransitionOrientationVertical
    
};

/**
 * @enum TKViewTransitionDirection
 * @discussion Represents an enum that defines the available transition direction options.
 */
typedef NS_ENUM(NSInteger, TKViewTransitionDirection)
{
    /**
     *  The transition direction is forward.
     */
    TKViewTransitionDirectionForward,
    
    /**
     *  The transition direction is backward.
     */
    TKViewTransitionDirectionBackward
    
};



/**
 *  @discussion A transition effect between two states of the same view.
 */
@interface TKViewTransition : UIView

/**
 *  Gets or sets the transition duration.
 */
@property (nonatomic) CGFloat transitionDuration;

/**
 *  Returns the transition orientation.
 
  @discussion The available orientation modes are specified below:
 
 typedef enum {
 TKViewTransitionOrientationHorizontal,  // The transition orientation is horizontal.
 TKViewTransitionOrientationVertical     // The transition orientation is vertical.
 } TKViewTransitionOrientation
 
 */
- (TKViewTransitionOrientation) orientation;

/**
 *  Returns the transition direction.
 
  @discussion The available direction modes are specified below:
 
 typedef enum {
 TKViewTransitionDirectionForward,   // The transition direction is forward.
 TKViewTransitionDirectionBackward   // The transition direction is backward.
 } TKViewTransitionDirection

 */
- (TKViewTransitionDirection) direction;

/**
 *  Returns YES when the transition is forward.
 */
@property (nonatomic, readonly) BOOL isForward;

/**
 *  Returns YES when the transition is vertical.
 */
@property (nonatomic, readonly) BOOL isVertical;

@end
