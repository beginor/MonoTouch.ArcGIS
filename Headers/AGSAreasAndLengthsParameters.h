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


/** @file AGSAreasAndLengthsParameters.h */ //Required for Globals API doc

/** @brief Parameters for computing areas and lengths 
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>areasAndLengthsWithParameters:</code> operation. 
 
 @define{AGSAreasAndLengthsParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSAreasAndLengthsParameters : NSObject <AGSCoding>

/** The array of @c AGSPolygon objects whose areas and lengths are to be computed.
 @since 1.0
 */
@property (nonatomic, copy) NSArray *polygons;

/** The length unit in which perimeters of polygons will be calculated. 
 It can be any @c AGSSRUnit constant. If <code>lengthUnit</code> is not specified,
 the units are derived from the spatial reference of the input polygons.
 
 Possible value:
 
 For a complete list, see @c AGSSRUnit
 @since 1.0
 @see AGSSRUnit
 */
@property (nonatomic, assign) AGSSRUnit lengthUnit;

/** The area unit in which areas of polygons will be calculated. It can be any 
 @c AGSAreaUnits constant. If unit is not specified, the units are derived from sr.
 
 Possible values:
 
 @li @c AGSAreaUnitsSquareInches
 @li @c AGSAreaUnitsSquareFeet
 @li @c AGSAreaUnitsSquareYards
 @li @c AGSAreaUnitsAcres
 @li @c AGSAreaUnitsSquareMiles
 @li @c AGSAreaUnitsSquareMillimeters
 @li @c AGSAreaUnitsSquareCentimeters
 @li @c AGSAreaUnitsSquareDecimeters
 @li @c AGSAreaUnitsSquareMeters
 @li @c AGSAreaUnitsAres
 @li @c AGSAreaUnitsHectares
 @li @c AGSAreaUnitsSquareKilometers
 
 @since 1.0
 @see AGSAreaUnits
 */
@property (nonatomic, assign) AGSAreaUnits areaUnit;

/** Initialize an autoreleased <code>AGSAreasAndLengthsParameters</code> object.
 @since 1.0
 */
+ (id)areasAndLengthsParameters;

@end