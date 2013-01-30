/*
 COPYRIGHT 2011 ESRI
 
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
@class AGSGraphic;
@class AGSSymbol;

/** @file AGSSymbolInterpolator.h */ //Required for Globals API doc

/** @brief An object that is used for changing the appearance of features. 

 Instance of this class represent interpolators that can be used to change the appearance of features. 
 This is a base class and is not to be used directly.  Sub-classes provide various schemes through which a symbol of 
 a feature can be modified based on the feature's attributes.
 
 @define{AGSSymbolInterpolator.h, ArcGIS}
 @since 1.8
 */
@interface AGSSymbolInterpolator : NSObject {

}

/** Returns an interpolated symbol for the specified feature.
 @since 1.8
 */
-(AGSSymbol*)interpolatedSymbolForGraphic:(AGSGraphic*)graphic
						   originalSymbol:(AGSSymbol*)origSymbol
									start:(double)start
									  end:(double)end
									  val:(double)val;

@end
