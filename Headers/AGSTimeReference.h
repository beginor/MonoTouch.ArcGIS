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

/** @file AGSTimeReference.h */

/** @brief Contains information about how the time was measured.
 
 Instances of this class represent time reference which contains information about 
 how the time was measured. Conceptually similar to a spatial reference, includes 
 information about daylight savings time in addition to the time zone. You can 
 use it to project a time object from one time zone to another. You can also 
 associate one of several predefined time zones with a given time object.
 
 @define{AGSTimeReference.h, ArcGIS}
 @since 1.0
 */
@interface AGSTimeReference : NSObject <AGSCoding>

/** Time zone information associated with the time reference.
 @since 1.0
 */
@property (nonatomic, copy) NSTimeZone *timeZone;

/** Determines whether or not the referenced time respects Daylight Savings Time.
 @since 1.0
 */
@property (nonatomic) BOOL respectsDaylightSaving;

@end
