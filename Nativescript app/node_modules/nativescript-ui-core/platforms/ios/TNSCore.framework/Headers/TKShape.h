//
//  TKChartShape.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 * @discussion Represents a drawable shape.
 */
@interface TKShape : NSObject
{
@protected
    CGMutablePathRef _path;
}

/**
 Creates a shape with specified size.
 @param size Specifies the size in pixels.
 */
- (instancetype __nonnull)initWithSize:(CGSize)size;

/**
 The size of the shape.
 */
@property (nonatomic, assign) CGSize size;

/**
 Returns the shape insets neeeded
 */
@property (nonatomic, readonly) UIEdgeInsets insets;

/**
 Draws the shape in a context.
 @param context The context to draw in.
 @param center The center of the shape.
 @param drawings The array of TKDrawing shape and fills.
*/
- (void)drawInContext:(CGContextRef __nonnull)context withCenter:(CGPoint)center drawings:(NSArray * __nonnull)drawings;

/**
 Draws the shape in a context.
 @param context The context to draw in.
 @param center The center of the shape.
 @param drawings The array of TKDrawing shape and fills.
 @param scale The shape scale (1.0f = draw with shape's size).
 */
- (void)drawInContext:(CGContextRef __nonnull)context withCenter:(CGPoint)center drawings:(NSArray * __nonnull)drawings scale:(CGFloat)scale;

@end
