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

@class AGSCredential;
@class AGSLayer;
@class AGSDynamicLayer;
@class AGSMapServiceLayerInfo;
@class AGSEnvelope;
@class AGSMapServiceInfo;

/** @file AGSDynamicMapServiceLayer.h */ //Required for Globals API doc

#pragma mark -


/** @brief A layer based on a dynamic ArcGIS Server map service.

 An instance of this class allows you to display maps from a dynamic map service 
 of ArcGIS Server. For example, <a href="http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Demographics/ESRI_Census_USA/MapServer">http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Demographics/ESRI_Census_USA/MapServer</a>. 
 A dynamic map service generates map images on the fly. 
 
 In a Model-View-Controller architecture, this object represents the Model. The 
 corresponding View object, @c AGSDynamicLayerView,  is created when this layer 
 is added to the map.
 
 @define{AGSDynamicMapServiceLayer.h,ArcGIS}
 @see AGSTiledMapServiceLayer for cached map services.
 @since 1.0
 */
@interface AGSDynamicMapServiceLayer : AGSDynamicLayer <AGSCoding, AGSSecuredResource> {
 @private
    NSURL *_URL;
    
	AGSMapServiceInfo *_mapServiceInfo;
	AGSCredential *_credential;
	NSOperation *_loadOperation;

    NSUInteger _dpi;
    AGSImageFormat _imageFormat;
    BOOL _transparent;
    NSArray *_layerDefinitions; 
    NSArray *_visibleLayers; //NSNumber[]  
 
    NSOperation *_currentRequest;
	NSArray *_layerTimeOptions;
	
	BOOL _userOverrodeDpi;
}

/** URL of the dynamic map service resource in the ArcGIS Server REST Services Directory.
 For example, <a href="http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Demographics/ESRI_Census_USA/MapServer">http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Demographics/ESRI_Census_USA/MapServer</a>.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSURL *URL;

/** Information about this layer's map service.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSMapServiceInfo *mapServiceInfo;

/** The credential to be used to access this layer's secured map service.
 @since 1.0
 */
@property (nonatomic, copy, readonly) AGSCredential *credential;

/** The DPI (dots-per-inch) resolution of map images generated by this layer's map service.
 The dpi will default to a value that takes into account the dpi of the device and the value of the
 renderNativeResolution property. If you programmatically change the dpi, it will then cease
 to change when the renderNativeResolution property changes.
 @since 1.0
 */
@property (nonatomic) NSUInteger dpi;

/** The image format of the map. Possible values include
 
 @li @c AGSImageFormatPNG32
 @li @c AGSImageFormatPNG24
 @li @c AGSImageFormatPNG8
 @li @c AGSImageFormatPNG
 @li @c AGSImageFormatJPG
 @li @c AGSImageFormatGIF 
 
 Please consult the ArcGIS Server REST Services Directory to ensure the map service supports 
 the requested image format.
 
 @since 1.0
 */
@property (nonatomic) AGSImageFormat imageFormat;

/** A property indicating whether or not images generated by this layer's map service 
 should be transparent.
 @since 1.0
 */
@property (nonatomic) BOOL transparent;

/** The array of @c AGSLayerDefinition objects that allow you to filter the features
 of individual layers in the exported map image.
 @since 1.0
 */
@property (nonatomic, retain) NSArray *layerDefinitions;

/** The sub-layers to be included in the map image exported by the map service. 
 By default, the array is nil, and the default visibility specified in each 
 sub-layer's @c AGSMapServiceLayerInfo is used in conjunction with its minimum and 
 maximum scale to determine whether it should be included in the map image.
 
 To exclude certain layers from the image, you need to set this property to
 an array containing @c layerId  of each @c AGSMapServiceLayerInfo that needs to
 be included in the image. The layers that are left out will not be included 
 in the image.
 
 @since 1.0
 */
@property (nonatomic, retain) NSArray *visibleLayers;

/** An array of @c AGSLayerTimeOptions specifiying time related properties for
 time-aware sub-layers. By default, this array is nil, and the defaults specified
 in the service are used. 
 @since 1.8
 */
@property (nonatomic, retain) NSArray *layerTimeOptions;

/** Flag indicating if the layer renders at the native resolution. 
 This property will not have any affect iOS devices without a retina display. If using an iOS
 device with a retina display and you want to take advantage of that display you can set
 this value to YES. The property must be set before the layer loads.
 
 When rendering at the native resolution, this layer will use more network bandwidth and memory (because the map images will be bigger).
 @since 2.1
 */
@property (nonatomic, assign, readwrite) BOOL renderNativeResolution;

/** Initialize this layer with a URL of an ArcGIS Server dynamic map service
 @param url URL to a dynamic map service.
 @return A new dynamic map service layer object.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url;

/** Initialize this layer with a URL of an ArcGIS Server dynamic map service as well as a
 credential to a secured resource.
 @param url URL to a dynamic map service.
 @param cred @c AGSCredential to access a secured resource.
 @return A new dynamic map service layer object.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Initialize this layer with an @c AGSMapServiceInfo object.
 Use this method if you already have an @c AGSMapServiceInfo so 
 that another round trip to the server does not occur to retrieve this 
 information.
 @param info Previously retrieved map service info.
 @return A new dynamic map service layer object.
 @since 1.0
 */
- (id)initWithMapServiceInfo: (AGSMapServiceInfo *)info;

/** A method to get an initialized, autoreleased layer with a URL of an ArcGIS Server 
 dynamic map service.
 @param url URL to a dynamic map service.
 @return A new, autoreleased, dynamic map service layer object.
 @since 1.0
 */
+ (id)dynamicMapServiceLayerWithURL:(NSURL *)url;

/** A method to get an initialized, autoreleased layer with a URL of an ArcGIS Server 
 dynamic map service.
 @param url URL to dynamic map service.
 @param cred @c AGSCredential used to access a secured resource.
 @return A new, autoreleased, dynamic map service layer object.
 @since 1.0
 */
+ (id)dynamicMapServiceLayerWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** A method to get an initialized, autoreleased layer using an @c AGSMapServiceInfo 
 object. Use this method if you already have an @c AGSMapServiceInfo so that another round 
 trip to the server does not occur to retrieve this information.
 @param info Previously retrieved map service info.
 @return A new, autoreleased, dynamic map service layer object.
 @since 1.0
 */
+ (id)dynamicMapServiceLayerWithMapServiceInfo: (AGSMapServiceInfo *)info;

/** For completeness, this is to be used when you have a raw dictionary from
 the REST endpoint.
 @param json The JSON dictionary to initialize a dynamic map service layer.
 @param url URL pointing to a dynamic map resource.
 @param cred The credential
 @return A new AGSDynamicMapServiceLayer object.
 @since 2.0
 */
- (id)initWithJSON:(NSDictionary *)json URL:(NSURL*)url credential:(AGSCredential*)cred;

/** If the layer failed to load with a specific url and credential, you can 
 resubmit it with a new URL and credential. This function does nothing if the 
 layer is already loaded. This function also does nothing if the layer is 
 currently trying to load.
 @param url URL to the dynamic map service.
 @param cred @c AGSCredential to access the secured resource.
 @since 1.0
 */
-(void)resubmitWithURL:(NSURL*)url credential:(AGSCredential*)cred;

@end
