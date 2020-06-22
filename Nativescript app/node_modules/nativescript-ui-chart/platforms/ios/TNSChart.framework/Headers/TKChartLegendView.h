//
//  TkChartLegendView.h
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartLegendContainer.h"
#import "TKChartLegendStyle.h"
#import "TNSCore/TKView.h"

@class TKChart;

/**
 @discussion The legend in TKChart.
 */
@interface TKChartLegendView : TKView

/**
 The text title of the legend.
 @return A UILanbel representing the title of the legend.
 */
@property (nonatomic, strong, readonly) UILabel * __nonnull titleLabel;

/**
 The container that contains legend items.
 @return A TKChartLegendContainer containing legend items.
 */
@property (nonatomic, strong, readonly) TKChartLegendContainer * __nonnull container;

/**
 The legend's chart.
 */
@property (nonatomic, weak) TKChart * __nullable chart;

/**
 Determines visibility of legend title. By default, it is NO.
 */
@property (nonatomic, assign) BOOL showTitle;

/**
 Determines whether tapping on legend items will change selection. By default, it is YES.
 */
@property (nonatomic, assign) BOOL allowSelection;

/**
 The legend's style.
 */
@property (nonatomic, strong, readonly) TKChartLegendStyle * __nonnull style;

/**
 Initializes the legend with a TKChart instance.
 @param chart The associated TKChart instance.
 */
- (instancetype __nonnull)initWithChart:(TKChart* __nonnull)chart;

/**
 Reloads the legends view.
 */
- (void)reloadItems;

/**
 Updates legend item states when selection has changed.
 */
- (void)update;

@end
