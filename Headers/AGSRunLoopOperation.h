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

#import <Foundation/Foundation.h>
#include "pthread.h"

/** Represents the block signature for a request operation's completion handler.
 @since 2.3
 */
typedef void (^AGSIdBlock)(id obj);

/** Represents the block signature for a request operation's error handler.
 @since 2.3
 */
typedef void (^AGSErrorBlock)(NSError *error);

/** @brief Base class for concurrent operations that should run on a run loop thread.
 @since 2.1
 */
@interface AGSRunLoopOperation : NSOperation {
 @private
    BOOL _executing;
    BOOL _finished;
    id _target;
    NSThread *_runLoopThread;
    SEL _action;
    SEL _errorAction;
    id _result;
	BOOL _waitUntilActionSelectorIsDone;
}

/** Target class to perform the operation from.
 @since 2.1
 */
@property (nonatomic, assign) id target;

/** Selector to be called if the operation succeeds. The selector must represent a method that accepts 2 arguments of type NSOperation and NSDictionary respectively.
 @since 2.1
 */
@property (nonatomic, assign) SEL action;

/** Selector to be called if the operation fails. The selector must represent a method that accepts 2 arguments of type NSOperation and NSError respectively.
 @since 2.1
 */
@property (nonatomic, assign) SEL errorAction;

/** The thread that this concurrent operation should start it's work on.
 @since 2.1
 */
@property (nonatomic, retain, readonly) NSThread *runLoopThread;

/** Defaults to <code>NO</code>, but it is helpful if this operation is a 
 dependency for another operation and the action selector processes some results 
 that the dependent operation needs before it can start.
 @since 2.1
 */
@property (nonatomic, assign) BOOL waitUntilActionSelectorIsDone;

/** The results of an operation.
 @since 2.1
 */
@property (nonatomic, retain, readonly ) id result;

/** Completion handler that will be called when the operation is 
 completed successfully. This handler will only be called when a target is not
 specified. The AGSIdBlock is called with an object of type id passed as
 the parameter.
 @since 2.3
 */
@property (nonatomic, copy) AGSIdBlock completionHandler;

/** Error handler that will be called when an error is returned
 by the operation. This handler will only be called when a target is not
 specified. The AGSErrorBlock is called with an object of type NSError passed as
 the parameter.
 @since 2.3
 */
@property (nonatomic, copy) AGSErrorBlock errorHandler;

/**
 A subclass should call finishWithError: when the operation is complete, 
 passing the desired result. If an error ocurred, pass an NSError object and
 the errorAction selector will be called. Any other type of result will
 cause the action selector to be fired.
 
 Note that this will call -operationWillFinish before returning.
 @since 2.1
*/
- (void)finishWithResult:(id)result;

/** A function that can be overridden by subclasses to start actual operation work.
 @since 2.1
 */
- (void)operationDidStart;

/** A function that can be overridden by subclasses to know when the operation was finished.
 This may get called even if operationDidStart was never called.
 @since 2.1
 */
- (void)operationWillFinish;

@end
