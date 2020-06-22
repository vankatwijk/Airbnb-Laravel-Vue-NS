//
//  TKDataFormMinimumLengthValidator.h
//  TelerikUI
//
//  Copyright © 2016 Telerik. All rights reserved.
//

#import "TKDataFormPropertyValidator.h"

@interface TKDataFormMinimumLengthValidator : TKDataFormPropertyValidator

@property (nonatomic) NSInteger minimumLength;

- (id)initWithMinimumLength:(NSInteger)minimumLength;

@end
