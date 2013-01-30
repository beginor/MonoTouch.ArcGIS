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


@protocol AGSCoding;
@class AGSSymbol;

/** @file AGSUniqueValue.h */ //Required for Globals API doc

/** @brief An object representing value objects that are used in unique value
 renderers.
 
 Instances of this class represent value objects that are used in
 unique value renderers.
 
 @define{AGSUniqueValue.h, ArcGIS}
 @since 1.0
 */
@interface AGSUniqueValue : NSObject <AGSCoding, NSCopying>

/** The unique value.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *value;

/** Label for the symbol used to draw the value.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *label;

/** Label for the symbol used to draw the value.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *valueDescription;

/** The symbol used to display the value.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSSymbol *symbol;

/** Initialize an autoreleased unique value.
 @param value The value to symbolize.
 @param symbol The symbol to be used to display the value.
 @return A new, autoreleased, unique value.
 @since 1.0
 */
+(id)uniqueValueWithValue:(NSString*)value symbol:(AGSSymbol*)symbol;

/** Initialize a new unique value.
 @param value The value to symbolize.
 @param label The label for the symbol used to draw the value.
 @param description The description for the symbol used to draw the value.
 @param symbol The symbol used to display the value.
 @since 1.0
 */
-(id)initWithValue:(NSString*)value label:(NSString*)label description:(NSString*)description symbol:(AGSSymbol*)symbol;

@end