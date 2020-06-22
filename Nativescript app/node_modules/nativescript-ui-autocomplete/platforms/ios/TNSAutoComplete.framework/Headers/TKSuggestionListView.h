//
//  TKSuggestionListView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKAutoCompleteTextView.h"

/**
 The default suggestions view used by the autocomplete.
 */
@interface TKSuggestionListView : UICollectionView<TKAutoCompleteSuggestViewDelegate, UICollectionViewDataSource, UICollectionViewDelegate>

/**
 The progress bar indicating that operation is being performed and will take a while.
 */
@property (strong, nonatomic, readonly, nonnull) UIProgressView *progressBar;

/**
 The TKAutoCompleteTextView objec owning the instance.
 */
@property (weak, nonatomic, nullable) TKAutoCompleteTextView *owner;

/**
 The selected item.
 */
@property (weak, nonatomic, nullable) TKAutoCompleteToken *selectedItem;

/**
 The selected index path.
 */
@property (weak, nonatomic, nullable) NSIndexPath *selectedIndexPath;

/**
 The data collection which populates the view.
 */
@property (strong, nonatomic, nonnull) NSArray<__kindof TKAutoCompleteToken*> *items;

/**
 The height of the items in the TKSuggestionListView.
 */
@property (nonatomic) CGFloat cellHeight;

/**
 Initializes the TKSuggestionListView with an corresponding TKAutoCompleteTextView object.
 @param autocomplete The TKAutoCompleteTextView objec owning the instance.
 */
- (instancetype __nonnull)initWithAutoComplete:(TKAutoCompleteTextView* __nonnull)autocomplete;

@end

