//
//  TKPropertyGroupTitleViewIndicator.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TKStroke;
@class TKSolidFill;

/**
 @discussion A class that represents an indicator for TKEntityPropertyGroupTitle.
 */
@interface TKEntityPropertyGroupTitleViewIndicator : UIView

/**
 Size for the indicator.
 */
@property (nonatomic) CGSize size;

/**
 Stroke for the indicator.
 */
@property (nonatomic, strong, nullable) TKStroke *strokeColor;

/**
 Fill for the indicator.
 */
@property (nonatomic, strong, nullable) TKSolidFill *fillColor;

@end
