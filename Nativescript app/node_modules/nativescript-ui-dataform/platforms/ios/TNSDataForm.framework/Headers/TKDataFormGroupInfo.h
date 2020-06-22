//
//  TKDataFormGroupInfo.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKEntityPropertyGroup;

@interface TKDataFormGroupInfo : NSObject

@property (nonatomic, weak) TKEntityPropertyGroup *group;

@property (nonatomic, strong) NSArray *properties;

@property (nonatomic) NSUInteger index;

- (instancetype)initWithGroup:(TKEntityPropertyGroup*)group;

@end
