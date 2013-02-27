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

@class AGSTileKey;

/** @file AGSTiledLayer+Subclass.h */ //Required for Globals API doc

/** @brief Information relevant to sublcasses of @c AGSTiledLayer
 
 This category organizes the  methods that are relevant to subclassing a tiled layer.
 Developer can create custom tiled layers by paying special attention to the methods in this category when subclassing @c AGSTiledLayer.
 
 Sub-classes must provide valid values for @c AGSLayer#tileInfo, @c AGSLayer#spatialReference, @c AGSLayer#fullEnvelope, and
 @c AGSLayer#initialEnvelope properties. Other properties on @c AGSLayer are optional.

 @since 10.1.1

 @see AGSLayer(ForSubclassEyesOnly)
 */

@interface AGSTiledLayer (ForSubclassEyesOnly)

/** This must be implemented by subclasses to retreive the requested tile.
 It will be called by the framework when a tile is needed.
 @since 10.1.1
 */
-(void)requestTileForKey:(AGSTileKey*)key;

/** This must be implemented by subclasses to cancel previous tile requests.
 It will be called by the framework when a tile request needs to be aborted.
 @since 10.1.1
 */
-(void)cancelRequestForKey:(AGSTileKey*)key;

/** Subclasses should call this when they have the data for a previously requested tile.
 If subclasses failed to fetch a tile or encountered some other error, they should pass nil. The implementation for this method is provided by the framework.
 @since 10.1.1
 */
-(void)setTileData:(NSData*)data forKey:(AGSTileKey*)tilekey;

@end
