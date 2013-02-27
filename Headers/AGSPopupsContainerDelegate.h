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

#import <UIKit/UIKit.h>

@protocol AGSPopupsContainer;

@class AGSPopup;

/** @file AGSPopupsContainerDelegate.h */ //Required for Globals API doc

/** @brief A delegate of @c AGSPopupsContainerViewController
 
  A protocol that must be adopted by any class wishing to be notified when @c AGSPopupsContainerViewController detects user interaction with popups or if a user tries to edit a popup. An instance of the class must then be set as the delegate of @c AGSPopupsContainerViewController.
 
 All methods of this protocol are optional.
 @since 2.0
 */
@protocol AGSPopupsContainerDelegate <NSObject>
@optional

/** Tells the delegate that a new mutable geometry is required for a graphic that currently has no geometry.
 Must return a mutable geometry.
 @param popupsContainer The popup view controller
 @param popup Popup for who's graphic we need a geometry for.
 @since 2.0
 */
-(AGSGeometry*)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsNewMutableGeometryForPopup:(AGSPopup*)popup;

/** Tells the delegate that a user is ready to edit the geometry for
 the current popup. This will happen when the user clicks the toolbar item for 
 editing the geometry. Or if the editing mode is "Geometry Inline", it will happen when
 editing begins.
 @param popupsContainer The popup view controller
 @param geometry If you are using an @c AGSSketchGraphicsLayer, this will be the same geometry that
 you give the AGSSketchGraphicsLayer.
 @param popup whose graphic's geometry needs to be edited
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer readyToEditGraphicGeometry:(AGSGeometry*)geometry forPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user begins editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose graphic needs to be edited
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didStartEditingGraphicForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user is done editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose graphic was edited
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didFinishEditingGraphicForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user cancels editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose graphic was started to be edited but later cancelled
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didCancelEditingGraphicForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user presses the delete button.
 The implementer of this method must actually delete the graphic.
 @param popupsContainer The popup view controller
 @param popup whose graphic needs to be deleted
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToDeleteGraphicForPopup:(AGSPopup*)popup;

/** The method that is called when the user is done viewing the popups.
 @param popupsContainer The popup view controller
 @since 2.0
 */
-(void)popupsContainerDidFinishViewingPopups:(id<AGSPopupsContainer>)popupsContainer;

/** The AGSPopupsContainer will call this method on the delegate when a view controller needs to be presented.
 This method is optional, but if you want to show view controllers in different ways than the standard modal way,
 then you need to implement this method.
 @param popupsContainer The popup view controller
 @param svc The view controller that needs to be displayed
 @param viewType The predefined type of the view controller
 @param fvc The view controller that is currently being displayed
 @param rect The rect is in the coordinate space of the fromViewController. Only applicable if viewType is @c AGSPopupViewTypeUIImagePicker
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToShowViewController:(UIViewController *)svc ofType:(AGSPopupViewType)viewType fromViewController:(UIViewController*)fvc atRect:(CGRect)rect;

/** The AGSPopupsContainer will call this method on the delegate when a view controller needs to be hidden.
 You need to implement this if you implement popupsContainer:wantsToShowViewController:fromViewController:atRect, 
 so that you can hide a view controller in the proper way if you've shown it in a custom manner.
 @param popupsContainer The popup view controller
 @param vc The view controller that needs to be hidden
 @param viewType the predefined type of the view controller  
 
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToHideViewController:(UIViewController*)vc ofType:(AGSPopupViewType)viewType;

/** The AGSPopupsContainer will call this delegate method when it one of it's view controllers
 needs to know if it can auto-rotate to an certain interface orientation. If you don't implement this
 method then we just always return YES.
 @param popupsContainer The popup view controller
 @param interfaceOrientation The orientation to change to
 @param vc The view controller that needs to respond to orientation change
 @param viewType the predefined type of the view controller  
 @since 2.0
 */
-(BOOL)popupsContainer:(id<AGSPopupsContainer>)popupsContainer shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation forViewController:(UIViewController*)vc ofType:(AGSPopupViewType)viewType;

/** The AGSPopupsContainer will call this method when the currently showing popup changes.
 @param popupsContainer The popup view controller
 @param popup which is currently being displayed
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didChangeToCurrentPopup:(AGSPopup*)popup;

/** The AGSPopupsContainer will call this method when there is a document that it wants to preview. 
 By default, if this method is not implemented, it will preview the document with a UIDocumentInteractionController. 
 If you have need to hide or show popovers before previewing you should implement this method and 
 create the UIDocumentInteractionController manually.
 @since 2.3
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToPreviewDocumentAtURL:(NSURL*)documentURL fromViewController:(UIViewController*)fvc atRect:(CGRect)rect;

/** The AGSPopupsContainer will call this when the user switches a feature type for the current popup.
 Potentially at this point symbology will change for the feature.
 @since 10.1.1
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didChangeFeatureTypeForPopup:(AGSPopup *)popup;
@end

