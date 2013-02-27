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
@protocol AGSPortalGroupDelegate;

/** @file AGSPortalGroup.h */ //Required for Globals API doc

/** @brief Represents a group within the Portal or Organization.
 
 An Instance of this class resource represents a group within the Portal or Organization. The owner is 
 automatically an administrator and is returned in the list of admins. Adminstrators can invite, add to
 or remove members from a group as well as update or delete the group. The administrator for an 
 organization may also reassign the group to another member of the organization. Group members may leave
 the group. Authenticated users may apply to join a group.
 
 @see AGSPortalGroupDelegate
 @since 2.2
 */
@interface AGSPortalGroup : NSObject <AGSCoding>

/** The delegate for the portal group operations. 
 @since 2.2
 */
@property (nonatomic, weak, readwrite) id<AGSPortalGroupDelegate> delegate;

/** The portal that the group belongs to. 
 @since 2.2
 */
@property (nonatomic, weak, readonly) AGSPortal *portal;

/** Id of the group.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *groupId;

/** The group title.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *title;

/** The user who created the group. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *owner;

/** The description of the group, if exists. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *groupDescription;

/** Snippet or summary of the group with a character limit of 250 characters.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *snippet;

/** The name of the thumbnail image of the group.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *thumbnailFileName;

/** Words or short phrases that describe the group.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *tags;

/** The date on which the group was created.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSDate *created;

/** The date on which the group was modified.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSDate *modified;

/** Determines who can access the group's conent. Can be either @c AGSPortalAccessPrivate, @c AGSPortalAccessOrganization, or @c AGSPortalAccessPublic.
 
 @c AGSPortalAccessPrivate implies only members of the group have access. @c AGSPortalAccessOrganization implies all members of the organization have access regardless of whether they are members of the group. @c AGSPortalAccessPublic implies everyone has access.
 
  @since 2.2
 */
@property (nonatomic, assign, readonly) AGSPortalAccess access;

/** If YES, this group will not accept join requests. Else, this group does not require an invitation to join. Only group owners and admins can invite users to the group. 
 @since 2.2
 */
@property (nonatomic, assign, readonly) BOOL isInvitationOnly;

/** The thumbnail image file. This needs to be fetched explicitly using #fetchThumbnail
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSImage *thumbnail;

/** Array of strings representing users of the group. These need to be fetched explicitly using #fetchUsers
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *users;

/** Array of strings representing admin users of the group. These need to be fetched explicitly using #fetchUsers
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *admins;


/** Kicks off an operation to fetch a thumbnail image for the group. The corresponding methods on @c AGSPortalGroupDelegate are invoked when the operation completes successfully or encounters an error.
 @since 2.2
 */
-(NSOperation*)fetchThumbnail;

/** Fetches the users and admins of the group. When completed, the #admins and #users properties
 will have requested information. The corresponding methods on @c AGSPortalGroupDelegate are invoked when the operation completes successfully or encounters an error.
 @since 2.2
 */
-(NSOperation*)fetchUsers;

@end


/** @brief The delegate of @c AGSPortalGroup
 
 A protocol which must be adopted by a class wishing to serve as a delegate for AGSPortalGroup. 
 AGSPortalGroup informs the delegate of events and consults the delegate before taking some action.
 
 All of the methods of this protocol are optional.
 
 @since 2.2
 */
@protocol AGSPortalGroupDelegate <NSObject>
@optional

/** Tells the delegate that the fetch operation of the group's thumbnail image completed successfully. 
 @param portalGroup The portal group for which the thumbnail was fetched. 
 @param op The operation that performed the fetch. 
 @param thumbnail The thumbnail image file.
 @since 2.2
 */
-(void)portalGroup:(AGSPortalGroup*)portalGroup operation:(NSOperation*)op didFetchThumbnail:(AGSImage*)thumbnail;

/** Tells the delegate that the specified error was encountered while tyring to fetch the thumbnail image. 
 @param portalGroup The portal group for which the thumbnail was fetched. 
 @param op The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalGroup:(AGSPortalGroup*)portalGroup operation:(NSOperation*)op didFailToFetchThumbnailWithError:(NSError*)error;

/** Tells the delegate that the fetch operation of the group's users and admins completed successfully. 
 @param portalGroup The portal group for which the users and admins were fetched. 
 @param op The operation that performed the fetch. 
 @param users Array of all the users (@c AGSPortalUser) of the group.
 @param admins Array of all the admin users (@c AGSPortalUser) of the group.
 @since 2.2
 */
-(void)portalGroup:(AGSPortalGroup*)portalGroup operation:(NSOperation*)op didFetchUsers:(NSArray*)users admins:(NSArray*)admins;

/** Tells the delegate that the specified error was encountered while tyring to fetch the users and admins of the group. 
 @param portalGroup The portal group for which the users and admins were fetched.  
 @param op The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalGroup:(AGSPortalGroup*)portalGroup operation:(NSOperation*)op didFailToFetchUsersWithError:(NSError*)error;
@end








