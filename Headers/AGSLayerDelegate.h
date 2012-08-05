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

@required

// This is currently used by FeatureLayer because it needs to know the map's full 
// envelope for querying and selection.

/** The layer can call this function on its delegate to find out what the full 
 envelope of the map is.
 @since 1.0
 */
-(AGSEnvelope*)mapFullEnvelope;

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

/** Tells the delegate that @p layer data has changed. The delegate may decide 
 to refresh the UI.
 @since 1.0
 */
- (void)layerDataChanged:(AGSLayer *)layer;

@end