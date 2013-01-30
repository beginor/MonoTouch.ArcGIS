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

/** @file AGSClosestFacilityLayerInfo.h */

@class AGSNALayerInfoBase;
@protocol AGSCoding;

/** @brief Represents default parameters from the closest facility layer.
 
 Represents default parameter values for the closest facility layer of a network analyst
 service.
 
 @since 1.8
 */
@interface AGSClosestFacilityLayerInfo : AGSNALayerInfoBase <AGSCoding> {
 @private
	NSString *_hierarchyAttributeName;
	NSUInteger _hierarchyLevelCount;
	NSArray *_hierarchyMaxValues;
	NSArray *_hierarchyNumTransitions;
	double _defaultCutoffValue;
	NSUInteger _facilityCount;
	AGSNATravelDirection _travelDirection;
	AGSNAOutputLine _outputLineType;
	NSString *_directionsLanguage;
	NSString *_directionsStyleName;
	AGSNAUnit _directionsLengthUnits;
	NSString *_directionsTimeAttribute;	
}

/** @todo Divesh
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *hierarchyAttributeName;

/** @todo Divesh
 @since 1.8
 */
@property (nonatomic, assign, readonly) NSUInteger hierarchyLevelCount;

/** @todo Divesh
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *hierarchyMaxValues;

/** @todo Divesh
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *hierarchyNumTransitions;

/** The cutoff value used to determine when to stop traversing.
 @since 1.8
 */
@property (nonatomic, assign, readonly) double defaultCutoffValue;

/** The number of facilities to find.
 @since 1.8
 */
@property (nonatomic, assign, readonly) NSUInteger facilityCount;

/** Options for traveling to or from the facility.
 @see @c AGSNATravelDirection for a list of valid values.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSNATravelDirection travelDirection;

/** The type of output lines generated in the result.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSNAOutputLine outputLineType;

/** The default language used when computing directions.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *directionsLanguage;

/** @todo Divesh
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *directionsStyleName;

/** The network layer's default length units used when computing directions. 
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSNAUnit directionsLengthUnits;

/** The network layer's default name of the attribute field that contains the 
 drive time values. 
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *directionsTimeAttribute;

@end