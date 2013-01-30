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
@class AGSEditResult;

/** @file AGSFeatureLayerAttachmentResults.h */ //Required for Globals API doc

/** @brief Results of attachment edit operations.
 
 Instances of this class represent the results of edit operations (adds, updates, 
 and/or deletes) on a feature's attachment.
 
 @define{AGSFeatureLayer+Editing.h, ArcGIS}
 @since 1.0
 */
@interface AGSFeatureLayerAttachmentResults : NSObject

/** The result of an @em add operation. 
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSEditResult *addResult;

/** The result of an @em update operation. 
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSEditResult *updateResult;

/** The results of @em delete operations as an array of @c AGSEditResult objects. 
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *deleteResults;

@end