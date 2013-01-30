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

@class AGSCredential;

/** @file AGSCredentialCache.h */ //Required for Globals API doc

/** @brief A cache containing credentials to reuse
 
 Instances of this class represent a cache containing credentials. 
 Objects that use the same cache could potentially reuse credentials if they need to access the same
 security realm and a credential for it already exists in the cache. This will happen automatically if #shouldAutoCacheCredentials is enabled.
 
 @since 10.1.1
 */
@interface AGSCredentialCache : NSObject

/** Indicates whether or not @c AGSCredential objects should be cached automatically.
 By default, credential caching is ON.
 @since 10.1.1
 */
@property (nonatomic, assign) BOOL shouldAutoCacheCredentials;

/** Removes all @c AGSCredential objects from the shared cache.
 @since 10.1.1
 */
- (void)removeAllCredentials;

/** Set an @c AGSCredential in the cache to be used for the given @p url.
 @param credential An @c AGSCredential object to put in the cache.
 @param url The url in which to pair the @p credential. The url can be one of several things:
 @li The full path to a server from an ArcGIS Server.
 @li The full path to a portal, portal item, hosted item.
 @li The url to a portal - http(s)://www.arcgis.com
 @li The url to an ArcGIS Server instance - http(s)://host(:port)/instance
 @since 10.1.1
 */
- (void)setCredential:(AGSCredential*)credential forUrl:(NSURL*)url;

/** Retrieves an @c AGSCredential from the cache for the given @p url
 @param url The url in which to pair the @p credential. The url can be one of several things:
 @li The full path to a server from an ArcGIS Server.
 @li The full path to a portal, portal item, hosted item.
 @li The url to a portal - http(s)://www.arcgis.com
 @li The url to an ArcGIS Server instance - http(s)://host(:port)/instance
 @return The @c AGSCredential from the cache for the given @p serverKey.
 @since 10.1.1
 */
- (AGSCredential*)credentialForUrl:(NSURL*)url;

/** Removes the associated @c AGSCredential from the cache for the given @p url
 @param url The url in which to remove the @p credential for. The url can be one of several things:
 @li The full path to a server from an ArcGIS Server.
 @li The full path to a portal, portal item, hosted item.
 @li The url to a portal - http(s)://www.arcgis.com
 @li The url to an ArcGIS Server instance - http(s)://host(:port)/instance
 @since 10.1.1
 */
- (void)removeCredentialForUrl:(NSURL*)url;

/** Removes a specific @c AGSCredential from the cache.
 @param credential The credential in which to remove from the cache.
 @since 10.1.1
 */
- (void)removeCredential:(AGSCredential*)credential;

/** Returns the default @c AGSCredentialCache. This is also a global cache.
 @since 10.1.1
 */
+ (AGSCredentialCache*)defaultCache;

@end
