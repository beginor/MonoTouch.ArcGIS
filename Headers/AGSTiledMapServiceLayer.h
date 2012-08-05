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

@class AGSCredential;
@class AGSTiledLayer;
@class AGSMapServiceLayerInfo;
@class AGSMapServiceInfo;

/** @file AGSTiledMapServiceLayer.h */ //Required for Globals API doc

#pragma mark -

/** @brief A layer based on a cached ArcGIS Server map service.

 An instance of this class allows you to display maps from a cached map service of ArcGIS 
 Server. For example, <a href="http://server.arcgisonline.com/ArcGIS/rest/services/World_Street_Map/MapServer">http://server.arcgisonline.com/ArcGIS/rest/services/World_Street_Map/MapServer</a>. 
 A cached map service uses a cache of pre-generated tiles to create a map instead of 
 dynamically generating map images. 
 
 In a Model-View-Controller architecture, this object represents the Model. The 
 corresponding View object, @c AGSTiledLayerView, is created when this layer is 
 added to the map. 
 
 @define{AGSTiledMapServiceLayer.h,ArcGIS}
 @since 1.0
 @see AGSDynamicMapServiceLayer for dynamic map services.
 */
@interface AGSTiledMapServiceLayer : AGSTiledLayer <AGSCoding, AGSSecuredResource> {}

/** URL of a cached map service resource in ArcGIS Server REST Services Directory.
 For example, <a href="http://server.arcgisonline.com/ArcGIS/rest/services/World_Street_Map/MapServer">http://server.arcgisonline.com/ArcGIS/rest/services/World_Street_Map/MapServer</a>.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSURL *URL;

/** Information about the map service.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSMapServiceInfo *mapServiceInfo;

/** The credential to be used to access secured resources.
 @since 1.0
 */
@property (nonatomic, copy, readonly) AGSCredential *credential;

/** Flag indicating if the layer renders at the native resolution. 
 This property will not have any affect iOS devices without a retina display. If using an iOS
 device with a retina display and you want to take advantage of that display you can set
 this value to YES. The property must be set before the layer loads.
 
 Note, the tiles should have been generated at 192 DPI to have a perceptible improvement when rendering at native resolution. Typically,
 most tiles are generated only at 96 DPI and do not look any better at native resolution. 
 
 When rendering at the native resolution, this layer will use more network bandwidth and memory (because more tiles will need to be fetched and displayed).
 @since 2.1
 */
@property (nonatomic, assign, readwrite) BOOL renderNativeResolution;

/** Initialize this layer with a URL to an ArcGIS Server cached map service. 
 @param url URL to cached map service.
 @return A new tiled map service layer object.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url;

/** Initialize this layer with a URL to an ArcGIS Server cached map service with 
 a specified credential object.
 @param url URL to a cached map service. 
 @param cred @c AGSCredential used to access the secured resource.
 @return A new tiled map service layer object.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Initialize this layer with an @c AGSMapServiceInfo object.
 You can use this method if you already have an @c AGSMapServiceInfo so 
 that another round trip to the server does not occur to retrieve this 
 information.
 @param info Previously retrieved map service info.
 @return A new tiled map service layer object.
 @since 1.0
 */
- (id)initWithMapServiceInfo: (AGSMapServiceInfo *)info;

/** A method to get an initialized, autoreleased object using a URL to 
 an ArcGIS Server cached map service.
 @param url URL to a cached map service.
 @return A new, autoreleased, tiled map service layer object.
 @since 1.0
 */
+ (id)tiledMapServiceLayerWithURL:(NSURL *)url;

/** A method to get an initialized, autoreleased object using a URL to 
 an ArcGIS Server cached map service and a credential.
 @param url URL to a cached map service.
 @param cred @c AGSCredential used to access the secured resource.
 @return A new, autoreleased, tiled map service layer object.
 @since 1.0
 */
+ (id)tiledMapServiceLayerWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** A method to get an initialized, autoreleased map service layer using 
 an @c AGSMapServiceInfo object. Use this method if you already have an 
 @c AGSMapServiceInfo so that another round trip to the server does not occur to 
 retrieve this information.
 @param info Previously retrieved map service info.
 @return A new, autoreleased, tiled map service layer object.
 @since 1.0
 */
+ (id)tiledMapServiceLayerWithMapServiceInfo: (AGSMapServiceInfo *)info;

/** For completeness, this is to be used when you have a raw dictionary from
 the REST endpoint.
 @param json The JSON dictionary to initialize a tiled map service layer.
 @param url URL pointing to a dynamic map resource.
 @param cred The credential.
 @return A new tiled map service object.
 @since 2.0
 */
- (id)initWithJSON:(NSDictionary *)json URL:(NSURL*)url credential:(AGSCredential*)cred;


/** If the layer failed to load with a specific url and credential, you can 
 resubmit it with a new URL and credential. This function does nothing if the 
 layer is already loaded. This function also does nothing if the layer is 
 currently trying to load.
 @param url URL to the tiled map service.
 @param cred @c AGSCredential used to access the secured resource.
 @since 1.0
 */
-(void)resubmitWithURL:(NSURL*)url credential:(AGSCredential*)cred;

@end
