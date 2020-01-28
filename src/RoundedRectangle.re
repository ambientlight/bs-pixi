class type _t = [@bs] {
  [@bs.set] pub height: float;

  /** 
    Controls the radius of the rounded corners
   */
  [@bs.set] pub radius: float;

  [@bs.set] pub width: float;
  [@bs.set] pub x: float;
  [@bs.set] pub y: float;

  /** 
    Creates a clone of this rounded rectangle 
   */
  pub clone: unit => Js.t(_t);

  /**
    Checks whether the x and y coordinates passed to this function are contained within this rounded rectangle
   */
  pub contains: (float, float) => bool;
};

/**
  The Rounded Rectangle object is an area that has nice rounded corners, 
  as indicated by its top-left corner point (x, y) and by its width and its height and its radius.
 */
type t = Js.t(_t);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: (~x: float=?, ~y: float=?, ~width: float=?, ~height: float=?, ~radius: float=?, unit) => t = "RoundedRectangle";

  [@bs.get] external getHeight: Js.t(#_t) => float = "height";
  [@bs.set] external setHeight: (Js.t(#_t), float) => unit = "height";
  [@bs.get] external getWidth: Js.t(#_t) => float = "width";
  [@bs.set] external setWidth: (Js.t(#_t), float) => unit = "width";

  /**
    Controls the radius of the rounded corners
   */    
  [@bs.get] external getRadius: Js.t(#_t) => float = "radius";

  /**
    Controls the radius of the rounded corners
   */
  [@bs.set] external setRadius: (Js.t(#_t), float) => unit = "radius";

  [@bs.get] external _getType: Js.t(#_t) => int = "type";

  /**
    The type of the object, mainly used to avoid instanceof checks
   */
  let getType = roundedRect => roundedRect |. _getType |. SHAPES.tFromJs |. Belt.Option.getExn;

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
    Creates a clone of this rounded rectangle 
   */
  [@bs.send] external clone: Js.t(#_t) => Js.t(#_t) = "clone";

  /**
    Checks whether the x and y coordinates passed to this function are contained within this rounded rectangle
   */
  [@bs.send] external contains: (Js.t(#_t), ~x: float, ~y: float) => bool = "contains";
};

include Impl;