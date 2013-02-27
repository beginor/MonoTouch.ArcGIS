/*
 COPYRIGHT 2010 ESRI
 
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
#import <UIKit/UIColor.h>

/** @file UIColor+AGSAdditions.h */ //Required for Globals API doc

/** @brief Category to initialize a <code>UIColor</code> with JSON.
 
 Category that adds the ability to initialize a <code>UIColor</code> with an 
 array of <code>NSUInteger</code> color values.
 
 @define{UIColor+AGSAdditions.h, ArcGIS}
 @since 1.0
 @see AGSCoding
 */
@interface UIColor (AGSAdditions)

/** Initialize a <code>UIColor</code> with an array of <code>NSUInteger</code> objects 
 representing color values. The order should be (Red, Green, Blue, Alpha).
 @param colors The array of color values to initialize the object.
 @return A new, initialized, <code>UIColor</code> object.
 @since 1.0
 */
- (id)initWithRGBA:(NSArray *)colors;

/** Returns an <code>NSArray</code> of the color components of the 
 <code>UIColor</code>.
 @since 1.0
 */
- (NSArray *)encodeToRGBA;

@end
