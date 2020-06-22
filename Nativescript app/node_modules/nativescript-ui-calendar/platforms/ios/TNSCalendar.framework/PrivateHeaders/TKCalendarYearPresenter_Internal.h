//
//  TKCalendarYearPresenter_Internal.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarYearPresenter.h"

@interface TKCalendarYearPresenter ()

@property (nonatomic, strong) UICollectionView *collection;

- (NSString*)monthName:(NSInteger)monthIndex;

- (NSString*)dayName:(NSInteger)weekDayIndex;

@end
