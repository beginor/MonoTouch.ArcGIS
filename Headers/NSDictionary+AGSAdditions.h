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

/** @file NSDictionary+AGSAdditions.h */ //Required for Globals API doc

/** @brief A category on @c NSDictionary containing convenience methods
 
 A category on @c NSDictionary containing convenience methods

 
 @define{NSDictionary+AGSAdditions.h, ArcGIS}
 @since 1.0
 */
@interface NSDictionary (AGSAdditions)

/** Used to encode dictionary into URL query parameter string.
 @since 1.0
 */
- (NSString *)ags_encodeQueryParams;

/** Used for encoding of dictionary in order to simplify encoding to query parameters.
 @since 1.0
 */
- (NSDictionary *)ags_encodeJSON;

/** Used when retrieving a result from a dictionary when only the key name is 
 available.
 
 For example when retrieving the result of a query, with key "Display Name" available
 but not the value.
 
 If the results look like this:
 <code>
 {
	"Display Name" = "California",
 }
 </code>
 and @p templateString = @"${Display Name}"
 
 The following method will return an <code>NSString</code> equal to @"California".
 @since 1.0
 */
- (NSString *)ags_stringByApplyingTemplate:(NSString *)templateString;

/** Returns the value associated with key from dict.  If the
 value is equal to <code>[NSNull null]</code>, the method will return <code>nil</code>.
 @param key Key corresponding to the value to retrieve.
 @return The value associated with the given key.
 @deprecated Deprecated at 10.1.1 Use #safeValue:forKey: or #safeObject:forKey on NSDictionary instead.
 @since 2.2
 */
-(id)ags_safeGetObjectForKey:(id)key __attribute__((deprecated));

/** Returns the value associated with key from dict.  If the
 value is equal to <code>[NSNull null]</code>, the method will return <code>nil</code>.
 @param key Key corresponding to the value to retrieve.
 @return The value associated with the given key.
 @since 10.1.1
 */
-(id)ags_safeValueForKey:(NSString*)key;

/** Returns the value associated with key from dict.  Because this method is "safe", if the
 value is equal to <code>[NSNull null]</code>, the method will return <code>nil</code>.
 @param key Key corresponding to the value to retrieve.
 @return The value associated with the given key.
 @since 10.1.1
 */
-(id)ags_safeObjectForKey:(id)key;

/** Returns an NSURL for the given key. This method will account for unicode characters or spaces.
 If the value for the given key is not a string, this method will return nil.
 @param key Key corresponding to the value to retrieve.
 @return An NSURL object for the string value associated with the given key.
 @since 10.1.1
 */
-(NSURL*)ags_URLForKey:(id)key;
@end

/** @brief A category on @c NSDictionary containing convenience methods
 
 A category on @c NSMutableDictionary containing convenience methods
 
 @since 1.0
 */

@interface NSMutableDictionary (AGSAdditions)

/** Sets the object into the dictionary with the given key.  If the
 object is <code>nil</code>, will not set anything in the dictionary.
 @param object The object to place in the dictionary.
 @param key The key in which to pair with @p object in the dictionary.
 @deprecated Deprecated at 10.1.1. Use #setValue:forKey: on NSMutableDictionary instead.
 @since 2.2
 */
-(void)ags_safeSetObject:(NSObject*)object forKey:(NSString*)key __attribute__((deprecated));

/** Sets the object into the dictionary with the given key.  If the
 object is <code>nil</code>, will use the useNSNull parameter to determine
 if it should set NSNull or not for nil objects.
 @param object The object to place in the dictionary.
 @param key The key in which to pair with @p object in the dictionary.
 @param useNSNull The parameter that determines if NSNull should be used for nil objects.
 @deprecated Deprecated at 10.1.1. Use #setValue:forKey: on NSMutableDictionary instead.
 @since 2.2
 */
-(void)ags_safeSetObject:(NSObject*)object forKey:(NSString*)key useNSNull:(BOOL)useNSNull __attribute__((deprecated));
@end