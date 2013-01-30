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


/** @file AGSRelationship.h */ //Required for Globals API doc

/** @brief An object representing the relationship between two layers/tables.
 
 Instances of this class represent a relationship between a @em source and a 
 @em target. The source could either be a layer or a table. The target could 
 also be either a layer or a table.
 @since 1.0
 */
@interface AGSRelationship : NSObject <AGSCoding>

/** ID of the relationship.
 @since 1.0
 */
@property (nonatomic, readonly) NSInteger relationshipId;

/** Name of the relationship. Usually describes how the source and target are 
 related.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The ID of the layer/table which is the target of this relationship.
 @since 1.0
 */
@property (nonatomic, readonly) NSInteger relatedTableId;

@end