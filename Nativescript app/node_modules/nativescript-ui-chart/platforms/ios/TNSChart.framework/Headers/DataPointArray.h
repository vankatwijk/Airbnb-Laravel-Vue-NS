//
//  DataPointArray.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@interface DataPointArray : NSArray

@property (nonatomic, readonly) NSUInteger position;

- (instancetype)initWithHost:(NSArray *)array position:(NSInteger)position count:(NSInteger)count;

- (void)setPosition:(NSInteger)position count:(NSInteger)count;

@end