//
//  TKLayer.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

@class TKFill;
@class TKStroke;
@class TKShape;

/**
 Represents a layer that supports drawings and shapes
 */
@interface TKLayer : CALayer

/**
 Gets or sets the layer's shape
 */
@property (nonatomic, strong) TKShape *shape;

/**
 The layer's fill
 */
@property (nonatomic, strong) TKFill *fill;

/**
 The layer's stroke
 */
@property (nonatomic, strong) TKStroke *stroke;

/**
 Return 'best' size to fit given size. does not actually resize view. Default is return existing view size
 @param size The size
 */
- (CGSize)sizeThatFits:(CGSize)size;

/**
 Calls sizeThatFits: with current view bounds and changes bounds size.
 */
- (void)sizeToFit;

@end
