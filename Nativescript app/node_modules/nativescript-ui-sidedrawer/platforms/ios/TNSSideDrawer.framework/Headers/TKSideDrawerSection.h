//
//  TKSideDrawerSection.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKSideDrawerItem.h"

/**
 Defines a section that holds a collection of TKSideDrawerItem instances.
 */
@interface TKSideDrawerSection : TKSideDrawerItem

/**
 Returns the items of the current section.
 */
@property (nonatomic, strong, readonly) NSArray *items;

/**
 Adds an item inside the current section.
 @param item The TKSideDrawerItem that is added.
 */
- (void)addItem:(TKSideDrawerItem *)item;

/**
 Creates and adds an item inside the current section.
 @param title The title of the TKSideDrawerItem that is added.
 @return The added TKSideDrawerItem.
 */
- (TKSideDrawerItem *)addItemWithTitle:(NSString *)title;

/**
 Creates and adds an item inside the current section.
 @param title The title of the TKSideDrawerItem that is added.
 @param image The image of the TKSideDrawerItem that is added.
 @return The added TKSideDrawerItem.
 */
- (TKSideDrawerItem *)addItemWithTitle:(NSString *)title image:(UIImage *)image;

/**
 Removes an item from the current section.
 @param item The TKSideDrawerItem that is removed.
 */
- (void)removeItem:(TKSideDrawerItem *)item;

/**
 Removes all items from the current section.
 */
- (void)removeAllItems;

/**
 Inserts an item at a specified index.
 @param item TKSideDrawerItem that is insterted.
 @param index The index at which the item is inserted.
 */
- (void)insertItem:(TKSideDrawerItem *)item atIndex:(NSInteger)index;

@end
