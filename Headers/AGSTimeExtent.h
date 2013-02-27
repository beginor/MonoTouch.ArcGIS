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

/** @file AGSTimeExtent.h */

/** @brief An interface to hold a given time interval.
 
 Instances of this class represent a time extent. The time extent is a span of 
 time going from a start time to an end time and it is returned in the metadata
 for time-aware services and layers.
 
 @define{AGSTimeExtent.h, ArcGIS}
 @since 1.0
 */
@interface AGSTimeExtent : NSObject

/** The start date for the time extent.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSDate *start;

/** The end date for the time extent.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSDate *end;

/** Initialize an <code>%AGSTimeExtent</code> with a start and end date.
 @param start The beginning date of the time extent.
 @param end The end date of the time extent.
 @return A new time extent object.
 @since 1.0
 */
-(id)initWithStart:(NSDate*)start end:(NSDate*)end;

/** Determines whether or not two time extents are equal.
 @param timeExtent The time extent to compare the current extent with.
 @since 1.0
 */
-(BOOL)isEqualToTimeExtent:(AGSTimeExtent*)timeExtent;

/** Convenience method to offset a time extent by a period.
 @param offsetValue The amount to offset 
 @param units The units of the offset amount
 @return The offset time extent
 @since 1.8
 */
-(AGSTimeExtent*)timeExtentByOffset:(NSInteger)offsetValue units:(AGSTimeIntervalUnits)units;

/** Convenience method to determine the overlapping period of two time extents
 @since 1.8
 */
+(AGSTimeExtent*)intersectionOfTimeExtent:(AGSTimeExtent*)timeExtent1 andTimeExtent:(AGSTimeExtent*)timeExtent2;

/** Return an initialized, auto released, time extent with the specified starting and ending points
 @param start The starting point
 @param end The ending point
 @return @c AGSTimeExtent
 @since 1.8
 */
+(AGSTimeExtent*)timeExtentWithStart:(NSDate *)start end:(NSDate *)end;

/** Convenience method to get a new date by applying an offset to an existing date
 @param date The starting date 
 @param offsetValue Amount to offset starting date by
 @param units The units of the offset amount
 @return @c The offset date
 @since 1.8
 */
+(NSDate*)dateByOffsettingDate:(NSDate*)date offset:(NSInteger)offsetValue units:(AGSTimeIntervalUnits)units;

@end