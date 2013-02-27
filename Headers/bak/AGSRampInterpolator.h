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

@class AGSSymbolInterpolator;

/** @file AGSRampInterpolator.h */ //Required for Globals API doc

/** @brief A symbol interpolator that uses ramps 
 
 Instances of this class represent interpolators that can be used to change the appearance of features. 
 
 A ramp interpolator finds a suitable size and color for a feature from a ramp (range) of sizes and colors.
 The ramps are specified using starting and ending values. The interpolator determines
 the exact size and color for a feature by comparing the feature's time information with the map's 
 time extent. For example, if a feature's time information falls in the center of the map's time extent, 
 a size and color from the middle of the specified range is used for the symbol. When a feature's time information
 contains both a start time and an end time, the start time is compared with the map's time extent to
 determine size and color to use.

 
 @define{AGSRampInterpolator.h, ArcGIS}
 @since 1.8
 */
@interface AGSRampInterpolator : AGSSymbolInterpolator {
@private
	UIColor *_startColor;
	UIColor *_endColor;
	CGFloat _startSize;
	CGFloat _endSize;
	
	CGFloat _r1, _g1, _b1, _a1, _r2, _g2, _b2, _a2;
}

/** The start color of the ramp.
 @since 1.8
 */
@property (nonatomic, retain) UIColor *startColor;

/** The end color of the ramp.
 @since 1.8
 */
@property (nonatomic, retain) UIColor *endColor;

/** The start size of the ramp.
 @since 1.8
 */
@property (nonatomic, assign) CGFloat startSize;

/** The end size of the ramp.
 @since 1.8
 */
@property (nonatomic, assign) CGFloat endSize;

/** Initializes an AGSRampInterpolator.
 @since 1.8
 */
-(id)initWithStartColor:(UIColor*)startColor endColor:(UIColor*)endColor startSize:(CGFloat)startSize endSize:(CGFloat)endSize;

/** Initializes an AGSRampInterpolator.
 @since 1.8
 */
-(id)initWithStartColor:(UIColor*)startColor endColor:(UIColor*)endColor;

/** Returns an autoreleased AGSRampInterpolator.
 @since 1.8
 */
+(AGSRampInterpolator*)rampInterpolatorWithStartColor:(UIColor*)startColor endColor:(UIColor*)endColor startSize:(CGFloat)startSize endSize:(CGFloat)endSize;

/** Returns an autoreleased AGSRampInterpolator.
 @since 1.8
 */
+(AGSRampInterpolator*)rampInterpolatorWithStartColor:(UIColor*)startColor endColor:(UIColor*)endColor;

@end
