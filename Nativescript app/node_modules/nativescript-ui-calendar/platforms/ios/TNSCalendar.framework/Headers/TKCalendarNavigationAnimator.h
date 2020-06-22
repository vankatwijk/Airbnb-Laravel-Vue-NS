//
//  TKCalendarNavigationAnimator.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

/**
 @discussion A class which implements the UIViewControllerAnimatedTransitioning and allows iOS 7 calendar style animation. This class is used internally.
 */
@interface TKCalendarNavigationAnimator : NSObject <UIViewControllerAnimatedTransitioning>

/**
 Defines whether this is a forward or backward animation.
 */
@property (nonatomic) BOOL presenting;

/**
 The operation for which this animator is applied.
 */
@property (nonatomic) UINavigationControllerOperation operation;

@end
