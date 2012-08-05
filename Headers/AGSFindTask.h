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

@class AGSCredential;
@class AGSGraphic;
@class AGSSpatialReference;
@class AGSTask;

/** @file AGSFindTask.h */ //Required for Globals API doc

#pragma mark -

@class AGSFindParameters;
@protocol AGSFindTaskDelegate;

/** @brief A task to perform simple, textual searches 
 
 This task performs text-based searches on an ArcGIS Server map service. The 
 search is performed on only layers in the map service. Any tables in the map service are not searched. The search can be 
 conducted on a single field of a single layer in the map service, on many 
 fields of a layer, or on many fields of many layers.  
 
 A find task needs a URL to a REST resource that represents a Map service.
 For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/SanFrancisco/311Incidents/MapServer
 
 @define{AGSFindTask.h, ArcGIS}
 @since 1.0
 @see AGSFindParameters for search criteria
 @see AGSFindTaskDelegate and AGSFindResult for search results
 */
@interface AGSFindTask : AGSTask {
@private
    id<AGSFindTaskDelegate> _delegate;
}

/** Delegate to be notified when the task completes successfully or encounters 
 an error.
 @since 1.0
 */
@property (nonatomic, assign) id<AGSFindTaskDelegate> delegate;

/** Initialize autoreleased find task.
 @param url URL to a map service resource in the ArcGIS Server REST Services 
 Directory.
 @return A new, autoreleased, find task object.
 @since 1.0
 */
+ (id)findTaskWithURL:(NSURL *)url;

/** Initialize autoreleased find task.
 @param url URL to a map service resource in the ArcGIS Server REST Services 
 Directory.
 @param cred <code>AGSCredential</code> to access secure resource.
 @return A new, autoreleased, find task object.
 @since 1.0
 */
+ (id)findTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Performs a search on the map service using the specified parameters. The 
 #delegate will be notified when the operation completes or if an error is 
 encountered.
 
 It relies on the <i>Find</i> operation
 of the REST resource.
 
 @param params The parameters for executing the search.
 @return <code>NSOperation</code> for current search operation.
 @see AGSFindTaskDelegate
 @since 1.0
 */
- (NSOperation *)executeWithParameters:(AGSFindParameters *)params;

@end



#pragma mark -

/** @brief A delegate of @c AGSFindTask.
 
 A protocol which must be adopted by any class wishing to be notified when the 
 @c AGSFindTask completes successfully or encounters an error. An instance of 
 the class must then be set as the delegate of @c AGSFindTask.
 
 @define{AGSFindTask.h, ArcGIS}
 @since 1.0
 */
@protocol AGSFindTaskDelegate <NSObject>

@required
/** Tells the delegate that @c AGSFindTask completed successfully with the 
 provided results.
 @param findTask The task which performed the search.
 @param op <code>NSOperation</code> which executed the find task.
 @param results The resulting array of @c AGSFindResult objects.
 */
- (void)findTask:(AGSFindTask *)findTask operation:(NSOperation*)op didExecuteWithFindResults:(NSArray *)results;

@optional
/** Tells the delegate that @c AGSFindTask encountered an error.
 @param findTask The task which performed the search.
 @param op <code>NSOperation</code> which executed the find task.
 @param error Information about the error returned by server.
 */
- (void)findTask:(AGSFindTask *)findTask operation:(NSOperation*)op didFailWithError:(NSError *)error;

@end



#pragma mark -

/** @brief Parameters for an @c AGSFindTask operation.
 
 Instances of this class represent parameters for @c AGSFindTask operations. 
 Parameters provide criteria for performing a search on the map service. 
 Parameters are passed as an argument to executeWithParameters: on @c AGSFindTask.
 
 @define{AGSFindTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSFindParameters : NSObject <AGSCoding> {
@private
    BOOL _contains;
    NSArray *_layerIds;
    AGSSpatialReference *_outSpatialReference;
    BOOL _returnGeometry;
    NSArray *_searchFields;
    NSString *_searchText;
	NSArray *_layerDefinitions;
	double _maxAllowableOffset;
}

/** If <code>NO</code>, @c AGSFindTask searches for an <i>exact match</i> of 
 #searchText and in a case sensitive manner. Otherwise, it searches for a value 
 that <i>contains</i> the #searchText and in a case agnostic manner.
 Default is <code>YES</code>.
 @since 1.0
 */
@property (nonatomic) BOOL contains;

/** The IDs of layers to to be searched. This parameter must be specified.
 @since 1.0
 */
@property (nonatomic, retain) NSArray *layerIds;

/** The spatial reference of the result geometries. By default, geometries 
 are returned in the spatial reference of the map service.
 @since 1.0
 */
@property (nonatomic, retain) AGSSpatialReference *outSpatialReference;

/** Whether or not the returned results should contain geometries. By default, 
 geometries are returned. You can reduce the size of the result payload by 
 excluding the geometries if you don't intend to display those results on the map.
 @since 1.0
 */
@property (nonatomic) BOOL returnGeometry;

/** The names of fields to be searched. If this parameter is not specified, all 
 fields are searched.
 @since 1.0 
 */
@property (nonatomic, retain) NSArray *searchFields;

/** The text to be searched.
 @since 1.0
 */
@property (nonatomic, copy) NSString *searchText;

/** Array of @c AGSLayerDefinition objects that allows you to filter the features 
 of individual layers. Definition expressions for layers that are currently not 
 visible will be ignored by the server.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, retain) NSArray *layerDefinitions;

/** The maximum allowable offset used for generalizing geometries returned by 
 the query operation. The default is 0. If 0 is specified the value is not passed 
 to the server in a query. The offset is in the units of the spatial reference. 
 If a spatial reference is not defined the spatial reference of the map is used.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, assign) double maxAllowableOffset;

@end



#pragma mark -

/** @brief A result of @c AGSFindTask operation
 
 Instances of this class represent results of an @c AGSFindTask operation. 
 
 @define{AGSFindTask.h, ArcGIS}
 @since 1.0
 */
@interface AGSFindResult : NSObject <AGSCoding> {
@private
    NSString *_displayFieldName;
    AGSGraphic *_feature;
    NSString *_foundFieldName;
    NSUInteger _layerId;
    NSString *_layerName;
}

/** Name of the layer's primary display field. 
 @since 1.0
 */
@property (nonatomic, readonly, retain) NSString *displayFieldName;

/** The feature in the layer that contains or matches the search text. The 
 feature's attributes contain field values from the layer. The feature may or 
 may not have a geometry depending on whether it belongs to a layer or a table 
 respectively.
 @since 1.0
 */
@property (nonatomic, readonly, retain) AGSGraphic *feature;

/** Name of the layer's field that contains the search text.
 @since 1.0
 */
@property (nonatomic, readonly, retain) NSString *foundFieldName;

/** ID of the layer that contains the search text.
 @since 1.0
 */
@property (nonatomic, readonly) NSUInteger layerId;

/** Name of the layer that contains the search text.
 @since 1.0
 */
@property (nonatomic, readonly, retain) NSString *layerName;

@end