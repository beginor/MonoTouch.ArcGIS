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

/** @file AGSServiceAreaLayerInfo.h */

@protocol AGSCoding;
@class AGSNALayerInfoBase;

/** @brief Represents default parameters from the service area layer.
 
 Represents default parameter values for the service area layer of a network analyst
 service.
 
 @since 1.8
 */
@interface AGSServiceAreaLayerInfo : AGSNALayerInfoBase <AGSCoding> {
 @private
	NSArray *_defaultBreaks;
	NSArray *_excludeSourcesFromPolygons;
	BOOL _mergeSimilarPolygonRanges;
	AGSNAOutputLine _outputLines;
	AGSNAOutputPolygon _outputPolygons;
	BOOL _overlapLines;
	BOOL _overlapPolygons;
	BOOL _splitLinesAtBreaks;
	BOOL _splitPolygonsAtBreaks;
	BOOL _trimOuterPolygon;
	double _trimPolygonDistance;
	AGSUnits _trimPolygonDistanceUnits;
	BOOL _includeSourceInformationOnLines;
	AGSNATravelDirection _travelDirection;
}

/** The network layer's default array of numbers defining the breaks.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *defaultBreaks;

/** The network layer's default array of network source names to NOT use when
 generating polygons.
 @since 1.8
 */
@property (nonatomic, retain, readonly) NSArray *excludeSourcesFromPolygons;

/** If <code>true</code>, similar ranges will be merged in the result polygons.
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL mergeSimilarPolygonRanges;

/** The network layer's default type of output lines to be generated in the
 result.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSNAOutputLine outputLines;

/** The network layer's default type of output polygons to be generated in the
 result.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSNAOutputPolygon outputPolygons;

/** The network layer default indicating if the lines should overlap from multiple 
 facilities. 
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL overlapLines;

/** The network layer default indicating if the polygons should overlap from 
 multiple facilities. 
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL overlapPolygons;

/** If <code>true</code>, lines will be split at breaks.
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL splitLinesAtBreaks;

/** If <code>true</code>, the polygons will be split at breaks. 
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL splitPolygonsAtBreaks;

/** If <code>true</code>, the outermost polygon (at the maximum break value) will 
 be trimmed. 
 @since 1.8
 */
@property (nonatomic, assign, readonly) BOOL trimOuterPolygon;

/** If polygons are being trimmed, provides the distance to trim.
 @since 1.8
 */
@property (nonatomic, assign, readonly) double trimPolygonDistance;

/** If polygons are being trimmed, specifies the units of the #trimPolygonDistance.
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSUnits trimPolygonDistanceUnits;

// @todo - This shows up in json, but isn't doc'd
@property (nonatomic, assign, readonly) BOOL includeSourceInformationOnLines;

/** The network layer's default options for traveling to or from the facility. 
 @since 1.8
 */
@property (nonatomic, assign, readonly) AGSNATravelDirection travelDirection;

@end