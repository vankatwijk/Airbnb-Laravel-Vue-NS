//
//  TKChartSeriesRenderState.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKMutableArray;

/**
 Represents the visual state for chart series.
 */
@interface TKChartSeriesRenderState : NSObject

/**
 Returns the points that will be rendered.
 */
@property (nonatomic, strong, readwrite) TKMutableArray * __nonnull points;

/**
 Returns the points that have been rendered.
 */
@property (nonatomic, strong, readonly) TKMutableArray * __nullable oldPoints;

/**
 Returns the index according to series order
 */
@property (nonatomic, readonly) NSUInteger index;

/**
 Initializes the TKChartSeriesRenderState for series.
 @param index The index according to the series order.
 */
- (instancetype __nonnull)initWithIndex:(NSUInteger)index;

/**
 Creates an animation key path for a particular point at a specified index.
 @param pointIndex The point's index in the series.
 */
- (NSString * __nullable)animationKeyPathForPointAtIndex:(NSUInteger)pointIndex;

@end
