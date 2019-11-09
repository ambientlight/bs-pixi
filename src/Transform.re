class type _t = [@bs] {
  /**
    The local transformation matrix.
   */
  [@bs.set] pub localTranform: Matrix.t;

  /**
    The pivot point of the displayObject that it rotates around
   */
  [@bs.set] pub pivot: ObservablePoint.t;

  /**
    The coordinate of the object relative to the local coordinates of the parent
   */
  [@bs.set] pub position: ObservablePoint.t;

  /**
    The rotation of the object in radians
   */
  [@bs.set] pub rotation: float;

  /**
    The scale factor of the object
   */
  [@bs.set] pub scale: ObservablePoint.t;

  /**
    The skew amount, on the x and y axis
   */
  [@bs.set] pub skew: ObservablePoint.t;

  /**
    The world transformation matrix
   */
  [@bs.set] pub worldTransform: Matrix.t;

  /**
    Decomposes a matrix and sets the transforms properties based on it

      @param matrix The matrix to decompose
   */
  pub setFromMatrix: Matrix.t => unit;

  /**
    Updates the local transformation matrix
   */
  pub updateLocalTransform: unit => unit;

  /**
    Updates the local and the world transformation matrices

      @param parentTransform The parent transform
   */
  pub updateTransform: Js.t(_t) => unit;
};

type t = Js.t(_t);

/**
  creates new transform
 */
[@bs.module "pixi.js"][@bs.new]
external create: unit => t = "Transform";

/**
  A default (identity) transform
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Transform"]
external identity: Js.t(#_t) = "IDENTITY";

/**
  The local transformation matrix
 */
[@bs.get] external getLocalTransform: Js.t(#_t) => Js.t(#Matrix._t) = "localTransform";

/**
  The local transformation matrix
 */
[@bs.set] external setLocalTransform: (Js.t(#_t), Js.t(#Matrix._t)) => unit = "localTransform";

/**
  The pivot point of the displayObject that it rotates around.
 */
[@bs.get] external getPivot: Js.t(#_t) => Js.t(#ObservablePoint._t) = "pivot";

/**
  The pivot point of the displayObject that it rotates around.
 */
[@bs.set] external setPivot: (Js.t(#_t), Js.t(#ObservablePoint._t)) => unit = "pivot";

/**
  The coordinate of the object relative to the local coordinates of the parent
 */
[@bs.get] external getPosition: Js.t(#_t) => Js.t(#ObservablePoint._t) = "position";

/**
  The coordinate of the object relative to the local coordinates of the parent
 */
[@bs.set] external setPosition: (Js.t(#_t), Js.t(#ObservablePoint._t)) => unit = "position";

/**
  The rotation of the object in radians.
 */
[@bs.get] external getRotation: Js.t(#_t) => float = "rotation";

/**
  The rotation of the object in radians.
 */
[@bs.set] external setRotation: (Js.t(#_t), float) => unit = "rotation";

/**
  The scale factor of the object.
 */
[@bs.get] external getScale: Js.t(#_t) => float = "scale";

/**
  The scale factor of the object.
 */
[@bs.set] external setScale: (Js.t(#_t), float) => unit = "scale";

/**
  The skew factor of the object.
 */
[@bs.get] external getSkew: Js.t(#_t) => float = "skew";

/**
  The skew factor of the object.
 */
[@bs.set] external setSkew: (Js.t(#_t), float) => unit = "skew";

/**
  The world transformation matrix
 */
[@bs.get] external getWorldTransform: Js.t(#_t) => Js.t(#Matrix._t) = "worldTransform";

/**
  The world transformation matrix
 */
[@bs.set] external setWorldTransform: (Js.t(#_t), Js.t(#Matrix._t)) => unit = "worldTransform";


/**
  Decomposes a matrix and sets the transforms properties based on it

    @param matrix The matrix to decompose
 */
[@bs.send]
external setFromMatrix: (Js.t(#_t), ~matrix: Js.t(#Matrix._t)) => unit = "setFromMatrix";

/**
  Updates the local transformation matrix
 */
[@bs.send]
external updateLocalTransform: Js.t(#_t) => unit = "updateLocalTransform";

/**
  Updates the local and the world transformation matrices

    @param parentTransform The parent transform
 */
[@bs.send]
external updateTransform: (Js.t(#_t), ~parentTransform: Js.t(#_t)) => unit = "updateTransform";
