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

/** @file AGSSpatialReference.h */ //Required for Globals API doc

@class AGSSpatialReference;

/** The WKID for WGS 84.
 @since 1.0
 */
#define WKID_WGS84 4326

/** The WKID for World Cylindrical Equal Area.
 @since 1.0
 */
#define WKID_EQUAL_AREA 54034

// "web mercator" wkids, considered mathematically equivalent

/** The WKID for WGS 1984 Web Mercator (102113). It was added at 9.3, deprecated 
 in favor of 3857 (added at 10.0).
 @since 1.0
 */
#define WKID_WGS_1984_WEB_MERCATOR 102113 

/** The WKID for WGS 1984 Web Mercator Auxiliary Sphere (102100).
 @since 1.0
 */
#define WKID_WGS_1984_WEB_MERCATOR_AUXILIARY_SPHERE 102100 

/** The WKID for Popular Visualisation CRS Mercator (3785). It was deprecated
 by EPSG in favor of 3857.
 @since 1.0
 */
#define WKID_POPULAR_VISUALISATION_CRS_MERCATOR 3785

/** The WKID for WGS 1984 Web Mercator Auxiliary Sphere starting at ArcGIS 10.0.
 
 @avail{10.0}
 @since 1.0
 */
#define WKID_WGS_1984_WEB_MERCATOR_AUXILIARY_SPHERE_10 3857

/** Get string representation of @p unit.
 @param unit The unit type to return as a string.
 @return String representation of @c AGSUnits.
 @see AGSUnits
 @since 1.0
 */
AGS_EXTERN NSString *AGSUnitsString(AGSUnits unit);

/** Get @c AGSUnits from string representation. For example, "esriMeters"
 would return <code>AGSUnitsMeters</code>.
 @param unit The string representation of unit to be converted.
 @return @c AGSUnits from string.
 @see AGSUnits
 @since 1.0
 */
AGS_EXTERN AGSUnits AGSUnitsFromString(NSString *unit);

/** Converts @p val from one unit to another.
 @param val The value to be converted.
 @param fromUnits The units of @p val.
 @param toUnits The units @p val is to be converted to.
 @return @p val in units specified by @p toUnits.
 @since 1.0
 */
AGS_EXTERN double AGSUnitsToUnits(double val, AGSUnits fromUnits, AGSUnits toUnits);

/** Get the display string for @c AGSUnits.
 @param unit The unit type to return as a string.
 @return Display string of @p unit.
 @since 1.0
 */
AGS_EXTERN NSString *AGSUnitsDisplayString(AGSUnits unit);

/** Get the abbreviated string for @c AGSUnits.
 For example, <code>AGSUnitsMeters</code> would return "m".
 @param unit The unit type to return as a string.
 @return Abbreviated string of @p unit.
 @since 1.0
 */
AGS_EXTERN NSString *AGSUnitsAbbreviatedString(AGSUnits unit);

/** Get the AGSUnits of the given spatial reference.
 @param sr The spatial reference to return units for.
 @return the AGSUnits of the spatial reference.
 @since 2.2
 */
AGS_EXTERN AGSUnits AGSUnitsFromSpatialReference(AGSSpatialReference* sr);

/** Get @c AGSAreaUnits from string representation. For example, "esriSquareKilometers"
 would return <code>AGSAreaUnitsSquareKilometers</code>.
 @param unit The string representation of @p unit.
 @return @c AGSAreaUnits from string.
 @since 1.0
 */
AGS_EXTERN AGSAreaUnits AGSAreaUnitsFromString(NSString *unit);

/** Converts @p val from one unit to another.
 @param val The value to be converted.
 @param fromUnits The initial units of @p val.
 @param toUnits The units @p val is to be converted to.
 @return @p val in the units specified by @p toUnits.
 @since 1.0
 */
AGS_EXTERN double AGSAreaUnitsToAreaUnits(double val, AGSAreaUnits fromUnits, AGSAreaUnits toUnits);

/** Get the display string for @c AGSAreaUnits.
 @param unit The unit type to return as a string.
 @return Display string of @p unit.
 @since 1.0
 */
AGS_EXTERN NSString *AGSAreaUnitsDisplayString(AGSAreaUnits unit);

/** Get the abbreviated string for @c AGSAreaUnits.
 For example, <code>AGSAreaUnitsSquareKilometers</code> would return "sq. km".
 @param unit The unit type to return as an abbreviated string.
 @return Abbreviated string of @p unit.
 @since 1.0
 */
AGS_EXTERN NSString *AGSAreaUnitsAbbreviatedString(AGSAreaUnits unit);

/** Get string representation of the area unit.
 @param unit The unit type to return as a string.
 @return String representation of @c AGSAreaUnits.
 @since 1.0
 */
AGS_EXTERN NSString *AGSAreaUnitsString(AGSAreaUnits unit);

/** Get @c AGSAreaUnits from string representation.
 @param unit The string representation of @p unit.
 @return @c AGSAreaUnits from string.
 @since 1.0
 */
AGS_EXTERN AGSAreaUnits AGSAreaUnitsFromString(NSString *unit);

/** @brief A spatial reference object.
 
 Instances of this class represent a spatial reference. Each spatial reference 
 can be represented by either a well-known ID (@p wkid), or a well-known text 
 (@p wkt). Spatial References define the spatial properties of a geometry, for 
 instance the coordinate system it uses. There are 2 broad classes of coordinate 
 systems - Geographic & Projected. A Geographic Coordinate system uses a 
 3-dimensional spherical surface to define locations on the earth. A Projected 
 Coordinate system on the other hand uses a flat, 2-dimensional surface. More 
 information about spatial references and coordinate systems is available
 <a href="http://help.arcgis.com/en/arcgisdesktop/10.0/help/index.html#/What_are_map_projections/003r00000001000000/">here</a>. 
 
 It is very important to associate spatial data, such as geometry objects, with 
 corresponding spatial references.
 
 @define{AGSSpatialReference.h, ArcGIS}
 @since 1.0
 
 */
@interface AGSSpatialReference : NSObject <AGSCoding, NSCopying> {}

/** The well-known ID of the spatial reference.
 @since 1.0
 */
@property (nonatomic, readonly) NSUInteger wkid;

/** The well-known text of the spatial reference.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *wkt;

/** Initialize a spatial reference with @p wkid.
 @param wkid The well-known ID to initialize the spatial reference with.
 @since 1.0
 */
-(id)initWithWKID:(NSUInteger)wkid;

/** Initialize a spatial reference with @p wkt.
 @param wkt The well-known text to initialize the spatial reference with.
 @since 1.0
 */
-(id)initWithWKT:(NSString *)wkt;

/** Initialize an autoreleased spatial reference with @p wkid.
 @param wkid The well-known ID to initialize the spatial reference with.
 @since 1.0
 */
+(id)spatialReferenceWithWKID:(NSUInteger)wkid;

/** Initialize an autoreleased spatial reference with @p wkt.
 @param wkt The well-known text to initialize the spatial reference with.
 @since 1.0
 */
+(id)spatialReferenceWithWKT:(NSString *)wkt;

/** Initialize spatial reference with well-known ID and text. 
 This is the designated initializer.
 @param wkid The well-known ID.
 @param wkt The well-known text.
 @return A new spatial reference object.
 @since 1.0
 */
- (id)initWithWKID:(NSUInteger)wkid WKT:(NSString *)wkt;

/** Create new autoreleased spatial reference object.
 @param wkid The well-known ID.
 @param wkt The well-known text.
 @return A new spatial reference object.
 @since 1.0
 */
+ (id)spatialReferenceWithWKID:(NSUInteger)wkid WKT:(NSString *)wkt;

/** Returns <code>YES</code> if @p wkid equals any of the "web mercator" projections.
 @since 1.0
 */
- (BOOL) isAnyWebMercator;

/** Returns <code>YES</code> if @p wkid equals 4326.
 @since 1.0
 */
- (BOOL) isWGS84;

/** Returns <code>YES</code> if spatial references are both web mercator. If not, it 
 will return <code>YES</code> if @p wkid or @p wkt are equal.
 @param sr The AGSSpatialReference to be compared.
 @since 1.0
 */
- (BOOL) isEqualToSpatialReference: (AGSSpatialReference *)sr;


/** Returns <code>YES</code> if spatial reference and wkid are both web mercator.
 If not, it will return <code>YES</code> if @p wkid is equal.
 @param wkid The well-known ID to be compared.
 @since 2.2
 */
- (BOOL) isEqualToWKID:(NSUInteger)wkid;

/** Encodes spatial reference to @p json conditionally based on existence of a wkt
 @param json The dictionary to encode spatial reference to.
 @param key The encoded spatial reference is paired with.
 @since 1.0
 */
- (void)encodeToJSON:(NSMutableDictionary*)json forKey:(NSString*)key;

/** The units that the spatial reference coordinates are in.
 @since 1.8
 */
-(AGSSRUnit)unit;

/** Returns a spatial reference object in web mercator.
 @since 1.8
 */
+(AGSSpatialReference*)webMercatorSpatialReference;

/** Returns a spatial reference object in WGS84 (4326).
 @since 1.8
 */
+(AGSSpatialReference*)wgs84SpatialReference;

/** Converts the value in the same unit as the current spatial
 reference to a specified unit. Will return nan if trying to convert
 between angular and linear units, for example, Decimal Degrees and Meters.
 @param val The value to convert.
 @param unit The unit to convert to.
 @return The converted value.
 @since 1.8
 */
-(double)convertValue:(double)val toUnit:(AGSSRUnit)unit;

/** Converts the value from a specified unit to the same unit as the current spatial
 reference. Will return nan if trying to convert
 between angular and linear units, for example, Decimal Degrees and Meters.
 @param val The value to convert.
 @param fromUnit The unit to convert from.
 @return The converted value.
 @since 1.8
 */
-(double)convertValue:(double)val fromUnit:(AGSSRUnit)fromUnit;

/** Returns <code>YES</code> if the spatial reference's wkid or wkt is supported by the
 the @c AGSGeometryEngine
 @since 10.1.1
 */
-(BOOL)isSupported;

@end
