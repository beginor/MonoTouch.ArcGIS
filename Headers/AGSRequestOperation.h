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

@class AGSCredential;
@class AGSCredentialCache;
@class AGSRunLoopOperation;
@class AGSProcessResultsOperation;
@protocol AGSSecuredResource;

/** @file AGSRequestOperation.h */ //Required for Globals API doc

/** @brief Base class for operations that perform http requests.
 
 This is a concurrent operation.
 
 The request will be asynchronously kicked off from the thread that the operation was
 created on. The request will execute in the background. If the response size is 
 above a certain threshold, then the operation may decide to parse the response 
 in a child operation that it kicks off. Once the response has been parsed the 
 action selectors will called from the thread that the operation was created on.
 
 
 @li This class encapsulates the logic for accessing secured (token or basic)
 resources. Including refreshing a token if it has expired. It also has the ability 
 to perform the parsing of the response in a child operation so that the main 
 thread of the application is not bogged down.
 
 @li This class, or a subclass thereof, is used by all the tasks execute requests across the wire.
 
 @li This class, or a subclass thereof, is also used by most of the layers for retrieving images or tiles.
 
 @li This class can be used directly, but you will probably use a subclass of it for getting
 back the response data in the format that you are looking for.
 
 @since 1.0
 */
@interface AGSRequestOperation : AGSRunLoopOperation

/** URL of the resource to make a request from.
 @since 1.0
 */
@property (readonly, copy) NSURL *URL;

/** String to append to the end of a url to access a specific resource, such as 
 when exporting an image. 
 @since 1.0
 */
@property (readonly, copy) NSString *resource;

/** Query parameters to be used in the request to #URL.
 @since 1.0
 */
@property (readonly, copy) NSDictionary *query;

/** Flag to determine whether or not the request is a <code>GET</code> or 
 <code>POST</code>.
 @since 1.0
 */
@property (readonly) BOOL post;

/** Request object to be used instead of generating one on the fly.
 @since 1.0
 */
@property (readonly, strong) NSURLRequest *request;

/** A dictionary that can be filled with objects that need to be retrieved upon
 completion of an operation and are not passed back as results.
 @since 1.0
 */
@property (nonatomic, strong, readonly) NSMutableDictionary *state;

/** Credentials to access a secured resource.
 @since 1.0
 */
@property (nonatomic, strong, readwrite) AGSCredential *credential;

/** Credential cache used to access a secured resources.
 @since 10.1.1
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

/** The secure resource, if applicable, that is making the request.
 @since 10.1.1
 */
@property (nonatomic, weak, readwrite) id<AGSSecuredResource> securedResource;

/** The response of the request.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSURLResponse *response;

/** Whether the response should be cached. Default is YES
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) BOOL shouldCacheResponse;

/** The cache policy that should be used for making the web request.
 Default value is NSURLRequestUseProtocolCachePolicy
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) NSURLRequestCachePolicy requestCachePolicy;

/** The timeout interval (in seconds) for this request. Default value is 60.
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) NSTimeInterval timeoutInterval;

/** Initialize an <code>AGSRequestOperation</code> with the specified request.
 @param req Request to initialize the operation with.
 @return Initialized <code>AGSRequestOperation</code>.
 @since 1.0
 */
- (id)initWithRequest:(NSURLRequest *)req;

/** Initialize an <code>AGSRequestOperation</code> with the specified url.
 @param url URL to initialize the request operation.
 @return Initialized <code>AGSRequestOperation</code>.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url;

/** Initialize an <code>AGSRequestOperation</code> with the specified url and
 query parameters.
 @param url URL to initialize the request operation.
 @param query Query parameters to submit along with the request.
 @return Initialized <code>AGSRequestOperation</code>.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url queryParameters:(NSDictionary *)query;

/** Initialize an <code>AGSRequestOperation</code> with the specified url, 
 resource, and query parameters.
 @param url URL to initialize the request operation.
 @param resource Resource to access off of the url.
 @param query Query parameters to submit along with the request to the resource.
 @return Initialized <code>AGSRequestOperation</code>
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url resource:(NSString *)resource queryParameters:(NSDictionary *)query;

/** Designated initializer. Initialize an <code>AGSRequestOperation</code> with 
 the specified url, resource, query parameters, and post flag.
 @param url URL to initialize the request operation.
 @param resource  Resource to access off of the url.
 @param query Query parameters to submit along with the request to the resource.
 @param post Post flag to determine whether or not to use a <code>GET</code> or 
 <code>POST</code>,
 @return Initialized <code>AGSRequestOperation</code>
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url resource:(NSString *)resource queryParameters:(NSDictionary *)query doPOST:(BOOL)post;

/** Class method to retrieve the shared operation queue that is handling all 
 operations. This is where all <code>AGSRequestOperations</code> will be queued.
 @since 1.0
 */
+ (NSOperationQueue *)sharedOperationQueue;

/** Subclasses can override this if processing the data will take a long time 
 and the superclass should call the process method on a bg thread.
 @param data to be processed in the background
 @since 1.0
 */
-(BOOL)shouldProcessResultDataInBackground:(NSData*)data;

/** Methods to override to process results and errors before sending them to the 
 callbacks
 @param data to be processed from the request
 @since 1.0
 */
-(id)processResultData:(NSData*)data;

/** Method to override to process the error that results, if any, from a request
 @since 1.0
 */
-(NSError *)processError:(NSError *)error;

@end
