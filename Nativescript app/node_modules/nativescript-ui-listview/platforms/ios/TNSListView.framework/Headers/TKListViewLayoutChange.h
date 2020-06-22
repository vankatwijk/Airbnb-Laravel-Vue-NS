//
//  LayoutChange.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKListViewLayoutChangeManager;

@interface TKListViewLayoutChange : NSObject

@property (nonatomic) CGFloat deltaY;

@property (nonatomic) CGFloat deltaX;

@property (nonatomic) NSIndexPath *from;

@property (nonatomic) NSIndexPath *to;

- (instancetype)initWithIndexPath:(NSIndexPath*)indexPath andDelta:(CGFloat)delta;

- (NSComparisonResult)compare:(NSIndexPath*)first with:(NSIndexPath*)second;

- (BOOL)startIsBefore:(TKListViewLayoutChange*)object;

- (BOOL)intersectsWith:(TKListViewLayoutChange*)change;

- (BOOL)isValid;

- (BOOL)isAfter:(UICollectionViewLayoutAttributes*)attributes;

- (BOOL)startsWith:(UICollectionViewLayoutAttributes*)attributes;

- (BOOL)endsWith:(UICollectionViewLayoutAttributes*)attributes;

- (BOOL)itemIsBeforeEnd:(UICollectionViewLayoutAttributes*)attributes in:(TKListViewLayoutChangeManager*)layout;

- (BOOL)shouldApply:(NSIndexPath*)indexPath;

- (BOOL)apply:(UICollectionViewLayoutAttributes*)attributes;

- (void)applyToAll:(UICollectionViewLayout*)layout;

- (NSInteger)power;

@end
