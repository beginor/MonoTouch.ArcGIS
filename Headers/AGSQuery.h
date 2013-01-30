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

@class AGSTimeExtent;
@class AGSGeometry;
@class AGSSpatialReference;

/** @file AGSQuery.h */ //Required for Globals API doc



/** @brief Parameters for a @c AGSQueryTask operation.
 
 Instances of this class represent parameters for executing queries with 
 @c AGSQueryTask. Parameters define criteria for the query and provide options 
 for how the results should be returned. 
 
 All parameters related to geometry and spatial queries will be ignored when 
 querying tables.
 
 @define{AGSQueryTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSQuery : NSObject <AGSCoding, NSCopying>

/** The geometry to use while performing a spatial query. Valid geometry types 
 are @c AGSEnvelope, @c AGSPoint, @c AGSMultipoint, @c AGSPolygon, and 
 @c AGSPolyline. Results of the query will include only those features which 
 conform to the specified @c #spatialRelationship with this geometry.
 @since 1.0
 */
@property (nonatomic, strong) AGSGeometry *geometry;

/** Attribute fields to be included for the result features or records. To include 
 geometry information in the results, use #returnGeometry. You must use the actual 
 field names rather than the field aliases. As a best practice, you should try to 
 limit the fields to only those you expect to use. The fewer fields you include, 
 the faster the response will be.
 
 This parameter must be specified. You can use the wildcard "*" to include all fields.
 
 If a table is being queried, results will not contain geometries. 
 @since 1.0
 */
@property (nonatomic, copy) NSArray *outFields;

/** The spatial reference in which result geometries are to be returned. If not 
 specified, geometries are returned in the spatial reference of the service.
 @since 1.0
 */
@property (nonatomic, strong) AGSSpatialReference *outSpatialReference;

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
@property (nonatomic, copy) NSString *text;

/** A SQL where clause for the query. If the where clause includes dates, they 
 must be correctly formatted based on the geodatabase datasource used in the 
 service. Refer to <a href="http://help.arcgis.com/en/arcgisdesktop/10.0/help/index.html#//00s500000033000000.htm">this</a> 
 document for date formats expected by different datasources.
 @since 1.0
 */
@property (nonatomic, copy) NSString *where;

/** The IDs of features that the query should be restricted to.
 @avail{10}
 @since 1.0
 */
@property (nonatomic, copy) NSArray *objectIds;

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
@property (nonatomic, copy) NSString *relationParam;

/** Specify a time extent for the query.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, strong) AGSTimeExtent *timeExtent;

/** The maximum allowable offset used for generalizing geometries returned by the 
 query operation. The default is 0. If 0 is specified the value is not passed to 
 the server in a query. The offset is in the units of the 
 <code>#outSpatialReference</code>. If a <code>outSpatialReference</code> is not 
 defined, the spatial reference of the service is used.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, assign) double maxAllowableOffset;

/** Definitions, as an array of @c AGSOutStatistic objects, for one or more field-based statitics to be calculated. Note, the service being queried must support calculating statistics.
 @avail{10.1}
 @since 10.1.1
 */
@property (nonatomic, copy) NSArray *outStatistics;

/** One or more field by which the statistics must be calculated and grouped. It is an array of strings, where each string represents a field name. This property works together with @c #outStatistics;
 @avail{10.1}
 @since 10.1.1
 */
@property (nonatomic, copy) NSArray *groupByFieldsForStatistics;

/** Fields by which the results need to be ordered. It is an array of strings, where each string contains a field name followeb by the sort order (ASC or DESC). For example, <i>[ "STATE_NAME ASC", "POP1990 DESC"]</i>. Note, the service being queried must support advanced queries.
 @avail{10.1}
 @since 10.1.1
 */
@property (nonatomic, copy) NSArray *orderByFields;

/** Initialize an autoreleased Query object with defaults.
 @return A new, autoreleased, query object.
 @since 1.0
 */
+ (id)query;

@end
