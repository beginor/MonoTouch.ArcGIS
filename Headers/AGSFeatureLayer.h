/*
 COPYRIGHT 2009 ESRI
 
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
@protocol AGSQueryTaskDelegate;
@protocol AGSFeatureLayerEditingDelegate;
@protocol AGSFeatureLayerQueryDelegate;
@protocol AGSInfoTemplateDelegate;

@class AGSLayer;
@class AGSDynamicLayer;
@class AGSGraphicsLayer;

@class AGSQueryTask;
@class AGSQuery;
@class AGSGraphic;
@class AGSSymbol;
@class AGSFeatureType;
@class AGSFeatureTemplate;
@class AGSFeatureLayer;
@class AGSFeatureLayerModeModule;
@class AGSRequestOperation;
@class AGSTimeInfo;
@class AGSField;
@class AGSAttachmentManager;
@class AGSTimerContainer;
@class AGSEditFieldsInfo;
@class AGSTimeExtent;
@class AGSCredential;
@class AGSRelationshipQuery;
@class AGSFeatureSet;

/** @file AGSFeatureLayer.h */ //Required for Globals API doc

#pragma mark -

/** Supported modes in which @c AGSFeatureLayer fetches features from the server.
 @since 1.0
 */
typedef enum {
    AGSFeatureLayerModeSnapshot = 0,	/*!< Features are fetched right at the beginning. */
    AGSFeatureLayerModeOnDemand,		/*!< Features are fetched when needed.*/
	AGSFeatureLayerModeSelection		/*!< Features are fetched when they are selected*/	
} AGSFeatureLayerMode;

/** Supported modes for selecting features through @c AGSFeatureLayer.
 @since 1.0
 */
typedef enum {
    AGSFeatureLayerSelectionMethodAdd = 0,	/*!< Adds newly selected features to the existing list of selected features*/
    AGSFeatureLayerSelectionMethodNew,		/*!< Replaces existing selected features with the newly selected features */
	AGSFeatureLayerSelectionMethodSubtract	/*!< Removes newly selected features from existing list of selected features*/	
} AGSFeatureLayerSelectionMethod;

// example of this taken from "UIKeyboardDidShowNotification"
/** Notification that indicates that AGSFeatureLayer completed loading its features (for example, from a remote feature service).
 @since 10.1.1
 */
AGS_EXTERN NSString *const AGSFeatureLayerDidLoadFeaturesNotification;

#pragma mark -

/** @brief A layer based on an ArcGIS Server map/feature service layer.
 
 Instances of this class represent a feature layer. The layer allows you to display features from an individual layer or table in an ArcGIS Server map 
 service or a feature service .
 
 When using a map service, the layer allows you to only view features. You cannot create new 
 features or edit existing features. If the  service is from ArcGIS 
 Server 9.3.1 or earlier,you will need to assign this layer a 
 #renderer to properly symbolize the features. If the service is from ArcGIS Server 10 or greater, the renderer information will be inherited from the service.
 
 The layer retrieves features from the service based on its #mode. The 
 features are then held on the device and drawn much like @c AGSGraphicsLayer does.
 
 When using a  feature service, the layer can also potentially allow you to 
 create, delete, and update features depending upon whether the backend feature service allows those operations, who owns the feature, and what ownership-based access control policies are in place (for example, should someone be allowed to delete/update a feature they do not own?)  
 You should check  #canCreate, #canDeleteFeature:, #canUpdateFeature:, and #canUpdateGeometry properties to see what is allowed.
 
 If the layer supports attachments, the #attachments property will 
 be <code>true</code>. If the feature layer is editable and has #attachments, 
 you can also add, update, delete, and query attachments. 
 
 Note, Feature Services are only avaialble on ArcGIS Server 10.0 or above. 
 
 <h3>Notifications</h3>
 The layer posts @c #AGSFeatureLayerDidLoadFeaturesNotification when it finishes loading features
 from a remote feature service.
 
 @see @concept{ArcGIS_Feature_Layer/00pw0000004s000000/, ArcGIS Feature Layer}
 @see @sample{2ddb261648074b9aabb22240b6975918, Feature Layer Editing}
 @see @sample{feae3db9536c414f970302ee5f5f066a, Online-Offline Editing}
 @since 1.0
 */
@interface AGSFeatureLayer : AGSGraphicsLayer <AGSCoding, AGSInfoTemplateDelegate, AGSSecuredResource>

/** URL to a layer resource in the ArcGIS Server REST Services Directory. The 
 layer resource can belong to a Map Service or a Feature Service and can 
 represent either a layer or a table in the service.
 
 Feature Service layers support both viewing and editing the features, whereas 
 Map Service layers support only viewing.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSURL *URL;

/** Mode in which the layer retrieves features from the service. Possible modes 
 include
 @li @c AGSFeatureLayerModeSnapshot
 @li @c AGSFeatureLayerModeOnDemand
 @li @c AGSFeatureLayerModeSelection
 
 In @em Snapshot mode, the feature layer retrieves all of the features from the
 associated layer resource and displays them as graphics. This includes all 
 features that satisfy the #definitionExpression and 
 #defaultDefinitionExpression. Note that the number of features that are 
 retrieved will be limited based on the ArcGIS Server's configuration (500 
 features by default for ArcGIS Server 9.3, and 1000 for ArcGIS Server 10).
 
 In @em On-Demand mode, features are fetched asynchronously and when they are 
 needed to be displayed. These include those features that satisfy the 
 #definitionExpression and #defaultDefinitionExpression, and also fall within 
 the map's current spatial and time extents.
 
 In @em Selection mode, features are retrieved from the server only when they
 are selected. To work with selected features:
 
 @li Send <code>selectFeaturesWithQuery:selectionMethod:message:</code> to an
 instance of <code>%AGSFeatureLayer</code>. The #queryDelegate will be notified
 when the operation completes or if an error is encountered.
 @li If operation completes successfully, retrieve the selected features from 
 @p featureSet object of the #queryDelegate's 
 <code>featureLayer:didSelectFeaturesWithFeatureSet:</code> method or send
 <code>selectedFeatures</code> message to an instance of 
 <code>%AGSFeatureLayer</code>.
 
 When editing feature layers in selection mode, you will need to add the map
 service associated with the feature service to the map as a dynamic map
 service. Once the edit operation completes successfully, manually refresh the
 associated dynamic map service layer so that the modified features are
 rendered. If you do not have the map service added as a dynamic map service 
 then the changes will not be visible. This is because once the edits are 
 completed, the feature is no longer selected.

 @since 1.0
 */
@property (nonatomic, readonly) AGSFeatureLayerMode mode;

/** The credential to be used to access secured resources.
 @since 1.0
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource. By default this will be set to the global cache.
 @since 10.1.1
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

/** The cache policy that should be used for making the web request.
 Default value is NSURLRequestUseProtocolCachePolicy
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) NSURLRequestCachePolicy requestCachePolicy;

/** The timeout interval (in seconds) for this request. Default value is 60.
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) NSTimeInterval timeoutInterval;

/** The ID of the layer as defined by the service.
 @since 1.0
 */
@property (nonatomic, readonly) NSUInteger layerId;

/** The name of the layer as defined by the service.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *serviceLayerName;

/** The description of the layer as defined by the service.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *layerDescription;

/** The type of the layer as defined by the service. Could be either 
 @em Feature @em Layer or @em Table.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *type;

/** The geometry type of features contained in the layer as defined by the service.  
 All features in the layer will have the same geometry type.
 Possible types include
 @li @c AGSGeometryTypePoint
 @li @c AGSGeometryTypePolyline
 @li @c AGSGeometryTypePolygon
 
 @c AGSGeometryTypeMultipoint and @c AGSGeometryTypeEnvelope types are not supported.
 @since 1.0
 */
@property (nonatomic, readonly) AGSGeometryType geometryType;

/** The primary display field as defined by the service.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *displayField;

/** The fields available in the layer as defined by the service. The property is an
 array of @c AGSField objects. Attributes of features belonging to this layer 
 contain values for each field.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *fields;

/** The name of field which contains the @em OBJECTID.
 @since 1.0
 @see #objectIdForFeature: to conveniently get a feature's @em OBJECTID.
 */
@property (nonatomic, copy, readonly) NSString *objectIdField;

/** The name of the field which contains the sub-type information.
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *typeIdField;

/** Definition expression for the layer as defined by the service. This 
 expression limits which features are returned by the service.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *defaultDefinitionExpression;

/** A collection of @c AGSFeatureType objects representing feature sub-types in 
 the layer. For example, a @em roads layer may contain 2 feature sub-types : highways 
 and streets. 
 @avail{10.0}
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *types;

/** A collection of @c AGSFeatureTemplate objects representing feature templates 
 for the layer. Usually only present if the layer does not contain feature 
 sub-types. Only applicable if this layer is based on an ArcGIS Server Feature 
 Service layer.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *templates;

/** Collection of @c AGSRelationship objects that describe this layer's 
 relationship with another layer or table in the service.
 @since 1.0
 @see #queryRelatedFeatures: to query features that participate in the relationship.
 */
@property (nonatomic, copy, readonly) NSArray *relationships;

/** Time information for the layer, such as start time field, end time field, 
 track id field, layers time extent and the draw time interval. Only applicable 
 if the layer is time aware.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSTimeInfo *timeInfo;

/** If <code>YES</code>, features in the layer may have attachments. Developers 
 should call #queryAttachmentInfosForObjectId: for each feature to see if it has 
 any attachments.
 @since 1.0
 */
@property (nonatomic, readonly, getter=hasAttachments) BOOL attachments;

/** 
 A definition expression limits the features displayed by this layer based on some a SQL query. 
 Only those features whose attribute values match the SQL query are retrieved by the layer. Setting a definition
 expression is useful when the dataset is large and you do not want to bring
 all the features to the client for analysis. 
 
 This definition expression is combined with and applied in addition to the layer's 
 #defaultDefinitionExpression. Net result is that only those features that satisfy both
 expressions are retrieved by the layer.
 @since 1.0
 */
@property (nonatomic, copy) NSString *definitionExpression;

/** Delegate to be notified when editing operations complete successfully or 
 encounter an error.
 @since 1.0
 */
@property (nonatomic, weak) id<AGSFeatureLayerEditingDelegate> editingDelegate;

/** Delegate to be notified when query operations complete successfully or 
 encounter an error.
 @since 1.0
 */
@property (nonatomic, weak) id<AGSFeatureLayerQueryDelegate> queryDelegate;

/** An array of field names to include in the feature layer. If not specified, 
 the feature layer will return the OBJECTID field and if applicable the start 
 time field, end time field, type id field, display field and any fields 
 associated with the renderer. You can specify ["*"] to fetch 
 the values for all fields in the layer, this is useful when editing features.
 @since 1.0
 */
@property (nonatomic, copy) NSArray *outFields;

/** This is only applicable for feature layers that are not editable. The maximum 
 allowable offset used for generalizing geometries returned by the query operation. 
 The default is 0. If 0 is specified the value is not passed to the server in a 
 query. The offset is in the units of the spatialReference. If a spatialReference 
 is not defined the spatial reference of the map is used.
 @since 1.0
 */
@property (nonatomic, assign) double maxAllowableOffset;

/** Specifies whether or not the layer is queryable. If the layer is not queryable, 
 it will not be displayed.
 @since 1.0
 */
@property (nonatomic, readonly, getter=isQueryable) BOOL queryable;

/** This is an easy way to set the info template delegate for all graphics in the 
 feature layer. It must be set before the features are fetched. For basic callout 
 behavior, this can be set to the feature layer itself. By default it is 
 <code>nil</code>.
 @since 1.0
 */
@property (nonatomic, weak) id<AGSInfoTemplateDelegate> infoTemplateDelegate;

/** The time interval in seconds that features in the layer will expire when the 
 layer is in @em OnDemand mode. Setting this to 0 will cause the features to not 
 expire.
 @since 1.0
 */
@property (nonatomic, assign) double expirationInterval;

/** Specifies whether or not the layer will #refresh automatically when the
 expiration interval is reached. Default is <code>NO</code>. This uses an 
 <code>NSTimer</code> for implementation. This is used only in @em OnDemand mode.
 @since 10.1.1
 */
@property (nonatomic, assign) BOOL autoRefreshOnExpiration;

/** This is the buffer around the current extent that features are retrieved for in @em OnDemand 
 mode. Features are not retrieved again until either they expire or the map extent changes and is 
 no longer in the buffered extent. Buffer factor can be up to 10. If it is set to 0,
 every time the map extent is changed a refresh with requery will take place in @em OnDemand mode. If the buffer factor
 is less than 0, then the layer will never requery from an extent change.
 This is not usually recommended. 
 @since 1.0
 */
@property (nonatomic, assign) CGFloat bufferFactor;

/** Constraint factor is used when the feature layer is in OnDemand mode. This property
 defines refresh with requery behavior for OnDemand mode when the user is zooming in. This property should be set to a fraction
 between 0 and 1. If the size of the envelope the user zooms in to is less than that specified fraction of the buffered envelope's size
 then a requery will happen. For example: the constraintFactor is set to .1 (one-tenth), we have a buffered envelope of features
 that is 50 miles wide. The user zooms in to an envelope that is 4 miles wide. Since the envelope the layer needs to draw is less
 than one-tenth the size of the buffered envelope, the feature layer will requery, even though the zoomed-to envelope is contained 
 within the buffered envelope. This is useful if you have a service with a number of features that exceeds the ArcGIS server
 query limit and you want the layer to requery when the user zooms in by a certain amount.
 A value of 0 or less will never requery when the user zooms in within the buffered envelope.
 A value of 1 will always requery when the user zooms in within the buffered envelope.
 The default value is .1f (one-tenth).
 @since 2.1
 */
@property (nonatomic, assign) CGFloat constraintFactor;

/** The version of the service.
 @since 1.8
 */
@property (nonatomic, assign, readonly) CGFloat version;

/** The full envelope of the service. In the service's native spatial reference.
 @since 1.8
 */
@property (nonatomic, strong, readonly) AGSEnvelope *serviceFullEnvelope;

/** An array of @c AGSLabelClass objects representing labeling information.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSArray *labelingInfo;

/** A time definition is similar to a #definitionExpression in that it limits the features displayed by this
 layer based on some contraints. A time definition specifies contraints based on a time extent. Only those features 
 whose time information falls within the given time extent are retrieved by the layer.
 @since 1.8
 */
@property (nonatomic, strong) AGSTimeExtent *timeDefinition;

/** Metadata regarding which fields or attributes of a feature contain information
 about who created/edited the feature and when was it created/edited.
 @since 2.3
 */
@property (nonatomic, strong, readonly) AGSEditFieldsInfo *editFieldsInfo;

/** Indicates whether the layer allows geometries of features to be updated.
  You should check this property before allowing the ability to update a feature's geometry in your app.
 @since 2.3
 */
@property (nonatomic, assign, readonly) BOOL canUpdateGeometry;

/** Indicates whether the layer allows new features to be created.
 You should check this property before allowing the ability to create a new feature in your app.
 @since 2.3
 */
@property (nonatomic, assign, readonly) BOOL canCreate;

/** Indicates whether the layer allows a feature to be updated.
 It is preferable to use #canUpdateFeature: instead because this property
 does not take into account any ownership-based access control policies for the specific feature you are trying to edit.
 It only provides general information about whether the layer is capable of updating features at all.
 @since 2.3
 */
@property (nonatomic, assign, readonly) BOOL canUpdate;

/** Indicates whether the layer allows features to be deleted.
 It is preferable to use #canDeleteFeature: instead because this property
 does not take into account any ownership-based access control policies for the specific feature you are trying to delete.
 It only provides general information about whether the layer is capable of deleting features at all.
 @since 2.3
 @see #canDeleteFeature:
 */
@property (nonatomic, assign, readonly) BOOL canDelete;

/** Initialize this layer with a URL of an ArcGIS Server Map or Feature Service layer.
 @param url URL to a map or feature service layer. 
 @param mode The mode in which to retrieve features.
 @return A new feature layer object.
 @see @c AGSLayerDelegate#layerDidLoad: , method on delegate for success
 @see @c AGSLayerDelegate#layer:didFailToLoadWithError: , method on delegate for failure
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url mode:(AGSFeatureLayerMode)mode;

/** Initialize this layer with a URL of an ArcGIS Server Map or Feature Service layer.
 @param url URL to a map or feature service layer.
 @param mode The mode in which to retrieve features.
 @param cred <code>AGSCredential</code> used to access secure resource.
 @return A new feature layer object.
 @since 1.0
 @see @c AGSLayerDelegate#layerDidLoad: , method on delegate for success
 @see @c AGSLayerDelegate#layer:didFailToLoadWithError: , method on delegate for failure
 */
- (id)initWithURL:(NSURL *)url mode:(AGSFeatureLayerMode)mode credential:(AGSCredential*)cred;

/** Initialize this layer, in a synchronous fashion, with a URL of an ArcGIS Server Map or Feature 
 Service layer.
 NOTE: The AGSCredentialCache can not be used with synchronous methods.
 @param url URL to a map or feature service layer.
 @param mode The mode in which to retrieve features.
 @param error Information about the error returned if init fails.
 @return A new feature layer object.
 @since 1.0
 @see @c AGSLayerDelegate#layerDidLoad: , method on delegate for success
 @see @c AGSLayerDelegate#layer:didFailToLoadWithError: , method on delegate for failure
 */
- (id)initWithURL:(NSURL*)url mode:(AGSFeatureLayerMode)mode error:(NSError**)error;

/** Initialize this layer, in a synchronous fashion, with a URL of an ArcGIS Server Map or Feature
 Service layer.
 NOTE: The AGSCredentialCache can not be used with synchronous methods.
 @param url URL to a map or feature service layer.
 @param mode The mode in which to retrieve features.
 @param cred <code>AGSCredential</code> used to access secure resource.
 @param error Information about the error returned if init fails.
 @return A new feature layer object.
 @since 1.0
 @see @c AGSLayerDelegate#layerDidLoad: , method on delegate for success
 @see @c AGSLayerDelegate#layer:didFailToLoadWithError: , method on delegate for failure
 */
- (id)initWithURL:(NSURL*)url mode:(AGSFeatureLayerMode)mode credential:(AGSCredential*)cred error:(NSError**)error;

/** A method to get an initialized, autoreleased layer with a URL of an ArcGIS
 Server Map or Feature Service layer.
 @param url URL to a map or feature service layer. 
 @param mode The mode in which to retrieve features.
 @return A new, autoreleased, feature layer object.
 @since 1.0
 @see @c AGSLayerDelegate#layerDidLoad: , method on delegate for success
 @see @c AGSLayerDelegate#layer:didFailToLoadWithError: , method on delegate for failure
 */
+ (id)featureServiceLayerWithURL:(NSURL *)url mode:(AGSFeatureLayerMode)mode;

/** A method to get an initialized, autoreleased layer with a URL of an ArcGIS
 Server Map or Feature Service layer.
 @param url URL to a map or feature service layer.
 @param mode The mode in which to retrieve features.
 @param cred <code>AGSCredential</code> used to access secure resource.
 @return A new, autoreleased, feature layer object.
 @since 1.0
 @see @c AGSLayerDelegate#layerDidLoad: , method on delegate for success
 @see @c AGSLayerDelegate#layer:didFailToLoadWithError: , method on delegate for failure
*/
+ (id)featureServiceLayerWithURL:(NSURL *)url mode:(AGSFeatureLayerMode)mode credential:(AGSCredential*)cred;

/** A way to get an initialized layer that does not work with an ArcGIS Server map or feature service, but instead
 works a predefined set of features. In this mode, layer will not make any network connections because it already
 has all the information it needs to display features.
 @param layerDefinitionJSON JSON representation of this layer's properties. This is the JSON returned by a Map or Feature
 Service for one of its layers, for example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/SanFrancisco/311Incidents/FeatureServer/0?f=pjson
 It can also be retrieved from an existing feature layer using @c #encodeToJSON
 @param featureSetJSON JSON representation of an @c AGSFeatureSet containing the features to be displayed by the layer
 @since 1.8
 */
-(id)initWithLayerDefinitionJSON:(NSDictionary*)layerDefinitionJSON featureSetJSON:(NSDictionary*)featureSetJSON;

/** 
 @since 2.3
 */
-(id)initWithLayerDefinitionJSON:(NSDictionary *)layerDefinitionJSON featureSet:(AGSFeatureSet*)featureSet;

/** Executes a query against the service layer pointed by the URL. The query 
 returns records matching the specified criteria. The records could be features, 
 if the service layer represents a layer. Or the records could be simple records 
 (without geometry) if the service layer represents a table. The #queryDelegate 
 will be notified when the operation completes or if an error is encountered.

 The number of results returned by the query is limited  by the service's 
 configuration.
 @param query Specifies the criteria for the query.
 @return The operation performing the query.
 @since 1.0
 @see AGSFeatureLayerQueryDelegate
 */
-(NSOperation*)queryFeatures:(AGSQuery *)query;

/** Executes a query against the service layer pointed by the URL. The query 
 returns only IDs of matching features.  This is useful if you want to implement 
 paging for results or if you want to only fetch result details on demand. Unlike 
 #queryFeatures: , there is no limit on the number of results returned by this query.
 
 The #queryDelegate will be notified when the operation completes or if an error 
 is encountered.
 @param query Specifies the criteria for the query.
 @return The operation performing the query.
 @since 1.0
 @see AGSFeatureLayerQueryDelegate
 */
-(NSOperation*)queryIds:(AGSQuery *)query;

/** Executes a query against the service layer pointed by the URL. The query 
 returns only the feature count of matching features. 
 
 The #queryDelegate will be notified when the operation completes or if an error 
 is encountered.
 @param query Specifies the criteria for the query.
 @return The operation performing the query.
 @since 1.8
 @see AGSFeatureLayerQueryDelegate
 */
-(NSOperation*)queryFeatureCount:(AGSQuery *)query;

/**Executes a query against the service layer pointed by the URL. The query 
 returns records that are related to the given set of features. The related 
 records could be features, if the service layer is related to a layer. Or the 
 related records could be simple records (without geometry) if the service layer 
 is related to a table.
 
 The #queryDelegate will be notified when the operation completes or if an error 
 is encountered. 
 @param query Specifies the criteria for the query.
 @return The operation performing the query.
 @since 1.0
 @see AGSFeatureLayerQueryDelegate
 */
-(NSOperation*)queryRelatedFeatures:(AGSRelationshipQuery *)query;

/** Selects features based on the specified query. Selected features are 
 symbolized using #selectionSymbol if available, otherwise using the layer's 
 renderer. 
 
 The #queryDelegate will be notified when the operation completes or if an error
 is encountered.
 
 @param query Specifies the criteria for the query.
 @param selectionMethod Specifies whether the matching features should be added 
 to, removed from, or replace the existing selected features. Possible values 
 include
 @li @c AGSFeatureLayerSelectionMethodAdd 
 @li @c AGSFeatureLayerSelectionMethodNew
 @li @c AGSFeatureLayerSelectionMethodSubtract
 
 @return The operation performing the selection.
 
 @since 1.0
 @see @c AGSGraphicsLayer#selectedFeatures
 */
-(NSOperation*)selectFeaturesWithQuery:(AGSQuery*)query selectionMethod:(AGSFeatureLayerSelectionMethod)selectionMethod;

/**
 Selects a feature with the method specified. The feature must exist in the feature layer graphics collection.
 @param feature The feature that you want apply the selection method to
 @param selectionMethod Whether you want to add to, delete from, or entirely replace the existing set of selected features
 @since 1.8
 @deprecated Deprecated at 10.1.1. Use #setSelected:forGraphic: instead.
 */
-(void)selectFeature:(AGSGraphic*)feature withSelectionMethod:(AGSFeatureLayerSelectionMethod)selectionMethod __attribute__((deprecated));

/** Clears the current selection.
 @since 1.0
 */
-(void)clearSelection;

/** A convenience method to lookup a feature in the graphics collection using 
 the specified object id.
 @param objectId The object ID of the graphic to be looked up.
 @return @c AGSGraphic object corresponding to @p objectId.
 @since 1.0
 */
-(AGSGraphic*)lookupFeatureWithObjectId:(NSInteger)objectId;

/** Requeries for the features in the feature layer. The feature layer requeries 
 the features in the service, according to it's mode, and updates itself.
 @since 10.1.1
 */
-(void)refresh;

/** A convenience method to get the @em OBJECTID for specified feature.
 @param feature The feature to get @em OBJECTID for.
 @return The @em OBJECTID for @p feature.
 @since 1.0
 */
-(int)objectIdForFeature:(AGSGraphic*)feature;

/** If the layer failed to load with a specific url and credential, you can
 resubmit it to try and load again using the same url and credential. If you want to modify the
 credential, you can update the credential on the layer before calling this method.
 If you also want to update the url, you should use @c # resubmitWithURL:credential: instead.
 
 This function does nothing if the
 layer is already loaded. This function also does nothing if the layer is currently
 trying to load.
 @since 10.1.1
 */
- (void)resubmit;

/** If the layer failed to load with a specific url and credential, you can 
 resubmit it with a new URL and credential. This function does nothing if the 
 layer is already loaded. This function also does nothing if the layer is currently 
 trying to load.
 @param url URL to the feature service.
 @param cred <code>AGSCredential</code> used to access the secured resource.
 @since 1.0
 */
-(void)resubmitWithURL:(NSURL*)url credential:(AGSCredential*)cred;

/** Convenience method to find the feature template associated with a particular feature.
 @param feature The feature to find the template for.
 @param type The type (if any) that the feature template was found in.
 @return @c AGSFeatureTemplate object that the feature matches.
 @since 1.8
 */
-(AGSFeatureTemplate *)templateForFeature:(AGSGraphic*)feature type:(AGSFeatureType**)type;

/** Convenience method to find a field with a specified name.
 @param fieldName The name of the field to find.
 @return @c AGSField object with specified name.
 @since 1.8
 */
-(AGSField*)findFieldWithName:(NSString*)fieldName;

/** Gives a handle to the attachment manager that can download and manage edits to
 attachments belonging to the specified feature.
 @param feature for which we want the attachment manager
 @return AGSAttachmentManager
 @since 2.0
 */
-(AGSAttachmentManager*)attachmentManagerForFeature:(AGSGraphic*)feature;

/** Clears all the attachment managers that may have been handed out by this feature layer.
 When an attachment manager is cleared, the tempororay files used by the attachment manager
 to manage attachments is deleted.
 @since 2.0
 */
-(void)clearAttachmentManagers;

/** Clears the attachment manager that manages attachments for the feature specified by
 the given objectID. When an attachment manager is cleared, the tempororay files used by 
 the attachment manager to manage attachments is deleted.
 @param objectId of the feature whose attachment manager is to be cleared.
 @since 2.0
 */
-(void)clearAttachmentManagerForFeatureWithObjectId:(NSInteger)objectId;

/** Indicates whether the layer can update this particular feature. The method first checks #canUpdate to verify if the layer is capable of updating any features in general. It also checks ownership-based access control policies of the layer to see if the  user specified in the #credential has persmissions to edit this specific feature.
 You should check this property before allowing the ability to update this feature in your app.
 @param feature Can be nil, in which case, this method is the same as #canUpdate
 @return A boolean value
 @since 2.3
 */
- (BOOL)canUpdateFeature:(AGSGraphic*)feature;

/** Indicates whether the layer can delete this particular feature. The method first checks #canDelete to verify if the layer is capable of deleting any features in general. It also checks ownership-based access control policies of the layer to see if the  user specified in the #credential has persmissions to delete this specific feature.
 @param feature Can be nil, in which case, this method is the same as #canDelete
 @return A boolean value
 @since 2.3
 */
- (BOOL)canDeleteFeature:(AGSGraphic*)feature;

/** Returns a localized string representing the most recent activity on this feature.
 For example, <i>Created by John Doe 5 hours ago.</i>
 @since 2.3
 */
- (NSString*)editSummaryForFeature:(AGSGraphic*)feature;

@end




#pragma mark -

/** @brief A delegate of @c AGSFeatureLayer.
 
 A protocol which must be adopted by any class wishing to be notified when query 
 operations performed by @c AGSFeatureLayer complete successfully or encounter an 
 error.
 An instance of the class must then be set as the @p queryDelegate of 
 @c AGSFeatureLayer.
 
 @define{AGSFeatureLayer.h, ArcGIS}
 @since 1.0
 */
@protocol AGSFeatureLayerQueryDelegate <NSObject>

@optional
/** Tells the delegate that @c AGSFeatureLayer completed the query successfully 
 with the provided results.
 @param featureLayer The feature layer which performed the query.
 @param op The operation that performed the query.
 @param featureSet The feature set returned by executing query.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didQueryFeaturesWithFeatureSet:(AGSFeatureSet *)featureSet;

/**  Tells the delegate that @c AGSFeatureLayer encountered an error while 
 performing the query.
 @param featureLayer The feature layer which performed the query.
 @param op The operation that performed the query.
 @param error Information about the error that was encountered.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFailQueryFeaturesWithError:(NSError *)error;

/** Tells the delegate that @c AGSFeatureLayer completed query for IDs successfully 
 with the provided results.
 @param featureLayer The feature layer which performed the query.
 @param op The operation that performed the query.
 @param objectIds The object IDs returned by executing query.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didQueryObjectIdsWithResults:(NSArray *)objectIds;

/** Tells the delegate that @c AGSFeatureLayer encountered an error while 
 performing query for IDs 
 @param featureLayer The feature layer which performed the query.
 @param op The operation that performed the query.
 @param error Information about the error that was encountered.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFailQueryObjectIdsWithError:(NSError *)error;

/** Tells the delegate that @c AGSFeatureLayer completed query for feature count successfully 
 with the provided results.
 @param featureLayer The feature layer which performed the query.
 @param op The operation that performed the query.
 @param count The number of features matching the specified query.
 @since 1.8
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didQueryFeatureCountWithResult:(NSInteger)count;

/** Tells the delegate that @c AGSFeatureLayer encountered an error while 
 performing query for feature count. 
 @param featureLayer The feature layer which performed the query.
 @param op The operation that performed the query.
 @param error Information about the error that was encountered.
 @since 1.8
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFailQueryFeatureCountWithError:(NSError *)error;

/** Tells the delegate that @c AGSFeatureLayer completed query for related features 
 successfully with the provided results. The related features are returned as a 
 dictionary of key-value pairs. Keys are <code>NSNumber</code> objects representing 
 IDs from @c AGSRelationshipQuery. Values are @c AGSFeatureSet objects 
 representing the corresponding related features.
 @param featureLayer The feature layer which performed the query.
 @param op The operation that performed the query.
 @param relatedFeatures The related features returned by executing query.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didQueryRelatedFeaturesWithResults:(NSDictionary *)relatedFeatures;

/** Tells the delegate that @c AGSFeatureLayer encountered an error while performing 
 query for related features.
 @param featureLayer The feature layer which performed the query.
 @param op The operation that performed the query.
 @param error Information about the error that was encountered.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFailQueryRelatedFeaturesWithError:(NSError *)error;

/** Tells the delegate that @c AGSFeatureLayer successfully selected the given 
 features.
 @param featureLayer The feature layer which performed the selection.
 @param op The operation that performed the selection.
 @param featureSet The set of features that were selected.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didSelectFeaturesWithFeatureSet:(AGSFeatureSet *)featureSet;

/** Tells the delegate that @c AGSFeatureLayer encountered an error while try to 
 select features.
 @param featureLayer The feature layer which performed the selection.
 @param op The operation that performed the selection.
 @param error Information about the error that was encountered.
 @since 1.0
 */
- (void)featureLayer:(AGSFeatureLayer *)featureLayer operation:(NSOperation*)op didFailSelectFeaturesWithError:(NSError *)error;

@end
