[@bs.deriving jsConverter]
type t = 
  | [@bs.as 0] Clamp
  | [@bs.as 1] Repeat
  | [@bs.as 2] MirroredRepeat;

/** 
  The textures uvs are clamped
 */
let clamp = 0;

/**
  The texture uvs tile and repeat
 */
let repeat = 1;

/**
  The texture uvs tile and repeat with mirroring
 */
let mirroredRepeat = 2;