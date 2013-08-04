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
 
 If you implement a subclass of this class, also check AGSLayer+Subclass.h for additional functionality available to or required by subclasses.
 */
@interface AGSDynamicLayer (ForSubclassEyesOnly)

/**
 Will be called by the framework when the layer needs to draw. Subclass needs to implement.
 */
-(void)requestImageWithWidth:(NSInteger)width
                      height:(NSInteger)height
                    envelope:(AGSEnvelope*)env
                  timeExtent:(AGSTimeExtent*)timeExtent;

/**
 To be called by the subclass after it draws. If the draw wasn't successful, it should pass nil data for the envelope that was requested.
 */
-(void)setImageData:(NSData*)data forEnvelope:(AGSEnvelope*)env;

/**
 Each dynamic layer has it's own operation queue with max of 1 concurrent operation. Subclasses can use this to make image requests.
 */
@property (nonatomic, strong, readonly) NSOperationQueue *queue;

/** Subclasses must set this property before the layer loads so that the AGSMapView can know if it can allow wrap-around support.
 */
@property (nonatomic, assign) BOOL wrapAroundSupported;

@end
