class type _t = [@bs] {
  /**
    returns the bottom edge of the rectangle
   */
  pub bottom: float;

  /**
    rectangle hight
   */
  [@bs.set] pub height: float;

  /**
    returns the left edge of the rectangle
   */
  pub left: float;
  
  /**
    returns the right edge of the rectangle
   */
  pub right: float;

  /**
    returns the top edge of the rectangle
   */
  pub top: float;

  /* no [bs.as] support here for now, use module level accessor */
  /* [@bs.as "type"] pub type_: string; */

  /**
    rectangle width
   */
  [@bs.set] pub width: float;

  /**
    The X coordinate of the upper-left corner of the rectangle
   */
  [@bs.set] pub x: float;

  /**
    The Y coordinate of the upper-left corner of the rectangle
   */
  [@bs.set] pub y: float;

  /**
    Enlarges rectangle that way its corners lie on grid

      @deprecated consider using Rectangle.ceil instead
      @see </PIXI/Rectangle-PIXI/#val-ceil> Rectangle.ceil
      @param (optional) resolution resolution
      @param (optional) eps eps
      @return itself
   */
  pub ceil: (Js.Undefined.t(float), Js.Undefined.t(float)) => Js.t(_t);

  /**
    Creates a clone of this Rectangle

      @return a copy of the rectangle
   */
  pub clone: unit => Js.t(_t);

  /**
    Checks whether the x and y coordinates given are contained within this Rectangle

      @param x The X coordinate of the point to test
      @param y The Y coordinate of the point to test
      @return Whether the x/y coordinates are within this Rectangle
   */
  pub contains: (float, float) => bool;

  /** 
    Copies another rectangle to this one.

      @param rectangle The rectangle to copy from.
      @return itself
   */
  pub copyFrom: Js.t(_t) => Js.t(_t);

  /**
    Copies this rectangle to another one.

      @param The rectangle to copy to
      @return returns updated rectangle that was passed as parameter
   */
  pub copyTo: Js.t(_t) => Js.t(_t);

  /**
    Enlarges this rectangle to include the passed rectangle

      @param rectangle The rectangle to include
      @return itself
   */
  pub enlarge: Js.t(_t) => Js.t(_t);

  /**
    Fits this rectangle around the passed one

      @param rectangle The rectangle to fit
      @return itself
   */
  pub fit: Js.t(_t) => Js.t(_t);

  /**
    Pads the rectangle making it grow in all directions. 
    If paddingY is omitted, both paddingX and paddingY will be set to paddingX.

      @deprecated Consider using Rectangle.pad instead
      @see </PIXI/Rectangle-PIXI/#val-pad> Rectangle.pad
      @param paddingX The horizontal padding amount
      @param paddingY The vertical padding amount
      @return itself
   */
  pub pad: (Js.Undefined.t(float), Js.Undefined.t(float)) => Js.t(_t);
};

/**
  Rectangle object is an area defined by its position, 
  as indicated by its top-left corner point (x, y) and by its width and its height.
 */
type t = Js.t(_t);

/**
  creates new rectangle

    @param x The X coordinate of the upper-left corner of the rectangle
    @param y The Y coordinate of the upper-left corner of the rectangle
    @param width The overall width of this rectangle
    @param heigth The overall height of this rectangle
 */
[@bs.module "pixi.js"][@bs.new]
external create: (
  ~x: float=?, 
  ~y: float=?, 
  ~width: float=?, 
  ~height: float=?, 
  unit) => t = "Rectangle";

/**
  A constant empty rectangle
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Rectangle"]
external empty: Js.t(#_t) = "EMPTY";

/**
  the bottom edge of the rectangle
 */
[@bs.get] external getBottom: Js.t(#_t) => float = "bottom";

/**
  rectangle height
 */
[@bs.get] external getHeight: Js.t(#_t) => float = "height";

/**
  rectangle height
 */
[@bs.set] external setHeight: (Js.t(#_t), float) => unit = "height";

/**
  the left edge of the rectangle
 */
[@bs.get] external getLeft: Js.t(#_t) => float = "left";

/**
  the right edge of the rectangle
 */
[@bs.get] external getRight: Js.t(#_t) => float = "right";

/**
  the top edge of the rectangle
 */
[@bs.get] external getTop: Js.t(#_t) => float = "top";


[@bs.get]
external _getType: t => int = "type";

/**
  The type of the object, mainly used to avoid instanceof checks
 */
let getType = rect => rect |. _getType |. SHAPES.tFromJs |. Belt.Option.getExn;

/**
  rectangle width
 */
[@bs.get] external getWidth: Js.t(#_t) => float = "width";

/**
  rectangle width
 */
[@bs.set] external setWidth: (Js.t(#_t), float) => unit = "width";

/**
  The X coordinate of the upper-left corner of the rectangle
 */
[@bs.get] external getX: Js.t(#_t) => float = "x";

/**
  The X coordinate of the upper-left corner of the rectangle
 */
[@bs.set] external setX: (Js.t(#_t), float) => unit = "x";

/**
  The Y coordinate of the upper-left corner of the rectangle
 */
[@bs.get] external getY: Js.t(#_t) => float = "y";

/**
  The Y coordinate of the upper-left corner of the rectangle
 */
[@bs.set] external setY: (Js.t(#_t), float) => unit = "y";

/**
  Enlarges rectangle that way its corners lie on grid

    @param resolution resolution
    @param eps eps
    @return itself
  */
[@bs.send]
external ceil: (Js.t(#_t), ~resolution:float=?, ~eps:float=?, unit) => Js.t(#_t) = "ceil";

/**
  Creates a clone of this Rectangle

    @return a copy of the rectangle
  */
[@bs.send]
external clone: Js.t(#_t) => Js.t(#_t) = "clone";

/**
  Checks whether the x and y coordinates given are contained within this Rectangle

    @param x The X coordinate of the point to test
    @param y The Y coordinate of the point to test
    @return Whether the x/y coordinates are within this Rectangle
  */
[@bs.send]
external contains: (Js.t(#_t), ~x: float, ~y: float) => bool = "contains";

/** 
  Copies another rectangle to this one.

    @param rectangle The rectangle to copy from.
    @return itself
  */
[@bs.send]
external copyFrom: (Js.t(#_t), ~rectangle: Js.t(#_t)) => Js.t(#_t) = "copyFrom";

/**
  Copies this rectangle to another one.

    @param The rectangle to copy to
    @return returns updated rectangle that was passed as parameter
  */
[@bs.send]
external copyTo: (Js.t(#_t), ~rectangle: Js.t(#_t)) => Js.t(#_t) = "copyTo";

/**
  Enlarges this rectangle to include the passed rectangle

    @param rectangle The rectangle to include
    @return itself
  */
[@bs.send]
external enlarge: (Js.t(#_t), ~rectangle: Js.t(#_t)) => Js.t(#_t) = "enlarge";

/**
  Fits this rectangle around the passed one

    @param rectangle The rectangle to fit
    @return itself
  */
[@bs.send]
external fit: (Js.t(#_t), ~rectangle: Js.t(#_t)) => Js.t(#_t) = "fit";

/**
  Pads the rectangle making it grow in all directions. 
  If paddingY is omitted, both paddingX and paddingY will be set to paddingX.

    @param paddingX The horizontal padding amount
    @param paddingY The vertical padding amount
    @return itself
  */
[@bs.send]
external pad: (Js.t(#_t), ~paddingX: float=?, ~paddingY: float=?, unit) => Js.t(#_t) = "pad";