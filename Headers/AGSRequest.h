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

/** @file AGSRequest.h */ //Required for Globals API doc

/** @brief Wrapper class request for synchronous requests to URLs
 
 This class provides some simple methods for requesting data from a URL
 synchronously. 
 
 @since 1.0
 */
@interface AGSRequest : NSObject

/** Creates a request object for a URL with the specified arguments
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param query parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or 
 <code>POST</code>
 @since 1.0
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url credential:(AGSCredential*)cred resource:(NSString *)operation queryParameters:(NSDictionary *)query doPOST:(BOOL)post;

/** Creates a request object for a URL with the specified arguments
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param queryParams parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or <code>POST</code>
 @param cachePolicy The cache policy that the request will honor.
 @param timeoutInterval The timeout interval (in seconds) of this request. Default is 60.
 @since 10.1.1
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url credential:(AGSCredential*)cred resource:(NSString *)operation queryParameters:(NSDictionary *)queryParams doPOST:(BOOL)post cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(NSTimeInterval)timeoutInterval;

/** Requests data synchronously from the url with the specified arguments
 @param url to request data from
 @param operation The specific resource to access at @p url
 @param query parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or 
 <code>POST</code>
 @param error Information about the request if it fails
 @since 1.0
 */
+ (NSData *)dataForURL:(NSURL *)url resource:(NSString *)operation queryParameters:(NSDictionary *)query doPOST:(BOOL)post error:(NSError**)error;

/** Requests data synchronously from the url with the specified arguments
 @param url to request data from
 @param cred <code>AGSCredential</code> to access the secured resource
 @param operation The specific resource to access at @p url
 @param query parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or 
 <code>POST</code>
 @param error Information passed back if the request fails
 @since 1.0
 */
+ (NSData *)dataForURL:(NSURL *)url credential:(AGSCredential*)cred resource:(NSString *)operation queryParameters:(NSDictionary *)query doPOST:(BOOL)post error:(NSError**)error;

/** Requests data synchronously for the specified request.
 @param request object containing url and query parameters
 @param error Information passed back if the request fails
 @since 1.0
 */
+ (NSData *)dataForRequest:(NSURLRequest *)request error:(NSError**)error;

/** Used to set some specific user agent information. This is useful for 
 analytics.
 @param additionalInfo to send along in the user agent string
 @since 1.0
 */
+ (void) setAdditionalUserAgentInfo:(NSString*)additionalInfo;

/** Class method to retrieve the user agent string
 @since 1.0
 */
+ (NSString*)userAgent;

/** Whether or not the http/s method is forced to be POST for all AGSRequests.
 @since 2.2
 */
+(BOOL)forcePostForAllRequests;

/** Whether or not the http/s method is forced to be POST for all AGSRequests.
 @since 2.2
 */
+(void)setForcePostForAllRequests:(BOOL)forcePost;

@end
