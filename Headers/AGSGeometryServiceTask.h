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
@class AGSPolygon;
@class AGSPolyline;
@class AGSCredential;
@class AGSTask;
@class AGSDistanceParameters;
@class AGSRelationParameters;

@protocol AGSCoding;
@protocol AGSGeometryServiceTaskDelegate;

/** @file AGSGeometryServiceTask.h */ //Required for Globals API doc

#pragma mark -

/** @brief A task to perform geometric operations.
 
 An instance of this class allows you to  perform various frequently used 
 geometric operations using a remote ArcGIS Server Geometry Sservice. 
 For example, <a href="http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Geometry/GeometryServer">http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Geometry/GeometryServer</a>.
 
 Geometric operations include :
 
 @li Buffer, project, and simplify geometries
 @li Calculate areas and lengths for geometries
 @li Determine spatial relations and label points
 @li Compute union, intersection, and difference between geometries
 @li Auto complete, generalize, reshape, offset, trim, extend and compute convex 
 hulls of geometries
 
 The input and output geometries are always packaged in arrays.

 @define{AGSGeometryServiceTask.h, ArcGIS}
 @since 1.0
 @see @sample{7ef2e7a505b44ac78d20307a05a92cbf, Geometry Service Task}
 @see @c AGSGeometryEngine in order to perform geometric operations locally on the device
 

 */
@interface AGSGeometryServiceTask : AGSTask

/** Delegate to be notified when the task completes successfully or encounters 
 an error.
 @since 1.0
 */
@property (nonatomic, weak) id<AGSGeometryServiceTaskDelegate> delegate;

/** Initialize an autoreleased Geometry service task.
 @param url URL to a geometry service.
 @return A new, autoreleased, geometry service task object
 @since 1.0
 */
+ (id)geometryServiceTaskWithURL:(NSURL *)url;

/** Initialize an autoreleased Geometry service task.
 @param url URL to a geometry service.
 @param cred <code>AGSCredential</code> used to access the secured resource.
 @return A new, autoreleased, geometry service task object
 @since 1.0
 */
+ (id)geometryServiceTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Computes pairs of geometries that satisfy the specified spatial relation.  
 The relations are evaluated in 2-dimensions. Z coordinates are not used. 
 Geometries in both arrays must have the same spatial reference. All geometries 
 must be of the same type - @c AGSPoint, @c AGSMultipoint, @c AGSPolygon, 
 @c AGSPolyline, or @c AGSEnvelope. The #delegate is notified when the operation
 completes successfully or encounters an error.
 @param relationParams The parameters to be used as input for the operation.
 @return <code>NSOperation</code> for current request.
 
 @avail{9.3 Service Pack 1}
 @since 1.0
 */
- (NSOperation *)relationWithParameters:(AGSRelationParameters*)relationParams;

/** Measures the planar or geodesic distance between geometries. The #delegate 
 is notified when the operation completes successfully or encounters an error.
 @param distanceParams Sets the input geometries to measure, distance units
 and other parameters for the operation.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */
- (NSOperation *)distanceWithParameters:(AGSDistanceParameters *)distanceParams;

/** The union operation constructs the set-theoretic union of the geometries
 in the input array. All inputs must be of the same type. The #delegate is 
 notified when the operation completes successfully or encounters an error.
 @param geometries The array of geometries to be unioned.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */
- (NSOperation *)unionGeometries:(NSArray *)geometries;

/** Reshapes a polyline or a part of a polygon using a reshaping line. The 
 #delegate is notified when the operation completes successfully or encounters 
 an error.
 @param geometry The polyline or polygon to be reshaped.
 @param reshaper The single-part polyline that does the reshaping.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */
- (NSOperation *)reshapeGeometry:(AGSGeometry*)geometry withReshaper:(AGSPolyline*)reshaper;

/** Returns the convex hull of the input geometries. The input geometries can be
 points, multipoints, polylines, or polygons. The hull is typically a polygon
 but can also be a polyline or point in degenerate cases. The #delegate is 
 notified when the operation completes successfully or encounters an error.
 @param geometries Array of geometries whose convex hull is to be created.
 @return <code>NSOperation</code> for current request.
 
 @avail{10.0}
 @since 1.0
 */
- (NSOperation *)convexHullGeometries:(NSArray*)geometries;

@end



#pragma mark -

/** @brief A delegate of @c AGSGeometryServiceTask.
 
 A protocol which must be adopted by any class wishing to be notified when 
 @c AGSGeometryServiceTask completes successfully or encounters an error. An 
 instance of the class must then be set as the delegate of @c AGSGeometryServiceTask.
 
 @define{AGSGeometryServiceTask.h, ArcGIS}
 @since 1.0
 */
@protocol AGSGeometryServiceTaskDelegate <NSObject>

@optional
/** Tells the delegate that geometries were buffered successfully.
 @param geometryServiceTask The task called to buffer.
 @param op <code>NSOperation</code> that performed the task.
 @param bufferedGeometries The resulting array of buffered polygons. If multiple 
 input geometries and buffer distances were supplied, the array contains results 
 for all geometries based on the first distance, followed by the next distance, 
 and so on.
 @since 1.0
 @see AGSPolygon
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnBufferedGeometries:(NSArray *)bufferedGeometries;

/** Tells the delegate that an error was encountered while buffering the 
 geometries.
 @param geometryServiceTask The task called to buffer.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailBufferWithError:(NSError *)error;

/** Tells the delegate that geometries were projected successfully.
 @param geometryServiceTask The task called to project.
 @param op <code>NSOperation</code> that performed the task.
 @param projectedGeometries The resulting array of projected geometries.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnProjectedGeometries:(NSArray *)projectedGeometries;

/** Tells the delegate that an error was encountered while projecting the geometries.
 @param geometryServiceTask The task called to project.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailProjectWithError:(NSError *)error;

/** Tells the delegate that geometries were simplified successfully.
 @param geometryServiceTask The task called to simplify.
 @param op <code>NSOperation</code> that performed the task.
 @param simplifiedGeometries The resulting array of simplified polygons.
 @since 1.0
 @see AGSPolygon
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnSimplifiedGeometries:(NSArray *)simplifiedGeometries;

/** Tells the delegate that an error was encountered while simplifying the geometries.
 @param geometryServiceTask The task called to simplify.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailSimplifyWithError:(NSError *)error;

/** Tells the delegate that areas and lengths of polygons were calculated successfully.
 @param geometryServiceTask The task called to calculate areas and lengths.
 @param op <code>NSOperation</code> that performed the task.
 @param areas The areas of the input polygons. The areas are represented as double
 values.
 @param lengths The perimeters of the input polygons. The lengths are represented
 as double values.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnAreas:(NSArray *)areas andLengths:(NSArray *)lengths;

/** Tells the delegate that an error was encountered while calculating the areas 
 and lengths of polygons.
 @param geometryServiceTask The task called to compute areas and lengths.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailAreasAndLengthsWithError:(NSError *)error;

/** Tells that delegate that label points of polygons were returned successfully.
 @param geometryServiceTask The task called to get label points.
 @param op <code>NSOperation</code> that performed the task.
 @param labelPoints The resulting label points for the input polygons.
 @since 1.0
 @see AGSPoint
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnLabelPoints:(NSArray *)labelPoints;

/** Tells the delegate that an error was encountered while fetching the label 
 points of polygons.
 @param geometryServiceTask The task called to get label points.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailLabelPointsWithError:(NSError *)error;

/** Tells the delegate that lengths of polylines were calculated successfully.
 @param geometryServiceTask The task called to get lengths.
 @param op <code>NSOperation</code> that performed the task.
 @param lengths The lengths of the input polylines. The lengths are returned
 as double values.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnLengths:(NSArray *)lengths;

/** Tells the delegate that an error was encountered while calculating lengths 
 of polylines.
 @param geometryServiceTask The task called to compute lengths.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailLengthsWithError:(NSError *)error;

/** Tells the delegate that related geometries were paired successfully.
 @param geometryServiceTask The task called to pair related geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param relations The relations of the input geometries. Each relation is an 
 @c AGSGeometryRelationship object where @p geometry1 relates to @p geometry2 
 with the relation @p type.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnRelations:(NSArray *)relations;

/** Tells the delegate that an error was encountered while pairing related geometries.
 @param geometryServiceTask The task called to pair related geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailRelationWithError:(NSError *)error;

/** Tells the delegate that a distance was returned successfully.
 @param geometryServiceTask The task called to calculate distance.
 @param op <code>NSOperation</code> that performed the task.
 @param distance The distance between the input geometries. The distance is 
 returned as a double value.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnDistance:(double)distance;

/** Tells the delegate that an error was encountered while calculating the distance.
 @param geometryServiceTask The task called to calculate distance.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailDistanceWithError:(NSError *)error;

/** Tells the delegate that densified geometries were returned successfully.
 @param geometryServiceTask The task called to the input densify geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param geometries The resulting array of densified geometries.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnDensifiedGeometries:(NSArray*)geometries;

/** Tells the delegate that an error was encountered while performing the 
 densify operation.
 @param geometryServiceTask The task called to densify the input geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailDensifyWithError:(NSError *)error;

/** Tells the delegate that generalized geometries were returned successfully.
 @param geometryServiceTask The task called to generalize the input geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param geometries The resulting array of generalized geometries.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnGeneralizedGeometries:(NSArray*)geometries;

/** Tells the delegate that an error was encountered while performing the 
 generalize operation.
 @param geometryServiceTask The task called to generalize the input geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailGeneralizeWithError:(NSError*)error;

/** Tells the delegate that unioned geometries were returned successfully.
 @param geometryServiceTask The task called to union the input geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param geometry The result of unioning the input geometries.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnUnionedGeometry:(AGSGeometry*)geometry;

/** Tells the delegate that an error was encountered while unioning the input
 geometries.
 @param geometryServiceTask The task called to union the input geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailUnionWithError:(NSError*)error;

/** Tells the delegate that reshaped geometries were returned successfully.
 @param geometryServiceTask The task called to reshape the input geometry.
 @param op <code>NSOperation</code> that performed the task.
 @param geometry The result of reshaping the input geometry.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnReshapedGeometry:(AGSGeometry*)geometry;

/** Tells the delegate that an error was encountered while reshaping the input
 geometry.
 @param geometryServiceTask The task called to reshape the input geometry.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailReshapeWithError:(NSError*)error;

/** Tells the delegate that intersecting geometries were returned successfully.
 @param geometryServiceTask The task called to perform an intersect on the input 
 geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param geometries The result of calculating the intersection of the input geometries.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnIntersectingGeometries:(NSArray*)geometries;

/** Tells the delegate that an error was encountered while calculating the
 intersection of the input geometries.
 @param geometryServiceTask The task called to perform an intersect on the input 
 geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailIntersectWithError:(NSError*)error;

/** Tells the delegate that the difference of the input geometries was returned
 successfully.
 @param geometryServiceTask The task called to calculate the difference of the input
 geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param geometries The resulting geometries from calculating the difference of the 
 input geometries.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnDifferenceGeometries:(NSArray*)geometries;

/** Tells the delegate that an error was encountered while calculating the
 difference of the input geometries.
 @param geometryServiceTask The task called to calculate the difference of the input
 geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailDifferenceWithError:(NSError*)error;

/** Tells the delegate that the cut operation returned successfully.
 @param geometryServiceTask The task called to cut the input geometry.
 @param op <code>NSOperation</code> that performed the task.
 @param geometries The resulting geometries defining the cut region.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnCutGeometries:(NSArray*)geometries; 

/** Tells the delegate that an error was encountered while performing the cut 
 operation on the input geometry.
 @param geometryServiceTask The task called to cut the input geometry.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailCutWithError:(NSError*)error;

/** Tells the delegate that the autocomplete operation returned successfully.
 @param geometryServiceTask The task called to autocomplete the input polygons.
 @param op <code>NSOperation</code> that performed the task.
 @param polygons The resulting autocompleted polygons.
 @since 1.0
 @see AGSPolygon
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnAutoCompletedPolygons:(NSArray*)polygons;

/** Tells the delegate that an error was encountered while autocompleting the 
 input polygons.
 @param geometryServiceTask The task called to autocomplete the input polygons.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailAutoCompleteWithError:(NSError*)error;

/** Tells the delegate that the convex hull geometry was returned successfully.
 @param geometryServiceTask The task called to calculate the convex hull of the 
 input geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param geometry The resulting convex hull of the input geometries.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnConvexHullGeometry:(AGSGeometry*)geometry;

/** Tells the delegate that an error was encountered while calculating the convex
 hull of the input geometries.
 @param geometryServiceTask The task called to calculate the convex hull of the 
 input geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailConvexHullWithError:(NSError*)error;

/** Tells the delegate that the offset was constructed successfully.
 @param geometryServiceTask The task called to calculate the offset of the input
 geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param geometries The resulting offset geometries.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnOffsetGeometries:(NSArray*)geometries;

/** Tells the delegate that an error was encountered while calculating the offset
 of the input geometries.
 @param geometryServiceTask The task called to calculate the offset of the input
 geometries.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailOffsetWithError:(NSError*)error;

/** Tells the delegate that the trimExtend operation completed successfully.
 @param geometryServiceTask The task called to trim/extend the input polylines.
 @param op <code>NSOperation</code> that performed the task.
 @param polylines The resulting trimmed/extended polylines.
 @since 1.0
 @see AGSPolyline
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didReturnTrimExtendPolylines:(NSArray*)polylines;

/** Tells the delegate that an error was encountered while trimming/extending
 the input polylines.
 @param geometryServiceTask The task called to trim/extend the input polylines.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the operation's failure.
 @since 1.0
 */
- (void)geometryServiceTask:(AGSGeometryServiceTask *)geometryServiceTask operation:(NSOperation*)op didFailTrimExtendWithError:(NSError*)error;

@end