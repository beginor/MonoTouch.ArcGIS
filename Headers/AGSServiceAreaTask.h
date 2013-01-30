/*
 COPYRIGHT 2011 ESRI
 
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



/** @file AGSServiceAreaTask.h */

@class AGSTask;
@class AGSServiceAreaTaskParameters;
@class AGSServiceAreaTaskResult;
@protocol AGSServiceAreaTaskDelegate;

/** @brief A task to compute service areas.
 
 Instances of this class represent tasks that can compute service areas. A service area is a region that encompasses 
 all accessible streets, that is, streets that lie within a specified impedance. For instance, the 10-minute service area 
 for a facility includes all the streets that can be reached within 10 minutes from that facility. 
 
 A service area task needs a URL to a REST resource that represents a Service Area layer in a Network Analyst service.
 For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer/Service%20Area

 @avail{10.0}
 @see @concept{Service_Area_Task/00pw00000057000000/, Using a Service Area Task}
 @see @sample{1d5c8a7a86334b1a8191ac61cfe0d52e, Service Area}
 @since 1.8
 */
@interface AGSServiceAreaTask : AGSTask

/** Delegate to be notified when the service area operation has completed or returned 
 an error.
 @since 1.8
 */
@property (nonatomic, weak) id<AGSServiceAreaTaskDelegate> delegate;

/**
 @since 1.8
 */
+ (id)serviceAreaTaskWithURL:(NSURL *)url;

/**
 @since 1.8
 */
+ (id)serviceAreaTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Performs a service area operation with the given input parameters.
 @param serviceAreaParams The input parameters for the service area operation.
 @return <code>NSOperation</code> for the current service area task.
 @since 1.8
 @see @c AGSServiceAreaTaskDelegate#serviceAreaTask:operation:didSolveServiceAreaWithResult: , method on delegate for success
 @see @c AGSServiceAreaTaskDelegate#serviceAreaTask:operation:didFailSolveWithError:  , method on delegate for failure
 */
- (NSOperation*)solveServiceAreaWithParameters:(AGSServiceAreaTaskParameters*)serviceAreaParams;

/** Retrieves the default service area parameters. 
 @return <code>NSOperation</code> for the request.
 @since 1.8
 @see @c AGSServiceAreaTaskDelegate#serviceAreaTask:operation:didRetrieveDefaultServiceAreaTaskParameters: , method on delegate for success
 @see @c AGSServiceAreaTaskDelegate#serviceAreaTask:operation:didFailToRetrieveDefaultServiceAreaTaskParametersWithError:  , method on delegate for failure
 */
- (NSOperation*)retrieveDefaultServiceAreaTaskParameters;

@end


/** @brief A delegate of @c AGSServiceAreaTask.
 
 A protocol which must be adopted by any class wishing to be notified when 
 @c AGSServiceAreaTask completes successfully or encounters an error. An 
 instance of the class must then be set as the delegate of @c AGSServiceAreaTask.
 
 @define{AGSServiceAreaTask.h, ArcGIS}
 @since 1.8
 */
@protocol AGSServiceAreaTaskDelegate <NSObject>

@required

/** Tells the delegate that the service area operation completed successfully.
 @param serviceAreaTask The task that performed the service area operation.
 @param op <code>NSOperation</code> that performed the service area task.
 @param serviceAreaTaskResult The result of the service area operation.
 @since 1.8
 */
- (void)serviceAreaTask:(AGSServiceAreaTask*)serviceAreaTask operation:(NSOperation*)op didSolveServiceAreaWithResult:(AGSServiceAreaTaskResult*)serviceAreaTaskResult;

@optional

/** Tells the delegate that an error was encountered while performing the 
 service area operation.
 @param serviceAreaTask The task that performed the service area operation.
 @param op <code>NSOperation</code> that performed the service area task.
 @param error The error encountered by the service area operation.
 @since 1.8
 */
- (void)serviceAreaTask:(AGSServiceAreaTask*)serviceAreaTask operation:(NSOperation*)op didFailSolveWithError:(NSError*)error;

/** Tells the delegate that the default service area parameters were retrieved successfully.
 @param serviceAreaTask The task that performed the request for default parameters.
 @param op <code>NSOperation</code> that performed the request.
 @param serviceAreaParams The default service area parameters for the task.
 @since 1.8
 */
- (void)serviceAreaTask:(AGSServiceAreaTask*)serviceAreaTask operation:(NSOperation*)op didRetrieveDefaultServiceAreaTaskParameters:(AGSServiceAreaTaskParameters*)serviceAreaParams;

/** Tells the delegate that an error was encountered while retrieving the default
 service area parameters.
 @param serviceAreaTask The task that performed the request for default parameters.
 @param op <code>NSOperation</code> that performed the request.
 @param error The error encountered by the request.
 @since 1.8
 */
- (void)serviceAreaTask:(AGSServiceAreaTask*)serviceAreaTask operation:(NSOperation*)op didFailToRetrieveDefaultServiceAreaTaskParametersWithError:(NSError*)error;
@end