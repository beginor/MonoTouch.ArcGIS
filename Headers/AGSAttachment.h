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

@class AGSAttachmentInfo;
@class AGSEditResultError;

/** @file AGSAttachment.h */

/** An enum that defines the various edit states of an attachment.
@since 2.0
*/
typedef enum {
    AGSAttachmentEditStateOriginal = 0,		/*!< The attachment is as it is on the server */
    AGSAttachmentEditStateAdded,			/*!< The attachment was added locally, but does not exist on the server yet */
    AGSAttachmentEditStateMarkedForDeletion,/*!< The attachment was marked for deletion locally, but still exists on the server */
	AGSAttachmentEditStateDeletedFromServer /*!< The attachment was deleted from the server successfully. The attachment will never be in the Attachments array of the AGSAttachmentManager in this state.*/
} AGSAttachmentEditState;


/** @brief An attachment belonging to a feature
 
 Instances of this class represent an attachment on the client. This is
 used with the @c AGSAttachmentManager. This class automatically saves the attachment data
 to a temporary file and pulls the data out from that temporary 
 file when needed. Thus, it does not store actual attachment data in memory.  The temporary 
 file is cleaned up when the @c AGSAttachmentManager that is managing this attachment is cleared.
 @since 2.0
 */
@interface AGSAttachment : NSObject 

/** The attachment metadata  associated with this attachment.
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSAttachmentInfo *attachmentInfo;

/** The path to the temporary file that has been downloaded or saved.
 This will be nil if the attachment data has not been downloaded yet.
 @since 2.0
 */
@property (nonatomic, copy, readonly) NSString *filepath;

/** The edit state of this particular attachment.
 @since 2.0
 */
@property (nonatomic, assign, readonly) AGSAttachmentEditState editState;

/** Error that occurred, if any, when the local edits were synced with the server for this
 attachment.
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSEditResultError *editResultError;

/** Network error that occurred, if any, when the attachment manager attempted
 to download data for this attachment or post edits for this attachment.
 @since 2.0
 */
@property (nonatomic, strong, readonly) NSError *networkError;

/** Indicates whether or not the data for this this attachment is currently downloading.
 @since 2.0
 */
@property (nonatomic, assign, readonly) BOOL isDownloading;

/** Marks the attachment for deletion. The attachment will not actually be deleted
 until the edits are synced with the server.
 @since 2.0
 */
-(void)markForDeletion:(BOOL)del;

/** Indicates whether the feature exists on the server or if it is only on the client at this point.
 @since 2.0
 */
-(BOOL)existsOnServer;

/** Indicates whether the actual attachment data has been downloaded yet.
 @since 2.0
 */
-(BOOL)isLocal;

/** Returns a thumbnail image the attachment. Only works with some types of attachments - mainly images and videos.
 @since 2.0
 */
-(AGSImage*)thumbnail;

/** If the attachment data has been downloaded, it will be saved to a temporary file. This method
 pulls the actual NSData from that file and returns it to the caller.
 @since 2.0
 */
-(NSData*)data;

@end
