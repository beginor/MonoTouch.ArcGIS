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




#import <Foundation/Foundation.h> 
#import <CoreLocation/CoreLocation.h>
#import <QuartzCore/QuartzCore.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)
#import <AppKit/AppKit.h>
#else
#error Unsupported platform
#endif

#import "AGSDefines.h"
#import "AGSCoding.h"
#import "AGSEnumerations.h"
#import "AGSCredential.h"
#import "AGSCredentialCache.h"
#import "AGSImage.h"
#import "AGSColor.h"
#import "AGSView.h"

#import "AGSJSONUtility.h"
#import "NSDictionary+AGSAdditions.h"

#import "AGSRequest.h"
#import "AGSRunLoopOperation.h"
#import "AGSRequestOperation.h"
#import "AGSImageDataRequestOperation.h"
#import "AGSJSONRequestOperation.h"
#import "AGSImageRequestOperation.h"

#import "AGSSpatialReference.h"
#import "AGSGeometry.h"
#import "AGSEnvelope.h"
#import "AGSMultipoint.h"
#import "AGSPoint.h"
#import "AGSPolygon.h"
#import "AGSPolyline.h"
#import "AGSGeometryEngine.h"
#import "AGSProximityResult.h"

#import "AGSLayer.h"
#import "AGSLayer+Subclass.h"

#import "AGSTileInfo.h"
#import "AGSTileKey.h"
#import "AGSTiledLayer.h"
#import "AGSTiledLayer+Subclass.h"
#import "AGSTiledServiceLayer.h"
#import "AGSTiledServiceLayer+Subclass.h"
#import "AGSTiledMapServiceLayer.h"
#import "AGSOpenStreetMapLayer.h"

#import "AGSDynamicLayer.h"
#import "AGSDynamicLayer+Subclass.h"
#import "AGSDynamicMapServiceLayer.h"

#import "AGSLayerDefinition.h"
#import "AGSLayerDelegate.h"
#import "AGSMapServiceInfo.h"
#import "AGSLayerInfo.h"
#import "AGSLocalTiledSubLayerInfo.h"
#import "AGSMapServiceLayerInfo.h"
#import "AGSMapServiceTableInfo.h"
#import "AGSTask.h"
#import "AGSGeoprocessor.h"
#import "AGSImageParameters.h"
#import "AGSGPJobInfo.h"
#import "AGSGPRasterData.h"
#import "AGSGPLinearUnit.h"
#import "AGSGPMessage.h"
#import "AGSGPParameterValue.h"
#import "AGSGPResultLayer.h"

#import "AGSNADirectionsString.h"
#import "AGSNALayerInfoBase.h"
#import "AGSNAMessage.h"
#import "AGSNALayerDefinition.h"
#import "AGSDirectionSet.h"
#import "AGSRouteTaskParameters.h"
#import "AGSRouteTask.h"
#import "AGSRouteTaskResult.h"
#import "AGSRouteResult.h"

#import "AGSServiceAreaTaskParameters.h"
#import "AGSServiceAreaTask.h"
#import "AGSServiceAreaTaskResult.h"

#import "AGSClosestFacilityResult.h"
#import "AGSClosestFacilityTaskParameters.h"
#import "AGSClosestFacilityTask.h"
#import "AGSClosestFacilityTaskResult.h"

#import "AGSMosaicRule.h"
#import "AGSImageServiceIdentifyTask.h"
#import "AGSImageServiceIdentifyResult.h"
#import "AGSImageServiceIdentifyParameters.h"

#import "AGSImageServiceInfo.h"
#import "AGSImageServiceLayer.h"
#import "AGSRasterFunction.h"
#import "AGSWMSLayer.h"
#import "AGSWMSLayerInfo.h" 
#import "AGSBingMapLayer.h"
#import "AGSBingMapLayerMetadata.h"
#import "AGSLocalTiledLayer.h"
#import "AGSLOD.h"

#import "AGSLayerTimeOptions.h"
#import "AGSTimeExtent.h"
#import "AGSTimeInfo.h"
#import "AGSTimeReference.h"
#import "AGSMapViewBase_iOS.h"
#import "AGSMapView.h"
#import "AGSDomain.h"
#import "AGSCodedValue.h"
#import "AGSCodedValueDomain.h"
#import "AGSFeatureSet.h"
#import "AGSField.h"
#import "AGSGraphic.h"
#import "AGSDirectionGraphic.h"
#import "AGSStopGraphic.h"
#import "AGSFacilityGraphic.h"
#import "AGSIncidentGraphic.h"
#import "AGSInfoTemplateDelegate.h"
#import "AGSCallout.h"
#import "AGSCalloutTemplate.h"
#import "AGSRangeDomain.h"

#import "AGSAddressCandidate.h"
#import "AGSFindParameters.h"
#import "AGSFindResult.h"
#import "AGSFindTask.h"
#import "AGSIdentifyParameters.h"
#import "AGSIdentifyResult.h"
#import "AGSIdentifyTask.h"
#import "AGSLocator.h"
#import "AGSLocationsForAddressParameters.h"
#import "AGSLocatorFindParameters.h"
#import "AGSLocatorFindResult.h"
#import "AGSQuery.h"
#import "AGSQueryTask.h"
#import "AGSRelationshipQuery.h"
#import "AGSOutStatistic.h"

#import "AGSAreasAndLengthsParameters.h"
#import "AGSBufferParameters.h"
#import "AGSDensifyParameters.h"
#import "AGSDistanceParameters.h"
#import "AGSGeneralizeParameters.h"
#import "AGSGeometryRelationship.h"
#import "AGSGeometryServiceTask.h"
#import "AGSGeometryServiceTask+AGSGeometryArray.h"
#import "AGSGeometryServiceTask+AreasAndLengths.h"
#import "AGSLengthsParameters.h"
#import "AGSOffsetParameters.h"
#import "AGSRelationParameters.h"
#import "AGSTrimExtendParameters.h"
#import "AGSApplication+AGSAdditions.h"
#import "AGSBase64.h"
#import "AGSDevice.h"

#import "AGSScreen.h"

#import "NSError+AGSAdditions.h"
#import "NSURL+AGSAdditions.h"
#import "NSURLConnection+AGSAdditions.h"

//
// sbjson includes
#import "AGSSBJson.h"
#import "AGSSBJsonParser.h"
#import "AGSSBJsonWriter.h"
#import "AGSSBJsonStreamParser.h"
#import "AGSSBJsonStreamParserAdapter.h"
#import "AGSSBJsonStreamWriter.h"
#import "NSObject+AGSSBJson.h"

#import "AGSSymbol.h"
#import "AGSGraphicsLayer.h"
#import "AGSRenderer.h"
#import "AGSSimpleRenderer.h"
#import "AGSFillSymbol.h"
#import "AGSPictureFillSymbol.h"
#import "AGSMarkerSymbol.h"
#import "AGSSimpleFillSymbol.h"
#import "AGSSimpleLineSymbol.h"
#import "AGSSimpleMarkerSymbol.h"
#import "AGSPictureMarkerSymbol.h"
#import "AGSCompositeSymbol.h"
#import "AGSTextSymbol.h"
#import "AGSUniqueValue.h"
#import "AGSUniqueValueRenderer.h"
#import "AGSClassBreak.h"
#import "AGSClassBreaksRenderer.h"


#import "AGSEditResult.h"
#import "AGSEditResultError.h"
#import "AGSEditFieldsInfo.h"
#import "AGSFeatureLayer.h"
#import "AGSFeatureLayer+Editing.h"
#import "AGSFeatureLayerEditResults.h"
#import "AGSFeatureLayerAttachmentResults.h"
#import "AGSAttachment.h"
#import "AGSAttachmentManager.h"
#import "AGSAttachmentInfo.h"
#import "AGSFeatureTemplate.h"
#import "AGSFeatureType.h"
#import "AGSLabelClass.h"
#import "AGSRelationship.h"

#import "AGSSketchGraphicsLayer.h"

#import "AGSPortal.h"
#import "AGSPortalFolder.h"
#import "AGSPortalGroup.h"
#import "AGSPortalInfo.h"
#import "AGSPortalItem.h"
#import "AGSPortalItemComment.h"
#import "AGSPortalQueryParams.h"
#import "AGSPortalQueryResultSet.h"
#import "AGSPortalUser.h"

#import "AGSWebMap.h"
#import "AGSWebMapBaseMap.h"
#import "AGSWebMapBookmark.h"
#import "AGSWebMapFeatureCollection.h"
#import "AGSWebMapLayerInfo.h"
#import "AGSWebMapQuery.h"
#import "AGSWebMapQueryParameter.h"
#import "AGSWebMapSubLayerInfo.h"

#import "AGSPopup.h"
#import "AGSPopupFieldInfo.h"
#import "AGSPopupInfo.h"
#import "AGSPopupMediaInfo.h"

#if TARGET_OS_IPHONE
#import "AGSPopupViewType.h"
#import "AGSPopupsContainer.h"
#import "AGSPopupsContainerDelegate.h"
#import "AGSPopupsContainerViewController.h"
#endif

#import "AGSLocationDisplayDataSourceDelegate.h"
#import "AGSLocationDisplayDataSource.h"
#import "AGSLocationDisplay.h"
#import "AGSLocation.h"
#import "AGSSimulatedLocationDisplayDataSource.h"
#import "AGSGPXLocationDisplayDataSource.h"
#import "AGSCLLocationManagerLocationDisplayDataSource.h"

#import "AGSWMTSLayer.h"
#import "AGSWMTSLayerInfo.h"
#import "AGSWMTSInfo.h"
#import "AGSWMTSStyle.h"

#import "AGSGroupLayer.h"
#import "AGSMPDictionaryRenderer.h"
#import "AGSMPMessageProcessor.h"
#import "AGSMPMessage.h"
#import "AGSMPMessageHelper.h"
#import "AGSMPSymbolDictionary.h"
#import "AGSMPSymbolDictionaryQuery.h"
#import "AGSMPSymbolDictionaryFilter.h"



/*******************************************************************/

/** @mainpage Introduction
 ArcGIS Runtime SDK for iOS provides an Objective-C API for developers that allows you to add mapping and GIS functionality to your 
 iPhone, iPod touch, and iPad applications. 
 
 The API leverages functionality
 provided by ArcGIS Online and ArcGIS Server services through the REST interface. The API 
 provides a map component, layers, and tasks. The map component displays map content from 
 layers or webmaps which in turn rely on backing map services from ArcGIS Server or other geospatial 
 technology such as Bing, OpenStreetmap, WMS, and so on.
 You can also add Graphics on the map to display your own points or areas of 
 interest. Tasks provide functionality such as identifying features on a map, 
 querying features given some criteria, finding addresses, 
 running geoprocessing jobs, performing network analysis such as routing, etc.
 
 The API is distributed as a framework called ArcGIS. This framework is installed by default under <i> ${HOME}/Library/SDKs/ArcGIS/iOS</i>. Classes and 
 functions defined in this framework begin with the prefix AGS. This prefix acts 
 as a namespace and prevents naming conflicts with classes defined in your 
 application or other frameworks you use. 
 
 @section project Setting up your XCode project
 
 You need to use a minimum of 
 iOS 5 SDK to build your applications. Be sure to set your XCode project's 
 <b>Base SDK</b> setting accordingly. 
 
 Also, the applications you build will require a minimum of iOS 5 running on the device.
 
 The API depends upon the following iOS frameworks and libraries. These 
 need to be added to your XCode project as references -
 @li CoreGraphics.framework
 @li CoreLocation.framework
 @li CoreText.framework
 @li Foundation.framework
 @li QuartzCore.framework
 @li MediaPlayer.framework
 @li MobileCoreServices.framework
 @li OpenGLES.framework
 @li Security.framework
 @li UIKit.framework
 @li libc++.dylib
 @li libz.dylib
 
 You need to set the project's <b>Frameworks Search Paths</b> setting to 
 include <i>${HOME}/Library/SDKs/ArcGIS</i> , and the <b>Other Linker Flags</b> setting to include the following entries: <i> -ObjC -all_load -framework ArcGIS </i>
 
 Finally, you must also add the <i>ArcGIS.bundle</i> file found under <i>${HOME}/Library/SDKs/ArcGIS/iOS/ArcGIS.framework/Versions/Current/Resources</i> to your project. This bundle file contains the resources (images, localized strings, etc) used by the API.
 
 @section Third-party Third party libraries
 
 The ArcGIS library depends upon and already includes the following third party libraries -
 @li <a target="_blank" href="https://github.com/stig/json-framework/">json-framework</a>
 @li <a target="_blank" href="http://www.winimage.com/zLibDll/minizip.html">minizip</a>
 @li <a target="_blank" href="http://code.google.com/p/objective-zip/">objective-zip</a>
 @li <a target="_blank" href="http://code.google.com/p/core-plot/">core-plot</a>
 
 The functions/classes in these libaries have been renamed/namespaced to avoid conflicts with other versions of the same libraries you may have in your project.
 */






