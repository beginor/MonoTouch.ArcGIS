# MonoTouch.ArcGIS

[ArcGIS Runtime SDK for iOS][1] v10.1.1 binding to MonoTouch.

## Support Features

This project is very early state， only support a few features following:

- AGSTiledMapServiceLayer
- AGSDynamicMapServiceLayer

Other features need to be added, please wait or add them by yourself.

## Build the Binding project and run test

1. Login to ESRI Online, download and install ArcGIS Runtime SDK **v10.1.1**.
2. Clone this repository to local, for example `~/Projects/MonoTouch.ArcGIS`
3. Copy file `~/Library/SDKs/ArcGIS/iOS/ArcGIS.framework/Versions/Current/ArcGIS` to Binding project folder, and rename it to `libArcGIS.a`
4. Rebuild the Binding project first, if no errors occured, then build the AGSTestCS Project.
5. Run the AGSTestCS

## Usage and Tutorial

- Check ESRI ArcGIS Runtime SDK for iOS [Guide][2].
- Check ESRI ArcGIS Runtime SDK for iOS [API reference][3].
- Check the **AGSTestCS** project in this repository.

## How to add new features

## Still need help


[1]:https://developers.arcgis.com/en/ios/
[2]:https://developers.arcgis.com/en/ios/guide/introduction.htm
[3]:https://developers.arcgis.com/en/ios/api-reference/index.htm