//
//  TKDrawing.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 * @discussion Represents a protocol that draws content on screen.
 */
@protocol TKDrawing <NSObject>

@required

/**
 Draw within a rectangle in a context.
 
 @param context The context to draw in.
 @param rect The rectangle to draw within
 */
- (void)drawInContext:(CGContextRef)context withRect:(CGRect)rect;

/**
 Draw a within rectangle in a context and clip with a path.
 
 @param context The context to draw in.
 @param path The path to draw within.
 */
- (void)drawInContext:(CGContextRef)context withPath:(CGPathRef)path;

@optional

/**
 Edge insets to apply.
 */
@property (nonatomic, assign) UIEdgeInsets insets;

@end
