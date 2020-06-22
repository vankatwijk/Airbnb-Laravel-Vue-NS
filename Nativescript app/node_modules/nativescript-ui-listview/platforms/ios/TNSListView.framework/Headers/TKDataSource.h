//
//  TKDataSource.h
//  TestDataSource
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKView.h"

@class TKDataSourceSettings;
@class TKDataSourceGroup;
@class TKDataSourceSortDescriptor;
@class TKDataSourceFilterDescriptor;
@class TKDataSourceGroupDescriptor;

/**
 * @enum TKDataSourceDataFormat
 * @discussion Represents an enum that defines the format of the data that can be parsed by TKDataSource.
 */
typedef NS_ENUM(NSInteger, TKDataSourceDataFormat) {
    /**
     The data is in JSON format.
     */
    TKDataSourceDataFormatJSON,
};

/**
 Defines a block that is used when evaluating the text for an item in TKDataSource.
 
 @param item The item that is evaluated.
 @param group The group which owns this item. Can be nil if no grouping is applied.
 */
typedef NSString* __nullable (^TKDataSourceFormatTextBlock)(id __nonnull item, TKDataSourceGroup * __nullable group);

/**
 Defines a block that is used when enumerating items in TKDataSource.
 
 @param item The current item.
 */
typedef void (^TKDataSourceEnumerator)(id __nonnull item);

/**
 Defines a block that is used when mapping the items in TKDataSource.
 
 @param item The current item that is mapped.
 */
typedef id __nonnull (^TKDataSourceMapFunctionBlock)(id __nonnull item);

/**
 Defines a block that is used when reducing the items in TKDataSource to a single value.
 
 @param item The item that is reduced.
 @param value The current value.
 */
typedef id __nonnull (^TKDataSourceReduceFunctionBlock)(id __nonnull item, id __nonnull value);

/**
 Defines a block that is used when filtering items in TKDataSource.
 
 @param item The item that is tested.
 */
typedef BOOL (^TKDataSourceFilterBlock)(id __nonnull item);



/**
 @discussion TKDataSource is an adapter that consumes data from various sources and has functionality for data manipulations. It implements various data source protocols and can be used as a data source for TKChart, TKCalendar, TKListView, UITableView and UICollectionView.
 */
@interface TKDataSource : NSObject <UITableViewDataSource,
                                    UITableViewDelegate,
                                    UICollectionViewDataSource,
                                    UICollectionViewDelegate,
                                    NSURLConnectionDataDelegate,
                                    NSURLConnectionDelegate>

#pragma mark - Properties

/**
 The item source for this class. It can be a simple array with value types, complex objects or a dictionary.
 */
@property (nonatomic, strong, nullable) id itemSource;

/**
 An array view of the items contained in the itemSource after applying sorting, grouping and filtering operations.
 */
@property (nonatomic, readonly, nonnull) NSArray *items;

/**
 The current item. It is syncronized among all consumers of this class.
 */
@property (nonatomic, weak, null_unspecified) id currentItem;

/**
 The display key used when extracting text from a single item.
 */
@property (nonatomic, copy, nullable) NSString *displayKey;

/**
 The value key used when extracting a value from a single item.
 */
@property (nonatomic, copy, nullable) NSString *valueKey;

/**
 The key used to extract items for specific group when grouping is applied. The key path is relative to the group object.
 */
@property (nonatomic, copy, nullable) NSString *groupItemSourceKey;

/**
 Provides the ability to customize the appearance of TKDataSource consumers. e.g. TKChart, TKCalendar, UITableView, etc.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataSourceSettings *settings;

/**
 A formatted that is applied when extracting text from an item by using the displayKey property.
 */
@property (nonatomic, strong, nullable) NSFormatter *formatter;

/**
 Determines whether items reordering is allowed or not.
 */
@property (nonatomic) BOOL allowItemsReorder;

/**
 When parsing data from JSON TKDataSource chaecks whether the mapClass property is set.
 If true it tries to create an instance of this class and initializes its properties with the JSON data.
 */
@property (nonatomic, nullable) Class mapClass;

/**
 Used when initializing an instance of mapClass to map its properties against JSON data.
 The format is: <class-property-name>:<json-field-name>
 */
@property (nonatomic, strong, nullable) NSDictionary *propertyMap;

/**
 When set to YES TKDataSource tries to map NSArray value proerties with instances of mapClass.
 */
@property (nonatomic) BOOL mapCollectionsRecursively;

#pragma mark - Initialization

/**
 Initializes the data source with a value for the itemSource property.

 @param itemSource The value for the itemSource property.
 */
- (instancetype __nonnull)initWithItemSource:(id __nonnull)itemSource;

/**
 Initializes the data source with an array of items.
 
 @param items The array that is assigned to the itemSource property.
 */
- (instancetype __nonnull)initWithArray:(NSArray* __nonnull)items;

/**
 Initializes the data source with an array of items and parameters.
 
 @param items The array that is assigned to the itemSource property.
 @param displayKey The display key to use.
 */
- (instancetype __nonnull)initWithArray:(NSArray* __nonnull)items displayKey:(NSString* __nullable)displayKey;

/**
 Initializes the data source with an array of items and parameters.
 
 @param items The array that is assigned to the itemSource property.
 @param displayKey The display key to use.
 @param valueKey The value key to use.
 */
- (instancetype __nonnull)initWithArray:(NSArray* __nonnull)items displayKey:(NSString* __nullable)displayKey valueKey:(NSString* __nullable)valueKey;

/**
 Initializes the data source with a JSON formatted string.

 @param str The string containing JSON formatted data.
 */
- (instancetype __nonnull)initWithJSONString:(NSString * __nonnull)str;

/**
 Initializes the data source with data coming from a web service.

 @param url The url where the data is located.
 @param dataFormat The format of the data coming from the web service.
 @param rootItemKeyPath The key path to the item containing the items collection that will be used in this data source.
 @param completion The block that is called after the data is loaded.
 */
- (instancetype __nonnull)initWithDataFromURL:(NSString* __nonnull)url
               dataFormat:(TKDataSourceDataFormat)dataFormat
          rootItemKeyPath:(NSString* __nullable)rootItemKeyPath
               completion:(void (^ __nullable)(NSError * __nullable error))completion;

/**
 Initializes the data source with data coming from a JSON formatted resource.
 
 @param name The file name.
 @param type The file type.
 @param rootItemKeyPath The key path to the item containing the items collection that will be used in this data source.
 */
- (instancetype __nonnull)initWithDataFromJSONResource:(NSString * __nonnull)name
                            ofType:(NSString* __nonnull)type
                   rootItemKeyPath:(NSString* __nullable)rootItemKeyPath;

/**
 Reads a JSON formatted string and loads the parsed data in the data source.

 @param string The string containing JSON formatted data.
 @param rootItemKeyPath The key path to the item containing the items collection that is used in this data source.
 */
- (void)loadDataFromJSONString:(NSString* __nonnull)string rootItemKeyPath:(NSString* __nullable)rootItemKeyPath;

/**
 Reads a JSON formatted resource and loads the parsed data in the data source.
 
 @param name The file name.
 @param type The file type.
 @param rootItemKeyPath The key path to the item containing the items collection that is used in this data source.
 */
- (void)loadDataFromJSONResource:(NSString * __nonnull)name ofType:(NSString* __nonnull)type rootItemKeyPath:(NSString* __nullable)rootItemKeyPath;

/**
 Downloads data from a web service and initializes the data source with it.

 @param url The url where the data is located.
 @param dataFormat The format of the data coming from the web service.
 @param rootItemKeyPath The key path to the item containing the items collection that is used in this data source.
 @param completion A block that is called after the data is loaded.
 */
- (void)loadDataFromURL:(NSString* __nonnull)url
             dataFormat:(TKDataSourceDataFormat)dataFormat
        rootItemKeyPath:(NSString* __nullable)rootItemKeyPath
             completion:(void (^ __nullable)(NSError *  __nullable error))completion;



#pragma mark - Descriptors

/**
 Returns a list with filter descriptors that is applied after the itemSource propety is set.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray <__kindof TKDataSourceFilterDescriptor* > * filterDescriptors;

/**
 Adds a new filter descriptor.

 @param filterDescriptor The filter descriptor to add.
 */
- (void)addFilterDescriptor:(TKDataSourceFilterDescriptor* __nonnull)filterDescriptor;

/**
 Removes a filter descriptor.

 @param filterDescriptor The filter descriptor to remove.
 */
- (void)removeFilterDescriptor:(TKDataSourceFilterDescriptor* __nonnull)filterDescriptor;

/**
 Removes all filter descriptors.
 */
- (void)removeAllFilterDescriptors;

/**
 Returns a list with sort descriptors that is applied after the itemSource propety is set.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray <__kindof TKDataSourceSortDescriptor* > * sortDescriptors;

/**
 Adds a new sort descriptor.
 
 @param sortDescriptor The sort descriptor to add.
 */
- (void)addSortDescriptor:(TKDataSourceSortDescriptor* __nonnull)sortDescriptor;

/** 
 Removes a sort descriptor.
 
 @param sortDescriptor The sort descriptor to remove.
 */
- (void)removeSortDescriptor:(TKDataSourceSortDescriptor* __nonnull)sortDescriptor;

/**
 Removes all sort descriptors.
 */
- (void)removeAllSortDescriptors;

/**
 Returns a list with group descriptors that will be applied when the itemSource propety is set.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray <__kindof TKDataSourceGroupDescriptor* > * groupDescriptors;

/**
 Adds a new group descriptor.
 
 @param groupDescriptor The group descriptor to be added.
 */
- (void)addGroupDescriptor:(TKDataSourceGroupDescriptor* __nonnull)groupDescriptor;

/**
 Removes a group descriptor.
 
 @param groupDescriptor The group descriptor to remove.
 */
- (void)removeGroupDescriptor:(TKDataSourceGroupDescriptor* __nonnull)groupDescriptor;

/**
 Removes all group descriptors.
 */
- (void)removeAllGroupDescriptors;

/**
 Reloads the data and applies again all descriptors. Call this method when the data has changed.
 */
- (void)reloadData;



#pragma mark - Data operations

/**
 Apples the specified block to all items in the data source and allows changing their values.

 @param mapBlock The block function that is applied to all items.
 */
- (void)map:(TKDataSourceMapFunctionBlock __nonnull)mapBlock;

/**
 Enumerates all items in the data source.
 
 @param enumeratorBlock The block function that is called when enumerating data source items.
 */
- (void)enumerate:(TKDataSourceEnumerator __nonnull)enumeratorBlock;

/**
 Reduces the items collection to a single value and returns it.
 
 @param initialValue The value to start with.
 @param reduceBlock The block function that is called when reducing the items collection.
 */
- (id __nonnull)reduce:(id __nonnull)initialValue with:(TKDataSourceReduceFunctionBlock __nonnull)reduceBlock;

/**
 Filters the items in the data source.
 
 @param filterBlock The block function that is used when filtering.
 */
- (void)filter:(TKDataSourceFilterBlock __nonnull)filterBlock;

/**
 Filters the items in the data source by using a query.
 
 @param filterQuery The filter query that is used to filter the items.
 */
- (void)filterWithQuery:(NSString* __nonnull)filterQuery;

/**
 Sorts the items in the data source.
 
 @param comparatorBlock The comparator block function that is used when sorting.
 */
- (void)sort:(NSComparator __nonnull)comparatorBlock;

/**
 Sorts the items in the data source by using a property name.
 
 @param propertyName The property that is used to sort the items.
 @param ascending The sort direction.
 */
- (void)sortWithKey:(NSString* __nonnull)propertyName ascending:(BOOL)ascending;

/**
 Groups the items in the data source.
 
 @param keyForItem The group block function that is used to get a group key.
 */
- (void)group:(TKDataSourceMapFunctionBlock __nonnull)keyForItem;

/**
 Groups the items in the data source.
 
 @param keyForItem The group block function that is used to get a group key.
 @param comparatorBlock The comparator to be used to sort groups.
 */
- (void)group:(TKDataSourceMapFunctionBlock __nonnull)keyForItem comparator:(NSComparator __nonnull)comparatorBlock;

/**
 Groups the items in the data source by using a property name.
 
 @param propertyName The property that is used to group the items.
 */
- (void)groupWithKey:(NSString* __nonnull)propertyName;

/**
 Groups the items in the data source by using a property name.
 
 @param propertyName The property that is used to group the items.
 @param comparatorBlock The comparator to be used to sort groups.
 */
- (void)groupWithKey:(NSString* __nonnull)propertyName comparator:(NSComparator __nonnull)comparatorBlock;

#pragma mark - Methods

/**
 Moves an item. This method is applicable only when grouping is not applied.
 
 @param fromIndex The old item index.
 @param toIndex The new item index.
 */
- (void)moveItemAtIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;

/**
 Returns the value of an item. Uses the valueKey property.
 
 @param item The item.
 @param group The group which owns this item. Can be nil if there is no grouping applied.
 */
- (id __nullable)valueForItem:(id __nonnull)item inGroup:(TKDataSourceGroup* __nullable)group;

/**
 Returns the text for the item. Uses the displayKey property.
 
 @param item The item.
 @param group The group which owns this item. Can be nil if there is no grouping applied.
 */
- (NSString* __nullable)textFromItem:(id __nonnull)item inGroup:(TKDataSourceGroup* __nullable)group;

/**
 Defines a textblock that is applied to get the text from an item when calling the textForItem method if specified.
 
 @param  formatTextBlock The block function that gets text from an item.
 */
- (void)formatText:(TKDataSourceFormatTextBlock __nonnull)formatTextBlock;

/**
 Return the `NSIndexPath` of the passed object.
 
 @param  itemToFind The object of whom the NSIndexPath is being looked for.
 */
- (NSIndexPath* __nullable)findItem:(id _Nonnull )itemToFind;

@end
