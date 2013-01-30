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




@class AGSFeatureSet;
@class AGSPoint;
@protocol AGSCoding;

/** @brief An object representing the result of an Image Service Identify Task.
 
 The results from an @c AGSImageServiceIdentifyTask. It has no constructor.
 @define{AGSImageServiceIdentifyResult.h, ArcGIS}
 @since 1.8
 */
@interface AGSImageServiceIdentifyResult : NSObject <AGSCoding>

/** The set of catalog items that overlap the input geometry. CatalogItems are
 returned only when the image service source is a mosaic dataset.
 @since 1.8
 */
@property (nonatomic, strong, readonly) AGSFeatureSet *catalogItems;

/** The set of visible areas for the identified catalog items. CatalogItemVisibilities
 are returned only when the image service source is a mosaic dataset.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *catalogItemVisibilities;

/** The identified location.
 @since 1.8
 */
@property (nonatomic, strong, readonly) AGSPoint *location;

/** The identify property name.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The identify property id.
 @since 1.8
 */
@property (nonatomic, strong, readonly) NSNumber *objectId;

/** The attributes of the identified object.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSDictionary *properties;

/** The identify property pixel value.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *value;

@end
