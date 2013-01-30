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

@class AGSBufferParameters;
@class AGSDensifyParameters;
@class AGSGeneralizeParameters;
@class AGSOffsetParameters;
@class AGSSpatialReference;
@class AGSTrimExtendParameters;

/** @file AGSGeometryServiceTask+AGSGeometryArray.h  */ //Required for Globals API doc

@interface AGSGeometryServiceTask (AGSGeometryArray)

/** Creates buffer polygons at the specified distance around the given geometries.
 The #delegate is notified when an operation completes successfully or encounters 
 an error.
 @param params Specifies the input geometries, buffer distances, and other options
 @return <code>NSOperation</code> for current request.
 @since 1.0
 */
- (NSOperation *)bufferWithParameters:(AGSBufferParameters *)params;

/** Projects the given geometries into a new spatial reference. All geometries 
 must be of the same type - @c AGSPoint, @c AGSMultipoint, @c AGSPolygon, 
 @c AGSPolyline, or @c AGSEnvelope. The #delegate is notified when an operation 
 completes successfully or encounters an error.
 @param geometries The array of geometries to be projected.
 @param spatialReference The spatial reference to which geometries need to be 
 projected.
 @return <code>NSOperation</code> for current request.
 @since 1.0
 */
- (NSOperation *)projectGeometries:(NSArray *)geometries toSpatialReference:(AGSSpatialReference *)spatialReference;

/** Simplifies the given geometries to make them topologically consistent according
 to their geometry type. All geometries must be of the same type - @c AGSPoint,
 @c AGSMultipoint, @c AGSPolygon, or @c AGSPolyline. The #delegate is notified 
 when an operation completes successfully or encounters an error.
 @param geometries The array of geometries to be simplified.
 @return <code>NSOperation</code> for current request.
 @since 1.0
 */
- (NSOperation *)simplifyGeometries:(NSArray *)geometries;

/** Calculates an interior point for each @c AGSPolygon in the array. These interior 
 points can be used by clients to place labels for the polygons. The #delegate
 is notified when an operation completes successfully or encounters an error.
 @param polygons The array of polygons to get label points for.
 @return <code>NSOperation</code> for current request.
 
 @avail{9.3 Service Pack 1}
 @since 1.0
 */
- (NSOperation *)labelPointsForPolygons:(NSArray *)polygons;

/** Densifies the input geometries by plotting points between existing vertices.
 The #delegate is notified when an operation completes successfully or encounters 
 an error.
 @param densifyParams The parameters to be used as input to the operation.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */ 
- (NSOperation *)densifyWithParameters:(AGSDensifyParameters*)densifyParams;

/** Returns generalized (Douglas-Poiker) versions of the input geometries. The #delegate 
 is notified when an operation completes successfully or encounters an error.
 @param generalizeParams Sets the geometries, maximum deviation and units for 
 the generalize operation.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */ 
- (NSOperation *)generalizeWithParameters:(AGSGeneralizeParameters*)generalizeParams;

/** Constructs the set-theoretic intersection between an array of geometries and 
 another geometry. The #delegate is notified when an operation completes 
 successfully or encounters an error.
 @param geometries The array of geometries to be used as input for the 
 intersection. These should be an array of points, multipoints, polylines or 
 polygons.
 @param intersectGeometry A single geometry of any type, of dimension equal 
 to or greater than the elements of @p geometries.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */ 
- (NSOperation *)intersectGeometries:(NSArray*)geometries withGeometry:(AGSGeometry*)intersectGeometry;

/** Constructs the set-theoretic difference between an array of geometries and 
 another geometry. The #delegate is notified when an operation completes 
 successfully or encounters an error.
 @param geometries The array of geometries to be used as input for the difference 
 operation. These should be an array of points, multipoints, polylines or polygons.
 @param differenceGeometry A single geometry of any type, of dimension equal 
 to or greater than the elements of @p geometries.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */ 
- (NSOperation *)differenceGeometries:(NSArray*)geometries withGeometry:(AGSGeometry*)differenceGeometry;

/** Splits the input polyline or polygon where it crosses a cutting polyline.
 The #delegate is notified when an operation completes successfully or 
 encounters an error. 
 @param geometries The array of geometries to be cut. 
 @param cutterGeometry The polyline that will be used to divide the target 
 into pieces where it crosses the target.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */ 
- (NSOperation *)cutGeometries:(NSArray*)geometries withGeometry:(AGSPolyline*)cutterGeometry;

/** Simplifies the process of constructing new polygons that are adjacent to 
 other polygons. It constructs polygons that fill in the gaps between existing 
 polygons and a set of polylines. The #delegate is notified when an operation 
 completes successfully or encounters an error.
 @param polygons An array of polygons that will provide some boundaries for new 
 polygons.
 @param polylines An array of polylines that will provide the remaining boundaries 
 for the new polygons.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */ 
- (NSOperation *)autoCompletePolygons:(NSArray*)polygons withPolylines:(NSArray*)polylines;

/** Offset constructs the offset of the given input geometries. If the 
 @p offsetDistance parameter is positive the constructed offset will be on the 
 right side of the geometry. (Left side offsets are constructed with negative 
 parameters.) Tracing the geometry from it's first vertex to the last will give 
 you a direction along the geometry. It is to the right and left perspective of 
 this direction that the positive and negative parameters will dictate where the 
 offset is contructed. In these terms it is simple to infer where the offset of 
 even horizontal geometries will be constructed. The @p offsetHow parameter 
 determines how outer corners between segments are handled. Rounded offset rounds 
 the corner between extended offsets. Bevelled offset squares off the corner 
 after a given ratio distance. Mitered offset attempts to allow extended offsets 
 to naturally intersect, but if that intersection occurs too far from the corner, 
 the corner is eventually bevelled off at a fixed distance. The #delegate
 is notified when an operation completes successfully or encounters an error.
 @param offsetParams The parameters to be used as input to the operation.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */
- (NSOperation *)offsetWithParameters:(AGSOffsetParameters*)offsetParams;

/**  This operation trims / extends each polyline specified in the input array, 
 using the user specified guide polylines. When trimming features, the part to 
 the left of the oriented cutting line is preserved in the output and the other 
 part is discarded. An empty polyline is added to the output array if the 
 corresponding input polyline is neither cut nor extended. The #delegate
 is notified when an operation completes successfully or encounters an error.
 @param trimExtendParams The set the polylines and other parameters for the 
 operation.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */
- (NSOperation *)trimExtendWithParameters:(AGSTrimExtendParameters*)trimExtendParams;

@end
