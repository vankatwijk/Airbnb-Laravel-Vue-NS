//
//  TKDataFormStringToDateTimeConverter.h
//  TelerikUI
//
//  Copyright © 2016 Telerik. All rights reserved.
//

#import "TKDataFormConverter.h"

@interface TKDataFormStringToDateTimeConverter : NSObject <TKDataFormConverter>

@property (nonatomic, strong) NSString *format;
@property (nonatomic, strong) NSLocale *locale;
@property (nonatomic) BOOL useLongFormat;

@end
