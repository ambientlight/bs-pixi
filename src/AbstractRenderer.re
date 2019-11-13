type t = Js.t(C.abstractRenderer);

/**
  Whether CSS dimensions of canvas view should be resized to screen dimensions automatically
 */
[@bs.get] external getAutoDensity: Js.t(#C.abstractRenderer) => bool = "autoDensity";

/**
  Whether CSS dimensions of canvas view should be resized to screen dimensions automatically
 */
[@bs.set] external setAutoDensity: (Js.t(#C.abstractRenderer), bool) => unit = "autoDensity";

/**
  The background color to fill if not transparent
 */
[@bs.get] external getBackgroundColor: Js.t(#C.abstractRenderer) => int = "backgroundColor";

/**
  The background color to fill if not transparent
 */
[@bs.set] external setBackgroundColor: (Js.t(#C.abstractRenderer), int) => unit = "backgroundColor";

/**
  This sets if the CanvasRenderer will clear the canvas or not before the new render pass. 
  If the scene is NOT transparent PixiJS will use a canvas sized 
  fillRect operation every frame to set the canvas background color. 
  If the scene is transparent PixiJS will use clearRect to clear the canvas every frame. 
  Disable this by setting this to false. 
  For example, if your game has a canvas filling background image you often don't need this set.
 */
[@bs.get] external getCleanBeforeRender: Js.t(#C.abstractRenderer) => bool = "cleanBeforeRender";

/**
  This sets if the CanvasRenderer will clear the canvas or not before the new render pass. 
  If the scene is NOT transparent PixiJS will use a canvas sized 
  fillRect operation every frame to set the canvas background color. 
  If the scene is transparent PixiJS will use clearRect to clear the canvas every frame. 
  Disable this by setting this to false. 
  For example, if your game has a canvas filling background image you often don't need this set.
 */
[@bs.set] external setCleanBeforeRender: (Js.t(#C.abstractRenderer), bool) => unit = "cleanBeforeRender";

/**
  Same as view.height, actual number of pixels in the canvas by vertical
 */
[@bs.get] external getHeight: Js.t(#C.abstractRenderer) => float = "height";

/**
  The supplied constructor options
 */
[@bs.get] external getOptions: Js.t(#C.abstractRenderer) => 'a = "options";

/**
  Collection of plugins
 */
[@bs.get] external getPlugins: Js.t(#C.abstractRenderer) => 'a = "plugins";

/**
  The value of the preserveDrawingBuffer flag affects 
  whether or not the contents of the stencil buffer is retained after rendering
 */
[@bs.get] external getPreserveDrawingBuffer: Js.t(#C.abstractRenderer) => bool = "preserveDrawingBuffer";

/**
  The value of the preserveDrawingBuffer flag affects 
  whether or not the contents of the stencil buffer is retained after rendering
 */
[@bs.set] external setPreserveDrawingBuffer: (Js.t(#C.abstractRenderer), bool) => unit = "preserveDrawingBuffer";

/**
  The resolution / device pixel ratio of the renderer
 */
[@bs.get] external getResolution: Js.t(#C.abstractRenderer) => float = "resolution";

/**
  The resolution / device pixel ratio of the renderer
 */
[@bs.set] external setResolution: (Js.t(#C.abstractRenderer), float) => unit = "resolution";

/**
  Measurements of the screen. (0, 0, screenWidth, screenHeight).
  Its safe to use as filterArea or hitArea for the whole stage  
 */
[@bs.get] external getScreen: Js.t(#C.abstractRenderer) => Js.t(#Rectangle._t) = "screen";

/**
  Measurements of the screen. (0, 0, screenWidth, screenHeight).
  Its safe to use as filterArea or hitArea for the whole stage  
 */
[@bs.set] external setScreen: (Js.t(#C.abstractRenderer), Js.t(#Rectangle._t)) => unit = "screen";

/**
  Whether the render view is transparent
 */
[@bs.get] external getTransparent: Js.t(#C.abstractRenderer) => bool = "transparent";

/**
  Whether the render view is transparent
 */
[@bs.set] external setTransparent: (Js.t(#C.abstractRenderer), bool) => unit = "transparent";


[@bs.get] external _getType: Js.t(#C.abstractRenderer) => int = "type";

/**
  The type of the renderer
 */
let getType = rend => rend |. _getType |. RENDERER_TYPE.tFromJs |. Belt.Option.getExn;

/**
  Whether the render view is transparent
 */
[@bs.get] external getView: Js.t(#C.abstractRenderer) => Dom.element = "view";

/**
  Whether the render view is transparent
 */
[@bs.set] external setView: (Js.t(#C.abstractRenderer), Dom.element) => unit = "view";

/**
  Same as view.width, actual number of pixels in the canvas by horizontal
 */
[@bs.get] external getWidth: Js.t(#C.abstractRenderer) => float = "width";

/**
  Removes everything from the renderer and optionally removes the Canvas DOM element

    @param removeView Removes the Canvas element from the DOM
 */
[@bs.send] external destroy: (Js.t(#C.abstractRenderer), ~removeView: bool=?, unit) => unit = "destroy";

/**
  Useful function that returns a texture of the display object 
  that can then be used to create sprites 
  This can be quite useful if your displayObject is complicated and needs to be reused multiple times

    @param displayObject The displayObject the object will be generated from
    @param scaleMode Should be one of the scaleMode consts
    @param resolution The resolution / device pixel ratio of the texture being generated
    @param region
 */
//TODO: RenderTexture support
[@bs.send] external generateTexture: (
  Js.t(#C.abstractRenderer), 
  ~displayObject: Js.t(#C.displayObject), 
  ~scaleMode: int,
  ~resolution: float,
  ~region: Js.t(#Rectangle._t)=?, unit
) => Js.t({..}) = "generateTexture";

/**
  Resizes the screen and canvas to the specified width and height
  Canvas dimensions are multiplied by resolution

    @param screenWidth The new width of the screen
    @param screenHeight The new height of the screen
 */
[@bs.send] external resize: (Js.t(#C.abstractRenderer), ~screenWidth: float, ~screenHeight: float) => unit = "resize";


