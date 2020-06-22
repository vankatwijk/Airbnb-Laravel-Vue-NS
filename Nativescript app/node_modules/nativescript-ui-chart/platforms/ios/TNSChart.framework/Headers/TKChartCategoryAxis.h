//
//  TKCategoryAxis.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAxis.h"
#import "TNSCore/TKRange.h"

/**
 The category axis of TKChart.

 <img src="../docs/images/chart-axes-types003.png">
 
 @see [Working with Category Axis](chart-axes-category)
 
 @discussion TKChart uses Categorical axes to plot data that contains categorical values. The axis is valid only in the context of Cartesian series. It also introduces several important properties:
 
 - majorTickInterval - Defines an interval among major axis ticks
 
 - minorTickInterval - Defines an interval among minor axis ticks
 
 - baseline - Contains a value, which defines how the series data should be aligned to. (For example: The TKChartBarSeries might render its bars up and down side depending on wether its value is greater or less than the baseline value.)
 
 - offset - Determines a axis value where the axis is crossed with another axis

 */
@interface TKChartCategoryAxis : TKChartAxis

/**
 The major tick mark frequency.
 */
@property (nonatomic, strong) NSNumber * __nullable majorTickInterval;

/**
 The minor tick mark frequency.
 */
@property (nonatomic, strong) NSNumber * __nullable minorTickInterval;

/**
 The value to which the series data is aligned to.
 */
@property (nonatomic, assign) NSInteger baseline;

/**
 The value where the axis will be crossed by the other.
 */
@property (nonatomic, assign) NSInteger offset;

/**
 The axis categories.
 @return The array of associated categories.
 */
@property (nonatomic, strong, readonly) NSArray* __nonnull categories;

/**
 The plot mode of the axis.
 @param plotMode The plot mode.
 */
- (void)setPlotMode:(TKChartAxisPlotMode)plotMode;

/**
 Initializes the category axis from an array of categories.
 @param categories The array of categories.
 */
- (instancetype __nonnull)initWithCategories:(NSArray* __nonnull)categories;

/**
 Initializes the category axis from an array of categories and range.
 @param categories The array of categories.
 @param range The axis range.
 */
- (instancetype __nonnull)initWithCategories:(NSArray * __nonnull)categories andRange:(TKRange* __nonnull)range;

/**
 Adds a category to the axis.
 @param category The category that should be added.
 */
- (void)addCategory:(id __nonnull)category;

/**
 Adds an array of categories to the axis.
 @param categories The categories' array that should be added to the axis.
 */
- (void)addCategoriesFromArray:(NSArray* __nonnull)categories;

/**
 Removes a category from the axis.
 @param category The category that should be removed from the axis.
 */
- (void)removeCategory:(id __nonnull)category;

/**
 Removes an array of categories from the axis.
 @param categories The array of category that should be removed from the axis.
 */
- (void)removeCategoriesInArray:(NSArray* __nonnull)categories;

/**
 Removes all categories.
 */
- (void)removeAllCategories;

@end
