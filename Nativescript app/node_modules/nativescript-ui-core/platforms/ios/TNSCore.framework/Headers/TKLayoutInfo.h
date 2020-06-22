//
//  TKLayoutInfo.h
//  TelerikUI
//
//  Copyright © 2016 Telerik. All rights reserved.
//

/**
 @discussion Represents layout information about a view.
 */
@interface TKLayoutInfo : NSObject


/**
 The index of the view.
 */
@property (nonatomic) NSUInteger index;

/**
 The row where the view should be rendered.
 */
@property (nonatomic) NSUInteger row;

/**
 The column where the view should be rendered.
 */
@property (nonatomic) NSUInteger column;

/**
 The row span in grid layout.
 */
@property (nonatomic) NSUInteger rowSpan;

/**
 The column span in grid layout.
 */
@property (nonatomic) NSUInteger columnSpan;

/**
 Creates new TKLayoutInfo instance.
 @param row The layout info row.
 @param column The layout info column.
 @param rowSpan The layout info row span.
 @param columnSpan The layout info column span.
 */
- (id)initWithRow:(NSUInteger)row column:(NSUInteger)column rowSpan:(NSUInteger)rowSpan columnSpan:(NSUInteger)columnSpan;

@end
