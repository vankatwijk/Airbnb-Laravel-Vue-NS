//
//  TKEntityPropertyGroupView_Internal.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKEntityPropertyGroupView.h"

@class TKDataForm;
@class TKEntityPropertyGroup;
@class  TKDataFormEditor;

@interface TKEntityPropertyGroupView ()

@property (nonatomic, weak, readonly) TKDataForm *owner;

- (id)initWithOwner:(TKDataForm *)owner propertyGroup:(TKEntityPropertyGroup *)group;

- (void)addEditor:(TKDataFormEditor *)editor;

- (void)expand:(void (^)())completion;

- (void)collapse:(void (^)())completion;

@end
