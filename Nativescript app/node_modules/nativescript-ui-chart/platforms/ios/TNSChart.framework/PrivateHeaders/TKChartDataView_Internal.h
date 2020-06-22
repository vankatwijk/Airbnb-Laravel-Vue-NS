//
//  TKChartDataView+Calculator.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartDataView.h"

@interface TKChartDataView ()

- (id)getMaxForKey:(NSString*)key;
- (id)getMinForKey:(NSString*)key;
- (id)getAvgForKey:(NSString*)key;

- (NSInteger)getIndexForKey:(NSString*)key andValue:(id)value;



@end
