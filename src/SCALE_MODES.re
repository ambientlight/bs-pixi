/**
  The scale modes that are supported by pixi.

  The PIXI.settings.SCALE_MODE scale mode affects the default scaling mode of future operations.
  It can be re-assigned to either LINEAR or NEAREST, depending upon suitability.
  Ref: https://github.com/pixijs/pixi.js/blob/dev/packages/constants/src/index.ts#L267
 */
[@bs.deriving jsConverter]
type t =
  | [@bs.as 0] Nearest
  | [@bs.as 1] Linear;

/**
  Pixelating scaling
 */
let nearest = 0;

/**
  Smooth scaling
 */
let linear = 1;
