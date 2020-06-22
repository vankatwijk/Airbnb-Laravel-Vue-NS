//
//  TKEntityPropertyGroupView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TNSCore/TKLayout.h"

@class TKEntityPropertyGroup;
@class TKEntityPropertyGroupEditorsView;
@class TKEntityPropertyGroupTitleView;

/**
 @discussion Represents a view that displays TKEntityGroup.
 */
@interface TKEntityPropertyGroupView : UIView

/**
 Title view for the group.
 */
@property (nonatomic, strong) TKEntityPropertyGroupTitleView *titleView;

/**
 View that contains editors for the properties in the group.
 */
@property (nonatomic, strong, readonly) TKEntityPropertyGroupEditorsView *editorsContainer;

/**
 A bool that determines if the group is collapsable.
 */
@property (nonatomic) BOOL collapsible;

/**
 Shows if the group is collapsed or not.
 */
@property (nonatomic, readonly) BOOL isCollapsed;

/**
 The TKEntityPropertyGroup that this view represents.
 */
@property (nonatomic, strong, readonly) TKEntityPropertyGroup *group;

/**
 Expands this group.
 */
- (void)expand;

/**
 Collapses this group.
 */
- (void)collapse;

@end
