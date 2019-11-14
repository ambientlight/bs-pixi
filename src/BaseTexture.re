/**
  A Texture stores the information that represents an image. 
  All textures have a base texture, which contains information about the source. 
  Therefore you can have many textures all using a single BaseTexture
 */
type t = Js.t(C1.baseTexture);

[@bs.obj] external _createOptions: (
  ~mipmap: int=?,
  ~anisotropicLevel: int=?,
  ~wrapMode: int=?,
  ~scaleMode: int=?,
  ~format: int=?,
  ~_type: int=?,
  ~target: int=?,
  ~alphaMode: int=?,
  ~width: float=?,
  ~height: float=?,
  ~resolution: float=?,
  ~resourceOptions: Js.t({.})=?,
  unit
) => _ = "";

/**
  create collection of options for base texture creation

    @param mipmap If mipmapping is enabled for texture
    @param anisotropicLevel Anisotropic filtering level of texture
    @param wrapMode Wrap mode for textures
    @param scaleMode Default scale mode, linear, nearest
    @param format GL format type
    @param _type GL data type
    @param target GL texture target
    @param alphaMode Pre multiply the image alpha
    @param width Width of the texture
    @param height Height of the texture
    @param resolution Resolution of the base texture
    @param resourceOptions Optional resource options
 */
let createOptions = (
  ~mipmap=?,
  ~anisotropicLevel=?,
  ~wrapMode=?,
  ~scaleMode=?,
  ~format=?,
  ~_type=?,
  ~target=?,
  ~alphaMode=?,
  ~width=?,
  ~height=?,
  ~resolution=?,
  ~resourceOptions=?,
  _unit: unit
) => _createOptions(
  ~mipmap =? mipmap |. Belt.Option.map(mipmap => mipmap |. MIPMAP_MODES.tToJs),
  ~anisotropicLevel?,
  ~wrapMode =? wrapMode |. Belt.Option.map(wrapMode => wrapMode |. WRAP_MODES.tToJs),
  ~scaleMode =? scaleMode |. Belt.Option.map(scaleMode => scaleMode |. SCALE_MODES.tToJs),
  ~format =? format |. Belt.Option.map(format => format |. FORMATS.tToJs),
  ~_type =? _type |. Belt.Option.map(_type => _type |. TYPES.tToJs),
  ~target =? target |. Belt.Option.map(target => target |. TARGETS.tToJs),
  ~alphaMode =? alphaMode |. Belt.Option.map(alphaMode => alphaMode |. ALPHA_MODES.tToJs),
  ~width?,
  ~height?,
  ~resolution?,
  ~resourceOptions?,
  ()
);

/**
  creates a new base texture

    @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-createOptions> for options BaseTexture.createOptions
    @param resource The current resource to use, for things that aren't Resource objects, will be converted into a Resource.
    @param options collection of options
 */
[@bs.module "pixi.js"][@bs.new]
external create: (
  ~resource: [@bs.unwrap] [
    | `Resource(Resource.t) 
    | `String(string)
    | `HTMLImageElement(Webapi.Dom.HtmlImageElement.t)
    | `HTMLCanvasElement(Webapi.Dom.Element.t)
    | `HTMLVideoElement(Webapi.Dom.Element.t)
  ]=?,
  ~options: 'a=?,
  unit
) => Js.t(#C1.baseTexture) = "BaseTexture";

/**
  number of the texture batch, used by multi-texture renderers    
 */
[@bs.get] external get_BatchEnabled: Js.t(#C1.baseTexture) => int = "_batchEnabled";

/**
  number of the texture batch, used by multi-texture renderers    
 */
[@bs.set] external set_BatchEnabled: (Js.t(#C1.baseTexture), int) => unit = "_batchEnabled";

/**
  location inside texture batch, used by multi-texture renderers   
 */
[@bs.get] external get_BatchLocation: Js.t(#C1.baseTexture) => int = "_batchLocation";

/**
  location inside texture batch, used by multi-texture renderers
 */
[@bs.set] external set_BatchLocation: (Js.t(#C1.baseTexture), int) => unit = "_batchLocation";

[@bs.get] external _getAlphaMode: Js.t(#C1.baseTexture) => int = "alphaMode";

/**
  How to treat premultiplied alpha
 */
let getAlphaMode = baseTexture => baseTexture |. _getAlphaMode |. ALPHA_MODES.tFromJs |. Belt.Option.getExn;

[@bs.set] external _setAlphaMode: (Js.t(#C1.baseTexture), int) => unit = "alphaMode";

/**
  How to treat premultiplied alpha
 */
let setAlphaMode = (baseTexture, alphaMode) => baseTexture |. _setAlphaMode(alphaMode |. ALPHA_MODES.tToJs);

/**
  anisotropic filtering level of texture   
 */
[@bs.get] external getAnisotropicLevel: Js.t(#C1.baseTexture) => float = "anisotropicLevel";

/**
  anisotropic filtering level of texture   
 */
[@bs.set] external setAnisotropicLevel: (Js.t(#C1.baseTexture), float) => unit = "anisotropicLevel";

/**
  Currently default cache ID  
 */
[@bs.get] external getCacheId: Js.t(#C1.baseTexture) => string = "cacheId";

/**
  Currently default cache ID
 */
[@bs.set] external setCacheId: (Js.t(#C1.baseTexture), string) => unit = "cacheId";

/**
  flag if BaseTexture has been destroyed
 */
[@bs.get] external getDestroyed: Js.t(#C1.baseTexture) => bool = "destroyed";

/**
  used by TextureSystem to only update texture to the GPU when needed. Please call update() to increment it
 */
[@bs.get] external getDirtyId: Js.t(#C1.baseTexture) => int = "dirtyId";

/**
  the pixel format of the texture
 */
[@bs.get] external getFormat: Js.t(#C1.baseTexture) => int = "format";

/**
  The height of the base texture set when the image has loaded
 */
[@bs.get] external getHeight: Js.t(#C1.baseTexture) => int = "height";

/**
  Whether or not the texture is a power of two, 
  try to use power of two textures as much as you can
 */
[@bs.get] external getIsPowerOfTwo: Js.t(#C1.baseTexture) => bool = "isPowerOfTwo";

[@bs.get] external _getMipmap: Js.t(#C1.baseTexture) => int = "mipmap";

/**
  Mipmap mode of the texture, affects downscaled images
 */
let getMipmap = baseTexture => baseTexture |. _getMipmap |. MIPMAP_MODES.tFromJs |. Belt.Option.getExn;

[@bs.set] external _setMipmap: (Js.t(#C1.baseTexture), int) => unit = "mipmap";

/**
  Mipmap mode of the texture, affects downscaled images
 */
let setMipmap = (baseTexture, mipmap) => baseTexture |. _setMipmap(mipmap |. MIPMAP_MODES.tToJs);

/**
  Pixel height of the source of this texture
 */
[@bs.get] external getRealHeight: Js.t(#C1.baseTexture) => float = "realHeight";

/**
   Pixel width of the source of this texture
 */
[@bs.get] external getRealWeight: Js.t(#C1.baseTexture) => float = "realWeight";

/**
  The resolution / device pixel ratio of the texture
 */
[@bs.get] external getResolution: Js.t(#C1.baseTexture) => float = "resolution";

/**
  The resolution / device pixel ratio of the texture
 */
[@bs.set] external setResolution: (Js.t(#C1.baseTexture), float) => unit = "resolution";

/**
  The scale mode to apply when scaling this texture
 */
[@bs.get] external getScaleMode: Js.t(#C1.baseTexture) => int = "scaleMode";

/**
  The scale mode to apply when scaling this texture
 */
[@bs.set] external setScaleMode: (Js.t(#C1.baseTexture), int) => unit = "scaleMode";

[@bs.get] external _getTarget: Js.t(#C1.baseTexture) => int = "target";

/**
  Mipmap mode of the texture, affects downscaled images
 */
let getTarget = baseTexture => baseTexture |. _getTarget |. TARGETS.tFromJs |. Belt.Option.getExn;

[@bs.set] external _setTarget: (Js.t(#C1.baseTexture), int) => unit = "target";

/**
  Mipmap mode of the texture, affects downscaled images
 */
let setTarget = (baseTexture, target) => baseTexture |. _setTarget(target |. TARGETS.tToJs);

/**
  The collection of alternative cache ids, since some BaseTextures can have more than one ID
  short name and longer full URL
 */
[@bs.get] external getTextureCacheIds: Js.t(#C1.baseTexture) => array(string) = "textureCacheIds";

/**
  Global unique identifier for this BaseTexture
 */
[@bs.get] external getUid: Js.t(#C1.baseTexture) => string = "uid";

/**
  Generally speaking means when resource is loaded
 */
[@bs.get] external getValid: Js.t(#C1.baseTexture) => bool = "valid";

/**
  The width of the base texture set when the image has loaded
 */
[@bs.get] external getWidth: Js.t(#C1.baseTexture) => bool = "width";

[@bs.get] external _getWrapMode: Js.t(#C1.baseTexture) => int = "wrapMode";

/**
  How the texture wraps
 */
let getWrapMode = baseTexture => baseTexture |. _getWrapMode |. WRAP_MODES.tFromJs |. Belt.Option.getExn;

[@bs.set] external _setWrapMode: (Js.t(#C1.baseTexture), int) => unit = "wrapMode";

/**
  How the texture wraps
 */
let setTarget = (baseTexture, target) => baseTexture |. _setWrapMode(target |. WRAP_MODES.tToJs);

/**
  Destroys this base texture. The method stops if resource doesn't want this texture to be destroyed. 
  Removes texture from all caches.
 */
[@bs.send]
external destroy: Js.t(#C1.baseTexture) => unit = "destroy";

/**
  Frees the texture from WebGL memory without destroying this texture object. 
  This means you can still use the texture later which will upload it to GPU memory again
 */
[@bs.send]
external dispose: Js.t(#C1.baseTexture) => unit = "dispose";

[@bs.send]
external _getDrawableSource: Js.t(#C1.baseTexture) => Webapi.Dom.HtmlElement.t = "getDrawableSource";

/**
  Get the drawable source, such as HTMLCanvasElement or HTMLImageElement suitable for rendering with CanvasRenderer. 
  Provided by @pixi/canvas-renderer package

    @raise Failure when drawable source is not recognized
    @return Source to render with CanvasRenderer
 */
let getDrawableSource: Js.t(#C1.baseTexture) => ICanvasImageSource.t = baseTexture => { 
  let drawableSource = baseTexture |. _getDrawableSource;

  module Internal {
    type constructor;
    [@bs.val] external htmlImageElement: constructor = "HTMLImageElement";
    [@bs.val] external htmlCanvasElement: constructor = "HTMLCanvasElement";
    [@bs.val] external htmlVideoElement: constructor = "HTMLVideoElement";
    [@bs.val] external imageBitmap: constructor = "ImageBitmap";

    let instanceOf: ('a, constructor) => bool = [%bs.raw {|function(x,y) {return +(x instanceof y)}|}];
  };

  if(Internal.instanceOf(drawableSource, Internal.htmlImageElement)){
    `HTMLImageElement(drawableSource |> Obj.magic)
  } else if (Internal.instanceOf(drawableSource, Internal.htmlCanvasElement)) {
    `HTMLCanvasElement(drawableSource)
  } else if (Internal.instanceOf(drawableSource, Internal.htmlVideoElement)) {
    `HTMLVideoElement(drawableSource)
  } else if (Internal.instanceOf(drawableSource, Internal.imageBitmap)){
    `ImageBitmap(drawableSource |> Obj.magic)
  } else {
    raise(Failure("Unrecognized drawable source"))
  }
};

/**
  Sets real size of baseTexture, preserves current resolution. 

    @param realWidth Full rendered width
    @param realHeight Full rendered height
    @param resolution Optionally set resolution
    @return itself
 */
[@bs.send]
external setRealSize: (Js.t(#C1.baseTexture), ~realWidth: float, ~realHeight: float, ~resolution: float=?, unit) => Js.t(#C1.baseTexture) = "setRealSize";

/**
  Changes resolution

    @param resolution res
    @return itself
 */
[@bs.send]
external setResolution: (Js.t(#C1.baseTexture), ~resolution: float) => Js.t(#C1.baseTexture) = "setResolution";

/**
  Sets the resource if it wasn't set. Throws error if resource already present

    @param resource that is managing this BaseTexture
    @return itself
 */
[@bs.send]
external setResource: (Js.t(#C1.baseTexture), ~resource: Js.t(#C1.resource)) => Js.t(#C1.baseTexture) = "setResource";

/**
  Changes w/h/resolution. Texture becomes valid if width and height are greater than zero

    @param width visual width
    @param height visual height
    @param resolution (optional) optionally set resolution
    @return itself
 */
[@bs.send]
external setSize: (Js.t(#C1.baseTexture), ~width: float, ~height: float, ~resolution: float=?, unit) => Js.t(#C1.baseTexture) = "setSize";

[@bs.send]
external _setStyle: (Js.t(#C1.baseTexture), ~scaleMode: int=?, ~mipmap: int=?, unit) => Js.t(#C1.baseTexture) = "setStyle";

/**
  Changes style options of BaseTexture

    @param scaleMode (optional) Pixi scalemode
    @parm mipmap (optional) enable mipmaps
    @return itself
 */
let setStyle = 
  (baseTexture, ~scaleMode, ~mipmap, _unit: unit) => 
    baseTexture |. _setStyle(
      ~scaleMode =? scaleMode |. Belt.Option.map(scaleMode => scaleMode |. SCALE_MODES.tToJs),
      ~mipmap =? mipmap |. Belt.Option.map(mipmap => mipmap |. MIPMAP_MODES.tToJs),
      ());

/**
  Invalidates the object. Texture becomes valid if width and height are greater than zero
 */
[@bs.send]
external update: Js.t(#C1.baseTexture) => unit = "update";