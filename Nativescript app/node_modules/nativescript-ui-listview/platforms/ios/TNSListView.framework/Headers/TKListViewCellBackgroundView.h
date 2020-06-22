//
//  TKListViewCellBackgroundView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKView.h"

@class TKCheckView;

@interface TKListViewCellBackgroundView : TKView

@property (nonatomic, strong, readonly, nonnull) TKCheckView *checkView;

@property (nonatomic, strong, nonnull) UIColor *checkViewFillColor;

@property (nonatomic) BOOL allowsMultipleSelection;

@property (nonatomic) BOOL isSelectedBackground;

@property (nonatomic) BOOL isVertical;

@property (nonatomic) CGFloat checkInset;

- (void)updateStyle;

- (void)updateCheckViewForSelection;

@end
