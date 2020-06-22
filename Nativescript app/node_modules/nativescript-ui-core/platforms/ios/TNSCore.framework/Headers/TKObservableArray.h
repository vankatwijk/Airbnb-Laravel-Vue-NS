//
//  TKObservableArray.h
//  TelerikUI
//
//  Created by Viktor Skarlatov on 11/30/16.
//  Copyright © 2016 Telerik. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TKObservableArrayDelegate <NSObject>

@optional
- (void) didAddObject: (id) object atIndex: (NSInteger) index;
- (void) didRemoveObject: (id) object atIndex: (NSInteger) index;
- (void) didSetObject: (id) object atIndex: (NSInteger) index ofOldObject: (id) oldObject;
@end

@interface TKObservableArray : NSObject<NSFastEnumeration>

@property (weak, nonatomic) id<TKObservableArrayDelegate> delegate;
/**
 Returns a NSArray representation of the object.
 */
@property (nonatomic, strong, readonly) NSArray* array;

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

- (BOOL) containsObject: (id) object;

- (NSUInteger) indexOfObject: (id) object;

@property (assign, nonatomic, readonly) NSUInteger count;

@end
