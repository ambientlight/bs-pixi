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

  //TODO: FilterSystem / Texture / RenderTexture
  // pub apply: (FilterSystem.t, RenderTexture.t, RenderTexture.t, bool, Js.Undefined.t(Js.t({..}))) => unit;
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

//TODO: getters/setters
//TODO: FilterSystem / Texture / RenderTexture

// [@bs.send]
// external apply: (Js.t(#_t), ~filterManager: FilterSystem.t, ~input: RenderTexture.t, ~output: RenderTexture.t, ~clear: bool, ~currentState: Js.t({..}) = ?, unit) => unit = "apply";