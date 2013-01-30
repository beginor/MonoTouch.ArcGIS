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
@class AGSCredential;
@class AGSGeometry;
@class AGSFeatureSet;
@class AGSSpatialReference;
@class AGSTimeExtent;

@class AGSQuery;
@class AGSRelationshipQuery;
@protocol AGSQueryTaskDelegate;

/** @file AGSQueryTask.h */ //Required for Globals API doc

#pragma mark -

/** @brief A task to perform structured queries.
 
 This task performs structured queries on a layer of ArcGIS Server Map Service, 
 Image Service, or Feature Service. For Map and Feature services, the query can 
 also be performed on a table. Queries can be based on SQL expressions, spatial 
 relationships, or time extents.
 
 A query task needs a URL to a REST resource that represents a layer in a Map, Image, or Feature service.
 For example, http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Demographics/ESRI_Census_USA/MapServer/5
 
 @see @concept{Query_Task/00pw00000016000000/, Using a Query Task}
 @see @sample{9e07d23f0bd3439e9e89fc06bf9ff201, Query Task}
 @since 1.0
 */
@interface AGSQueryTask : AGSTask

/** Delegate to be notified when the task completes successfully or returns an error.
 @since 1.0
 */
@property (nonatomic, weak) id<AGSQueryTaskDelegate> delegate;

/** Initialize an autoreleased query task.
 @param url URL to a layer resource in the ArcGIS Server REST Services Directory.
 @return A new, autoreleased, query task object.
 @since 1.0
 */
+ (id)queryTaskWithURL:(NSURL *)url;

/** Initialize autoreleased query task.
 @param url URL to a layer resource in the ArcGIS Server REST Services Directory.
 @param cred <code>AGSCredential</code> used to access the secured service.
 @return A new, autoreleased, query task object.
 @since 1.0
 */
+ (id)queryTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Executes a query against the layer resource pointed by the <code>url</code>.
 It relies on the <i>Query</i> operation of the REST resource.
 
 The query returns records matching the specified criteria. The records could be 
 features, if the service layer represents a layer. Or the records could be simple 
 records (without geometry) if the service layer represents a table. The #delegate 
 will be notified when the operation completes or if an error is encountered.
 
 The number of results returned by the query is limited by the service's configuration.
 @param query Specifies the criteria for the query.
 @return <code>NSOperation</code> for current execute request.
 @since 1.0
 @see @c AGSQueryTaskDelegate#queryTask:operation:didExecuteWithFeatureSetResult: , method on delegate for success
 @see @c AGSQueryTaskDelegate#queryTask:operation:didFailWithError:  , method on delegate for failure
 */
- (NSOperation *)executeWithQuery:(AGSQuery *)query;

/** Executes a query against the layer resource pointed by the <code>url</code>.
 It relies on the <i>Query</i> operation of the REST resource.
 
 The query returns only IDs of records matching the specified criteria. This is 
 useful if you want to implement paging for results or if you want to only fetch 
 result details on demand. Unlike <code>executeWithQuery:</code> , there is no 
 limit on the number of results returned by this query.
 
 The #delegate will be notified when the operation completes or if an error is 
 encountered.
 @param query Specifies the criteria for the query.
 @return <code>NSOperation</code> for current execute request.
 @since 1.0

 @avail{10}
 @see @c AGSQueryTaskDelegate#queryTask:operation:didExecuteWithObjectIds: , method on delegate for success
 @see @c AGSQueryTaskDelegate#queryTask:operation:didFailQueryForIdsWithError: , method on delegate for failure
 */
- (NSOperation *)executeForIdsWithQuery:(AGSQuery *)query;

/** Executes a query against the layer resource pointed by the <code>url</code>.
 It relies on the <i>Query Related Records</i> operation of the REST resource.
 
 The query returns records that are related to the given set of features. The 
 related records could be features, if the service layer is related to a layer. 
 Or the related records could be simple records (wihtout geometry) if the service 
 layer is related to a table. 
 
 The #delegate will be notified when the operation completes or if an error is 
 encountered. 
 @param query Specifies the criteria for the query.
 @return <code>NSOperation</code> for current execute request.
 @since 1.0

 @avail{10}
 @see @c AGSQueryTaskDelegate#queryTask:operation:didExecuteWithRelatedFeatures: , method on delegate for success
 @see @c AGSQueryTaskDelegate#queryTask:operation:didFailRelationshipQueryWithError: , method on delegate for failure
 */
- (NSOperation *)executeWithRelationshipQuery:(AGSRelationshipQuery *)query;

/** Executes a query against the layer resource pointed by the <code>url</code>.
 It relies on the <i>Query</i> operation of the REST resource.
 
 The query returns only a feature count of records matching the specified criteria. 
 
 The #delegate will be notified when the operation completes or if an error is 
 encountered.
 @param query Specifies the criteria for the query.
 @return <code>NSOperation</code> for current execute request.
 @since 1.0
 
 @avail{10}
 @see @c AGSQueryTaskDelegate#queryTask:operation:didExecuteWithFeatureCount: , method on delegate for success
 @see @c AGSQueryTaskDelegate#queryTask:operation:didFailQueryFeatureCountWithError: , method on delegate for failure
 */
- (NSOperation *)executeFeatureCountWithQuery:(AGSQuery*)query;

@end



#pragma mark -

/** @brief A delegate of @c AGSQueryTask.
 
 A protocol which must be adopted by any class wishing to be notified when the 
 @c AGSQueryTask completes successfully or encounters an error. An instance of 
 the class must then be set as the <code>delegate</code> of @c AGSQueryTask.
 
 @define{AGSQueryTask.h, ArcGIS}
 @since 1.0
 */
@protocol AGSQueryTaskDelegate <NSObject>

@optional
/** Tells the delegate that @c AGSQueryTask completed successfully with the 
 provided results.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param featureSet The feature set returned by executing query.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didExecuteWithFeatureSetResult:(AGSFeatureSet *)featureSet;

/** Tells the delegate that @c AGSQueryTask encountered an error.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didFailWithError:(NSError *)error;

/** Tells the delegate that @c AGSQueryTask completed query for IDs successfully 
 with the provided results.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param objectIds The array of object IDs returned by executing query.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didExecuteWithObjectIds:(NSArray *)objectIds;

/** Tells the delegate that @c AGSQueryTask encountered an error while performing 
 query for IDs.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didFailQueryForIdsWithError:(NSError *)error;

/** Tells the delegate that @c AGSQueryTask completed query for related features 
 successfully with the provided results.
 
 The related features are returned as a dictionary of key-value pairs.
 Keys contain <code>NSNumber</code> objects representing IDs from @c AGSRelationshipQuery 
 <code>objectIds</code>. Values contain arrays of @c AGSFeatureSet objects representing the 
 corresponding related features.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param relatedFeatures The related features returned by executing query.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didExecuteWithRelatedFeatures:(NSDictionary *)relatedFeatures;

/** Tells the delegate that @c AGSQueryTask encountered an error while performing 
 query for related features.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didFailRelationshipQueryWithError:(NSError *)error;

/** Tells the delegate that @c AGSQueryTask completed query with feature count 
 successfully.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param count The feature count returned by the query.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didExecuteWithFeatureCount:(NSInteger)count;

/** Tells the delegate that @c AGSQueryTask encountered an error while performing 
 query for feature count.
 @param queryTask The task which performed the query.
 @param op <code>NSOperation</code> that performed the query task.
 @param error Information about the error returned by the service.
 @since 1.0
 */
- (void)queryTask:(AGSQueryTask *)queryTask operation:(NSOperation*)op didFailQueryFeatureCountWithError:(NSError*)error;

@end


