//
//  TKSideDrawerHeader.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKView.h"
#import "TKSideDrawerItemStyle.h"

@class TKCoreStackLayout;

/**
 @enum TKSideDrawerHeaderButtonPosition
 @discussion Represents an enum that defines the position of TKSideDrawerHeader action button.
 */
typedef NS_ENUM(NSInteger, TKSideDrawerHeaderButtonPosition)
{
    /**
     The button is positioned on the left.
     */
    TKSideDrawerHeaderButtonPositionLeft,
    
    /**
     The button is positioned on the right.
     */
    TKSideDrawerHeaderButtonPositionRight,
    
    /**
     The button is positioned at the top.
     */
    TKSideDrawerHeaderButtonPositionTop,
    
    /**
     The button is positioned at the bottom.
     */
    TKSideDrawerHeaderButtonPositionBottom
};

/**
 Defines a header view for TKSideDrawer or TKSideDrawerSection.
 */
@interface TKSideDrawerHeader : TKView

/**
 The text label.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *titleLabel;

/**
 The action button.
 */
@property (nonatomic, strong, nonnull) UIButton *actionButton;

/**
 The image view.
 */
@property (nonatomic, strong, readonly, nonnull) UIImageView *imageView;

/**
 The separator view.
 */
@property (nonatomic, strong, readonly, nonnull) UIView *separator;

/**
 Determines the button position.
 */
@property (nonatomic) TKSideDrawerHeaderButtonPosition buttonPosition;

/**
 Determines the image view position.
 */
@property (nonatomic) TKSideDrawerItemImagePosition imagePosition;

/**
 The stack layout.
 */
@property (nonatomic, strong, readonly, nonnull) TKCoreStackLayout *stack;

/**
 The margins of the content.
 */
@property (nonatomic) UIEdgeInsets contentInsets;

/**
 The color used for the separator view.
 */
@property (nonatomic, strong, nullable) TKFill *separatorColor;

/**
 Initializes a new TKSideDrawer instance.
 @param title The NSString that is used as a title for TKSideDrawerHeader.
 @return The new TKSideDrawerHeader instance.
 */
- (instancetype __nonnull)initWithTitle:(NSString * __nonnull)title;

/**
 Initializes a new TKSideDrawerHeader instance.
 @param title The NSString that is used as a title for TKSideDrawerHeader.
 @param button The TKSideDrawerHeader's button.
 @return The new TKSideDrawerHeader instance.
 */
- (instancetype __nonnull)initWithTitle:(NSString * __nonnull)title button:(UIButton * __nullable)button;

/**
 Initializes a new TKSideDrawerHeader instance.
 @param title The NSString that is used as a title for TKSideDrawerHeader.
 @param image The TKSideDrawerHeader's image.
 @return The new TKSideDrawerHeader instance.
 */
- (instancetype __nonnull)initWithTitle:(NSString * __nonnull)title image:(UIImage * __nullable)image;

/**
 Initializes a new TKSideDrawerHeader instance.
 @param title The NSString that is used as a title for TKSideDrawerHeader.
 @param button The TKSideDrawerHeader's button.
 @param image The TKSideDrawerHeader's image.
 @return The new TKSideDrawerHeader instance.
 */
- (instancetype __nonnull)initWithTitle:(NSString * __nonnull)title button:(UIButton * __nullable)button image:(UIImage * __nullable)image;

@end
