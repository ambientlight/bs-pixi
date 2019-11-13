/**
  Contains declaration of co-dependent class types.
 */

class type displayObject = [@bs] {
  inherit EventEmitter._t;

  /**
    Flag for if the object is accessible. If true AccessibilityManager will overlay a shadow div with attributes set
   */
  [@bs.set] pub accessible: bool;

  /**
    Setting to false will prevent any children inside this container to be accessible. Defaults to true
   */
  [@bs.set] pub accessibleChildren: bool;

  /**
    Sets the aria-label attribute of the shadow div
   */
  [@bs.set] pub accessibleHint: Js.Nullable.t(string);

  /**
    Sets the title attribute of the shadow div 
    If accessibleTitle AND accessibleHint has not been this will default to 'displayObject [tabIndex]'
   */
  [@bs.set] pub accessibleTitle: Js.Nullable.t(string);

  /**
    Specify the type of div the accessible layer is. 
    Screen readers treat the element differently depending on this type. Defaults to button.
   */
  [@bs.set] pub accessibleType: string;

  /**
    The opacity of the object.
   */
  [@bs.set] pub alpha: float;

  /**
    The angle of the object in degrees. 
    'rotation' and 'angle' have the same effect on a display object; rotation is in radians, angle is in degrees
   */
  [@bs.set] pub angle: float;

  /**
    If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject 
    if it is interactive Setting this changes the 'cursor' property to 'pointer'.
   */
  [@bs.set] pub buttonMode: bool;

  /**
    Set this to true if you want this display object to be cached as a bitmap. 
    This basically takes a snap shot of the display object as it is at that moment. 
    It can provide a performance benefit for complex static displayObjects. 
    To remove simply set this property to false

    IMPORTANT GOTCHA - Make sure that all your textures are preloaded 
    BEFORE setting this property to true as it will take a snapshot of what is currently there. 
    If the textures have not loaded then they will not appear.
   */
  [@bs.set] pub cacheAsBitmap: bool;

  /**
    This defines what cursor mode is used when the mouse cursor is hovered over the displayObject.
   */
  [@bs.set] pub cursor: string;

  /**
    The area the filter is applied to. 
    This is used as more of an optimization rather than figuring out 
    the dimensions of the displayObject each frame you can set this rectangle.

    Also works as an interaction mask.
   */
  [@bs.set] pub filterArea: Js.Nullable.t(Rectangle.t);

  /**
    Sets the filters for the displayObject.

    IMPORTANT: This is a WebGL only feature and will be ignored by the canvas renderer. 
    To remove filters simply set this property to 'null'.    
   */
  [@bs.set] pub filters: Js.Nullable.t(array(Filter.t));

  /**
    Interaction shape. Children will be hit first, then this shape will be checked. 
    Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
   */
  [@bs.set] pub hitArea: Js.t({..});

  /**
    Enable interaction events for the DisplayObject. 
    Touch, pointer and mouse events will not be emitted unless interactive is set to true.
   */
  [@bs.set] pub interactive: bool;

  /**
    Does any other displayObject use this object as a mask?
   */
  pub isMask: bool;

  /**
    used to fast check if a sprite is.. a sprite!
   */
  pub isSprite: bool;

  /**
    Current transform of the object based on local factors: position, scale, other stuff.
   */
  pub localTransform: Matrix.t;

  /**
    Sets a mask for the displayObject. A mask is an object that limits the visibility of an object 
    to the shape of the mask applied to it. 
    In PixiJS a regular mask must be a PIXI.Graphics or a PIXI.Sprite object. 
    This allows for much faster masking in canvas as it utilities shape clipping. 
    To remove a mask, set this property to null.

    For sprite mask both alpha and red channel are used. Black mask is the same as transparent mask.

      @deprecated consider using PIXI.DisplayObject.getMask for PIXI.Graphics | PIXI.Sprite | null support
      @see </bs-pixi/PIXI/DisplayObject-PIXI/#val-getMask> DisplayObject.getMask 
   */
  /* TODO: PIXI.Graphics | PIXI.Sprite | null */
  [@bs.set] pub mask: Js.t({..});

  /**
    The instance name of the object.
   */
  [@bs.set][@bs.get nullable] pub name: string;

  /** 
    The display object container that contains this display object.
   */
  pub parent: Js.t(container);

  /* TODO: IPoint.t */
  /**
    The pivot point of the displayObject that it rotates around. Assignment by value since pixi-v4.
   */
  [@bs.set] pub pivot: Point.t;

  /**
    The coordinate of the object relative to the local coordinates of the parent. 
    Assignment by value since pixi-v4.
   */
  [@bs.set] pub position: Point.t;

  /**
    Can this object be rendered, if false the object will not be drawn but the updateTransform methods will still be called.
    Only affects recursive calls from parent. You can ask for bounds manually.
   */
  [@bs.set] pub renderable: bool;

  /**
    The rotation of the object in radians. 
    'rotation' and 'angle' have the same effect on a display object; rotation is in radians, angle is in degrees.
   */
  [@bs.set] pub rotation: float;

  /* TODO: IPoint.t */
  /**
    The scale factor of the object. Assignment by value since pixi-v4.
   */
  [@bs.set] pub scale: Point.t;

  /**
    The skew factor for the object in radians. Assignment by value since pixi-v4.
   */
  [@bs.set] pub skew: ObservablePoint.t;

  /**
    World transform and local transform of this object. 
    This will become read-only later, please do not assign anything there unless you know what are you doing.
   */
  [@bs.set] pub transform: Transform.t;

  /**
    The visibility of the object. If false the object will not be drawn, and the updateTransform function will not be called.
    Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually.
   */
  [@bs.set] pub visible: bool;

  /**
    The multiplied alpha of the displayObject.
   */
  pub worldAlpha: float;

  /**
    Current transform of the object based on world (parent) factors.
   */
  pub worldTransform: Matrix.t;

  /**
    Indicates if the object is globally visible.
   */
  pub worldVisible: bool;
  
  /**
    The position of the displayObject on the x axis relative to the local coordinates of the parent. 
    An alias to position.x
   */
  [@bs.set] pub x: float;

  /**
    The position of the displayObject on the y axis relative to the local coordinates of the parent. 
    An alias to position.y
   */
  [@bs.set] pub y: float;
  
  /**
    The zIndex of the displayObject. 
    If a container has the sortableChildren property set to true, children will be 
    automatically sorted by zIndex value; a higher value will mean it will be moved towards the end of the array, 
    and thus rendered on top of other displayObjects within the same container.
   */
  [@bs.set] pub zIndex: int;
  
  /**
    Recursively updates transform of all objects from the root to this one internal function for toLocal()
   */
  pub _recursivePostUpdateTransform: unit => unit;

  /**
    Base destroy method for generic display objects. 
    This will automatically remove the display object from its parent Container 
    as well as remove all current event listeners and internal references. 
    Do not use a DisplayObject after calling destroy().
   */
  pub destroy: unit => unit;

  /**
    Retrieves the bounds of the displayObject as a rectangle object.

      @param skipUpdate Setting to true will stop the transforms of the scene graph from being updated. 
        This means the calculation returned MAY be out of date BUT will give you a nice performance boost.
      @param rect Optional rectangle to store the result of the bounds calculation.
   */
  pub getBounds: (bool, Js.Undefined.t(Rectangle.t)) => Rectangle.t;

  /**
    Returns the global position of the displayObject. 
    Does not depend on object scale, rotation and pivot.
   */
  pub getGlobalPosition: (Point.t, bool) => Point.t;

  /**
    Retrieves the local bounds of the displayObject as a rectangle object
   */
  pub getLocalBounds: Js.Undefined.t(Rectangle.t) => Rectangle.t;

  // TODO: Renderer.t
  // pub render: Renderer.t => unit;

  //NOTE: setParent is in Container.t
  /**
    Convenience function to set the position, scale, skew and pivot at once.

      @param x Position on the x axis
      @param y Position on the y axis
      @param pivotX Pivot on the x axis
      @param pivotY Pivot on the y axis
      @param scaleX Scale on the x axis
      @param scaleY Scale on the y axis
      @param rotation rotation in radians
      @param skewX Skew on the x axis
      @param skewY Skew on the y axis
      @param pivotX The X pivot value
      @param pivotY The Y pivot value
      @return This display object
   */
  pub setTransform: (float, float, float, float, float, float, float, float, float) => Js.t(displayObject);

  /* TODO: IPoint.t */
  /**
    Calculates the global position of the display object

      @param position The world origin to calculate from
      @param from (optional) The DisplayObject to calculate the global position from
      @param point (optional) A Point object in which to store the value, optional (otherwise will create a new Point)
      @param skipUpdate Should we skip the update transform
      @return A point object representing the position of this object
   */
  pub toGlobal: (Point.t, Js.Undefined.t(Point.t), bool) => Point.t;
  /* TODO: IPoint.t */

  /**
    Calculates the local position of the display object relative to another point

      @param position The world origin to calculate from
      @param from (optional) The DisplayObject to calculate the global position from
      @param point (optional) A Point object in which to store the value, optional (otherwise will create a new Point)
      @param skipUpdate Should we skip the update transform
      @return A point object representing the position of this object
   */
  pub toLocal: (Point.t, Js.Undefined.t(Js.t(displayObject)), Js.Undefined.t(Point.t), bool) => Point.t;

  /**
    Updates the object transform for rendering
   */
  pub updateTransform: unit => unit;
} and container = [@bs] {
  inherit displayObject;

} and abstractRenderer = [@bs] {
  inherit EventEmitter._t; 

  /**
    Whether CSS dimensions of canvas view should be resized to screen dimensions automatically
   */
  [@bs.set] pub autoDensity: bool;

  /**
    The background color to fill if not transparent
   */
  [@bs.set] pub backgroundColor: int;

  /**
    This sets if the CanvasRenderer will clear the canvas or not before the new render pass. 
    If the scene is NOT transparent PixiJS will use a canvas sized 
    fillRect operation every frame to set the canvas background color. 
    If the scene is transparent PixiJS will use clearRect to clear the canvas every frame. 
    Disable this by setting this to false. 
    For example, if your game has a canvas filling background image you often don't need this set.
   */
  [@bs.set] pub cleanBeforeRender: bool;

  /**
    Same as view.height, actual number of pixels in the canvas by vertical
   */
  pub height: float;

  /**
    The supplied constructor options
   */
  pub options: Js.t({..});


  /**
    Collection of plugins
   */
  pub plugins: Js.t({..});

  /*
    The value of the preserveDrawingBuffer flag affects 
    whether or not the contents of the stencil buffer is retained after rendering
   */  
  [@bs.set] pub preserveDrawingBuffer: bool;

  /**
    The resolution / device pixel ratio of the renderer.
   */
  [@bs.set] pub resolution: float;

  /**
    Measurements of the screen. (0, 0, screenWidth, screenHeight).
    Its safe to use as filterArea or hitArea for the whole stage  
   */
  [@bs.set] pub screen: Rectangle.t;

  /**
    Whether the render view is transparent
   */
  [@bs.set] pub transparent: bool;

  /**
    The canvas element that everything is drawn to
   */
  [@bs.set] pub view: Dom.element;

  /**
    Same as view.width, actual number of pixels in the canvas by horizontal
   */
  pub width: float;

  /**
    Removes everything from the renderer and optionally removes the Canvas DOM element.

      @param removeView removes the Canvas element from the DOM
   */
  pub destroy: bool => unit;

  /**
    Useful function that returns a texture of the display object 
    that can then be used to create sprites 
    This can be quite useful if your displayObject is complicated and needs to be reused multiple times

      @param displayObject The displayObject the object will be generated from
      @param scaleMode Should be one of the scaleMode consts
      @param resolution The resolution / device pixel ratio of the texture being generated
      @param region
   */
  //pub generateTexture: Js.t(#displayObject) => Js.t()
};

class type baseTexture = [@bs] {
  inherit EventEmitter._t;

  /**
    number of the texture batch, used by multi-texture renderers    
   */
  [@bs.set] pub _batchEnabled: int;

  /**
    location inside texture batch, used by multi-texture renderers
   */
  [@bs.set] pub _batchLocation: int;

  /**
    How to treat premultiplied alpha

      @deprecated consider using BaseTexture.getAlphaMode instead
      @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-getAlphaMode> BaseTexture.getAlphaMode
   */
  [@bs.set] pub alphaMode: int;

  /**
    anisotropic filtering level of texture
   */
  [@bs.set] pub anisotropicLevel: float;

  /**
    Currently default cache ID
   */
  [@bs.set] pub cacheId: string;

  /**
    flag if BaseTexture has been destroyed
   */
  pub destroyed: bool;

  /**
    used by TextureSystem to only update texture to the GPU when needed. Please call update() to increment it.
   */
  pub dirtyId: int;

  /**
    the pixel format of the texture

      @deprecated consider using BaseTexture.getFormat instead
      @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-getFormat> BaseTexture.getFormat
   */
  pub format: int;

  /**
    The height of the base texture set when the image has loaded
   */
  pub height: float;

  /**
    Whether or not the texture is a power of two, 
    try to use power of two textures as much as you can
   */
  pub isPowerOfTwo: bool;

  /**
    Mipmap mode of the texture, affects downscaled images

      @deprecated consider using BaseTexture.getFormat instead
      @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-getFormat> BaseTexture.getFormat
   */
  [@bs.set] pub mipmap: int;

  /**
    Pixel height of the source of this texture
   */
  pub realHeight: float;

  /**
    Pixel width of the source of this texture
   */
  pub realWidth: float;

  /**
    The resolution / device pixel ratio of the texture
   */
  [@bs.set] pub resolution: float;

  /**
    The scale mode to apply when scaling this texture

      @deprecated consider using BaseTexture.getScaleMode instead
      @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-getScaleMode> BaseTexture.getScaleMode
   */
  [@bs.set] pub scaleMode: int;

  /**
    the target type

      @deprecated consider using BaseTexture.getTarget instead
      @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-getTarget> BaseTexture.getTarget
   */
  [@bs.set] pub target: int;

  /**
    The collection of alternative cache ids, since some BaseTextures can have more than one ID
    short name and longer full URL
   */
  pub textureCacheIds: array(string);

  // for type refer to BaseTexture.getType

  /**
    Global unique identifier for this BaseTexture
   */
  pub uid: string;

  /**
    Generally speaking means when resource is loaded
   */
  pub valid: bool;

  /**
    The width of the base texture set when the image has loaded
   */
  pub width: float;

  /**
    How the texture wraps
   */
  [@bs.set] pub wrapMode: int

  /**
    Destroys this base texture. The method stops if resource doesn't want this texture to be destroyed. 
    Removes texture from all caches.
   */
  pub destroy: unit => unit;

  /**
    Frees the texture from WebGL memory without destroying this texture object. 
    This means you can still use the texture later which will upload it to GPU memory again
   */
  pub dispose: unit => unit;

  // HTMLImageElement | HTMLCanvasElement | HTMLVideoElement | ImageBitmap
  /**
    Get the drawable source, such as HTMLCanvasElement or HTMLImageElement suitable for rendering with CanvasRenderer. 
    Provided by @pixi/canvas-renderer package

      @deprecated consider using BaseTexture.getDrawableSource instead for ICanvasImageSource support
      @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-getDrawableSource> BaseTexture.getDrawableSource
   */
  pub getDrawableSource: unit => Webapi.Dom.HtmlElement.t;

  /**
    Sets real size of baseTexture, preserves current resolution.    

      @deprecated consider using BaseTexture.setRealSize
      @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-setRealSize> BaseTexture.setRealSize
      @param realWidth Full rendered width
      @param realHeight Full rendered height
      @param resolution (optional) Optionally set resolution
      @return itself
   */
  pub setRealSize: (float, float, Js.Undefined.t(float)) => Js.t(baseTexture);

  /**
    Changes resolution

      @param resolution res
      @return itself
   */
  pub setResolution: float => Js.t(baseTexture);

  /**
    Sets the resource if it wasn't set. Throws error if resource already present

      @param resource that is managing this BaseTexture
      @return itself
   */
  pub setResource: Js.t(resource) => Js.t(baseTexture);

  /**
    Changes w/h/resolution. Texture becomes valid if width and height are greater than zero

      @deprecated consider using BaseTexture.setSize
      @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-setSize> BaseTexture.setSize
      @param width visual width
      @param height visual height
      @param resolution (optional) optionally set resolution
      @return itself
   */
  pub setSize: (float, float, Js.Undefined.t(float)) => Js.t(baseTexture);

  /**
    Changes style options of BaseTexture

      @deprecated consider using BaseTexture.setStyle
      @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-setStyle> BaseTexture.setStyle
      @param scaleMode (optional) Pixi scalemode
      @parm mipmap (optional) enable mipmaps
      @return itself
   */
  pub setStyle: (Js.Undefined.t(int), Js.Undefined.t(int)) => Js.t(baseTexture);
  
  /**
    Invalidates the object. Texture becomes valid if width and height are greater than zero.
   */
  pub update: unit => unit;

} and resource = [@bs] {
  /**
    if resource has been destroyed
   */
  pub destroyed: bool;
  
  /**
    the height of the resource
   */
  pub height: float;

  /**
    true if resource is created by BaseTexture useful for doing cleanup 
    with BaseTexture destroy and not cleaning up resources that were created externally.
   */
  pub internal: bool;

  /**
    has been validated
   */
  pub valid: bool;

  /**
    the width of the resource
   */
  pub width: float;

  /**
    bind to a parent BaseTexture

      @param baseTexture Parent texture
   */
  pub bind: Js.t(baseTexture) => unit;

  /**
    Call when destroying resource, unbind any BaseTexture object before calling this method, 
    as reference counts are maintained internally
   */
  pub destroy: unit => unit;

  /**
    trigger a resize event

      @param width X dimension
      @param width Y dimension
   */
  pub resize: (float, float) => unit;

  /**
    set the style, optional to override

      @param renderer yeah, renderer!
      @param baseTexture the texture
      @param glTexture texture instance for this webgl context
      @return true if success
   */
  pub style: (Renderer.t, baseTexture, GLTexture.t) => bool;

  /**
    unbind a parent base texture

      @param baseTexture parent texture
   */
  pub unbind: baseTexture => unit;

  /**
    has been updated trigger event
   */
  pub update: unit => unit;

  /**
    uploads the texture or returns false if it cant for some reason. Override this.

      @param renderer yeah, renderer!
      @param baseTexture the texture
      @param gTexture texture instance of this webgl context
   */
  pub upload: (Renderer.t, baseTexture, GLTexture.t) => bool;
};