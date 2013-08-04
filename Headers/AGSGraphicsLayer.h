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

@class AGSLayer;
@class AGSGraphic;
@class AGSRenderer;
@class AGSSymbol;
@class AGSSpatialReference;
@class AGSEnvelope;


/**
 Specifies how the AGSSGraphicsLayer renders it's content.
 Use the dynamic mode if your graphics are constantly moving.
 If your content is more static then use static mode.
 Static mode is the default.
 @agssince{10.1.1-u1, 10.2}
 */
typedef enum {
    AGSGraphicsLayerRenderingModeStatic = 0,             /*!<  */
    AGSGraphicsLayerRenderingModeDynamic        /*!<  */
} AGSGraphicsLayerRenderingMode;

/** @file AGSGraphicsLayer.h */ //Required for Globals API doc

/** @brief A layer to display graphics on the map.
 
 This layer  allows you to add graphics on the map. By using these graphics, you
 can add your own places of interest to the map, or highlight existing places.
 
 Each graphic contains a geometry describing the location and the shape of the
 graphic. A Graphics layer typically contains @p graphics based on a single
 geometry type (Point, Multipoint, Polyline, or Polygon).  Each graphic can be
 associated with an @c AGSSymbol which controls how the graphic looks.
 Alternatively, the layer can be associated with an @c AGSRenderer which manages
 the appearance of all graphics in the layer.
 
 In a Model-View-Controller architecture, this object represents the Model. The
 corresponding View object, @c AGSDynamicLayerView, is created when this object
 is added to the map.
 
 The @p spatialReference property of a graphics layer is defined either by
 setting the #initialEnvelope with a valid spatial reference or when the first
 graphic is added with a valid geometry and spatial reference. Furthermore, the
 geometry of individual graphics in the layer must be of the same spatial
 reference.
 
 @define{AGSGraphicsLayer.h, ArcGIS}
 @agssince{1.0, 10.2}
 @see AGSMapViewDelegate for events related to tapping on graphics
 in the %graphics layer.
 
 */
@interface AGSGraphicsLayer : AGSLayer

/** Initializes a graphics layer with a full envelope.
 If you don't use this, the spatial reference is implied from the contents of the
 graphics in the layer at the point the graphics layer is added to the map.
 It's recommended to use this initWithFullEnvelope: or initWithSpatialReference if the AGSGraphicsLayer will
 be a base-map layer (the first layer added to a map). In this case the
 full envelope should have it's spatialReference property not nil.
 @agssince{10.1.1, 10.2}
 */
-(id)initWithFullEnvelope:(AGSEnvelope*)fullEnv;

/** Initializes an AGSGraphicsLayer with a spatial reference.
 You should use this or #initWithFullEnvelope: if you want your layer to be the base layer.
 This method is helpful if you don't know the full envelope. This method will attempt to pull
 the defualt full envelope from the spatial reference for initialization purposes.
 @agssince{10.1.1, 10.2}
 */
-(id)initWithSpatialReference:(AGSSpatialReference*)sr;

/** Initializes an AGSGraphicsLayer with a full envelope and a flag stating whether
the layer will rasterize it's graphics. 
Rasterizing graphics is good when you have a lot of graphics.
If you have a small number of graphics you can move them around more efficiently 
if you set this to NO.
The full envelope can be nil, but it should be valid and have a valid spatial reference
if this layer will be a base layer in a map.
 @agssince{10.1.1-u1, 10.2}
 */
-(id)initWithFullEnvelope:(AGSEnvelope*)fullEnv renderingMode:(AGSGraphicsLayerRenderingMode)renderingMode;

/** The rendering mode for this graphics layer.
 @agssince{10.1.1-u1, 10.2}
 */
@property (nonatomic, assign, readonly) AGSGraphicsLayerRenderingMode renderingMode;

/** The array of @c AGSGraphic objects that need to be displayed on the map.
 This property returns a thread-safe copy.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSArray *graphics;

/** If you simply need the count of the graphics, you can access it through
 this property instead of using the graphics property which has the overhead
 of creating a copy.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readonly) NSUInteger graphicsCount;

/** @c AGSRenderer assigned to the layer. It is responsible for symbolizing the
 graphics. It is optional as each graphic may have it's own symbol. If a graphic
 has a symbol, that will be used for drawing the graphic instead of the renderer.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, strong) AGSRenderer *renderer;

/** The name of the attribute that contains starting time information of a graphic.
 Only applicable if graphics contain temporal information.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, copy) NSString *startTimeField;

/** The name of the attribute that contains ending time information of a graphic.
 Only applicable if graphics contain temporal information.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, copy) NSString *endTimeField;

/** The amount of time by which data in this layer is offset from the time when the data was recorded. Specify the units using the
 #timeOffsetUnits property.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign) double timeOffset;

/** Units of the amount specified by #timeOffset.
 Refer to @c AGSTimeIntervalUnits for possible values.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign) AGSTimeIntervalUnits timeOffsetUnits;

/** Specifies whether the layer can be consolidated with other layers for saving memory.
 @agssince{10.1.1-u1, 10.2}
 */
@property (nonatomic, assign) BOOL allowLayerConsolidation;

/** A method to get an initialized and autoreleased graphics layer.
 @return A new, autoreleased, graphics layer object.
 @agssince{1.0, 10.2}
 */
+ (id)graphicsLayer;

/** Adds @p graphic to the layer.
 @param graphic The graphic to be added.
 @agssince{1.0, 10.2}
 */
- (void)addGraphic:(AGSGraphic *)graphic;

/** Adds @p graphics to the layer.
 @param graphics Array of @c AGSGraphic objects to be added.
 @agssince{1.0, 10.2}
 */
- (void)addGraphics:(NSArray *)graphics;

/** Remove @p graphic from the graphics collection.
 redraw the layer.
 @param graphic The graphic to be removed.
 @agssince{1.0, 10.2}
 */
- (void)removeGraphic:(AGSGraphic *)graphic;

/** Remove all graphics from the layer.
 the layer.
 @agssince{1.0, 10.2}
 */
- (void)removeAllGraphics;

/**
 Removes a set of graphics from the layer.
 */
-(void)removeGraphics:(NSArray *)objects;

/** The symbol to use for drawing selected graphics
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, strong, readwrite) AGSSymbol *selectionSymbol;

/** The color to use for drawing a halo around selected graphics
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, copy) AGSColor *selectionColor;

/** Selects or un-selects the graphic.
 Graphics with selection enabled will be drawn using #selectionSymbol.
 If #selectionSymbol is not specified, then #selectionColor will be used to draw a halo around the graphic.
 @param selected If YES, graphic will be selected. Else it will be un-selected
 @param graphic
 @agssince{10.1.1, 10.2}
 */
-(void)setSelected:(BOOL)selected forGraphic:(AGSGraphic*)graphic;

/** Returns whether a given graphic is selected or not.
 Graphics with selection enabled will be drawn using #selectionSymbol.
 If #selectionSymbol is not specified, then #selectionColor will be used to draw a halo around the graphic.
 @param graphic
 @agssince{10.1.1, 10.2}
 */
-(BOOL)isGraphicSelected:(AGSGraphic*)graphic;

/** Clears selection on all graphics
 @agssince{10.1.1, 10.2}
 */
-(void)clearSelection;

/** An array of @c AGSGraphic objects representing graphics that have selection enabled
 Graphics with selection enabled will be drawn using #selectionSymbol.
 If #selectionSymbol is not specified, then #selectionColor will be used to draw a halo around the graphic.
 @agssince{10.1.1, 10.2}
 */
-(NSArray*)selectedGraphics;

/** This method does nothing for AGSGraphicsLayer. This method will be potentially
 implemented of subclasses of AGSGraphicsLayer that retrieve their content from a service.
 @agssince{10.1.1, 10.2}
 */
-(void)refresh;

@end
