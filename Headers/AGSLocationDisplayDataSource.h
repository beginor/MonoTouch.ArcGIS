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

@protocol AGSLocationDisplayDataSourceDelegate;

/** @file AGSLocationDisplayDataSource.h */ //Required for Globals API doc

/** @brief An abstract source of location updates
 
 @define{AGSLocationDisplayDataSource.h, ArcGIS}
 @since 10.1.1
 */

@protocol AGSLocationDisplayDataSource <NSObject>
/**
 The delegate is typically an AGSLocationDisplay. The framework will set this.
 You should not set this.
 @since 10.1.1
 */
@property (nonatomic, weak) id<AGSLocationDisplayDataSourceDelegate> delegate;

/**
 Starts the datasource. The framework will call this when you invoke @c AGSLocationDisplay::startDataSource. You should not call this directly.
 */
-(void)start;

/**
 Stops the datasource. The framework will call this when you invoke @c AGSLocationDisplay::stopDataSource. You should not call this directly.
 */
-(void)stop;

/** Indicates whether or not the datasource is started.
 @since 10.1.1
 */
@property (nonatomic, readonly, getter = isStarted) BOOL started;

/** Indicates any error that may have occurred on the datasource.
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) NSError *error;

@end
