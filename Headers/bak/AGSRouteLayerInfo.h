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

/** @file AGSRouteLayerInfo.h */

@class AGSNALayerInfoBase;
@protocol AGSCoding;

/** @brief Represents default parameters from the route layer.
 
 Represents default parameter values for the route layer of a network analyst
 service.
 @since 1.8
 */
@interface AGSRouteLayerInfo : AGSNALayerInfoBase <AGSCoding> {
 @private
	NSString *_hierarchyAttributeName;
	NSUInteger _hierarchyLevelCount;
	NSArray *_hierarchyMaxValues;
	NSArray *_hierarchyNumTransitions;
	BOOL _findBestSequence;
	BOOL _useStartTime;
	NSDate *_startTime;
	BOOL _useTimeWindows;
	BOOL _preserveFirstStop;
	BOOL _preserveLastStop;
	AGSNAOutputLine _outputLineType;
	NSString *_directionsLanguage;
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

/** Indicates the network layer's default value for whether the order of the stops 
 in the route should be optimized while taking into account #preserveFirstStop 
 and #preserveLastStop, if they are <code>true</code>.
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL findBestSequence;

/** @todo Divesh
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL useStartTime;

/** The time the route begins.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSDate *startTime;

/** Indicates the network layer's default value for whether or not time windows 
 should be used in the analysis.
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL useTimeWindows;

/** Indicates the network layer's default value for whether the first stop is 
 fixed in the sequence even when #findBestSequence is <code>true</code>. Only 
 applicable if #findBestSequence is <code>true</code>.
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL preserveFirstStop;

/** Indicates the network layer's default value for whether the last stop is 
 fixed in the sequence even when #findBestSequence is <code>true</code>. Only 
 applicable if #findBestSequence is <code>true</code>.
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL preserveLastStop;

/** The network layer's default type of output lines to be generated in the result. 
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSNAOutputLine outputLineType;

/** The network layer's default language used when computing directions.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *directionsLanguage;

/** The network layer's default length units to use when computing directions.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSNAUnit directionsLengthUnits;

/** The network layer's default name of network attribute to use for the drive 
 time when computing directions. 
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *directionsTimeAttribute;

@end

