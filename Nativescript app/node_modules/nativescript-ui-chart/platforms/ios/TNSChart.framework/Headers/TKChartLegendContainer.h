//
//  TKChartLegendContainer.h
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartLegendItem.h"
#import "TNSCore/TKCoreStackLayoutView.h"

@class TKChartPaletteItem;

/**
 @discussion The container which contains legend items.
 */
@interface TKChartLegendContainer : TKCoreStackLayoutView

/**
 Set preferred size for the container.
 */
@property (nonatomic) CGSize preferredSize;

/**
 The items count.
 */
@property (nonatomic, readonly) NSUInteger itemCount;

/**
 Adds a legend item.
 @param item The item to add to the legend container.
 */
- (void)addItem:(TKChartLegendItem * __nonnull)item;

/**
 Removes all items contained in this container.
 */
- (void)removeAllItems;

/**
 Returns the item at a specified index.
 @param index The index of the item that the method should return.
 @return An instance of TKLegendItem which represents the legend item.
 */
- (TKChartLegendItem * __nullable)itemAtIndex:(NSUInteger)index;

/**
 Returns the index for specific item.
 @param item The item.
 @return The item index.
 */
- (NSInteger)indexOfItem:(TKChartLegendItem* __nonnull)item;

@end
