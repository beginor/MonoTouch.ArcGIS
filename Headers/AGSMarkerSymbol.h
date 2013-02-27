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

@class AGSSymbol;

/** @file AGSMarkerSymbol.h */ //Required for Globals API doc

/** @brief A base class for marker symbols. 
 
 Instances of this class represent marker symbols. Symbols describe how graphics 
 look on the map. Different symbols are used for graphics with different geometry 
 types.  Marker symbols are used to display those graphics which are based on 
 point or multipoint geometry.
 
 @define{AGSMarkerSymbol.h, ArcGIS}
 @since 1.0
 
 */
@interface AGSMarkerSymbol : AGSSymbol

/** The rotation angle (in degrees) of the marker. The marker is rotated in a counter-clockwise direction by the amount specified. 
 @since 1.0
 */
@property (nonatomic, assign) double angle;

/** The offset on the x-axis & y-axis in points, relative to the center of the marker. Default is 0.0
 The values specified are interpreted in a cartesian coordinate system.
 Thus, a value of -5,-5 will shift the marker left by 5 points on the x-axis and
 down by 5 points on the y-axis.
 
 This is useful when the marker needs to be offset to properly coincide with a 
 location on the map. 
 
 For example, consider an @c AGSPictureMarkerSymbol using the image of a pushpin.  
 By default, the center of the image will be used as the anchor to center the 
 image at the map location. However, if you wanted the needle of the pushpin to 
 end at the map location, you would need to specify the #offset
 to shift the image appropriately. 
 
 @since 1.0
 */
@property (nonatomic, assign) CGPoint offset;

/** The location where to show the callout's leader (for example, when a user taps on the symbol)
  By default, the leader is shown at the center of the symbol. The values specified here are interpreted in
 a cartesian coordinate system and in points (not pixels). Thus, a value of (-5,-5) will move the leaderPoint location left on the x-axis by 5 points and down on the y-axis by 5 points.
 @since 10.1.1
 */
@property (nonatomic, assign) CGPoint leaderPoint;

/** The size of the marker in points (not pixels).
 On retina devices, 1 point = 2 pixels. On non-retina, 1 point = 1 pixel.
 @since 10.1.1
 */
@property (nonatomic, assign) CGSize size;

@end
