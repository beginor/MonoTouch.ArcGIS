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

#import <Foundation/Foundation.h>

@class AGSRequestOperation;

/** @brief Represents an object to invoke a JSON based REST webservice.
 
 Instances of this object represent an operation that can be used to invoke a JSON based REST webservice. You can use it with your own custom or third party webservices. You can also use it for ArcGIS  REST webservices, such as ArcGIS Server services, ArcGIS Server server object extensions, and ArcGIS Online.
 
 @since 1.0
 @see @concept{Working_with_JSON/00pw0000004w000000/, Working with JSON}
 @see @sample{5310bd25559d41418b9225f424329ead, Weather Information}
 */
@interface AGSJSONRequestOperation : AGSRequestOperation {
}

@end
