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
#import "AGSTime.h"

@class AGSSymbolInterpolator;

/** @file AGSTimeClassBreaksAger.h */ //Required for Globals API doc

/** @brief A symbol interpolator that uses time class breaks 
 
 Instances of this class represent symbol interpolators that use a collection of time class breaks to "age" features. 
 Aging a feature means modifying its symbol's properties, such as size or color, depending on how old or recent its
 time information is, relative to the interpolator's time extent.
 
 A class break is represented by an @c AGSTimeClassBreak object. Each class break is associated with a maximum relative age, 
 a symbol size, and color.  The age specifies how old a feature could be to be applicable for the class break. 
 Thus, you can specify different symbol sizes and colors for features of different ages. 
 
 The interpolator determines the actual size and color for a feature by computing the feature's age and finding 
 a class break appropriate for that age. Age is computed by comparing the feature's time information with the ending 
 point of the map's time extent. When a feature's time information contains both a start time and an end time, 
 the start time is used is used for computing the age.
 
 
 @define{AGSRampInterpolator.h, ArcGIS}
 @since 1.8
 */
@interface AGSTimeClassBreaksAger : AGSSymbolInterpolator {
@private
	NSArray *_timeClassBreaks;
	AGSTimeIntervalUnits _units;
	AGSTimeExtent *_timeExtent;
	NSArray *_orderedDates;
	NSMutableDictionary *_datesAndBreaks;
}

/** The time class breaks. This is an array of @c AGSTimeClassBreak objects.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *timeClassBreaks;

/** The time interval units for which the age of the breaks are in.
 @since 1.8
 */
@property (nonatomic, readonly) AGSTimeIntervalUnits units;

/** The time extent for which the age of each break is relative to.
 @since 1.8
 */
@property (nonatomic, retain) AGSTimeExtent *timeExtent;

/** Initializes an AGSTimeClassBreaksAger with an array of timeClassBreaks and time internal units.
 @param timeClassBreaks The breaks associated with this ager.
 @param units The unit of the time interval for the associated breaks.
 @return An initialized AGSTimeClassBreaksAger.
 @since 1.8
 */
-(id)initWithTimeClassBreaks:(NSArray*)timeClassBreaks units:(AGSTimeIntervalUnits)units;

/** Initializes an autoreleased AGSTimeClassBreaksAger with an array of timeClassBreaks and time internal units.
 @param timeClassBreaks The breaks associated with this ager.
 @param units The unit of the time interval for the associated breaks.
 @return An initialized, autoreleased AGSTimeClassBreaksAger.
 @since 1.8
 */
+(AGSTimeClassBreaksAger*)timeClassBreaksAgerWithTimeClassBreaks:(NSArray*)timeClassBreaks units:(AGSTimeIntervalUnits)units;

/** Returns an interpolated symbol for the given feature based on the feature's age relative to the given time extent.
 @param graphic The feature whose age is to be considered
 @param origSymbol The symbol used as the starting point for interpolation
 @param timeExtent The time extent to which the feature's time information will be compared to
 @param valDate 
 @return <code>AGSSymbol</code> representing the interpolated symbol
 @since 1.8
 */
-(AGSSymbol*)interpolatedSymbolForGraphic:(AGSGraphic*)graphic
						   originalSymbol:(AGSSymbol*)origSymbol
							   timeExtent:(AGSTimeExtent*)timeExtent
								  date:(NSDate*)valDate;
@end


/** @brief An object that represents a time class break for the AGSTimeClassBreaksAger.
 
 An object that represents a time class break for the @c AGSTimeClassBreaksAger.
 
 @define{AGSTimeClassBreaksAger.h, ArcGIS}
 @since 1.8
 */
@interface AGSTimeClassBreak : NSObject {
@private
	UIColor *_color;
	double _maxRelativeAge;
	CGFloat _size;
}

/** The color of the symbol for this time break.
 @since 1.8
 */
@property (nonatomic, retain) UIColor *color;

/** The max relative age (relative to the ager's time extent) for this time break.
 @since 1.8
 */
@property (nonatomic) double maxRelativeAge;

/** The size of the symbol for this time break.
 @since 1.8
 */
@property (nonatomic) CGFloat size;

/** Initializes an AGSTimeClassBreak.
 @since 1.8
 */
-(id)initWithColor:(UIColor*)color size:(float)size  maxRelativeAge:(double)maxRelativeAge;

/** Initializes an AGSTimeClassBreak.
 @since 1.8
 */
-(id)initWithColor:(UIColor*)color maxRelativeAge:(double)maxRelativeAge;

/** Returns an autoreleased AGSTimeClassBreak.
 @since 1.8
 */
+(AGSTimeClassBreak*)timeClassBreakWithColor:(UIColor*)color size:(float)size maxRelativeAge:(double)maxRelativeAge;

/** Returns an autoreleased AGSTimeClassBreak.
 @since 1.8
 */
+(AGSTimeClassBreak*)timeClassBreakWithColor:(UIColor*)color maxRelativeAge:(double)maxRelativeAge;

@end