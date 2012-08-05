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

/** @file AGSSymbolSubclass.h */ //Required for Globals API doc

/** @brief 
 
 The extensions in this header are to be used by subclasses of AGSSymbol only.
 
 @define{AGSSymbolSubclass.h, ArcGIS}
 @since 2.2
 */
@interface AGSSymbol (ForSubclassEyesOnly)

/** Property called by the framework. Most symbols should have this set to YES as soon as 
 the symbol is init'ed. If a symbol needs to access a resource asynchronously before it's ready
 to draw then it should be set to NO initially then YES once it is ready. This is not as efficient
 as if a symbol is readyToDraw to begin with, however, so custom symbols should only set this to NO
 initially if absolutely necessary.
 */
@property (nonatomic, assign) BOOL readyToDraw;

/** Method called by @c AGSGraphicsLayer to draw geometry onto context.
 @since 1.8
 */
- (void)drawGraphic:(AGSGraphic *)graphic inContext:(CGContextRef)context forEnvelope:(AGSEnvelope*)env atResolution:(double)resolution;

/** Called to see if the symbol should draw for a specific envelope.
 @since 1.8
 */
-(BOOL)shouldDrawGraphic:(AGSGraphic*)graphic forEnvelope:(AGSEnvelope*)envelope atResolution:(double)resolution;

/** Called to see if the geometry passes a hit test for this symbol.
 @since 1.8
 */
-(BOOL)hitTestGraphic:(AGSGraphic*)graphic withEnvelope:(AGSEnvelope*)envelope atResolution:(double)resolution;

/** A method that derived classes can call to help during drawing.
 @since 2.2
 */
+(CGPoint)toScreenPointWithX:(double)x y:(double)y envelope:(AGSEnvelope*)env resolution:(double)res;

@end

