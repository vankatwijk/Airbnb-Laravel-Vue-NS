//
//  TKDataForm_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataForm.h"

@class TKDataFormViewController;
@class TKEntityPropertyGroupView;

@interface TKDataForm ()


@property (nonatomic, strong) UIView *firstResponderView;

@property (nonatomic) TKDataFormEditor *selectedEditor;

- (void)editorValueChanged:(TKDataFormEditor *)editor;

- (TKDataFormEditor *)createEditorForProperty:(TKEntityProperty*)property;

- (void)groupViewTapped:(TKEntityPropertyGroupView *)groupView collapse:(BOOL)shouldCollapse completion:(void (^)())completion;

- (void)didSelectEditor:(TKDataFormEditor *)editor inGroupView:(TKEntityPropertyGroupView *)groupView;

- (void)commitPropertyValueWithEditor:(TKDataFormEditor *)editor;

@end
