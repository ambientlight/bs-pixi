class type _t = [@bs] {
  inherit Texture._t;

  /**
    Stores sourceFrame when this texture is inside current filter stack. 
    You can read it inside filters.
   */
  pub filterFrame: Rectangle.t;

  /**
    This will let the renderer know if the texture is valid. 
    If it's not then it cannot be rendered.
   */
  pub valid: bool;

  /**
    Resizes the RenderTexture.

      @param width The width to resize to
      @param height The height to resize to
      @param resizeBaseTexture Should the baseTexture.width and height values be resized as well?
   */
  pub resize: (float, float, bool) => unit;  

  /**
    Changes the resolution of baseTexture, but does not change framebuffer size

      @param resolution The new resolution to apply to RenderTexture
   */
  pub setResolution: float => unit;
};

/**
  A RenderTexture is a special texture that allows any PixiJS display object to be rendered to it.
  Hint: All DisplayObjects (i.e. Sprites) that render to a RenderTexture 
  should be preloaded otherwise black rectangles will be drawn instead.

  Hint-2: The actual memory allocation will happen on first render. 
  You shouldn't create renderTextures each frame just to delete them after, try to reuse them.
 */
type t = Js.t(_t);

[@bs.obj] external _createOptions: (
  ~width: float=?,
  ~height: float=?,
  ~scaleMode: int=?,
  ~resolution: float=?,
  unit
) => _ = "";

/**
  create collection of options for base render texture creation

    @param width The width of the render texture
    @param height The height of the render texture
    @param scaleMode 
    @param resolution The resolution / device pixel ratio of the texture being generated
 */
let createOptions = (
  ~width=?,
  ~height=?,
  ~scaleMode=?,
  ~resolution=?,
  _unit: unit
) => _createOptions(
  ~width?,
  ~height?,
  ~scaleMode =? scaleMode |. Belt.Option.map(scaleMode => scaleMode |. SCALE_MODES.tToJs),
  ~resolution?,
  ()
);

module Impl {

  [@bs.module "pixi.js"][@bs.new]
  external create: (
    ~baseRenderTexture: Js.t(#BaseRenderTexture._t),
    ~frame: Js.t(#Rectangle._t)=?,
    unit
  ) => t = "RenderTexture";

  [@bs.val][@bs.module "pixi.js"][@bs.scope "RenderTexture"]
  external _create_: (
    ~options: 'a=?,
    unit
  ) => t = "create";

  /**
    A short hand way of creating a render texture

      @see </bs-pixi/PIXI/RenderTexture-PIXI/#val-createOptions> for options RenderTexture.createOptions
      @param options collection of options
  */
  let create_ = (~options=createOptions(()), ()) => _create_(~options, ());

  /**
    Stores sourceFrame when this texture is inside current filter stack. 
    You can read it inside filters.
  */
  [@bs.get] external getFilterFrame: Js.t(#_t) => Js.t(#Rectangle._t) = "filterFrame";

  /**
    Stores sourceFrame when this texture is inside current filter stack. 
    You can read it inside filters.
  */
  [@bs.set] external setFilterFrame: (Js.t(#_t), Js.t(#Rectangle._t)) => unit = "filterFrame";

  /**
    This will let the renderer know if the texture is valid. 
    If it's not then it cannot be rendered.
  */
  [@bs.get] external getValid: Js.t(#_t) => bool = "valid";

  /**
    This will let the renderer know if the texture is valid. 
    If it's not then it cannot be rendered.
  */
  [@bs.set] external setValid: (Js.t(#_t), bool) => unit = "valid";

  /**
    Resizes the RenderTexture

      @param width The width to resize to.
      @param height The height to resize to.
      @param resizeBaseTexture Should the baseTexture.width and height values be resized as well?
  */
  [@bs.send]
  external resize: (Js.t(#_t), ~width: float, ~height: float, ~resizeBaseTexture: bool=?, unit) => unit = "resize";

  /**
    Changes the resolution of baseTexture, but does not change framebuffer size.

      @param resolution The new resolution to apply to RenderTexture
  */
  [@bs.send]
  external setResolution: (Js.t(#_t), ~resolution: float) => unit = "setResolution";
}

include EventEmitter.Impl;
include Texture.Impl;
include Impl;