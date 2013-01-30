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



@protocol AGSCoding;

/** @file AGSAttachmentInfo.h */ //Required for Globals API doc

/** @brief Information about an attachment.
 
 Information about an attachment associated with a feature.

 @define{AGSAttachmentInfo.h, ArcGIS}
 @since 1.0
 @see AGSFeatureLayerEditingDelegate
 */
@interface AGSAttachmentInfo : NSObject <AGSCoding>

/** The unique id of the attachment in the database.
 @since 1.0
 */
@property (nonatomic, assign, readonly) NSInteger attachmentId;

/** The MIME type of the attachment.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *contentType;

/** The size of the attachment in bytes.
 @since 1.0
 */
@property (nonatomic, assign, readonly) NSInteger size;

/** The name of the attachment.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Compares one attachment info to another.
 @since 1.8
 */
-(BOOL)isEqualToAttachmentInfo:(AGSAttachmentInfo*)other;

@end
