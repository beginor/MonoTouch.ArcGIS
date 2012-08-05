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

#import <Foundation/Foundation.h>
@class AGSMapView;
@protocol AGSWebMapDelegate;
@class AGSWebMapBaseMap;
@class AGSPortalItem;
@class AGSPopupInfo;
@class AGSPortal;
@class AGSPortalItem;
@class AGSWebMapLayerInfo;

/** @file AGSWebMap.h */ //Required for Globals API doc

/** @brief An object representing a webmap
 
 Instances of this class represent a webmap. A webmap is essentially a simple configuration
 file that describes the contents to be displayed in a map. You can use, create, and share webmaps
 interactively on www.ArcGIS.com or your own ArcGIS Portal.   

 Instantiating an object of @c AGSWebMap loads the webmap by retrieving its data from a server. To view the contents 
 of the webmap, you need to open it using @c #openIntoMapView:
 
 The webmap's #delegate is kept informed whenver operations performed by the webmap complete successfully or encounter an error.
 For exmaple, as each layer in the webmap is loaded successfully, the delegate is informed. If any layers fail to load, 
 the delegate is given an opportunity to skip to the next layer, or re-try loading the current layer with proper 
 credentials if the layer was using a secured service. If the webmap contains a Bing Maps layer, the delegate is asked 
 to provide a valid Bing Maps app ID to use with that layer. 
 
 Note, you should always open a webmap into a
 map view on the main thread.
 @see @concept{Viewing_a_Web_Map/00pw00000055000000/, Viewing a Web Map}
 @since 1.8
 */
@interface AGSWebMap : NSObject <AGSCoding, AGSSecuredResource>{
@private
    NSURL *_URL;
    NSURL *_sharingEndPoint;
	AGSCredential *_credential;
	float _version; 
	NSArray *_operationalLayers; // make public prop for?
	AGSWebMapBaseMap *_baseMap; // make public prop for?
	AGSPortalItem *_portalItem; // make public prop for?
	NSArray *_bookmarks; // webmapmake public prop for?
	NSArray *_queries; // make public prop for?
	
	id<AGSWebMapDelegate> _delegate;
	BOOL _zoomToDefaultExtentOnOpen;
	
	NSMutableArray *_layerInfosToLoad;
	AGSMapView *_mapView;
	AGSLayer *_currentLayerToLoad;
	AGSCredential *_currentLayerCredential;
	BOOL _waiting;
	int _failedCount;
	NSMutableArray *_credentialsList;
	AGSWebMapBaseMap *_customBaseMap;	
	
	NSOperation *_currentLoadOperation;
	BOOL _loaded;
	AGSMapView *_preloadMapView;
	AGSWebMapBaseMap *_preloadBaseMap;
    
    NSMutableArray *_itemIdOperations;
    NSMutableArray *_checkedForHosted;
}

/** Initializes a webmap. The @c #delegate will be informed when the webmap data is successfully retrieved from the server
 or if an error is encountered.
 @param url where the webmap's data can be accessed. 
 For example, http://<my_arcgis_portal>/sharing/content/items/<web_map_id>/data
 @param cred The credential to access the webmap.
 @since 2.0
 */
-(id)initWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Returns an autoreleased webmap. The @c #delegate will be informed when the webmap data is successfully retrieved from the server
 or if an error is encountered.
 @param url where the webmap's data can be accessed. 
 For example, http://<my_arcgis_portal>/sharing/content/items/<web_map_id>/data
 @param cred The credential to access the webmap.
 @since 2.0
 */
+(AGSWebMap*)webMapWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Returns an autoreleased webmap. The @c #delegate will be informed when the webmap data is successfully retrieved from the server
 or if an error is encountered.
 @param itemId The item id of the webmap on ArcGIS.com
 @param cred The credential to access the webmap.
 @since 2.0
 */
+(AGSWebMap*)webMapWithItemId:(NSString*)itemId credential:(AGSCredential*)cred;

/** Initializes a webmap. The @c #delegate will be informed when the webmap data is successfully retrieved from the server
 or if an error is encountered.
 @param itemId The item id of the webmap on ArcGIS.com
 @param cred The credential to access the webmap.
 @since 2.0
 */
-(id)initWithItemId:(NSString*)itemId credential:(AGSCredential*)cred;

/** Returns an autoreleased webmap. The @c #delegate will be informed when the webmap data is successfully retrieved from the server
 or if an error is encountered.
 @param itemId The item id of the webmap.
 @param sharingEndPoint The sharing endpoint of the portal where the webmap is stored. 
 For example, http://<my_arcgis_portal>/sharing/rest . Can be nil, in which case it is assumed the webmap is 
 stored on ArcGIS.com.
 @param cred The credential to access the webmap.
 @since 2.0
 */
+(AGSWebMap*)webMapWithItemId:(NSString*)itemId sharingEndPoint:(NSURL*)sharingEndPoint credential:(AGSCredential*)cred;

/** Initializes a webmap. The @c #delegate will be informed when the webmap data is successfully retrieved from the server
 or if an error is encountered.
 @param itemId The item id of the webmap.
 @param sharingEndPoint The sharing endpoint of the portal where the webmap is stored. 
 For example, http://<my_arcgis_portal>/sharing/rest . Can be nil, in which case it is assumed the webmap is 
 stored on ArcGIS.com.
 @param cred The credential to access the webmap.
 @since 2.0
 */
-(id)initWithItemId:(NSString*)itemId sharingEndPoint:(NSURL*)sharingEndPoint credential:(AGSCredential*)cred;

/** Initializes a webmap based on the given portal item. The item's @link AGSPortalItem#type type @endlink must be @c AGSPortalItemTypeWebMap. 
 
 The @c #delegate will be informed when the webmap's data is successfully retrieved from the server
 or if an error is encountered.
 
 @param item The item which is a webmap
 @since 2.2
 */
-(id)initWithPortalItem:(AGSPortalItem*)item;

/** Returns an autoreleased webmap based on the given portal item. The item's @link AGSPortalItem#type type @endlink must be @c AGSPortalItemTypeWebMap. 

 The @c #delegate will be informed when the webmap data is successfully retrieved from the server
 or if an error is encountered.
 @param item The item which is a webmap
 @since 2.2
 */
+(AGSWebMap*)webMapWithPortalItem:(AGSPortalItem*)item;

/** Returns an autoreleased webmap based on the given portal and itemId. The item's @link AGSPortalItem#type type @endlink must be @c AGSPortalItemTypeWebMap. 
 
 The @c #delegate will be informed when the webmap data is successfully retrieved from the server
 or if an error is encountered.
 @param itemId The id of the item which is a webmap
 @param portal The portal where the item resides
 @since 2.2
 */
+(AGSWebMap*)webMapWithItemId:(NSString*)itemId portal:(AGSPortal*)portal;

/** Initializes a webmap based on the given portal and itemId. The item's @link AGSPortalItem#type type @endlink must be @c AGSPortalItemTypeWebMap. 
 
 The @c #delegate will be informed when the webmap data is successfully retrieved from the server
 or if an error is encountered.
 @param itemId The id of the item which is a webmap
 @param portal The portal where the item resides
 @since 2.2
 */
-(id)initWithItemId:(NSString*)itemId portal:(AGSPortal*)portal;

/** The URL where the webmap's data can be accessed from.
 For example, http://<my_arcgis_portal>/sharing/content/items/<web_map_id>/data
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSURL *URL;

/** Credential used to access a secured resource
 @since 1.8
 */
@property (nonatomic, copy, readonly) AGSCredential *credential;

/** The delegate for the webmap.
 @since 1.8
 */
@property (nonatomic, assign) id<AGSWebMapDelegate> delegate;

/** Determines whether the webmap zooms to the default webmap extent
 when it is opened into a mapview.
 @since 1.8
 */
@property (nonatomic, assign) BOOL zoomToDefaultExtentOnOpen;

/** The bookmarks that this AGSWebMap contains.
 @since 2.0
 */
@property (nonatomic, retain, readonly) NSArray *bookmarks;

/** Whether or not the webmap is loaded.
 @since 2.0
 */
@property (nonatomic, readonly, getter=isLoaded) BOOL loaded;

/** This webmap's version information.
 @since 2.2
 */
@property (nonatomic, readonly) float version;

/** An array of @c AGSWebMapLayerInfo objects representing the operational layers in this webmap.
 @since 2.2
 */
@property (nonatomic, retain, readonly) NSArray *operationalLayers;

/** The basemap layer(s) in this webmap.
 @since 2.2
 */
@property (nonatomic, retain, readonly) AGSWebMapBaseMap *baseMap;

/** An instance of @c AGSPortalItem class representing this webmap. 
 @since 2.2
 */
@property (nonatomic, retain, readonly) AGSPortalItem *portalItem;

/** An array of @c AGSWebMapQuery objects representing the predefined queries that were authored with this webmap.
 @since 2.2
 */
@property (nonatomic, retain, readonly) NSArray *queries;

/** Starts opening a webmap into an AGSMapView. This method must be called on the main thread.
 The mapview will be @link AGSMapView#reset reset @endlink before opening the webmap.
 @param mapView The mapView to open the webmap into.
 @since 1.8
 */
-(void)openIntoMapView:(AGSMapView*)mapView;

/** Starts opening a webmap into an AGSMapView.
 @param mapView The mapView to open the webmap into.
 @param baseMap The alternate base map to use for opening the webmap. Can pass nil for this parameter,
 in which case it will use the default basemap.
 @since 2.2
 */
-(void)openIntoMapView:(AGSMapView*)mapView withAlternateBaseMap:(AGSWebMapBaseMap*)baseMap;

/** Starts opening a webmap into an AGSMapView. The other openIntoMapView methods all reset the AGSMapView
 before-hand. This method gives you the option of overriding that behavior. This is useful if you have your own
 basemap layers and you want to open the AGSWebMap over those layers. If you want to add only the operational layers
 (skipping the basemap layers), you can pass in an empty AGSWebMapBaseMap for the baseMap parameter. To get an empty
 AGSWebMapBaseMap you simply alloc and init it.
 @param mapView The mapView to open the webmap into.
 @param baseMap The alternate base map to use for opening the webmap. Can pass nil for this parameter,
 in which case it will use the default basemap.
 @param reset Whether or not you want this method to reset the AGSMapView before it starts opening the AGSWebMap.
 @since 2.2
 */
-(void)openIntoMapView:(AGSMapView*)mapView withAlternateBaseMap:(AGSWebMapBaseMap *)baseMap resetMapView:(BOOL)reset;

/** Continues opening the webmap with a credential.
 @since 1.8
 */
-(void)continueOpenWithCredential:(AGSCredential*)credential;

/** Continues opening the webmap and skips the current layer that failed.
 @since 1.8
 */
-(void)continueOpenAndSkipCurrentLayer;

/** Cancels opening the webmap.
 @since 1.8
 */
-(void)cancelOpen;

/** Returns the AGSPopupInfo that is associated with the layer of a particular url.
 This method does not create a new AGSPopupInfo. It returns a reference to an existing AGSPopupInfo.
 @since 2.0
 */
-(AGSPopupInfo*)popupInfoForMapServiceLayerWithURL:(NSURL*)url sublayerId:(NSInteger)sublayerId;

/** Returns the AGSPopupInfo that is associated with the AGSDynamicMapSerciceLayer.
 This method does not create a new AGSPopupInfo. It returns a reference to an existing AGSPopupInfo.
 @since 2.0
 */
-(AGSPopupInfo*)popupInfoForDynamicMapServiceLayer:(AGSDynamicMapServiceLayer*)dmsl sublayerId:(NSInteger)sublayerId;

/** Returns the AGSPopupInfo that is associated with the AGSTiledMapServiceLayer.
 This method does not create a new AGSPopupInfo. It returns a reference to an existing AGSPopupInfo.
 @since 2.0
 */
-(AGSPopupInfo*)popupInfoForTiledMapServiceLayer:(AGSTiledMapServiceLayer*)tmsl sublayerId:(NSInteger)sublayerId;

/** Returns the AGSPopupInfo that is associated with the AGSFeatureLayer.
 This method does not create a new AGSPopupInfo. It returns a reference to an existing AGSPopupInfo.
 @since 2.0
 */
-(AGSPopupInfo*)popupInfoForFeatureLayer:(AGSFeatureLayer*)featureLayer;

@end


/** @brief A delegate of @c AGSWebMap
 
 A protocol which must be adopted by a class wishing to serve as a delegate for 
 @c AGSWebMap. @c AGSWebMap informs the delegate of events and consults the 
 delegate before taking some action. 
 
 All of the methods of this protocol are optional.
 @since 1.8
 */
@protocol AGSWebMapDelegate <NSObject>
@optional

/** Tells the delegate that the webmap data was retrieved successfully.
 @param webMap The webmap that was loaded.
 @since 2.0
 */
- (void)webMapDidLoad:(AGSWebMap *)webMap;

/** Tells the delegate that the specified @p error was encountered while tyring to retrieve the webmap's data.
 @param webMap The webmap that failed to load.
 @param error Information about the cause of the failure.
 @since 2.0
 */
- (void)webMap:(AGSWebMap *)webMap didFailToLoadWithError:(NSError *)error;

/** Called when a webmap is done opening into an AGSMapView.
 @since 1.8
 */
-(void)didOpenWebMap:(AGSWebMap*)webMap intoMapView:(AGSMapView*)mapView;

/** Called when a layer fails to load. The delegate can either
 skip loading the layer using @c continueOpenAndSkipCurrentLayer method or retry loading it with credentials
 using @c continueOpenWithCredential: method on @c AGSWebMap
 @since 1.8
 @deprecated Use #didFailToLoadLayer:url:withError: instead. Deprecated at 2.1
 */
-(void)didFailToLoadLayer:(NSString*)layerTitle withError:(NSError*)error __attribute__((deprecated));

/** Called when a layer fails to load. The delegate can either
 skip loading the layer using @c continueOpenAndSkipCurrentLayer method or retry loading it with credentials
 using @c continueOpenWithCredential: method on @c AGSWebMap
 @param layerTitle The title of the layer being loaded.
 @param url The url of the layer being loaded.
 @param baseLayer Whether or not the layer is part of the basemap layers.
 @param error The error describing why the layer failed to load.
 @since 2.1
 */
-(void)didFailToLoadLayer:(NSString*)layerTitle url:(NSURL*)url baseLayer:(BOOL)baseLayer withError:(NSError*)error;

/**
 Called when a layer will be skipped because it was determined the layer was hosted and that the logged-in
 user did not have access to it.
 @since 2.3
 */
-(void)webMap:(AGSWebMap*)webMap willSkipHostedLayer:(AGSWebMapLayerInfo*)layerInfo;

/** Called when a layer loads.
 @since 1.8
*/
-(void)didLoadLayer:(AGSLayer*)layer;

/** Called when the webmap needs to open a Bing layer.
 @since 1.8
 */
-(NSString*)bingAppId;

@end




