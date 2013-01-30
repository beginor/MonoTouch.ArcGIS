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

@class AGSLayer;
@class AGSMapView;
@class AGSLayerViewRequestParams;
@protocol AGSLayerDelegate;

/** @file AGSLayerView.h */ //Required for Globals API doc

/** @brief A protocol to display layers on a map.

 This protocol must be adopted by all classes which wish to display map layers 
 for @c AGSMapView.
 
 @since 1.0
 @define{AGSLayerView.h, ArcGIS}
 @see AGSTiledLayerView
 @see AGSDynamicLayerView
 */
@protocol AGSLayerView <AGSLayerDelegate>

/** Name of the view.
 @since 1.0
 */
@property (nonatomic, copy) NSString *name;

/** Layer being represented.
 @since 1.0
 */
@property (nonatomic, retain) AGSLayer *agsLayer;

/** Map view this layer view is contained in.
 @since 1.0
 */
@property (nonatomic, assign) AGSMapView *mapView;

/** Latest error, if any. May be error returned by service or client.
 @since 1.0
 */
@property (nonatomic, retain, readonly) NSError *error;

/** Property to determine whether or not we should draw while the map is panning.
 @since 1.0
 */
@property (nonatomic, assign) BOOL drawDuringPanning;

/** Property to determine whether or not we should draw while the map is zooming.
 @since 1.0
 */
@property (nonatomic, assign) BOOL drawDuringZooming;

/** Method to clear the current layer view.
 @since 1.0
 */
-(void)clear;

@end

