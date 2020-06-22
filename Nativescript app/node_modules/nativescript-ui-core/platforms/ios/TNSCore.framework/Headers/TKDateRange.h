//
//  TKDateRange.h
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

/**
 *  A class that represents a range between two dates.
 */
@interface TKDateRange : NSObject

/**
 *  Gets or sets the start date.
 */
@property (nonatomic, strong, nonnull) NSDate *startDate;

/**
 *  Gets or sets the end date.
 */
@property (nonatomic, strong, nonnull) NSDate *endDate;

/**
 *  A boolean that indicates if the range has been normalized.
 */
@property (nonatomic, readonly) BOOL isNormalized;

/**
 *  Initializes a new instance of TKDateRange with start and end dates
 *
 *  @param startDate The start date.
 *  @param endDate   The end date.
 *
 *  @return An instance of TKDateRange.
 */
- (instancetype __nonnull)initWithStart:(NSDate* __nonnull)startDate end:(NSDate* __nonnull)endDate;

/**
 *  Normalizes the range by swiping the dates if necessary.
 */
- (void)normalize;

/**
 *  Returns YES if the specified date is contained within the range.
 *
 *  @param date The date to be tested.
 *
 *  @return YES if the date is contained within the range.
 */
- (BOOL)containsDate:(NSDate* __nonnull)date;

@end
