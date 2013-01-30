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

/** @file AGSPortalFolder.h */ //Required for Globals API doc

/** @brief Represents a folder of content within the Portal or Organization.
 
 A user's content in a portal can be organized into folders. 
 
 @since 2.2
 */
@interface AGSPortalFolder : NSObject <AGSCoding>

/** The Id of the folder
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *folderId;

/** The title of the folder
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *title;

/** The date of creation of the folder.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSDate *created;
@end
