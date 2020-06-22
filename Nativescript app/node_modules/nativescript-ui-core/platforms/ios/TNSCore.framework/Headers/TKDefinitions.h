//
//  TKDefinitions.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#ifdef DEBUG
#    define TKDLog(__FORMAT__, ...) NSLog((@"%s [Line %d] " __FORMAT__), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#    define TKDLog(...)
#endif
#define TKLog(...) NSLog(__VA_ARGS__)

#define TKRGB(r, g, b) ([UIColor colorWithRed:(r)/255.f green:(g)/255.f blue:(b)/255.f alpha:1.f])
#define TKRGBA(r, g, b, a) ([UIColor colorWithRed:(r)/255.f green:(g)/255.f blue:(b)/255.f alpha:(a)])
#define TKRectMake(x, y, width, height) (CGRectMake(roundf(x), roundf(y), roundf(width), roundf(height)))
#define TKRadianMakeFromDegrees(angle) ((angle * M_PI) / 180.f)
#define TKDegreeMakeFromRadians(radians) ((radians) * (180.0 / M_PI))
#define TKInfinityCGPoint CGPointMake(INFINITY, INFINITY)

#ifdef DEBUG
#    define TKAssert(__CONDITION__, __FORMAT__, ...) {if (!(__CONDITION__)) { NSLog((@"%s [Line %d]\n"__FORMAT__), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}}
#else
#    define TKAssert(__CONDITION__,__FORMAT__, ...)
#endif
