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

@class AGSGeometry;
@class AGSSpatialReference;

/** @file AGSFeatureSet.h */ //Required for Globals API doc

#pragma mark -

/** @brief A set of features.
 
 Instances of this class respresent a feature set. A feature set is simply a 
 collection of features. Each feature is represented as an @c AGSGraphic object. 
 They may contain geometry, attributes, and symbology. If the features contain 
 only attributes but no geometry, the feature set can be considered a simple table 
 where each feature is a row object. 
 
 A feature set can be the result of a task or used as an input to a task. Tasks 
 that return a feature set include @c AGSQueryTask and @c AGSGeoprocessor. In 
 addition, @c AGSGeoprocessor may require a feature set as input.
 
 @define{AGSFeatureSet.h, ArcGIS}
 @since 1.0
 */
@interface AGSFeatureSet : NSObject <AGSCoding>

/** The name of the primary display field. 
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *displayFieldName;

/** The features in the feature set as an array of @c AGSGraphic objects.
 @since 1.0
 */
@property (nonatomic, copy) NSArray *features; //AGSGraphic[]

/** Set of key-value pairs of field-name and field-alias. Field aliases are 
 usually more user friendly than actual field names which may use underlying 
 datasource naming conventions. The feature attributes use actual field names.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSDictionary *fieldAliases;

/** The spatial reference of features in the feature set. All features in the 
 feature set must have the same spatial reference.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The geometry type of features in the feature set. All features in the feature 
 set must have the same geometry type. Possible types include
 
 @li @c AGSGeometryTypePoint
 @li @c AGSGeometryTypePolyline
 @li @c AGSGeometryTypePolygon
 @li @c AGSGeometryTypeMultipoint
 @li @c AGSGeometryTypeEnvelope
 
 @since 1.0
 */
@property (nonatomic, assign, readonly) AGSGeometryType geometryType;

/** An array of @c AGSField objects containing metadata about attributes of each feature in the
 featureset.
 @since 2.3
 @avail{10.1}
 */
@property (nonatomic, copy, readonly) NSArray *fields;

/** Initializes a new <code>%AGSFeatureSet</code>.
 @param displayFieldName The name of the primary display field.
 @param features The features to be used to initialize the set.
 @param fieldAliases The user-friendly values associated with field names.
 @param spatialReference The spatial reference for each object in the feature set.
 @param geometryType The type of geometry for the features in the set.
 @return An initialized <code>%AGSFeatureSet</code> with the given parameters.
 @since 1.0
 */
-(id)initWithDisplayFieldName:(NSString*)displayFieldName
					 features:(NSArray*)features
				 fieldAliases:(NSDictionary*)fieldAliases
			 spatialReference:(AGSSpatialReference*)spatialReference
				 geometryType:(AGSGeometryType)geometryType;

/** Initializes a new <code>AGSFeatureSet</code>. All features must contain
 a single type of geometry, all having the same spatial reference.
 @param features The features to be used to initialize the set.
 @return An initialized <code>AGSFeatureSet</code> with the specified features.
 @since 1.8
 */
- (id)initWithFeatures:(NSArray*)features;

/** Initializes a new, autoreleased <code>AGSFeatureSet</code>. All features 
 must contain a single type of geometry, all having the same spatial reference.
 @param features The features to be used to initialize the set.
 @return An initialized <code>AGSFeatureSet</code> with the specified features.
 @since 1.8
 */
+ (id)featureSetWithFeatures:(NSArray*)features;

@end
