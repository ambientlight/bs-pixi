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