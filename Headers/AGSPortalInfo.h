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

@class AGSPortal;
@class AGSWebMapBaseMap;
@class AGSEnvelope;
@protocol AGSPortalInfoDelegate;

/** @file AGSPortalInfo.h */ //Required for Globals API doc

/** @brief Information about a Portal or Organization
 
 If the accessing user is a member of
 an organization, the details pertain to that organization. If the accessing user is not a member of an organization then then the details 
 pertain to the Portal instead. Information includes the name and logo for the portal/ 
 organization, query information for the featured groups and content, and other 
 customizable aspects of the Portal for an organization.
 
 The AGSPortalInfo's #delegate is informed whenever operations performed by the AGSPortalInfo  
 complete successfully or encounter an error. 

 @see AGSPortalInfoDelegate
 @since 2.2
 */
@interface AGSPortalInfo : NSObject <AGSCoding>

/** The delegate for operations on AGSPortalInfo.
 @since 2.2
 */
@property (nonatomic, weak, readwrite) id<AGSPortalInfoDelegate> delegate;

/** The portal that is being referred to. 
 @since 2.2
 */
@property (nonatomic, weak, readonly) AGSPortal *portal;

/** The id of the organization. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *organizationId;

/** The name of the organization.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *organizationName;

/** The description of the organization.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *organizationDescription;

/** The name of the portal.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *portalName;

/** The pre-defined query string for finding featured items group. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *featuredItemsGroupQuery;

/** Indicates whether the members of the organization can share content outside of the organization.
 @since 2.2
 */
@property (nonatomic, assign, readonly) BOOL canSharePublic;

/** Indicates whether the members of the organization can search content outside of the organization.
 @since 2.3
 */
@property (nonatomic, assign, readonly) BOOL canSearchPublic;

/** The name of the Organization's thumbnail file.  
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *organizationThumbnailFileName;

/** The name of the Portal's thumbnail file.  
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *portalThumbnailFileName;

/** The pre-defined query string for finding the collection of basemaps.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *basemapGalleryGroupQuery;

/** The default basemap of the portal/organization.
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSWebMapBaseMap *defaultBasemap;

/** The default extent for the basemaps.
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSEnvelope *defaultExtent;

/** The pre-defined query string for finding homepage featured items group.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *homepageFeaturedContentGroupQuery;

/** Array of pre-defined query strings for finding featured groups.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *featuredGroupsQueries;

/** The thumbnail image of the portal. This needs to be fetched explicitly using #fetchPortalThumbnail. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSImage *portalThumbnail;

/** The thumbnail image of the organization. This needs to be fetched explicitly using #fetchOrganizationThumbnail. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSImage *organizationThumbnail;

/** Determines who can view the organization's content. Can be either  @c AGSPortalAccessPublic or @c AGSPortalAccessPrivate. 
 
 @c AGSPortalAccessPublic implies even anonymous users can access the content. @c AGSPortalAccessPrivate restricts access to only members of the organization. 
 
 @since 2.2
 */
@property (nonatomic, assign, readonly) AGSPortalAccess access;

/** Indicates whether the portal is single or multi tenant.
 A multi tenant portal supports organization subscriptions, but a
 single tenant does not.
 @since 2.2
 */
@property (nonatomic, assign, readonly) AGSPortalMode portalMode;

/** The portion of the URL's host component that identifies the portal
 For example, http://&lt;urlkey&gt;.&lt;customBaseUrl&gt;/
 @since 2.3
 @see #urlKey
 */
@property (nonatomic, copy, readonly) NSString *customBaseUrl;

/** The portion of the URL's host component that identifies a specific organization subscription within a portal.
 For example, http://&lt;urlkey&gt;.&lt;customBaseUrl&gt;/
 @since 2.3
 @see #customBaseUrl
 */
@property (nonatomic, copy, readonly) NSString *urlKey;

/** The locator services configured for this portal..
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSArray *geocodeServiceUrls;

/** The route service configured for this portal..
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) NSURL *routeServiceUrl;

/** The geometry service configured for this portal.
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) NSURL *geometryServiceUrl;

/** The print service configured for this portal.
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) NSURL *printTaskUrl;


/** Kicks off an operation that fetches the portal thumbnail. The corresponding methods on @c AGSPortalInfoDelegate are invoked when the operation completes successfully or encounters an error.
 @since 2.2
 */
-(NSOperation*)fetchPortalThumbnail;

/** Kicks off an operation that fetches the organization thumbnail. The corresponding methods on @c AGSPortalInfoDelegate are invoked when the operation completes successfully or encounters an error.
 @since 2.2
 */
-(NSOperation*)fetchOrganizationThumbnail;
@end

/** @brief A delegate of @c AGSPortalInfo
 
  A protocol which must be adopted by a class wishing to serve as a delegate for AGSPortalInfo. 
 AGSPortalInfo informs the delegate when operations complete successfully or encounter an error.
 
 All of the methods of this protocol are optional.
 
 @since 2.2
 */
@protocol AGSPortalInfoDelegate <NSObject>
@optional

/** Tells the delegate that the fetch operation of the portal's thumbnail image completed successfully. 
 @param portalInfo The portal info on which the fetch was done.
 @param op The operation that performed the fetch. 
 @param thumbnail The thumbnail image file.
 @since 2.2
 */
-(void)portalInfo:(AGSPortalInfo*)portalInfo operation:(NSOperation*)op didFetchPortalThumbnail:(AGSImage*)thumbnail;

/** Tells the delegate that the specified error was encountered while tyring to fetch the thumbnail image. 
 @param portalInfo The portal info on which the fetch was done.
 @param op The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalInfo:(AGSPortalInfo*)portalInfo operation:(NSOperation*)op didFailToFetchPortalThumbnailWithError:(NSError*)error;

/** Tells the delegate that the fetch operation of the oraganization's thumbnail image completed successfully. 
 @param portalInfo The portal info on which the fetch was done.
 @param op The operation that performed the fetch. 
 @param thumbnail The thumbnail image file.
 @since 2.2
 */
-(void)portalInfo:(AGSPortalInfo*)portalInfo operation:(NSOperation*)op didFetchOrganizationThumbnail:(AGSImage*)thumbnail;

/** Tells the delegate that the specified error was encountered while tyring to fetch the thumbnail image. 
 @param portalInfo The portal info on which the fetch was done.
 @param op The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalInfo:(AGSPortalInfo*)portalInfo operation:(NSOperation*)op didFailToFetchOrganizationThumbnailWithError:(NSError*)error;
@end
