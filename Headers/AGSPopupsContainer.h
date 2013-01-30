/*
 COPYRIGHT 2011 ESRI
 
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


@protocol AGSPopupsContainerDelegate;

@class AGSGeometry;
@class AGSPopup;

/** @file AGSPopupsContainer.h */ //Required for Globals API doc

/** @brief An abstraction for a container of popups
 
 A protocol that needs to be adopted by an object wishes to serve as an AGSPopupsContainer.
 
 @see @c AGSPopupsContainerViewController
 @since 2.0
 */
@protocol AGSPopupsContainer <NSObject>
@required

/** The delegate.
 @since 2.0
 */
@property (nonatomic, assign) id<AGSPopupsContainerDelegate> delegate;

/**
 Main data structure for supplying individual popupviewcontroller's
 their data
 @since 2.0
 */
@property (nonatomic, copy) NSArray *popups;

/** Whether the AGSPopupsContainer is in a process of editing.
 @since 2.0
 */
@property (nonatomic, assign, readonly) BOOL inEditingMode;

/** The style for the AGSPopupsContainer.
 @since 2.0
 */
@property (nonatomic, assign) AGSPopupsContainerStyle style;

/** The UIColor that is used along with the style AGSPopupsContainerStyleCustomColor.
 @since 2.0
 */
@property (nonatomic, strong) UIColor *styleColor;

/** When in edit mode and geometry editing is allowed, this property 
 returns a mutable geometry that you can edit and when editing is finished, it will 
 be set on the feature.
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSGeometry *currentEditingGeometry;

/** The current AGSPopup that is being viewed.
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSPopup *currentPopup;

/** The style that is used in the AGSPopupsContainer for editing.
 @since 2.0
 */
@property (nonatomic, assign) AGSPopupsContainerEditingStyle editingStyle;

/** You can replace the button that appears on the left side of the top bar of the 
 container view with a custom button through this property. This button is only used
 when not in editing mode.
 @since 2.1
 */
@property (nonatomic, strong, readwrite) UIBarButtonItem *doneButton;

/** You can replace the button that appears on the right side of the top bar of the 
 container view with a custom button through this property. This button is only used
 when not in editing mode.
 @since 2.1
 */
@property (nonatomic, strong, readwrite) UIBarButtonItem *actionButton;

/** The default action button that is shown.
 @since 2.1
 */
@property (nonatomic, strong, readonly) UIBarButtonItem *defaultActionButton;

/** The default done button that is shown.
 @since 2.1
 */
@property (nonatomic, strong, readonly) UIBarButtonItem *defaultDoneButton;

/** The UIViewController that should be used for presenting modal view controllers
 from within this AGSPopupsContainer. This is useful when using this view controller
 as a standalone object and when it's not part of a view controller hierarchy.
 @since 2.0
 */
@property (nonatomic, strong) UIViewController *modalPresenter;

/**
 Popups view controller should show additional popups as defined by input.
 @since 2.0
 */
-(void)showAdditionalPopups:(NSArray *)popupInfos;

/** Method to start editing the currently displayed popup.
 @since 2.0
 */
-(void)startEditingCurrentPopup;

/** Clears all the popups currently being shown. This is useful if you want to cache 
 a reference to the popups container so it doesn't have to reload from a NIB 
 everytime it is shown.
 @since 2.0
 */
-(void)clearAllPopups;

@end
