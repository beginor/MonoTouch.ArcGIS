/*
 COPYRIGHT 2010 ESRI
 
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

/** @file AGSCredential.h */ //Required for Globals API doc

@class AGSCredentialCache;

/** Supported authentication types.
 @since 1.0
 */
typedef enum {
	AGSAuthenticationTypeUnknown = 0,           /*!<  */
    AGSAuthenticationTypeNone,                  /*!<  */
    AGSAuthenticationTypeToken,                 /*!<  */
	AGSAuthenticationTypeHTTP,                  /*!<  */
    AGSAuthenticationTypeClientCertificate,     /*!<  */
} AGSAuthenticationType;

/** Error types returned
 @since 1.0
 */
typedef enum {
	AGSCredentialErrorTypeNone = 0,
	AGSCredentialErrorTypeInvalidCredentials,
	AGSCredentialErrorTypeSSLRequired,
	AGSCredentialErrorTypeUnknown
} AGSCredentialErrorType;

/** @brief Represents an credential to access a secured resource.
 
 Instances of this class represent a credential object to access a secured ArcGIS resource. The
 resource could be secured using ArcGIS tokens or HTTP (basic or digest) authentication.
 
 @define{AGSCredential.h, ArcGIS}
 @since 1.0
 */
@interface AGSCredential : NSObject <NSCopying>

/** Username used to access secured resource or retrieve a token.
 @since 1.0
 */
@property (nonatomic, copy) NSString *username;

/** Password used to access secured resource or retrieve a token.
 @since 1.0
 */
@property (nonatomic, copy) NSString *password;

/** Url to the token service.
 @since 1.0
 */
@property (nonatomic, copy) NSURL *tokenUrl;

/** The type of authentication needed to access a secured resource. Possibile
 values include
 
 @li @c AGSAuthenticationTypeUnknown
 @li @c AGSAuthenticationTypeNone
 @li @c AGSAuthenticationTypeToken
 @li @c AGSAuthenticationTypeHTTP	

 @since 1.0
 */
@property (nonatomic, assign) AGSAuthenticationType authType;

/** A string representing the referer for which the long-lived token was generated.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *referer;


/** Generated by the server from a username/password combination.
 @since 1.0
 */
@property (nonatomic, copy) NSString *token;

/** Indicates if the token provider requires that this token should only be transmitted over HTTPS.
 @since 2.2
 */
@property (nonatomic, assign, readonly) BOOL sslRequired;

/** Returns the @c SecIdentityRef that this credential was initialized with (if present)
 @return The identity associated with this credential object.
 @since 10.1.1
 */
- (SecIdentityRef)identity;

/** Initialize an <code>%AGSCredential</code> object.
 @param username The username of user attempting to access secured resource.
 @param password The password of user attempting to access secured resource.
 @return A new, initialized <code>%AGSCredential</code>.
 @since 1.0
 */
- (id)initWithUser:(NSString*)username password:(NSString*)password;

/** Initialize an AGSCredential object when you know the authType.
 @param username The username of user attempting to access secured resource.
 @param password The passwordof user attempting to access secured resource.
 @param authType The authentication type to be used when accessing secured resource.
 @return A new, initialized <code>%AGSCredential</code>.
 @since 1.0
 */
- (id)initWithUser:(NSString*)username password:(NSString*)password authenticationType:(AGSAuthenticationType)authType;

/** Initialize an AGSCredential object when you know the #authType and #tokenUrl.
 @param username The username of user attempting to access secured resource.
 @param password The password of user attempting to access secured resource.
 @param authType The authentication type to be used when accessing secured resource.
 @param tokenUrl The token service URL to be used to retrieve a token with given 
 credentials.
 @return A new, initialized <code>%AGSCredential</code>.
 @since 1.0
 */
- (id)initWithUser:(NSString*)username password:(NSString*)password authenticationType:(AGSAuthenticationType)authType tokenUrl:(NSURL*)tokenUrl;

/** Initialize an AGSCredential object with a short-lived token. This token will be used to access the secured resource.
 @param token The short-lived token to initialize the credential object.
 @return A new, initialized <code>%AGSCredential</code>.
 @since 1.8
 */
- (id)initWithToken:(NSString*)token;

/** Initialize an AGSCredential object with an @c SecIdentityRef.
 @param identityRef The identity in which to initialize the credential object.
 @return A new, initialized <code>%AGSCredential</code>.
 @since 10.1.1
 */
- (id)initWithIdentityRef:(SecIdentityRef)identityRef;

/** Initialize an AGSCredential object with a long-lived token and referer. This token will be used to access the secured resource.
 @param token The long-lived token to initialize the credential object.
 @param referer The referer to be sent along with token in the request.
 @return A new, initialized <code>%AGSCredential</code>.
 @since 1.8
 */
- (id)initWithToken:(NSString*)token referer:(NSString*)referer;

/** Helper method to deduce the URL for a token service. 
 This method is synchronous, it will block the calling thread until it finishes.
 Therefore, you should invoke this on a background thread to avoid locking up the main UI thread.
 @param url URL of the resource you wish to access.
 @param error Returned if an error is encountered retrieving the token service url.
 @return The URL of the token service.
 @since 2.1
 */
+ (NSURL*)getTokenServiceUrl:(NSURL *)url error:(NSError**)error;

/** Determines the type of security, if any, of a resource with a given url.
 This method is synchronous, it will block the calling thread until it finishes.
 Therefore, you should invoke this on a background thread to avoid locking up the main UI thread.
 @param url URL of the resource you wish to access.
 @param error Returned if an error is encountered while determining if the service is secured.
 @return The authentication type needed to access the specified resource.
 @since 2.1
 */
+ (AGSAuthenticationType)isServiceSecured:(NSURL*)url error:(NSError**)error;

/** Returns an array of @c SecIdentityRef objects that can be used to authenticate against
 the specified @c NSURLProtectionSpace.
 @param protectionSpace The protection space in which to retrieve identities for.
 @return An array of @c SecIdentityRef objects that can be used for client certificate authentication.
 @since 10.1.1
 */
+ (NSArray*)identitiesForProtectionSpace:(NSURLProtectionSpace*)protectionSpace;

/** Imports the certificate data into the keychain for the running application. This certificate can be
 retrieved from any application that shares the same keychain access group.
 @param data The data representing the client certificate.
 @param password The password to be used to access the certificate.
 @param overwrite If <code>YES</code>, this method will delete an existing certificate that matches and then
 re-add the certificate represented by data.
 @param error Returned if an error is encountered while importing the data.
 @return An @c SecIdentityRef object representing the imported data.
 @since 10.1.1
 */
+ (SecIdentityRef)importCertificateData:(NSData*)data password:(NSString*)password overwrite:(BOOL)overwrite error:(NSError**)error;

/** Removes an identity and its certificates from the keychain.
 @param identityRef The identity to remove from the keychain.
 @return An @c OSStatus result code indicating success or failure. See SecBase.h for for possible values.
 @since 10.1.1
 */
+ (OSStatus)removeIdentityFromKeychain:(SecIdentityRef)identityRef;

/** Returns the host (including port number) that a username/password will be sent to for authentication.
 This is useful to display to a user when prompting them for credentials when a resource fails to load.
 @since 10.1.1
 */
- (NSString*)authenticatingHost;

@end

/** @brief A protocol to aid in handling of secured resources.
 
 A protocol which must be adopted by a class wishing to handle token-expiration for a 
 particular resource. 
 
 @define{AGSCredential.h, ArcGIS}
 @since 1.0
 */
@protocol AGSSecuredResource <NSObject>

/** The credential to be used to access secured resources.
 @since 1.0
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for accessing secured resources.
 @since 10.1.1
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

@end
