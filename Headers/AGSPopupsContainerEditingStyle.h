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

/** @file AGSPopupsContainerEditingStyle.h */ //Required for Globals API doc

/** An enumeration that is used for defining the editing style of an AGSPopupsContainer.
 @since 2.0
 */
typedef enum {
	AGSPopupsContainerEditingStyleGeometryTool, /*!< Shows a toolbar with a button for attachments and a button for collecting the geometry */
	AGSPopupsContainerEditingStyleGeometryInline /*!< has a view to switch between attributes and attachments,
												  there is no button for the collecting the geometry, as this is assumed
												  the user has access to the map while the popup is up (think ipad), or
												  the user will not be collecting a geometry at all. */
} AGSPopupsContainerEditingStyle;
