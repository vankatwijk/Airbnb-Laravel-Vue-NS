//
//  TKListViewPullToRefreshView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKView.h"
/**
 An UIView containing an activity indicator to be displayed while user is waiting for data update after a pull-to-refresh gesture takes place.
 */
@interface TKListViewPullToRefreshView : UIView

@property (nonatomic, strong, readonly, nonnull) UIActivityIndicatorView *activityIndicator;

- (void)startAnimating;

- (void)stopAnimating;

@end
