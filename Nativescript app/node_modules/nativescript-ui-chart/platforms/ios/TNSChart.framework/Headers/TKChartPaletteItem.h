//
//  TKChartPaletteItem.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKFill;
@class TKStroke;

/**
 @discussion Represents a single palette item used in TKChart.
 */
@interface TKChartPaletteItem : NSObject

/**
 Creates a palette item with a specified fill.
 @param fill The TKFill to set.
 */
+ (instancetype __nonnull)paletteItemWithFill:(TKFill *  __nonnull)fill;

/**
 Creates a palette item with a specified stroke.
 @param stroke The TKStroke to set.
 */
+ (instancetype __nonnull)paletteItemWithStroke:(TKStroke * __nonnull)stroke;

/**
 Creates a palette item with a specified stroke & fill.
 @param stroke The TKStroke to set.
 @param fill The TKFill to set.
 */
+ (instancetype __nonnull)paletteItemWithStroke:(TKStroke * __nonnull)stroke andFill:(TKFill * __nonnull)fill;

/**
 Creates a palette item with drawables. Drawing is performed in the order of the array elements.
 @param drawables The Array of the TKDrawing implementations.
 */
+ (instancetype __nonnull)paletteItemWithDrawables:(NSArray * __nonnull)drawables;

/**
 Initializes with a specified fill.
 @param fill The TKFill to set.
 */
- (instancetype __nonnull)initWithFill:(TKFill *  __nonnull)fill;

/**
 Initializes with a specified stroke.
 @param stroke The TKStroke to set.
 */
- (instancetype __nonnull)initWithStroke:(TKStroke *  __nonnull)stroke;

/**
 Initializes with a specified stroke & fill.
 @param stroke The TKStroke to set.
 @param fill The TKFill to set.
 */
- (instancetype __nonnull)initWithStroke:(TKStroke *  __nonnull)stroke andFill:(TKFill *  __nonnull)fill;

/**
 Initializes with drawables. Drawing is performed in the order of the array elements.
 @param drawables The Array of the TKDrawing implementations.
 */
- (instancetype __nonnull)initWithDrawables:(NSArray * __nonnull)drawables;

/**
 The palette's text color.
 */
@property (nonatomic, strong) UIColor *  __nullable textColor;

/**
 The palette's font.
 */
@property (nonatomic, strong) UIFont *  __nullable font;

/**
 The fill color of the palette item.
 @return An instance of UIColor representing the fill color.
 */
@property (nonatomic, strong) TKFill *  __nullable fill;

/**
 The stroke color of the palette item.
 @return An instance of UIColor representing the stroke color.
 */
@property (nonatomic, strong) TKStroke *  __nullable stroke;

/**
 An array of the TKDrawing implementations.
 All is drawn in the order of the elements in the array.
*/
@property (nonatomic, strong) NSArray * __nonnull drawables;

@end
