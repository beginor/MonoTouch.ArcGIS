/*
 COPYRIGHT 2012 ESRI
 
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

/** @file AGSColor.h */ //Required for Globals API doc


#if TARGET_OS_IPHONE
/** AGSColor is defined as UIColor on iOS platform. 
 @since 10.1.1
 */
#define AGSColor UIColor
#elif TARGET_OS_MAC && !TARGET_OS_IPHONE
#define AGSColor NSColor
#endif