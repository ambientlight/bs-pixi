/**
  FIXME: lack of support for https://github.com/BuckleScript/bucklescript/issues/3949
  doesn't allow recursive dependencies on JS-class bindings, so references to PIXI.Transform.t
  are rendered as anonymous types in Matrix context

  @see </PIXI/MatrixUtils-PIXI/> MatrixUtils
 */
type transformOpaque;

class type _t = [@bs] {
  /**
    x scale
   */
  [@bs.set] pub a: float;

  /**
    x skew
   */
  [@bs.set] pub b: float;

  /**
    y skew
   */
  [@bs.set] pub c: float;

  /**
    y scale
   */
  [@bs.set] pub d: float;

  /**
    x translation
   */
  [@bs.set] pub tx: float;

  /**
    y translation
   */
  [@bs.set] pub ty: float;

  /** 
    Appends the given Matrix to this Matrix.

      @param matrix The matrix to append.
      @return This matrix. Good for chaining method calls
   */
  pub append: Js.t(_t) => Js.t(_t);

  /**
    Get a new position with the current transformation applied. 
    Can be used to go from a child's coordinate space to the world coordinate space. (e.g. rendering)

      @deorecated consider using Matrix.apply instead
      @see </PIXI/Matrix-PIXI/#val-apply> Matrix.apply
      @param pos The origin
      @param newPos (optional) The point that the new position is assigned to (allowed to be same as input)
      @return The new point, transformed through this matrix
   */
  pub apply: (Point.t, Js.Undefined.t(Point.t)) => Point.t;

  /**
    Get a new position with the inverse of the current transformation applied. 
    Can be used to go from the world coordinate space to a child's coordinate space. (e.g. input)

      @deorecated consider using Matrix.applyInverse instead
      @see </PIXI/Matrix-PIXI/#val-applyInverse> Matrix.applyInverse
      @param pos The origin
      @param newPos (optional) The point that the new position is assigned to (allowed to be same as input)
      @return The new point, transformed through this matrix    
   */
  pub applyInverse: (Point.t, Js.Undefined.t(Point.t)) => Point.t;

  /**
    Creates a new Matrix object with the same values as this one.

      @return A copy of this matrix. Good for chaining method calls.
   */
  pub clone: unit => Js.t(_t);

  /**
    Changes the values of the matrix to be the same as the ones in given matrix

      @param matrix The matrix to copy from.
      @return itself
   */
  pub copyFrom: Js.t(_t) => Js.t(_t);

  /**
    Changes the values of the given matrix to be the same as the ones in this matrix

      @param matrix The matrix to copy to.
      @return The matrix given in parameter with its values updated.
   */
  pub copyTo: Js.t(_t) => Js.t(_t);

  /**
    Decomposes the matrix (x, y, scaleX, scaleY, and rotation) and sets the properties on to a transform.

      @deprecated Consider using MatrixUtils.decompose instead
      @see </PIXI/MatrixUtils-PIXI/#val-decompose> MatrixUtils.decompose
      @param transform The transform to apply the properties to
      @return The transform with the newly applied properties
   */
  pub decompose: transformOpaque => transformOpaque;

  /**
    Creates a Matrix object based on the given array. 
    The Element to Matrix mapping order is as follows
    a = array[0] b = array[1] c = array[3] d = array[4] tx = array[2] ty = array[5]

      @param array The array that the matrix will be populated from.
   */
  pub fromArray: array(float) => unit;

  /**
    Resets this Matrix to an identity (default) matrix.

      @return This matrix. Good for chaining method calls.
   */
  pub identity: unit => Js.t(_t);

  /**
    Inverts this matrix

      @return This matrix. Good for chaining method calls.
   */
  pub invert: unit => Js.t(_t);

  /**
    Prepends the given Matrix to this Matrix.

      @param The matrix to prepend
      @return This matrix. Good for chaining method calls.
   */
  pub prepend: Js.t(_t) => Js.t(_t);

  /**
    Applies a rotation transformation to the matrix.

      @param angle The angle in radians
      @return This matrix. Good for chaining method calls.
   */
  pub rotate: float => Js.t(_t);

  /**
    Applies a scale transformation to the matrix.

      @param x The amount to scale horizontally
      @param y The amount to scale vertically
      @return This matrix. Good for chaining method calls.
   */
  pub scale: (float, float) => Js.t(_t);

  /**
    sets the matrix properties

      @param a Matrix component
      @param b Matrix component
      @param c Matrix component
      @param d Matrix component
      @param tx Matrix component
      @param ty Matrix component
      @return This matrix. Good for chaining method calls
   */
  pub set: (float, float, float, float, float, float) => Js.t(_t);

  /**
    Sets the matrix based on all the available properties

      @param x Position on the x axis
      @param y Position on the y axis
      @param pivotX Pivot on the x axis
      @param pivotY Pivot on the y axis
      @param scaleX Scale on the x axis
      @param scaleY Scale on the y axis
      @param rotation rotation in radians
      @param skewX Skew on the x axis
      @param skewY Skew on the y axis
      @return This matrix. Good for chaining method calls.
   */
  pub setTransform: (float, float, float, float, float, float, float, float, float) => Js.t(_t);

  /**
    Creates an array from the current Matrix object

      @deprecated Consider using Matrix.toArray
      @see </PIXI/Matrix-PIXI/#val-toArray> Matrix.toArray
      @param transpose Whether we need to transpose the matrix or not
      @param out (optional) If provided the array will be assigned to out
      @return the newly created array which contains the matrix
   */
  pub toArray: (bool, Js.Undefined.t(Js.Typed_array.Float32Array.t)) => array(float);

  /**
    Translates the matrix on the x and y

      @param x How much to translate x by
      @param y How much to translate y by
      @return This matrix. Good for chaining method calls.
   */
  pub translate: (float, float) => Js.t(_t);
};

/**
  The PixiJS Matrix as a class makes it a lot faster (to work with matrixes).
  Here is a representation of it:

  | a | c | tx|
  | b | d | ty|
  | 0 | 0 | 1 |
 */
type t = Js.t(_t);

/**
  creates a new matrix

    @param a x scale (default 1)
    @param b x skew (default 0)
    @param c y skew (default 0)
    @param d y scale (default 1)
    @param tx x translation (default 0)
    @param ty y translation (default 0)
 */
[@bs.module "pixi.js"][@bs.new]
external create: (~a:float=?, ~b:float=?, ~c:float=?, ~d:float=?, ~tx:float=?, ~ty:float=?, unit) => t = "Matrix";

/**
  A default (identity) matrix
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Matrix"]
external identity: t = "IDENTITY";

/**
  A temp matrix
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Matrix"]
external tempMatrix: t = "TEMP_MATRIX";

/**
  x scale
 */
[@bs.get] external getA: Js.t(#_t) => float = "a";

/**
  x scale
 */
[@bs.set] external setA: (Js.t(#_t), float) => unit = "a";

/**
  x skew
 */
[@bs.get] external getB: Js.t(#_t) => float = "b";

/**
  x skew
 */
[@bs.set] external setB: (Js.t(#_t), float) => unit = "b";

/**
  y skew
 */
[@bs.get] external getC: Js.t(#_t) => float = "c";

/**
  y skew
 */
[@bs.set] external setC: (Js.t(#_t), float) => unit = "c";

/**
  y scale
 */
[@bs.get] external getD: Js.t(#_t) => float = "d";

/**
  y scale
 */
[@bs.set] external setD: (Js.t(#_t), float) => unit = "d";

/**
  x translation
 */
[@bs.get] external getTx: Js.t(#_t) => float = "tx";

/**
  x translation
 */
[@bs.set] external setTx: (Js.t(#_t), float) => unit = "tx";

/**
  y translation
 */
[@bs.get] external getTy: Js.t(#_t) => float = "ty";

/**
  y translation
 */
[@bs.set] external setTy: (Js.t(#_t), float) => unit = "ty";

/** 
  Appends the given Matrix to this Matrix.

    @param matrix The matrix to append.
    @return This matrix. Good for chaining method calls
  */
[@bs.send]
external append: (Js.t(#_t), ~matrix: Js.t(#_t)) => Js.t(#_t) = "append";

/**
  Get a new position with the current transformation applied. 
  Can be used to go from a child's coordinate space to the world coordinate space. (e.g. rendering)

    @param pos The origin
    @param newPos The point that the new position is assigned to (allowed to be same as input)
    @return The new point, transformed through this matrix
  */
[@bs.send]
external apply: (Js.t(#_t), ~pos: Js.t(#Point._t), ~newPos: Js.t(#Point._t)=?, unit) => Js.t(#Point._t) = "apply";

/**
  Get a new position with the inverse of the current transformation applied. 
  Can be used to go from the world coordinate space to a child's coordinate space. (e.g. input)

    @param pos The origin
    @param newPos (optional) The point that the new position is assigned to (allowed to be same as input)
    @return The new point, transformed through this matrix    
  */
[@bs.send]
external applyInverse: (Js.t(#_t), ~pos: Js.t(#Point._t), ~newPos: Js.t(#Point._t)=?, unit) => Js.t(#Point._t) = "applyInverse";

/**
  Creates a new Matrix object with the same values as this one.

    @return A copy of this matrix. Good for chaining method calls.
  */
[@bs.send]
external clone: Js.t(#_t) => Js.t(#_t) = "clone";

/**
  Changes the values of the matrix to be the same as the ones in given matrix

    @param matrix The matrix to copy from.
    @return itself
  */
[@bs.send]
external copyFrom: (Js.t(#_t), ~matrix: Js.t(#_t)) => Js.t(#_t) = "copyFrom";

/**
  Changes the values of the given matrix to be the same as the ones in this matrix

    @param matrix The matrix to copy to.
    @return The matrix given in parameter with its values updated.
  */
[@bs.send]
external copyTo: (Js.t(#_t), ~matrix: Js.t(#_t)) => Js.t(#_t) = "copyTo";

/**
  Decomposes the matrix (x, y, scaleX, scaleY, and rotation) and sets the properties on to a transform.

    @deprecated Consider using MatrixUtils.decompose instead
    @see </PIXI/MatrixUtils-PIXI/#val-decompose> MatrixUtils.decompose
    @param transform The transform to apply the properties to
    @return The transform with the newly applied properties
  */
[@bs.send]
external decompose: (Js.t(#_t), ~transform: transformOpaque) => transformOpaque = "decompose";

/**
  Creates a Matrix object based on the given array. 
  The Element to Matrix mapping order is as follows
  a = array[0] b = array[1] c = array[3] d = array[4] tx = array[2] ty = array[5]

    @param array The array that the matrix will be populated from.
  */
[@bs.send]
external fromArray: (Js.t(#_t), ~array: array(float)) => unit = "fromArray";

/**
  Resets this Matrix to an identity (default) matrix.

    @return This matrix. Good for chaining method calls.
  */
[@bs.send]
external identity: Js.t(#_t) => Js.t(#_t) = "identity";

/**
  Inverts this matrix

    @return This matrix. Good for chaining method calls.
  */
[@bs.send]
external invert: Js.t(#_t) => Js.t(#_t) = "invert";

/**
  Prepends the given Matrix to this Matrix.

    @param The matrix to prepend
    @return This matrix. Good for chaining method calls.
  */
[@bs.send]
external prepend: (Js.t(#_t), ~matrix: Js.t(#_t)) => Js.t(#_t) = "prepend";

/**
  Applies a rotation transformation to the matrix.

    @param angle The angle in radians
    @return This matrix. Good for chaining method calls.
  */
[@bs.send]
external rotate: (Js.t(#_t), ~angle: float) => Js.t(#_t) = "rotate";

/**
  Applies a scale transformation to the matrix.

    @param x The amount to scale horizontally
    @param y The amount to scale vertically
    @return This matrix. Good for chaining method calls.
  */
[@bs.send]
external scale: (Js.t(#_t), ~x: float, ~y: float) => Js.t(#_t) = "scale";

/**
  sets the matrix properties

    @param a Matrix component
    @param b Matrix component
    @param c Matrix component
    @param d Matrix component
    @param tx Matrix component
    @param ty Matrix component
    @return This matrix. Good for chaining method calls
  */
[@bs.send]
external set: (t, ~a: float, ~b: float, ~c: float, ~d: float, ~tx: float, ~ty: float) => t = "set";

/**
  Sets the matrix based on all the available properties

    @param x Position on the x axis
    @param y Position on the y axis
    @param pivotX Pivot on the x axis
    @param pivotY Pivot on the y axis
    @param scaleX Scale on the x axis
    @param scaleY Scale on the y axis
    @param rotation rotation in radians
    @param skewX Skew on the x axis
    @param skewY Skew on the y axis
    @return This matrix. Good for chaining method calls.
  */
[@bs.send]
external setTransform: (t, ~x: float, ~y: float, ~pivotX: float, ~pivotY: float, ~scaleX: float, ~scaleY: float, ~rotation: float, ~skewX: float, ~skewY: float) => t = "setTransform";

/**
  Creates an array from the current Matrix object

    @param transpose Whether we need to transpose the matrix or not
    @param out (optional) If provided the array will be assigned to out
    @return the newly created array which contains the matrix
  */
[@bs.send]
external toArray: (t, ~transpose: bool, ~out: Js.Typed_array.Float32Array.t=?, unit) => array(float) = "toArray";

/**
  Translates the matrix on the x and y

    @param x How much to translate x by
    @param y How much to translate y by
    @return This matrix. Good for chaining method calls.
  */
[@bs.send]
external translate: (t, ~x: float, ~y: float) => t = "translate";