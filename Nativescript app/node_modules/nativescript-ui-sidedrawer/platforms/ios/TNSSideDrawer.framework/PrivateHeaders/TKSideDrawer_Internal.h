//
//  TKSideDrawer_Internal.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKSideDrawer.h"

@class TKStyleSheet;

@interface TKSideDrawer()

@property (nonatomic, strong) TKStyleSheet *styleSheet;

@property (nonatomic, weak) UIViewController *viewController;

@property (nonatomic, strong) TKSideDrawerTransition *singleTransition;

@property (nonatomic, weak) UIView *hostview;

- (instancetype)initWithViewController:(UIViewController *)viewController hostview:(UIView *)hostview;

- (instancetype)initWithSideDrawerView:(UIView *)sideDrawerView hostview:(UIView *)hostview;

- (void)notifyDidPanDelegate;

@end
