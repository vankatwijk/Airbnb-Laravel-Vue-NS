//
//  TNSDataForm.h
//  TNSDataForm
//
//  Created by Vladimir Amiorkov on 11/3/17.
//  Copyright © 2017 NativeScript. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for TNSDataForm.
FOUNDATION_EXPORT double TNSDataFormVersionNumber;

//! Project version string for TNSDataForm.
FOUNDATION_EXPORT const unsigned char TNSDataFormVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TNSDataForm/PublicHeader.h>

#import <TNSDataForm/TKDataForm.h>
#import <TNSDataForm/TKDataFormViewController.h>
#import <TNSDataForm/TKDataFormOptionsViewController.h>
#import <TNSDataForm/TKDataFormEntityDataSource.h>
#import <TNSDataForm/TKDataFormGroupInfo.h>
#import <TNSDataForm/TKDataFormConverter.h>

#import <TNSDataForm/TKAutoCompleteDataSourceGroupDescriptor.h>
#import <TNSDataForm/TKAutoCompleteDataSourceSortDescriptor.h>
#import <TNSDataForm/TKAutoCompleteDataSourceFilterDescriptor.h>
#import <TNSDataForm/TKAutoCompleteDataSourceAutoCompleteSettings.h>
#import <TNSDataForm/TKAutoCompleteDataSourceSettings.h>
#import <TNSDataForm/TKAutoCompleteDataSourceCollectionViewSettings.h>
#import <TNSDataForm/TKAutoCompleteDataSourceTableViewSettings.h>
#import <TNSDataForm/TKDataSourceExtended.h>
#import <TNSDataForm/TKCollectionViewCell.h>
#import <TNSDataForm/TKAutoCompleteDataSourceGroup.h>

#import <TNSDataForm/TKDataFormAutocompleteController.h>
#import <TNSDataForm/TKDataFormAutoCompleteInlineEditor.h>
#import <TNSDataForm/TKDataFormAutocompleteEditor.h>
#import <TNSDataForm/TKDataFormEditor.h>
#import <TNSDataForm/TKDataFormTextFieldEditor.h>
#import <TNSDataForm/TKDataFormMultilineTextEditor.h>
#import <TNSDataForm/TKDataFormEmailEditor.h>
#import <TNSDataForm/TKDataFormPasswordEditor.h>
#import <TNSDataForm/TKDataFormNamePhoneEditor.h>
#import <TNSDataForm/TKDataFormPhoneEditor.h>
#import <TNSDataForm/TKDataFormDecimalEditor.h>
#import <TNSDataForm/TKDataFormNumberEditor.h>
#import <TNSDataForm/TKDataFormSwitchEditor.h>
#import <TNSDataForm/TKDataFormStepperEditor.h>
#import <TNSDataForm/TKDataFormSliderEditor.h>
#import <TNSDataForm/TKDataFormSegmentedEditor.h>
#import <TNSDataForm/TKDataFormInlineEditor.h>
#import <TNSDataForm/TKDataFormDatePickerEditor.h>
#import <TNSDataForm/TKDataFormTimePickerEditor.h>
#import <TNSDataForm/TKDataFormOptionsEditor.h>
#import <TNSDataForm/TKDataFormPickerViewEditor.h>
#import <TNSDataForm/TKDataFormCustomEditor.h>
#import <TNSDataForm/TKTextField.h>
#import <TNSDataForm/TKDataFormAccessoryView.h>
#import <TNSDataForm/TKLabel.h>
#import <TNSDataForm/TKImageView.h>
#import <TNSDataForm/TKDataFormViewControllerEditor.h>
#import <TNSDataForm/TKDataFormLabelEditor.h>
#import <TNSDataForm/TKDataFormEditorView.h>

#import <TNSDataForm/TKDataFormEditorStyle.h>
#import <TNSDataForm/TKDataFormGroupTitleStyle.h>

#import <TNSDataForm/TKDataFormValidator.h>
#import <TNSDataForm/TKDataFormPropertyValidator.h>
#import <TNSDataForm/TKDataFormEmailValidator.h>
#import <TNSDataForm/TKDataFormNonEmptyValidator.h>
#import <TNSDataForm/TKDataFormMinimumLengthValidator.h>
#import <TNSDataForm/TKDataFormMaximumLengthValidator.h>
#import <TNSDataForm/TKDataFormRangeValidator.h>
#import <TNSDataForm/TKDataFormPhoneValidator.h>
#import <TNSDataForm/TKDataFormManualValidator.h>
#import <TNSDataForm/TKDataFormRegExValidator.h>
#import <TNSDataForm/TKDataFormIsTrueValidator.h>

#import <TNSDataForm/TKEntityPropertyGroupView.h>
#import <TNSDataForm/TKEntityPropertyGroupEditorsView.h>
#import <TNSDataForm/TKEntityPropertyGroupTitleView.h>
#import <TNSDataForm/TKEntityPropertyGroupTitleViewIndicator.h>

#import <TNSDataForm/TKDataFormStringToDateTimeConverter.h>
#import <TNSDataForm/TKDataFormStringToDateConverter.h>
#import <TNSDataForm/TKDataFormStringToTimeConverter.h>

#import <TNSDataForm/TKEntityPropertyGroup.h>
#import <TNSDataForm/TKEntity.h>
#import <TNSDataForm/TKEntityProperty.h>
