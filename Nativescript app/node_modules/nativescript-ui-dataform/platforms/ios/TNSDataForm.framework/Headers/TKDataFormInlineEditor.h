//
//  TKDataFormInlineEditor.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

@class TKLabel;
/**
 @enum TKDataFormInlineEditorDisplayMode
 @discussion An enum that defines how inline editors are displayed.
 */
typedef NS_ENUM(NSInteger, TKDataFormInlineEditorDisplayMode) {
    /**
     Indicator will be displayed inline.
     */
    TKDataFormInlineEditorDisplayModeInline,
    
    /**
     Indicator will be displayed modally.
     */
    TKDataFormInlineEditorDisplayModeModal
};

/**
 @discussion An abstract base class for editors that can be displayed inline.
 */
@interface TKDataFormInlineEditor : TKDataFormEditor

/**
 A label for the editor's value.
 */
@property (nonatomic, strong, readonly, nonnull) TKLabel *editorValueLabel;

/**
 The editor's accesory image.
 */
@property (nonatomic, strong, readonly, nonnull) UIImageView *accessoryImageView;

/**
 A bool that determines if accessory image should be visible.
 */
@property (nonatomic) BOOL showAccessoryImage;

/**
 The editor's display mode.
 */
@property (nonatomic) TKDataFormInlineEditorDisplayMode displayMode;

@end
