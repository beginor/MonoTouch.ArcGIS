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

@class AGSAreasAndLengthsParameters;
@class AGSLengthsParameters;

/** @file AGSGeometryServiceTask+AreasAndLengths.h  */ //Required for Globals API doc

@interface AGSGeometryServiceTask (AreasAndLengths)

/** Gets the area and length for each @c AGSPolygon in the array. The #delegate
 is notified when an operation completes successfully or encounters an error.
 @param areasAndLengthsParams Specifies the input polygons and ,optionally, the
 linear and areal units.
 @return <code>NSOperation</code> for current request.
 @since 1.0
 */
- (NSOperation *)areasAndLengthsWithParameters:(AGSAreasAndLengthsParameters *)areasAndLengthsParams;

/** Gets the length for each @c AGSPolyline in the array. The #delegate
 is notified when an operation completes successfully or encounters an error.
 @param lengthsParams Specifies the polylines and, optionally, the length unit
 and the geodesic length option.
 @return <code>NSOperation</code> for current request.
 @since 1.0
 */
- (NSOperation *)lengthsWithParameters:(AGSLengthsParameters *)lengthsParams;

@end
