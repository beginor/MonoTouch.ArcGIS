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

@class AGSEditResultError;

/** @file AGSEditResult.h */ //Required for Globals API doc


#pragma mark _
#pragma mark AGSEditResult

/** @brief An edit result.
 
 Instances of this class represent the outcome of an edit operation (add, update, 
 or delete) on a feature or a feature's attachment.
 
 @define{AGSEditResult.h, ArcGIS}
 @since 1.0
 */
@interface AGSEditResult : NSObject <AGSCoding>

/** The @em OBJECTID of the feature or the attachment which was edited.
 @since 1.0
 */
@property (nonatomic, assign, readonly) NSInteger objectId;

/** The @em GLOBALID of the feature or the attachment which was edited.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *globalId;

/** Indicates whether the edit succeeded.
 @since 1.0
 */
@property (nonatomic, assign, readonly) BOOL success;

/** Information about the error if the edit did not succeed.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSEditResultError *error;

@end
