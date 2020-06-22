//
//  TKDataFormRegExValidator.h
//  TelerikUI
//
//  Copyright © 2017 Telerik. All rights reserved.
//

#import "TKDataFormPropertyValidator.h"

@interface TKDataFormRegExValidator : TKDataFormPropertyValidator
    
@property (nonatomic) NSString* regEx;
    
- (id)initWithRegEx:(NSString*)regEx;
    
@end
