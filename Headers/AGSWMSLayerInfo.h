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

@class AGSEnvelope;


/** @file AGSWMSLayerInfo.h */ //Required for Globals API doc

#pragma mark -

/** @brief A class to represent the basic properties of a layer within a WMS map service.
 
 
 Instances of this class represent information about a layer in a WMS map service.
 
 @define{AGSWMSLayerInfo.h,ArcGIS}
 @since 2.2
 */

@interface AGSWMSLayerInfo : NSObject

/** The name of this layer.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The title of this layer.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *title;

/** The extent of this layer.
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSEnvelope *extent;

/** The sublayers of this layer, represented as an array of @c AGSWMSLayerInfo objects.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *subLayers;


@end
