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

@class AGSSymbol;
@class AGSSimpleLineSymbol;

/** @file AGSFillSymbol.h */ //Required for Globals API doc

/** @brief A base class for fill symbols.
 
 @define{AGSFillSymbol.h, ArcGIS}
 @since 2.2
 */

@interface AGSFillSymbol : AGSSymbol

/** This outline of the symbol.
 @since 2.2
 */
@property (nonatomic, strong) AGSSimpleLineSymbol *outline;

@end
