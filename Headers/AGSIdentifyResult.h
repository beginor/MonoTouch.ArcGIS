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

@class AGSGraphic;

/** @file AGSIdentifyResult.h */ //Required for Globals API doc


/** @brief A result of @c %AGSIdentifyTask operation.
 
 Instances of this class represent results of an @c AGSIdentifyTask operation. 
 
 @define{AGSIdentifyTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSIdentifyResult : NSObject <AGSCoding>

/** Name of the layer's primary display field. 
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *displayFieldName;

/** The identified feature.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSGraphic *feature;

/** ID of the layer that contains the identified feature.
 @since 1.0
 */
@property (nonatomic, readonly) NSUInteger layerId;

/** Name of the layer that contains the identified feature
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *layerName;

@end
