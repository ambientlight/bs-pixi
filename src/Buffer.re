class type _t = [@bs] {
  /**
    The data in the buffer, as a typed array
   */
  pub data: Js.Typed_array.ArrayBuffer.t;

  /**
    Destroys the buffer
   */
  pub destroy: unit => unit;

  /**
    disposes WebGL resources that are connected to this geometry
   */
  pub dispose: unit => unit;
  
  /**
    flags this buffer as requiring an upload to the GPU
   */
  pub update: Js.Typed_array.ArrayBuffer.t => unit;
};

/**
  A wrapper for data so that it can be used and uploaded by WebGL
 */
type t = Js.t(_t);

/**
  Helper function that creates a buffer based on an array or TypedArray ArrayBufferView
 */
[@bs.module "pixi.js"][@bs.scope "Buffer"]
external from: array(float) => t = "from";

module Impl {
  /**
    Note that SharedArrayBuffer was disabled by default in all major browsers on 5 January, 2018 
    in response to Spectre. Chrome re-enabled it in v67 on platforms where its site-isolation feature 
    is enabled to protect against Spectre-style vulnerabilities.
  */
  /* TODO: ArrayBuffer | ArrayBufferView */
  [@bs.module "pixi.js"][@bs.new]
  external create: (~data: Js.Typed_array.ArrayBuffer.t, ~_static: bool=?, ~index: bool=?, unit) => t = "Buffer";

  /**
    The data in the buffer, as a typed array
   */
  [@bs.get] external getData: Js.t(#_t) => Js.Typed_array.ArrayBuffer.t = "data";

  /**
    The data in the buffer, as a typed array
   */
  [@bs.set] external setData: (Js.t(#_t), Js.Typed_array.ArrayBuffer.t) => unit = "data";

  [@bs.send]
  external destroy: Js.t(#_t) => unit = "destroy";

  [@bs.send]
  external dispose: Js.t(#_t) => unit = "dispose";

  /* TODO: ArrayBuffer | ArrayBufferView */
  [@bs.send]
  external update: (Js.t(#_t), Js.Typed_array.ArrayBuffer.t) => unit = "update";
};

include Impl;