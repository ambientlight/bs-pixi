type webGLRenderingContext;
type jsClassRef;

[@bs.obj] external createOptions: (
  ~width: float=?,
  ~height: float=?,
  ~view: Webapi.Dom.HtmlElement.t=?,
  ~transparent: bool=?,
  ~autoDensity: bool=?,
  ~antialias: bool=?,
  ~forceFXAA: bool=?,
  ~resolution: float=?,
  ~clearBeforeRender: bool=?,
  ~preserveDrawingBuffer: bool=?,
  ~backgroundColor: int=?,
  ~context: Js.t({..})=?,
  unit
) => _ = "";

class type _t = [@bs] {
  inherit AbstractRenderer._t;

  /**
    Batch system instance
   */
  pub batch: Systems.BatchSystem.t;  

  /**
    Context system intance
   */
  pub context: Systems.ContextSystem.t;

  /**
    Collection of methods for extracting data (image, pixels, etc.) 
    from a display object or render texture
   */  
  pub extract: Extract.Extract.t;

  /**
    Filter system instance
   */
  pub filter: Systems.FilterSystem.t;

  /**
    Framebuffer system instance
   */
  pub framebuffer: Systems.FramebufferSystem.t;

  /**
    Geometry system instance
   */
  pub geometry: Systems.GeometrySystem.t;

  /**
    WebGL context, set by the contextSystem (this.context)
   */
  pub gl: webGLRenderingContext;

  /**
    Global uniforms
   */
  [@bs.set] pub globalUniforms: UniformGroup.t;

  /**
    Global uniforms
   */
  pub mask: Systems.MaskSystem.t;

  /**
    Projection system instance
   */  
  pub projection: Systems.ProjectionSystem.t;

  /**
    Flag if we are rendering to the screen vs renderTexture
   */
  pub renderingToScreen: bool;

  /**
    RenderTexture system instance
   */
  pub renderTexture: Systems.RenderTextureSystem.t;

  /**
    Scissor system instance
   */
  pub scissors: Systems.ScissorSystem.t;

  /**
    Shader system instance
   */
  pub shader: Systems.ShaderSystem.t;

  /**
    State system instance
   */
  pub state: Systems.StateSystem.t;

  /**
    Stencil system instance
   */
  pub stencil: Systems.StencilSystem.t;

  /**
    Texture system instance
   */
  pub texture: Systems.TextureSystem.t;

  /**
    Texture garbage collector system instance
   */
  pub textureGC: Systems.TextureGCSystem.t;
  
  /**
    Add a new system to the renderer.

      @param classRef Class Reference
      @param name Property name for system, if not specified will use a static name property on the class itself. This name will be assigned as s property on the Renderer so make sure it doesn't collide with properties on Renderer
      @return Return instance of renderer
   */
  pub addSystem: (jsClassRef, Js.Undefined.t(string)) => Js.t(_t);

  /**
    Clear the frame buffer
   */
  pub clear: unit => unit;

  /**
    Removes everything from the renderer (event listeners, spritebatch, etc...)

      @param removeView Removes the Canvas element from the DOM
   */
  pub destroy: bool => unit;

  /**
    Renders the object to its WebGL view

      @deprecated Consider using Renderer.render
      @see </bs-pixi/PIXI/Renderer-PIXI/#val-render> Renderer.render
      @param displayObject The object to be rendered
      @param renderTexture The render texture to render to
      @param clear Should the canvas be cleared before the new render
      @param transform A transform to apply to the render texture before rendering
      @param skipUpdateTransform Should we skip the update transform pass?
   */
  pub render: (
    AbstractRenderer.displayObjectOpaque,
    Js.Undefined.t(AbstractRenderer.renderTextureOpaque),
    bool,
    Js.Undefined.t(Js.t(#Matrix._t)),
    bool) => unit;

  /**
    Resets the WebGL state so you can render things however you fancy

      @return itself
   */
  pub reset: unit => Js.t(_t)

  /**
    Resizes the WebGL view to the specified width and height

      @param screenWidth The new width of the screen
      @param screenHeight The new height of the screen
   */
  pub resize: (float, float) => unit;
};

type t = Js.t(_t);

/**
  Adds a plugin to the renderer

    @param pluginName The name of the plugin
    @param ctor The constructor function or class for the plugin
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Renderer"]
external registerPlugin: (~pluginName: string, ~ctor: Js.Types.function_val) => unit = "registerPlugin";

module Impl {

  [@bs.module "pixi.js"][@bs.new]
  external _create: (~options: 'a=?, unit) => t = "Renderer";
  /**
    creates a new renderer

      @see </bs-pixi/PIXI/Renderer-PIXI/#val-createOptions> for options Renderer.createOptions
      @param options The optional renderer parameters
  */
  let create = (~options = createOptions(()), ()) => _create(~options, ());

  /**
    Batch system instance
  */
  [@bs.get] external getBatch: Js.t(#_t) => Systems.BatchSystem.t = "batch";

  /**
    Context system intance
  */
  [@bs.get] external getContext: Js.t(#_t) => Systems.ContextSystem.t = "context";

  /**
    Collection of methods for extracting data (image, pixels, etc.) 
    from a display object or render texture
  */
  [@bs.get] external getExtract: Js.t(#_t) => Extract.Extract.t = "extract";

  /**
    Filter system instance
  */
  [@bs.get] external getFilter: Js.t(#_t) => Systems.FilterSystem.t = "filter";

  /**
    Framebuffer system instance
  */
  [@bs.get] external getFramebuffer: Js.t(#_t) => Systems.FramebufferSystem.t = "framebuffer";

  /**
    Geometry system instance
  */
  [@bs.get] external getGeometry: Js.t(#_t) => Systems.BatchSystem.t = "geometry";

  /**
    WebGL context, set by the contextSystem (this.context)
  */
  [@bs.get] external getGl: Js.t(#_t) => webGLRenderingContext = "gl";

  /**
    Global uniforms
  */
  [@bs.get] external getGlobalUniforms: Js.t(#_t) => UniformGroup.t = "globalUniforms";

  /**
    Global uniforms
  */
  [@bs.set] external setGlobalUniforms: (Js.t(#_t), UniformGroup.t) => unit = "globalUniforms";

  /**
    Projection system instance
  */
  [@bs.get] external getProjection: Js.t(#_t) => Systems.ProjectionSystem.t = "projection";

  /**
    Flag if we are rendering to the screen vs renderTexture
  */
  [@bs.get] external getRenderingToScreen: Js.t(#_t) => bool = "renderingToScreen";

  /**
    RenderTexture system instance
  */
  [@bs.get] external getRenderTexture: Js.t(#_t) => Systems.RenderTextureSystem.t = "renderTexture";

  /**
    Scissor system instance
  */
  [@bs.get] external getScissor: Js.t(#_t) => Systems.ScissorSystem.t = "scissors";

  /**
    Shader system instance
  */
  [@bs.get] external getShader: Js.t(#_t) => Systems.ShaderSystem.t = "shader";

  /**
    State system instance
  */
  [@bs.get] external getState: Js.t(#_t) => Systems.StateSystem.t = "state";

  /**
    Stencil system instance
  */
  [@bs.get] external getStencil: Js.t(#_t) => Systems.StencilSystem.t = "stencil";

  /**
    Texture system instance
  */
  [@bs.get] external getTexture: Js.t(#_t) => Systems.TextureSystem.t = "texture";

  /**
    Texture garbage collector system instance
  */
  [@bs.get] external getTextureGC: Js.t(#_t) => Systems.TextureGCSystem.t = "textureGC";

  /**
    Add a new system to the renderer.

      @param classRef Class Reference
      @param name Property name for system, if not specified will use a static name property on the class itself. This name will be assigned as s property on the Renderer so make sure it doesn't collide with properties on Renderer
      @return Return instance of renderer
  */
  [@bs.send]
  external addSystem: (Js.t(#_t), ~classRef: jsClassRef, ~name: string=?, unit) => Js.t(#_t) = "addSystem";

  /**
    Clear the frame buffer
  */
  [@bs.send]
  external clear: Js.t(#_t) => unit = "clear";

  /**
    Removes everything from the renderer (event listeners, spritebatch, etc...)

      @param removeView Removes the Canvas element from the DOM
  */
  [@bs.send]
  external destroy: (Js.t(#_t), ~removeView: bool=?, unit) => unit = "destroy";

  /**
    Renders the object to its WebGL view

      @param displayObject The object to be rendered
      @param renderTexture The render texture to render to
      @param clear Should the canvas be cleared before the new render
      @param transform A transform to apply to the render texture before rendering
      @param skipUpdateTransform Should we skip the update transform pass?
  */
  [@bs.send]
  external render: (
    Js.t(#_t), 
    ~displayObject: AbstractRenderer.displayObjectOpaque, 
    ~renderTexture: AbstractRenderer.renderTextureOpaque=?, 
    ~clear: bool=?,
    ~transform: Js.t(#Matrix._t)=?,
    ~skipUpdateTransform: bool=?, unit) => unit = "render";

  /**
    Resets the WebGL state so you can render things however you fancy

      @return itself
  */
  [@bs.send]
  external reset: Js.t(#_t) => Js.t(#_t) = "reset";

  /**
    Resizes the WebGL view to the specified width and height

      @param screenWidth The new width of the screen
      @param screenHeight The new height of the screen
  */
  [@bs.send]
  external resize: (Js.t(#_t), ~screenWidth: float, ~screenHeight: float) => unit = "resize";
}

include EventEmitter.Impl;
include AbstractRenderer.Impl;
include Impl;