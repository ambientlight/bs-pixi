class type _t = [@bs] {
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
      @param region (optional) The region of the displayObject, that shall be rendered, if no region is specified, defaults to the local bounds of the displayObject
      @return A texture of the graphics object
   */
  pub generateTexture: (Js.t(C.displayObject), int, float, Js.Undefined.t(Rectangle.t)) => RenderTexture.t
  
  /**
    Initialize the plugins

      @param staticMap the dictionary of statically saved plugins
   */
  pub initPlugins: Js.t({..}) => unit;

  /**
    Resizes the screen and canvas to the specified width and height
    Canvas dimensions are multiplied by resolution

      @param screenWidth The new width of the screen
      @param screenHeight The new height of the screen
   */
  pub resize: (float, float) => unit;
};

type t = Js.t(_t);

/**
  Whether CSS dimensions of canvas view should be resized to screen dimensions automatically
 */
[@bs.get] external getAutoDensity: Js.t(#_t) => bool = "autoDensity";

/**
  Whether CSS dimensions of canvas view should be resized to screen dimensions automatically
 */
[@bs.set] external setAutoDensity: (Js.t(#_t), bool) => unit = "autoDensity";

/**
  The background color to fill if not transparent
 */
[@bs.get] external getBackgroundColor: Js.t(#_t) => int = "backgroundColor";

/**
  The background color to fill if not transparent
 */
[@bs.set] external setBackgroundColor: (Js.t(#_t), int) => unit = "backgroundColor";

/**
  This sets if the CanvasRenderer will clear the canvas or not before the new render pass. 
  If the scene is NOT transparent PixiJS will use a canvas sized 
  fillRect operation every frame to set the canvas background color. 
  If the scene is transparent PixiJS will use clearRect to clear the canvas every frame. 
  Disable this by setting this to false. 
  For example, if your game has a canvas filling background image you often don't need this set.
 */
[@bs.get] external getCleanBeforeRender: Js.t(#_t) => bool = "cleanBeforeRender";

/**
  This sets if the CanvasRenderer will clear the canvas or not before the new render pass. 
  If the scene is NOT transparent PixiJS will use a canvas sized 
  fillRect operation every frame to set the canvas background color. 
  If the scene is transparent PixiJS will use clearRect to clear the canvas every frame. 
  Disable this by setting this to false. 
  For example, if your game has a canvas filling background image you often don't need this set.
 */
[@bs.set] external setCleanBeforeRender: (Js.t(#_t), bool) => unit = "cleanBeforeRender";

/**
  Same as view.height, actual number of pixels in the canvas by vertical
 */
[@bs.get] external getHeight: Js.t(#_t) => float = "height";

/**
  The supplied constructor options
 */
[@bs.get] external getOptions: Js.t(#_t) => 'a = "options";

/**
  Collection of plugins
 */
[@bs.get] external getPlugins: Js.t(#_t) => 'a = "plugins";

/**
  The value of the preserveDrawingBuffer flag affects 
  whether or not the contents of the stencil buffer is retained after rendering
 */
[@bs.get] external getPreserveDrawingBuffer: Js.t(#_t) => bool = "preserveDrawingBuffer";

/**
  The value of the preserveDrawingBuffer flag affects 
  whether or not the contents of the stencil buffer is retained after rendering
 */
[@bs.set] external setPreserveDrawingBuffer: (Js.t(#_t), bool) => unit = "preserveDrawingBuffer";

/**
  The resolution / device pixel ratio of the renderer
 */
[@bs.get] external getResolution: Js.t(#_t) => float = "resolution";

/**
  The resolution / device pixel ratio of the renderer
 */
[@bs.set] external setResolution: (Js.t(#_t), float) => unit = "resolution";

/**
  Measurements of the screen. (0, 0, screenWidth, screenHeight).
  Its safe to use as filterArea or hitArea for the whole stage  
 */
[@bs.get] external getScreen: Js.t(#_t) => Js.t(#Rectangle._t) = "screen";

/**
  Measurements of the screen. (0, 0, screenWidth, screenHeight).
  Its safe to use as filterArea or hitArea for the whole stage  
 */
[@bs.set] external setScreen: (Js.t(#_t), Js.t(#Rectangle._t)) => unit = "screen";

/**
  Whether the render view is transparent
 */
[@bs.get] external getTransparent: Js.t(#_t) => bool = "transparent";

/**
  Whether the render view is transparent
 */
[@bs.set] external setTransparent: (Js.t(#_t), bool) => unit = "transparent";


[@bs.get] external _getType: Js.t(#_t) => int = "type";

/**
  The type of the renderer
 */
let getType = rend => rend |. _getType |. RENDERER_TYPE.tFromJs |. Belt.Option.getExn;

/**
  Whether the render view is transparent
 */
[@bs.get] external getView: Js.t(#_t) => Dom.element = "view";

/**
  Whether the render view is transparent
 */
[@bs.set] external setView: (Js.t(#_t), Dom.element) => unit = "view";

/**
  Same as view.width, actual number of pixels in the canvas by horizontal
 */
[@bs.get] external getWidth: Js.t(#_t) => float = "width";

/**
  Removes everything from the renderer and optionally removes the Canvas DOM element

    @param removeView Removes the Canvas element from the DOM
 */
[@bs.send] external destroy: (Js.t(#_t), ~removeView: bool=?, unit) => unit = "destroy";

/**
  Useful function that returns a texture of the display object 
  that can then be used to create sprites 
  This can be quite useful if your displayObject is complicated and needs to be reused multiple times

    @param displayObject The displayObject the object will be generated from
    @param scaleMode Should be one of the scaleMode consts
    @param resolution The resolution / device pixel ratio of the texture being generated
    @param region The region of the displayObject, that shall be rendered, if no region is specified, defaults to the local bounds of the displayObject
    @return A texture of the graphics object
 */
[@bs.send] external generateTexture: (
  Js.t(#_t), 
  ~displayObject: Js.t(#C.displayObject), 
  ~scaleMode: int,
  ~resolution: float,
  ~region: Js.t(#Rectangle._t)=?, unit
) => Js.t(#RenderTexture._t) = "generateTexture";

/**
  Resizes the screen and canvas to the specified width and height
  Canvas dimensions are multiplied by resolution

    @param screenWidth The new width of the screen
    @param screenHeight The new height of the screen
 */
[@bs.send] external initPlugins: (Js.t(#_t), ~staticMap: 'a) => unit = "initPlugins";

/**
  Resizes the screen and canvas to the specified width and height
  Canvas dimensions are multiplied by resolution

    @param screenWidth The new width of the screen
    @param screenHeight The new height of the screen
 */
[@bs.send] external resize: (Js.t(#_t), ~screenWidth: float, ~screenHeight: float) => unit = "resize";


