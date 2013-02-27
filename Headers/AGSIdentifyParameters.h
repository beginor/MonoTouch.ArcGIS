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

@class AGSGeometry;
@class AGSEnvelope;
@class AGSSpatialReference;
@class AGSTimeExtent;

/** @file AGSIdentifyParameters.h */ //Required for Globals API doc

/** Supported options for identifying features.
 @since 1.0
 */
typedef enum {
    AGSIdentifyParametersLayerOptionTop = 0,	/*!< */
    AGSIdentifyParametersLayerOptionVisible,	/*!< */
    AGSIdentifyParametersLayerOptionAll			/*!< */
} AGSIdentifyParametersLayerOption;


/** @brief Parameters for a @c AGSIdentifyTask operation.
 
 Instances of this class represent parameters for @c AGSIdentifyTask operations.  
 Parameters specify the criteria according to which features should be 
 identified in the map. Parameters are passed as an argument to 
 <code>executeWithParameters:</code> on @c AGSIdentifyTask.
 
 @define{AGSIdentifyTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSIdentifyParameters : NSObject <AGSCoding>

/** Resolution of the map in dots per inch. This property, in conjuction with 
 #size, and #mapEnvelope, is used by the server to determine which layers are 
 visible. It is also used to calculate a distance, based on the specified 
 #tolerance, within which to identify features. This defaults to the ppi in UIDevice(Utility), 
 but it should be set by the user to match the dpi property of the associated map service layer (if any).
 
 @since 1.0
 */
@property (nonatomic) NSUInteger dpi;

/** Size of the @c AGSMapView in pixels. This property, in conjuction with #dpi, 
 and #mapEnvelope, is used by the server to determine which layers are visible. 
 @since 1.0
 */
@property (nonatomic) CGSize size;

/** Whether or not the returned results should contain geometries. By default, 
 geometries are returned. You can reduce the size of the result payload by 
 excluding the geometries if you don't intend to display those results on the map. 
 @since 1.0
 */
@property (nonatomic) BOOL returnGeometry;

/** The distance, in screen pixels, from the specified geometry within which 
 features should be identified.
 @since 1.0
 */
@property (nonatomic) NSUInteger tolerance;

/** Layers within which the features should be identified. Possible values include
 
 @li @c AGSIdentifyParametersLayerOptionTop :  Top-most layer at the specified location
 @li @c AGSIdentifyParametersLayerOptionVisible : Visible layers at the specified location
 @li @c AGSIdentifyParametersLayerOptionAll : All layers at the specified location
 
 By default, only features within the top-most layer are identified.
 
 You can further restrict the set of layers included in the operation by 
 specifying @p layerIds. When both @p layerOption and @p layerIds are specified, 
 the server treats it as a boolean "AND" operator.
 @since 1.0
 */
@property (nonatomic) AGSIdentifyParametersLayerOption layerOption;

/** The geometry according to which features should be identified. @c AGSPoint 
 is most commonly used for identifying features at a location, but @c AGSPolygon 
 may also be used for searching within an area.
 @since 1.0
 */
@property (nonatomic, strong) AGSGeometry *geometry;

/** Subset of layers within which features should be identified. The layers are 
 specified as a list of layer IDs. 
 @since 1.0
 */
@property (nonatomic, copy) NSArray *layerIds;

/** The current extent of the map. This property, in conjuction with #size, and 
 #dpi, is used by the server to determine which layers are visible.
 @since 1.0
 */
@property (nonatomic, strong) AGSEnvelope *mapEnvelope;

/** The spatial reference of the input and output geometries as well as of the 
 #mapEnvelope. If not specified, the #geometry and the #mapEnvelope are assumed 
 to be in the spatial reference of the map service, and the identified 
 features will also be returned in the spatial reference of the map service.
 @since 1.0
 */
@property (nonatomic, strong) AGSSpatialReference *spatialReference;

/** Array of @c AGSLayerDefinition objects that allows you to filter the features 
 of individual layers. Definition expressions for layers that are currently not 
 visible will be ignored by the server.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, copy) NSArray *layerDefinitions;

/** The maximum allowable offset used for generalizing geometries returned by 
 the query operation. The default is 0. If 0 is specified the value is not 
 passed to the server in a query. The offset is in the units of the 
 #spatialReference. If a #spatialReference is not defined the spatial reference 
 of the map is used.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, assign) double maxAllowableOffset;

/** An array of @c AGSLayerTimeOptions specifiying time related properties for
 time-aware sub-layers. By default, this array is nil, and the defaults specified
 in the service are used.
 @avail{10.0}
 @since 1.8
 */
@property (nonatomic, copy) NSArray *layerTimeOptions;

/** The time extent of the map. Will be used only for time-aware layers to identify
 features that have a time stamp/period that falls within the time extent.
 @avail{10.0}
 @since 1.8
 */
@property (nonatomic, strong) AGSTimeExtent *timeExtent;

/** Initialize autoreleased Identify parameters object with defaults.
 @return A new, autoreleased, identify parameters object.
 @since 1.0
 */
+ (id)identifyParameters;

@end