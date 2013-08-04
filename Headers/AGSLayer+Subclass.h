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

/** @file AGSLayer+Subclass.h */ //Required for Globals API doc

@class AGSMapView;

/** Enumeration that specifies how a map was updated.
 @since 10.1.1
 */
typedef enum{
    AGSMapUpdateTypeSpatialExtent,
    AGSMapUpdateTypeTimeExtent,
    AGSMapUpdateTypeLayerAdded,
    AGSMapUpdateTypeLayerRemoved
}AGSMapUpdateType;

/** @brief Information relevant to sublcasses of @c AGSLayer
 If you implement a custom layer, you should set the error when drawing:
 If the layer draws successfully, you should set the error to nil.
 If the layer fails to draw the error should be set there as well.
 */

@interface AGSLayer (ForSubclassEyesOnly)

/** Can be set by subclasses when the layer has an error loading or drawing.
 */
@property (nonatomic, strong, readwrite) NSError *error;

/** The default dpi for the layer.
 */
-(int)defaultDpi;

/** Subclasses should call this when the layer is ready to draw.
 */
-(void)layerDidLoad;

/** Subclasses should call this when the layer fails to load.
 */
-(void)layerDidFailToLoad:(NSError*)error;

/** Called when the status of the layer's spatial reference has been established.
 You can override this method, just make sure to call the super's implementation.
 */
-(void)spatialReferenceStatusInitialized;

/** Method called when the map is updated.
 You can override this, but make sure to call the super's implementation.
 @since 10.1.1
 */
-(void)mapDidUpdate:(AGSMapUpdateType)updateType;

/** The map that the layer is in.
 */
@property (nonatomic, weak, readwrite) AGSMapView *mapView;

@end