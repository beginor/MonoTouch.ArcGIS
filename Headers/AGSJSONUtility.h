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

/** @file AGSJSONUtility.h */ //Required for Globals API doc

/** @brief Utility interface for dealing with JSON.

 Represents an interface with convenience methods for dealing with JSON.
 
 @define{AGSJSONUtility.h, ArcGIS}
 @since 1.0
 */
@interface AGSJSONUtility : NSObject {

}

/** Class method to encode an <code>NSArray</code> to a dictionary for a given key.
 @param json The JSON dictionary to encode @em items to.
 @param key The key to place encoded array at.
 @param items The array to be encoded to JSON.
 @since 1.0
 */
+(void)encodeToDictionary: (NSMutableDictionary *)json
				  withKey:(NSString *)key
		   AGSCodingArray: (NSArray *)items;

/** Class method to decode an array from a dictionary. The decoded area will contain
 objects of type @p cls.
 @param json The JSON dictionary to decode from.
 @param key The key to pull value to decode from.
 @param cls The type of objects to place in array.
 @return The array of decoded objects of type @p cls.
 @since 1.0
 */ 
+(NSMutableArray *)decodeFromDictionary: (NSDictionary *)json
						 withKey:(NSString *)key
					   fromClass:(Class) cls;

/** Class method to retrieve an <code>NSString</code> from a dictionary for a 
 given @p key.
 @param json The JSON dictionary to pull string from.
 @param key The key to object in JSON dictionary.
 @return The string value of object at @p key.
 @since 1.0
 */
+(NSString*)getStringFromDictionary: (NSDictionary *)json
							withKey:(NSString *)key;

@end
