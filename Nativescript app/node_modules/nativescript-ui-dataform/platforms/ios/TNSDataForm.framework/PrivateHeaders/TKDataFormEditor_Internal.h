//
//  TKDataFormEditor_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

@interface TKDataFormEditor ()

@property (nonatomic) BOOL selected;

@property (nonatomic, strong) UIView *inputView;

@property (nonatomic) CGFloat preferredHeight;

- (id)convertedPropertyValue:(id)source;

- (void)setupEditorWithProperty:(TKEntityProperty *)property;

- (void)applyStylesToGridDefinitions;

- (void)notifyValueChange;

- (BOOL)isEditorValueSynced;

@end
