//
//  TKBalloonShape.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKShape.h"

/**
 Represents a trackabll tooltip arrow position
 */
typedef NS_ENUM(NSInteger, TKBalloonShapeArrowPosition) {
    /**
     The arrow is not visible
     */
    TKBalloonShapeArrowPositionNone = 0,
    /**
     The arrow is at left side of balloon shape
     */
    TKBalloonShapeArrowPositionLeft = 1,
    /**
     The arrow is in the right side of balloon shape
     */
    TKBalloonShapeArrowPositionRight = 2,
    /**
     The arrow is in the top side of balloon shape
     */
    TKBalloonShapeArrowPositionTop = 3,
    /**
     The arrow is in the bottom side of balloon shape
     */
    TKBalloonShapeArrowPositionBottom = 4,
    /**
     The arrow is in the left-top side of balloon shape
     */
   TKBalloonShapeArrowPositionLeftTop = 5,
    /**
     The arrow is in the left-bottom side of balloon shape
     */
   TKBalloonShapeArrowPositionLeftBottom = 6,
    /**
     The arrow is in the right-top side of balloon shape
     */
    TKBalloonShapeArrowPositionRightTop = 7,
    /**
     The arrow is in the right-bottom side of balloon shape
     */
    TKBalloonShapeArrowPositionRightBottom = 8,
    /**
     The arrow is in the top-left side of balloon shape
     */
    TKBalloonShapeArrowPositionTopLeft = 9,
    /**
     The arrow is in the top-right side of balloon shape
     */
    TKBalloonShapeArrowPositionTopRight = 10,
    /**
     The arrow is in the bottom-left side of balloon shape
     */
    TKBalloonShapeArrowPositionBottomLeft = 11,
    /**
     The arrow is in the bottom-right side of balloon shape
     */
    TKBalloonShapeArrowPositionBottomRight = 12,
};

/**
 Represents a balloon shape with arrow
 */
@interface TKBalloonShape : TKShape

/**
 Initializes the balloon shape
 @param arrowPosition The arrow position
 @param size The size position
 */
- (instancetype __nonnull)initWithArrowPosition:(TKBalloonShapeArrowPosition)arrowPosition size:(CGSize)size;

/**
 Gets or sets the arrow position
 */
@property (nonatomic, assign) TKBalloonShapeArrowPosition arrowPosition;

/**
 Gets or sets the arrow size
 */
@property (nonatomic, assign) CGSize arrowSize;

/**
 Gets or sets the corner radius of shape
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 Gets or sets an offset which will be used when calculating the arrow position when it is centered.
 */
@property (nonatomic, assign) CGFloat arrowOffset;

/**
 Gets or sets a value which determines how to align the arrow when a corner arrow position is selected
 */
@property (nonatomic, assign) BOOL useStrictArrowPosition;

@end
