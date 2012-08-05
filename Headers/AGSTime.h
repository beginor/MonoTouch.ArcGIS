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

@protocol AGSCoding;

/** @file AGSTime.h */ //Required for Globals API doc

/** Supported time interval units.
 @since 1.0
 */
typedef enum {
    AGSTimeIntervalUnitsCenturies = 0,	/*!< */
    AGSTimeIntervalUnitsDays,		/*!< */
    AGSTimeIntervalUnitsDecades,			/*!< */
    AGSTimeIntervalUnitsHours,				/*!< */
    AGSTimeIntervalUnitsMilliseconds,				/*!< */	
    AGSTimeIntervalUnitsMinutes,			/*!< */	
    AGSTimeIntervalUnitsMonths,				/*!< */
    AGSTimeIntervalUnitsSeconds,				/*!< */
    AGSTimeIntervalUnitsUnknown,		/*!< */	
    AGSTimeIntervalUnitsWeeks,		/*!< */	
    AGSTimeIntervalUnitsYears
} AGSTimeIntervalUnits;

#pragma mark -

/** @brief An interface to hold a given time interval.
 
 Instances of this class represent a time extent. The time extent is a span of 
 time going from a start time to an end time and it is returned in the metadata
 for time-aware services and layers.
 
 @define{AGSTime.h, ArcGIS}
 @since 1.0
 */
@interface AGSTimeExtent : NSObject {
 @private
    NSDate *_start;
    NSDate *_end;
}

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



#pragma mark -

/** @brief Contains information about how the time was measured.
 
 Instances of this class represent time reference which contains information about 
 how the time was measured. Conceptually similar to a spatial reference, includes 
 information about daylight savings time in addition to the time zone. You can 
 use it to project a time object from one time zone to another. You can also 
 associate one of several predefined time zones with a given time object.
 
 @define{AGSTime.h, ArcGIS}
 @since 1.0
 */
@interface AGSTimeReference : NSObject <AGSCoding> {
 @private
    NSTimeZone *_timeZone;
    BOOL _respectsDaylightSaving;
}

/** Time zone information associated with the time reference.
 @since 1.0
 */
@property (nonatomic, copy) NSTimeZone *timeZone;

/** Determines whether or not the referenced time respects Daylight Savings Time.
 @since 1.0
 */
@property (nonatomic) BOOL respectsDaylightSaving;

@end



#pragma mark -

/** @brief Time information details.
 
 Instances of this class represent time information of a layer. It contains various time related
 info for dealing with time-aware layers.
 
 @define{AGSTime.h, ArcGIS}
 @since 1.0
 */
@interface AGSTimeInfo : NSObject <AGSCoding> {
 @private
    NSString *_startTimeField;
	NSString *_endTimeField;
	NSString *_trackIdField;
	AGSTimeExtent *_timeExtent;
	AGSTimeReference *_timeReference;
	double _timeInterval;
	AGSTimeIntervalUnits _timeIntervalUnits;
}

/** The name of the attribute field that contains the start time information.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *startTimeField;

/** The name of the attribute field that contains the end time information.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *endTimeField;

/** The field that contains the trackId.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *trackIdField;

/** The time extent for all the data in the layer.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSTimeExtent *timeExtent;

/** Information about how the time was referenced.
 @since 1.0
 */
@property (nonatomic, retain, readonly) AGSTimeReference *timeReference;

/** Time interval of the data in the layer.
 @since 1.0
 */
@property (nonatomic, assign, readonly) double timeInterval;

/** Temporal unit in which the time interval is measured. Possible values 
 include
  
 @li @c AGSTimeIntervalUnitsCenturies
 @li @c AGSTimeIntervalUnitsDays
 @li @c AGSTimeIntervalUnitsDecades
 @li @c AGSTimeIntervalUnitsHours
 @li @c AGSTimeIntervalUnitsMilliseconds	
 @li @c AGSTimeIntervalUnitsMinutes	
 @li @c AGSTimeIntervalUnitsMonths
 @li @c AGSTimeIntervalUnitsSeconds
 @li @c AGSTimeIntervalUnitsUnknown	
 @li @c AGSTimeIntervalUnitsWeeks
 @li @c AGSTimeIntervalUnitsYears
 
 @since 1.0
 */
@property (nonatomic, assign, readonly) AGSTimeIntervalUnits timeIntervalUnits;

@end

/*
 "<layerId1>" : {
 //If true, use the time extent specified by the time parameter
 "useTime" : < true | false >,
 //If true, draw all the features from the beginning of time for that data
 "timeDataCumulative" : < true | false >,
 //Time offset for this layer so that it can be overlaid on the top of a previous or future time period
 "timeOffset" : <timeOffset1>,
 "timeOffsetUnits" : "<esriTimeUnitsCenturies | esriTimeUnitsDays | esriTimeUnitsDecades | 
 esriTimeUnitsHours | esriTimeUnitsMilliseconds | esriTimeUnitsMinutes | 
 esriTimeUnitsMonths | esriTimeUnitsSeconds | esriTimeUnitsWeeks | esriTimeUnitsYears |
 esriTimeUnitsUnknown>"
}*/

/** @brief Options pertaining to time-aware layers
 
 Instances of this class represent options for time-aware layers.
 
 @define{AGSTime.h, ArcGIS}
 @since 1.8
 */
@interface AGSLayerTimeOptions : NSObject <AGSCoding>
{
@private
	BOOL _useTime;
	BOOL _timeDataCumulative;
	double _timeOffset;
	AGSTimeIntervalUnits _timeOffsetUnits;
	NSUInteger _layerId;
}

/** Specifies whether the layer should be time aware. If a layer is time aware,
 it honours the map's time extent and only displays features that belong to
 that time period/instant.
 @since 1.8
 */
@property (nonatomic) BOOL useTime;

/** Specifies whether the layer should treat the map's time extent cumulatively. 
If true, the layer will draw all features from the beginning of the data's time extent.
 @since 1.8
 */
@property (nonatomic) BOOL timeDataCumulative;

/** Specifies an offset that will be applied to the time information
 of all features in the layer. The offset it applied on-the-fly, it does not
 change the actual data of the layer.
 @since 1.8
 */
@property (nonatomic) double timeOffset;

/** Specifies the units of @c #timeOffset
 @since 1.8
 */
@property (nonatomic) AGSTimeIntervalUnits timeOffsetUnits;

/** The ID of the layer 
 @since 1.8
 */
@property (nonatomic) NSUInteger layerId;

@end

