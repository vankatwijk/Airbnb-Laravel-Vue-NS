//
//  TKDataFormRangeValidator.h
//  TelerikUI
//
//  Copyright © 2016 Telerik. All rights reserved.
//

#import "TKDataFormPropertyValidator.h"

@class TKRange;
@interface TKDataFormRangeValidator : TKDataFormPropertyValidator

@property (nonatomic, strong) TKRange *range;

- (id)initWithRange:(TKRange *)range;

@end
