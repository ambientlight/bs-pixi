class type _t = [@bs] {
  /** 
    Loader instance to help with asset loading.
   */
  pub loader: Loader.t;

  /**
    WebGL renderer if available, otherwise CanvasRenderer.
   */
  [@bs.set] pub renderer: Js.t(#AbstractRenderer._t);

  /**
    The element or window to resize the application to.
   */
  [@bs.set] pub resizeTo: Webapi.Dom.Window.t;

  /**
    Reference to the renderer's screen rectangle. Its safe to use as filterArea or hitArea for the whole screen.
   */
  pub screen: Rectangle.t;

  /**
    The root display container that's rendered.
   */
  [@bs.set] pub stage: Js.t(#C.container);

  /**
    Ticker for doing render updates.
   */  
  [@bs.set] pub ticker: Js.t(#Ticker._t);

  /**
    Reference to the renderer's canvas element.
   */
  pub view: Webapi.Dom.HtmlElement.t;

  /**
    Destroy and don't use after this.
   */
  pub destroy: (bool, Js.Undefined.t(Js.t({..}))) => unit;

  /**
    Render the current stage.
   */
  pub render: unit => unit;

  /**
    If resizeTo is set, calling this function will resize to the width and height of that element.
   */
  pub resize: unit => unit;

  /**
    Convenience method for starting the render.
   */
  pub start: unit => unit;

  /**
    Convenience method for stopping the render.
   */
  pub stop: unit => unit;
};

/**
  Convenience class to create a new PIXI application.
  This class automatically creates the renderer, ticker and root container.
 */
type t = Js.t(_t);

[@bs.obj] external createApplicationOptions: (
  ~sharedTicker: bool=?,
  ~sharedLoader: bool=?,
  ~autoStart: bool=?,
  ~width: int=?,
  ~height: int=?,
  ~view: Webapi.Dom.HtmlElement.t=?,
  ~transparent: bool=?,
  ~antialias: bool=?,
  ~preserveDrawingBuffer: bool=?,
  ~resolution: float=?,
  ~forceCanvas: bool=?,
  ~backgroundColor: int=?,
  ~clearBeforeRender: bool=?,
  ~roundPixels: bool=?,
  ~forceFXAA: bool=?,
  ~legacy: bool=?,
  unit
) => _ = "";

/**
  Register a middleware plugin for the application
 */
[@bs.module "pixi.js"][@bs.scope "Application"]
external registerPlugin: (Js.t({.. init: Js.t(#_t) => unit, destroy: Js.t(#_t) => unit})) => unit = "registerPlugin";

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external _create: (~options: 'a=?, unit) => Js.t(#_t) = "Application";

  let create = (~options = createApplicationOptions(()), ()) => _create(~options, ());

  [@bs.send]
  external _destroy: (Js.t(#_t), ~removeView: bool=?, ~stageOptions: 'a=?, unit) => unit = "destroy";

  /**
    Destroy and don't use after this.
  */
  let destroy = (application, ~removeView=?, ~stageOptions=Container.createDestroyOptions(()), ()) => 
    application |. _destroy(~removeView?, ~stageOptions, ());

  /**
    Render the current stage.
  */
  [@bs.send]
  external render: Js.t(#_t) => unit = "render";

  /**
    If resizeTo is set, calling this function will resize to the width and height of that element.
  */
  [@bs.send]
  external resize: Js.t(#_t) => unit = "resize";

  /**
    Convenience method for starting the render.
  */
  [@bs.send]
  external start: Js.t(#_t) => unit = "start";

  /**
    Convenience method for stopping the render.
  */
  [@bs.send]
  external stop: Js.t(#_t) => unit = "stop";
}

include Impl;