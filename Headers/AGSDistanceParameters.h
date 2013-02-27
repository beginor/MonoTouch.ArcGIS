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

@class AGSGeometry;

/** @file AGSDistanceParameters.h */ //Required for Globals API doc

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>distanceWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>distanceWithParameters:</code> operation. 
 
 @define{AGSDistanceParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSDistanceParameters : NSObject <AGSCoding>

/** Specifies the units for measuring distance between #geometry1 and #geometry2. 
 If the unit is not specified the units are derived from the spatial reference 
 of the input geometries.
 @since 1.0
 */
@property (nonatomic, assign) AGSSRUnit distanceUnit;

/** The geometry from which the distance is to measured. The geometry can be one 
 of the following geometry types: @c AGSPoint, @c AGSPolyline, @c AGSPolygon or 
 @c AGSMultipoint.
 @since 1.0
 */
@property (nonatomic, strong) AGSGeometry *geometry1;

/** The geometry to which the distance is measured. The geometry can be one of 
 the following geomtry types: @c AGSPoint, @c AGSPolyline, @c AGSPolygon or 
 @c AGSMultipoint.
 @since 1.0
 */
@property (nonatomic, strong) AGSGeometry *geometry2;

/** Default value is <code>false</code>. When <code>true</code> the geodesic 
 distance between #geometry1 and #geometry2 is measured.
 @since 1.0
 */
@property (nonatomic, assign) BOOL geodesic;

/** Returns an autoreleased instance of the distance parameters object.
 @since 1.0
 */
+ (id)distanceParameters;

@end