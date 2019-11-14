class type _t = [@bs] {
  inherit Shader._t;

  /**
    If enabled, PixiJS will fit the filter area into boundaries for better performance. 
    Switch it off if it does not work for specific shader.
   */
  [@bs.set] pub autoFit: bool;

  /**
    Sets the blendmode of the filter
   */
  [@bs.set] pub blendMode: int;

  /**
    If enabled is true the filter is applied, if false it will not
   */
  [@bs.set] pub enabled: bool;

  /**
    Legacy filters use position and uvs from attributes
   */
  pub legacy: bool;

  /**
    The padding of the filter. Some filters require extra space to breath such as a blur. 
    Increasing this will add extra width and height to the bounds of the object that the filter is applied to
   */
  [@bs.set] pub padding: float;

  /**
    The resolution of the filter. 
    Setting this to be lower will lower the quality but increase the performance of the filter.
   */
  [@bs.set] pub resolution: float;

  /**
    The WebGL state the filter requires to render
   */
  [@bs.set] pub state: State.t;

  /**
    Applies the filter

      @param filterManager The renderer to retrieve the filter from
      @param input The input render target
      @param output The target to output to
      @param clear Should the output be cleared before rendering to it
      @param currentState (optional) It's current state of filter. There are some useful properties in the currentState : target, filters, sourceFrame, destinationFrame, renderTarget, resolution
   */
  pub apply: (Systems.FilterSystem.t, RenderTexture.t, RenderTexture.t, bool, Js.Undefined.t(Js.t({..}))) => unit;
};

/**
  Filter is a special type of WebGL shader that is applied to the screen.
  Example of the BlurFilter.
 */
type t = Js.t(_t);

/**
  creates a new filter

    @param vertexSrc The source of the vertex shader
    @param fragmentSrc The source of the fragment shader
    @param uniforms Custom uniforms to use to augment the built-in ones
 */
[@bs.module "pixi.js"][@bs.new]
external create: (~vertexSrc: string=?, ~fragmentSrc: string=?, ~uniforms: 'a=?, unit) => Js.t(#_t) = "Filter";

/**
  The default fragment shader source
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Filter"]
external defaultFragmentSrc: string = "defaultFragmentSrc";

/**
  The default vertex shader source
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Filter"]
external defaultVertexSrc: string = "defaultVertexSrc";

/**
  Used for caching shader IDs
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Filter"]
external sourceKeyMap: 'a = "SOURCE_KEY_MAP";

/**
  If enabled, PixiJS will fit the filter area into boundaries for better performance. 
  Switch it off if it does not work for specific shader.
 */
[@bs.get] external getAutoFit: Js.t(#_t) => bool = "autoFit";

/**
  If enabled, PixiJS will fit the filter area into boundaries for better performance. 
  Switch it off if it does not work for specific shader.
 */
[@bs.set] external setAutoFit: (Js.t(#_t), bool) => unit = "autoFit";

[@bs.get] external _getBlendMode: Js.t(#_t) => int = "blendMode";

/**
  Returns the blendmode of the filter
 */
let getBlendMode = filter => filter |. _getBlendMode |. BLEND_MODES.tFromJs |. Belt.Option.getExn;

[@bs.set] external _setBlendMode: (Js.t(#_t), int) => int = "blendMode";

/**
  Sets the blendmode of the filter
 */
let setBlendMode = (filter, blendMode) => filter |. _setBlendMode(blendMode |. BLEND_MODES.tToJs);

/**
  If enabled is true the filter is applied, if false it will not.
 */
[@bs.get] external getEnabled: Js.t(#_t) => bool = "enabled";

/**
  If enabled is true the filter is applied, if false it will not.
 */
[@bs.set] external setEnabled: (Js.t(#_t), bool) => unit = "enabled";

/**
  Legacy filters use position and uvs from attributes
 */
[@bs.get] external getLegacy: Js.t(#_t) => bool = "legacy";

/**
  The padding of the filter. 
  Some filters require extra space to breath such as a blur. 
  Increasing this will add extra width and height to the bounds of the object that the filter is applied to
 */
[@bs.get] external getPadding: Js.t(#_t) => float = "padding";

/**
  The padding of the filter. 
  Some filters require extra space to breath such as a blur. 
  Increasing this will add extra width and height to the bounds of the object that the filter is applied to
 */
[@bs.set] external setPadding: (Js.t(#_t), float) => unit = "padding";

/**
  The resolution of the filter. 
  Setting this to be lower will lower the quality but increase the performance of the filter.
 */
[@bs.get] external getResolution: Js.t(#_t) => float = "resolution";

/**
  The resolution of the filter. 
  Setting this to be lower will lower the quality but increase the performance of the filter.
 */
[@bs.set] external setResolution: (Js.t(#_t), float) => unit = "resolution";

/**
  The WebGL state the filter requires to render
 */
[@bs.get] external getState: Js.t(#_t) => Js.t(#State._t) = "state";

/**
  The WebGL state the filter requires to render
 */
[@bs.set] external setState: (Js.t(#_t), Js.t(#State._t)) => unit = "state";

/**
  Applies the filter

    @param filterManager The renderer to retrieve the filter from
    @param input The input render target
    @param output The target to output to
    @param clear Should the output be cleared before rendering to it
    @param currentState It's current state of filter. There are some useful properties in the currentState : target, filters, sourceFrame, destinationFrame, renderTarget, resolution
 */
[@bs.send]
external apply: (
  Js.t(#_t), 
  ~filterManager: Systems.FilterSystem.t, 
  ~input: RenderTexture.t, 
  ~output: RenderTexture.t, 
  ~clear: bool, 
  ~currentState: 'a = ?, unit) => unit = "apply";