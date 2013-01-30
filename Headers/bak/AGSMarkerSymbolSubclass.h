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
@class AGSMarkerSymbol;

/** @file AGSMarkerSymbolSubclass.h */ //Required for Globals API doc

/** @brief 
 
 The extensions in this header are to be used by subclasses of AGSMarkerSymbol only.
 
 @define{AGSMarkerSymbolSubclass.h, ArcGIS}
 @since 2.2
 */
@interface AGSMarkerSymbol (ForSubclassEyesOnly)

/** This must be implemented by derived classes, don't implement drawGraphic:inContext:forEnvelope:withResolution,
 implement this instead.
 @since 2.2
 */
-(void)drawGraphic:(AGSGraphic*)graphic atX:(float)x y:(float)y inContext:(CGContextRef)context;

/** This must be implemented by derived classes. Returns the screen size in points of the symbol
 to be drawn.
 @since 2.2
 */
-(CGSize)drawingSize;

/** This may be called by derived classes when a property changes and it needs to invalidate
 the cache. For example, when you change the size of a simple marker symbol, SMS will
 call it so that it draws correctly, if the symbol is cached.
 @since 2.2
 */
-(void)invalidateCache;

@end

