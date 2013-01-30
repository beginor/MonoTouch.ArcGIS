/*
 COPYRIGHT 2010 ESRI
 
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

/** @file UIScreen+AGSAdditions.h */ //Required for Globals API doc

/** @brief A category to assist with screen properties
 
 A category to assist with screen properties
 @since 2.1
 */
@interface UIScreen(AGSAdditions)

/** The scale of the main screen
 @since 2.1
 */
+(CGFloat)mainScreenScale;

/** The Points per inch of the main screen
 @since 2.1
 */
+(int)mainScreenPpi;

@end




