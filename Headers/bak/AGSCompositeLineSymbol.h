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

#import <Foundation/Foundation.h>

@class AGSSymbol;

/** @file AGSCompositeLineSymbol.h */ //Required for Globals API doc

#pragma mark -

#pragma mark -

/** @brief A line symbol based on simple patterns.
 
 Instances of this class represent composite line symbols. Symbols describe how 
 graphics look on the map. Different symbols are used for graphics with different 
 geometry types. Line symbols are used to display those graphics which are based 
 on a polyline geometry. Composite line symbols display graphics using an array of 
 @c AGSSimpleLineSymbols to create a gradient effect. 
 
 @define{AGSCompositeLineSymbol.h, ArcGIS}
 @since 2.2
 */
@interface AGSCompositeLineSymbol : AGSSymbol 

/** The array of @c AGSSimpleLineSymbols to be used to draw the composite line.
 @since 2.2
 */
@property (nonatomic, retain) NSMutableArray *symbols;

/** Initialize a composite line symbol with an array of @c AGSSimpleLineSymbols. 
 The objects should be in a descending order by width in order to draw correctly.
 @param symbols An array of @c AGSSimpleLineSymbols to draw.
 @return A new composite line symbol object.
 @since 2.2
 */
- (id)initWithLineSymbols:(NSMutableArray*)symbols;

/** Initialize a composite line symbol with an array of colors and widths. 
 The objects should be in a descending order by width in order to draw correctly.
 @param colors An array of UIColor objects.
 @param widths An array of line widths.
 @return A new composite line symbol object.
 @since 2.2
 */
- (id)initWithColors:(NSMutableArray*)colors widths:(NSMutableArray*)widths;

/** Initialize an autoreleased composite line symbol.
 @return A new, autoreleased, composite line symbol object.
 @since 2.2
 */
+ (id)compositeLineSymbol;

/** Initialize a composite line symbol with an array of @c AGSSimpleLineSymbols. 
 The objects should be in a descending order by width in order to draw correctly.
 @param symbols An array of @c AGSSimpleLineSymbols to draw.
 @return A new, autoreleased, composite line symbol object.
 @since 2.2
 */
+ (id)compositeLineSymbolWithSymbols:(NSMutableArray*)symbols;

@end
