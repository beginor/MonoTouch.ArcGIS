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

/** @file AGSImage.h */ //Required for Globals API doc

#if TARGET_OS_IPHONE
/** AGSImage is defined as a UIImage for iOS platform.
 @since 10.1.1
 */
#define AGSImage UIImage

/** AGSImagePNGRepresentation(x) is defined as a UIImagePNGRepresentation(x) for iOS platform.
 @since 10.1.1
 */
#define AGSImagePNGRepresentation(x) UIImagePNGRepresentation(x)

/** AGSImageJPEGRepresentation(x,y) is defined as a UIImageJPEGRepresentation(x,y) for iOS platform.
 @since 10.1.1
 */
#define AGSImageJPEGRepresentation(x, y) UIImageJPEGRepresentation(x, y)
#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)
/** AGSImage is defined as a NSImage for MacOS platforms.
 @since 10.1.1
 */
#define AGSImage NSImage
#define AGSImagePNGRepresentation(x) NSImagePNGRepresentation(x)
#define AGSImageJPEGRepresentation(x, y) NSImageJPEGRepresentation(x, y)

/** @brief A category on @c NSImage providing convenience methods.
 
  A category on @c NSImage providing convenience methods.
 
 @since 10.1.1
 */
@interface NSImage (AGSImage)

/** Returns an image using the provided data
 @param data
 @since 10.1.1
 */
+(NSImage*)imageWithData:(NSData*)data;

/** Returns an image using the provided file
 @param path
 @since 10.1.1
 */
+(NSImage*)imageWithContentsOfFile:(NSString*)path;

@end

/** Returns the data for a given image object
 @since 10.1.1
 */
AGS_EXTERN NSData* NSImagePNGRepresentation(NSImage *image);

/** Returns the data for a given image object and compression threshold
 @since 10.1.1
 */
AGS_EXTERN NSData* NSImageJPEGRepresentation(NSImage *image, float compression);

#endif