/**
  Constants that identify shapes, mainly to prevent instanceof calls
 */
[@bs.deriving jsConverter]
type t =
  | [@bs.as 0] Poly
  | [@bs.as 1] Rect
  | [@bs.as 2] Circ
  | [@bs.as 3] Elip
  | [@bs.as 4] Rrec;

/** polygon */
let poly = 0;
/** rectangle */
let rect = 1;
/** circle */
let circle = 2;
/** elip */
let elip = 3;
/** rounded rectangle */
let rrec = 4;