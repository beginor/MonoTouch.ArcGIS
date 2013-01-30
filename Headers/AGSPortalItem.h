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

@class AGSEnvelope;
@class AGSSpatialReference;
@class AGSPortal;
@protocol AGSPortalItemDelegate;

/** @file AGSPortalItem.h */ //Required for Globals API doc

/** @brief Object representing a unit of content in the portal. 
 
 An AGSPortalItem is a unit of content in the AGSPortal.  Each item has a unique identifier and a well-
 known URL that is independent of the user owning the item. An item may have associated binary or 
 textual data which has to be fetched explicitly using @c #fetchData.  For example, an item of type @c AGSPortalItemTypeMapPackage will
 fetch the actual bits corresponding to the map package.
 
 The AGSPortalItem's #delegate is informed whenever operations performed by the AGSPortalItem  
 complete successfully or encounter an error. 
 
 @see AGSPortalItemDelegate
 @since 2.2
 */
@interface AGSPortalItem : NSObject <AGSCoding>

/** The delegate for the portal item operations. 
 @since 2.2
 */
@property (nonatomic, weak, readwrite) id<AGSPortalItemDelegate> delegate;

/** The portal that the item belogs to. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSPortal *portal;

/** The Id of the item. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *itemId;

/** The user who created the item. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *owner;

/** Title of the item. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *title;

/** The type of the item. 
 @since 2.2
 */
@property (nonatomic, assign, readonly) AGSPortalItemType type; 

/** The description of the item, if any. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *itemDescription;

/** Snippet or summary of the item with a character limit of 250 characters.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *snippet;

/** The access information about the item. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *credits;

/** Information about licenses or restrictions to view or edit the item. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *license;

/** The name of the thumbnail image of the item. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *thumbnailFileName;

/** The item's language and country information.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSLocale *locale;

/** Words or short phrases that describe the item.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *tags;

/** Date on which the item was first uploaded. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSDate *created;

/** Date on which the item was modified.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSDate *modified;

/** The default extent of the item. Only applicable to certain item types.
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSEnvelope *extent;

/** The spatial reference of the item. Only applicable to certain item types.
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The size of the item in kilobytes.
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSInteger size;

/** The number of comments on the item.
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSInteger numComments;

/** The number of ratings made by the users on the item.
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSInteger numRatings;

/** Average rating of the item.
 @since 2.2
 */
@property (nonatomic, assign, readonly) CGFloat avgRating;

/** Number of times a file item type is downloaded for the first time or a text item type is opened. For 
 a URL item type, the numViews property increases the first time a service is opened. 
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSInteger numViews;

/** Indicates who can access this item. Can be @c AGSPortalAccessPrivate, @c AGSPortalAccessShared, @c AGSPortalAccessOrganization, or @c AGSPortalAccessPublic.
 
 If @c AGSPortalAccessPrivate, only the item owner
 can access. @c AGSPortalAccessShared allows access to members of a group that the item is shared with . @c AGSPortalAccessOrganization restricts item access to members of an organization. If @c AGSPortalAccessPublic, all users can access the item.
 @since 2.2
 */
@property (nonatomic, assign, readonly) AGSPortalAccess access;

/** The thumbnail image of the item.  This needs to be fetched explicitly using #fetchThumbnail. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSImage *thumbnail;

/** Array of comments (@c AGSPortalItemComment) of the item. These need to be fetched explicitly using #fetchComments. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *comments;

/** Initializes a portal item with a portal and item id.
 @param portal The portal to which the item may belong to. 
 @param itemId The Id of the item. 
 @since 2.2
 */
-(id)initWithPortal:(AGSPortal*)portal itemId:(NSString*)itemId;

/** Kicks off an operation that fetches raw bytes for the item. The corresponding methods on @c AGSPortalItemDelegate are invoked when the operation completes successfully or encounters an error.
 @since 2.2
 */
-(NSOperation*)fetchData;

/** Kicks off an operation that fetches the thumbnail for the item. The corresponding methods on @c AGSPortalItemDelegate are invoked when the operation completes successfully or encounters an error.
 @since 2.2
 */
-(NSOperation*)fetchThumbnail;

/** Kicks off an operation that fetches the comments for the item. The corresponding methods on @c AGSPortalItemDelegate are invoked when the operation completes successfully or encounters an error.
 @since 2.2
 */
-(NSOperation*)fetchComments;

@end


/** @brief The delegate of @c AGSPortalItem
 
 A protocol which must be adopted by a class wishing to serve as a delegate for AGSPortalItem. 
 AGSPortalItem informs the delegate when operations complete successfully or encounter an error.
 
 All of the methods of this protocol are optional. 
 
 @since 2.2
 */
@protocol AGSPortalItemDelegate <NSObject>
@optional

/** Tells the delegate that the portal item was loaded successfully.
 @param portalItem The portalItem that was loaded. 
 @since 2.2
 */
-(void)portalItemDidLoad:(AGSPortalItem*)portalItem;

/** Tells the delegate that an error was encountered while tyring to load the portal item.
 @param portalItem 	The portal item that failed to load.
 @param error Information about the cause of the failure. 
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem didFailToLoadWithError:(NSError*)error;

/** Tells the delegate that item's data was fetched successfully. 
 @param portalItem The portal item of which the data was fetched. 
 @param op The operation that performed the fetch. 
 @param data The NSData that was retrieved. 
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFetchData:(NSData*)data;

/** Tells the delegate that an error was encountered while tyring to fetch the item's data. 
 @param portalItem The portal item of which the data was fetched.  
 @param op The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFailToFetchDataWithError:(NSError*)error;

/** Tells the delegate that the item's thumbnail was fetched successfully. 
 @param portalItem 	The portal item for which the thumbnail was fetched. 
 @param op The operation that performed the fetch. 
 @param thumbnail The thumbnail image file.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFetchThumbnail:(AGSImage*)thumbnail;

/** Tells the delegate that an error was encountered while fetching the item's thumbnail. 
 @param portalItem The portal item for which the thumbnail was fetched. 
 @param op The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFailToFetchThumbnailWithError:(NSError*)error;

/** Tells the delegate that the item's comments were fetched successfully.
 @param portalItem 	The portal item for which the comments were fetched. 
 @param op The operation that performed the fetch. 
 @param comments The comments.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFetchComments:(NSArray*)comments;

/** Tells the delegate that an error was encountered while trying to fetch the item's comments. 
 @param portalItem The portal item for which the comments fetched. 
 @param op The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFailToFetchCommentsWithError:(NSError*)error;
@end
