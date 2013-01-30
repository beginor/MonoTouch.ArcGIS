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
@class AGSSymbol;

/** @file AGSClassBreak.h */ //Required for Globals API doc

/** @brief A class break for the @c AGSClassBreaksRenderer
 
 Instances of this class represent class breaks. A class break specifies a 
 range of values and a corresponding symbol. @c AGSClassBreaksRenderer applies 
 the symbol to graphics which have values that fall within the specified range.
 
 @define{AGSClassBreaksRenderer.h, ArcGIS}
 @since 1.0
 */
@interface AGSClassBreak : NSObject <AGSCoding, NSCopying> {
}

/** Label for the symbol used to draw the value.
 @since 1.0
 */
@property (nonatomic, copy, readwrite) NSString *label;

/** Description for the symbol used to draw the value.
 @since 1.0
 */
@property (nonatomic, copy, readwrite) NSString *breakDescription;

/** The maximum value for this class break.
 @since 1.0
 */
@property (nonatomic, readwrite) double maxValue;

/** Symbol to use for this class break.
 @since 1.0
 */
@property (nonatomic, strong, readwrite) AGSSymbol *symbol;

/** Initialize an <code>AGSClassBreak</code>.
 @param label The label for the symbol used to draw the value.
 @param description The description for the symbol used to draw the value.
 @param maxValue The maximum value.
 @param symbol The symbol used to display the value.
 @since 1.0
 */
- (id)initWithLabel:(NSString *)label description:(NSString*)description maxValue:(double)maxValue symbol:(AGSSymbol *)symbol;

/** Initialize an autoreleased <code>AGSClassBreak</code>.
 @param label The label for the symbol used to draw the value.
 @param description The description for the symbol used to draw the value.
 @param maxValue The maximum value.
 @param symbol The symnol used to display the value.
 @since 1.0
 */
+ (id)classBreakInfoWithLabel:(NSString *)label description:(NSString*)description maxValue:(double)maxValue symbol:(AGSSymbol *)symbol;

/** Returns an NSComparisonResult value that indicates the ordering of the receiver and another class break.
 @since 1.8
 */
-(NSComparisonResult)compare:(AGSClassBreak*)anotherClassBreak;

@end