/*
 COPYRIGHT 2010 ESRI
 
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

@class AGSCredential;
@class AGSGeometry;
@class AGSEnvelope;
@class AGSSpatialReference;
@class AGSTileInfo;
@class AGSTimeInfo;
@protocol AGSSecuredResource;
@protocol AGSMapServiceInfoDelegate;

/** @file AGSMapServiceInfo.h */ //Required for Globals API doc

#pragma mark -

/** @brief Information about an ArcGIS Server map service.
 
 Instances of this class represent information about an ArcGIS Server map service.
 
 @define{AGSMapServiceInfo.h, ArcGIS}
 @since 1.0
 */
@interface AGSMapServiceInfo : NSObject <AGSCoding, AGSSecuredResource>

/** URL of a map service resource in ArcGIS Server REST Services Directory.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSURL *URL;

/** Copyright text as defined by the map service.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *copyright;

/** Map description as defined by the map service.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** The version of the server.
 @since 1.8
 */
@property (nonatomic, assign, readonly) CGFloat version;

/** The units the map service is in. Possible values include 
 
 @li @c AGSUnitsCentimeters 
 @li @c AGSUnitsDecimalDegrees
 @li @c AGSUnitsDecimeters
 @li @c AGSUnitsFeet
 @li @c AGSUnitsInches
 @li @c AGSUnitsKilometers
 @li @c AGSUnitsMeters
 @li @c AGSUnitsMiles
 @li @c AGSUnitsMillimeters
 @li @c AGSUnitsNauticalMiles
 @li @c AGSUnitsPoints
 @li @c AGSUnitsUnknown
 @li @c AGSUnitsYards
 
 @since 1.0
 */
@property (nonatomic, assign, readonly) AGSUnits units;

/** Available layers in the map service and their default visibility as an array of 
 @c AGSMapServiceLayerInfo objects.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *layerInfos;

/** The spatial reference of the map service.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Full extent of the map service.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSEnvelope *fullEnvelope;

/** Initial extent of the map service.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSEnvelope *initialEnvelope;

/** Tiling scheme of the map service. Only applicable if the map service is cached.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSTileInfo *tileInfo;

/** Indicates whether the map service is cached.
 @since 1.0
 */
@property (nonatomic, assign, readonly) BOOL singleFusedMapCache;

/** Credential used to access a secured resource
 @since 1.0
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource. By default this will be set to the global cache.
 @since 10.1.1
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

/** Time information for the layer, such as start time field, end time field, 
 track id field, layers time extent and the draw time interval. Only applicable 
 if the layer is time aware.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSTimeInfo *timeInfo;

/** The delegate that is notified when asynchronous operations for this map service info complete.
 @since 1.8
 */
@property (nonatomic, weak) id<AGSMapServiceInfoDelegate> delegate;

/** Available tables in the map service as an array of 
 @c AGSMapServiceTableInfo objects.
 @since 1.8
 */
@property (nonatomic, strong, readonly) NSArray *tableInfos;

/** The minimum scale at which this layer is visible. If the map is zoomed out
 beyond this scale, the layer will not be visible.
 @since 10.1.1
 */
@property (nonatomic, readonly) double minScale;

/** The maximum scale at which this layer is visible. If the map is zoomed in
 beyond this scale, the layer will not be visible.
 @since 10.1.1
 */
@property (nonatomic, readonly) double maxScale;

/** Initialize with URL to an ArcGIS Server map service. This will synchronously 
 request the service info from the URL.
 NOTE: The AGSCredentialCache can not be used with synchronous methods.
 @param url URL pointing to a map service.
 @param error Information returned in the event the object could not be initialized.
 @return A new map service info object.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url error:(NSError**)error;

/** Initialize autoreleased map service info with URL to an ArcGIS Server map service.
 This will synchronously request the service info from the URL.
 NOTE: The AGSCredentialCache can not be used with synchronous methods.
 @param url URL pointing to a map service.
 @param error Information returned in the event the object could not be initialized.
 @return A new, autoreleased, map service info object.
 @since 1.0
 */
+ (id)mapServiceInfoWithURL:(NSURL *)url error:(NSError**)error;

/** Initialize with URL to an ArcGIS Server map service. This will synchronously request the 
 service info from the URL.
 NOTE: The AGSCredentialCache can not be used with synchronous methods.
 @param url URL pointing to a map service. 
 @param cred @c AGSCredential used to access secure service.
 @param error Information returned in the event the object could not be initialized.
 @return A new map service info object.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url credential:(AGSCredential*)cred error:(NSError**)error;

/** Initialize autoreleased map service info with URL to an ArcGIS Server map service.
 This will synchronously request the service info from the URL.
 NOTE: The AGSCredentialCache can not be used with synchronous methods.
 @param url URL pointing to a map service.
 @param cred @c AGSCredential used to access secure service.
 @param error Information returned in the event the object could not be initialized.
 @return A new, autoreleased, map service info object.
 @since 1.0
 */
+ (id)mapServiceInfoWithURL:(NSURL *)url credential:(AGSCredential*)cred error:(NSError**)error;

/** For completeness, this is to be used when you have a raw dictionary from
 the REST endpoint.
 @param json The JSON dictionary to initialize the map service info.
 @param url URL to initialize the map service info.
 @param credential @c AGSCredential used to access secure service.
 @return A new, autoreleased, map service info object.
 @since 2.0
 */
- (id)initWithJSON:(NSDictionary *)json URL:(NSURL*)url credential:(AGSCredential*)credential;

/** Asynchronously retrieves the legend information for all the layer infos. The @c #delegate is
 informed when the operation completes successfully or encounters an error. 
 @avail{10 Service Pack 1}
 @since 1.8
 @see @concept{Map_Legend/00pw00000053000000/, Displaying Map Legend}
 @see @sample{901ca5cbcc6e4fe9bee960136c5971ba, Legend}
 */
-(NSOperation*)retrieveLegendInfo;

@end


/** @brief A delegate of @c AGSMapServiceInfo
 
 A protocol to implement if you want to be notified when an AGSMapServiceInfo completes operations.
 @since 1.8
 */
@protocol AGSMapServiceInfoDelegate <NSObject>

@optional

/** Tells the delegate that @c AGSMapServiceInfo completed retrieving legend info.
 The legend info is available on each individual @c AGSMapServiceLayerInfo objects of @c AGSMapServiceInfo 
 @param mapServiceInfo The @c AGSMapServiceInfo called to retrieve the legend.
 @param op <code>NSOperation</code> that performed the locate task.
 @since 1.8
 */
- (void)mapServiceInfo:(AGSMapServiceInfo *)mapServiceInfo operationDidRetrieveLegendInfo:(NSOperation*)op;

/** Tells the delegate that @c AGSMapServiceInfo failed to retrieve legend info.
 @param mapServiceInfo The @c AGSMapServiceInfo called to retrieve the legend.
 @param op <code>NSOperation</code> that performed the locate task.
 @param error The error that occurred that caused the failure.
 @since 1.8
 */
- (void)mapServiceInfo:(AGSMapServiceInfo *)mapServiceInfo operation:(NSOperation*)op didFailToRetrieveLegendInfoWithError:(NSError*)error;
@end
