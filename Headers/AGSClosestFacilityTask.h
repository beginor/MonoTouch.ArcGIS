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



/** @file AGSClosestFacilityTask.h */

@class AGSTask;
@class AGSClosestFacilityTaskParameters;
@class AGSClosestFacilityTaskResult;
@class AGSCredential;
@protocol AGSClosestFacilityTaskDelegate;

/** @brief A task to find closest facilities around a location.
 
 Instances of this class represent tasks that can find the find closest facilities around any location on a network. 
 Finding the closest hospital to an accident, the closest police cars to a crime scene, and the closest store 
 to a customer's address are all examples of closest facility problems. When finding closest facilities, you can specify 
 how many to find and whether the direction of travel is toward or away from them. Once you've found 
 the closest facilities, you can display the best route to or from them, return the
 travel cost for each route, and display directions to each facility. Additionally, 
 you can specify an impedance cutoff beyond which the task should not search for a facility. 
 For instance, you can set up a closest facility problem to search for hospitals within 15 minutes' 
 drive time of the site of an accident. Any hospitals that take longer than 
 15 minutes to reach will not be included in the results
 
 A closest facility task needs a URL to a REST resource that represents a Closest Facility layer in a Network Analyst service.
 For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer/Closest%20Facility
 
 @avail{10.0}
 @see @concept{Closest_Facility_Task/00pw00000058000000/, Using a Closest Facility Task}
 @see @sample{3092d2d547ef4f0c92d333841df8ee68, Closest Facility}
 @since 1.8
 */
@interface AGSClosestFacilityTask : AGSTask

/** Delegate to be notified when the closest facility operation has completed or returned 
 an error.
 @since 1.8
 */
@property (nonatomic, weak) id<AGSClosestFacilityTaskDelegate> delegate;

/** Initialize a new, autoreleased closest facility task with the given url.
 @param url The url of the closest facility layer.
 @return A new, autoreleased closest facility task object.
 @since 1.8
 */
+ (id)closestFacilityTaskWithURL:(NSURL *)url;

/** Initialize a new, autoreleased closest facility task with the given url and credential.
 @param url The url of the closest facility layer.
 @param cred The credential to be used to access the secured resource.
 @return A new, autoreleased closest facility task object.
 @since 1.8
 */
+ (id)closestFacilityTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Performs a closest facility operation with the given input parameters.
 @param closestFacilityParams The input parameters for the closest facility operation.
 @return <code>NSOperation</code> for the current closest facility task.
 @since 1.8
 @see @c AGSClosestFacilityTaskDelegate#closestFacilityTask:operation:didSolveClosestFacilityWithResult: , method on delegate for success
 @see @c AGSClosestFacilityTaskDelegate#closestFacilityTask:operation:didFailSolveWithError:  , method on delegate for failure
 */
- (NSOperation*)solveClosestFacilityWithParameters:(AGSClosestFacilityTaskParameters*)closestFacilityParams;

/** Retrieves the default closest facility parameters as defined by the service. 
 @return <code>NSOperation</code> for the request.
 @since 1.8
 @see @c AGSClosestFacilityTaskDelegate#closestFacilityTask:operation:didRetrieveDefaultClosestFacilityTaskParameters: , method on delegate for success
 @see @c AGSClosestFacilityTaskDelegate# closestFacilityTask:operation:didFailToRetrieveDefaultClosestFacilityTaskParametersWithError: , method on delegate for failure

 */
- (NSOperation*)retrieveDefaultClosestFacilityTaskParameters;

@end


/** @brief A delegate of @c AGSClosestFacilityTask.
 
 A protocol which must be adopted by any class wishing to be notified when 
 @c AGSClosestFacilityTask completes successfully or encounters an error. An 
 instance of the class must then be set as the delegate of @c AGSClosestFacilityTask.
 
 @define{AGSClosestFacilityTask.h, ArcGIS}
 @since 1.8
 */
@protocol AGSClosestFacilityTaskDelegate <NSObject>

@required

/** Tells the delegate that the closest facility operation completed successfully.
 @param closestFacilityTask The task that performed the closest facility operation.
 @param op <code>NSOperation</code> that performed the closest facility task.
 @param closestFacilityTaskResult The result of the closest facility operation.
 @since 1.8
 */
- (void)closestFacilityTask:(AGSClosestFacilityTask*)closestFacilityTask operation:(NSOperation*)op didSolveClosestFacilityWithResult:(AGSClosestFacilityTaskResult*)closestFacilityTaskResult;

@optional

/** Tells the delegate that an error was encountered while performing the 
 closest facility operation.
 @param closestFacilityTask The task that performed the closest facility operation.
 @param op <code>NSOperation</code> that performed the closest facility task.
 @param error The error encountered by the closest facility operation.
 @since 1.8
 */
- (void)closestFacilityTask:(AGSClosestFacilityTask*)closestFacilityTask operation:(NSOperation*)op didFailSolveWithError:(NSError*)error;

/** Tells the delegate that the default closest facility parameters were retrieved successfully.
 @param closestFacilityTask The task that performed the request for default parameters.
 @param op <code>NSOperation</code> that performed the request.
 @param closestFacilityParams The default closest facility parameters for the task.
 @since 1.8
 */
- (void)closestFacilityTask:(AGSClosestFacilityTask*)closestFacilityTask operation:(NSOperation*)op didRetrieveDefaultClosestFacilityTaskParameters:(AGSClosestFacilityTaskParameters*)closestFacilityParams;

/** Tells the delegate that an error was encountered while retrieving the default
 closest facility parameters.
 @param closestFacilityTask The task that performed the request for default parameters.
 @param op <code>NSOperation</code> that performed the request.
 @param error The error encountered by the request.
 @since 1.8
 */
- (void)closestFacilityTask:(AGSClosestFacilityTask*)closestFacilityTask operation:(NSOperation*)op didFailToRetrieveDefaultClosestFacilityTaskParametersWithError:(NSError*)error;
@end