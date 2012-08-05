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

@protocol AGSCoding;

@class AGSTask;
@class AGSCredential;
@class AGSGeometry;
@class AGSFeatureSet;
@class AGSSpatialReference;
@class AGSTimeExtent;

@class AGSQuery;
@class AGSRelationshipQuery;
@protocol AGSQueryTaskDelegate;

/** @file AGSQueryTask.h */ //Required for Globals API doc

#pragma mark -

/** @brief A task to perform structured queries.
 
 This task performs structured queries on a layer of ArcGIS Server Map Service, 
 Image Service, or Feature Service. For Map and Feature services, the query can 
 also be performed on a table. Queries can be based on SQL expressions, spatial 
 relationships, or time extents.
 
 A query task needs a URL to a REST resource that represents a layer in a Map, Image, or Feature service.
 For example, http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Demographics/ESRI_Census_USA/MapServer/5
 
 @see @concept{Query_Task/00pw00000016000000/, Using a Query Task}
 @see @sample{9e07d23f0bd3439e9e89fc06bf9ff201, Query Task}
 @since 1.0
 */
@interface AGSQueryTask : AGSTask {
 @private
     id<AGSQueryTaskDelegate> _delegate;
}

/** Delegate to be notified when the task completes successfully or returns an error.
 @since 1.0
 */
@property (nonatomic, assign) id<AGSQueryTaskDelegate> delegate;

/** Initialize an autoreleased query task.
 @param url URL to a layer resource in the ArcGIS Server REST Services Directory.
 @return A new, autoreleased, query task object.
 @since 1.0
 */
+ (id)queryTaskWithURL:(NSURL *)url;

/** Initialize autoreleased query task.
 @param url URL to a layer resource in the ArcGIS Server REST Services Directory.
 @param cred <code>AGSCredential</code> used to access the secured service.
 @return A new, autoreleased, query task object.
 @since 1.0
 */
+ (id)queryTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Executes a query against the layer resource pointed by the <code>url</code>.
 It relies on the <i>Query</i> operation of the REST resource.
 
 The query returns records matching the specified criteria. The records could be 
 features, if the service layer represents a layer. Or the records could be simple 
 records (without geometry) if the service layer represents a table. The #delegate 
 will be notified when the operation completes or if an error is encountered.
 
 The number of results returned by the query is limited by the service's configuration.
 @param query Specifies the criteria for the query.
 @return <code>NSOperation</code> for current execute request.
 @since 1.0
 @see AGSQueryTaskDelegate
 */
- (NSOperation *)executeWithQuery:(AGSQuery *)query;

/** Executes a query against the layer resource pointed by the <code>url</code>.
 It relies on the <i>Query</i> operation of the REST resource.
 
 The query returns only IDs of records matching the specified criteria. This is 
 useful if you want to implement paging for results or if you want to only fetch 
 result details on demand. Unlike <code>executeWithQuery:</code> , there is no 
 limit on the number of results returned by this query.
 
 The #delegate will be notified when the operation completes or if an error is 
 encountered.
 @param query Specifies the criteria for the query.
 @return <code>NSOperation</code> for current execute request.
 @since 1.0
 
 @avail{10}
 @see AGSQueryTaskDelegate
 */
- (NSOperation *)executeForIdsWithQuery:(AGSQuery *)query;

/** Executes a query against the layer resource pointed by the <code>url</code>.
 It relies on the <i>Query Related Records</i> operation of the REST resource.
 
 The query returns records that are related to the given set of features. The 
 related records could be features, if the service layer is related to a layer. 
 Or the related records could be simple records (wihtout geometry) if the service 
 layer is related to a table. 
 
 The #delegate will be notified when the operation completes or if an error is 
 encountered. 
 @param query Specifies the criteria for the query.
 @return <code>NSOperation</code> for current execute request.
 @since 1.0

 @avail{10}
 @see AGSQueryTaskDelegate
 */
- (NSOperation *)executeWithRelationshipQuery:(AGSRelationshipQuery *)query;

/** Executes a query against the layer resource pointed by the <code>url</code>.
 It relies on the <i>Query</i> operation of the REST resource.
 
 The query returns only a feature count of records matching the specified criteria. 
 
 The #delegate will be notified when the operation completes or if an error is 
 encountered.
 @param query Specifies the criteria for the query.
 @return <code>NSOperation</code> for current execute request.
 @since 1.0
 
 @avail{10}
 @see AGSQueryTaskDelegate
 */
- (NSOperation *)executeFeatureCountWithQuery:(AGSQuery*)query;

@end



#pragma mark -

/** @brief A delegate of @c AGSQueryTask.
 
 A protocol which must be adopted by any class wishing to be notified when the 
 @c AGSQueryTask completes successfully or encounters an error. An instance of 
 the class must then be set as the <code>delegate</code> of @c AGSQueryTask.
 
 @define{AGSQueryTask.h, ArcGIS}
 @since 1.0
 */
@protocol AGSQueryTaskDelegate <NSObject>

@optional
/** Tells the delegate that @c AGSQueryTask completed successfully with the 
 provided results.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param featureSet The feature set returned by executing query.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didExecuteWithFeatureSetResult:(AGSFeatureSet *)featureSet;

/** Tells the delegate that @c AGSQueryTask encountered an error.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didFailWithError:(NSError *)error;

/** Tells the delegate that @c AGSQueryTask completed query for IDs successfully 
 with the provided results.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param objectIds The array of object IDs returned by executing query.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didExecuteWithObjectIds:(NSArray *)objectIds;

/** Tells the delegate that @c AGSQueryTask encountered an error while performing 
 query for IDs.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didFailQueryForIdsWithError:(NSError *)error;

/** Tells the delegate that @c AGSQueryTask completed query for related features 
 successfully with the provided results.
 
 The related features are returned as a dictionary of key-value pairs.
 Keys contain <code>NSNumber</code> objects representing IDs from @c AGSRelationshipQuery 
 <code>objectIds</code>. Values contain arrays of @c AGSFeatureSet objects representing the 
 corresponding related features.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param relatedFeatures The related features returned by executing query.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didExecuteWithRelatedFeatures:(NSDictionary *)relatedFeatures;

/** Tells the delegate that @c AGSQueryTask encountered an error while performing 
 query for related features.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didFailRelationshipQueryWithError:(NSError *)error;

/** Tells the delegate that @c AGSQueryTask completed query with feature count 
 successfully.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param count The feature count returned by the query.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didExecuteWithFeatureCount:(NSInteger)count;

/** Tells the delegate that @c AGSQueryTask encountered an error while performing 
 query for feature count.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didFailQueryFeatureCountWithError:(NSError*)error;

@end

#pragma mark -

/** @brief Parameters for a @c AGSQueryTask operation.
 
 Instances of this class represent parameters for executing queries with 
 @c AGSQueryTask. Parameters define criteria for the query and provide options 
 for how the results should be returned. 
 
 All parameters related to geometry and spatial queries will be ignored when 
 querying tables.
 
 @define{AGSQueryTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSQuery : NSObject <AGSCoding, NSCopying> {
 @private
    AGSGeometry *_geometry;
    NSArray *_outFields;
    AGSSpatialReference *_outSpatialReference;
    BOOL _returnGeometry;
    AGSSpatialRelationship _spatialRelationship;
    NSString *_text;
    NSString *_where;
    
    NSArray *_objectIds;
    AGSTimeExtent *_timeExtent;
    NSString *_relationParam;
	double _maxAllowableOffset;
}

/** The geometry to use while performing a spatial query. Valid geometry types 
 are @c AGSEnvelope, @c AGSPoint, @c AGSMultipoint, @c AGSPolygon, and 
 @c AGSPolyline. Results of the query will include only those features which 
 conform to the specified @c #spatialRelationship with this geometry.
 @since 1.0
 */
@property (nonatomic, retain) AGSGeometry *geometry;

/** Attribute fields to be included for the result features or records. To include 
 geometry information in the results, use #returnGeometry. You must use the actual 
 field names rather than the field aliases. As a best practice, you should try to 
 limit the fields to only those you expect to use. The fewer fields you include, 
 the faster the response will be.
 
 This parameter must be specified. You can use the wildcard "*" to include all fields.
 
 If a table is being queried, results will not contain geometries. 
 @since 1.0
 */
@property (nonatomic, retain) NSArray *outFields;

/** The spatial reference in which result geometries are to be returned. If not 
 specified, geometries are returned in the spatial reference of the service.
 @since 1.0
 */
@property (nonatomic, retain) AGSSpatialReference *outSpatialReference;

/** If <code>YES</code>, result features will include their geometry. This is 
 needed when you want to display the features on the map. Default is 
 <code>NO</code> to get better performance since geometries make up a significant 
 portion of the response. If a table is being queried, results will not contain 
 geometries. 
 @since 1.0
 */
@property (nonatomic, assign) BOOL returnGeometry;

/** The spatial constraint that needs to be applied on the query #geometry. 
 Possible values include
 
 @li @c AGSSpatialRelationshipIntersects
 @li @c AGSSpatialRelationshipContains
 @li @c AGSSpatialRelationshipCrosses
 @li @c AGSSpatialRelationshipEnvelopeIntersects
 @li @c AGSSpatialRelationshipIndexIntersects
 @li @c AGSSpatialRelationshipOverlaps
 @li @c AGSSpatialRelationshipTouches
 @li @c AGSSpatialRelationshipWithin
 @li @c AGSSpatialRelationshipRelation
 
 You can also specify a custom spatial constraint in #relationParam by setting 
 this parameter to @c AGSSpatialRelationshipRelation. 
 @since 1.0
 */
@property (nonatomic, assign) AGSSpatialRelationship spatialRelationship;

/** The text to be searched in the layer's primary display field. The search is 
 case-sensitive. The display field for a layer is listed in the Services Directory. 
 
 This parameter is a shorthand for a where clause of the form
 <i>&lt;displayField&gt; like '%&lt;text&gt;%'</i>. It is ignored if #where clause 
 is specified.
 
 @since 1.0
 */
@property (nonatomic, retain) NSString *text;

/** A SQL where clause for the query. If the where clause includes dates, they 
 must be correctly formatted based on the geodatabase datasource used in the 
 service. Refer to <a href="http://help.arcgis.com/en/arcgisdesktop/10.0/help/index.html#//00s500000033000000.htm">this</a> 
 document for date formats expected by different datasources.
 @since 1.0
 */
@property (nonatomic, retain) NSString *where;

/** The IDs of features that the query should be restricted to.
 @avail{10}
 @since 1.0
 */
@property (nonatomic, retain) NSArray *objectIds;

/** The spatial relate function to be applied on the query @c #geometry while 
 performing the query. For example <i>"FFFTTT****"</i>. It is a 9 character 
 string describing a custom spatial relationship, something that is not possible 
 with #spatialRelationship . A spatial relationship is defined by the intersections 
 between the <i>boundary</i>, <i>interior</i>, and <i>exterior</i> of the query 
 geometry and the result geometry. 
 
 <i>Interior:</i>
 The interior of a shape is defined as the entire shape minus its boundary. All 
 shapes have interior.
 
 <i>Boundary:</i>
 Linear and area shapes have boundaries, but point shapes do not. The boundary of 
 linear shapes consists of the end points of all linear parts. The boundary of 
 area shapes consists of the linear boundary of the polygon shell(s).
 
 <i>Exterior:</i>
 The area outside a shape. All shapes have an exterior.
 
 The 9 character string is used to specify whether the intersection of each of 
 the elements in following table is true (T), false (F), or not tested (*).
 
 <TABLE style="border-width:2px; border-style:solid; border-color: #84B0C7">
	<TR >
		<TD class="indexkey">&nbsp;</TD>
		<TD class="indexkey">Query Geometry</TD>
		<TD class="indexkey">Result Geometry</TD>
	</TR>
	<TR>
		<TD class="indexkey">1</TD><TD>Interior</TD><TD>Interior</TD>
	</TR>
	<TR>
		<TD class="indexkey">2</TD><TD>Interior</TD><TD>Boundary</TD>
	</TR>
	<TR>
		<TD class="indexkey">3</TD><TD>Interior</TD><TD>Exterior</TD>
	</TR>
	<TR>
		<TD class="indexkey">4</TD><TD>Boundary</TD><TD>Interior</TD>
	</TR>
	<TR>
		<TD class="indexkey">5</TD><TD>Boundary</TD><TD>Boundary</TD>
	</TR>
	<TR>
		<TD class="indexkey">6</TD><TD>Boundary</TD><TD>Exterior</TD>
	</TR>
	<TR>
		<TD class="indexkey">7</TD><TD>Exterior</TD><TD>Interior</TD>
	</TR>
	<TR>
		<TD class="indexkey">8</TD><TD>Exterior</TD><TD>Boundary</TD>
	</TR>
	<TR>
		<TD class="indexkey">9</TD><TD>Exterior</TD><TD>Exterior</TD>
	</TR>
 </TABLE>
 
 
 Thus, in <i>"FFFTTT****"</i>,  relationships 1-3 must be false, relationships 
 4-6 must be true, and relationships 7-9 are not tested.
 
 Refer to the <i>Spatial Relate Function</i> section of <a href="http://help.arcgis.com/en/sdk/10.0/vba_desktop/conceptualhelp/index.html#//00010000007v000000">this</a> 
 document for more information.
  
 You must set #spatialRelationship to @c AGSSpatialRelationshipRelation when 
 specifying this parameter.
 @avail{10}
 @since 1.0
 */
@property (nonatomic, retain) NSString *relationParam;

/** Specify a time extent for the query.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, retain) AGSTimeExtent *timeExtent;

/** The maximum allowable offset used for generalizing geometries returned by the 
 query operation. The default is 0. If 0 is specified the value is not passed to 
 the server in a query. The offset is in the units of the 
 <code>#outSpatialReference</code>. If a <code>outSpatialReference</code> is not 
 defined, the spatial reference of the service is used.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, assign) double maxAllowableOffset;

/** Initialize an autoreleased Query object with defaults.
 @return A new, autoreleased, query object.
 @since 1.0
 */
+ (id)query;

@end



#pragma mark -

/** @brief Parameters for a @c AGSQueryTask operation to query related records.
 
 Instances of this class represent parameters for executing queries with 
 @c AGSQueryTask that fetch related records. Parameters define the criteria for 
 finding related records and provide options for how the results should be returned.
 
 All parameters related to geometry will be ignored when fetching related records 
 from a table.
 
 @define{AGSQueryTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSRelationshipQuery : NSObject <AGSCoding, NSCopying> {
 @private
    NSInteger _relationshipId;
    NSArray *_objectIds;
    NSString *_definitionExpression;
    NSArray *_outFields;
	double _maxAllowableOffset;
    BOOL _returnGeometry;
    AGSSpatialReference *_outSpatialReference;
}

/** The ID of the relationship this query should be based on. The IDs of 
 relationships that a layer or table participates in are listed in the ArcGIS 
 Services Directory.
 @since 1.0 
 */
@property (nonatomic, assign) NSInteger relationshipId;

/** IDs of features whose related records are to be queried.
 @since 1.0 
 */
@property (nonatomic, retain) NSArray *objectIds;

/** The definition expression to be applied to the related layer or table. Only 
 features that satisfy both the definition expression and the query criteria 
 will be returned.
 @since 1.0 
 */
@property (nonatomic, retain) NSString *definitionExpression;

/** Attribute fields to be included for the result features or records. To 
 include geometry information in the results, use #returnGeometry. You must use 
 the actual field names rather than the field aliases. As a best practice, you 
 should try to limit the fields to only those you expect to use. The fewer fields 
 you include, the faster the response will be.
 
 This parameter must be specified. You can use the wildcard "*" to include all 
 fields.
 
 @since 1.0
 */
@property (nonatomic, retain) NSArray *outFields;

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
@property (nonatomic, retain) AGSSpatialReference *outSpatialReference;

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
