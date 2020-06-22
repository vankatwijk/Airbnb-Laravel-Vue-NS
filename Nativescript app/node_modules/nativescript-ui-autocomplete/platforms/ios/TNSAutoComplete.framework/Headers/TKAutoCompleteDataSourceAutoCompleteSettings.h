//
//  TKAutoCompleteDataSourceAutoCompleteSettings.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

@class TKAutoCompleteToken;

/**
 * @enum TKAutoCompleteCompletetionMode
 * @discussion Represents an enum that defines the possible completion modes of the TKAutoComplete.
 */

typedef NS_ENUM(int, TKAutoCompleteCompletionMode)
{
    /**
     All items that start with the specified string will be matched.
     */
    TKAutoCompleteCompletionModeStartsWith,
    /**
     All items that contain the specified string will be matched.
     */
    TKAutoCompleteCompletionModeContains
};

/**
 Defines a block function that is used when creating a new token in TKAutoCompleteTextViewwhen using it with TKDataSourceExtended.
 
 @param dataIndex The point index within the series.
 @param item The item associated with this point.
 */
typedef TKAutoCompleteToken* __nullable (^TKAutoCompleteDataSourceAutoCompleteSettings_CreateTokenBlock)(NSUInteger dataIndex, id __nonnull item);

/**
 Represents the settings that can be customized when using TKDataSourceExtended with TKAutoComplete.
 */
@interface TKAutoCompleteDataSourceAutoCompleteSettings : NSObject

@property (nonatomic, strong, nonnull) NSString *valueKey;

/**
 Represents the completion mode of the autocomplete
 */
@property (nonatomic, assign) TKAutoCompleteCompletionMode completionMode;

/**
 Defines whether the searched string should be highlight in the matches.
 */
@property (nonatomic, assign) BOOL highlightMatch;

/**
 Defines the color of match highlighting.
 */
@property (nonatomic, strong) UIColor* _Nullable highlightColor;

/**
 Defines a block function that is called when creating a new token in TKAutoComplete.
 
 @param createToken The block function that will be when creating a new point.
 */
- (void)createToken:(TKAutoCompleteDataSourceAutoCompleteSettings_CreateTokenBlock __nonnull)createToken;

@end
