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



@class AGSSymbol;
@class AGSFillSymbol;
@class AGSSimpleLineSymbol;

/** @file AGSSimpleFillSymbol.h */ //Required for Globals API doc

#pragma mark -

/** Supported fill styles.
 @since 1.0
 */
typedef enum {
    AGSSimpleFillSymbolStyleBackwardDiagonal = 0,	/*!< */
    AGSSimpleFillSymbolStyleCross,					/*!< */
    AGSSimpleFillSymbolStyleDiagonalCross,			/*!< */
    AGSSimpleFillSymbolStyleForwardDiagonal,		/*!< */	
    AGSSimpleFillSymbolStyleHorizontal,				/*!< */
    AGSSimpleFillSymbolStyleNull,					/*!< */
    AGSSimpleFillSymbolStyleSolid,					/*!< */
    AGSSimpleFillSymbolStyleVertical				/*!< */
} AGSSimpleFillSymbolStyle;



#pragma mark -

/** @brief A fill symbol based on simple patterns.
 
 Instances of this class represent simple fill symbols. Symbols describe how 
 graphics look on the map. Different symbols are used for graphics with different 
 geometry types.  Fill symbols are used with graphics which are based 
 on a polygon geometry. The symbol can fill the interior of a polygon graphic
 with a solid color. In addition, the symbol can have 
 an optional outline which is defined by a line symbol.
 
 @define{AGSSimpleFillSymbol.h, ArcGIS}
 @since 1.0
 */

@interface AGSSimpleFillSymbol : AGSFillSymbol

/** The fill style. Possible values include
  
 @li @c AGSSimpleFillSymbolStyleBackwardDiagonal
 @li @c AGSSimpleFillSymbolStyleCross
 @li @c AGSSimpleFillSymbolStyleDiagonalCross
 @li @c AGSSimpleFillSymbolStyleForwardDiagonal
 @li @c AGSSimpleFillSymbolStyleHorizontal
 @li @c AGSSimpleFillSymbolStyleNull
 @li @c AGSSimpleFillSymbolStyleSolid
 @li @c AGSSimpleFillSymbolStyleVertical
 
 Default is AGSSimpleFillSymbolStyleSolid.
 @since 1.0
 */
@property (nonatomic, assign) AGSSimpleFillSymbolStyle style;

/** Initialize an autoreleased symbol.
 @return A new, autoreleased, simple fill symbol object.
 @since 1.0
 */
+ (id)simpleFillSymbol;

/** Initialize a symbol with a fill color and an outline color
 @since 1.8
 */
-(id)initWithColor:(AGSColor*)fillColor outlineColor:(AGSColor*)outlineColor;

/** Initialize an autoreleased symbol with a fill color and an outline color
 @since 1.8
 */
+(AGSSimpleFillSymbol*)simpleFillSymbolWithColor:(AGSColor*)fillColor outlineColor:(AGSColor*)outlineColor;

@end




