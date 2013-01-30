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

@class AGSSpatialReference;

/** @file AGSRelationshipQuery.h */ //Required for Globals API doc

/** @brief Parameters for a @c AGSQueryTask operation to query related records.
 
 Instances of this class represent parameters for executing queries with 
 @c AGSQueryTask that fetch related records. Parameters define the criteria for 
 finding related records and provide options for how the results should be returned.
 
 All parameters related to geometry will be ignored when fetching related records 
 from a table.
 
 @define{AGSQueryTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSRelationshipQuery : NSObject <AGSCoding, NSCopying>

/** The ID of the relationship this query should be based on. The IDs of 
 relationships that a layer or table participates in are listed in the ArcGIS 
 Services Directory.
 @since 1.0 
 */
@property (nonatomic, assign) NSInteger relationshipId;

/** IDs of features whose related records are to be queried.
 @since 1.0 
 */
@property (nonatomic, copy) NSArray *objectIds;

/** The definition expression to be applied to the related layer or table. Only 
 features that satisfy both the definition expression and the query criteria 
 will be returned.
 @since 1.0 
 */
@property (nonatomic, copy) NSString *definitionExpression;

/** Attribute fields to be included for the result features or records. To 
 include geometry information in the results, use #returnGeometry. You must use 
 the actual field names rather than the field aliases. As a best practice, you 
 should try to limit the fields to only those you expect to use. The fewer fields 
 you include, the faster the response will be.
 
 This parameter must be specified. You can use the wildcard "*" to include all 
 fields.
 
 @since 1.0
 */
@property (nonatomic, copy) NSArray *outFields;

/** If <code>YES</code>, result features will include their geometry. This is 
 needed when you want to display the features on the map. Default is 
 <code>NO</code> to get better performance since geometries makes up a significant 
 portion of the response. If the results originate from a table, they will not 
 contain geometries.
 @since 1.0
 */
@property (nonatomic, assign) BOOL returnGeometry;

/** The spatial reference in which result geometries are to be returned. If not 
 specified, geometries are returned in the spatial reference of the service. If 
 the results originate from a table, they will not contain geometries.
 @since 1.0 
 */
@property (nonatomic, strong) AGSSpatialReference *outSpatialReference;

/** The maximum allowable offset used for generalizing geometries returned by the 
 query operation. The default is 0. If 0 is specified the value is not passed to 
 the server in a query. The offset is in the units of the 
 <code>spatialReference</code>. If a <code>spatialReference</code> is not 
 defined the spatial reference of the map is used.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, assign) double maxAllowableOffset;

/** Initialize autoreleased <code>AGSRelationshipQuery</code> object with defaults.
 @return A new, autoreleased, relationship query object.
 @since 1.0 
 */
+ (id)relationshipQuery;

@end
