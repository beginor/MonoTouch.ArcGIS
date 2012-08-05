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
#import <QuartzCore/QuartzCore.h>

@protocol AGSLayerDelegate;
@class AGSSpatialReference;
@class AGSGeometry;
@class AGSEnvelope;

/** @file AGSLayer.h */ //Required for Globals API doc

#pragma mark -

/** @brief A base class for all layers.

 A base class for all layers, tiled or dynamic. Sub-classes must provide 
 implementation for the #spatialReference, #fullEnvelope, #initialEnvelope, and 
 #units properties declared by this class. They must also update the #loaded 
 property and notify the #delegate when appropriate.

 Will fire notifications for LayerDidLoad and LayerFailedToLoad.
 
 @see @concept{Overview/00pw0000001v000000/, Overview of Layers}
 @since 1.0
 */
@interface AGSLayer : NSObject {
//## @cond protected
 @protected
	BOOL _timeAware;
	UIView<AGSLayerDelegate> *_delegate;
	BOOL _loaded;
	NSString *_name;
	BOOL _renderNativeResolution;
//## @endcond protected
	
 @private
	NSError *_error;
}

/** A property indicating whether the layer is loaded and ready to be used.
 When the layer is loaded, the value becomes <code>YES</code>, and layer 
 properties can be accessed.
 @since 1.0
 @see AGSLayerDelegate
 */
@property (nonatomic, readonly, getter=isLoaded) BOOL loaded;


/** A property indicating whether the layer is time-aware.
 @since 1.0
 */
@property (nonatomic, readonly, getter=isTimeAware) BOOL timeAware;

/** The spatial reference of the layer. 
 @since 1.0
 */
@property (nonatomic, readonly) AGSSpatialReference *spatialReference;

/** Full extent of the layer. 
 @since 1.0 
*/
@property (nonatomic, readonly) AGSEnvelope *fullEnvelope;

/** Initial extent of the  layer. 
 @since 1.0
*/
@property (nonatomic, readonly) AGSEnvelope *initialEnvelope;

/** Delegate to be notified when the layer is loaded or fails to load. When this 
 layer is loaded, a corresponding @c AGSLayerView object is automatically set as 
 the delegate. This delegate must not be replaced.
 @since 1.0
 */
@property (nonatomic, assign) UIView<AGSLayerDelegate> *delegate;

/** Information about the error associated with a layer.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSError *error;

/** The units the layer is in. Possible values include
 
 @li @c AGSUnitsCentimeters 
 @li @c AGSUnitsDecimalDegrees
 @li @c AGSUnitsDecimeters
 @li @c AGSUnitsFeet
 @li @c AGSUnitsInches
 @li @c AGSUnitsKilometers
 @li @c AGSUnitsMeters
 @li @c AGSUnitsMiles
 @li @c AGSUnitsMillimeters
 @li @c AGSUnitsNauticalMiles
 @li @c AGSUnitsPoints
 @li @c AGSUnitsUnknown
 @li @c AGSUnitsYards
 
@since 1.0
 */
@property (nonatomic, assign) AGSUnits units;

/** The name of the layer. This property will be set by the framework when the
 layer is added to the map.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSString *name;

/** Gets a value that determines if the layer renders at the native resolution.
 This property will not have any affect on iOS devices without a retina display. If using an iOS
 device with a retina display and you want to take advantage of that display you can set
 this value to YES. If YES, this layer will use more memory and network bandwidth, but 
 the layer will render at a higher resolution.
 This property is not settable for every layer type.
 @since 2.1
 */
@property (nonatomic, assign, readonly) BOOL renderNativeResolution;

/** Method to notify the delegate that a layer successfully loaded. This method 
 will also post a "LayerDidLoad" notification that can be observed by the developer.
 @since 1.0
 */
- (void)layerDidLoad;

/** Method to notify the delegate that a layer failed to load. This method will 
 also post a "LayerFailedToLoad" notification that can be observed by the developer.
 @param error Information regarding the cause of the layer failing to load.
 @since 1.0
 */
- (void)layerDidFailToLoad:(NSError*)error;

/** This method tells the layer that the data has changed and it should be redrawn. 
 @since 1.0
 */
-(void)dataChanged;

@end



