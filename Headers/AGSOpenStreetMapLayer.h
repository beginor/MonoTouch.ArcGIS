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

@class AGSTiledServiceLayer;

/** @file AGSOpenStreetMapLayer.h */ //Required for Globals API doc

/** @brief A layer based on OpenStreetMap.
 
 An instance of this class allows you display maps from Open Street Map. 
 
 @define{AGSOpenStreetMapLayer.h, ArcGIS}
 @since 1.0
 */
@interface AGSOpenStreetMapLayer : AGSTiledServiceLayer {
}

/** Returns an autoreleased, initialized layer
 @since 1.0
 @see @c AGSLayerDelegate#layerDidLoad: , method on delegate for success
 @see @c AGSLayerDelegate#layer:didFailToLoadWithError: , method on delegate for failure
 */
+(AGSOpenStreetMapLayer*)openStreetMapLayer;
@end