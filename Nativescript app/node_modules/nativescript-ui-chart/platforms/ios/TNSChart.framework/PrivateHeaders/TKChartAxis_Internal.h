//
//  TKAxis_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAxis.h"
#import "TKChartData.h"


#define DEFAULT_INTERVAL 5
#define NOTATION 10

extern NSString* const kAutoMajorTickInterval;
extern NSString* const kAutoPlotMode;

@class TKRange;
@class TKChart;
@class TKChartDataView;

@interface TKChartAxis () {
@public
    TKRange *_range;
    TKChartAxisPlotMode _plotMode;
}

+ (BOOL)tickIsEqual:(id)tickValue toTick:(id)secondTickValue;

+ (id)axisOffset:(TKChartAxis*)axis;

+ (id)axisBaseline:(TKChartAxis*)axis;

@property (nonatomic, strong) TKStyleSheet *styleSheet;

@property (nonatomic) BOOL isSized;

@property (nonatomic) CGFloat prevZoom;

@property (nonatomic) BOOL isAuto;

@property (nonatomic) BOOL isChartAxis;

@property (nonatomic) BOOL rangeIsAuto;

- (TKRange *)visibleRangeInternal;

///**
// Returns the tick text for the tick at a specified index.
// @param index The index.
// @return A string representing the text at the specified index.
// */
//- (NSString *)tickText:(NSInteger)index;

///**
// Returns the tick's index for a specific value.
// @param value The tick value.
// @return The tick's index.
// */
//- (NSInteger)tickIndexWithValue:(id)value;


//internal utils

- (NSInteger)startIndex;

- (BOOL)isSorted;

- (BOOL)isAuto:(NSString*)propertyName;

- (void)setAuto:(NSString*)propertyName;

- (void)resetAuto:(NSString*)propertyName;

- (BOOL)hasOffsetForPosition:(TKChartAxisPosition)position;

- (void)updateRangeWithSeries:(TKChartSeries*)series forKey:(NSString*)key;

- (void)updateStackedRangeWithSeries:(NSArray *)seriesArray forKey:(NSString *)key;

- (BOOL)canZoom;

- (BOOL)canPan;

- (NSUInteger)minorTickCount;

- (NSInteger)tickIndexWithValue:(id)value;

- (void)setPlotMode:(TKChartAxisPlotMode)plotMode;

/**
 Updates the axis range values selecting the minimum and maximum values
 between the current range and the new values.
 @param minimum The minimum value that specifies the start of the range.
 @param maximum The maximum value that specifies the end of the range.
 */
- (void)updateRangeWithMinimum:(id)minimum andMaximum:(id)maximum;

- (BOOL)isCompatibleWith:(TKChartSeries*)series;

- (void)panAxisWithDeltaX:(CGFloat)deltaX deltaY:(CGFloat)deltaY viewportSize:(CGSize)viewport verticalDirection:(BOOL)vDirection;

- (double)numericRange;

- (void)sortDataView:(TKChartDataView*)dataView;

/**
 Resets the axis data - range, categories, etc
 */
- (void)resetAxisForAutoData;

@end
