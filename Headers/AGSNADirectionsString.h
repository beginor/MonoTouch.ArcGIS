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

@protocol AGSCoding;

/** @file AGSNADirectionsString.h */ //Required for Globals API doc

/** @brief A direction maneuver
 
 Instances of this class represent individual direction maneuvers.
 
 @define{AGSNADirectionsString.h, ArcGIS}
 @avail{10.1}
 @since 2.3
 */
@interface AGSNADirectionsString : NSObject<AGSCoding>

/** The maneuver in text representation
 @avail{10.1}
 @since 2.3
 */
@property (nonatomic, copy, readonly) NSString *value;

/** The type of maneuver
 @since 2.3
 @avail{10.1}
 */
@property (nonatomic, assign, readonly) AGSNADirectionsStringType type;

@end
