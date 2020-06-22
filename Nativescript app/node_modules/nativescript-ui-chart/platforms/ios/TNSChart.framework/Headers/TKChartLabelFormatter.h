//
//  TKChartLabelFormatter.h
//  TNSChart
//
//  Copyright © 2019 NativeScript. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TKChartLabelFormatter : NSObject

+ (NSString*)formatValue:(id)value withStringFormat:(NSString*)format;

@end
