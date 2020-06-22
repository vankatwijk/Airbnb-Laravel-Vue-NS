//
//  TKRange.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 @discussion A class that represents a range of minimum and maximum values.
 */
@interface TKRange : NSObject

/**
 Initializes the range with its minimum and maximum.
 @param minimum The minimum value of the range.
 @param maximum The maximum value of the range
 */
+ (instancetype __nonnull)rangeWithMinimum:(id __nullable)minimum andMaximum:(id __nullable)maximum;

/**
 Initializes the range with its minimum and maximum index path.
 @param minimumIndex The minimum index of the range.
 @param maximumIndex The maximum index of the range
 */
+ (instancetype __nonnull)rangeWithMinimumIndex:(NSInteger)minimumIndex andMaximumIndex:(NSInteger)maximumIndex;

/** 
 The range's minimum.
 */
@property (nonatomic, strong, nullable) id minimum;

/** 
 The range's maximum.
 */
@property (nonatomic, strong, nullable) id maximum;

/** 
 Initializes the range with its minimum and maximum.
 @param minimum The minimum value of the range.
 @param maximum The maximum value of the range 
 */
- (instancetype __nonnull)initWithMinimum:(id __nullable)minimum andMaximum:(id __nullable)maximum;

/** 
 Defines the range's minimum and maximum.
 @param minimum The minimum value of the range.
 @param maximum The maximum value of the range.
 */
- (void)setMinimum:(id __nullable)minimum andMaximum:(id __nullable)maximum;

/** 
 Defines the range's minimum and maximum.
 @param minimum The minimum value of the range.
 @param maximum The maximum value of the range.
 @param includeCurrentRange Includes the current values in calculation.
*/
- (void)setMinimum:(id __nullable)minimum andMaximum:(id __nullable)maximum calcWithCurrent:(BOOL)includeCurrentRange;

@end
