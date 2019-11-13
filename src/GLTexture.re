/**
  Internal texture for WebGL context
 */
[@bs.deriving abstract]
type t = {
  /**
    texture contents dirty flag
   */
  dirtyId: int,

  /**
    Texture style dirty flag
   */
  dirtyStyleId: int,

  /**
    height of texture that was used in texImage2D
   */
  height: float,

  /**
    type copied from baseTexture
   */
  internalFormat: int,

  /**
    whether mip levels has to be generated
   */
  mipmap: bool,

  /**
    the WebGL texture
   */
  texture: Webapi.Canvas.WebGl.glT,

  /**
    type copied from baseTexture
   */
  [@bs.as "type"] type_: int,

  /**
    width of texture that was used in texImage2D
   */
  width: float,

  /**
    wrapMode copied from baseTexture
   */
  wrapMode: int
};

/**
  creates a new glTexture
 */
[@bs.module "pixi.js"][@bs.new]
external create: unit => t = "GLTexture";