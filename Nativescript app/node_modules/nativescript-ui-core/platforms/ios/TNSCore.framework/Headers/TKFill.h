//
//  TKFill.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKDrawing.h"

/**
 @discussion The base class for all fills. Should not be instantiated directly.
*/
@interface TKFill : NSObject<TKDrawing, NSCopying>

/**
 A value that specifies the opacity level. Values can range from 0.0 (transparent) to 1.0 (opaque). Values outside this range are clipped to 0.0 or 1.0.
 */
@property (nonatomic, assign) CGFloat alpha;

/**
 A bitmask value that identifies the corners that you want rounded. You can use this parameter to round only a
 subset of the corners of the rectangle. The default is all corners. Ignored if cornerRadius is zero.
 */
@property (nonatomic, assign) UIRectCorner corners;

/**
 The radius to use when drawing rounded corners. The default is 0.
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 Edge insets to apply.
 */
@property (nonatomic, assign) UIEdgeInsets insets;

/**
 The shadow offset
 */
@property (nonatomic) CGSize shadowOffset;

/**
 The shadow blur.
 */
@property (nonatomic) CGFloat shadowBlur;

/**
 The shadow color.
 */
@property (nonatomic, strong, nullable) UIColor *shadowColor;

/**
 * Draws a fill as rectangle in a given context.
 * @param context The context used to draw with.
 * @param rect The rectangle drawn on the screen.
 */
- (void)drawFillInContext:(CGContextRef __nonnull)context withRect:(CGRect)rect;

/**
 * Draws a fill as a path in a given context
 * @param context The context used to draw with.
 * @param path The path drawn on the screen.
 */
- (void)drawFillInContext:(CGContextRef __nonnull)context withPath:(CGPathRef __nullable)path;

@end
