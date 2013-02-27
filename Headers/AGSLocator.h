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
@protocol AGSLocatorDelegate;
@class AGSPoint;
@class AGSCredential;
@class AGSTask;
@class AGSAddressCandidate;
@class AGSLocationsForAddressParameters;
@class AGSLocatorFindParameters;

/** @file AGSLocator.h */ //Required for Globals API doc

/** @brief A locator to geocode and reverse-geocode addresses.
 
 An instance of this class allows you to geocode addresses and reverse-geocode locations using a remote geocoding service.  Geocoding involves finding matching locations for a given address. Reverse-geocoding is the opposite and involves finding corresponding addresses for a given location.
 
 The geocoding service could be hosted by ArcGIS Online or based on an ArcGIS Server ( For example, <a target="_blank" href="http://tasks.arcgisonline.com/ArcGIS/rest/services/Locators/ESRI_Places_World/GeocodeServer">http://tasks.arcgisonline.com/ArcGIS/rest/services/Locators/ESRI_Places_World/GeocodeServer</a>.

 
 The @link AGSLocator::locator default locator @endlink uses the <a target="_blank" href="http://resources.arcgis.com/en/help/arcgis-online-geocoding-rest-api/#/Overview_of_the_World_Geocoding_Service/02q000000008000000/">World Geocode Service</a> on ArcGIS Online. The service covers 100+ countries and is
 capable of finding locations based on street addresses, points of interest, 
 postal codes, x/y coordinates, place names, and more.
 
 @see @concept{Locator/00pw00000049000000/, Using a Locator}
 @see @sample{c1e9abdacf524c2f99d39fbac14b3e0d, Geocoding}
 @since 1.0
 
 */
@interface AGSLocator : AGSTask

/** Delegate to be notified when the locator completes successfully or
 encounters an error.
 @since 1.0
 */
@property (nonatomic, weak) id<AGSLocatorDelegate> delegate;

/** Initializes a default locator that uses the <a target="_blank" href="http://resources.arcgis.com/en/help/arcgis-online-geocoding-rest-api/#/Overview_of_the_World_Geocoding_Service/02q000000008000000/">World Geocode Service</a> on ArcGIS Online. The service covers 100+ countries and is
 capable of finding locations based on street addresses, points of interest,
 postal codes, x/y coordinates, place names, and more.

 @since 10.1.1
 @see @c #findWithParameters: 
 */
+(id)locator;

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
 @see @c AGSLocatorDelegate#locator:operation:didFindAddressForLocation: , method on delegate for success
 @see @c AGSLocatorDelegate#locator:operation:didFailAddressForLocation: , method on delegate for failure
 */
- (NSOperation *)addressForLocation:(AGSPoint *)location maxSearchDistance:(double)distance;

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
 @see @c AGSLocatorDelegate#locator:operation:didFindAddressForLocation: , method on delegate for success
 @see @c AGSLocatorDelegate#locator:operation:didFailAddressForLocation: , method on delegate for failure
 */
- (NSOperation *)addressForLocation:(AGSPoint *)location maxSearchDistance:(double)distance outSpatialReference:(AGSSpatialReference*)sr;

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
 @see @c AGSLocatorDelegate#locator:operation:didFindLocationsForAddress: , method on delegate for success
 @see @c AGSLocatorDelegate#locator:operation:didFailLocationsForAddress: , method on delegate for failure
 */
- (NSOperation *)locationsForAddress:(NSDictionary *)address returnFields:(NSArray *)outFields;

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
 @see @c AGSLocatorDelegate#locator:operation:didFindLocationsForAddress: , method on delegate for success
 @see @c AGSLocatorDelegate#locator:operation:didFailLocationsForAddress: , method on delegate for failure
 */
- (NSOperation *)locationsForAddress:(NSDictionary *)address returnFields:(NSArray *)outFields outSpatialReference:(AGSSpatialReference*)sr;

/** Executes a geocoding operation to find location candidates for a given
 address. The @c #delegate will be notified when the operation completes or if
 an error is encountered.
 
 This method is functionally equivalent to #locationsForAddress:returnFields:
 #locationsForAddress:returnFields:outSpatialReference: , but its parameters provide a few more options
 for narrowing down the results.
 @param params Parameters for performing the operation
 @since 10.1.1
 @see @c AGSLocatorDelegate#locator:operation:didFindLocationsForAddress: , method on delegate for success
 @see @c AGSLocatorDelegate#locator:operation:didFailLocationsForAddress: , method on delegate for failure
 */
-(NSOperation *)locationsForAddressWithParameters:(AGSLocationsForAddressParameters*)params;

/** Executes a geocoding operation to find location candidates for various types of inputs -
 @li address <i>(380 New York St Redlands CA)</i>
 @li point of interest <i>(Disneyland, bank in paris, los angeles starbucks, mount everest)</i>
 @li administrative place name <i>(Seattle Washington)</i>
 @li postal code <i>(90201 USA)</i>
 @li X/Y coordinates <i>(-117.155579,32.703761)</i>
 
 The @c #delegate will be notified when the operation completes or if
 an error is encountered.
 
 <b>Note</b>, this operation is only applicable to the @link AGSLocator::locator default locator @endlink at this time.
 @param findParams Parameters for performing the operation
 @since 10.1.1
 @see @c AGSLocatorDelegate#locator:operation:didFind: , method on delegate for success
 @see @c AGSLocatorDelegate#locator:operation:didFailToFindWithError: , method on delegate for failure

 */
-(NSOperation*)findWithParameters:(AGSLocatorFindParameters*)findParams;

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
 for the operation AGSLocator#locationsForAddresss:returnFields:
 @param locator The locator called to find locations.
 @param op <code>NSOperation</code> that performed the locate task.
 @param candidates Array of @c AGSAddressCandidate objects.
 @since 1.0
 */
- (void)locator:(AGSLocator *)locator operation:(NSOperation*)op didFindLocationsForAddress:(NSArray *)candidates;

/** Tells the delegate that @c AGSLocator encountered an error while finding 
 matching locations for the operation AGSLocator#locationsForAddresss:returnFields:
 @param locator The locator called to find locations.
 @param op <code>NSOperation</code> that performed the locate task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)locator:(AGSLocator *)locator operation:(NSOperation*)op didFailLocationsForAddress:(NSError *)error;

/** Tells the delegate that @c AGSLocator completed finding an address candidate 
for the operation AGSLocator#addressForLocation:maxSearchDistance:
 @param locator The locator called to find address candidate.
 @param op <code>NSOperation</code> that performed the locate task.
 @param candidate The address candidate for specified location.
 @since 1.0
 */
- (void)locator:(AGSLocator *)locator operation:(NSOperation*)op didFindAddressForLocation:(AGSAddressCandidate *)candidate;

/** Tells the delegate that @c AGSLocator encountered an error while finding an 
 address candidate for the operation AGSLocator#addressForLocation:maxSearchDistance:
 @param locator The locator called to find address candidates.
 @param op <code>NSOperation</code> that performed the locate task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)locator:(AGSLocator *)locator operation:(NSOperation*)op didFailAddressForLocation:(NSError *)error;

/** Tells the delegate that @c AGSLocator found locations for the operation @c AGSLocator#findWithParameters:
 @param locator The locator called to find address candidates.
 @param op <code>NSOperation</code> that performed the task.
 @param results An array of @c AGSLocatorFindResult objects
 @since 10.1.1
 */
-(void)locator:(AGSLocator*)locator operation:(NSOperation*)op didFind:(NSArray*)results;

/** Tells the delegate that @c AGSLocator encountered an error for the operation @c AGSLocator#findWithParameters:
 @param locator The locator called to find address candidates.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the error returned by the service.
 @since 10.1.1
 */
-(void)locator:(AGSLocator*)locator operation:(NSOperation*)op didFailToFindWithError:(NSError*)error;

@end
