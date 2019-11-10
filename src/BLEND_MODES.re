[@bs.deriving jsConverter]
type t =
  | [@bs.as 0] Normal
  | [@bs.as 1] Add
  | [@bs.as 2] Multiply
  | [@bs.as 3] Screen
  | [@bs.as 4] Overlay
  | [@bs.as 5] Darken
  | [@bs.as 6] Lighten
  | [@bs.as 7] Color_dodge
  | [@bs.as 8] Color_burn
  | [@bs.as 9] Hard_light
  | [@bs.as 10] Soft_light
  | [@bs.as 11] Difference
  | [@bs.as 12] Exclusion
  | [@bs.as 13] Hue
  | [@bs.as 14] Saturation
  | [@bs.as 15] Color
  | [@bs.as 16] Luminosity
  | [@bs.as 17] Normal_npm
  | [@bs.as 18] Add_npm
  | [@bs.as 19] Screen_npm
  | [@bs.as 20] None
  /* TODO: [@bs.as 0] Src_over */
  | [@bs.as 21] Src_in
  | [@bs.as 22] Src_out
  | [@bs.as 23] Src_atop
  | [@bs.as 24] Dst_over
  | [@bs.as 25] Dst_in
  | [@bs.as 26] Dst_out
  | [@bs.as 27] Dst_atop
  /* TODO: [@bs.as 26] Erase */
  | [@bs.as 28] Subtract;

let normal = 0;
let add = 1;
let multiply = 2;
let screen = 3;
let overlay = 4;
let darken = 5;
let lighten = 6;
let color_dodge = 7;
let color_burn = 8;
let hard_light = 9;
let soft_light = 10;
let difference = 11;
let exclusion = 12;
let hue = 13;
let saturation = 14;
let color = 15;
let luminosity = 16;
let normal_npm = 17;
let add_npm = 18;
let screen_npm = 19;
let none = 20;

let src_over = 0;
let src_in = 21;
let src_out = 22;
let src_atop = 23;
let dst_over = 24;
let dst_in = 25;
let dst_out = 26;
let dst_atop = 27;
let erase = 26;
let subtract = 28;