//
//  TKDataFormMaximumLengthValidator.h
//  TelerikUI
//
//  Copyright © 2016 Telerik. All rights reserved.
//

#import "TKDataFormPropertyValidator.h"

@interface TKDataFormMaximumLengthValidator : TKDataFormPropertyValidator

@property (nonatomic) NSInteger maximumLegth;

- (id)initWithMaximumLength:(NSInteger)maximumLength;

@end
