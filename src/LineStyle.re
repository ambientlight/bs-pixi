class type _t = [@bs] {
  inherit FillStyle._t;

  /** The alignment of any lines drawn (0.5 = middle, 1 = outter, 0 = inner). */
  [@bs.set] pub allignment: float;

  /** If true the lines will be draw using LINES instead of TRIANGLE_STRIP */
  [@bs.set] pub native: bool;

  /** The width (thickness) of any lines drawn. */
  [@bs.set] pub width: float;
};

type t = Js.t(_t);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: unit => t = "LineStyle";
}

include FillStyle.Impl;
include Impl;
