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

@protocol AGSCoding;

/** @file AGSEditFieldsInfo.h */ //Required for Globals API doc

/** @brief Information about edit tracking fields
 
 Instances of this class indicate which fields or attributes of a feature contain information
 about who created/edited the feature and when was it created/edited.
 
 @define{AGSEditFieldsInfo.h, ArcGIS}
 @since 2.3
 */
@interface AGSEditFieldsInfo : NSObject<AGSCoding>

/** Name of the field containing information about when the feature was first created.
 @since 2.3
 */
@property (nonatomic, copy, readonly) NSString *creationDateField;

/** Name of the field containing information about who created the feature.
 @since 2.3
 */
@property (nonatomic, copy, readonly) NSString *creatorField;

/** Name of the field containing information about when the feature was last edited.
 @since 2.3
 */
@property (nonatomic, copy, readonly) NSString *editDateField;

/** Name of the field containing information about who edited the feature last. 
 @since 2.3
 */
@property (nonatomic, copy, readonly) NSString *editorField;

@end
