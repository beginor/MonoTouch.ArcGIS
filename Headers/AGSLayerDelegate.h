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

@class AGSLayer;
@class AGSEnvelope;

/** @file AGSLayerDelegate.h */ //Required for Globals API doc

#pragma mark -

/** @brief A delegate of @c AGSLayer.
 
 A protocol which must be adopted by a class wishing to serve as a delegate for 
 @c AGSLayer. @c AGSLayer notifies the delegate whenever the layer is loaded or 
 fails to load. Developers can listen to these events by attaching their delegate 
 to the @c AGSLayer. 
 
 @define{AGSLayerDelegate.h,ArcGIS}
 @since 1.0
 */
@protocol AGSLayerDelegate <NSObject>

@optional
/** Tells the delegate that @p layer is loaded and ready to use.
 @param layer The layer that was loaded.
 @since 1.0
 */
- (void)layerDidLoad:(AGSLayer *)layer;

/** Tells the delegate that @p layer failed to load with the specified @p error.
 @param layer The layer that failed to load.
 @param error Information about the cause of the failure.
 @since 1.0
 */
- (void)layer:(AGSLayer *)layer didFailToLoadWithError:(NSError *)error;

/** Tells the delegate that the spatial reference status of the layer
 has been initialized. This means that the map has determined that the layer 
 either has a matching spatial reference (or has the capability to project to
 a matching spatial reference), or does not have a matching spatial reference and does
 not have the capability of reprojecting itself.
 */
-(void)layer:(AGSLayer *)layer didInitializeSpatialReferenceStatus:(BOOL)srStatusValid;

@end