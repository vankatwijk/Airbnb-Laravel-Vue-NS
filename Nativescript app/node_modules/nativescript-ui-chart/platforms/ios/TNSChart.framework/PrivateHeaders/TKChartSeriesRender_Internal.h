//
//  TKChartSeriesRender.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeriesRender.h"
#import "TNSCore/TKMutableArray.h"

@class TKChartSeries;
@class TKChartPointLabelRender;

typedef NS_ENUM(NSInteger, TKChartAnimationType) {
    TKChartAnimationTypeEntry,
    TKChartAnimationTypeDataChanged,
    TKChartAnimationTypeSelectionChanged
};

typedef NS_ENUM(NSInteger, TKChartSeriesHitTestContext) {
    TKChartSeriesHitTestContextSelection,
    TKChartSeriesHitTestContextSingleSeriesTracking,
    TKChartSeriesHitTestContextAllSeriesTracking
};

@interface TKChartSeriesRender ()
{
@public
    NSMutableArray *_series;
    TKMutableArray *_seriesRenderStates;
    BOOL _statesDisabled;
    BOOL _updated;
    BOOL _suspendDrawing;

    // points specific to the render
    //NSMutableDictionary *_renderPoints;
    BOOL _animationsSuspended;
}
/**
  Render for series point labels.
 */
@property (nonatomic, strong) TKChartPointLabelRender *pointLabelLayout;

/**
 Returns a sorted array of render keys
 */
//- (NSArray *)sortedRenderKeys;

/**
 This method is being called by TKChart when the selection has changed.
 @param series The series that is currently selected.
 @param pointIndex The point index of the currently selected point.
 */
- (void)selectionDidChangedForSeries:(TKChartSeries*)series andPoint:(NSInteger)pointIndex;

/**
 Returns a value indicating whether to create visual point elements or not.
 */
- (BOOL)shouldCreateVisualPoints;

/**
 Adds animation for type
 */
- (void)addAnimationWithType:(TKChartAnimationType)type;

- (void)drawPointLabelsInContext:(CGContextRef)ctx;

- (TKChartPointLabelRender *)createPointLabelRender;

/**
 Determines whether the states are disabled
 */
@property (nonatomic) BOOL statesDisabled;

/**
Determines if the render contains specific series object.
 @param series The series object.
 @return Boolean that shows if the render contains the series object.
 */
- (BOOL)containsSeries:(TKChartSeries *)series;

@end
