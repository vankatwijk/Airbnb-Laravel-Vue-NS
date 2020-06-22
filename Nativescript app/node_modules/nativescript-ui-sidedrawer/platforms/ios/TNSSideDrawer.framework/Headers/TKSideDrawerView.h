//
//  TKSideDrawerView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKSideDrawer.h"

@class TKSideDrawer;

/**
 *  A class that represents a side drawer view.
 */
@interface TKSideDrawerView : UIView


/**
 *  Adds a UIView to the host UIView of the TKSideDrawerView instance.
 */
- (void)setMainView:(UIView * __nonnull)mainView;

/**
*  The view in which the main content is added as subview.
*/
@property (nonatomic, strong, nonnull) UIView *hostview;

/**
 *  An array containing the side drawers of the TKSideDrawerView instance.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray <__kindof TKSideDrawer *>  *sideDrawers;

/**
 *  The default side drawer created when the TKSideDrawerView is instantiated.
 */
@property (nonatomic, strong, readonly, nonnull) TKSideDrawer *defaultSideDrawer;

/**
 *  The main content.
 */
@property (nonatomic, strong, nonnull) UIView *mainView;

/**
 * Attach all sidedrawers to application's key window.
 */
- (void)attachDrawerToWindow;

/**
 * Detach all sidedrawers from application's key window.
 */
- (void)detachDrawerFromWindow;

/**
 *  Initilizes new TKSideDrawerView
 *  @param frame    Frame of the TKSideDrawerView.
 *  @param mainView The main content.
 *  @return TKSideDrawerView instance.
 */
- (instancetype __nonnull)initWithFrame:(CGRect)frame mainView:(UIView * __nonnull)mainView;

/**
 *  Add TKSideDrawer to the TKSideDrawerView instance at specified position.
 *  @param position The position of the TKSideDrawer.
 *  @return TKSideDrawer that was created.
 */
- (TKSideDrawer * __nonnull)addSideDrawerAtPosition:(TKSideDrawerPosition)position;

/**
 *  Adds TKSideDrawer to TKSideDrawerView.
 *  @param sideDrawer The TKSideDrawer that will be added.
 */
- (void)addSideDrawer:(TKSideDrawer * __nonnull)sideDrawer;

/**
 *  Remove TKSideDrawer from TKSideDrawerView.
 *  @param sideDrawer The TKSideDrawer to be removed.
 */
- (void)removeSideDrawer:(TKSideDrawer * __nonnull)sideDrawer;

/**
 *  Remove all TKSideDrawers from TKSideDrawerView.
 */
- (void)removeAllSideDrawers;

@end
