//
//  TKListViewLoadOnDemandCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKListViewCell.h"

@interface TKListViewLoadOnDemandCell : TKListViewCell

@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;

- (void)updateState;

@end
