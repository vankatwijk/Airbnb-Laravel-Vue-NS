//
//  TKSideDrawerController.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKSideDrawer.h"

@class TKSideDrawer;

/**
 @discussion The container UIViewController that holds TKSideDrawer instance
 */
@interface TKSideDrawerController : UIViewController

/**
 The content controller of TKSideDrawerController.
 */
@property (nonatomic, strong, nullable) UIViewController *contentController;

/**
 The TKSideDrawer instance attached to TKSideDrawerController.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray *sideDrawers;

@property (nonatomic, strong, readonly, nonnull) TKSideDrawer *defaultSideDrawer;

/**
 Initializes the TKSideDrawerController with content.
 @param contentController TKSideDrawerController's content UIViewController.
 */
- (instancetype __nonnull)initWithContent:(UIViewController * __nonnull)contentController;

/**
 *  Add TKSideDrawer to the TKSideDrawerController instance at specified position.
 *  @param position The position of the TKSideDrawer.
 *  @return TKSideDrawer that was created.
 */
- (TKSideDrawer * __nonnull)addSideDrawerAtPosition:(TKSideDrawerPosition)position;

/**
 *  Adds TKSideDrawer to TKSideDrawerController.
 *  @param sideDrawer The TKSideDrawer that will be added.
 */
- (void)addSideDrawer:(TKSideDrawer * __nonnull)sideDrawer;

/**
 *  Remove TKSideDrawer from TKSideDrawerController.
 *  @param sideDrawer The TKSideDrawer to be removed.
 */
- (void)removeSideDrawer:(TKSideDrawer * __nonnull)sideDrawer;

/**
 *  Remove all TKSideDrawers from TKSideDrawerView.
 */
- (void)removeAllSideDrawers;

@end


