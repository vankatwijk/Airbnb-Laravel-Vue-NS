//
//  TKListViewCell_internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKListViewCell.h"

@interface TKListViewCell ()

@property (readonly, nonatomic) CGPoint swipeOffset;

@property (nonatomic, strong) UIPanGestureRecognizer *panRecognizer;

@property (nonatomic) BOOL wasSelected;

@property (nonatomic) BOOL swiping;

- (void)resetSwipe;

- (void)initReorderHandleAndBackgroundView;

@end

