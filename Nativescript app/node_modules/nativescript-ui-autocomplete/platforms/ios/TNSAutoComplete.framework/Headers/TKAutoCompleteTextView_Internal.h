//
//  TKAutoCompleteTextView_Internal.h
//  TelerikUI
//
//  Created by Sophia Lazarova on 1/6/16.
//  Copyright © 2016 Telerik. All rights reserved.
//

#import "TKAutoCompleteTextView.h"

@interface TKAutoCompleteTextView ()

- (void)textFieldWasUpdated:(UITextField *)sender;
- (void)performRemovingOfToken:(TKAutoCompleteTokenView*)tokenToRemove withModel:(TKAutoCompleteToken*) token;

@end
