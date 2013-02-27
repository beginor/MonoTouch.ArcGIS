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

/** @file AGSGPXLocationDisplayDataSource.h */ //Required for Globals API doc

@class AGSSimulatedLocationDisplayDataSource;

/** @brief Simulates location updates based on a GPX file
 
 Instances of this class represent a datasource that can simulate location updates from a GPX file. If a track exists, it will use the first track segment in the file. Else, if a route exists, it will use the full route.
 
 The init methods are synchronous, they will block the calling thread unil the file is 
 loaded and parsed. Therefore, you should initialize this datasource on a background thread
 to avoid locking up the main UI thread.
 
 @since 10.1.1
 @see AGSLocationDisplay
 */
@interface AGSGPXLocationDisplayDataSource : AGSSimulatedLocationDisplayDataSource

/** Initializes the datasource using a path to the GPX file (on the device).
 This method is synchronous, it will block the calling thread unil the file is 
 loaded and parsed. Therefore, you should call it on a background thread
 to avoid locking up the main UI thread.
 @param path to the GPX file on the device
 @since 10.1.1
 */
- (id)initWithPath:(NSString*)path;

/** Initialize the datasource using GPX data
 This method is synchronous, it will block the calling thread unil the data is parsed. Therefore, you should call it on a background thread
 to avoid locking up the main UI thread.
 @param gpxData Representation of data in a GPX file
 @since 10.1.1
 */
- (id)initWithGPXData:(NSData*)gpxData;

/** Initializes the datasource using a URL to the GPX file (on the web)
 This method is synchronous, it will block the calling thread unil the file is 
 loaded and parsed. Therefore, you should call it on a background thread
 to avoid locking up the main UI thread.
 @param gpxUrl URL to a GPX file on the web
 @since 10.1.1
 */
- (id)initWithURL:(NSURL*)gpxUrl;

@end
