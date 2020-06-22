//
//  TKSideDrawerEdgePanRecognizer.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKSideDrawer;

@interface TKSideDrawerEdgePanRecognizer : UIPanGestureRecognizer

@property (nonatomic) CGFloat treshold;

- (instancetype)initWithSideDrawer:(TKSideDrawer *)sideDrawer;

@end
