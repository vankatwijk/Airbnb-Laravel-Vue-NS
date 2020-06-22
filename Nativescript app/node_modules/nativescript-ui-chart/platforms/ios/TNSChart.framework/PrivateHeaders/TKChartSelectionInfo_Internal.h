//
//  TKChartSelectionInfo_Internal.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSelectionInfo.h"

@interface TKChartSelectionInfo ()

/**
 Gets or sets the x-location
 */
@property (nonatomic, assign) CGFloat x;

/**
 Gets or sets the y-location
 */
@property (nonatomic, assign) CGFloat y;

/**
 Sets the location
 */
- (void)setLocation:(CGPoint)location;

@end
