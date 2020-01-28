class type _t = [@bs] {
  
  [@bs.set] pub radius: float;

  [@bs.set] pub x: float;
  [@bs.set] pub y: float;

  /** 
    Creates a clone of this circle 
   */
  pub clone: unit => Js.t(_t);

  /**
    Checks whether the x and y coordinates passed to this function are contained within this circle
   */
  pub contains: (float, float) => bool;

  /**
    Returns the framing rectangle of the circle as a Rectangle object
   */
  pub getBounds: unit => Rectangle.t;
};

/** 
  The Circle object is used to help draw graphics and can also be used to specify a hit area for displayObjects.
 */
type t = Js.t(_t);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: (~x: float=?, ~y: float=?, ~radius: float=?, unit) => t = "Circle";

  [@bs.get] external getRadius: Js.t(#_t) => float = "radius";
  [@bs.set] external setRadius: (Js.t(#_t), float) => unit = "radius";

  /**
    position of the circle on the x axis
  */
  [@bs.get] external getX: Js.t(#_t) => float = "x";

  /**
    position of the circle on the x axis
  */
  [@bs.set] external setX: (Js.t(#_t), float) => unit = "x";

  /**
    position of the circle on the y axis
  */
  [@bs.get] external getY: Js.t(#_t) => float = "y";

  /**
    position of the circle on the y axis
  */
  [@bs.set] external setY: (Js.t(#_t), float) => unit = "y";

  [@bs.get] external _getType: Js.t(#_t) => int = "type";

  /**
    The type of the object, mainly used to avoid instanceof checks
   */
  let getType = circle => circle |. _getType |. SHAPES.tFromJs |. Belt.Option.getExn;

  /** 
    Creates a clone of this polygon 
   */
  [@bs.send] external clone: Js.t(#_t) => Js.t(#_t) = "clone";

  /**
    Checks whether the x and y coordinates passed to this function are contained within this polygon
   */
  [@bs.send] external contains: (Js.t(#_t), ~x: float, ~y: float) => bool = "contains";

  /**
    Returns the framing rectangle of the circle as a Rectangle object
   */
  [@bs.send] external getBounds: Js.t(#_t) => Js.t(#Rectangle._t) = "getBounds";
};

include Impl;

