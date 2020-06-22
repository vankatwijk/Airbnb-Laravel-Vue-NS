//
//  TKCollection.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 Represents a collection.
 */
@protocol TKCollection <NSFastEnumeration>

/**
 Returns the number of objects in the collection.
 */
@property (nonatomic, readonly) NSUInteger count;

/**
 Returns the object located at the specified index.
 @param index The object's index.
 */
- (id)objectAtIndex:(NSUInteger)index;

@end
