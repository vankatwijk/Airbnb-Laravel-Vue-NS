//
//  TKDataFormGroupTitleStyle.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

@class TKStroke;
@class TKFill;

/**
 @discussion Represents style fot group's title.
 */
@interface TKDataFormGroupTitleStyle : TKStyleNode

/**
 Stroke for the group's title.
 */
@property (nonatomic, strong) TKStroke *stroke;

/**
 Fill for the group's title.
 */
@property (nonatomic, strong) TKFill *fill;

/**
 Group's title separator color.
 */
@property (nonatomic, strong) TKFill *separatorColor;

/**
 Group's title separator leading space.
 */
@property (nonatomic) CGFloat separatorLeadingSpace;

/**
 Group's title separator trailing space.
 */
@property (nonatomic) CGFloat separatorTrailingSpace;

/**
 Insets for the group's title.
 */
@property (nonatomic) UIEdgeInsets insets;

@end
