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



/** @file AGSEditResultError.h */ //Required for Globals API doc

/** @brief An edit error.
 
 Instances of this class represent the error encountered for an edit operation (add, 
 update, or delete) on a feature or a feature's attachment.
 
 @define{AGSEditResult.h, ArcGIS}
 @since 1.0
 */
@interface AGSEditResultError : NSObject <AGSCoding>

/** The error code for the edit result.
 @since 1.0
 */
@property (nonatomic, assign, readonly) NSInteger code;

/** The error description for the edit result.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *errorDescription;

@end