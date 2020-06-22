//
//  TKDataFormPropertyValidator.h
//  TelerikUI
//
//  Copyright © 2016 Telerik. All rights reserved.
//

#import "TKDataFormValidator.h"

@interface TKDataFormPropertyValidator : NSObject <TKDataFormValidator>

@property (nonatomic, strong, nullable) NSString *positiveMessage;

@property (nonatomic, strong, nullable) NSString *errorMessage;

- (BOOL)validateProperty:(TKEntityProperty * __nonnull)property;

@end
