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

#import <Foundation/Foundation.h>
@class AGSFeatureLayer;
@class AGSFeatureType;
@class AGSGraphic;
@class AGSFeatureTemplate;
@class AGSFeatureServiceTask;
@class AGSEditResult;

/** @file AGSFeatureLayer+Editing.h */ //Required for Globals API doc

#pragma mark -

/** @brief Results of feature edit operations.
 
 Instances of this class represent the combined results of many feature edit 
 operations (adds, updates, and/or deletes).
 
 @define{AGSFeatureLayer+Editing.h, ArcGIS}
 @since 1.0
 */
@interface AGSFeatureLayerEditResults : NSObject {
 @private
	NSArray *_addResults;
	NSArray *_updateResults;
	NSArray *_deleteResults;
	BOOL _deleteWithQuerySuccess;
}

/** The results of @em add operations as an array of @c AGSEditResult objects. 
 @since 1.0
 */
@property (nonatomic,retain,readonly) NSArray *addResults;

/** The results of @em update operations as an array of @c AGSEditResult objects. 
 @since 1.0
 */
@property (nonatomic,retain,readonly) NSArray *updateResults;

/** The results of @em delete operations as an array of @c AGSEditResult objects. 
 @since 1.0
 */
@property (nonatomic,retain,readonly) NSArray *deleteResults;

/** Flag to indicate whether the <code>deleteFeaturesWithWhereClause:geometry:spatialRelation:</code> 
 operation was successful.
 @since 1.0
 */
@property (nonatomic,assign,readonly) BOOL deleteWithQuerySuccess;

@end

#pragma mark -

/** @brief Results of attachment edit operations.
 
 Instances of this class represent the results of edit operations (adds, updates, 
 and/or deletes) on a feature's attachment.
 
 @define{AGSFeatureLayer+Editing.h, ArcGIS}
 @since 1.0
 */
@interface AGSFeatureLayerAttachmentResults : NSObject {
 @private
	AGSEditResult *_addResult;
	AGSEditResult *_updateResult;
	NSArray *_deleteResults;
}

/** The result of an @em add operation. 
 @since 1.0
 */
@property (nonatomic,retain,readonly) AGSEditResult *addResult;

/** The result of an @em update operation. 
 @since 1.0
 */
@property (nonatomic,retain,readonly) AGSEditResult *updateResult;

/** The results of @em delete operations as an array of @c AGSEditResult objects. 
 @since 1.0
 */
@property (nonatomic,retain,readonly) NSArray *deleteResults;

@end

#pragma mark -

/** @brief An editing delegate of @c AGSFeatureLayer.
 
 A protocol which must be adopted by any class wishing to be notified when editing 
 or attachment related operations performed by @c AGSFeatureLayer complete 
 successfully or encounter an error. An instance of the class must then be set 
 as the @p editingDelegate of @c AGSFeatureLayer.
 
 @define{AGSFeatureLayer+Editing.h, ArcGIS}
 @since 1.0
 
 */
@protocol AGSFeatureLayerEditingDelegate <NSObject>

@optional

/** Tells the delegate that @c AGSFeatureLayer successfully completed making the 
 feature edits  (adds, updates, or deletes). It is possible that a subset of the 
 edits failed. You should inspect the provided @c AGSFeatureLayerEditResults 
 object to find out which edits (if any) failed.
 @param featureLayer Feature Layer on which the feature edit operation was executed.
 @param op The operation that is performing the server request.
 @param editResults Results returned by the feature edit operation.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFeatureEditsWithResults:(AGSFeatureLayerEditResults *)editResults;

/** Tells the delegate that @c AGSFeatureLayer encountered an error while making 
 the feature edits  (adds, updates, or deletes).
 @param featureLayer Feature Layer on which the feature edit operation was executed.
 @param op The operation that is performing the server request.
 @param error Information returned by the feature edit operation.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFailFeatureEditsWithError:(NSError *)error;

/** Tells the delegate that @c AGSFeatureLayer successfully completed making the 
 attachment edits (adds, updates, or deletes). It is possible that a subset of 
 the edits failed. You should inspect the provided @c AGSFeatureLayerAttachmentResults 
 object to find out which edits (if any) failed.
 @param featureLayer Feature Layer on which the attachment edit operation was executed.
 @param op The operation that is performing the server request.
 @param attachmentResults Results returned by the attachment edit operation.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didAttachmentEditsWithResults:(AGSFeatureLayerAttachmentResults *)attachmentResults;

/** Tells the delegate that @c AGSFeatureLayer encountered an error while making 
 the attachment edits (adds, updates, or deletes).
 @param featureLayer Feature Layer on which the attachment edit operation was executed.
 @param op The operation that is performing the server request.
 @param error Information returned by the attachment edit operation.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFailAttachmentEditsWithError:(NSError *)error;


/** Tells the delegate that @c AGSFeatureLayer successfully completed querying 
 attachment metadata.
 @param featureLayer Feature Layer on which the query attachment infos operation 
 was executed.
 @param op The operation that is performing the server request.
 @param attachmentInfos Array of @c AGSAttachmentInfo objects returned by the query.
 @since 1.0
*/
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didQueryAttachmentInfosWithResults:(NSArray *)attachmentInfos;

/** Tells the delegate that @c AGSFeatureLayer encountered an error while querying 
 attachment metadata.
 @param featureLayer Feature Layer on which the query attachment infos operation 
 was executed.
 @param op The operation that is performing the server request.
 @param error Information returned by the query attachment infos operation.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFailQueryAttachmentInfosWithError:(NSError *)error;

/** Tells the delegate that @c AGSFeatureLayer successfully completed querying 
 the actual attachment data.
 @param featureLayer Feature Layer on which the retrieve attachment operation 
 was executed.
 @param op The operation that is performing the server request.
 @param attachmentData The raw <code>NSData</code> object associated with the 
 attachment.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didRetrieveAttachmentWithData:(NSData *)attachmentData;

/** Tells the delegate that AGSFeatureLayer encountered an error while querying 
 the actual attachment data.
 @param featureLayer Feature Layer on which the retrieve attachment operation 
 was executed.
 @param op The operation that is performing the server request.
 @param error Information returned by the retrieve attachment operation.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFailRetrieveAttachmentWithError:(NSError *)error;
@end

#pragma mark -

@interface AGSFeatureLayer (Editing)

/** Creates a new autoreleased feature based on the specified feature sub-type and feature 
 template. Note, the new feature is only available on the device at this point, 
 it is not commited to the server.
 @param featureTemplate The feature template to use while creating the feature.
 @return The new feature. 
 @since 2.1
 @see <code>addFeatures:</code> or 
 <code>applyEditsWithFeaturesToAdd:toUpdate:toDelete:</code> for 
 committing the feature to the server.
 */
-(AGSGraphic *)featureWithTemplate:(AGSFeatureTemplate*)featureTemplate;

/** Creates a new autoreleased feature based on the specified feature sub-type. Note, the new 
 feature is only available on the device at this point, it is not commited to 
 the server. This method uses the first template in the feature type.
 @param featureType The type of feature to create.
 @return The new feature. 
 @since 2.1
 @see <code>addFeatures:</code> or 
 <code>applyEditsWithFeaturesToAdd:toUpdate:toDelete:</code> for 
 committing the feature to the server.
 */
-(AGSGraphic *)featureWithType:(AGSFeatureType*)featureType;

#pragma mark feature edit methods

/** Adds the specified features to the server.
 @param features The features to add.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0 
 */
-(NSOperation *)addFeatures: (NSArray*)features;

/** Commits changes made to the specified features to the server.
 @param features The features to update.
 @return <code>NSOperation</code> that performs the update.
 @since 1.0
 */
-(NSOperation *)updateFeatures: (NSArray *)features;

/** Delete features on the server based on the specified @em OBJECTIDs
 @param objectIds The object IDs of the features to delete.
 @return <code>NSOperation</code> that performs the delete.
 @since 1.0
 */
-(NSOperation *)deleteFeaturesWithObjectIds: (NSArray *)objectIds;

/** Deletes features on the server based on the specified parameters. Only 
 features satisfying all parameters will be deleted.
 @param where The where clause to restrict the set of candidate features.
 @param geometry The geometry to be used while testing spatial relationships.
 @param spatialRelation The spatial relation which should be satisfied between 
 the candidate features and the geometry.
 @return <code>NSOperation</code> that performs the delete.
 @since 1.0
 */
-(NSOperation *)deleteFeaturesWithWhereClause: (NSString *)where geometry: (AGSGeometry*)geometry spatialRelation: (AGSSpatialRelationship)spatialRelation;

/** A convenience method to add, delete, and update features on the server.
 @param addFeatures The array of features to add.
 @param updateFeatures The array of features to modify.
 @param objectIds The object IDs of the features to delete.
 @return <code>NSOperation</code> that applies the edits.
 @since 1.0
 */
-(NSOperation *)applyEditsWithFeaturesToAdd: (NSArray *)addFeatures
											toUpdate: (NSArray *)updateFeatures
											toDelete: (NSArray *)objectIds;

#pragma mark attachment edit methods

/** Add an attachment to the feature specified by @p objectId. Only applicable
 if #editable and #attachments are <code>true</code>.
 @param objectId The object ID of the feature to which the attachment belongs.
 @param data The raw contents of the attachment.
 @param filename The name for the attachment.
 @param contentType The content type of the attachment. If nil is passed, the api will
 try to match a content type to known file extensions.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0
 */
-(NSOperation *)addAttachment:(NSUInteger)objectId data:(NSData*)data filename:(NSString*)filename contentType:(NSString*)contentType;

/** Add an attachment to the feature specified by @p objectId. Only applicable
 if #editable and #attachments are <code>true</code>.
 @param objectId The object ID of the feature to which the attachment belongs.
 @param data The raw contents of the attachment.
 @param filename The name for the attachment.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0
 */
-(NSOperation *)addAttachment:(NSUInteger)objectId data:(NSData*)data filename:(NSString*)filename;

/** Add the provided attachment for the specified feature on the server.
 @param objectId The object ID of the feature to which the attachment belongs .
 @param filepath The path of the attachment on the device.
 @param contentType The content type of the attachment. If nil is passed, the api will
 try to match a content type to known file extensions.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0
 */
-(NSOperation *)addAttachment:(NSUInteger)objectId filepath:(NSString*)filepath contentType:(NSString*)contentType;

/** Add the provided attachment for the specified feature on the server.
 @param objectId The object ID of the feature to which the attachment belongs .
 @param filepath The path of the attachment on the device.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0
 */
-(NSOperation *)addAttachment:(NSUInteger)objectId filepath:(NSString*)filepath;

/** Update the specified attachment of the specified feature on the server using 
 the provided attachment.
 @param objectId The object ID of the feature to which the attachment belongs.
 @param data The raw contents of the new attachment.
 @param filename The name for the new attachment.
 @param contentType The content type of the attachment. If nil is passed, the api will
 try to match a content type to known file extensions.
 @param attachmentId The attachment ID of the old attachment that the new 
 attachment will replace.
 @return <code>NSOperation</code> that performs the update.
 @since 1.0
 */
-(NSOperation *)updateAttachment:(NSUInteger)objectId data:(NSData*)data filename:(NSString*)filename contentType:(NSString*)contentType attachmentId:(NSUInteger) attachmentId;

/** Update the specified attachment of the specified feature on the server using 
 the provided attachment.
 @param objectId The object ID of the feature to which the attachment belongs.
 @param data The raw contents of the new attachment.
 @param filename The name for the new attachment.
 @param attachmentId The attachment ID of the old attachment that the new 
 attachment will replace.
 @return <code>NSOperation</code> that performs the update.
 @since 1.0
 */
-(NSOperation *)updateAttachment:(NSUInteger)objectId data:(NSData*)data filename:(NSString*)filename attachmentId:(NSUInteger)attachmentId;

/** Delete the specified attachments for the specified feature on the server.
 @param objectId The object ID of the feature to which the attachments belong.
 @param attachmentIds The attachment IDs of the attachments to be deleted.
 @return <code>NSOperation</code> that performs the delete.
 @since 1.0
 */
-(NSOperation *)deleteAttachmentsForObjectId: (NSUInteger)objectId attachmentIds:(NSArray *)attachmentIds;

#pragma mark get attachment infos method

/** Get information about all attachments that belong to the specified feature.
 @param objectId The object ID of the feature.
 @return <code>NSOperation</code> that performs the query.
 @since 1.0
 */
-(NSOperation *)queryAttachmentInfosForObjectId: (NSUInteger)objectId;

#pragma mark get attachment method

/** Fetch the contents of the specified attachment.
 @param objectId The object ID of the feature to which the attachment belongs.
 @param attachmentId The ID of the attachment to fetch.
 @return <code>NSOperation</code> that performs the retrieval.
 @since 1.0.
 */
-(NSOperation *)retrieveAttachmentForObjectId: (NSUInteger)objectId attachmentId: (NSUInteger)attachmentId;

@end
