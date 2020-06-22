//
//  TKSideDrawerItemStyle.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

@class TKFill;
@class TKStroke;

/**
 @enum TKSideDrawerItemImagePosition
 @discussion An enum that defines the position of the TKSideDrawerItem image.
 */
typedef NS_ENUM(NSInteger, TKSideDrawerItemImagePosition)
{
    /**
     Left position.
     */
    TKSideDrawerItemImagePositionLeft,
    
    /**
     Right position.
     */
    TKSideDrawerItemImagePositionRight,
    
    /**
     Top position.
     */
    TKSideDrawerItemImagePositionTop,
    
    /**
     Bottom position.
     */
    TKSideDrawerItemImagePositionBottom
};

/**
 @discussion Represents TKSideDrawerItem's styles.
 */
@interface TKSideDrawerItemStyle : TKStyleNode

/**
 Title's font.
 */
@property (nonatomic, strong) UIFont *font;

/**
 Title's color.
 */
@property (nonatomic, strong) UIColor *textColor;

/**
 Title's alignment.
 */
@property (nonatomic) NSTextAlignment textAlignment;

/**
 Fill.
 */
@property (nonatomic, strong) TKFill *fill;

/**
 Stroke.
 */
@property (nonatomic, strong) TKStroke *stroke;

/**
 Separator's color.
 */
@property (nonatomic, strong) TKFill *separatorColor;

/**
 Position of the image.
 */
@property (nonatomic) TKSideDrawerItemImagePosition imagePosition;

/**
 Content margins.
 */
@property (nonatomic) UIEdgeInsets contentInsets;

@end
