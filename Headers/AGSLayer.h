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

/** @file AGSLayer.h */ //Required for Globals API doc

@class AGSSpatialReference;
@class AGSEnvelope;
@protocol AGSLayerDelegate;

/** Notification that indicates that an AGSLayer loaded successfully.
 @since 10.1.1
 */
AGS_EXTERN NSString *const AGSLayerDidLoadNotification;

/** Notification that indicates that an AGSLayer wasn't able to load successfully.
 @since 10.1.1
 */
AGS_EXTERN NSString *const AGSLayerDidFailToLoadNotification;

/** Notification that indicates that an AGSLayer initialized its spatial reference successfully.
 @since 10.1.1
 */
AGS_EXTERN NSString *const AGSLayerDidInitializeSpatialReferenceStatusNotification;

/** @brief A base class for all layers.
 
 A base class for all layers, tiled or dynamic. Sub-classes must provide 
 valid values for the #spatialReference, #fullEnvelope, and #initialEnvelope properties declared by this class.
 
 
 <h3>Notifications</h3>
 All layers post @c #AGSLayerDidLoadNotification , @c #AGSLayerDidFailToLoadNotification, and @c #AGSLayerDidInitializeSpatialReferenceStatusNotification 
 
 @see @concept{Overview/00pw0000001v000000/, Overview of Layers}
 @since 1.0
 */
@interface AGSLayer : NSObject

/** Indicates that this layer loaded successfully.
 @since 1.0
 */
@property (nonatomic, assign, readonly) BOOL loaded;

/** Information about the error associated with a layer.
 @since 1.0
 */
@property (nonatomic, strong, readonly) NSError *error;

/** Gets a value that determines if the layer renders at the native resolution.
 This property will not have any affect on iOS devices without a retina display. If using an iOS
 device with a retina display and you want to take advantage of that display you can set
 this value to YES. If YES, this layer will use more memory and network bandwidth, but 
 the layer will render at a higher resolution.
 This property is not settable for every layer type.
 @since 2.1
 */
@property (nonatomic, assign, readwrite) BOOL renderNativeResolution;

/** The opacity of this layer as a value between 0(fully transparent) and 1(fully opaque)
 @since 10.1.1
 */
@property (nonatomic, assign) CGFloat opacity;

/** The name of this layer
 @since 10.1.1
 */
@property (nonatomic, copy, readwrite) NSString *name;

/** Delegate to be notified when the layer is loaded or fails to load.
 @since 1.0
 */
@property (nonatomic, weak, readwrite) id<AGSLayerDelegate> delegate;

/** This property will be NO until the spatial reference status has been initialized.
 See the layer:didInitializeSpatialReferenceStatus method on delegate for more information.
 */
@property (nonatomic, assign) BOOL spatialReferenceStatusValid;

/** The spatial reference of the layer. 
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Full extent of the layer. 
 @since 1.0 
 */
@property (nonatomic, strong, readonly) AGSEnvelope *fullEnvelope;

/** Gets or sets the initial envelope of the layer.
 @since 1.0
 */
@property (nonatomic, strong) AGSEnvelope *initialEnvelope;

/** The minimum scale at which this layer is visible. If the map is zoomed out 
 beyond this scale, the layer will not be visible.
 @since 1.0
 */
@property (nonatomic, readwrite) double minScale;

/** The maximum scale at which this layer is visible. If the map is zoomed in 
 beyond this scale, the layer will not be visible.
 @since 1.0
 */
@property (nonatomic, readwrite) double maxScale;

/** This method tells the layer that it should refresh its data and redraw.
 @since 10.1.1
 */
-(void)refresh;

/** A property indicating whether the layer is time-aware.
 @since 1.0
 */
@property (nonatomic, readonly, getter=isTimeAware) BOOL timeAware;

/**
 Indicates whether this layer should be visible in the map.
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite, getter = isVisible) BOOL visible;

/** Indicates whether the map's scale is within this layer's scale range (@c #minScale and @c #maxScale).
 @since 10.1.1
 */
-(BOOL)isInScale;

@end
