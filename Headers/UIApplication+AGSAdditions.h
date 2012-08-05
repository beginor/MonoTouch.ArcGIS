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

/** @file UIApplication+AGSAdditions.h */ //Required for Globals API doc

/** @brief Helper category to show/hide the network activity indicator.
 
 This category provides a helper method to track whether or not the network 
 activity indicator should be shown or hidden. 
 
 @since 1.0
 */
@interface UIApplication (AGSAdditions)

/** Provides a cetralized way to show or hide the network activity indicator. It 
 contains logic to reconcile competing requests to control the indicator.
 
 Developers should use this method instead of 
 <code> [UIApplication sharedApplication].networkActivityIndicatorVisible </code> 
 to show/hide the indicator for any network calls they make in their application. 
 This will ensure that the indicator can keep track of, and properly reflects the 
 state of, any outstanding network call regardless of which component issued the 
 call.  
 @param show Flag to determine visibility of indicator: <code>YES</code> to show, 
 <code>NO</code> to hide.
 @since 1.0
 */
+(void)showNetworkActivityIndicator:(BOOL)show;

@end
