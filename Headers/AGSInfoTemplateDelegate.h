/*
 COPYRIGHT 2009 ESRI
 
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



@class AGSGraphic;
@class AGSPoint;

/** @file AGSInfoTemplateDelegate.h */ //Required for Globals API doc

/** @brief A template describing the contents of @c AGSCallout for a graphic.
 
 A protocol which must be adopted by any class wishing to display content for an 
 @c AGSGraphic in the callout window. An instance of the class must then be set as the 
 @p infoTemplateDelegate on the graphic.
 
 The methods are optional. If the custom view method is implemented and does not return nil,
 then the other methods will not be called. This is because if a custom view is displayed
 in the callout then it is the only content in the callout. 
 
 @define{AGSInfoTemplateDelegate.h, ArcGIS}
 @since 1.0
 @see AGSMapViewCalloutDelegate for events related to showing the callout.
 */
@protocol AGSInfoTemplateDelegate <NSObject>
@optional

/** Title text to be displayed in the callout.
 @param graphic The graphic to display a title for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @param mapPoint The coordinates at which the graphic callout will be displayed.
 @return The title text for the callout.
 @since 1.0
 */
- (NSString *)titleForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint;

/** Detail string to be displayed in the callout.
 @param graphic The graphic to display detail for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @param mapPoint The coordinates at which the graphic callout will be displayed.
 @return The detail text for the callout.
 @since 1.0
 */
- (NSString *)detailForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint;

/** Image to be displayed in the callout to the left of the text. The image will be scaled to
 40x40 points.
 @param graphic The graphic to display the image for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @param mapPoint The coordinates at which the graphic callout will be displayed.
 @return The image to be displayed in the callout.
 @since 1.8
 */
-(AGSImage*)imageForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint;

/** The custom view to be displayed in the callout. If you implement this function then the title, detail
 and image methods will not get called, as only the custom view will be displayed in the callout. The callout will be expanded
 to the dimensions of the custom view.
 @param graphic The graphic to display the custom view for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @param mapPoint The coordinates at which the graphic callout will be displayed.
 @return The custom view to be displayed in the callout.
 @since 1.8
 */
-(AGSView*)customViewForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint;

@end



