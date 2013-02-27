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

/** @file AGSMPSymbolDictionaryFilter.h */ //Required for Globals API doc

/** @brief A symbol dictionary filter.
 
 The @c AGSMPSymbolDictionaryFilter class is to be used with @c AGSMPSymbolDictionaryQuery
 to query the symbol dictionary to get a filtered list of symbols. 
 A dictionary provides a set of predefined filters and associated values
 that can then be passed to a symbol dictionary query using instances of this class.
 
 @define{AGSMPSymbolDictionaryFilter.h, ArcGIS}
 @since 10.1.1
 */
@interface AGSMPSymbolDictionaryFilter : NSObject

/** The filter name.
 @since 10.1.1
 */
@property (nonatomic, copy, readwrite) NSString* name;

/** The filter value.
 @since 10.1.1
 */
@property (nonatomic, copy, readwrite) NSString* value;

/** Initialize this filter with a name and value.
 @param value value for filter.
 @param name name for value.
 @return A new, autoreleased, symbol dictionary filter object.
 @since 10.1.1
 */
- (id)initWithValue:(NSString *)value forName:(NSString *)name;

/** A method to get an initialized, autoreleased, filter with a name and value.
 @param value value for filter.
 @param name name for value.
 @return A new, autoreleased, symbol dictionary filter object.
 @since 10.1.1
 */
+ (id)filterWithValue:(NSString *)value forName:(NSString *)name;

@end
