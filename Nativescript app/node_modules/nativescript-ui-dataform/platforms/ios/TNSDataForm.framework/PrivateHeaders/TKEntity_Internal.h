//
//  TKEntity_Internal.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TKEntity.h"

@interface TKEntity ()

- (TKEntityPropertyType)propertyTypeForNumericProperty:(NSNumber *)propertyValue;
- (void)reload;

@end
