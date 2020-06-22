//
//  TKDataFormMultilineTextEditor.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

@interface TKDataFormMultilineTextEditor : TKDataFormEditor <UITextViewDelegate>

@property (nonatomic, strong, readonly) UITextView *textView;

@property (nonatomic) BOOL dynamicHeight;

@property (nonatomic) CGFloat maxDynamicHeight;

@end
