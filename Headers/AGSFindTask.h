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
@interface AGSFindTask : AGSTask

/** Delegate to be notified when the task completes successfully or encounters 
 an error.
 @since 1.0
 */
@property (nonatomic, weak) id<AGSFindTaskDelegate> delegate;

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

