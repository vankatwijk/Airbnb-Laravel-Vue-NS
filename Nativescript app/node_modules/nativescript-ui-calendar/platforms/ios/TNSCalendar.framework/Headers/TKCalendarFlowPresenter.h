//
//  TKCalendarFlowPresenter.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendar.h"

/**
 @discussion A calendar presenter used to render TKCalendar in flow view mode.
 */
@interface TKCalendarFlowPresenter : UIView <TKCalendarPresenter>

/**
 Returns the collection view used by this presenter.
 */
@property (nonatomic, strong, readonly) UICollectionView* __nonnull collectionView;

@end
