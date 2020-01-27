class type _t = [@bs] {
  /**
    position of the point on the x axis
   */
  [@bs.set] pub x: float;

  /**
    position of the point on the y axis
   */
  [@bs.set] pub y: float;

  /**
    Creates a clone of this point

      @param (optional) cb callback when changed
      @param (optional) scope owner of callback
      @return a copy of the point
   */
  pub clone: (Js.Null.t(unit => unit), Js.Null.t(Js.t({..}))) => Js.t(_t);

  /**
    Copies x and y from the given point
    
      @deprecated consider using IPoint.copyFrom instead for Point support
      @see </bs-pixi/PIXI/IPoint-PIXI/#val-copyFrom> IPoint.copyFrom
      @param p The point to copy from
      @return itself
   */
  pub copyFrom: Js.t(_t) => Js.t(_t);

  /**
    Copies x and y into the given point
    
      @deprecated consider using IPoint.copyTo instead for Point support
      @see </bs-pixi/PIXI/IPoint-PIXI/#val-copyTo> IPoint.copyTo
      @param p The point to copy
      @return Given point with values updated
   */
  pub copyTo: Js.t(_t) => Js.t(_t);

  /**
    Returns true if the given point is equal to this point

      @deprecated consider using IPoint.equals instead for Point support
      @see </bs-pixi/PIXI/IPoint-PIXI/#val-equals> IPoint.equals
      @param p The point to check
      @return Whether the given point equal to this point
   */
  pub equals: Js.t(_t) => bool;


  /**
    Sets the point to a new x and y position. 
    If y is omitted, both x and y will be set to x.

      @deprecated consider using ObservablePoint.set instead
      @see </bs-pixi/PIXI/ObservablePoint-PIXI/#val-set> ObservablePoint.set
      @param x position of the point on the x axis
      @param y position of the point on the y axis
   */
  pub set: (float, float) => unit;
};

/**
  The Point object represents a location in a two-dimensional coordinate system, 
  where x represents the horizontal axis and y represents the vertical axis.
  
  An ObservablePoint is a point that triggers a callback when the point's position is changed.
 */
type t = Js.t(_t);

module Impl {
  /**
    creates a new observable point

      @param cb callback when changed
      @param scope owner of callback
      @param x position of the point on the x axis
      @param y position of the point on the y axis
      @return new point
  */
  [@bs.module "pixi.js"][@bs.new]
  external create: (~cb: unit => unit, ~scope: 'a=?, ~x: float=?, ~y: float=?, unit) => Js.t(#_t) = "ObservablePoint";

  /**
    position of the point on the x axis
  */
  [@bs.get] external getX: Js.t(#_t) => float = "x";

  /**
    position of the point on the x axis
  */
  [@bs.set] external setX: (Js.t(#_t), float) => unit = "x";

  /**
    position of the point on the y axis
  */
  [@bs.get] external getY: Js.t(#_t) => float = "y";

  /**
    position of the point on the y axis
  */
  [@bs.set] external setY: (Js.t(#_t), float) => unit = "y";

  /**
    Creates a clone of this point

      @param cb callback when changed
      @param scope owner of callback
      @return a copy of the point
  */
  [@bs.send]
  external clone: (Js.t(#_t), ~cb:(unit=>unit)=?, ~scope:'a=?, unit) => Js.t(#_t) = "clone";

  /**
    Copies x and y from the given point
      
      @deprecated consider using IPoint.copyFrom instead for Point support
      @see </bs-pixi/PIXI/IPoint-PIXI/#val-copyFrom> IPoint.copyFrom
      @param p The point to copy from
      @return itself
  */
  [@bs.send]
  external copyFrom: (Js.t(#_t), ~p: Js.t(#_t)) => Js.t(#_t) = "copyFrom";

  /**
    Copies x and y into the given point
      
      @deprecated consider using IPoint.copyTo instead for Point support
      @see </bs-pixi/PIXI/IPoint-PIXI/#val-copyTo> IPoint.copyTo
      @param p The point to copy
      @return Given point with values updated
  */
  [@bs.send]
  external copyTo: (Js.t(#_t), ~p: Js.t(#_t)) => Js.t(#_t) = "copyTo";

  /**
    Returns true if the given point is equal to this point

      @deprecated consider using IPoint.equals instead for Point support
      @see </bs-pixi/PIXI/IPoint-PIXI/#val-equals> IPoint.equals
      @param p The point to check
      @return Whether the given point equal to this point
  */
  [@bs.send]
  external equals: (Js.t(#_t), ~p: Js.t(#_t)) => bool = "equals";

  /**
    Sets the point to a new x and y position. 
    If y is omitted, both x and y will be set to x.
  
      @param x position of the point on the x axis
      @param y position of the point on the y axis
  */
  [@bs.send]
  external set: (Js.t(#_t), ~x: float=?, ~y: float=?, unit) => unit = "set";
}

include Impl;