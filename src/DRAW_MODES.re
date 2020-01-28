[@bs.deriving jsConverter]
type t = 
  | [@bs.as 0] Points
  | [@bs.as 1] Lines
  | [@bs.as 2] LineLoop
  | [@bs.as 3] LineStrip
  | [@bs.as 4] Triangles
  | [@bs.as 5] TriangleStrip
  | [@bs.as 6] TriangleFan;

let points = 0;
let lines = 1;
let line_loop = 2;
let line_strip = 3;
let triangles = 4;
let triangle_strip = 5;
let triangle_fan = 6;