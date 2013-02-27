/*
 COPYRIGHT 2010 ESRI
 
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

#import <UIKit/UIKit.h>

/** @file UIDevice+AGSAdditions.h */ //Required for Globals API doc

/*
 The return values will be as follows:
 iPhone Simulator == i386
 iPhone == iPhone1,1
 3G iPhone == iPhone1,2
 3GS iPhone == iPhone2,1
 iPhone 4 == iPhone3,1
 1st Gen iPod == iPod1,1
 2nd Gen iPod == iPod2,1
 3rd Gen iPod == iPod3,1
 4th Gen iPod == iPod4,1
 1st Gen iPad == iPad1,1
 2nd Gen iPad == iPad2,1
 */

/** List of supported devices.
 @since 1.0
 */
typedef enum {
	UIDeviceMachineTypeUnknown = 0,			/*!< */
	UIDeviceMachineTypeiPhoneSimulator,		/*!< */
	UIDeviceMachineTypeiPhone,				/*!< */
	UIDeviceMachineTypeiPhone3G,			/*!< */
	UIDeviceMachineTypeiPhone3GS,			/*!< */
	UIDeviceMachineTypeiPhone4,				/*!< */
	UIDeviceMachineTypeiPod1stGen,			/*!< */
	UIDeviceMachineTypeiPod2ndGen,			/*!< */
	UIDeviceMachineTypeiPod3rdGen,			/*!< */
	UIDeviceMachineTypeiPod4thGen,			/*!< */
	UIDeviceMachineTypeiPad1stGen,			/*!< */
	UIDeviceMachineTypeiPad2ndGen,			/*!< */
    UIDeviceMachineTypeiPhone4S,			/*!< */
	UIDeviceMachineTypeiPad3rdGen,			/*!< */
} UIDeviceMachineType;

/** @brief A category to assist with device specific properties.
 
 Category to assist with determining the device we are running on.
 @since 1.0
 */
@interface UIDevice(AGSAdditions)

/** Method to return a string corresponding to a device .
 @since 1.0
 */
-(NSString *)machine;

/** Method to return the type of device that is currently running.
 @since 1.0
 */
-(UIDeviceMachineType)machineType;

/** Method to return the points per inch that should be used for a given device.
 @since 1.0
 */
-(int)ppi;

/** Method to return whether or not the device is an iPad.
 @since 1.8
 */
-(BOOL)isIPad;

/** Returns whether or not the iOS version is at least 4.0.
 @since 1.8
 */
-(BOOL)isAtLeastiOS4;

/** Returns whether or not the iOS version is at least 5.0.
 @since 2.2
 */
-(BOOL)isAtLeastiOS5;

@end




