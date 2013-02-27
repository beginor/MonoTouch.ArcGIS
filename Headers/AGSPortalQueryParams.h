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

/** @file AGSPortalQueryParams.h */ //Required for Globals API doc

/** @brief Defines a query on a portal. 
 
 To query a portal for items or groups, AGSPortal's <code>findItemsWithQueryParams:</code> and <code>
 findItemsWithQueryParams:</code> need to be used with the query parameters obtained from 
 AGSPortalQueryParams. It provides various pre-defined query strings. You can also create custom query 
 strings as per the specification in the Portal API. It also helps you to search with paging enabled by 
 specifying the search limit and start index. You can also sort the results according to a particular 
 field in the results. 
 
 @since 2.2
 */
@interface AGSPortalQueryParams : NSObject <AGSCoding>

/** The query string specified for the search. 
 @since 2.2
 */
@property (nonatomic, copy, readwrite) NSString *query;

/** The field on which sorting should be done. 
 @since 2.2
 */
@property (nonatomic, copy, readwrite) NSString *sortField;

/** The order of sorting. 

 @since 2.2
 */
@property (nonatomic, assign, readwrite) AGSPortalQuerySortOrder sortOrder;

/** The index from which the results should be returned. The index number is 1-based. You should use this for paginating the search results. 
 @since 2.2
 */
@property (nonatomic, assign, readwrite) NSInteger startIndex;

/** The number of results to be returned. This, along with the @c #startIndex, can help you paginate the search results. . 
 @since 2.2
 */
@property (nonatomic, assign, readwrite) NSInteger limit;

/** Initializes a AGSPortalQueryParams with a query string. 
 @param query The query string.  
 @since 2.2
 */
-(id)initWithQuery:(NSString*)query;

/** A method to get an initialized, autoreleased query params object with a query string. 
 @param query The query string. 
 @since 2.2
 */
+(AGSPortalQueryParams*)queryParamsWithQuery:(NSString*)query;

/** Initializes a AGSPortalQueryParams with a query string and the limit on results. 
 @param query The query string.
 @param limit The number of results to be returned. 
 @since 2.2
 */
-(id)initWithQuery:(NSString*)query limit:(NSInteger)limit;

/** A method to get an initialized, autoreleased query params object with a query string and the limit. 
 @param query The query string. 
 @param limit The number of results to be returned.  
 @since 2.2
 */
+(AGSPortalQueryParams*)queryParamsWithQuery:(NSString*)query limit:(NSInteger)limit;

/** Returns query params that will find groups with a specified owner and title. Either property can be 
 nil, but not simultaneously.
 @param username The username of the owner. 
 @param title The title of the group. 
 @since 2.2
 */
+(AGSPortalQueryParams*)queryParamsForGroupsWithOwner:(NSString*)username title:(NSString*)title;

/** Returns query params that will find items with a specified type that satisfy the specified criteria.
 @param type The type of the portal item. 
 @param searchString The string used for broader search on the items; such as on tags, title etc. Can be nil.
 @since 2.2
 */
+(AGSPortalQueryParams*)queryParamsForItemsOfType:(AGSPortalItemType)type withSearchString:(NSString*)searchString;

/** Returns query params that will find items with a specified type that belong to a specified group .
 @param type The type of the portal item. 
 @param groupId The id of the group. Can be nil.
 @param searchString The string used for broader search on the items; such as on tags, title etc. Can be nil.
 @since 2.2
 */
+(AGSPortalQueryParams*)queryParamsForItemsOfType:(AGSPortalItemType)type inGroup:(NSString*)groupId withSearchString:(NSString*)searchString;

/** Returns query params that will find items with a specified type that belong to a specified group.
 @param type The type of the portal item. 
 @param groupId The id of the group. Can be nil.
 @since 2.2
 */
+(AGSPortalQueryParams*)queryParamsForItemsOfType:(AGSPortalItemType)type inGroup:(NSString*)groupId;

/** Returns query params that will find all items belonging to a specified group.
 @param groupId The id of the group.
 @since 2.2
 */
+(AGSPortalQueryParams*)queryParamsForItemsInGroup:(NSString*)groupId;

/** Returns a query params that will find an item with a specified id.
 @param itemId The id of the item.
 @since 2.2
 */
+(AGSPortalQueryParams*)queryParamsForItemWithId:(NSString*)itemId;
@end
