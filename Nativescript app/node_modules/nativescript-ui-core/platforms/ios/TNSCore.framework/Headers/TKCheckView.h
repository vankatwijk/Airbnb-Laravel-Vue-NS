//
//  TKCheckView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKView.h"

/**
 A visual glyph representing a checked/unchecked state.
 */
@interface TKCheckView : TKView

/**
 Defines the checked/unchecked visual state.
 */
@property (nonatomic) BOOL isChecked;

/**
 Defines the checkmark shape.
 */
@property (nonatomic, strong) TKShape *checkShape;

/**
 The check's fill
 */
@property (nonatomic, strong) TKFill *checkFill;

/**
 The check's stroke
 */
@property (nonatomic, strong) TKStroke *checkStroke;

@end
