class type _t = [@bs]{
  /**
    Whether or not this ticker should invoke the method PIXI.Ticker#start automatically when a listener is added.
    @default: false
   */
  [@bs.set] pub autoStart: bool;

  /**
    Counts the number of listeners on this ticker.
   */
  pub count: int;

  /**
    Scaler time elapsed in milliseconds from last frame to this frame. 
    This value is capped by setting PIXI.Ticker#minFPS and is scaled with PIXI.Ticker#speed. 
    Note: The cap may be exceeded by scaling. If the platform supports DOMHighResTimeStamp, 
    this value will have a precision of 1 µs. 
    @default: 16.66
   */
  pub deltaMS: float;

  /**
    Scalar time value from last frame to this frame.
    This value is capped by setting PIXI.Ticker#minFPS and is scaled with PIXI.Ticker#speed.
    Note: The cap may be exceeded by scaling.
    @default: 1
   */
  pub deltaTime: float;

  /**
    Time elapsed in milliseconds from last frame to this frame. 
    Opposed to what the scalar PIXI.Ticker#deltaTime is based, this value is neither capped nor scaled. 
    If the platform supports DOMHighResTimeStamp, this value will have a precision of 1 µs. 
    @default: 16.66
   */
  pub elapsedMS: float;
  // pub FPS: float;

  /**
    The last time PIXI.Ticker#update was invoked. 
    This value is also reset internally outside of invoking update, but only when a new animation frame is requested. 
    If the platform supports DOMHighResTimeStamp, this value will have a precision of 1 µs.
    @default: -1
   */
  pub lastTime: float;

  /**
    Manages the minimum amount of milliseconds required to elapse between invoking PIXI.Ticker#update. 
    This will effect the measured value of PIXI.Ticker#FPS. 
    If it is set to 0, then there is no limit; PixiJS will render as many frames as it can. 
    Otherwise it will be at least minFPS
    @default: 0
   */
  [@bs.set] pub maxFPS: float;

  /**
    Manages the maximum amount of milliseconds allowed to elapse between invoking PIXI.Ticker#update. 
    This value is used to cap PIXI.Ticker#deltaTime, but does not effect the measured value of PIXI.Ticker#FPS. 
    When setting this property it is clamped to a value between 0 and PIXI.settings.TARGET_FPMS * 1000.
    @default: 10 
   */
  [@bs.set] pub minFPS: float;

  /**
    Factor of current PIXI.Ticker#deltaTime.
    @default: 1
   */
  [@bs.set] pub speed: float;

  /**
    Whether or not this ticker has been started. true if PIXI.Ticker#start has been called. false if PIXI.Ticker#stop has been called. While false, this value may change to true in the event of PIXI.Ticker#autoStart being true and a listener is added.
    @default: false
   */
  pub started: bool;

  /**
    Register a handler for tick events. Calls continuously unless it is removed or the ticker is stopped.
   */
  pub add: (float => unit, Js.Undefined.t('context), Js.Undefined.t(UPDATE_PRIORITY.t)) => Js.t(_t);

  /**
    Add a handler for the tick event which is only execute once.
   */
  pub addOnce: (float => unit, Js.Undefined.t('context), Js.Undefined.t(UPDATE_PRIORITY.t)) => Js.t(_t);

  /**
    Destroy the ticker and don't use after this. Calling this method removes all references to internal events.
   */
  pub destroy: unit => unit;

  /**
    Removes any handlers matching the function and context parameters. If no handlers are left after removing, then it cancels the animation frame.
   */
  pub remove: (float => unit, Js.Undefined.t('context)) => Js.t(_t);

  /**
    Starts the ticker. If the ticker has listeners a new animation frame is requested at this point.
   */
  pub start: unit => unit;

  /**
    Stops the ticker. If the ticker has requested an animation frame it is canceled at this point.
   */
  pub stop: unit => unit;

  /**
    Triggers an update. An update entails setting the current PIXI.Ticker#elapsedMS, 
    the current PIXI.Ticker#deltaTime, invoking all listeners with current deltaTime, 
    and then finally setting PIXI.Ticker#lastTime with the value of currentTime that was provided. 
    This method will be called automatically by animation frame callbacks if the ticker instance has been started and listeners are added.
   */
  pub update: (Js.Undefined.t(float)) => unit;
};

/**
  A Ticker class that runs an update loop that other objects listen to.
  This class is composed around listeners meant for execution on the next requested animation frame. 
  Animation frames are requested only when necessary, e.g. When the ticker is started and the emitter has listeners.
 */
type t = Js.t(_t);

/**
  The shared ticker instance used by PIXI.AnimatedSprite and by 
  PIXI.VideoResource to update animation frames / video textures.
  It may also be used by PIXI.Application if created with the sharedTicker option property set to true.
  
  The property PIXI.Ticker#autoStart is set to true for this instance. 
  Please follow the examples for usage, including how to opt-out of auto-starting the shared ticker.
*/
[@bs.module "pixi.js"][@bs.scope "Ticker"][@bs.val]
external shared: t = "shared";

/**
  The system ticker instance used by PIXI.interaction.InteractionManager and by PIXI.BasePrepare for core timing functionality that shouldn't usually need to be paused, unlike the shared ticker which drives visual animations and rendering which may want to be paused.
  The property PIXI.Ticker#autoStart is set to true for this instance.
*/
[@bs.module "pixi.js"][@bs.scope "Ticker"][@bs.val]
external system: t = "system";

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: unit => t = "Ticker";

  /**
    Whether or not this ticker should invoke the method PIXI.Ticker#start automatically when a listener is added.
    @default: false
    */
  [@bs.get] external getAutoStart: Js.t(#_t) => bool = "autoStart";

  /**
    Whether or not this ticker should invoke the method PIXI.Ticker#start automatically when a listener is added.
    @default: false
  */
  [@bs.set] external setAutoStart: (Js.t(#_t), bool) => unit = "autoStart";

  /**
    Counts the number of listeners on this ticker.
  */
  [@bs.get] external getCount: Js.t(#_t) => int = "count";

  /**
    Scaler time elapsed in milliseconds from last frame to this frame. 
    This value is capped by setting PIXI.Ticker#minFPS and is scaled with PIXI.Ticker#speed. 
    Note: The cap may be exceeded by scaling. If the platform supports DOMHighResTimeStamp, 
    this value will have a precision of 1 µs. Defaults to target frame time 16.66
    */
  [@bs.get] external getDeltaMS: Js.t(#_t) => float = "deltaMS";

  /**
    Scalar time value from last frame to this frame.
    This value is capped by setting PIXI.Ticker#minFPS and is scaled with PIXI.Ticker#speed.
    Note: The cap may be exceeded by scaling.
    @default: 1
    */
  [@bs.get] external getDeltaTime: Js.t(#_t) => float = "deltaTime";

  /**
    Time elapsed in milliseconds from last frame to this frame. 
    Opposed to what the scalar PIXI.Ticker#deltaTime is based, this value is neither capped nor scaled. 
    If the platform supports DOMHighResTimeStamp, this value will have a precision of 1 µs. 
    @default: 16.66
  */
  [@bs.get] external getElapsedMS: Js.t(#_t) => float = "elapsedMS";

  /**
    The frames per second at which this ticker is running. 
    The default is approximately 60 in most modern browsers. 
    Note: This does not factor in the value of PIXI.Ticker#speed, which is specific to scaling PIXI.Ticker#deltaTime.
  */
  [@bs.get] external getFPS: Js.t(#_t) => float = "FPS";

  /**
    The last time PIXI.Ticker#update was invoked. 
    This value is also reset internally outside of invoking update, but only when a new animation frame is requested. 
    If the platform supports DOMHighResTimeStamp, this value will have a precision of 1 µs.
    @default: -1
  */
  [@bs.get] external getLastTime: Js.t(#_t) => float = "lastTime"; 

  /**
    Manages the minimum amount of milliseconds required to elapse between invoking PIXI.Ticker#update. 
    This will effect the measured value of PIXI.Ticker#FPS. 
    If it is set to 0, then there is no limit; PixiJS will render as many frames as it can. 
    Otherwise it will be at least minFPS
    @default: 0
  */
  [@bs.get] external getMaxFPS: Js.t(#_t) => float = "maxFPS";

  /**
    Manages the maximum amount of milliseconds allowed to elapse between invoking PIXI.Ticker#update. 
    This value is used to cap PIXI.Ticker#deltaTime, but does not effect the measured value of PIXI.Ticker#FPS. 
    When setting this property it is clamped to a value between 0 and PIXI.settings.TARGET_FPMS * 1000.
    @default: 10 
  */
  [@bs.get] external getMinFPS: Js.t(#_t) => float = "minFPS";

  /**
    Factor of current PIXI.Ticker#deltaTime.
    @default: 1
  */
  [@bs.get] external getSpeed: Js.t(#_t) => float = "speed";

  /**
    Factor of current PIXI.Ticker#deltaTime.
    @default: 1
  */
  [@bs.set] external setSpeed: (Js.t(#_t), float) => unit = "speed";

  /**
    Whether or not this ticker has been started. true if PIXI.Ticker#start has been called. false if PIXI.Ticker#stop has been called. While false, this value may change to true in the event of PIXI.Ticker#autoStart being true and a listener is added.
    @default: false
  */
  [@bs.get] external getStarted: Js.t(#_t) => bool = "started";

  /**
    Register a handler for tick events. Calls continuously unless it is removed or the ticker is stopped.
  */
  [@bs.send]
  external add: (Js.t(#_t) as 'a, [@bs.uncurry](float => unit), ~context: 'b=?, ~priority: int=?, unit) => 'a = "add";

  /**
    Add a handler for the tick event which is only execute once.
  */
  [@bs.send]
  external addOnce: (Js.t(#_t) as 'a, [@bs.uncurry](float => unit), ~context: 'b=?, ~priority: int=?, unit) => 'a = "addOnce";

  /**
    Destroy the ticker and don't use after this. Calling this method removes all references to internal events.
  */
  [@bs.send]
  external destroy: Js.t(#_t) => unit = "destroy";

  /**
    Removes any handlers matching the function and context parameters. If no handlers are left after removing, then it cancels the animation frame.
  */
  [@bs.send]
  external remove: (Js.t(#_t) as 'a, [@bs.uncurry](float => unit), ~context: 'b=?, unit) => 'a = "remove";

  /**
    Starts the ticker. If the ticker has listeners a new animation frame is requested at this point.
  */
  [@bs.send]
  external start: Js.t(#_t) => unit = "start";

  /**
   Stops the ticker. If the ticker has requested an animation frame it is canceled at this point.
  */
  [@bs.send]
  external stop: Js.t(#_t) => unit = "stop";

  /**
    Triggers an update. An update entails setting the current PIXI.Ticker#elapsedMS, 
    the current PIXI.Ticker#deltaTime, invoking all listeners with current deltaTime, 
    and then finally setting PIXI.Ticker#lastTime with the value of currentTime that was provided. 
    This method will be called automatically by animation frame callbacks if the ticker instance has been started and listeners are added.
  */
  [@bs.send]
  external update: (Js.t(#_t), ~currentTime: float=?, unit) => unit = "update";
}

include Impl;
