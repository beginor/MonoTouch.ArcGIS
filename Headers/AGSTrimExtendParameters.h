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

@class AGSPolyline;

/** @file AGSTrimExtendParameters.h */ //Required for Globals API doc

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>trimExtendWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>trimExtendWithParameters:</code> operation. 
 
 @define{AGSTrimExtendParameters.h, ArcGIS}
 @since 1.0
 @see AGSGeometryServiceTask
 */
@interface AGSTrimExtendParameters : NSObject <AGSCoding>

/** An array of polylines to be trimmed or extended.
 @since 1.0
 */
@property (nonatomic, copy) NSArray *polylines;

/** A polyline which is used as a guide for trimming / extending input polylines.
 @since 1.0
 */
@property (nonatomic, strong) AGSPolyline *trimExtendTo;

/** An optional flag with the following possible values:
 
 @li 0 - By default, extension considers both ends of paths. The old ends remain 
 and new points are added to the extended ends. The new points have attributes 
 that are extrapolated from adjacent existing segments. 
 @li 1 - If an extension is performed at an end, relocate the end point to the 
 new position instead of leaving the old point and adding a new point at the new 
 position.
 @li 2 - If an extension is performed at an end, do not extrapolate the 
 end-segment's attributes for the new point. Instead, make its attributes the 
 same as the current end. Incompatible with esriNoAttributes.
 @li 4 - If an extension is performed at an end, do not extrapolate the 
 end-segment's attributes for the new point. Instead, make its attributes be 
 empty. Incompatible with esriKeepAttributes.
 @li 8 - Do not extend the 'from' end of any path.
 @li 16 - Do not extend the 'to' end of any path.
 
 @since 1.0
 */
@property (nonatomic, assign) NSUInteger extendHow;

/** Returns an autoreleased instance of the <code>%AGSTrimExtendParameters</code> object.
 @since 1.0
 */
+ (id)trimExtendParameters;

@end