//
//  TKSideDrawerStyle.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

#ifndef __IPHONE_8_0
/**
 @enum UIBlurEffectStyle
 @discussion This enumeration has effect on the blur style only on iOS 8 and later.
 */
typedef NS_ENUM(NSInteger, UIBlurEffectStyle)
{
    /**
     Light blur style.
     */
    UIBlurEffectStyleLight,
    
    /**
     Dark blur style.
     */
    UIBlurEffectStyleDark,
    
    /**
     Extra light blur style.
     */
    UIBlurEffectStyleExtraLight
};
#endif

/**
 @enum TKSideDrawerBlurType
 @discussion An enum that defines TKSideDrawer's blur type.
 */
typedef NS_ENUM(NSInteger, TKSideDrawerBlurType)
{
    /**
     No blur.
     */
    TKSideDrawerBlurTypeNone,
    
    /**
     Dynamic blur. Available in iOS 8 and later. Applies blur effect dynamically on top of the host view.
     */
    TKSideDrawerBlurTypeDynamic,
    
    /**
     Static blur. Takes a screenshot of the host view.
     */
    TKSideDrawerBlurTypeStatic
};

/**
 @enum TKSideDrawerBlurType
 @discussion Represents an enum that defines TKSideDrawer's shadow mode.
 */
typedef NS_ENUM(NSInteger, TKSideDrawerShadowMode)
{
    /**
     No shadow.
     */
    TKSideDrawerShadowModeNone,
    
    /**
     Applies a shadow to TKSideDrawer's hostview.
     */
    TKSideDrawerShadowModeHostview,
    
    /**
     Applies a shadow to TKSideDrawer.
     */
    TKSideDrawerShadowModeSideDrawer
};

/**
 @discussion Represents a set of visual style properties for TKSideDrawer.
 */
@interface TKSideDrawerStyle : TKStyleNode

/**
 Header view's height.
 */
@property (nonatomic) CGFloat headerHeight;

/**
 Footer view's height.
 */
@property (nonatomic) CGFloat footerHeight;

/**
 Section header's height.
 */
@property (nonatomic) CGFloat sectionHeaderHeight;

/**
 Items' height.
 */
@property (nonatomic) CGFloat itemHeight;

/**
 Blur style for TKSideDrawer. Works only with TKSideDrawerBlurTypeDynamic.
 */
@property (nonatomic) UIBlurEffectStyle blurEffect;

/**
 Determines blur type that should be used.
 */
@property (nonatomic) TKSideDrawerBlurType blurType;

/*
 Blur tint color. This property is used only with static blur.
 */
@property (nonatomic, strong) UIColor *blurTintColor;

/*
 Shadow color.
 */
@property (nonatomic, strong) UIColor *shadowColor;

/**
 The opacity of the dim over the hostview. If 0, no dim will be added.
 */
@property (nonatomic) CGFloat dimOpacity;

/**
 Determines if shadow casts over TKSideDrawer or its hostview.
 */
@property (nonatomic) TKSideDrawerShadowMode shadowMode;

/**
 Shadow's offset.
 */
@property (nonatomic) CGSize shadowOffset;

/**
 Shadow's opacity.
 */
@property (nonatomic) CGFloat shadowOpacity;

/**
 Shadow's radius.
 */
@property (nonatomic) CGFloat shadowRadius;

@end
