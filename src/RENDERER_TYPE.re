[@bs.deriving jsConverter]
type t =
  | [@bs.as 0] Unknown
  | [@bs.as 1] WebGL
  | [@bs.as 2] Canvas;

/** Unknown render type */
let unknown = 0;
/** WebGL render type */
let webGL = 1;
/** Canvas render type */
let canvas = 2;
