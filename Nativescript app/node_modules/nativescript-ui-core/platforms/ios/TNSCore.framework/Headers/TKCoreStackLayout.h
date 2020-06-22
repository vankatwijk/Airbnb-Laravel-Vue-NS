//
//  TKCoreStackLayout.h
//  TestLayout
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKCoreLayout.h"

/**
 @enum TKCoreStackLayoutOrientation
 @discussion Defines whether the stack layout should arrange its subviews horiontally or vertically.
 */
typedef NS_ENUM(NSInteger, TKCoreStackLayoutOrientation) {
    /**
     Items should be arranged horizontally.
    */
    TKCoreStackLayoutOrientationHorizontal,
    /**
     Items should be arranged vertically.
    */
    TKCoreStackLayoutOrientationVertical
};

/**
 @enum TKCoreStackLayoutItemOrder
 @discussion Defines whether to reverse the order in which subviews are arranged.
 */
typedef NS_ENUM(NSInteger, TKCoreStackLayoutItemOrder) {
    /**
     Items should be arranged in the same order they are added in the stack.
    */
    TKCoreStackLayoutItemOrderNormal,
    /**
     Items should be arranged in reverse order.
    */
    TKCoreStackLayoutItemOrderReverse
};

/**
 @discussion A class that is able to arrange subviews in a stack layout.
 */
@interface TKCoreStackLayout : NSObject<TKCoreLayout, NSFastEnumeration>

/**
 The layout orientation. It can be horizontal or vertical.

 @discussion The stack layout orientations are defined as follows:

    typedef enum {
        TKCoreStackLayoutOrientationHorizontal,     // Items should be arranged horizontally.
        TKCoreStackLayoutOrientationVertical        // Items should be arranged vertically.
    } TKCoreStackLayoutOrientation;

 */
@property (nonatomic, assign) TKCoreStackLayoutOrientation orientation;

/**
 The layout order. It can be normal or reversed.
 
 @discussion The stack layout item orders are defined as follows:

    typedef enum {
        TKCoreStackLayoutItemOrderNormal,       // Items should be arranged in the same order they are added in the stack.
        TKCoreStackLayoutItemOrderReverse       // Items should be arranged in reverse order.
    } TKCoreStackLayoutItemOrder;

 */
@property (nonatomic, assign) TKCoreStackLayoutItemOrder itemOrder;

/**
 A value that defines the spacing between the subviews.
 */
@property (nonatomic, assign) CGFloat itemSpacing;

/**
 The alignment mode that will be used when arranging the view.
 */
@property TKCoreLayoutAlignmentMode alignmentMode;

/**
 The streching mode that will be used when arranging the view.
 */
@property TKCoreLayoutStretchMode stretchMode;

/**
 The items count.
 @returns The items count.
 */
@property (nonatomic, readonly) NSInteger count;

/**
 The stack items.
 */
@property (nonatomic, strong, readonly) NSArray *items;

/**
 Adds a new stack layout item to the stack. This method does not add a subview to a superview. The developer should do this explicitly.
 @param item The item to be added.
 @return YES if successfull.
 */
- (BOOL)addItem:(id<TKCoreLayout>)item;

/**
 Inserts a new item at a specified position in the stack. This method does not add a subview to a superview. The developer should do this explicitly.
 @param item The item to be inserted.
 @param index The index at which the item will be inserted.
 @return YES if successfull.
 */
- (BOOL)insertItem:(id<TKCoreLayout>)item atIndex:(NSUInteger)index;

/**
 Removes an item from the stack.
 @param item The item to be removed.
 @return YES if successfull.
 */
- (BOOL)removeItem:(id<TKCoreLayout>)item;

/**
 Removes an item from the stack.
 @param index The index of the item to be removed.
 @return YES if successfull.
 */
-(BOOL)removeItemAtIndex:(NSUInteger)index;

/** 
 Removes all items from the stack. This method does not remove subviews from their superview.
 */
- (void)removeAllItems;

/**
 Gets an item at a specific index.
 @param index The index of the item.
 @return An instance of TKCoreStackLayoutItem if successfull.
 */
- (id<TKCoreLayout>)itemAtIndex:(NSUInteger)index;

/**
 Gets the index of specific item.
 @param layoutItem The item.
 @return The item index if successfull.
 */
- (NSInteger)indexOfItem:(id<TKCoreLayout>)layoutItem;

/**
 The last item in the layout
 @returns The last item in the layout
 */
- (id<TKCoreLayout>)lastItem;

@end
