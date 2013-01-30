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




/** @file AGSRouteTask.h */

@class AGSTask;
@class AGSCredential;
@class AGSRouteTaskParameters;
@class AGSRouteTaskResult;
@protocol AGSRouteTaskDelegate;

/** @brief A task to compute routes.
 
 Instances of this class represent tasks than can find the best route 
 to get from one location to another or to visit several locations. 
 
 The best route can be the quickest, shortest, or most scenic route, depending on the impedance chosen. 
 If the impedance is time, then the best route is the quickest route. Hence, the best route can
 be defined as the route that has the lowest impedance.
 
 A route task needs a URL to a REST resource that represents a Route layer in a Network Analyst service.
 For example, http://tasks.arcgisonline.com/ArcGIS/rest/services/NetworkAnalysis/ESRI_Route_NA/NAServer/Route

 @see @concept{Route_Task/00pw00000056000000/, Using a Route Task}
 @see @sample{e4fa8dafbe83475882ac9c0fd0a075c7, Routing}
 @since 1.8
 */
@interface AGSRouteTask : AGSTask

/** Delegate to be notified when the solve operation has completed or returned 
 an error.
 @since 1.8
 */
@property (nonatomic, weak) id<AGSRouteTaskDelegate> delegate;

/** Return an initialized, auto released, route task
 @param url URL to a REST resource that represents a Route layer in a Network Analyst service
 @since 1.8
 */
+ (id)routeTaskWithURL:(NSURL *)url;

/** Return an initialized, auto released, route task
 @param url URL to a REST resource that represents a Route layer in a Network Analyst service
 @param cred Credentials need to access the secured service
 @since 1.8
 */
+ (id)routeTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;


/** Solves a route with the given input parameters. It relies on the <i>Solve Route</i> operation
 of the REST resource.
 @param routeParams The input parameters for the solve operation.
 @return <code>NSOperation</code> for the current solve task.
 @since 1.8
 @see @c AGSRouteTaskDelegate#routeTask:operation:didSolveWithResult: , method on delegate for success
 @see @c AGSRouteTaskDelegate#routeTask:operation:didFailSolveWithError: , method on delegate for failure
 */
- (NSOperation*)solveWithParameters:(AGSRouteTaskParameters*)routeParams;

/** Retrieves the default route parameters. 
 @return <code>NSOperation</code> for the request.
 @since 1.8
 @see @c AGSRouteTaskDelegate#routeTask:operation:didRetrieveDefaultRouteTaskParameters: , method on delegate for success
 @see @c AGSRouteTaskDelegate#routeTask:operation:didFailToRetrieveDefaultRouteTaskParametersWithError: , method on delegate for failure
 */
- (NSOperation*)retrieveDefaultRouteTaskParameters;

@end

/** @brief A delegate of @c AGSRouteTask.
 
 A protocol which must be adopted by any class wishing to be notified when 
 @c AGSRouteTask completes successfully or encounters an error. An 
 instance of the class must then be set as the delegate of @c AGSRouteTask.
 
 @define{AGSRouteTask.h, ArcGIS}
 @since 1.8
 */
@protocol AGSRouteTaskDelegate <NSObject>

@required

/** Tells the delegate that the solve operation completed successfully.
 @param routeTask The route task that performed the solve operation.
 @param op <code>NSOperation</code> that performed the solve task.
 @param routeTaskResult The result of the solve operation.
 @since 1.8
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didSolveWithResult:(AGSRouteTaskResult*)routeTaskResult;

@optional

/** Tells the delegate that an error was encountered while performing the 
 solve operation.
 @param routeTask The route task that performed the solve operation.
 @param op <code>NSOperation</code> that performed the solve task.
 @param error The error encountered by the solve operation.
 @since 1.8
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didFailSolveWithError:(NSError*)error;

/** Tells the delegate that the default route parameters were retrieved successfully.
 @param routeTask The route task that performed the request for default parameters.
 @param op <code>NSOperation</code> that performed the request.
 @param routeParams The default route parameters for the task.
 @since 1.8
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didRetrieveDefaultRouteTaskParameters:(AGSRouteTaskParameters*)routeParams;

/** Tells the delegate that an error was encountered while retrieving the default
 route parameters.
 @param routeTask The route task that performed the request for default parameters.
 @param op <code>NSOperation</code> that performed the request.
 @param error The error encountered by the request.
 @since 1.8
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didFailToRetrieveDefaultRouteTaskParametersWithError:(NSError*)error;
@end

