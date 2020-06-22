//
//  TKChartRotateGestureRecognizer.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 @discussion Represents a rotation gesture recognizer for TKChart.
 */
@interface TKChartRotateGestureRecognizer : UIGestureRecognizer

/**
 Returns the rotation's angle (read-only).
 */
@property (nonatomic, assign, readonly) CGFloat rotation;

/**
 Returns the rotation's velocity.
 */
@property (nonatomic, assign, readonly) CGFloat velocity;

/**
 Determines whether the rotation is clockwise or not.
 */
@property (nonatomic, assign, readonly) BOOL clockwise;

@end
