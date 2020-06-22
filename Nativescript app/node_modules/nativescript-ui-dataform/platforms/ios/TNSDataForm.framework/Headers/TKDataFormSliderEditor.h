//
//  TKDataFormSliderCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

/**
 @discussion The default editor for floating point properties. In its essence, it is a UISlider.
 */
@interface TKDataFormSliderEditor : TKDataFormEditor

/**
 The editpr's UISlider control.
 */
@property (nonatomic, strong, readonly) UISlider *sliderView;

/**
 Step value for the slider.
 */
@property (nonatomic) CGFloat stepValue;

@end
