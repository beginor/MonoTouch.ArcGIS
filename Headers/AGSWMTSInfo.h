/*
 COPYRIGHT 2012 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and 
 Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */



@class AGSWMTSLayerInfo;
@class AGSWMTSLayer;
@protocol AGSSecuredResource;
@protocol AGSWMTSInfoDelegate;

/** @file AGSWMTSInfo.h */ //Required for Globals API doc


/** @brief A class to facilitate the creation of an @AGSWMTSLayer from a WMTS Server map service

 An instance of this class allows you to interact with a WMTS map service
 and create a layer from one of the tile sets provided by the service. When
 instantiated with a URL to a WMTS map service, an object of this class
 will issue a GetCapabilities request to the server, and report the layer 
 options in its layerInfos property. Using one of these
 @c AGSWMTSLayerInfo objects one can create the desired layer.
 
 @define{AGSWMTSInfo.h, ArcGIS}
 @since 10.1.1
*/
@interface AGSWMTSInfo : NSObject <AGSSecuredResource>

/** The delegate of the class.
 @since 10.1.1
*/
@property (nonatomic, weak) id <AGSWMTSInfoDelegate> delegate;

/** An array of @c AGSWMTSLayerInfo objects, each one representing
 the information for a different layer provided by a WMTS service.
 @since 10.1.1
*/
@property (nonatomic, copy, readonly) NSArray *layerInfos;

/** The credential to be used to access the secured map service.
 @since 10.1.1
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource. By default this will be set to the global cache.
 @since 10.1.1
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

/** The URL for the WMTS map service
@since 10.1.1
*/
@property (nonatomic, copy, readonly) NSURL *URL;

/** Initializes an @c AGSWMTSInfo object with a URL of a WMTS service.
 @param url URL to a WMTS service.
 @return A new @c AGSWMTSInfo object.
 @since 10.1.1
*/
- (id)initWithURL:(NSURL*)url;

/** Initializes an @c AGSWMTSInfo object with a URL of a WMTS service,
 as well as a credential to a secured resource.
 @param url URL to a WMTS service.
 @param credential @c AGSCredential to access a secured resource.
 @return A new @c AGSWMTSInfo object.
 @since 10.1.1
 */
- (id)initWithURL:(NSURL *)url credential:(AGSCredential*)credential;

/** A method to get an initialized, autoreleased @c AGSWMTSInfo with a URL of a WMTS map service.
 @param url URL to a WMTS map service.
 @return A new autoreleased @c AGSWMTSInfo object.
 @since 10.1.1
 */
+ (id)wmtsInfoWithURL:(NSURL*)url;

/** A method to get an initialized, autoreleased @c AGSWMTSInfo with a URL of a WMTS map service,
 as well as a credential to a secured resource.
 @param url URL to a WMTS map service.
 @param credential @c AGSCredential to access a secured resource.
 @return A new autoreleased @c AGSWMTSInfo object.
 @since 10.1.1
 */
+ (id)wmtsInfoWithURL:(NSURL *)url credential:(AGSCredential*)credential;


/** A method to get an initialized, autoreleased @c AGSWMTSLayer.
 @param layerInfo @c AGSWMTSLayerInfo object used to create an @c AGSWMTSLayer object.
 @param sr @c AGSSpatialReference desired for the layer, if this parameter is nil
        a WMTSLayer will be returned in the first spatial reference found.
 @return A new autoreleased @c AGSWMTSLayer.
 @since 10.1.1
 */
- (AGSWMTSLayer*)wmtsLayerWithLayerInfo:(AGSWMTSLayerInfo*)layerInfo andSpatialReference:(AGSSpatialReference *)sr;
@end

/** @brief A protocol that must be adopted in order create an @AGSWMTSLayer
 
 This protocol allows one to be informed when the @c AGSWMTSInfo object has
 completed extracting the layer information from a GetCapabilities request
 to a WMTS service.
 
 @since 10.1.1
 */
@protocol AGSWMTSInfoDelegate <NSObject>
@required
/** This method tells the delegate when the @c AGSWMTSInfo
 object is finished loading. A class implementing this function
 would typically create an instance of an @c AGSWMTSLayer
 by calling wmtsLayerWithLayerInfo:andSpatialReference:.
 @param wmtsInfo The @c AGSWMTSInfo object which has finished loading.
 @since 10.1.1
*/
- (void)wmtsInfoDidLoad:(AGSWMTSInfo*)wmtsInfo;

@optional
/** This method tells the delegate if the WMTSInfo object failed to load
 @param error Information regarding the cause of the failure to load.
 @since 10.1.1
 */
- (void)wmtsInfo:(AGSWMTSInfo*)wmtsInfo DidFailToLoad:(NSError*)error;

@end


