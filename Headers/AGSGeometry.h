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

@protocol AGSCoding;

@class AGSEnvelope;
@class AGSSpatialReference;

/** @file AGSGeometry.h */ //Required for Globals API doc

#pragma mark -

/** @brief Base class for all geometry objects.
 
 A base class for all geometry objects.
 @define{AGSGeometry.h, ArcGIS}
 @since 1.0
 */
@interface AGSGeometry : NSObject <AGSCoding, NSCopying, NSMutableCopying>

/** Geometry's spatial reference.
 @since 1.0
*/
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Smallest, rectangular bounding-box that covers the geometry.
 @since 1.0
 */
@property (nonatomic, copy, readonly) AGSEnvelope *envelope;

/** Initialize geometry object with spatial reference.
 @param spatialReference The spatial referenc of geometry.
 @return A new geometry object.
 @since 1.0
 */
- (id)initWithSpatialReference:(AGSSpatialReference *)spatialReference;

/** Initialize geometry object with json and a spatial reference.
 @param json The JSON to initialize an <code>AGSGeometry</code> with.
 @param sr The spatial reference of geometry represented in @p json.
 @return A new geometry object.
 @since 1.0
 */
- (id)initWithJSON:(NSDictionary *)json spatialReference:(AGSSpatialReference*)sr;

/** Returns <code>true</code> if @p envelope intersects this geometry.
 @param envelope The envelope to test intersection relation.
 @return <code>True</code> if envelopes intersects.
 @since 1.0
 */
- (BOOL)intersectsWithEnvelope:(AGSEnvelope *)envelope;

/** Returns whether or not the geometry is empty.
 @since 1.8
 */
-(BOOL)isEmpty;

/** Returns whether or not the geometry is valid.
 @since 1.8
 */
-(BOOL)isValid;

@end

#pragma mark -

/** Return autoreleased geometry, initialized from JSON representation.
 @param json The JSON representation.
 @return A new geometry object.
 */
AGS_EXTERN AGSGeometry *AGSGeometryWithJSON(NSDictionary *json);

/** Return autoreleased geometry, initialized from JSON representation and 
 spatial reference.
 @param json The JSON representation.
 @param sr The spatial reference of the geometry.
 @return A new geometry object.
 */
AGS_EXTERN AGSGeometry *AGSGeometryWithJSONAndSR(NSDictionary *json, AGSSpatialReference *sr);

/** Return @c AGSGeometryType from geometry.
 @param geometry The geometry to determine geometry type.
 @return @c AGSGeometryType for @p geometry.
 @see AGSGeometryType
 */
AGS_EXTERN AGSGeometryType AGSGeometryTypeForGeometry(AGSGeometry *geometry);

/** Return geometry type string for @c AGSGeometryType.
 @param geometryType The type for geometry.
 @return String representation of @p geometryType.
 @see AGSGeometryType
 */
AGS_EXTERN NSString *AGSGeometryTypeString(AGSGeometryType geometryType);

/** Return geometry type for type string.
 @param geometryType The string representation of a geometry type.
 @return @c AGSGeometryType for @p geometryType string.
 @see AGSGeometryType
 */
AGS_EXTERN AGSGeometryType AGSGeometryTypeFromString(NSString *geometryType);

/** Returns whether @p path intersects @p rectangle.
 @param path The input path that may or may not intersect rectangle.
 @param pathBBox The bounding box of @p path.
 @param rectangle The rectangle to test intersection relation.
 @return <code>YES</code> if @p path intersects @p rectangle.
 */
AGS_EXTERN BOOL AGSGeometryCGPathIntersectsRectangle(CGPathRef path, CGRect pathBBox, CGRect rectangle);

/** Returns a geometry converted from geographic to web mercator.
 @param geometry The geometry to convert to web mercator.
 @return An @c AGSGeometry object in web mercator.
 @since 1.0
 */
AGS_EXTERN AGSGeometry *AGSGeometryGeographicToWebMercator(AGSGeometry *geometry);

/** Returns a geometry converted from web mercator to geographic.
 @param geometry The geometry to convert to geographic.
 @return An @c AGSGeometry object in geographic.
 @since 1.0
 */
AGS_EXTERN AGSGeometry *AGSGeometryWebMercatorToGeographic(AGSGeometry *geometry);
	
/** Returns a mutable @c AGSGeometry from AGSGeometryType
 @param type The type of geometry to return.
 @param sr The spatial reference of the geometry to create.
 @return @c AGSGeometryType for @p geometry.
 @see AGSGeometryType
 */
AGS_EXTERN AGSGeometry *AGSMutableGeometryFromType(AGSGeometryType type, AGSSpatialReference *sr);
	