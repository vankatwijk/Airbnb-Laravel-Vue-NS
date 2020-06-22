//
//  TKSideDrawerTransition.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKSideDrawer.h"

/**
 @discussion This is a base class that represents a transition used to show and dismiss TKSideDrawer.
 */
@interface TKSideDrawerTransition : NSObject

/**
 TKSideDrawer that will be show or dismissed.
 */
@property (nonatomic, weak, null_unspecified) TKSideDrawer *sideDrawer;

/**
 Creates new TKSideDrawerTransition instance.
 @param sideDrawer The sideDrawer that will be shown and dismiss by this transition.
 @return TKSideDrawerTransition instance.
 */
- (instancetype __nonnull)initWithSideDrawer:(TKSideDrawer * __nonnull)sideDrawer;

/**
 Shows the TKSideDrawer instance.
 */
- (void)show;

/**
 Dismisses the TKSideDrawer intance.
 */
- (void)dismiss;

/**
 Handels a gesture.
 @param gestureRecognizer The gesture that will be handled.
 */
- (void)handleGesture:(UIGestureRecognizer * __nonnull)gestureRecognizer;

/**
 Called when the transition is about to begin.
 @param showing Determines if the sideDrawer is about to show or dismiss.
 */
- (void)transitionBegan:(BOOL)showing;

/**
 Called when the transition ended.
 @param showing Determines if the sideDrawer is shown or dismissed.
 */
- (void)transitionEnded:(BOOL)showing;

@end
