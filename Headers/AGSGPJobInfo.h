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

/** @file AGSGPJobInfo.h */ //Required for Globals API doc

/** @brief An object containing information about an asynchronous GP task.
 
 The instances of this class represent information pertaining to the execution 
 of an asynchronous geoprocessing task on the server. This class has no constructor.
 @define{AGSGPJobInfo.h, ArcGIS}
 @since 1.0
 @see AGSGeoprocessorDelegate
 */
@interface AGSGPJobInfo : NSObject

/** The unique identifier for the asynchronous GP task.
 @since 1.0
 */
@property(nonatomic, copy, readonly) NSString *jobId;

/** The current status of the job with id @p jobId. Possible values include -
 @li esriJobNew 
 @li esriJobSubmitted 
 @li esriJobWaiting 
 @li esriJobExecuting 
 @li esriJobSucceeded 
 @li esriJobFailed  
 @li esriJobTimedOut 
 @li esriJobCancelling 
 @li esriJobCancelled 
 @li esriJobDeleting 
 @li esriJobDeleted 
 @since 1.0
 */
@property(nonatomic, copy, readonly) NSString *jobStatus;

/** An array of @c AGSGPMessage objects related to the asynchronous GP task.
 @since 1.0
 */
@property(nonatomic, copy, readonly) NSArray *messages;

@end

