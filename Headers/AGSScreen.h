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

/** @file AGSScreen.h */ //Required for Globals API doc

/** @brief Provides information about the device screen
 
 Provides information about the device screen.
 
 @define{AGSScreen.h, ArcGIS}
 @since 
 */
@interface AGSScreen : NSObject

/** The scale of the main screen
 @since 2.1
 */
+(CGFloat)mainScreenScale;

/** The Points per inch of the main screen
 @since 2.1
 */
+(NSInteger)mainScreenPpi;

/** The Points per inch for the device if the screen scale was 1.0.
 */
+(NSInteger)basePpi;

@end
