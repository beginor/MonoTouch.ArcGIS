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

/** @file AGSTiledServiceLayer+Subclass.h */ //Required for Globals API doc

/** @brief Information relevant to sublcasses of @c AGSTiledServiceLayer
 
 This category organizes the  methods that are relevant to subclassing a tiled service layer.
 Developer can create custom tiled service layers by paying special attention to the methods in this category when subclassing @c AGSTiledServiceLayer.

 @since 10.1.1
 @see AGSLayer(ForSubclassEyesOnly)
 */
@interface AGSTiledServiceLayer (ForSubclassEyesOnly)


/** This must be implemented by the subclasses. Subclasses must simply provide a URL to the tile. The request will be made by the superclass.
 @since 10.1.1
 */
-(NSURL*)urlForTileKey:(AGSTileKey*)key;

@end
