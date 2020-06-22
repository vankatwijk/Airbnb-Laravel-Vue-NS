//
//  TKSideDrawerTransition_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKSideDrawerTransition.h"

@interface TKSideDrawerTransition()

@property (nonatomic) BOOL isAnimating;

@property (nonatomic) BOOL isPanning;

@property (nonatomic) CGPoint hostviewIdentityCenter;

@property (nonatomic) CGPoint sideDrawerIdentityCenter;

@property (nonatomic) CGFloat maskOpacity;

@property (nonatomic) BOOL didMaskHostview;

@property (nonatomic) BOOL didShadowHostview;

@property (nonatomic) BOOL didShadowSideDrawer;

- (CGRect)bounds;

- (CGRect)hostviewFrame;

- (UIView *)hostview;

- (CGRect)sideDrawerInitialFrame;

- (CGPoint)hostviewFinalCenter;

- (CGPoint)sideDrawerFinalCenter;

- (void)setShadow:(BOOL)shadow view:(UIView *)view;

- (void)setMaskForView:(UIView*)view  mask:(BOOL)mask;

- (void)notifyDelegate:(BOOL)showing;

- (void)panSideDrawerWithGesture:(UIPanGestureRecognizer *)gesture;

- (void)dimHostview;

- (void)refreshOnLayoutChange;

@end
