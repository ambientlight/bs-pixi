class type _t = [@bs] {
  inherit Mesh._t;

  /**
    re-calculate vertices by rope points each frame
   */
  [@bs.set] pub autoUpdate: bool;
};

/**
  The rope allows you to draw a texture across several points and then manipulate these points
 */
type t = Js.t(_t);

module Impl {
  /**
    creates new simple rope

      @param texture The texture to use on the rope.
      @param points An array of PIXI.Point objects to construct this rope.
      @param textureScale Positive values scale rope texture keeping its aspect ratio. You can reduce alpha channel artifacts by providing a larger texture and downsampling here. If set to zero, texture will be streched instead.
  */
  [@bs.module "pixi.js"][@bs.new]
  external create: (
    ~texture: Texture.t, 
    ~points: array(Point.t),
    ~textureScale: float=?,
    unit
  ) => Js.t(#_t) = "SimpleRope";

  /**
    re-calculate vertices by rope points each frame
  */
  [@bs.get] external getAutoUpdate: Js.t(#_t) => bool = "autoUpdate";

  /**
    re-calculate vertices by rope points each frame
  */
  [@bs.set] external setAutoUpdate: (Js.t(#_t), bool) => unit = "autoUpdate";
};

include EventEmitter.Impl;
include DisplayObject.Impl;
include Container.Impl;
include Mesh.Impl;
include Impl;