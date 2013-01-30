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

/** @file AGSApplication+AGSAdditions.h */ //Required for Globals API doc

#if TARGET_OS_IPHONE
/** AGSApplication is defined as UIApplication on iOS platform.
 @since 10.1.1
 */
#define AGSApplication UIApplication
#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)
#define AGSApplication NSApplication
#endif

@protocol AGSNetworkActivityDelegate;

/** @brief A category on UIApplication containing convenience methods.
 
 This category provides a helper method to track whether or not the network 
 activity indicator should be shown or hidden. On iOS platforms, the category
 is based on UIApplication. On Mac OS, it is based on NSApplication.
 
 @since 10.1.1
 */
@interface AGSApplication (AGSAdditions)

/** The delegate that needs to be informed when the activity indicator's status is changed.
 @since 10.1.1
 */
+ (void)ags_setNetworkActivityDelegate:(id<AGSNetworkActivityDelegate>)delegate;

/** Provides a cetralized way to show or hide the network activity indicator. It 
 contains logic to reconcile competing requests to control the indicator.
 
 Developers should use this method
 to show/hide the indicator for any network calls they make in their application. 
 This will ensure that the indicator can keep track of, and properly reflects the 
 state of, any outstanding network call regardless of which component issued the 
 call, be it a component in their appliation or in the SDK.  
 @param show Flag to determine visibility of indicator: <code>YES</code> to show, 
 <code>NO</code> to hide.
 @since 10.1.1
 */
+(void)ags_showNetworkActivityIndicator:(BOOL)show;

@end

/** @brief A delegate that is informed about changes in the network activity indicator
 
 Instances of this class are informed when
 the network activiity indicator is started or stopped.
 @see AGSApplication (AGSAdditions)
 @since 10.1.1
 */
@protocol AGSNetworkActivityDelegate <NSObject>
@required
/** Indicates that the network activity indicator started.
 @since 10.1.1
 */
- (void)networkActivityInProgress;
/** Indicates that the network activity indicator ended.
 @since 10.1.1
 */
- (void)networkActivityEnded;

@end