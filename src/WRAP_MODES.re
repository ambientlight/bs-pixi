/**
  The wrap modes that are supported by pixi.
  The PIXI.settings.WRAP_MODE wrap mode affects the default wrapping mode of future operations. 
  It can be re-assigned to either CLAMP or REPEAT, depending upon suitability. 
  If the texture is non power of two then clamp will be used regardless as WebGL can only use REPEAT if the texture is po2.

  This property only affects WebGL
 */
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