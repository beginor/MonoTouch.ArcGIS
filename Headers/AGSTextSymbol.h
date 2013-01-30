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

@class AGSMarkerSymbol;
	
/** @file AGSTextSymbol.h */ //Required for Globals API doc

/** @brief A text symbol
 
 Instances of this class represent text symbols. Symbols describe how graphics look on the map. 
 Different symbols are used for graphics with different geometry types.
 Text symbols are used to display text for graphics. The graphics can be based on
 any type of geometry - point, multipoint, polyline, or polygon. 
 
 @since 1.8
 */
@interface AGSTextSymbol : AGSMarkerSymbol 

/** The color of the background of the text symbol.
 @since 1.8
 */
@property (nonatomic, copy, readwrite) AGSColor *backgroundColor;

/** The outline color of the text.
 @since 1.8
 */
@property (nonatomic, copy, readwrite) AGSColor *borderLineColor;

/** The outline width of the text.
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) CGFloat borderLineWidth;

/** The vertical alignment of the text.
 @since 1.8
 */
@property (nonatomic, assign, readwrite) AGSTextSymbolVAlignment vAlignment;

/** The horizontal alignment of the text.
 @since 1.8
 */
@property (nonatomic, assign, readwrite) AGSTextSymbolHAlignment hAlignment;

/** The font family to use for the text.
 @since 1.8
 */
@property (nonatomic, copy) NSString *fontFamily;

/** The size of the font.
 @since 1.8
 */
@property (nonatomic, assign) CGFloat fontSize;

/** The text to be displayed for a the associated graphic.
 @since 10.1.1
 */
@property (nonatomic, copy) NSString *text;

/** Whether the text is bold or not.
 @since 10.1.1
 */
@property (nonatomic, assign) BOOL bold;

/** Whether the text is italic or not.
 @since 10.1.1
 */
@property (nonatomic, assign) BOOL italic;

/** Whether the text is underlined or not.
 @since 10.1.1
 */
@property (nonatomic, assign) BOOL underline;

/** Whether the text has a strike-thru line or not.
 @since 10.1.1
 */
@property (nonatomic, assign) BOOL strikeThru;

/** Initializes a text symbol.
 @since 1.8
 */
-(id)initWithText:(NSString*)text color:(AGSColor*)color;

/** Returns an autoreleased text symbol.
 @since 1.8
 */
+(AGSTextSymbol*)textSymbolWithText:(NSString*)text color:(AGSColor*)color;


@end