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

/** @brief Information relevant to sublcasses of AGSTiledLayer
 */

@interface AGSTiledLayer (ForSubclassEyesOnly)

/** This must be implemented by subclasses to retreive the requested tile.
 */
-(void)requestTileForKey:(AGSTileKey*)key;

/** This must be implemented by subclasses to cancel previous tile requests.
 */
-(void)cancelRequestForKey:(AGSTileKey*)key;

/** Subclasses can call this when they have the data for a previously requested tile.
 */
-(void)setTileData:(NSData*)data forKey:(AGSTileKey*)tilekey;

@end
