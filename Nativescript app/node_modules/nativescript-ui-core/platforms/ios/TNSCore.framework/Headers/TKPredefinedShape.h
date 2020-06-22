//
//  TKPredefinedShape.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKShape.h"

/**
 * @enum TKShapeType
 * @discussion Defines a shape's type.
 */
typedef NS_ENUM(NSInteger, TKShapeType) {
    /**
     No shape.
     */
    TKShapeTypeNone,
    /**
     Square shape.
     */
    TKShapeTypeSquare,
    /**
     Circle shape.
     */
    TKShapeTypeCircle,
    /**
     Triangle pointing up.
     */
    TKShapeTypeTriangleUp,
    /**
     Triangle pointing down.
     */
    TKShapeTypeTriangleDown,
    /**
     Rhombus shape.
     */
    TKShapeTypeRhombus,
    /**
     Pentagon shape.
     */
    TKShapeTypePentagon,
    /**
     Hexagon shape.
     */
    TKShapeTypeHexagon,
    /**
     Star shape.
     */
    TKShapeTypeStar,
    /**
     Heart shape.
     */
    TKShapeTypeHeart,
    
};

/**
 Represents a shape class that allows presenting different shapes based on a list with predefined shapes
 */
@interface TKPredefinedShape : TKShape

/**
 Creates a shape with specified type and size.
 @param type Specifies the type.
 @param size Specifies the size in pixels.
 */
+ (instancetype __nonnull)shapeWithType:(TKShapeType)type andSize:(CGSize)size;

/**
 Creates a shape with specified form and size.
 @param type Specifies the type.
 @param size Specifies the size in pixels.
 */
- (instancetype __nonnull)initWithType:(TKShapeType)type andSize:(CGSize)size;

/**a
 The type of the shape.
 
 @discussion The shape types are defined as follows:
 
 typedef enum TKShapeType {
 TKShapeTypeNone,            // No shape.
 TKShapeTypeSquare,          // Square shape.
 TKShapeTypeCircle,          // Circle shape.
 TKShapeTypeTriangleUp,      // Triangle pointing up.
 TKShapeTypeTriangleDown,    // Triangle pointing down.
 TKShapeTypeDiamond,         // Diamond shape.
 TKShapeTypeRhombus,         // Rhombus shape.
 TKShapeTypePentagon,        // Pentagon shape.
 TKShapeTypeHexagon,         // Hexagon shape.
 TKShapeTypeStar,            // Star shape.
 TKShapeTypeHeart,           // Heart shape.
 } TKShapeType;
 
 */
@property (nonatomic, assign, readonly) TKShapeType type;

@end
