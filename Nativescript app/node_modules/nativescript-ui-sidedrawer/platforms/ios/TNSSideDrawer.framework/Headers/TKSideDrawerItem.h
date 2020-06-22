//
//  TKSideDrawerItem.h
//
//  Copyright (c) 2013 Telerik Inc. All rights reserved.
//

@class TKSideDrawerItemStyle;
@class TKStyleSheet;

/**
 @enum TKSideDrawerTableViewCellContentAlignment
 @discussion Represents an enum that defines the position of the sidedrawer item's content.
 */
typedef NS_ENUM(NSInteger, TKSideDrawerTableViewCellContentAlignment)
{
    /**
     Aligns item's content to the left.
     */
    TKSideDrawerTableViewCellContentAlignmentLeft,
    /**
     Aligns item's content to the right.
     */
    TKSideDrawerTableViewCellContentAlignmentRight,
    /**
     Aligns item's content in the center.
     */
    TKSideDrawerTableViewCellContentAlignmentCenter
};

/**
 Defines TKSideDrawer item.
 */
@interface TKSideDrawerItem : NSObject

/**
 TKSideDrawerItem's title.
 */
@property (nonatomic, strong, nullable) NSString *title;

/**
 TKSideDrawerItem's styles.
 */
@property (nonatomic, strong, readonly, nonnull) TKSideDrawerItemStyle *style;

/**
 TKSideDrawerItem's image.
 */
@property (nonatomic, strong, nullable) UIImage *image;

/**
 The alignment of the TKsideDrawerItem's content.
 */
@property(nonatomic, assign) TKSideDrawerTableViewCellContentAlignment contentAlignment;

/**
 Creates new TKSideDrawerItem instance.
 @param title Title for the TKSideDrawerItem that will be created.
 @return New TKSideDrawerItem instance.
 */
- (instancetype __nonnull)initWithTitle:(NSString * __nullable)title;

/**
 Creates new TKSideDrawerItem instance.
 @param title Title for the TKSideDrawerItem that will be created.
 @param image UIImage fot the TKSideDrawerItem that will be created.
 @return New TKSideDrawerItem instance.
 */
- (instancetype __nonnull)initWithTitle:(NSString * __nullable)title image:(UIImage * __nullable)image;

@end
