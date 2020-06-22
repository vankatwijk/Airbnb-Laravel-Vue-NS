//
//  TKDataFormEditorStyle.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKStyleNode.h"

@class TKStroke;
@class TKFill;

/**
 @enum TKDataFormEditorTextLabelDisplayMode
 @discussion Defines the visibility of the text label
 */
typedef NS_ENUM(int, TKDataFormEditorTextLabelDisplayMode)
{
    /**
     Visibile
     */
    TKDataFormEditorTextLabelDisplayModeShow,
    /**
     Hidden
     */
    TKDataFormEditorTextLabelDisplayModeHidden
};

/**
Represents the style of an editor when using TKDataForm.
*/
@interface TKDataFormEditorStyle : TKStyleNode

/**
 The editor stroke.
 */
@property (nonatomic, strong, nullable) TKStroke *stroke;

/**
 The accessoryArrow stroke.
 */
@property (nonatomic, strong, nullable) TKStroke *accessoryArrowStroke;

/**
 The editor fill.
 */
@property (nonatomic, strong, nullable) TKFill *fill;

/**
 The insets for the editor.
 */
@property (nonatomic) UIEdgeInsets insets;

/**
 The separator fill color.
 */
@property (nonatomic, strong, nullable) TKFill *separatorColor;

/**
 Sets empty space before the separator
 */
@property (nonatomic) CGFloat separatorLeadingSpace;

/**
 The amount of empty space after the separator.
 */
@property (nonatomic) CGFloat separatorTrailingSpace;

/**
 Defines the visibility of the text label.
 */
@property (nonatomic) TKDataFormEditorTextLabelDisplayMode textLabelDisplayMode;

/**
 The offest amount to the text label.
 */
@property (nonatomic) UIOffset textLabelOffset;

/**
 The width of the text label.
 */
@property (nonatomic) CGFloat textLabelWidth;

/**
 The offset amount to the editor.
 */
@property (nonatomic) UIOffset editorOffset;

/**
 The offest amount to the feedback label.
 */
@property (nonatomic) UIOffset feedbackLabelOffset;

/**
 Offset for the image view.
 */
@property (nonatomic) UIOffset imageViewOffset;

/**
 *  Size for the image view.
 */
@property (nonatomic) CGSize imageViewSize;

/**
 Offset for the feedback image view.
 */
@property (nonatomic) UIOffset feedbackImageViewOffset;

/**
 *  Size of the feedback image.
 */
@property (nonatomic) CGSize feedbackImageSize;

/**
 The size of the accessory arrow.
 */
@property (nonatomic) CGSize accessoryArrowSize;

@end
