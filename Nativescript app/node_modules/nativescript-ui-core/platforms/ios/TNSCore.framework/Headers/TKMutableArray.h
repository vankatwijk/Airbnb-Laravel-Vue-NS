//
//  TKMutableArray.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 @discussion Represents a mutable array that supports keyValuePath access to its items.
 */
@interface TKMutableArray : NSObject<NSFastEnumeration>

/**
 Returns the count of objects.
 @return The count.
 */
- (NSUInteger)count;

/**
 Retruns the first object in the array.
 */
- (id)firstObject;

/**
 Returns the last object in the array.
 */
- (id)lastObject;

/**
 Returns a NSArray representation of the object.
 */
@property (nonatomic, strong, readonly) NSArray* array;

/**
 Initializes a mutable array from an array.
 @param array The array used for initialization.
 */
- (instancetype)initWithArray:(NSArray*)array;

/**
 Adds an object to the array.
 @param object The object which will be added to the array.
 */
- (void)addObject:(id)object;

/**
 Removes object from the array
 @param object The object which will be removed from the array.
 */
- (void)removeObject:(id)object;

/**
 Removes an object at a specified index.
 @param index The index of the object that will be removed.
 */
- (void)removeObjectAtIndex:(NSUInteger)index;

/**
 Returns a object at an index.
 @param index The object's index.
 @return A object
 */
- (id)objectAtIndex:(NSUInteger)index;

/**
 Returns the object at the specified index.
 @param idx The object's index in the array
 */
- (id)objectAtIndexedSubscript:(NSUInteger)idx;

/**
 Sets an object at specific index
 @param obj The object
 @param idx The index position
 */
- (void)setObject:(id)obj atIndexedSubscript:(NSUInteger)idx;

@end
