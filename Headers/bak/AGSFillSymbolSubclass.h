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
@class AGFillSymbol;

/** @file AGSFillSymbolSubclass.h */ //Required for Globals API doc

/** @brief 
 
 The extensions in this header are to be used by subclasses of AGSFillSymbol only.
 
 @define{AGSFillSymbolSubclass.h, ArcGIS}
 @since 2.2
 */
@interface AGSFillSymbol (ForSubclassEyesOnly)

/** This must be implemented by derived classes, don't implement drawGraphic:inContext:forEnvelope:withResolution,
 implement this instead.
 @since 2.2
 */
-(void)applySymbolToContext:(CGContextRef)context withGraphic:(AGSGraphic*)graphic envelope:(AGSEnvelope*)env resolution:(double)res;

@end

