//
//  TKChartStackInfo.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 @enum TKChartStackMode
 @discussion Defines the stack modes of TKChart series.
 */
typedef NS_ENUM(NSInteger, TKChartStackMode) {
    /**
     Stack series.
     */
    TKChartStackModeStack,
    /**
     Stack series up to 100%.
     */
    TKChartStackModeStack100
};

/**
 @discussion Represents a set of stack properties.
 */
@interface TKChartStackInfo : NSObject

/**
 The stack info id.
 */
@property (nonatomic, strong) id __nonnull stackID;

/**
 The stack info mode.
 
 @discussion The stack modes are defined as follows:
 
    typedef enum {
        TKChartStackModeStack,      // Stack series.
        TKChartStackModeStack100    // Stack series up to 100%.
    } TKChartStackMode;

 */
@property (nonatomic, assign) TKChartStackMode stackMode;

/**
 Initializes the stack info class.
 @param aStackID The stack id.
 @param aStackMode The stack mode.
 */
- (instancetype __nonnull)initWithID:(id __nonnull )aStackID withStackMode:(TKChartStackMode)aStackMode;

@end
