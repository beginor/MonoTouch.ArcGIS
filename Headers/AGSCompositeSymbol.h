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

@class AGSSymbol;

/** @file AGSCompositeSymbol.h */ //Required for Globals API doc

#pragma mark -

/** @brief A composite symbol composed of multiple symbols.
 
 Instances of this class represent composite symbols. Composite symbols are 
 simply a combination of two or more symbols. Each symbol can represent the same 
 or a different aspect of a graphic. 
 
 For example, consider a composite symbol of an @c AGSSimpleMarkerSymbol and an 
 @c AGSSimpleFillSymbol. A polygon displayed with this composite symbol would 
 display the marker at each vertex along the polygon, and fill the interior 
 space of each ring in the polygon.
 
 @define{AGSCompositeSymbol.h, ArcGIS}
 @since 1.0
 */
@interface AGSCompositeSymbol : AGSSymbol {
 @private
    NSMutableArray *_symbols;
}

/** The individual symbols which make up this composite symbol. The symbols are 
 drawn in the order they are stored in the array. The 0th symbol is drawn first,
 then the next symbol is drawn on top of it, and so on.
 @since 1.0
 */
@property (nonatomic, retain) NSMutableArray *symbols;

/** A method to get an initialized and autoreleased composite symbol.
 @return A new, autoreleased, composite symbol object.
 @since 1.0
 */
+ (id)compositeSymbol;

@end
