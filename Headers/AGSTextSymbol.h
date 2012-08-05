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

#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>

@class AGSSymbol;
	
/** Specifies how a text symbol should be vertically aligned.
 @since 1.8
 */
typedef enum {
	AGSTextSymbolVAlignmentBaseline = 0,	/*!<  */
	AGSTextSymbolVAlignmentTop,				/*!<  */
	AGSTextSymbolVAlignmentMiddle,			/*!<  */
	AGSTextSymbolVAlignmentBottom			/*!<  */
} AGSTextSymbolVAlignment;

/** Specifies how a text symbol should be horizontally aligned.
 @since 1.8
 */
typedef enum {
	AGSTextSymbolHAlignmentLeft = 0,		/*!<  */
	AGSTextSymbolHAlignmentRight,			/*!<  */
	AGSTextSymbolHAlignmentCenter,			/*!<  */
	AGSTextSymbolHAlignmentJustify			/*!<  */
} AGSTextSymbolHAlignment;

/** Specifies how a font should be  styled in a text symbol.
 @since 1.8
 */
typedef enum {
	AGSTextSymbolFontStyleNormal = 0,		/*!<  */
	AGSTextSymbolFontStyleItalic,			/*!<  */
	AGSTextSymbolFontStyleOblique			/*!<  */
} AGSTextSymbolFontStyle;

/** Specifies the weight of a font in a text symbol.
 @since 1.8
 */
typedef enum {
	AGSTextSymbolFontWeightLighter = 0,		/*!<  */
	AGSTextSymbolFontWeightNormal,			/*!<  */
	AGSTextSymbolFontWeightBold,			/*!<  */
	AGSTextSymbolFontWeightBolder			/*!<  */
} AGSTextSymbolFontWeight;

/** Specifies how a font should be  decorated in a text symbol.
 @since 1.8
 */
typedef enum {
	AGSTextSymbolFontDecorationNone = 0,		/*!<  */
	AGSTextSymbolFontDecorationLineThrough,		/*!<  */
	AGSTextSymbolFontDecorationUnderline		/*!<  */
} AGSTextSymbolFontDecoration;

/** @file AGSTextSymbol.h */ //Required for Globals API doc

/** @brief A text symbol
 
 Instances of this class represent text symbols. Symbols describe how graphics look on the map. 
 Different symbols are used for graphics with different geometry types.
 Text symbols are used to display text for graphics. The graphics can be based on
 any type of geometry - point, multipoint, polyline, or polygon. 
 
 
 @since 1.8
 */
@interface AGSTextSymbol : AGSSymbol 

/** The color of the background of the text symbol.
 @since 1.8
 */
@property (nonatomic, retain, readwrite) UIColor *backgroundColor;

/** The outline color of the text.
 @since 1.8
 */
@property (nonatomic, retain, readwrite) UIColor *borderLineColor;

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
@property (nonatomic, retain) NSString *fontFamily;

/** The size of the font.
 @since 1.8
 */
@property (nonatomic, assign) float fontSize;

/** The text template to be applied when drawing a graphic.
 Tokens of the form <i>${...}</i> in the 
 @c textTemplate are replaced at runtime with corresponding values 
 from the graphic's attributes. The final text is then displayed.
 
 For example, consider a graphic which has an attribute <b>STATE_NAME</b> with 
 the value <b>California</b>. For the symbol to draw the attribute's value,
 you need to set <i>${STATE_NAME}</i> as the @p textTemplate. The token 
 <i>${STATE_NAME}</i> will then be automatically substituted with the value 
 <b>California</b> when the symbol is drawn.
 @since 1.8
 */
@property (nonatomic, retain) NSString *textTemplate;

/** The style of the font.
 @since 1.8
 */
@property (nonatomic, assign) AGSTextSymbolFontStyle fontStyle;

/** The weight of the font.
 @since 1.8
 */
@property (nonatomic, assign) AGSTextSymbolFontWeight fontWeight;

/** The decoration on the font.
 @since 1.8
 */
@property (nonatomic, assign) AGSTextSymbolFontDecoration fontDecoration;

/** The offset to apply to the shadow. This is in points.
 @since 1.8
 */
@property (nonatomic, assign) CGSize shadowOffset;

/** The amount of blur to apply to the shadow.
 @since 1.8
 */
@property (nonatomic, assign) CGFloat shadowBlur;

/** The color of the shadow.
 @since 1.8
 */
@property (nonatomic, retain) UIColor *shadowColor;

/** The offset on the x-axis in points. Default is 0.
 @since 1.8
 */
@property (nonatomic) CGFloat xoffset;

/** The offset on the y-axis in points. Default is 0.
 @since 1.8
 */
@property (nonatomic) CGFloat yoffset;

//@property (nonatomic, assign, readwrite) BOOL rightToLeft;
//@property (nonatomic, assign, readwrite) BOOL kerning;

/** The rotation angle (in degrees) of the text. The text is rotated in a counter-clockwise direction by the amount specified. 
 @since 1.8
 */
@property (nonatomic) CGFloat angle;

/** Specifies whether the symbol should be rotated around its offset
 location or its center.
 @since 1.8
 */
@property (nonatomic) BOOL rotateAroundOffset;

/** Initializes a text symbol.
 @since 1.8
 */
-(id)initWithTextTemplate:(NSString*)textTemplate color:(UIColor*)color;

/** Returns an autoreleased text symbol.
 @since 1.8
 */
+(AGSTextSymbol*)textSymbolWithTextTemplate:(NSString*)textTemplate color:(UIColor*)color;


@end