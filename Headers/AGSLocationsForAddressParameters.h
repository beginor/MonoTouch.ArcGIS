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

#import <Foundation/Foundation.h>

@class AGSEnvelope;
@class AGSSpatialReference;
@class AGSPoint;

/**@brief Parameters of @c locationForAddresss operation on @c AGSLocator
 
 Specifies the location to be geocoded. This can be a street address, place name, postal code, or POI. It is a required parameter.
 
 @since 10.1.1
 */
@interface AGSLocationsForAddressParameters : NSObject

/** 
 A dictionary with key-value pairs of address field name and value. The address fields for a geocode service are listed in the Address Fields section of the ArcGIS Services Directory.
 
 The list of address fields for the @link AGSLocator::locator default locator @endlink  on ArcGIS Online are listed in <a target="_blank" href="http://resources.arcgis.com/en/help/arcgis-online-geocoding-rest-api/#/Multiple_input_field_geocoding/02q000000007000000//"> this </a> document.
 
@since 10.1.1
 */
@property (nonatomic, copy) NSDictionary *address;

/**
 A value representing the country. Providing this value increases geocoding speed.
 Acceptable values include the full country name, the ISO 3166-1 2-digit country code, or the ISO 3166-1 3-digit country code.
 
 The list of supported countries and codes for the @link AGSLocator::locator default locator @endlink  on ArcGIS Online are listed in <a target="_blank" href="http://resources.arcgis.com/en/help/arcgis-online-geocoding-rest-api/#/Service_coverage/02q000000005000000/"> this </a> document.
  
 If you want to use the current locale country code pass this: [[NSLocale currentLocale] objectForKey: NSLocaleCountryCode]
 
 <b>Note</b>, this feature is only available with the @link AGSLocator::locator default locator @endlink 
 @since 10.1.1
 */
@property (nonatomic, copy) NSString *sourceCountry;

/**
 A set of bounding box coordinates that limit the search area to a specific region. This is especially useful for applications in which a user will search for places and addresses within the current map extent. For example, in most mobile applications a user will want to search for places in the vicinity of their current GPS location; bbox can be used in this scenario.
 
 If the spatial reference is not specified on the extent, it is assumed to be same as that of the geocoding service.
 @since 10.1.1
 @avail{10.1}
 */
@property (nonatomic, retain) AGSEnvelope *searchExtent;

/**
 The spatial reference of the returned locations. If not specified, the coordinates
 of the returned locations will be in the same spatial reference as the geocoding service.
 @since 10.1.1
 */
@property (nonatomic, retain) AGSSpatialReference *outSpatialReference;

/**
 A list of candidate fields you want to be included in the returned results. If the address represents an
 intersection, you need to specify fields from the Intersection Candidate Fields section of the ArcGIS Services
 Directory. If the address does not represent an intersection, you need to specify fields from the Candidate Fields 
 section. For geocode services of ArcGIS Server 10 or above, you can specify "*" to get all the fields.
 
 The list of fields available for the @link AGSLocator::locator default locator @endlink  on ArcGIS Online are listed
 in <a target="_blank" href="http://resources.arcgis.com/en/help/arcgis-online-geocoding-rest-api/#/Service_output/02q000000009000000/"> this </a> document.
 @since 10.1.1
 */
@property (nonatomic, copy) NSArray *outFields;

/**
 Defines an origin point location that is used with the #distance parameter to sort geocoding candidates based upon their proximity to the location. The distance parameter specifies the radial distance from the location in meters. The priority of candidates within this radius is boosted relative to those outside the radius.
 
 This is useful in mobile applications where a user will want to search for places in the vicinity of their current GPS location; the location and distance parameters can be used in this scenario.
 
 The location parameter can be specified without specifying a distance. If distance is not specified, it defaults to 2000 meters.
 
 <b>Note</b>, this feature is only available with the @link AGSLocator::locator default locator @endlink.
 @since 10.1.1
 
 */
@property (nonatomic, retain) AGSPoint *location;

/**
 Specifies the distance in meters around the search #location to define a region that influences
 the candidates returned from a geocoding request. If this parameter is specified, #location
 parameter must also be specified. The value is interpreted to be in meters.
 
 <b>Note</b>, this feature is only available with the @link AGSLocator::locator default locator @endlink 
 @since 10.1.1
 */
@property (nonatomic, assign) CGFloat distance;

/** Encodes the parameters to JSON
 @since 10.1.1
 */
-(NSDictionary *)encodeToJSON;

@end
