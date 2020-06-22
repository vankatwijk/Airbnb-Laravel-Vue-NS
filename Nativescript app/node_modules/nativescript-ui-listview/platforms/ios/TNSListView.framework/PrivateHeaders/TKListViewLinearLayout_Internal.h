//
//  TKListViewLinearLayout_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKListViewLinearLayout.h"

@class TKListViewCell;

@interface TKListViewLinearLayout()

@property (nonatomic, strong) NSMutableDictionary *itemAttributes;

@property (nonatomic, strong) NSMutableArray *itemAttributesArray;

@property (nonatomic, strong) NSMutableArray *headerAttributes;

@property (nonatomic, strong) NSMutableArray *footerAttributes;

@property (nonatomic) CGRect contentFrame;

@property (nonatomic, strong) NSMutableArray *deleteIndexPaths;

@property (nonatomic, strong) NSMutableArray *insertIndexPaths;

@property (nonatomic) BOOL isInitialLayoutPreparing;

- (void)initLayout;

- (void)layoutSections;

- (void)initSectionLayout;

- (CGPoint)updateLocationAtSectionEnd:(CGPoint)currentLocation;

- (CGRect)alignItemInRect:(CGRect)rect proposedSize:(CGSize)proposedSize;

- (void)animateOnScroll:(TKListViewCell*)cell directionIsForward:(BOOL)isForward;

- (void)moveItem:(NSIndexPath*)itemIndexPath toToIndexPath:(NSIndexPath*)newItemIndexPath;

- (void)endItemMove;

- (CGSize)getItemSizeForIndexPath:(NSIndexPath*)indexPath;

- (BOOL)shouldMeasure:(NSIndexPath*)indexPath;

- (BOOL)shouldSkipItemAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)hasGapBeforeItemAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)hasGapAfterItemAtIndexPath:(NSIndexPath *)indexPath lastInSection:(BOOL)lastInSection;

- (void)updateContentSizeByInsets:(UIEdgeInsets) insets;

- (CGFloat)getPointAfterSafeAreaInsetsByX:(CGFloat)originalX;

@end
