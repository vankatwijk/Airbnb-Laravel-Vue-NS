//
//  TKDataFormCustomEditor.h
//  TelerikUI
//
//  Copyright (c) 2016 Telerik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKDataFormEditor.h"

@class TKDataFormCustomEditor;

/**
 @discussion The methods declared by the TKDataFormCustomEditorDelegate protocol allow the the usage of a custom views as editors in TKDataForm.
 */
@protocol TKDataFormCustomEditorDelegate <NSObject>

@required
/**
 Called when the editor view has to be created.
 @param editor The custom editor requesting a view.
 @return The editor view for the custom editor.
 */
- (UIView* __nullable)editorWillCreateView:(TKDataFormCustomEditor* __nonnull)editor;

/**
 Called when a property value should to be applied to the editor view.
 @param editor The custom editor that should apply value.
 @param value The value that should be applied.
 @param view The editor view that has to be updated with the value.
 */
- (void)editor:(TKDataFormCustomEditor* __nonnull)editor shouldApplyValue:(NSObject* __nullable)value editorView:(UIView* __nullable)view;

/**
 Called when the editor should return its value.
 @param editor The custom editor that requests the value.
 @param view The editor view that currently displays the value.
 @return The current value of the editor.
 */
- (NSObject* __nullable)editorWillReturnValue:(TKDataFormCustomEditor * __nonnull)editor editorView:(UIView* __nullable)view;
@end


/**
 A custom editor for TKDataForm. The TKDataFormCustomEditorDelegate provides the custom view and updates its according to the property value.
 */
@interface TKDataFormCustomEditor : TKDataFormEditor

/**
 The editor's UIView.
 */
@property (nonatomic, strong, readonly) UIView * __nullable editorView;

/**
 A delegate for the editor to provide a view and its value.
 */
@property (nonatomic, weak, nullable) id<TKDataFormCustomEditorDelegate> delegate;

/**
 Called when the value of the editor is changed,
 so it should try to update the property value depending on the current commit mode.
 */
- (void)notifyValueChange;

@end
