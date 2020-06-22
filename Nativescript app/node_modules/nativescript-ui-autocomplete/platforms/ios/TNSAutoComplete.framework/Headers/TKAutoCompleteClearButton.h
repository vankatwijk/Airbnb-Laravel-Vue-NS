//
//  TKAutoCompleteClearButton.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 The default clear button of the AutoComplete.
 */
@interface TKAutoCompleteClearButton : UIButton

/**
 The background color of the circle button for normal state.
 */
@property(nonatomic, strong) UIColor  *circleBackgroundColor;

/**
 Whether the clear shape should be drawn.
 */
@property (nonatomic) BOOL drawShape;

@end
