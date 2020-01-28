class type _t = [@bs] {
  /** The alpha value used when filling the Graphics object. */
  [@bs.set] pub alpha: float;
  /** The hex color value used when coloring the Graphics object. */
  [@bs.set] pub color: int;
  /** The transform applied to the texture. */
  [@bs.set] pub matrix: string;
  /** The texture to be used for the fill. */
  [@bs.set] pub texture: string;
  /** If the current fill is visible. */
  [@bs.set] pub visible: bool;

  /** Clones the object */
  pub clone: unit => Js.t(_t);
  /** Destroy and don't use after this */
  pub destroy: unit => unit;
  /** Reset */
  pub reset: unit => unit
};

type t = Js.t(_t);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: unit => t = "FillStyle";

  /** 
    Clones the object
  */
  [@bs.send] external clone: Js.t(#_t) => Js.t(#_t) = "clone";

  /**
    Destroy and don't use after this
  */
  [@bs.send] external destroy: Js.t(#_t) => unit = "destroy";

  /**
    Reset
  */
  [@bs.send] external reset: Js.t(#_t) => unit = "reset";
}

include Impl;