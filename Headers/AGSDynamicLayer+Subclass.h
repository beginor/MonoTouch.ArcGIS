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

@class AGSLayer;
@class AGSDynamicLayer;
@class AGSEnvelope;
@class AGSTimeExtent;

/** @file AGSDynamicLayer+Subclass.h */ //Required for Globals API doc

/** @brief Information relevant to sublcasses of @c AGSDynamicLayer
 
 This category organizes the  methods that are relevant to subclassing a dynamic layer.
 Developer can create custom dynamic layers by paying special attention to the methods in this category when subclassing @c AGSDynamicLayer.
 
 Sub-classes must provide valid values for @c AGSLayer#spatialReference, @c AGSLayer#fullEnvelope, and
 @c AGSLayer#initialEnvelope properties. Other properties on @c AGSLayer are optional.


 @since 10.1.1
 @see AGSLayer(ForSubclassEyesOnly)
*/
@interface AGSDynamicLayer (ForSubclassEyesOnly)

/**
 This must be implemented by subclasses to retrieve a map image.
 Will be called by the framework when the layer needs to draw. 
 @since 10.1.1
 */
-(void)requestImageWithWidth:(NSInteger)width
                      height:(NSInteger)height
                    envelope:(AGSEnvelope*)env
                  timeExtent:(AGSTimeExtent*)timeExtent;

/** Subclasses should call this when they have the data for a previously requested image.
 If subclasses failed to fetch an image or encountered some other error, they should pass nil. The implementation for this method is provided by the framework.
 @since 10.1.1
 */
-(void)setImageData:(NSData*)data forEnvelope:(AGSEnvelope*)env;

/**
 Each dynamic layer has it's own operation queue with max of 1 concurrent operation. Subclasses can use this to make image requests.
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) NSOperationQueue *queue;

/** Subclasses must set this property before the layer loads so that the AGSMapView can know if it can allow wrap-around support.
 @since 10.1.1
 */
@property (nonatomic, assign) BOOL wrapAroundSupported;

@end
