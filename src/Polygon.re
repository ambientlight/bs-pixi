class type _t = [@bs] {
  /** 
    false after moveTo, true after closePath. In all other cases it is true. 
   */
  [@bs.set] pub closeStroke: bool;

  /**  
    An array of the points of this polygon
   */
  [@bs.set] pub points: array(float);

  /** 
    Creates a clone of this polygon 
   */
  pub clone: unit => Js.t(_t);

  /**
    Checks whether the x and y coordinates passed to this function are contained within this polygon
   */
  pub contains: (float, float) => bool;
};

/** 
  A class to define a shape via user defined co-orinates.
 */
type t = Js.t(_t);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: ([@bs.unwrap][
    | `Point(array(Js.t(#Point._t)))
    | `Array(array(float))
    | `Array2d(array(array(float)))
  ]) => t = "Polygon";

  /** 
    false after moveTo, true after closePath. In all other cases it is true. 
   */
  [@bs.get] external getCloseStroke: Js.t(#_t) => bool = "getCloseStroke";

  /** 
    false after moveTo, true after closePath. In all other cases it is true. 
   */
  [@bs.set] external setCloseStroke: (Js.t(#_t), bool) => unit = "setCloseStroke";

  /** 
    An array of the points of this polygon 
   */
  [@bs.get] external getPoints: Js.t(#_t) => array(float) = "points";

  /** 
    An array of the points of this polygon
   */
  [@bs.set] external setPoints: (Js.t(#_t), array(float)) => unit = "points";

  [@bs.get] external _getType: Js.t(#_t) => int = "type";

  /**
    The type of the object, mainly used to avoid instanceof checks
   */
  let getType = polygon => polygon |. _getType |. SHAPES.tFromJs |. Belt.Option.getExn;

  /** 
    Creates a clone of this polygon 
   */
  [@bs.send] external clone: Js.t(#_t) => Js.t(#_t) = "clone";

  /**
    Checks whether the x and y coordinates passed to this function are contained within this polygon
   */
  [@bs.send] external contains: (Js.t(#_t), ~x: float, ~y: float) => bool = "contains"
};

include Impl;

