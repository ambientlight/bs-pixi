/**
  The scale modes that are supported by pixi.

  The PIXI.settings.SCALE_MODE scale mode affects the default scaling mode of future operations. 
  It can be re-assigned to either LINEAR or NEAREST, depending upon suitability.
 */
[@bs.deriving jsConverter]
type t = 
  | [@bs.as 0] Linear
  | [@bs.as 1] Nearest;

/**
  Smooth scaling
 */
let linear = 0;

/**
  Pixelating scaling
 */
let nearest = 1;