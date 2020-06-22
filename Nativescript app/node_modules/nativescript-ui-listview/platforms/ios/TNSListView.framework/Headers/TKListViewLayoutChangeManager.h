//
//  TKListViewLayoutChangeManager.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKListViewLayoutChange;

@interface TKListViewLayoutChangeManager : NSObject

@property (nonatomic, strong) NSMutableArray *changes;

@property (nonatomic, weak) UICollectionViewLayout *layout;

- (instancetype)initWithLayout:(UICollectionViewLayout*)layout;

- (void)addChange:(TKListViewLayoutChange*)change;

- (void)applyChange:(UICollectionViewLayoutAttributes*)attributes;

- (void)optimize;

- (NSIndexPath*)increaseIndexPath:(NSIndexPath*)indexPath;

- (NSIndexPath*)decreaseIndexPath:(NSIndexPath*)indexPath;

@end
