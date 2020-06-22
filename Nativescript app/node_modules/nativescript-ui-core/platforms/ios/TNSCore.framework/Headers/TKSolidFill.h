//
//  TKSolidFill.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKFill.h"

/**
 @discussion A solid color fill.
 */

@interface TKSolidFill : TKFill

/**
 * Initializes with a fill color.
 * @param color The fill color.
 */
+ (instancetype __nonnull)solidFillWithColor:(UIColor* __nonnull)color;

/**
 Initializes with a fill color.
 @param color The fill color.
 @param cornerRadius The corner radius in points.
 */
+ (instancetype __nonnull)solidFillWithColor:(UIColor*  __nonnull)color cornerRadius:(CGFloat)cornerRadius;

/**
 Initializes with a fill color.
 @param color The fill color.
 */
- (instancetype __nonnull)initWithColor:(UIColor*  __nonnull)color;

/**
 Initializes with a fill color.
 @param color The fill color.
 @param cornerRadius The corner radius in points.
 */
- (instancetype __nonnull)initWithColor:(UIColor *  __nonnull)color cornerRadius:(CGFloat)cornerRadius;

/**
 The Fill color to use while drawing.
 */
@property (nonatomic, strong, nonnull) UIColor* color;

@end
