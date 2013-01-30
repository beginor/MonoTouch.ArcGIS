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

@protocol AGSGeoprocessorDelegate;
@class AGSTask;
@class AGSSpatialReference;
@class AGSGeometry;
@class AGSEnvelope;
@class AGSImageParameters;
@class AGSGPParameterValue;
@class AGSGPMessage;
@class AGSDynamicMapServiceLayer;
@class AGSCredential;
@class AGSJSONRequestOperation;
@class AGSGPResultLayer;
@class AGSGPJobInfo;
@class AGSTimerContainer;


/** @file AGSGeoprocessor.h */ //Required for Globals API doc

#pragma mark -

/** @brief An object to invoke geoprocessing tasks.
 
 Instances of this class represent a geoprocessor. Geoprocessor is used to invoke 
 geoprocessing tasks of an ArcGIS Server Geoprocessing Service. Geoprocessing 
 allows you to automate your GIS tasks such as spatial analysis or data 
 management. A Geoprocessing task takes information from the user and existing 
 datasets, applies analytic functions and spatial operators, and derives a new 
 result.
 
 A geoprocessor needs a URL to a REST resource that represents a task in a Geoprocessing service.
 For example,http://sampleserver2.arcgisonline.com/ArcGIS/rest/services/Elevation/ESRI_Elevation_World/GPServer/ProfileService
 
 @see <a href="http://help.arcgis.com/en/arcgisdesktop/10.0/help/index.html#//002s00000001000000.htm">What is geoprocessing?</a>
 @see <a href="http://help.arcgis.com/en/arcgisdesktop/10.0/help/index.html#/An_overview_of_geoprocessing_with_ArcGIS_Server/002v00000001000000/">Geoprocessing with ArcGIS Server</a>
 @see @concept{Geoprocessor/00pw0000001m000000/, Using a Geoprocessor} 
 @see @sample{2d6cea4220e14b82ac3a442000848d17, Synchronous GP}
 @see @sample{8b5c66b85084439789311bb2f543a731, Asynchronous GP}
 @since 1.0
 */
@interface AGSGeoprocessor : AGSTask

/** List of asynchronous gp task operation types.
 @since 1.0
 */
typedef enum {
	AGSGPAsyncOperationTypeSubmit = 0,
	AGSGPAsyncOperationTypeCheckStatus,
	AGSGPAsyncOperationTypeQueryResultData,
	AGSGPAsyncOperationTypeQueryResultImage,
	AGSGPAsyncOperationTypeQueryResultImageLayer,
    AGSGPAsyncOperationTypeCancel
} AGSGPAsyncOperationType;

/** Delegate to be notified when task completes successfully or encounters an error.
 @since 1.0
 */
@property (nonatomic, weak) id<AGSGeoprocessorDelegate> delegate;

/** The intermediate spatial reference that the geoprocessing task will use to 
 perform geometric operations. If @p processSpatialReference is specified and  
 #outputSpatialReference is not specified, the result geometries will be returned 
 in @p processSpatialReference.
 @since 1.0
 */
@property (nonatomic, strong) AGSSpatialReference *processSpatialReference;

/** The spatial reference of the result geometries. If not specified, the result 
 geometries are in the same spatial reference as the input geometries. If 
 #processSpatialReference is specified and @p outputSpatialReference is not specified, 
 the result geometries will be returned in #processSpatialReference.
 @since 1.0
 */
@property (nonatomic, strong) AGSSpatialReference *outputSpatialReference;

/** Interval at which to check the status of a geoprocessing task being executed. 
 Only applies to tasks which are executed in asynchronous mode.
 
 Default is 5 seconds, but you should adjust this value in order to minimize the 
 number of times the status is checked. The value you choose will largely depend
 upon how long your geoprocessing task takes to complete.
 
 If you set the interval to 0, status updates will be suspended. Likewise, if you
 set the value to non-zero, updates will resume with the new interval.
 
 @since 1.0
 */
@property (nonatomic, assign) NSTimeInterval interval;

/** Initialize an autoreleased geoprocessor.
 @param url URL to a geoprocessing service's task.
 @return A new, autoreleased, geoprocessor object
 @since 1.0
 */
+ (id)geoprocessorWithURL:(NSURL *)url;

/** Initialize an autoreleased geoprocessor.
 @param url URL to a geoprocessing service's task.
 @param cred <code>AGSCredential</code> used to access the secure resource.
 @return A new, autoreleased, geoprocessor object.
 @since 1.0
 */
+ (id)geoprocessorWithURL:(NSURL *)url credential:(AGSCredential *)cred;

/** Executes a geoprocessing task in synchronous mode. The results of the task 
 are returned when the operation finishes. The #delegate will be notified when 
 the task completes or encounters an error.
 
 It relies on the <i>Execute Task</i> operation
 of the REST resource.
 
 @param params Array of @c AGSGPParameterValue objects for invoking the task. 
 These input parameters are listed in the parameters section of the geoprocessing 
 task resource in ArcGIS Server REST Services Directory. Their @em Direction 
 property is set to @em esriGPParameterDirectionInput.
 @return <code>NSOperation</code> for current request.
 @since 1.0
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:didExecuteWithResults:messages: , method on delegate for success
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:didFailExecuteWithError: , method on delegate for error
 
 */
- (NSOperation *)executeWithParameters:(NSArray *)params;

/** Executes a geoprocessing task in asynchronous mode - the operation finishes 
 immediately, even though the task may continue to run on the server. This is 
 commonly referred to as submitting a job. The Geoprocessor regularly polls the 
 server to determine if the job completed. The polling rate is specified by 
 #interval. The #delegate is notified when the job is submitted, the job 
 completes, or when the job's status is polled.
 @param params Array of @c AGSGPParameterValue objects for invoking the task. 
 These input parameters are listed in the parameters section of the geoprocessing 
 task resource in Services Directory. Their @em Direction property is set
 to @em esriGPParameterDirectionInput.
 
 It relies on the <i>Submit Job</i> operation
 of the REST resource.
 
 @return <code>NSOperation</code> for the current submit request.
 @since 1.0
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:didSubmitJob: , method on delegate for when job is submitted successfully
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:jobDidSucceed: , method on delegate for when submitted job succeeds
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:jobDidFail: , method on delegate for when submitted job failed

 */
- (NSOperation *)submitJobWithParameters:(NSArray *)params;

/** This method fires a request for the status of the job designated by @p jobId.
 This should only be used if you have previously set the #interval to 0 in order
 to stop constant status updates. The #delegate is notified when the status
 has been successfully retrieved or if an error is encountered.
 @param jobId The id of the job whose status is being requested.
 @return <code>NSOperation</code> for the current request.
 @since 1.0
 @see @c AGSGeoprocessorDelegate#geoprocessor:willCheckJobStatus: 
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:didCheckJobStatus: 
*/
- (NSOperation *)checkStatusForJob:(NSString*)jobId;

/** Fetch the results of the geoprocessing task. Only relevant for tasks which 
 are executed in asynchronous mode. The #delegate is notified when the results 
 are retrieved or encounters an error.
 @param jobId The jobId returned when the geoprocessing task is executed in 
 asynchronous mode.
 @param paramName Name of the output parameter whose value is to be fetched. 
 Output parameters are listed in the parameters section of the geoprocessing task 
 resource in Services Directory. Their @em Direction property is set
 to @em esriGPParameterDirectionOutput.
 @return <code>NSOperation</code> for current request.
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:didQueryWithResult:forJob:
 @since 1.0
 */
- (NSOperation*)queryResultData:(NSString *)jobId paramName:(NSString *)paramName;

/** Fetch the resulting image of the geoprocessing task when it is associated 
 with a result map service. Only relevant for tasks which are executed in 
 asynchronous mode. The #delegate is notified when the result is retrieved
 or encounters an error.
 @param jobId The jobId returned when the geoprocessing task is executed in 
 asynchronous mode.
 @param paramName Name of the output parameter whose value is to be fetched. Output 
 paramters are listed in the parameters section of the geoprocessing task 
 resource in Services Directory. Their @em Direction property is set
 to @em esriGPParameterDirectionOutput.
 @param imageParams Specifies the properties of the result image.
 @return <code>NSOperation</code> for current request.
 @since 1.0
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:didQueryWithResultImage:forJob:
 */
- (NSOperation*)queryResultImage:(NSString *)jobId paramName:(NSString *)paramName imageParams:(AGSImageParameters *)imageParams;

/** Fetch the resulting image layer of the geoprocessing task as an 
 @c AGSGPResultLayer. Only relavent for tasks which are executed in asynchronous 
 mode and are associated with a result map service. The #delegate is notified 
 when the result is retrieved or encounters an error.
 @param jobId The jobId returned when the geoprocessing task is executed in 
 asynchronous mode.
 @param paramName Name of the output parameter whose value is to be fetched. 
 Output parameters are listed in the parameters section of the geoprocessing 
 task resource in the Services Directory. Their @em Direction property is set to 
 @em esriGPParameterDirectionOutput.
 @return <code>NSOperation</code> for current request.
 @since 1.0
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:didQueryWithResultImageLayer:forJob:
 */
- (NSOperation*)queryResultImageLayer:(NSString *)jobId paramName:(NSString *)paramName;

/** Cancel the job with the given jobId. The #delegate will be notified upon success or failure.
 @param jobId The id of the job to cancel.
 @return The operation associated with the request.
 @avail{10.1}
 @since 2.3
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:didCancelJob: , method on delegate for when job cancelled
 @see @c AGSGeoprocessorDelegate#geoprocessor:operation:didFailToCancelJob:withError:, method on delegate for when job not cancelled

 */
- (NSOperation*)cancelJob:(NSString*)jobId;

@end


#pragma mark -

/** @brief A delegate of @c AGSGeoprocessor.
 
 A protocol which must be adopted by any class wishing to be notified when the 
 @c AGSGeoprocessor completes an operation successfully or encounters an error.
 An instance of the class must then be set as the delegate of @c AGSGeoprocessor.
 
 @define{AGSGeoprocessor.h, ArcGIS}
 @since 1.0
 */
@protocol AGSGeoprocessorDelegate <NSObject>

@optional
/** Tells the delegate that @c AGSGeoprocessor successfully invoked the 
 geoprocessing task in synchronous mode.
 @param geoprocessor The geoprocessor object which executed the task.
 @param op <code>NSOperation</code> that performed the task.
 @param results The array of @c AGSGPParameterValue objects representing output 
 parameters of the task and their values.        
 @param messages The array of @c AGSGPMessage objects containing details of task 
 execution.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op didExecuteWithResults:(NSArray *)results messages:(NSArray *)messages;

/** Tells the delegate that @c AGSGeoprocessor encountered an error when trying
 to execute the synchronous task.
 @param geoprocessor The geoprocessor object which executed the task.
 @param op <code>NSOperation</code> that performed the task.
 @param error Information about the error returned by the geoprocessing task 
 execution.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op didFailExecuteWithError:(NSError*)error;

/** Tells the delegate that the job submitted by @c AGSGeoprocessor completed 
 successfully. See <code>didSubmitJob:</code> for 
 notification of when the job was actually submitted.
 @param geoprocessor The geoprocessor which submitted the job.
 @param op <code>NSOperation</code> that performed the task.
 @param jobInfo @c AGSGPJobInfo object containing the jobId, status and messages.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op jobDidSucceed:(AGSGPJobInfo*)jobInfo;

/** Tells the delegate that @c AGSGeoprocessor successfully retrieved a result 
 of the completed job.
 @param geoprocessor The geoprocessor object which executed the task.
 @param op <code>NSOperation</code> that performed the task.
 @param result an @c AGSGPParameterValue representing the value of the output 
 parameter requested.
 @param jobId Id of the job which finished through
 <code>queryResultData:paramName:</code>.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op didQueryWithResult:(AGSGPParameterValue*)result forJob:(NSString*)jobId;

/** Tells the delegate that @c AGSGeoprocessor successfully retrieved a result
 image of the completed job.
 @param geoprocessor The geoprocessor object which executed the task.
 @param op <code>NSOperation</code> that performed the task.
 @param image An <code>AGSImage</code> representing the resulting image 
 parameter requested. 
 @param jobId Id of the job which finished through 
 <code>queryResultImage:paramName:imageParams:</code>.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op didQueryWithResultImage:(AGSImage*)image forJob:(NSString*)jobId;

/** Tells the delegate that @c AGSGeoprocessor successfully retrieved the result 
 image layer of the completed job.
 @param geoprocessor The geoprocessor object which executed the task.
 @param op <code>NSOperation</code> that performed the task.
 @param lyr Dynamic layer representing the results of the task.
 @param jobId Id of the job which finished.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op didQueryWithResultImageLayer:(AGSGPResultLayer*)lyr forJob:(NSString*)jobId;

/** Tells the delegate that @c AGSGeoprocessor encountered an error while 
 executing the geoprocessing task in asynchronous mode.
 @param geoprocessor The task called to execute asynchronously.
 @param op <code>NSOperation</code> that performed the task.
 @param opType @c AGSGPAsyncOperationType representing the type of operation that failed.
 @param error Information about the error returned by the geoprocessing task.
 @param jobId Id of the job which failed.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op ofType:(AGSGPAsyncOperationType)opType didFailWithError:(NSError *)error forJob:(NSString*)jobId;
/** Tells the delegate a job was successfully submitted by @c AGSGeoprocessor by 
 executing the geoprocessing task in asynchronous mode.
 @param geoprocessor The geoprocessor called to submit job.
 @param op <code>NSOperation</code> that performed the task.
 @param jobInfo @c AGSGPJobInfo object containing the jobId, status and messages. 
 execution.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op didSubmitJob:(AGSGPJobInfo*)jobInfo;

/** Tells the delegate that the status of the @p jobId within @p jobInfo will be 
 checked.
 @param geoprocessor The geoprocessor called to submit job.
 @param jobInfo @c AGSGPJobInfo object containing the jobId, status and messages.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor willCheckJobStatus:(AGSGPJobInfo*)jobInfo;

/** Tells the delegate that @c AGSGeoprocessor fetched an updated status for the 
 submitted job.
 @param geoprocessor The geoprocessor which submitted the job and checked the 
 status.
 @param op <code>NSOperation</code> that performed the task.
 @param jobInfo @c AGSGPJobInfo object containing the jobId, status and messages.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op didCheckJobStatus:(AGSGPJobInfo*)jobInfo;

/** Tells the delegate that the job submitted by @c AGSGeoprocessor encountered 
 an error. 
 @param geoprocessor The geoprocessor which submitted the job.
 @param op <code>NSOperation</code> that performed the task.
 @param jobInfo @c AGSGPJobInfo object containing the jobId, status and messages.
 execution.
 @since 1.0
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op jobDidFail:(AGSGPJobInfo*)jobInfo;

/** Tells the delegate that the job was cancelled successfully.
 @param geoprocessor The geoprocessor which submitted the cancel request.
 @param op The operation that performed the task.
 @param jobInfo @c AGSGPJobInfo object containing the jobId, status and messages.
 @avail{10.1}
 @since 2.3
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op didCancelJob:(AGSGPJobInfo*)jobInfo;

/** Tells the delegate that the job was not cancelled.
 @param geoprocessor The geoprocessor which submitted the cancel request.
 @param op The operation that performed the task.
 @param jobInfo @c AGSGPJobInfo object containing the jobId, status and messages.
 @param error The NSError associated with the failure.
 @avail{10.1}
 @since 2.3
 */
- (void)geoprocessor:(AGSGeoprocessor *)geoprocessor operation:(NSOperation*)op didFailToCancelJob:(AGSGPJobInfo*)jobInfo withError:(NSError*)error;

@end