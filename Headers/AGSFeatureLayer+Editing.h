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


@class AGSFeatureLayer;
@class AGSFeatureType;
@class AGSGraphic;
@class AGSFeatureTemplate;
@class AGSFeatureServiceTask;
@class AGSEditResult;
@class AGSFeatureLayerEditResults;
@class AGSFeatureLayerAttachmentResults;
@class AGSGeometry;

@protocol AGSFeatureLayerEditingDelegate;

/** @file AGSFeatureLayer+Editing.h */ //Required for Globals API doc

#pragma mark -

/**@brief A category on @c AGSFeatureLayer containing methods related to editing

 A category on @c AGSFeatureLayer containing methods related to editing
 
 @since 1.0
 */
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
 
 Only applicable if @c AGSFeatureLayer#canCreate is @c true.
 
 @param features The features to add.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0 
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFeatureEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailFeatureEditsWithError: , method on delegate for error
 */
-(NSOperation *)addFeatures: (NSArray*)features;

/** Commits changes made to the specified features to the server.
 
 Only applicable if @c AGSFeatureLayer#canUpdateFeature: is @c true for each of the 
 specified featrues
 
 @param features The features to update.
 @return <code>NSOperation</code> that performs the update.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFeatureEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailFeatureEditsWithError: , method on delegate for error
 */
-(NSOperation *)updateFeatures: (NSArray *)features;

/** Delete features on the server based on the specified @em OBJECTIDs
 
 Only applicable if @c AGSFeatureLayer#canDeleteFeature: is true for each specified feature.
 
 @param objectIds The object IDs of the features to delete.
 @return <code>NSOperation</code> that performs the delete.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFeatureEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailFeatureEditsWithError: , method on delegate for error
*/
-(NSOperation *)deleteFeaturesWithObjectIds: (NSArray *)objectIds;

/** Deletes features on the server based on the specified query parameters. Only 
 features satisfying all parameters will be deleted.
 
 Only applicable if @c AGSFeatureLayer#canDeleteFeature: is true for each feature specified by the
 parameters.
 
 @param where The where clause to restrict the set of candidate features.
 @param geometry The geometry to be used while testing spatial relationships.
 @param spatialRelation The spatial relation which should be satisfied between 
 the candidate features and the geometry.
 @return <code>NSOperation</code> that performs the delete.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFeatureEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailFeatureEditsWithError: , method on delegate for error
 */
-(NSOperation *)deleteFeaturesWithWhereClause: (NSString *)where geometry: (AGSGeometry*)geometry spatialRelation: (AGSSpatialRelationship)spatialRelation;

/** A convenience method to add, delete, and update features on the server.
 
 Only applicable if @c AGSFeatureLayer#canCreate, @c AGSFeatureLayer#canDeleteFeature:, and @c AGSFeatureLayer#canUpdateFeature:
 permit the edit.
 
 @param addFeatures The array of features to add.
 @param updateFeatures The array of features to modify.
 @param objectIds The object IDs of the features to delete.
 @return <code>NSOperation</code> that applies the edits.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFeatureEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailFeatureEditsWithError: , method on delegate for error
 */
-(NSOperation *)applyEditsWithFeaturesToAdd: (NSArray *)addFeatures
											toUpdate: (NSArray *)updateFeatures
											toDelete: (NSArray *)objectIds;

#pragma mark attachment edit methods

/** Add an attachment to the feature specified by @p objectId on the server. Only applicable
 if @c AGSFeatureLayer#attachments property is  <code>true</code> and the feature (to which this 
 attachment belongs) can be edited (@c AGSFeatureLayer#canUpdateFeature:).
 @param objectId The object ID of the feature to which the attachment belongs.
 @param data The raw contents of the attachment.
 @param filename The name for the attachment.
 @param contentType The content type of the attachment. If nil is passed, the api will
 try to match a content type to known file extensions.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didAttachmentEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailAttachmentEditsWithError: , method on delegate for error

 */
-(NSOperation *)addAttachment:(NSUInteger)objectId data:(NSData*)data filename:(NSString*)filename contentType:(NSString*)contentType;

/** Add an attachment to the feature specified by @p objectId on the server. Only applicable
 if @c AGSFeatureLayer#attachments property is  <code>true</code> and the feature (to which this 
 attachment belongs) can be edited (@c AGSFeatureLayer#canUpdateFeature:).
 @param objectId The object ID of the feature to which the attachment belongs.
 @param data The raw contents of the attachment.
 @param filename The name for the attachment.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didAttachmentEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailAttachmentEditsWithError: , method on delegate for error
 */
-(NSOperation *)addAttachment:(NSUInteger)objectId data:(NSData*)data filename:(NSString*)filename;

/** Add the provided attachment for the specified feature on the server.
 Only applicable
 if @c AGSFeatureLayer#attachments property is  <code>true</code> and the feature (to which this 
 attachment belongs) can be edited (@c AGSFeatureLayer#canUpdateFeature:).
 @param objectId The object ID of the feature to which the attachment belongs .
 @param filepath The path of the attachment on the device.
 @param contentType The content type of the attachment. If nil is passed, the api will
 try to match a content type to known file extensions.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didAttachmentEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailAttachmentEditsWithError: , method on delegate for error
 */
-(NSOperation *)addAttachment:(NSUInteger)objectId filepath:(NSString*)filepath contentType:(NSString*)contentType;

/** Add the provided attachment for the specified feature on the server.
 Only applicable
 if @c AGSFeatureLayer#attachments property is  <code>true</code> and the feature (to which this 
 attachment belongs) can be edited (@c AGSFeatureLayer#canUpdateFeature:).
 @param objectId The object ID of the feature to which the attachment belongs .
 @param filepath The path of the attachment on the device.
 @return <code>NSOperation</code> that performs the add.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didAttachmentEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailAttachmentEditsWithError: , method on delegate for error
*/
-(NSOperation *)addAttachment:(NSUInteger)objectId filepath:(NSString*)filepath;

/** Update the specified attachment of the specified feature on the server using 
 the provided attachment.
 Only applicable
 if @c AGSFeatureLayer#attachments property is  <code>true</code> and the feature (to which this 
 attachment belongs) can be edited (@c AGSFeatureLayer#canUpdateFeature:).
 @param objectId The object ID of the feature to which the attachment belongs.
 @param data The raw contents of the new attachment.
 @param filename The name for the new attachment.
 @param contentType The content type of the attachment. If nil is passed, the api will
 try to match a content type to known file extensions.
 @param attachmentId The attachment ID of the old attachment that the new 
 attachment will replace.
 @return <code>NSOperation</code> that performs the update.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didAttachmentEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailAttachmentEditsWithError: , method on delegate for error
*/
-(NSOperation *)updateAttachment:(NSUInteger)objectId data:(NSData*)data filename:(NSString*)filename contentType:(NSString*)contentType attachmentId:(NSInteger) attachmentId;

/** Update the specified attachment of the specified feature on the server using 
 the provided attachment.
 Only applicable
 if @c AGSFeatureLayer#attachments property is  <code>true</code> and the feature (to which this 
 attachment belongs) can be edited (@c AGSFeatureLayer#canUpdateFeature:).
 @param objectId The object ID of the feature to which the attachment belongs.
 @param data The raw contents of the new attachment.
 @param filename The name for the new attachment.
 @param attachmentId The attachment ID of the old attachment that the new 
 attachment will replace.
 @return <code>NSOperation</code> that performs the update.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didAttachmentEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailAttachmentEditsWithError: , method on delegate for error
*/
-(NSOperation *)updateAttachment:(NSUInteger)objectId data:(NSData*)data filename:(NSString*)filename attachmentId:(NSInteger)attachmentId;

/** Delete the specified attachments for the specified feature on the server.
 Only applicable
 if @c AGSFeatureLayer#attachments property is  <code>true</code> and the feature (to which this 
 attachment belongs) can be edited (@c AGSFeatureLayer#canUpdateFeature:).
 @param objectId The object ID of the feature to which the attachments belong.
 @param attachmentIds The attachment IDs of the attachments to be deleted.
 @return <code>NSOperation</code> that performs the delete.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didAttachmentEditsWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailAttachmentEditsWithError: , method on delegate for error
 */
-(NSOperation *)deleteAttachmentsForObjectId: (NSUInteger)objectId attachmentIds:(NSArray *)attachmentIds;

#pragma mark get attachment infos method

/** Get information about all attachments that belong to the specified feature.
 @param objectId The object ID of the feature.
 @return <code>NSOperation</code> that performs the query.
 @since 1.0
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didQueryAttachmentInfosWithResults: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didFailQueryAttachmentInfosWithError: , method on delegate for error
 */
-(NSOperation *)queryAttachmentInfosForObjectId: (NSUInteger)objectId;

#pragma mark get attachment method

/** Fetch the contents of the specified attachment.
 @param objectId The object ID of the feature to which the attachment belongs.
 @param attachmentId The ID of the attachment to fetch.
 @return <code>NSOperation</code> that performs the retrieval.
 @since 1.0.
 @see @c AGSFeatureLayerEditingDelegate#featureLayer:operation:didRetrieveAttachmentWithData: , method on delegate for success
 @see @c AGSFeatureLayerEditingDelegate# featureLayer:operation:didFailRetrieveAttachmentWithError: , method on delegate for error
 */
-(NSOperation *)retrieveAttachmentForObjectId: (NSUInteger)objectId attachmentId: (NSInteger)attachmentId;

@end



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
