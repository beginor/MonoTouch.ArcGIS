/*
 COPYRIGHT 2009 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */


/*
 
 This header is for public defines only

 */


#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#define AGS_EXTERN UIKIT_EXTERN
#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)
#import <AppKit/AppKit.h>
#define AGS_EXTERN APPKIT_EXTERN
#endif


#ifndef __has_feature
#define __has_feature(x) 0  // compatibility with non-clang compilers
#endif

#ifndef NS_CONSUMES_SELF
#if __has_feature(attribute_ns_consumes_self)
#define NS_CONSUMES_SELF __attribute__((ns_consumes_self))
#else
#define NS_CONSUMES_SELF
#endif
#endif

#ifndef NS_RETURNS_RETAINED
#if __has_feature(attribute_ns_returns_retained)
#define NS_RETURNS_RETAINED __attribute__((ns_returns_retained))
#else
#define NS_RETURNS_RETAINED
#endif
#endif
