//
//  TKEntity.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKEntityProperty;
@class TKEntityPropertyGroup;

/**
 @discussion This class represents a model that is created from the business object.
 */
@interface TKEntity : NSObject

/**
 The object from which a model will be created.
 */
@property (nonatomic, weak) NSObject *sourceObject;

/**
 @return An array of TKEntityProperty objects containing all the properties from the bisuness object.
 */
@property (nonatomic, strong, readonly) NSArray *properties;

/**
 @return An array of TKEntityPropertyGroup objects.
 */
@property (nonatomic, strong, readonly) NSArray *groups;

/**
 @return The default property group that contains all properties without a group name.
 */
@property (nonatomic, strong, readonly) TKEntityPropertyGroup *defaultGroup;

/**
 Instantiates a TKDataFormEntity with an object.
 @param sourceObject The source object.
 */
+ (instancetype)entityWithObject:(NSObject*)sourceObject;

/**
 Instantiates a TKEntity with an object.
 @param sourceObject The source object.
 */
- (instancetype)initWithObject:(NSObject*)sourceObject;

/**
 Instantiates a TKEntity with an object and specific list of properties.
 @param sourceObject The source object.
 @param propertyNames The propery names.
 */
- (instancetype)initWithObject:(NSObject *)sourceObject propertyNames:(NSArray*)propertyNames;

/**
 Instantiates a TKEntity with a JSON formatted string.
 @param str The string containing JSON formatted data.
 @param rootItemKeyPath The key path to an item in the JSON.
 */
- (instancetype)initWithJSONString:(NSString *)str rootItemKeyPath:(NSString *)rootItemKeyPath;

/**
 Instantiates a TKEntity with data coming from a JSON formatted resource.
 @param name The file name.
 @param type The file type.
 @param rootItemKeyPath The key path to an item in the JSON.
 */
- (instancetype)initWithDataFromJSONResource:(NSString *)name
                                                ofType:(NSString*)type
                                       rootItemKeyPath:(NSString*)rootItemKeyPath;

/**
 Instantiates a TKEntity which object will be created from JSON fetched from web service.
 @param url The url where the JSON is located.
 @param rootItemKeyPath The key path to an item in the JSON.
 @param completion The block that is called after the data is loaded.
 */
- (instancetype)initWithJSONFromURL:(NSString *)url
                    rootItemKeyPath:(NSString *)rootItemKeyPath
                         completion:(void (^)(NSError *error))completion;

/**
 Creates a JSON formatted string from the entity's properties.
 @return JSON formatted string.
 */
- (NSString *)writeJSONToString;

/**
 Writes JSON to an output stream.
 @param outputStream The output stream where the JSON will be written.
 @return Nil if the writing is successfull, otherwise NSError object.
 */
- (NSError *)writeJSONToStream:(NSOutputStream *)outputStream;
/**
 Sets a new source object and creates its model.
 @param sourceObject The object from which a model will be created.
 @param propertyNames The propery names.
 */
- (void)setSourceObject:(NSObject *)sourceObject withPropertyNames:(NSArray*)propertyNames;

/**
 Sets a new source object and creates its model.
 @param sourceObject The object from which a model will be created.
 @param properties A list containing valid TKEntityProperty objects.
 */
- (void)setSourceObject:(NSObject *)sourceObject withProperties:(NSArray *)properties;

/**
 The TKEntityProperty with the specified name.
 @param propertyName The name of the property that has to be returned.
 @return TKEntityProperty.
 */
- (TKEntityProperty*)propertyWithName:(NSString*)propertyName;

/**
 The TKEntityProperty with the specified name.
 @param propertyName The name of the property that has to be returned.
 @return TKEntityProperty.
 */
- (TKEntityProperty*)objectForKeyedSubscript:(NSString*)propertyName;

/**
 Returns the group at the specified index.
 @param index The group index.
 @return TKEntityPropertyGroup.
 */
- (TKEntityPropertyGroup*)groupAtIndex:(NSUInteger)index;

/**
 Returns the group with the specified name.
 @param groupName The group name.
 @return TKEntityPropertyGroup.
 */
- (TKEntityPropertyGroup*)groupWithName:(NSString*)groupName;

/**
 Creates a new group with the specified name and properties.
 @param name The group name.
 @param propertyNames a list with property names to include in the group.
 @return TKEntityPropertyGroup.
 */
- (TKEntityPropertyGroup*)addGroupWithName:(NSString*)name propertyNames:(NSArray*)propertyNames;

/**
 Adds a new group.
 @param group The group instance.
 */
- (void)addGroup:(TKEntityPropertyGroup*)group;

/**
 Inserts a new group at the specified index.
 @param group The group instance.
 @param index The index where the group should be inserted.
 */
- (void)insertGroup:(TKEntityPropertyGroup*)group atIndex:(NSUInteger)index;

/**
 Removes the group at the specified index.
 @param index The index of the group to remove.
 */
- (void)removeGroupAtIndex:(NSUInteger)index;

/**
 Removes the specified group.
 @param group The group to remove.
 */
- (void)removeGroup:(TKEntityPropertyGroup*)group;

/**
 Removes all groups.
 */
- (void)removeAllGroups;

/**
 Commits the values of all properties to the bussiness object.
 */
- (BOOL)commit;
/**
 Validates all properties and returns an array with property names that did not pass validation.
 */
- (NSArray *)validate;

@end
