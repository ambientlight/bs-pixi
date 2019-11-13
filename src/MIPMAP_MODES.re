[@bs.deriving jsConverter]
type t = 
  | [@bs.as 0] None
  | [@bs.as 1] Scissor
  | [@bs.as 2] Stencil
  | [@bs.as 3] Sprite; 

/**
  Mask is ignored
 */
let none = 0;

/**
  Scissor mask, rectangle on screen, cheap
 */
let scissor = 1;

/**
  Stencil mask, 1-bit, medium, works only if renderer supports stencil
 */
let stencil = 2;

/**
  Mask that uses SpriteMaskFilter, uses temporary RenderTexture
 */
let sprite = 3;