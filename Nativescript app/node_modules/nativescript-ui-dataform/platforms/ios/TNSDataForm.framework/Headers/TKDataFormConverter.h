//
//  TKDataFormConverter.h
//  TelerikUI
//
//  Copyright © 2016 Telerik. All rights reserved.
//

@protocol TKDataFormConverter <NSObject>

- (id)convertFrom:(id)source;

- (id)convertTo:(id)source;

@end
