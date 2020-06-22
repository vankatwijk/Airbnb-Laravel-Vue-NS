//
//  TKAutoComplete.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TNSCore/TKView.h"

@class TKAutoCompleteToken;
@class TKAutoCompleteTokenView;
@class TKAutoCompleteCoverView;
@class TKAutoCompleteClearButton;

@protocol TKAutoCompleteDelegate;
@protocol TKAutoCompleteDataSource;
@protocol TKAutoCompleteSuggestViewDelegate;

/**
 @enum TKAutoCompleteDisplayMode
 @discussion Defines the display mode of the selected items in TKAutoComplete.
 */

typedef NS_ENUM(int, TKAutoCompleteDisplayMode)
{
    /**
     Only one item can be selected and no tokenizing is applied.
     */
    TKAutoCompleteDisplayModePlain,
    
    /**
     Selected items are tokenized.
     */
    TKAutoCompleteDisplayModeTokens
};

/**
 @enum TKAutoCompleteSuggestMode
 @discussion Defines how the suggestions list is shown.
 */
typedef NS_ENUM(int, TKAutoCompleteSuggestMode)
{
    /**
     Suggestions are shown in a TKListView which can be replaced by a custom view.
     */
    TKAutoCompleteSuggestModeSuggest,
    /**
     Only one suggestion is shown as an instant completion to the types text.
     */
    TKAutoCompleteSuggestModeAppend,
    /**
     Combines Suggest and Append mode.
     */
    TKAutoCompleteSuggestModeSuggestAppend
};

/**
 @enum TKAutoCompleteLayoutMode
 @discussion Defines how the tokens alignment. Used only in TKAutoCompleteDisplayModeTokens.
 */
typedef NS_ENUM(int, TKAutoCompleteLayoutMode)
{
    /**
     Tokens horizontal alignment.
     */
    TKAutoCompleteLayoutModeHorizontal,
    
    /**
     Tokens vertically wrapped alignment.
     */
    TKAutoCompleteLayoutModeWrap
};

/**
 @discussion TkAutoCompleteTextView provides means to perform easy filtering of data and completion suggestioning according to typed text by the user. Provides tokenizing, layouts, completion modes, easy customizations.
 */
@interface TKAutoCompleteTextView: TKView

/**
 TKAutoCompleteDataSource object providing means to filter the suggestion items and populate the suggestion view.
 */
@property (nonatomic, weak, nullable)  id<TKAutoCompleteDataSource> dataSource;

@property(nonatomic, nonnull) TKAutoCompleteCoverView *cover;

/**
 TKAutoCompleteDelegate object allows easy managing of the autocomplete components and the interaction with them.
 */
@property (nonatomic, weak, nullable) id<TKAutoCompleteDelegate> delegate;

/**
 Collection of symbols used in Append and SuggestAppend mode to tokenize or complete the typed text.
 */
@property (nonatomic, strong, nonnull) NSArray<__kindof NSString*> *tokeninzingSymbols;

/**
 The view holding the base autocomplete components.
 */
@property (nonatomic,strong, readonly, nonnull) TKView *contentView;

/**
 The autocomplete label used to show text that can be selected when suggest mode is TKAutoCompleteSuggestModeAppend or TKAutoCompleteSuggestModeSuggestAppend.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *appendLabel;

/**
 The autocomplete textfield.
 */
@property (nonatomic, strong, readonly, nonnull) UITextField *textField;

/**
 The text diplayed when there are no matches for the current input.
 */
@property (nonatomic, strong, nonnull) NSString *noResultsText;

/**
 Controls whether the remove button used to clear the input should be visible.
 */
@property (nonatomic) BOOL showCloseButton;

/**
 The remove button used to clear the input.
 */
@property (nonatomic, strong, readonly, nonnull) TKAutoCompleteClearButton *closeButton;

/**
 The insets for the remove button used to clear the input.
 */
@property (nonatomic) UIEdgeInsets closeButtonInsets;

/**
 The width for the remove button used to clear the input.
 */
@property (nonatomic) CGFloat closeButtonWidth;

/**
 The height for the remove button used to clear the input.
 */
@property (nonatomic) CGFloat closeButtonHeight;

/**
 The label showed if no suggestion are presented. Showed in TKAutoCompleteSuggestModeSuggestAppend and TKAutoCompleteSuggestModeSuggest mode.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *noResultsLabel;

/**
 The image view located in the top left side of the autocomplete. By default is not presented.
 */
@property (nonatomic, strong, readonly, nonnull) UIImageView *imageView;

/**
 The insets for the image view located in the top left side of the autocomplete. By default is not presented.
 */
@property (nonatomic) UIEdgeInsets imageViewInsets;

/**
 The title view located in the top left side of the autocomplete. By default is not presented.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *titleLabel;

/**
 Indicates if the suggestion view is subview of the autocomplete or not. Defalut value is NO.
 */

@property (nonatomic, assign) BOOL suggestionViewOutOfFrame;

/**
 The view which represents the collection of filtered suggestions. Allows customization as well as exchange with custom view.
 */
@property (nonatomic, weak, nullable) UIView<TKAutoCompleteSuggestViewDelegate> *suggestionView;

/**
 Defines the display mode.
 */
@property (nonatomic) TKAutoCompleteDisplayMode displayMode;

/**
 Defines the suggest mode.
 */
@property (nonatomic) TKAutoCompleteSuggestMode suggestMode;

/**
 Defines the layout mode.
 */
@property (nonatomic) TKAutoCompleteLayoutMode layoutMode;

/**
 Indicated whether highlighting of tokens is allowd. Default if YES.
 */
@property(nonatomic) BOOL allowTokenHighlighting;

/**
 Defines whether or not adding tokenizing text outside of the suggestions is allowed.
 */
@property (nonatomic) BOOL allowCustomTokens;

/**
 Defines whether or not the aucomplete as read only.
 */
@property (nonatomic) BOOL readOnly;

/**
 Defines whether or not all items to be showed initially.
 */
@property (nonatomic) BOOL showAllItemsInitially;

/**
 Defines the inset of the tokens.
 */
@property (nonatomic) CGFloat tokenInset;

/**
 Defines he inset of the autocomplete.
 */
@property (nonatomic) CGFloat autocompleteInset;

/**
 Defines the insets of the autocomplete.
 */
@property (nonatomic) UIEdgeInsets insets;

/**
 Returns the current height of the token area of the autocomplete.
 */
@property (nonatomic, readonly) CGFloat currentWrapHeight;

/**
 Defines the height of the suggestion view.
 */
@property (nonatomic) CGFloat suggestionViewHeight;

/**
 Sets the maximum height of the autocomplete in TKAutoCompleteLayoutModeWrap.
 */
@property (nonatomic) CGFloat maximumWrapHeight;

/**
 Sets the minimum count of typed characters by which to be performd the suggestioning. The default value is 0.
 */
@property (nonatomic) NSUInteger minimumCharactersToSearch;

/**
 Sets the maximum tokens count.
 */
@property (nonatomic) NSUInteger maximumTokensCount;

/**
 Adds token.
 @param token The TKAutoCompleteToken object model.
 */
- (void)addToken:(TKAutoCompleteToken* __nonnull)token;

/**
 Inserts token at specific index.
 @param token The TKAutoCompleteToken object model.
 @param index The insertion index.
 */
- (void)insertToken:(TKAutoCompleteToken* __nonnull)token atIndex:(NSInteger)index;

/**
 Removes token.
 @param token The TKAutoCompleteToken object model.
 */
- (void)removeToken:(TKAutoCompleteToken* __nonnull)token;

/**
 Removes token at specific index.
 @param index Token index.
 */
- (void)removeTokenAtIndex:(NSInteger)index;

/**
 Removes all tokens.
 */
- (void)removeAllTokens;

/**
 Return collecion of all tokens.
 */
- (NSArray* __nonnull)tokens;

/**
 Returns specific token.
 @param index The token index.
 */
- (TKAutoCompleteToken* __nonnull)tokenAtIndex:(NSInteger)index;

/**
 Returns specific token view.
 @param index The token index.
 */
- (TKAutoCompleteTokenView* __nonnull)tokenViewAtIndex:(NSInteger)index;

/**
 Updates the visibility of the close button.
 */
-(void) updateCloseButtonVisibility;

/**
 Resets the autocomplete.
 */
-(void) resetAutocomplete;

/**
 Resets the autocomplete to initial state & removes all added tokens.
 */
-(void) resetAutocompleteState;

/**
 Completes the async population of the suggestion view. Used only with the dataSource autoComplete:autocomplete completionsForString:input method.
 @param suggestions The suggestions which are going to be presented.
 */
-(void) completeSuggestionViewPopulation:(NSArray* __nullable) suggestions;

/**
 * Forces TKAutoCompleteTextView's filtering logic and displays suggestions if necessary.
 */
- (void)findSuggestions;

/**
 Selects the suggestion at the specified index.
 */
-(void)selectSuggestionAtIndexPath:(NSIndexPath*__nonnull)indexPath;

@end

/**
 The TKAutoCompleteDataSource protocol allow you to provide custom suggestion filtering algorithm.
 */
@protocol TKAutoCompleteDataSource <NSObject>

@optional

/**
 Allows you to perform custom filtering over the suggestion list and  to define criteria on which completing suggestions to be shown.
 @param autocomplete The current TKAutoCompleteTextView object.
 @param prefix The typed text
 @return Array of the chosen completion suggestions
 */
-(NSArray<__kindof TKAutoCompleteToken*>*__nonnull)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete completionForPrefix:(NSString*__nullable)prefix;

/**
 Allows you to perform custom filtering over the suggestion list and  to define criteria on which completing suggestions to be shown.
 @param autocomplete The current TKAutoCompleteTextView object.
 @param input The typed text
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete completionsForString:(NSString *__nonnull)input;

@end


/**
 The TKAutoCompleteDelegate protocol defines methods that allow you to manage the components of the autocomplete  and the interaction with them.
 */
@protocol TKAutoCompleteDelegate <NSObject>

@optional

/**
 Provides a TKAutoCompleteTokenView to display the current object model TKAutoCompleteToken.
 @param autocomplete The current TKAutoCompleteTextView object.
 @param token The TKAutoCompleteToken object model.
 */
-(TKAutoCompleteTokenView * __nonnull)autoComplete:(TKAutoCompleteTextView* __nonnull)autocomplete viewForToken:(TKAutoCompleteToken * __nonnull)token;

/**
 The method is called after a suggestion has been chosen to complete the text input.
 @param autocomplete The object where the event occurred.
 @param completion The chosen completion.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didAutoComplete:(TKAutoCompleteToken *__nonnull)token;

/**
 The method is called before the suggestion list is shown. Provides access to the possible completions.
 @param autocomplete The object where the event occurred.
 @param suggestionList The list of possible completions.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete willShowSuggestionList:(NSArray<__kindof TKAutoCompleteToken*> *__nonnull)suggestionList;

/**
 The method is called when the suggestions are updated. Provides access to the possible completions.
 @param autocomplete The object where the event occurred.
 @param suggestionList The list of possible completions.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete suggestionListUpdated:(NSArray<__kindof TKAutoCompleteToken*> *__nonnull)suggestionList;

/**
 Returns a boolean value indicating whether the specified item should be selected.
 @param autocomplete The object where the event occurred.
 @param token The TKAutoCompleteToken object model.
 @return YES if the item should be selected.
 */
-(BOOL)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete shouldAddToken:(TKAutoCompleteToken *__nonnull)token;

/**
 The method is called after a suggestion has been chosen to complete the text input.
 @param autocomplete The object where the event occurred.
 @param token The added token.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didAddToken:(TKAutoCompleteToken *__nonnull)token atIndex:(NSUInteger) index;

/**
 Returns a boolean value indicating whether the specified item should be deleted.
 @param autocomplete The object where the event occurred.
 @param token The TKAutoCompleteToken object model.
 @return YES if the item should be deleted.
 */
-(BOOL)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete shouldRemoveToken:(TKAutoCompleteToken *__nonnull)token;

/**
 The method is called after a token has been deleted.
 @param autocomplete The object where the event occurred.
 @param token The TKAutoCompleteToken object model of the deleted token.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didRemoveToken:(TKAutoCompleteToken *__nonnull)token;

/**
 The method is called after the subviews of TKAutoCompleteTextView have been laid out.
 @param autocomplete The object where the event occurred.
 */
-(void)autoCompleteDidLayoutSubviews:(TKAutoCompleteTextView*__nonnull)autocomplete;

/**
 The method is called after the subviews of TKAutoCompleteTextView have been laid out.
 @param autocomplete The object where the event occurred.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didLayoutTokenView:(TKAutoCompleteTokenView *__nonnull)tokenView;

/**
 The method is called when a TKAutoCompleteTokenView has been selected.
 @param autocomplete The object where the event occurred.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didSelectTokenView:(TKAutoCompleteTokenView *__nonnull)tokenView;

/**
 The method is called when a TKAutoCompleteTokenView has been deselected.
 @param autocomplete The object where the event occurred.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didDeselectTokenView:(TKAutoCompleteTokenView *__nonnull)tokenView;

/**
 The method is called after a token has become a first responder.
 @param autocomplete The object where the event occurred.
 @param token The TKAutoCompleteToken object model of the selected token.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didSelectToken:(TKAutoCompleteToken *__nonnull)token;

/**
 The method is called after a token stops being selected.
 @param autocomplete The object where the event occurred.
 @param token The TKAutoCompleteToken object model of the deselected token.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didDeselectToken:(TKAutoCompleteToken *__nonnull)token;

/**
 The method is called after the text changes.
 @param autocomplete The object where the event occurred.
 @param text The new text of the autocomplete.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didChangeText:(NSString *__nonnull)text;

/**
 The method is called TKAutoCompleteTextView gets or loses focus.
 @param autocomplete The object where the event occurred.
 @param hasFocus Whether TKAutoCompleteTextView has focus.
 */
-(void)autoComplete:(TKAutoCompleteTextView*__nonnull)autocomplete didChangeFocus:(BOOL)hasFocus;

/**
 The method is called when the TKAutoCompleteTextView becomes first responder.
 @param autocomplete The current TKAutoCompleteTextView object.
 */
-(void)autoCompleteDidStartEditing:(TKAutoCompleteTextView*__nonnull)autocomplete;

/**
 The method is called when the TKAutoCompleteTextView updates the layout of its suggestion view.
 @param autocomplete The current TKAutoCompleteTextView object.
 */
-(void)autoCompleteDidLayoutSuggestionView:(TKAutoCompleteTextView*__nonnull)autocomplete;

@end


/**
 The TKAutoCompleteSuggestViewDelegate protocol allow you to define the behavior of a view which is intended to work as a suggestView for the autocomplete.
 */
@protocol TKAutoCompleteSuggestViewDelegate <NSObject>

/**
 Defines how the view will be populated with items.
 @param items The items that will be presented.
 */
-(void)populateWithItems:(NSArray<__kindof TKAutoCompleteToken*>*__nonnull)items;

/**
 Reload the suggestion items.
 */
-(void)reloadSuggestions;

/**
 Called when a suggestion item is selected.
 */
-(TKAutoCompleteToken*__nullable)selectedItem;

/**
 Defines if the suggestion view should be allways hidden.
 */
-(BOOL)shouldAlwaysHideSuggestionView;

/**
 Defines how the view will hide itself.
 */
-(void)hide;

/**
 Defines how the view will show itself.
 */
-(void)show;

/**
 Selects the suggestion at the specified index.
 */
-(void)selectSuggestionAtIndexPath:(NSIndexPath*__nonnull)indexPath;

@end


