//
//  TKImageFill.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKFill.h"

/**
 Defines how the image within TKImageFill can be resized.
 */
typedef NS_ENUM(NSInteger, TKImageFillResizingMode) {
    /**
     The image is tiled (default).
     */
    TKImageFillResizingModeTile,
    
    /**
     The image is stretched.
     */
    TKImageFillResizingModeStretch,

    /**
     The image is shown as is.
     */
    TKImageFillResizingModeNone,
};

/**
 @discussion Represents an image brush.
 */
@interface TKImageFill : TKFill

/**
 Initializes with an image.
 @param image The image to draw.
 */
+ (instancetype __nonnull)imageFillWithImage:(UIImage * __nonnull)image;

/**
 Initializes with an image.
 @param image The image to draw.
 @param cornerRadius The corner radius in points.
 */
+ (instancetype __nonnull)imageFillWithImage:(UIImage * __nonnull)image cornerRadius:(CGFloat)cornerRadius;


/**
 Initializes with an image.
 @param image The image to draw.
 */
- (instancetype __nonnull)initWithImage:(UIImage * __nonnull)image;


/**
 Initializes with an image.
 @param image The image to draw.
 @param cornerRadius The corner radius in points.
 */
- (instancetype __nonnull)initWithImage:(UIImage * __nonnull)image cornerRadius:(CGFloat)cornerRadius;

/**
 An image to draw.
 */
@property (nonatomic, strong, nullable) UIImage* image;

/**
 Defines the resizing mode of the image.
 
 @discussion The resizing modes are defined as follows:
 
    typedef enum {
        TKImageFillResizingModeTile,        // The image is tiled (default).
        TKImageFillResizingModeStretch,     // The image is stretched.
        TKImageFillResizingModeNone,        // The image is shown as is.
    } TKImageFillResizingMode;

 */
@property (nonatomic, assign) TKImageFillResizingMode resizingMode;

@end
