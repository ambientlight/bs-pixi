[@bs.deriving jsConverter]
type t = 
  | [@bs.as 6408] RGBA
  | [@bs.as 6407] RGB
  | [@bs.as 6406] Alpha
  | [@bs.as 6409] Luminance
  | [@bs.as 6410] LuminanceAlpha
  | [@bs.as 6402] DepthComponent
  | [@bs.as 34041] DepthStencil;

let rgba = 6408;
let rgb = 6407;
let alpha = 6406;
let luminance = 6409;
let luminanceAlpha = 6410;
let depthComponent = 6402;
let depthStencil = 34041;