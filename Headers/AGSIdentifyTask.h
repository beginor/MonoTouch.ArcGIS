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

@protocol AGSCoding;

@class AGSTask;
@class AGSGraphic;
@class AGSSpatialReference;
@class AGSCredential;
@class AGSTimeExtent;

/** @file AGSIdentifyTask.h */ //Required for Globals API doc

#pragma mark -

@class AGSIdentifyParameters;
@protocol AGSIdentifyTaskDelegate;

/** @brief A task to perform identify operations.
 
 This task performs identify operations on an ArcGIS Server map service. An 
 identify operation involves finding features in a map near a given a search 
 location. The search can be conducted on all layers in the map service, 
 just the visible layers, or just the top layer.
 
 An identify task needs a URL to a REST resource that represents a Map Service.
 For example, http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Demographics/ESRI_Population_World/MapServer
 
 @see @concept{Identify_Task/00pw00000018000000/, Using an Identify Task}
 @see @sample{6bef3f02c88e425db34650b4c4adc05d, Identify Task} 
 
 @since 1.0
 */
@interface AGSIdentifyTask : AGSTask {
@private
    id<AGSIdentifyTaskDelegate> _delegate;
}

/** Delegate to be notified when the task completes successfully or encounters 
 an error.
 @since 1.0
 */
@property (nonatomic, assign) id<AGSIdentifyTaskDelegate> delegate;

/** Initialize an autoreleased identify task.
 @param url URL to a map service resource in the ArcGIS Server REST Services Directory.
 @return A new, autoreleased, identify task object.
 @since 1.0
 */
+ (id)identifyTaskWithURL:(NSURL *)url;

/** Initialize autoreleased identify task with credential.
 @param url URL to a map service resource in the ArcGIS Server REST Services Directory.
 @param cred <code>AGSCredential</code> for accessing a secure identify task.
 @return A new, autoreleased, identify task object.
 @since 1.0
 */
+ (id)identifyTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Performs an identify operation on the map service using the specified 
 parameters. The #delegate will be notified when the operation completes or if an 
 error is encountered.
 
 It relies on the <i>Identify</i> operation
 of the REST resource.
 
 @param params Specifies the parameters for executing the search.
 @return <code>NSOperation</code> for current execute request.
 @since 1.0
 @see AGSIdentifyTaskDelegate
 */
- (NSOperation *)executeWithParameters:(AGSIdentifyParameters *)params;

@end



#pragma mark -

/** @brief A delegate of @c AGSIdentifyTask.
 
 A protocol which must be adopted by any class wishing to be notified when the 
 @c AGSIdentifyTask completes successfully or encounters an error. An instance 
 of the class must then be set as the delegate of @c AGSIdentifyTask.
 
 @define{AGSIdentifyTask.h, ArcGIS}
 @since 1.0
 */
@protocol AGSIdentifyTaskDelegate <NSObject>

@required
/** Tells the delegate that @c AGSIdentifyTask completed successfully with the 
 provided results.
 @param identifyTask The task which performed the operation.
 @param op <code>NSOperation</code> that performed the identify.
 @param results The resulting array of @c AGSIdentifyResult objects.
 @since 1.0
 */
- (void)identifyTask:(AGSIdentifyTask *)identifyTask operation:(NSOperation*)op didExecuteWithIdentifyResults:(NSArray *)results;

@optional
/** Tells the delegate that @c AGSIdentifyTask encountered an error.
 @param identifyTask The task which performed the operation.
 @param op <code>NSOperation</code> that performed the identify.
 @param error Information about the error returned by server.
 @since 1.0
 */
- (void)identifyTask:(AGSIdentifyTask *)identifyTask operation:(NSOperation*)op didFailWithError:(NSError *)error;

@end



#pragma mark -

/** Supported options for identifying features.
 @since 1.0
 */
typedef enum {
    AGSIdentifyParametersLayerOptionTop = 0,	/*!< */
    AGSIdentifyParametersLayerOptionVisible,	/*!< */
    AGSIdentifyParametersLayerOptionAll			/*!< */
} AGSIdentifyParametersLayerOption;



#pragma mark -

/** @brief Parameters for a @c AGSIdentifyTask operation.
 
 Instances of this class represent parameters for @c AGSIdentifyTask operations.  
 Parameters specify the criteria according to which features should be 
 identified in the map. Parameters are passed as an argument to 
 <code>executeWithParameters:</code> on @c AGSIdentifyTask.
 
 @define{AGSIdentifyTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSIdentifyParameters : NSObject <AGSCoding> {
@private
    NSUInteger _dpi;
    CGSize _size;
    BOOL _returnGeometry;
    NSUInteger _tolerance;
    AGSIdentifyParametersLayerOption _layerOption;
    
    AGSGeometry *_geometry;
    NSArray *_layerIds;
    AGSEnvelope *_mapEnvelope;
    AGSSpatialReference *_spatialReference;
	NSArray *_layerDefinitions;
	double _maxAllowableOffset;
	NSArray *_layerTimeOptions;
	AGSTimeExtent *_timeExtent;
}

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
@property (nonatomic, retain) AGSGeometry *geometry;

/** Subset of layers within which features should be identified. The layers are 
 specified as a list of layer IDs. 
 @since 1.0
 */
@property (nonatomic, retain) NSArray *layerIds;

/** The current extent of the map. This property, in conjuction with #size, and 
 #dpi, is used by the server to determine which layers are visible.
 @since 1.0
 */
@property (nonatomic, retain) AGSEnvelope *mapEnvelope;

/** The spatial reference of the input and output geometries as well as of the 
 #mapEnvelope. If not specified, the #geometry and the #mapEnvelope are assumed 
 to be in the spatial reference of the map service, and the identified 
 features will also be returned in the spatial reference of the map service.
 @since 1.0
 */
@property (nonatomic, retain) AGSSpatialReference *spatialReference;

/** Array of @c AGSLayerDefinition objects that allows you to filter the features 
 of individual layers. Definition expressions for layers that are currently not 
 visible will be ignored by the server.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, retain) NSArray *layerDefinitions;

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
@property (nonatomic, retain) NSArray *layerTimeOptions;

/** The time extent of the map. Will be used only for time-aware layers to identify
 features that have a time stamp/period that falls within the time extent.
 @avail{10.0}
 @since 1.8
 */
@property (nonatomic, retain) AGSTimeExtent *timeExtent;

/** Initialize autoreleased Identify parameters object with defaults.
 @return A new, autoreleased, identify parameters object.
 @since 1.0
 */
+ (id)identifyParameters;

@end



#pragma mark -

/** @brief A result of @c %AGSIdentifyTask operation.
 
 Instances of this class represent results of an @c AGSIdentifyTask operation. 
 
 @define{AGSIdentifyTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSIdentifyResult : NSObject <AGSCoding> {
@private
    NSString *_displayFieldName;
    AGSGraphic *_feature;
    NSUInteger _layerId;
    NSString *_layerName;
}

/** Name of the layer's primary display field. 
 @since 1.0
 */
@property (nonatomic, readonly, retain) NSString *displayFieldName;

/** The identified feature.
 @since 1.0
 */
@property (nonatomic, readonly, retain) AGSGraphic *feature;

/** ID of the layer that contains the identified feature.
 @since 1.0
 */
@property (nonatomic, readonly) NSUInteger layerId;

/** Name of the layer that contains the identified feature
 @since 1.0
 */
@property (nonatomic, readonly, retain) NSString *layerName;

@end
