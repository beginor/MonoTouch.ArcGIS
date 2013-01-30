/*
 COPYRIGHT 2011 ESRI
 
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

/** @file NSURL+AGSAdditions.h */ //Required for Globals API doc

/** @brief A category on @c NSURL containing convenience methods
 
 Simple addition to NSURL so that you can initialize an url with a string that contains spaces
 or unicode characters.
 
 @since 2.3
 */
@interface NSURL (AGSAdditions)

/** A method to initialize a url with a string that contains spaces
 or unicode characters.
 @param urlString containing spaces or unicode chars.
 @since 2.3
 */
+(NSURL*)ags_URLWithUnicodeString:(NSString*)urlString;
@end
