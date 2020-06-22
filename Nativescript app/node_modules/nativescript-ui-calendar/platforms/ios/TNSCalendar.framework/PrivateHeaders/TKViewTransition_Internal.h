//
//  TKViewTransition_Internal.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKViewTransition.h"

/**
 @discussion The methods declared by the TKViewTransitionDelegate protocol allow the adopting delegate to respond to notifications from TKViewTransition.
 */
@protocol TKViewTransitionDelegate <NSObject>

/**
 *  Called when the transition finishes.
 *
 *  @param transition The transition where this event occured.
 *  @param isCanceled A value indicating whether the transition was cancelled.
 */
- (void)transition:(TKViewTransition*)transition isCanceled:(BOOL)isCanceled;

@end



@interface TKViewTransition ()

/**
 *  Gets or sets the transition direction.
 */
@property (nonatomic) TKViewTransitionDirection direction;

/**
 *  Gets or sets the transition orientation.
 */
@property (nonatomic) TKViewTransitionOrientation orientation;

/**
 A delegate for receiving notifications.
 */
@property (nonatomic, strong) id<TKViewTransitionDelegate> delegate;

/**
 *  Crops an image with the specified rectangle.
 *
 *  @param img    The image to crop.
 *  @param bounds The rectangle to use when cropping.
 *  @param flip   A value that determines whether to flip the cropped image.
 *
 *  @return An instance of UIImage.
 */
+ (UIImage*)cropImg:(UIImage*)img withRect:(CGRect)bounds shouldFlip:(BOOL)flip orientation:(TKViewTransitionOrientation)orientation;

/**
 *  Begins transition with from and to images and specified direction.
 *
 *  @param before    An image representing the before state.
 *  @param after     An image representing the after state.
 *  @param direction The transition direction.
 */
- (void)beginTransitionFrom:(UIImage*)before to:(UIImage*)after direction:(TKViewTransitionDirection)direction;

/**
 *  Updates the transition to specific point. Call this method when doing an interactive transition to update the transition status.
 *
 *  @param percent The transition point (between 0 and 1)
 */
- (void)updateTransition:(CGFloat)percent;

/**
 *  Finishes a transition.
 */
- (void)finishTransition;

/**
 *  Cancels a transition.
 */
- (void)cancelTransition;

/**
 *  Applies a non-interactive transition.
 */
- (void)transitionWithAnimation;

/**
 *  Completes a transition. This method should be called to finish an interctive transition.
 *
 *  @param isCanceled A value indicating whether the transition was cancelled.
 */
- (void)completeTransition:(BOOL)isCanceled;

@end