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



/** @file AGSNALayerDefinition.h */

@protocol AGSCoding;
@class AGSGeometry;
@class AGSQuery;
@class AGSSpatialReference;

/** @brief Possible input object for stops/facilities/incidents/barriers 
 
 Instances of this class represent possible inputs such as <code>stops/facilities/incidents/barriers</code> 
 for @c AGSRouteTaskParameters, @c AGSServiceAreaTaskParameters, 
 and @c AGSClosestFacilityTaskParameters. 
 
 A layer definition allows you to specify these inputs by-reference. This is useful when you already have them stored in a data layer of a service.  In such cases, the application does not need to know the actual details about each input.  All it needs to do is set up a layer definition specifiying which inputs should be included in the analysis.

 The data layer can be part of the network analysis service itself, or it can belong to another service on any server. The network analysis service will automatically fetch input from the data layer at run-time when the analysis is being performed. You can restrict which inputs are used by specificy SQL queries or Spatial relationships.
 
 @since 1.8
 */
@interface AGSNALayerDefinition : NSObject <AGSCoding>

/** The geometry used to select features. The #spatialRelationship is applied to this geometry by the network analysis service while selecting which features to use as inputs during the analysis. 
 @see #initWithLayerName:geometry:spatialRelationship:where:
 @since 1.8
 */
@property (nonatomic, strong) AGSGeometry *geometry;

/** The name of the data layer in the network analysis service itself. The service retrieves features from this data layer at run-time to use as stops/barriers/facilities/incidents when the analysis is being performed.
 @since 1.8
 */
@property (nonatomic, copy) NSString *layerName;

/** The spatial relationship to be applied on the input geometry while performing 
 the query. See the Constants Table for a list of valid values. The default spatial
 relationship is <code>AGSSpatialRelationshipIntersects</code>.
 @since 1.8
 @see #initWithLayerName:geometry:spatialRelationship:where:
 */
@property (nonatomic, assign) AGSSpatialRelationship spatialRelationship;

/** A where clause for the query. Any legal SQL where clause operating on the 
 fields in the layer is allowed, for example: = "POP2000 > 350000".
 @since 1.8
 @see #initWithLayerName:where:
 */
@property (nonatomic, copy) NSString *where;

/** The URL of a data layer in any map or feature service. The network analysis service retrieves features from this data layer at run-time to use as stops/barriers/facilities/incidents when the analysis is being performed.
 @avail{10.1}
 @since 2.3
 @see #initWithURL:query:
 */
@property (nonatomic, copy, readonly) NSURL *URL;

/** Query to restrict which features from the data layer should be retrieved.
 @avail{10.1}
 @since 2.3
 @see #initWithURL:query:
 */
@property (nonatomic, strong, readonly) AGSQuery *query;

/** Initialize a new @c AGSNALayerDefinition
 @param layerName The name of the data layer in the network analyst service to reference.
 @param geometry The geometry used to select which features should be used as inputs
 @param spatialRelationship The spatial relationship to apply to the #geometry for selecting features.
 @param where The where clause for the query to further restrict which features from the data layer should be used as inputs
 @return An initialized @c AGSNALayerDefinition object.
 @since 1.8
 */
- (id)initWithLayerName:(NSString*)layerName 
			   geometry:(AGSGeometry*)geometry 
	spatialRelationship:(AGSSpatialRelationship)spatialRelationship 
				  where:(NSString*)where;

/** Initialize a new @c AGSNALayerDefinition.
 @param layerName The name of the data layer in the network analyst service to reference.
 @param where The where clause for the query to restrict which features from the data layer should be used as inputs.
 @return An initialized @c AGSNALayerDefinition object.
 @since 1.8
 */
- (id)initWithLayerName:(NSString*)layerName where:(NSString*)where;

/** Initialize a new @c AGSNALayerDefinition.
 @param url of a data layer in a map or feature service. The network analysis service retrieves features from this data layer at run-time to use as inputs in the analysis.
 @param query to restrict which features from the data layer should be used as inputs
 @return
 @avail{10.1}
 @since 2.3
 */
- (id)initWithURL:(NSURL*)url query:(AGSQuery*)query;
 

@end

