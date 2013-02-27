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

/** @file AGSDevice.h */ //Required for Globals API doc

/*
 The return values will be as follows:
 iPhone Simulator   == i386
 iPhone             == iPhone1,1
 3G iPhone          == iPhone1,2
 3GS iPhone         == iPhone2,1
 iPhone 4           == iPhone3,1 or iPhone3,3
 iPhone 4s          == iPhone4,1
 iPhone 5           == iPhone5,1 or iPhone5,2
 1st Gen iPod       == iPod1,1
 2nd Gen iPod       == iPod2,1
 3rd Gen iPod       == iPod3,1
 4th Gen iPod       == iPod4,1
 5th Gen iPod       == iPod5,1
 1st Gen iPad       == iPad1,1
 2nd Gen iPad       == iPad2,1 iPad2,2 iPad2,3 iPad2,4
 3rd Gen iPad       == iPad3,1 iPad3,2 iPad3,3
 4th Gen iPad       == iPad3,4 iPad3,5 iPad3,6
 iPad Mini          == iPad2,5 iPad2,6 iPad2,7
 */

/** List of supported devices.
 @since 10.1.1
 */
typedef enum {
	AGSDeviceMachineTypeUnknown = 0,		/*!< */
	AGSDeviceMachineTypeiPhoneSimulator,	/*!< */
	AGSDeviceMachineTypeiPhone,				/*!< */
	AGSDeviceMachineTypeiPhone3G,			/*!< */
	AGSDeviceMachineTypeiPhone3GS,			/*!< */
	AGSDeviceMachineTypeiPhone4,			/*!< */
	AGSDeviceMachineTypeiPhone5,			/*!< */
	AGSDeviceMachineTypeiPod1stGen,			/*!< */
	AGSDeviceMachineTypeiPod2ndGen,			/*!< */
	AGSDeviceMachineTypeiPod3rdGen,			/*!< */
	AGSDeviceMachineTypeiPod4thGen,			/*!< */
    AGSDeviceMachineTypeiPod5thGen,			/*!< */
	AGSDeviceMachineTypeiPad1stGen,			/*!< */
	AGSDeviceMachineTypeiPad2ndGen,			/*!< */
    AGSDeviceMachineTypeiPhone4S,			/*!< */
	AGSDeviceMachineTypeiPad3rdGen,			/*!< */
    AGSDeviceMachineTypeiPad4thGen,			/*!< */
    AGSDeviceMachineTypeiPadMini,			/*!< */
    AGSDeviceMachineTypeMac,                /*!< */
} AGSDeviceMachineType;


/** @brief An object to assist with device specific properties.
 
 Object to assist with determining the device we are running on.
 @since 10.1.1
 */
@interface AGSDevice : NSObject

/** The current device.
 @since 10.1.1
 */
+ (AGSDevice*)currentDevice;

/** A string representing the system version.
 @since 10.1.1
 */
- (NSString*)systemVersion;

/** Method to return a string corresponding to a device .
 @since 10.1.1
 */
-(NSString *)machine;

/** Method to return the type of device that is currently running.
 @since 10.1.1
 */
-(AGSDeviceMachineType)machineType;

/** Method to return whether or not the device is an iPad.
 @since 10.1.1
 */
-(BOOL)isIPad;

/** Returns whether or not the iOS version is at least 4.0.
 @since 10.1.1
 */
-(BOOL)isAtLeastiOS4;

/** Returns whether or not the iOS version is at least 5.0.
 @since 10.1.1
 */
-(BOOL)isAtLeastiOS5;

/** Returns whether or not the iOS version is at least 6.0.
 @since 10.1.1
 */
-(BOOL)isAtLeastiOS6;

/** Returns whether or not the device is a Mac.
 @since 10.1.1
 */
- (BOOL)isMac;

/** Method to return the points per inch that should be used for a given device.
 @since 10.1.1
 */
-(int)ppi;


@end




