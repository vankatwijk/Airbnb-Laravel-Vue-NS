//
//  TKGridLayoutCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKGridLayoutCellDefinition;

@interface TKGridLayoutCell : NSObject

@property (nonatomic) NSInteger row;

@property (nonatomic) NSInteger col;

@property (nonatomic) CGSize size;

@property (nonatomic) BOOL isUsed;

@property (nonatomic, weak) TKGridLayoutCellDefinition *definition;

- (id)initWithRow:(NSInteger)row col:(NSInteger)col;

@end
