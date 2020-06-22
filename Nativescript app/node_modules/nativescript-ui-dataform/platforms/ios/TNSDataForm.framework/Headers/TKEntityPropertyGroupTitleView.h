//
//  TKEntityPropertyGroupTitleView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TKDataFormGroupTitleStyle;
@class TKGridLayout;
@class TKLabel;

/**
 @enum TKEntityPropertyGroupTitleIndicatorPosition
 @discussion An enum that represents the position of the title indicator
 */
typedef NS_ENUM(NSInteger, TKEntityPropertyGroupTitleIndicatorPosition) {
    /**
     The title indicator is positioned on the left.
     */
    TKEntityPropertyGroupTitleIndicatorPositionLeft,
    
    /**
     The title indicator is positioned on the right.
     */
    TKEntityPropertyGroupTitleIndicatorPositionRight
};

/**
 @discussion A class that represents group's title view.
 */
@interface TKEntityPropertyGroupTitleView : UIView

/**
 Title's label.
 */
@property (nonatomic, strong, readonly, nonnull) TKLabel *titleLabel;

/**
 Title's indicator.
 */
@property (nonatomic, strong, nullable) UIView *indicatorView;

/**
 A bool that determines if the title's indicator should be animated on exapnd/collapse.
 */
@property (nonatomic) BOOL allowIndicatorAnimation;

/**
 The title's styles.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataFormGroupTitleStyle *style;

/**
 The title's indicator position.
 */
@property (nonatomic) TKEntityPropertyGroupTitleIndicatorPosition indicatorPosition;

/**
 The spacing between the items in the view.
 */
@property (nonatomic) CGFloat itemSpacing;

@end
