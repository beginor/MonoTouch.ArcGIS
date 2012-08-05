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
@protocol AGSLocatorDelegate;
@class AGSPoint;
@class AGSCredential;
@class AGSTask;

/** @file AGSLocator.h */ //Required for Globals API doc

/** @brief A locator to geocode and reverse-geocode addresses.
 
 An instance of this class allows you to geocode and reverse-geocode addresses 
 using a geocode service of ArcGIS Server. For example, <a href="http://tasks.arcgisonline.com/ArcGIS/rest/services/Locators/ESRI_Places_World/GeocodeServer">http://tasks.arcgisonline.com/ArcGIS/rest/services/Locators/ESRI_Places_World/GeocodeServer</a>.
 
 Geocoding involves finding matching locations for a given address. 
 Reverse-geocoding involves finding corresponding addresses for a given location.
 
 @see @concept{Locator/00pw00000049000000/, Using a Locator}
 @see @sample{c1e9abdacf524c2f99d39fbac14b3e0d, Geocoding}
 @since 1.0
 
 */
@interface AGSLocator : AGSTask {
 @private
    id<AGSLocatorDelegate> _delegate;
}

/** Delegate to be notified when the locator completes successfully or 
 encounters an error.
 @since 1.0
 */
@property (nonatomic, assign) id<AGSLocatorDelegate> delegate;

/** Initialize autoreleased Locator.
 @param url URL to a geocode service.
 @return A new, autoreleased, locator object
 @since 1.0
 */
+ (id)locatorWithURL:(NSURL *)url;

/** Initialize autoreleased Locator.
 @param url URL to a geocode service.
 @param cred <code>AGSCredential</code> to access a secure locator.
 @return A new, autoreleased, locator object.
 @since 1.0
 */
+ (id)locatorWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Executes a geocoding operation to find location candidates for a given 
 address. The @c #delegate will be notified when the operation completes or if 
 an error is encountered.
 
 It relies on the <i>Find Address Candidates</i> operation
 of the REST resource.
 
 @param address A dictionary with key-value pairs of address field name and 
 value. The address fields for a geocode service resource are listed in the 
 <i>Address Fields</i> section of the Services Directory.
 @param outFields A list of candidate fields you want to be included in the 
 returned results. If the address represents an intersection, you need to 
 specify fields from the <i>Intersection Candidate Fields</i> section of the 
 Services Directory. If the address does not represent an intersection, you need 
 to specify fields from the <i>Candidate Fields</i> section. For geocode 
 services of ArcGIS Server 10 or above, you can specify "*" to get all the 
 fields.
 @return <code>NSOperation</code> for current operation.
 @since 1.0
 @see AGSLocatorDelegate
 */
- (NSOperation *)locationsForAddress:(NSDictionary *)address returnFields:(NSArray *)outFields;

/** Executes a reverse-geocoding operation to find address candidates for a 
 given location. The @c #delegate will be notified when the operation completes 
 or if an error is encountered..
 
 It relies on the <i>Reverse Geocode</i> operation
 of the REST resource.
 
 @param location Location to search for address candidates. If the @c AGSPoint does 
 not have a spatial reference, it is assumed to be in the same spatial reference 
 as that of the geocode service.
 @param distance Distance in meters from the given location within which a matching 
 address should be searched. If this parameter is not provided or an invalid 
 value is provided, a default value of 0 meters is used.
 @return <code>NSOperation</code> for current request.
 @since 1.0
 @see AGSLocatorDelegate
 */
- (NSOperation *)addressForLocation:(AGSPoint *)location maxSearchDistance:(double)distance;

/** Executes a geocoding operation to find location candidates for a given 
 address. The @c #delegate will be notified when the operation completes or if 
 an error is encountered.
 
 It relies on the <i>Find Address Candidates</i> operation
 of the REST resource.
 
 
 @param address Dictionary with key-value pairs of address field name and 
 value. The address fields for a geocode service resource are listed in the 
 <i>Address Fields</i> section of the Services Directory.
 @param outFields List of candidate fields you want to be included in the 
 returned results. If the address represents an intersection, you need to 
 specify fields from the <i>Intersection Candidate Fields</i> section of the 
 Services Directory. If the address does not represent an intersection, you need 
 to specify fields from the <i>Candidate Fields</i> section. For geocode 
 services of ArcGIS Server 10 or above, you can specify "*" to get all the 
 fields.
 @param sr Spatial reference of output geometries.
 @return <code>NSOperation</code> for current operation.
 @avail{10.0}
 @since 1.0
 @see AGSLocatorDelegate
 */
- (NSOperation *)locationsForAddress:(NSDictionary *)address returnFields:(NSArray *)outFields outSpatialReference:(AGSSpatialReference*)sr;

/** Executes a reverse-geocoding operation to find address candidates for a 
 given location. The @c #delegate will be notified when the operation completes 
 or if an error is encountered.
 
 It relies on the <i>Reverse Geocode</i> operation
 of the REST resource.
 
 @param location Location to search for address candidates. If the @c AGSPoint does 
 not have a spatial reference, it is assumed to be in the same spatial reference 
 as that of the geocode service.
 @param distance Distance in meters from the given location within which a matching 
 address should be searched. If this parameter is not provided or an invalid 
 value is provided, a default value of 0 meters is used.
 @param sr Spatial reference of output geometries.
 @return <code>NSOperation</code> for current request.
 @avail{10.0}
 @since 1.0
 @see AGSLocatorDelegate
 */
- (NSOperation *)addressForLocation:(AGSPoint *)location maxSearchDistance:(double)distance outSpatialReference:(AGSSpatialReference*)sr;
@end



#pragma mark -

/** @brief Represents an address and its location.
 
 Instances of this class represent results returned by @c AGSLocator for 
 geocoding and reverse-geocoding operations. Each result is an address 
 candidate.
 
 @define{AGSLocator.h, ArcGIS}
 @since 1.0
 */
@interface AGSAddressCandidate : NSObject <AGSCoding> {
 @private
    NSString *_addressString;
    NSDictionary *_address;
    NSDictionary *_attributes;
    AGSPoint *_location;
    double _score;
}

/** A single line address of the candidate, if available.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSString *addressString;

/** Address of the candidate. The dictionary contains a key-value pair for each 
 address field defined by the geocode service. Each address field describes some 
 part of the address information for the candidate.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSDictionary *address;

/** A dictionary containing key-value pairs of address field name and value as 
 requested in the @p returnFields argument of 
 <code>locationsForAddress:returnFields:</code> on @c AGSLocator.  
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSDictionary *attributes;

/** x,y coordinates of the candidate.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSPoint *location;

/** Numeric score between 0 and 100 for the candidate. A score of 100 means a 
 perfect match, and 0 means no match.
 @since 1.0
 */
@property (nonatomic, readonly) double score;

@end



#pragma mark -

/** @brief A delegate of @c AGSLocator.
 
 A protocol which must be adopted by any class wishing to be notified when 
 @c AGSLocator completes successfully or encounters an error. An instance of the 
 class must then be set as the delegate of @c AGSLocator.

 @define{AGSLocator.h, ArcGIS}
 @since 1.0
 */
@protocol AGSLocatorDelegate <NSObject>

@optional

/** Tells the delegate that @c AGSLocator completed finding matching locations 
 with the provided results.
 @param locator The locator called to find locations.
 @param op <code>NSOperation</code> that performed the locate task.
 @param candidates Array of @c AGSAddressCandidate objects.
 @since 1.0
 */
- (void)locator:(AGSLocator *)locator operation:(NSOperation*)op didFindLocationsForAddress:(NSArray *)candidates;

/** Tells the delegate that @c AGSLocator encountered an error while finding 
 matching locations.
 @param locator The locator called to find locations.
 @param op <code>NSOperation</code> that performed the locate task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)locator:(AGSLocator *)locator operation:(NSOperation*)op didFailLocationsForAddress:(NSError *)error;

/** Tells the delegate that @c AGSLocator completed finding an address candidate 
 with the provided result.
 @param locator The locator called to find address candidate.
 @param op <code>NSOperation</code> that performed the locate task.
 @param candidate The address candidate for specified location.
 @since 1.0
 */
- (void)locator:(AGSLocator *)locator operation:(NSOperation*)op didFindAddressForLocation:(AGSAddressCandidate *)candidate;

/** Tells the delegate that @c AGSLocator encountered an error while finding an 
 address candidate.
 @param locator The locator called to find address candidates.
 @param op <code>NSOperation</code> that performed the locate task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)locator:(AGSLocator *)locator operation:(NSOperation*)op didFailAddressForLocation:(NSError *)error;

@end
