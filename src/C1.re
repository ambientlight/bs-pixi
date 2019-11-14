/**
  Contains declaration of co-dependent class types.
 */

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