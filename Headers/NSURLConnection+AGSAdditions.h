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

#import <Foundation/Foundation.h>

/** @brief A category to assist with network connections
 
 A category to assist with network connections
 @since 2.1
 */
@interface NSURLConnection (AGSAdditions)

/** A list of strings representing hosts that can be trusted even if they are using
 self-signed certificates.
 @since 2.1
 */
+(NSMutableArray*)trustedHosts;

@end
