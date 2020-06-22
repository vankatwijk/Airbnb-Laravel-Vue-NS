
#import "TKListView.h"

@interface TKListView ()

@property (nonatomic) BOOL scrolling;

@property (nonatomic) BOOL swipeLock;

@property (nonatomic) BOOL isPannig;

@property (nonatomic, weak) TKListViewCell *swipedCell;

@property (nonatomic, readonly) BOOL isSwiping;

@property (nonatomic, readonly) BOOL isReordering;

@property (nonatomic) BOOL isItemSizeCacheDisabled;

@property (nonatomic) BOOL skipDidSelect;

- (void)onCellLongPress:(TKListViewCell*)cell;

- (BOOL)handlePanBegan:(TKListViewCell *)cell translation:(CGPoint)translation byHandle:(BOOL)byHandle;

- (void)handlePanInProgress:(TKListViewCell *)cell translation:(CGPoint)translation;

- (void)handlePanEnded:(TKListViewCell *)cell;

/**
 Defines if the load on demand behavior has been automatically disabled to 'TKListViewSelectionBehaviorNone' by the return value of 'listView:shouldLoadMoreDataAtIndexPath:'.
 */
@property (nonatomic) BOOL loadOnDemandTerminated;

@end
