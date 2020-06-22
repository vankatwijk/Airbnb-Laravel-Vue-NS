//
//  TKListViewGridLayout.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKListViewLinearLayout.h"

/**
 A layout that renders cells in TKListView by distributing them in a fixed columns count. Supports cell alignment e.g. left, right , center, justify 
 */
@interface TKListViewGridLayout : TKListViewLinearLayout

/**
 The number of columns/rows to be rendered.
 */
@property (nonatomic,assign) NSInteger spanCount;

/**
 The spacing between item rows.
 */
@property (nonatomic) CGFloat lineSpacing;

@end
