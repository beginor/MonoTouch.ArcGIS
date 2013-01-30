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

@class AGSTask;
@class AGSImageServiceIdentifyParameters;
@class AGSImageServiceIdentifyResult;
@class AGSCredential;
@protocol AGSImageServiceIdentifyDelegate;

/** @brief Identify operation for an Image Service resource.
 
 Performs an identify operation on an image service resource. It identifies
 the content of an image service for the input location and mosaic rule.
 @define{AGSImageServiceIdentifyTask.h, ArcGIS}
 
 This identify task needs a URL to a REST resource that represents an Image Service.
 For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/World/Temperature/ImageServer

 @since 1.8
 */
@interface AGSImageServiceIdentifyTask : AGSTask

/** Delegate to be notified when the task succeeds or fails.
 @since 1.8
 */
@property (nonatomic, weak) id<AGSImageServiceIdentifyDelegate> delegate;

/** Executes an identify operation with the specified parameters. The #delegate
 will be notified when the operation completes or if an error is encountered.
 
 It relies on the <i>Identify</i> operation
 of the REST resource.
 
 @param identifyParams Parameters to be sent to the identify resource of the image service.
 @return <code>NSOperation</code> for current execute request.
 @since 1.8
 @see AGSImageServiceIdentifyDelegate
 */
- (NSOperation*)identifyWithParameters:(AGSImageServiceIdentifyParameters*)identifyParams;

@end

/** @brief A delegate of @c AGSImageServiceIdentifyTask.
 
 A protocol which must be adopted by any class wishing to be notified when the
 @c AGSImageServiceIdentifyTask completes successfully or encounters an error. An
 instance of the class must then be set as the delegate of @c AGSImageServiceIdentifyTask.
 
 @define{AGSImageServiceIdentifyTask.h, ArcGIS}
 @since 1.8
 */
@protocol AGSImageServiceIdentifyDelegate <NSObject>

@required
/** Tells the delegate that @c AGSImageServiceIdentifyTask completed successfully
 with the provided result.
 @param identifyTask The task which performed the operation.
 @param op <code>NSOperation</code> that performed the identify.
 @param result The image service identify result.
 @since 1.8
 */
- (void)imageServiceIdentifyTask:(AGSImageServiceIdentifyTask*)identifyTask operation:(NSOperation*)op didIdentifyWithResult:(AGSImageServiceIdentifyResult *)result;

@optional
/** Tells the delegate that @c AGSImageServiceIdentifyTask encountered an error.
 @param identifyTask The task which performed the operation.
 @param op <code>NSOperation</code> that performed the identify.
 @param error Information about the error returned by the server.
 @since 1.8
 */
- (void)imageServiceIdentifyTask:(AGSImageServiceIdentifyTask*)identifyTask operation:(NSOperation*)op didFailToIdentifyWithError:(NSError *)error;

@end
