class type _t = [@bs] {
  [@bs.set] pub height: float;
  [@bs.set] pub width: float;
  [@bs.set] pub x: float;
  [@bs.set] pub y: float;

  /** 
    Creates a clone of this ellipse 
   */
  pub clone: unit => Js.t(_t);

  /**
    Checks whether the x and y coordinates passed to this function are contained within this ellipse
   */
  pub contains: (float, float) => bool;

  /**
    Returns the framing rectangle of the ellipse as a Rectangle object
   */
  pub getBounds: unit => Rectangle.t;
};

/**
  The Ellipse object is used to help draw graphics and can also be used to specify a hit area for displayObjects.
 */
type t = Js.t(_t);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: (~x: float=?, ~y: float=?, ~halfWidth: float=?, ~halfHeight: float=?, unit) => t = "Ellipse";

  [@bs.get] external getHeight: Js.t(#_t) => float = "height";
  [@bs.set] external setHeight: (Js.t(#_t), float) => unit = "height";
  [@bs.get] external getWidth: Js.t(#_t) => float = "width";
  [@bs.set] external setWidth: (Js.t(#_t), float) => unit = "width";

  [@bs.get] external _getType: Js.t(#_t) => int = "type";

  /**
    The type of the object, mainly used to avoid instanceof checks
   */
  let getType = ellipse => ellipse |. _getType |. SHAPES.tFromJs |. Belt.Option.getExn;

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

  /** 
    Creates a clone of this ellipse 
   */
  [@bs.send] external clone: Js.t(#_t) => Js.t(#_t) = "clone";

  /**
    Checks whether the x and y coordinates passed to this function are contained within this ellipse
   */
  [@bs.send] external contains: (Js.t(#_t), ~x: float, ~y: float) => bool = "contains";

  /**
    Returns the framing rectangle of the ellipse as a Rectangle object
   */
  [@bs.send] external getBounds: Js.t(#_t) => Js.t(#Rectangle._t) = "getBounds";
};

include Impl;