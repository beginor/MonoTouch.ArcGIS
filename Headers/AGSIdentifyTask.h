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
@interface AGSIdentifyTask : AGSTask

/** Delegate to be notified when the task completes successfully or encounters 
 an error.
 @since 1.0
 */
@property (nonatomic, weak) id<AGSIdentifyTaskDelegate> delegate;

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
 @see @c AGSIdentifyTaskDelegate#identifyTask:operation:didExecuteWithIdentifyResults:, method on delegate for success
 @see @c AGSIdentifyTaskDelegate#identifyTask:operation:didFailWithError: , method on delegate for failure
 
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


