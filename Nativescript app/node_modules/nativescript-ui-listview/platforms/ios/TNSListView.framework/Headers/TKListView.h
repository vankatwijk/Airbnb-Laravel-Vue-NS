//
//  TKListView.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKListView;
@class TKListViewCell;
@class TKListViewReusableCell;
@class TKListViewPullToRefreshView;
@class TKListViewLoadOnDemandView;

#import "TKCollectionView.h"
#import "TKListViewLinearLayout.h"

/**
 This constant takes place in dequeing supplementary views for group headers.
 */
extern NSString *const __nonnull TKListViewElementKindSectionHeader;

/**
 This constant takes place in dequeing supplementary views for group footers.
 */
extern NSString *const __nonnull TKListViewElementKindSectionFooter;

/**
 @enum TKListViewReorderMode
 @discussion Defines the reorder behavior of TKListView.
 */
typedef NS_ENUM(NSInteger, TKListViewReorderMode)
{
    /**
     An item can be reordered with a handle.
     */
    TKListViewReorderModeWithHandle,

    /**
     An item can be reordered after a long press gesture.
     */
    TKListViewReorderModeWithLongPress,
};

/**
 @enum TKListViewSelectionBehavior
 @discussion Defines the selection behavior of TKListView.
 */
typedef NS_ENUM(NSInteger, TKListViewSelectionBehavior)
{
    /**
     No selection is allowed.
     */
    TKListViewSelectionBehaviorNone,
    /**
     Selection on press.
     */
    TKListViewSelectionBehaviorPress,
    /**
     Selection on long press.
     */
    TKListViewSelectionBehaviorLongPress,
};

/**
 @enum TKListViewLoadOnDemandMode
 @discussion Defines the load on demand mode used in TKListView.
 */
typedef NS_ENUM(NSInteger, TKListViewLoadOnDemandMode)
{
    /**
     Load on demand is disabled.
     */
    TKListViewLoadOnDemandModeNone,
    
    /**
     More data will be loaded in list view after clicking on load on demand cell.
     */
    TKListViewLoadOnDemandModeManual,
    
    /**
     More data will be loaded in list view automatically while scrolling.
     */
    TKListViewLoadOnDemandModeAuto
};

/**
 The TKListViewDelegate protocol defines methods that allow you to manage the selection of items in TKListView, to perform actions on those items, and respond to interaction with those items.
 */
@protocol TKListViewDelegate <UIScrollViewDelegate>
@optional

- (void)listView: (TKListView* __nonnull)listView scrollViewDidScroll:(UIScrollView* __nonnull)scrollView;                                               // any offset changes

// called on start of dragging (may require some time and or distance to move)
- (void)listView: (TKListView* __nonnull)listView scrollViewWillBeginDragging:(UIScrollView* __nonnull)scrollView;
// called on finger up if the user dragged. decelerate is true if it will continue moving afterwards
- (void)listView: (TKListView* __nonnull)listView scrollViewDidEndDragging:(UIScrollView* __nonnull)scrollView willDecelerate:(BOOL)decelerate;
// called on finger up as we are moving
- (void)listView: (TKListView* __nonnull)listView scrollViewDidEndDecelerating:(UIScrollView * __nonnull)scrollView;


/**
 * Returns a boolean value indicating whether the specified item should be highlighted.
 @param listView The TKListView instance requesting this information.
 @param indexPath The index path of the item about to be highlighted.
 
 @return YES if the item should be highlighted.
 */
- (BOOL)listView:(TKListView* __nonnull)listView shouldHighlightItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 This method is called after highliting an item.
 @param listView The TKListView instance.
 @param indexPath The index path of the highlighted item.
 */
- (void)listView:(TKListView * __nonnull)listView didHighlightItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 This method is called after unhighliting an item.
 @param listView The TKListView instance.
 @param indexPath The index path of the unhighlighted item.
 */
- (void)listView:(TKListView * __nonnull)listView didUnhighlightItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 Returns a boolean value indicating whether the specified item should be selected.
 @param listView The TKListView instance requesting this information.
 @param indexPath The index path of the item about to be selected.
 
 @return YES if the item should be selected.
 */
- (BOOL)listView:(TKListView * __nonnull)listView shouldSelectItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 Returns a boolean value indicating whether the specified item should be deselected.
 @param listView The TKListView instance requesting this information.
 @param indexPath The index path of the item about to be deselected.
 
 @return YES if the item should be selected.
 */
- (BOOL)listView:(TKListView * __nonnull)listView shouldDeselectItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 This method is called after selecting an item.
 @param listView The TKListView instance.
 @param indexPath The index path of the selected item.
 */
- (void)listView:(TKListView * __nonnull)listView didSelectItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 This method is called after deselecting an item.
 @param listView The TKListView instance.
 @param indexPath The index path of the deselected item.
 */
- (void)listView:(TKListView * __nonnull)listView didDeselectItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 This method is called when the user starts reordering a cell.
 @param listView The TKListView instance.
 @param indexPath The index path of the item.
 */
- (BOOL)listView:(TKListView * __nonnull)listView shouldReorderItem:(TKListViewCell* __nonnull)cell atIndexPath:(NSIndexPath* __nonnull)indexPath;

/**
 This method is called when list view is about to reorder an item.
 @param listView The TKListView instance.
 @param indexPath The index path of the item.
 @return YES if the item can be reordered, otherwise NO
 */
- (BOOL)listView:(TKListView * __nonnull)listView willReorderItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 This method is called after reordering an item an item.
 @param listView The TKListView instance.
 @param originalIndexPath The index path we move the item from.
 @param targetIndexPath The index path we move the item to.
 */
- (void)listView:(TKListView * __nonnull)listView didReorderItemFromIndexPath:(NSIndexPath * __nonnull)originalIndexPath toIndexPath:(NSIndexPath * __nonnull)targetIndexPath;

/**
 This method is called when the user starts swiping a cell.
 @param listView The TKListView instance.
 @param cell The TKListViewCell instance being swiped.
 @param indexPath The index path of the cell being swiped.
 */
- (BOOL)listView:(TKListView * __nonnull)listView shouldSwipeCell:(TKListViewCell* __nonnull)cell atIndexPath:(NSIndexPath* __nonnull)indexPath;

/**
 This method is called when the user swipes a cell. This method is called after shouldSwipeCell and before didFinishSwipingCell.
 @param listView The TKListView instance.
 @param cell The TKListViewCell instance being swiped.
 @param indexPath The index path of the cell being swiped.
 @param offset The swipe offset.
 */
- (void)listView:(TKListView * __nonnull)listView didSwipeCell:(TKListViewCell* __nonnull)cell atIndexPath:(NSIndexPath* __nonnull)indexPath withOffset:(CGPoint)offset;

/**
 This method is called after the user has finished swiping a cell.
 @param listView The TKListView instance.
 @param cell The TKListViewCell instance being swiped.
 @param indexPath The index path of the cell being swiped.
 @param offset The swipe offset.
 */
- (void)listView:(TKListView * __nonnull)listView didFinishSwipeCell:(TKListViewCell * __nonnull)cell atIndexPath:(NSIndexPath * __nonnull)indexPath withOffset:(CGPoint)offset;

/**
 This method is called when the user pulls the list view to refresh its data.
 @param listView The TKListView instance.
 @param offset The pull offset.
 */
- (void)listView:(TKListView * __nonnull)listView didPullWithOffset:(CGFloat)offset;

/**
 This method is called after the user long pressed a cell.
 @param listView The TKListView instance.
 @param cell The TKListViewCell instance being long pressed.
 @param indexPath The index path of the cell being long pressed.
 */
- (void)listView:(TKListView * __nonnull)listView didLongPressCell:(TKListViewCell* __nonnull) cell atIndexPath:(NSIndexPath* __nonnull) indexPath;

/**
 Returns a boolean value indicating whether more data will be loaded.
 Called after the user requested loading more data on demand by scrolling over the cellBuffer limit size.
 @param listView The TKListView instance.
 @param indexPath The index path where the buffer limit size was reached.
 */
- (BOOL)listView:(TKListView * __nonnull)listView shouldLoadMoreDataAtIndexPath:(NSIndexPath* __nonnull) indexPath;

/**
 Returns a boolean value indicating whether listView should display activity indicator and wait for fresh data.
 Called after user performs pull-to-refresh gesture.
 @param listView The listview component instance requesting the fresh data.
 */
- (BOOL)listViewShouldRefreshOnPull:(TKListView * __nonnull)listView;

/**
 This method is called before ReloadDataMethod of the collectionView.
 @param listView The TKListView instance.
 */
- (void)willReloadData:(TKListView * __nonnull)listView;

/**
 This method is called before ReloadDataMethod of the collectionView.
 @param listView The TKListView instance.
 */
- (void)didReloadData:(TKListView * __nonnull)listView;

/**
 This method is called before the animation of adding new objects has started.
 @param indexPaths An array of NSIndexPath objects.
 */
- (void) willInsertItemsAtIndexPaths:(NSArray *) indexPaths;

/**
 This method is called after the animation of adding new objects has complated.
 */
- (void) didInsertItems;

@end

/**
 A delegate class exposing mothods to provide cells and supplementary views matching the source data.
 */
@protocol TKListViewDataSource <NSObject>
@required

/**
 Returns the number of items conatined in specific section.
 @param listView The TKListView instance requesting the information.
 @param section The index for the section.
 */
- (NSInteger)listView:(TKListView * __nonnull)listView numberOfItemsInSection:(NSInteger)section;


/**
 Returns a TKListViewCell instance for a given index path.
 The cell that is returned must be retrieved from a call to -dequeueReusableCellWithReuseIdentifier:forIndexPath:
 @param listView The TKListView instance requesting the cell.
 @param indexPath The index path we need a cell for.
 */
- (TKListViewCell * __nullable)listView:(TKListView * __nonnull) listView cellForItemAtIndexPath:(NSIndexPath * __nonnull)indexPath isInitial:(BOOL) isInitial;

@optional

/**
 Returns the number of sections.
 @param listView The TKListView instance requesting the cell.
 */
- (NSInteger)numberOfSectionsInListView:(TKListView * __nonnull)listView;

/**
 Returns a view to be used as a section header or footer in TKListView.
 The cell that is returned must be retrieved from a call to -dequeueReusableSupplementaryViewOfKind:withReuseIdentifier:forIndexPath:
 @param listView The TKListView instance requesting the cell.
 @param kind The kind of the supplementary view e.g. TKListViewElementKindSectionHeader or TKListViewElementKindSectionFooter
 @param indexPath The index path we need a cell for.
 */
- (TKListViewReusableCell * __nullable)listView:(TKListView * __nonnull)listView viewForSupplementaryElementOfKind:(NSString * __nonnull)kind atIndexPath:(NSIndexPath * __nonnull)indexPath;

@end

/**
 @discussion TKListView provides means for displaying lists of data. The items of the list can be arranged in a columns layout or wrap layout. It provides UI virtualization, pull-to-refresh, load-on-demand, cells swipe, cell reorder, single/multiple selection, grouping.
 */
@interface TKListView : UIView <UICollectionViewDataSource, UICollectionViewDelegate>

/**
 A delegate used to manage the selection of items in TKListView, perform actions on those items and respond to interaction with those items.
 */
@property (nonatomic, weak, nullable) id<TKListViewDelegate> delegate;

/**
 A datasource delegate used to provide data for the cells, headers and footers.
 */
@property (nonatomic, weak, nullable) id<TKListViewDataSource> dataSource;

/**
 The layout object used to arrange cells.
 */
@property (nonatomic, strong) UICollectionViewLayout * __nonnull layout;

/**
 Indicates whether user is able to select multiple items.
 */
@property (nonatomic) BOOL allowsMultipleSelection;

/**
 Indicates whether user is able to reorder cells.
 */
@property (nonatomic) BOOL allowsCellReorder;

/**
 Indicates whether the end-user is able to swipe cells.
 */
@property (nonatomic) BOOL allowsCellSwipe;

/**
 Restricts the swipe direction based on the current scroll orientation.
 */
@property (nonatomic) BOOL autoRestrictSwipeDirection;

/**
 Indicates whether user is able to perform the pull-to-refresh gesture.
 */
@property (nonatomic) BOOL allowsPullToRefresh;

/**
 Defines whether to deselect an already selected item with a second tap. This property value is respected only when using single selection mode.
 */
@property (nonatomic) BOOL deselectOnSecondTap;

/**
 Defines the reorder mode.
 */
@property (nonatomic) TKListViewReorderMode reorderMode;

/**
 The maximum distance a cell can be swiped by the end-user.
 */
@property (nonatomic) UIEdgeInsets cellSwipeLimits;

/**
 The cell swipe threshold - the distance defining whether the cell will revert to original position or animate to the swipe limits if the end-user does not finish the swipe gesture.
 */
@property (nonatomic) CGFloat cellSwipeThreshold;

/**
 The cell swipe animation duration.
 */
@property (nonatomic) CGFloat cellSwipeAnimationDuration;

/**
 The distance from the edge where autoscroll commences while dragging/reordering a cell.
 */
@property (nonatomic) CGFloat autoScrollTreshold;

/**
 The pull distance at which pull-to-refresh activates.
 */
@property (nonatomic) CGFloat pullToRefreshTreshold;

/**
 Defines the load on demand mode.
 */
@property (nonatomic) TKListViewLoadOnDemandMode loadOnDemandMode;

/**
 Defines the number of cells from the bottom of TKListView up at which to start requesting load-on-demand data.
 */
@property (nonatomic) NSInteger loadOnDemandBufferSize;

/**
 The content insets relative to its view size.
 */
@property (nonatomic) UIEdgeInsets contentInset;

/**
 The content offset.
 */
@property (nonatomic) CGPoint contentOffset;

/**
 The collection view used by the component.
 */
@property (nonatomic, strong) TKCollectionView * __nonnull collectionView;


/**
 Defines the scroll direction. Applicable if the current layout supports it.
 */
@property (nonatomic) TKListViewScrollDirection scrollDirection;

/**
 Defines whether cells are selected on press, long press, or can't be selected at all.
 */
@property (nonatomic) TKListViewSelectionBehavior selectionBehavior;

/**
 The UIView containing the activity indicator while TKListView is refreshing data after the pull-to-refresh gesture.
 */
@property (nonatomic, strong) TKListViewPullToRefreshView * __nonnull pullToRefreshView;

/**
 The UIView containing the activity indicator while TKListView is loading data on demand and has scrolled to the end of the content size.
 */
@property (nonatomic, strong) TKListViewLoadOnDemandView * __nonnull loadOnDemandView;

/**
 A view that will be automatically resized to track the size of the collection view and placed behind all cells and supplementary views.
 */
@property (nonatomic, retain) UIView * __nullable backgroundView;

/**
 Returns an array with the index paths of the selected items.
 */
@property (nonatomic, strong, readonly, nullable) NSArray * indexPathsForSelectedItems;

/**
 Returns the number of sections.
 */
@property (nonatomic, readonly) NSInteger numberOfSections;

/**
 Returns the number for currently visible cells.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray<__kindof TKListViewCell *> * visibleCells;

/**
 Returns the index paths for the currently visible cells.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray<NSIndexPath *> *indexPathsForVisibleItems;

/**
 Determines the delay in miliseconds after which the "load on demand" delegate will be called while cells for items are being added.
 */
@property (nonatomic) NSInteger loadOnDemandDelay;

/**
 Determines the delay in miliseconds after which the TKListViewGridLayout will be invalidated after a frame is set to the TKListView.
 */
@property (nonatomic) NSInteger invalidateGridLayoutDelay;

/**
 Reloads all data.
 */
- (void)reloadData;

/**
 Restores the swiped cell to its initial state.
 @param animated Determines whether to animate the cell.
 */
- (void)endSwipe:(BOOL)animated;

/**
 Deselects all selected items.
 */
- (void)clearSelectedItems;

/**
 Selects an item at the given index path.
 @param indexPath The index path of the item to select.
 @param animated Determines whether to animate the selection.
 @param scrollPosition The scroll position.
 */
- (void)selectItemAtIndexPath:(NSIndexPath * __nonnull)indexPath animated:(BOOL)animated scrollPosition:(UICollectionViewScrollPosition)scrollPosition;

/**
 Deselects an item at the given index path.
 @param indexPath The index path of the item to deselect.
 @param animated Determines whether to animate the selection.
 */
- (void)deselectItemAtIndexPath:(NSIndexPath * __nonnull)indexPath animated:(BOOL)animated;

/**
 Returns a TKListVIewCell to be provided in the listView:cellForItemAtIndexPath:ndexPath delegate method.
 
 @param identifier A string identifier of the cell type.
 @param indexPath The index path of the item we need a cell for.
 */
- (id __nullable)dequeueReusableCellWithReuseIdentifier:(NSString * __nonnull)identifier forIndexPath:(NSIndexPath* __nonnull)indexPath;

/**
 Returns a header or footer view to be provided in the listView:viewForSupplementaryElementOfKind:atIndexPath:
 
 @param elementKind The element kind - header or footer.
 @param identifier A string identifier of the view type.
 @param indexPath The index path of the supplementary view.
 */
- (id __nullable)dequeueReusableSupplementaryViewOfKind:(NSString* __nonnull)elementKind withReuseIdentifier:(NSString * __nonnull)identifier forIndexPath:(NSIndexPath* __nonnull)indexPath;

/**
 Returns a TKListViewCell that should be used as load on demand cell when loadOnDemandMode is set to manual.
 @param indexPath The index path.
 */
- (TKListViewCell* __nullable)dequeueLoadOnDemandCellForIndexPath:(NSIndexPath* __nonnull)indexPath;

/**
 Registers a class to be used to represent load on demand cell in listview.
 @param cellClass The cell class.
 */
- (void)registerLoadOnDemandCell:(Class __nonnull)cellClass;

/**
 Registers a class to be used to represent cells in listview.
 @param cellClass The class of the UIView to represent a cell.
 @param identifier A string identifier of the cell type.
 */
- (void)registerClass:(Class __nonnull)cellClass forCellWithReuseIdentifier:(NSString * __nonnull)identifier;

/**
 Registers a class to be used to represent headers and footers.
 @param viewClass The class of the UIView to represent a header or footer.
 @param elementKind The element kind - header or footer.
 @param identifier A string identifier of the supplementary view type.
 */
- (void)registerClass:(Class __nonnull)viewClass forSupplementaryViewOfKind:(NSString * __nonnull)elementKind withReuseIdentifier:(NSString * __nonnull)identifier;

/**
 Registers a nib file to be used to represent cells in listview.
 @param nib The nib instance to represent a cell.
 @param identifier A string identifier of the cell type.
 */
- (void)registerNib:(UINib* __nullable)nib forCellReuseIdentifier:(NSString * __nonnull)identifier;

/**
 Registers a class to be used to represent headers and footers.
 @param nib The nib instance to represent a header or footer.
 @param elementKind The element kind - header or footer.
 @param identifier A string identifier of the supplementary view type.
 */
- (void)registerNib:(UINib* __nullable)nib forSupplementaryViewOfKind:(NSString* __nonnull)elementKind withReuseIdentifier:(NSString * __nonnull)identifier;

/**
 Returns the visible cell object at the specified index path.
 @param indexPath The index path for the cell.
 */
- (TKListViewCell* __nullable)cellForItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;

/**
 Inserts new items at the specified index paths.
 @param indexPaths The index paths of the newly inserted items.
 */
- (void)insertItemsAtIndexPaths:(NSArray * __nonnull)indexPaths;

/**
 Moves an item from one location to another in the list view.
 @param indexPath The old index path.
 @param newIndexPath The new index path.
 */
- (void)moveItemAtIndexPath:(NSIndexPath * __nonnull)indexPath toIndexPath:(NSIndexPath * __nonnull)newIndexPath;

/**
 Deletes the items at the specified index paths.
 @param indexPaths The index paths of the deleted items.
 */
- (void)deleteItemsAtIndexPaths:(NSArray * __nonnull)indexPaths;

/**
 Reloads the items at the specified index paths.
 @param indexPaths The index paths of items to reload.
 */
- (void)reloadItemsAtIndexPaths:(NSArray * __nonnull)indexPaths;

/**
 Allows multiple insert/delete/reload/move calls to be animated.
 @param updates The updates to apply.
 @param completion Will be executed upon completion.
 */
- (void)performBatchUpdates:(void (^ __nullable)(void))updates completion:(void (^ __nullable)(BOOL finished))completion;

/**
 Returns the number of items conatined in specific section.
 @param section The index of the section.
 */
- (NSInteger)numberOfItemsInSection:(NSInteger)section;

/**
 Returns the index path for the item at the specified location.
 @param point The point where the item is located.
 */
- (NSIndexPath * __nullable)indexPathForItemAtPoint:(CGPoint)point;

/**
 Returns the index path for specific cell.
 @param cell The cell.
 */
- (NSIndexPath * __nonnull)indexPathForCell:(UICollectionViewCell * __nullable)cell;

/**
 Scrolls to specific item.
 @param indexPath The index path for the item.
 @param scrollPosition The scroll position.
 @param animated Determines whether to animate the scrolling.
 */
- (void)scrollToItemAtIndexPath:(NSIndexPath * __nonnull)indexPath atScrollPosition:(UICollectionViewScrollPosition)scrollPosition animated:(BOOL)animated;

/**
 Sets the scroll offset with the given amount in a horizontal and vertical direction by either using animation or not.
 @param contentOffset a CGPoint instance representing the horizontal and vertical amount of scroll offset to be applied.
 @param animated a bool value determining whether animation is to be used or not.
 */
- (void)setContentOffset:(CGPoint)contentOffset animated:(BOOL)animated;

/**
 Notifies the list view that a new data requested on demand is ready to be shown.
 */
- (void)didLoadDataOnDemand;

/*
 Notifies the list view that a fresh data is available after a pull-to-refresh gesture takes place.
 */
- (void)didRefreshOnPull;

@end
