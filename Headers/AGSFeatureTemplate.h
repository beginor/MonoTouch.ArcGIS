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

/** @file AGSFeatureTemplate.h */ //Required for Globals API doc

/** @brief Represents all of the information needed to create a feature.
 
 Instances of this class represent a feature template. A feature template
 defines all the information required to create a feature: the layer where a
 feature will be stored and the attributes a feature is created with.
 
 @since 1.0
 */
@interface AGSFeatureTemplate : NSObject <AGSCoding>

/** Name of the template.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Description of the template.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *featureDescription;

/** A prototypical feature associated with the template which can be used to 
 easily create new features. The prototype specifies default values for the 
 feature's attributes, however, it does not contain a geometry.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSGraphic *prototype;

@end