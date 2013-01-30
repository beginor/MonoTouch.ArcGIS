/*
 COPYRIGHT 2011 ESRI
 
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

@class AGSTiledLayer;

/** @file AGSLocalTiledLayer.h */ //Required for Globals API doc

/** @brief A layer based on a tile package
 
 This object represents a local tiled layer that can display map contents from a tile package (.tpk file) on the device. This layer can function even when the device does not have any network connectivity.
 
 
 @see @concept{About_the_layer/00pw0000005q000000/, Using a local tiled layer}
 @see @sample{af2ec7bf652343c1bf98ff9fd06af5e0, Local Tiled Layer}

 @define{AGSLocalTiledLayer.h, ArcGIS}
 @since 2.1
 */
@interface AGSLocalTiledLayer : AGSTiledLayer

/** The full path to the tile package on disk.
 @since 2.1
 */
@property (nonatomic, copy, readonly) NSString *cachePath;

/** Returns a thumbnail image, if present, within the compact cache or tile package. 
 The file exists, by default, within a tile package, but can be added at the root level
 of a zipped cache.
 @since 2.1
 */
@property (nonatomic, strong, readonly) AGSImage *thumbnail;

/** 
 Flag indicating if the layer renders at the native resolution. 
 This property will not have any affect iOS devices without a retina display. If using an iOS
 device with a retina display and you want to take advantage of that display you can set
 this value to YES. The property must be set before the layer loads.
 
 Note, the tiles should have been generated at 192 DPI to have a perceptible improvment when rendering at native resolution. Typically,
 most tiles are generated only at 96 DPI and do not look better at native resolution. 
 
 When rendering at the native resolution, this layer will use more memory (because more tiles will need to be displayed).
 @since 2.1
 */
@property (nonatomic, assign, readwrite) BOOL renderNativeResolution;

/** An array of @c AGSLayerInfo objects representing the layers within this layer. 
 This only applies to TPKs.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSArray *layerInfos;


#if TARGET_OS_IPHONE
/** Initialize a local layer with the name of a cache within the application bundle, or the
 application's shared Documents directory.
 @param name The name of the tile package, excluding the '.tpk' extension.
 @return A new local tiled layer object.
 @since 2.1
 */
- (id)initWithName:(NSString*)name;

/** A method to get an initialized, autoreleased object using the name of a tile package
 residing withing the application bundle, or the shared Documents directory.
 @param name The name of the tile package, excluding the '.tpk' extension.
 @return A new, autoreleased, local tiled layer object.
 @since 2.1
 */
+ (id)localTiledLayerWithName:(NSString*)name;
#endif

/** Initialize a local layer with the full path to a tile package within the application bundle, or the
 application's shared Documents directory.
 @param fullPath The full path of the tile package, including the '.tpk' extension.
 @return A new local tiled layer object.
 @since 2.1
 */
- (id)initWithPath:(NSString*)fullPath;

/** A method to get an initialized, autoreleased object using the full path to a tile package
 residing withing the application bundle, or the application's shared Documents directory.
 @param fullPath The full path of the package, including the '.tpk' extension.
 @return A new, autoreleased, local tiled layer object.
 @since 2.1
 */
+ (id)localTiledLayerWithPath:(NSString*)fullPath;

@end
