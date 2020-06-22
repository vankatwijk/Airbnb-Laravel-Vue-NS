//
//  TKEntityPropertyGroupEditorsView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TNSCore/TKLayout.h"

/**
 @discussion A class that represents editors container.
 */
@interface TKEntityPropertyGroupEditorsView : UIView

/**
 A layout used to arrange the editors.
 */
@property (nonatomic) id<TKLayout> layout;

/**
 The items that will be arranged.
 */
@property (nonatomic, strong, readonly) NSArray *items;

/**
 Add an item to the editors view.
 @param item The item that will be added.
 */
- (void)addItem:(UIView *)item;

/**
 Add an item to the editors view at specified index.
 @param item The item that will be added.
 @param index The index of the item.
 */
- (void)addItem:(UIView *)item atIndex:(NSUInteger)index;

/**
 Remove an item from the editor view.
 @param item The item that will be removed.
 */
- (void)removeItem:(UIView *)item;

/**
 Remove all items from the editor view.
 */
- (void)removeAllItems;

/**
 Updates the layout.
 */
- (void)updateLayout;

@end
