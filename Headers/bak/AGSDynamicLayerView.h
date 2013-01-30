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

#import <UIKit/UIKit.h>

@protocol AGSLayerView;
@protocol AGSLayerDelegate;
@protocol AGSExportMapImageDelegate;
@protocol AGSDynamicLayerDrawingOperation;


@class AGSDynamicLayer;
@class AGSEnvelope;
@class AGSMapView;

/** @file AGSDynamicLayerView.h */ //Required for Globals API doc

/** @brief A view to display maps from a dynamic map service.
 
 In a Model-View-Controller architecture, this object represents the View. When 
 corresponding Model objects, subclasses of @c AGSDynamicLayer, are added to the 
 map, this view object is used internally display maps from the dynamic map 
 service.
 
 This class extends @c UIImageView. You can change the transparency of the layer 
 by modifying the @p alpha property.
 
 @define{AGSDynamicLayerView.h, ArcGIS} 
 @since 1.0
 @see AGSDynamicMapServiceLayer

 */

@interface AGSDynamicLayerView : UIImageView <AGSLayerView, AGSExportMapImageDelegate> {
@private
    NSString *_name;
    AGSDynamicLayer *_agsLayer;
    AGSMapView *_mapView;
    NSError *_error;
	
	BOOL _drawDuringPanning;
	BOOL _drawDuringZooming;
	
	NSOperation<AGSDynamicLayerDrawingOperation> *_currentOperation;
}

/** Flag to determine whether or not drawing should occur while panning.
 @since 1.0
 */
@property (nonatomic, assign) BOOL drawDuringPanning;

/** Flag to determine whether or not drawing should occur while zooming.
 @since 1.0
 */
@property (nonatomic, assign) BOOL drawDuringZooming;

@end
