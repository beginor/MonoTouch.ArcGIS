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



/** @file AGSFeatureLayerEditResults.h */ //Required for Globals API doc

/** @brief Results of feature edit operations.
 
 Instances of this class represent the combined results of many feature edit 
 operations (adds, updates, and/or deletes).
 
 @define{AGSFeatureLayer+Editing.h, ArcGIS}
 @since 1.0
 */
@interface AGSFeatureLayerEditResults : NSObject

/** The results of @em add operations as an array of @c AGSEditResult objects. 
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *addResults;

/** The results of @em update operations as an array of @c AGSEditResult objects. 
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *updateResults;

/** The results of @em delete operations as an array of @c AGSEditResult objects. 
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *deleteResults;

/** Flag to indicate whether the <code>deleteFeaturesWithWhereClause:geometry:spatialRelation:</code> 
 operation was successful.
 @since 1.0
 */
@property (nonatomic, assign, readonly) BOOL deleteWithQuerySuccess;

@end