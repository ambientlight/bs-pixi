class type _t = [@bs] {
  inherit C1.baseTexture;

  /**
    The data structure for the filters
   */
  [@bs.set] pub filterStack: array(Js.t({..}))

  /**
    The data structure for the stencil masks.
   */
  [@bs.set] pub maskStack: array(MaskData.t)

  /**
    Destroys the texture
   */
  pub destroy: unit => unit;

  /**
    Frees the texture and framebuffer from WebGL memory without destroying this texture object. 
    This means you can still use the texture later which will upload it to GPU memory again.
   */
  pub dispose: unit => unit;

  /**
    Resizes the BaseRenderTexture

      @param width The width to resize to
      @param height The height to resize to
   */
  pub resize: (float, float) => unit;
};

/**
  A BaseRenderTexture is a special texture that allows any PixiJS display object to be rendered to it.
  Hint: All DisplayObjects (i.e. Sprites) that render to a BaseRenderTexture should be preloaded 
  otherwise black rectangles will be drawn instead.
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

[@bs.module "pixi.js"][@bs.new]
external _create: (
  ~options: 'a=?,
  unit
) => Js.t(#C1.baseTexture) = "BaseRenderTexture";

/**
  creates a new base render texture

    @see </bs-pixi/PIXI/BaseRenderTexture-PIXI/#val-createOptions> for options BaseRenderTexture.createOptions
    @param options collection of options
 */
let create = (~options = createOptions(()), ()) => _create(~options, ());

/**
  The data structure for the filters
 */
[@bs.get] external getFilterStack: Js.t(#_t) => array(Js.t({..})) = "filterStack";

/**
  The data structure for the filters
 */
[@bs.set] external setFilterStack: (Js.t(#_t), array(Js.t({..}))) => unit = "filterStack";

/**
  The data structure for the stencil masks.
 */
[@bs.get] external getMaskStack: Js.t(#_t) => array(Js.t(#MaskData._t)) = "maskStack";

/**
  The data structure for the stencil masks.
 */
[@bs.set] external setMaskStack: (Js.t(#_t), array(Js.t(#MaskData._t))) => unit = "maskStack";

/**
  Destroys the texture
 */
[@bs.send]
external destroy: Js.t(#_t) => unit = "destroy";

/**
  Frees the texture and framebuffer from WebGL memory without destroying this texture object. 
  This means you can still use the texture later which will upload it to GPU memory again.
 */
[@bs.send]
external dispose: Js.t(#_t) => unit = "dispose";

/**
  Resizes the BaseRenderTexture

    @param width The width to resize to
    @param height The height to resize to
 */
[@bs.send]
external resize: (Js.t(#_t), ~width: float, ~height: float) => unit = "resize";

