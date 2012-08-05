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
#import <UIKit/UIKit.h>

@class AGSLayer;
@class AGSEnvelope;
@class AGSRequestOperation;
@class AGSImageRequestOperation;
@class AGSTimeExtent;
@class AGSExportImageParams;
@protocol AGSExportMapImageDelegate;

/** @file AGSDynamicLayer.h */ //Required for Globals API doc

/**
 @brief A protocol that drawing operations must implement for exporting a map image.
 
 You can use classes that implement this protocol for drawing a dynamic layer.
 @since 1.0
 */
@protocol AGSDynamicLayerDrawingOperation <NSObject>

/** Request parameters for specific area of a map.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSExportImageParams *exportImageParams;
@end


#pragma mark -

/** @brief A base class for dynamic layers.

 A base class for dynamic layers. You would typically work with concrete dynamic 
 layers represented by the sub-classes of this class, for instance, 
 @c AGSDynamicMapServiceLayer.
 
 Sub-classes must provide implementation for the #spatialReference, #fullEnvelope, 
 #initialEnvelope, and #units properties declared by @c AGSLayer. They must also 
 provide implementation for the 
 @link #exportMapImage: <code>exportMapImage:</code>@endlink
 method and notify the #exportDelegate when appropriate. It is also the 
 responsibility of sub-classes to update the #loaded property and notify the 
 #delegate when appropriate.
 
 In a Model-View-Controller architecture, this object represents the Model. It 
 is responsible for creating or fetching the map image. The corresponding View 
 object, @c AGSDynamicLayerView, is responsible for displaying the map image on 
 screen. It is created when sub-classes, for instance @c AGSDynamicMapServiceLayer, 
 are added to the map. 
 
 @define{AGSDynamicLayer.h,ArcGIS}
 @since 1.0
 */
@interface AGSDynamicLayer : AGSLayer {
 @private
    id<AGSExportMapImageDelegate> _exportDelegate;
    AGSDynamicLayerGPSAutoPanDrawingMode _gpsAutoPanDrawingMode;
}


/** Delegate to be notified of events related to exporting the map image. When 
 this layer is loaded, a corresponding View object is automatically set as the 
 @p exportDelegate which should not be replaced.
 @since 1.0
 */
@property (nonatomic, assign) id<AGSExportMapImageDelegate> exportDelegate;

/** The minimum scale of the layer.
 @since 1.0
 */
@property (nonatomic, assign, readonly) double minScale;

/** The maximum scale of the layer.
 @since 1.0
 */
@property (nonatomic, assign, readonly) double maxScale;

/** Defines the drawing behavior for a dynamic layer when
 the map's gps is in an auto-pan mode.
 For some layers, especially those that make network request, you may want this property accordingly. 
 When the map is navigating from the gps it can generate a lot of requests resulting in a heavy server load.
 @since 2.1
 */
@property (nonatomic, assign) AGSDynamicLayerGPSAutoPanDrawingMode gpsAutoPanDrawingMode;

/** Get new map image. The #exportDelegate is notified when the image is exported.
 This method must be implemented by subclasses.
 @param params The input parameters for the export image operation.
 @since 1.0
 */
-(NSOperation<AGSDynamicLayerDrawingOperation>*)exportMapImage:(AGSExportImageParams*)params;

@end


#pragma mark -

/** Defines why they layer is asked to redraw.
 @since 2.2
 */
typedef enum { 
    AGSLayerUpdateTypeZoomed = 0,
    AGSLayerUpdateTypeZooming,
    AGSLayerUpdateTypePanned,
    AGSLayerUpdateTypePanning,
    AGSLayerUpdateTypeTimeExtentChanged,
    AGSLayerUpdateTypeDataChanged, // re-draw what client layer currently has
    AGSLayerUpdateTypeDataExpired // need requery to see if data has changed, data has expired
} AGSLayerUpdateType;


/** @brief A class that encapsulates the parameters passed to an export image method.
 
 A class that encapsulates the parameters passed to an export image method.
 @define{AGSDynamicLayer.h, ArcGIS}
 @since 1.0
 */
@interface AGSExportImageParams : NSObject {
@private
	AGSEnvelope *_envelope;
	AGSTimeExtent *_timeExtent;
	CGSize _size;
	CGRect _frame;
	BOOL _mapWrapAround;
    AGSLayerUpdateType _layerUpdateType;
}

/** The envelope to draw.
 @since 1.0
 */
@property (nonatomic, retain) AGSEnvelope *envelope;

/** The time extent to draw. Can be nil. Should be ignored by layers that are 
 not time aware.
 @since 1.0
 */
@property (nonatomic, retain) AGSTimeExtent *timeExtent;

/** The size of the output image.
 @since 1.0
 */
@property (nonatomic, assign) CGSize size;

/** The frame used to place the image once it has been returned.
 @since 1.0
 */
@property (nonatomic, assign) CGRect frame;

/** Specifies the map wrap around property for the draw operation.
 @since 1.8
 */
@property (nonatomic, assign) BOOL mapWrapAround;

/** Defines why they layer is asked to redraw.
 @since 2.2
 */
@property (nonatomic, assign) AGSLayerUpdateType layerUpdateType;

/** Initializes an instance of <code>%AGSExportImageParams</code>.
 @param envelope The envelope to draw.
 @param timeExtent The time extent to draw.
 @param size The size of the output image.
 @param frame The frame used to place the image once it has been returned.
 @param mapWrapAround Whether or not the map's wrapAround property is YES or NO.
 @return A new <code>%AGSExportImageParams</code> object.
 @since 1.8
 */
-(id)initWithEnvelope:(AGSEnvelope*)envelope timeExtent:(AGSTimeExtent*)timeExtent size:(CGSize)size frame:(CGRect)frame mapWrapAround:(BOOL)mapWrapAround;

/** Returns an adjusted envelope if the map is wrapping around. The envelope will have a spatial reference with an adjusted
 central meridian if need be.
 @since 1.8
 */
-(AGSEnvelope *)adjustEnvelopeForWrapAround;

@end

#pragma mark -

/** @brief An exportDelegate of @c AGSDynamicLayer.
 
 A protocol which must be adopted by a class wishing to be notified when 
 @c AGSDynamicLayer generates a map image dynamically. An instance of the class 
 must then be set as the @p exportDelegate of @c AGSDynamicLayer.
 
@define{AGSDynamicLayer.h,ArcGIS}
 @since 1.0
 */
@protocol AGSExportMapImageDelegate <NSObject>

@required
/** Tells the delegate the map image was successfully exported.
 @param layer The layer which exported the map image.
 @param op <code>NSOperation</code> that executed the export.
 @param image The exported image.
 @since 1.0
 */
- (void)dynamicLayer:(AGSDynamicLayer *)layer exportMapImageOperation:(NSOperation<AGSDynamicLayerDrawingOperation>*)op didFinishWithImage:(UIImage *)image;

@optional

/** Tells the delegate the map image could not be exported.
 @param layer The layer that was to export the map image.
 @param op <code>NSOperation</code> that executed the export.
 @param error Information about the error returned by the operation.
 @since 1.0
 */
- (void)dynamicLayer:(AGSDynamicLayer *)layer exportMapImageOperation:(NSOperation<AGSDynamicLayerDrawingOperation>*)op didFailWithError:(NSError*)error;

@end

#pragma mark -

/** @brief An operation to retrieve a dynamic layer image.
 
 Operation that will retrieve a dynamic layer image and adopts the 
 @c AGSDynamicLayerDrawingOperation protocol.
 
 @define{AGSDynamicLayer.h,ArcGIS}
 @since 1.0
 */
@interface AGSDynamicLayerImageRequestOperation : AGSImageRequestOperation <AGSDynamicLayerDrawingOperation> {
 @private
	AGSExportImageParams *_exportImageParams;
}

/** Request parameters for specific area of a map.
 @since 1.0
 */
@property (nonatomic, retain, readwrite) AGSExportImageParams *exportImageParams;

@end

