//
//  TKGridLayoutCellDefinition.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 @enum TKGridLayoutAlignment
 @disussion Grid layout cell alignment.
 */
typedef NS_OPTIONS(NSInteger, TKGridLayoutAlignment) {
    /**
     Top alignment.
     */
    TKGridLayoutAlignmentTop                = 1 << 0,
    
    /**
     Left alignment.
     */
    TKGridLayoutAlignmentLeft               = 1 << 1,
    
    /**
     Bottom alignment.
     */
    TKGridLayoutAlignmentBottom             = 1 << 2,
    
    /**
     Right alignment.
     */
    TKGridLayoutAlignmentRight              = 1 << 3,
    
    /**
     Center alignment.
     */
    TKGridLayoutAlignmentCenter             = 1 << 4,
    
    /**
     Center vertical alignment.
     */
    TKGridLayoutAlignmentCenterVertical     = 1 << 5,
    
    /**
     Center horizontal alignment.
     */
    TKGridLayoutAlignmentCenterHorizontal   = 1 << 6,
    
    /**
     Stretch the view to fill its cell.
     */
    TKGridLayoutAlignmentFill               = 1 << 7,
    
    /**
     Stretch the view vertically..
     */
    TKGridLayoutAlignmentFillVertical       = 1 << 8,
    
    /**
     Stectch the view horizontally.
     */
    TKGridLayoutAlignmentFillHorizontal     = 1 << 9
};

/**
 @disussion A class that represents definition for a grid layout cell.
 */
@interface TKGridLayoutCellDefinition : NSObject

/**
 The view that will be layed out according to the cell definition.
 */
@property (nonatomic, weak) UIView *view;

/**
 Row span.
 */
@property (nonatomic) NSUInteger rowSpan;

/**
 Column span.
 */
@property (nonatomic) NSUInteger columnSpan;

/**
 The row at which the view should be layed out.
 */
@property (nonatomic) NSNumber *row;

/**
 The column at which the view should be layed out.
 */
@property (nonatomic) NSNumber *column;

/**
 The index used to find next editor to focus.
 */
@property (nonatomic) NSNumber *index;

/**
 Alignment.
 */
@property (nonatomic) TKGridLayoutAlignment alignment;

/**
 Content offset.
 */
@property (nonatomic) UIOffset contentOffset;

/**
 Creates new TKGridLayoutCellDefinition object.
 @param view The view for the cell definition.
 @return New TKGridLayoutCellDefinition object.
 */
- (id)initWithView:(UIView *)view;

/**
 Creates new TKGridLayoutCellDefinition object.
 @param view The view for the cell definition.
 @param row The row of the definition.
 @param col The column of the definition.
 @return New TKGridLayoutCellDefinition object.
 */
- (id)initWithView:(UIView *)view atRow:(NSNumber *)row column:(NSNumber *)col;

/**
 Creates new TKGridLayoutCellDefinition object.
 @param view The view for the cell definition.
 @param row The row of the definition.
 @param col The column of the definition.
 @param rowSpan Row span for the definition.
 @param colSpan Column span for the definition.
 @return New TKGridLayoutCellDefinition object.
 */
- (id)initWithView:(UIView *)view atRow:(NSNumber *)row column:(NSNumber *)col rowSpan:(NSInteger)rowSpan columnSpan:(NSInteger)colSpan;

@end
