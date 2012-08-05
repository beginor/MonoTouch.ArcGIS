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

#import "AGSJSON.h"
#import "AGSCoding.h"
#import "AGSCredential.h"
#import "AGSEnumerations.h"
#import "AGSTask.h"
#import "AGSSpatialReference.h"
#import "AGSGeometry.h"
#import "AGSLayer.h"
#import "AGSLayerView.h"
#import "AGSTiledLayer.h"
#import "AGSLOD.h"
#import "AGSTileInfo.h"
#import "AGSRenderer.h"
#import "AGSRunLoopOperation.h"
#import "AGSRequestOperation.h"
#import "AGSJSONRequestOperation.h"
#import "AGSImageRequestOperation.h"
#import "AGSSymbol.h"
#import "AGSEnvelope.h"
#import "AGSPoint.h"
#import "AGSMultipoint.h"
#import "AGSPolygon.h"
#import "AGSPolyline.h"
#import "AGSGeometryServiceTask.h"
#import "AGSGeoprocessor.h"
#import	"AGSGPS.h"
#import "AGSAttachmentInfo.h"
#import "AGSBingMapLayer.h"
#import "AGSCallout.h"
#import "AGSClassBreak.h"
#import "AGSClassBreaksRenderer.h"
#import "AGSCompositeSymbol.h"
#import "AGSDynamicLayer.h"
#import "AGSDynamicLayerView.h"
#import "AGSDynamicMapServiceLayer.h"
#import "AGSEditResult.h"
#import "AGSQueryTask.h"
#import "AGSInfoTemplateDelegate.h"
#import "AGSGraphicsLayer.h"
#import "AGSEditFieldsInfo.h"
#import "AGSFeatureLayer.h"
#import "AGSFeatureLayer+Editing.h"
#import "AGSFeatureSet.h"
#import "AGSFillSymbol.h"
#import "AGSSimpleFillSymbol.h"
#import "AGSFindTask.h"
#import "AGSGPResultLayer.h"
#import "AGSGeometryParameters.h"
#import "AGSGeometryServiceTask+AGSGeometryArray.h"
#import "AGSGeometryServiceTask+AreasAndLengths.h"
#import "AGSGeometryServiceTask.h"
#import "AGSGeometryEngine.h"
#import "AGSGraphic.h"
#import "AGSIdentifyTask.h"
#import "AGSImageParameters.h"
#import "AGSImageServiceInfo.h"
#import "AGSImageServiceLayer.h"
#import "AGSImageServiceIdentifyTask.h"
#import "AGSImageServiceIdentifyParameters.h"
#import "AGSImageServiceIdentifyResult.h"
#import "AGSLayerDefinition.h"
#import "AGSLayerDelegate.h"
#import "AGSSimpleLineSymbol.h"
#import "AGSCompositeLineSymbol.h"
#import "AGSLocator.h"
#import "AGSMapServiceInfo.h"
#import "AGSMapServiceLayerInfo.h"
#import "AGSMapView.h"
#import "AGSMarkerSymbol.h"
#import "AGSSimpleMarkerSymbol.h"
#import "AGSOpenStreetMapLayer.h"
#import "AGSPictureMarkerSymbol.h"
#import "AGSRequest.h"
#import "AGSSimpleRenderer.h"
#import "AGSTile.h"
#import "AGSTileOperation.h"
#import "AGSTileRequestOperation.h"
#import "AGSTiledLayerView.h"
#import "AGSTiledMapServiceLayer.h"
#import "AGSTime.h"
#import "AGSUniqueValue.h"
#import "AGSUniqueValueRenderer.h"
#import "AGSBase64.h"
#import "AGSFeatureLayerModelObjects.h"
#import "AGSJSONUtility.h"
#import "NSError+AGSAdditions.h"
#import "UIApplication+AGSAdditions.h"
#import "UIColor+AGSAdditions.h"
#import "UIDevice+AGSAdditions.h"
#import "AGSSketchGraphicsLayer.h"
#import "AGSLabelClass.h"
#import "AGSPictureFillSymbol.h"
#import "AGSTextSymbol.h"
#import "AGSMosaicRule.h"
#import "AGSRasterFunction.h"
#import "AGSTemporalRenderer.h"
#import "AGSSymbolInterpolator.h"
#import "AGSRampInterpolator.h"
#import "AGSTimeClassBreaksAger.h"
#import "AGSWebMap.h"
#import "AGSWebMapBookmark.h"
#import "AGSWebMapBaseMap.h"
#import "AGSPortal.h"
#import "AGSPortalInfo.h"
#import "AGSPortalItem.h"
#import "AGSPortalQueryParams.h"
#import "AGSPortalQueryResultSet.h"
#import "AGSPortalUser.h"
#import "AGSPortalGroup.h"
#import "AGSPortalFolder.h"
#import "AGSPortalItemComment.h"
#import "AGSWebMapLayerInfo.h"
#import "AGSWebMapSubLayerInfo.h"
#import "AGSWebMapFeatureCollection.h"
#import "AGSWebMapQuery.h"
#import "AGSWebMapQueryParameter.h"
#import "AGSNADirectionsString.h"
#import "AGSDirectionSet.h"
#import "AGSDirectionGraphic.h"
#import "AGSStopGraphic.h"
#import "AGSNALayerInfoBase.h"
#import "AGSRouteTaskParameters.h"
#import "AGSRouteLayerInfo.h"
#import "AGSRouteTask.h"
#import "AGSRouteTaskResult.h"
#import "AGSRouteResult.h"
#import "AGSNAMessage.h"
#import "AGSNALayerDefinition.h"
#import "AGSFacilityGraphic.h"
#import "AGSIncidentGraphic.h"
#import "AGSServiceAreaLayerInfo.h"
#import "AGSServiceAreaTaskParameters.h"
#import "AGSServiceAreaTask.h"
#import "AGSServiceAreaTaskResult.h"
#import "AGSClosestFacilityLayerInfo.h"
#import "AGSClosestFacilityTaskParameters.h"
#import "AGSClosestFacilityTask.h"
#import "AGSClosestFacilityResult.h"
#import "AGSClosestFacilityTaskResult.h"
#import "AGSMapServiceTableInfo.h"
#import "AGSLocalTiledLayer.h"
#import "AGSPopupInfo.h"
#import "AGSPopupMediaInfo.h"
#import "AGSPopupFieldInfo.h"
#import "AGSPopupViewType.h"
#import "AGSPopupsContainer.h"
#import "AGSPopupsContainerDelegate.h"
#import "AGSPopupsContainerStyle.h"
#import "AGSPopupsContainerEditingStyle.h"
#import "AGSPopupsContainerPagingStyle.h"
#import "AGSPopupsContainerViewController.h"
#import "AGSPopup.h"
#import "AGSAttachment.h"
#import "AGSAttachmentManager.h"
#import "NSURLConnection+AGSAdditions.h"
#import "AGSWMSLayer.h"
#import "AGSWMSLayerInfo.h"


/*******************************************************************/

/** @mainpage Introduction
 ArcGIS Runtime SDK for iOS provides an Objective-C API for developers that allows you to add mapping and GIS functionality to your 
 iPhone, iPod touch, and iPad applications. The API leverages functionality 
 provided by ArcGIS Server services through the REST interface. The API primarily 
 provides a map component and tasks. The map component displays map content from 
 layers or webmaps which in turn rely on backing Tiled or Dynamic map services. 
 You can also add Graphics on the map to display your own points or areas of 
 interest. Tasks provide functionality such as identifying features on a map, 
 querying features given some criteria, geocoding and reverse geocoding addresses, 
 running geoprocessing jobs, performing network analysis such as routing, etc.
 
 The API is distributed as a framework called ArcGIS. This framework is installed by default under <i> ${HOME}/Library/SDKs/ArcGIS</i>. Classes and 
 functions defined in this framework begin with the prefix AGS. This prefix acts 
 as a namespace and prevents naming conflicts with classes defined in your 
 application or other frameworks you use. 
 
 @section project Setting up your XCode project
 
 You need to use a minimum of 
 iOS 4 SDK to build your applications. Be sure to set your XCode project's 
 <b>Base SDK</b> setting accordingly. 
 
 The API depends upon the following iOS frameworks and libraries. These 
 need to be added to your XCode project as references -
 @li CoreGraphics.framework
 @li CoreLocation.framework
 @li CoreText.framework
 @li Foundation.framework
 @li QuartzCore.framework
 @li MediaPlayer.framework
 @li MobileCoreServices.framework
 @li Security.framework
 @li UIKit.framework
 @li libstdc++.dylib
 @li libz.dylib
 
 You need to set the project's <b>Frameworks Search Paths</b> setting to 
 include <i>${HOME}/Library/SDKs/ArcGIS</i> , and the <b>Other Linker Flags</b> setting to include the following entries: <i> -ObjC -all_load -framework ArcGIS </i>
 
 You must also add the <i>ArcGIS.bundle</i> file found under <i>${HOME}/Library/SDKs/ArcGIS/ArcGIS.framework/Versions/Current/Resources</i> to your project. This bundle file contains the resources (images, etc) used by the API.
 
 @section Third-party Third party libraries

 The ArcGIS library depends upon and already includes the following third party libraries -
 @li <a target="_blank" href="https://github.com/stig/json-framework/">json-framework</a>
 @li <a target="_blank" href="http://www.winimage.com/zLibDll/minizip.html">minizip</a>
 @li <a target="_blank" href="http://code.google.com/p/objective-zip/">objective-zip</a>
 @li <a target="_blank" href="http://code.google.com/p/core-plot/">core-plot</a>
 
 The functions/classes in these libaries have been renamed/namespaced to avoid conflicts with other versions of these libraries you may have in your project.
 */
