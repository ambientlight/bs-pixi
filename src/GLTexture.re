/**
  Internal texture for WebGL context
 */
[@bs.deriving abstract]
type t = {
  /**
    texture contents dirty flag
   */
  mutable dirtyId: int,

  /**
    Texture style dirty flag
   */
  mutable dirtyStyleId: int,

  /**
    height of texture that was used in texImage2D
   */
  mutable height: float,

  /**
    type copied from baseTexture
   */
  mutable internalFormat: int,

  /**
    whether mip levels has to be generated
   */
  mutable mipmap: bool,

  /**
    the WebGL texture
   */
  mutable texture: Webapi.Canvas.WebGl.glT,

  /**
    type copied from baseTexture
   */
  [@bs.as "type"] mutable type_: int,

  /**
    width of texture that was used in texImage2D
   */
  mutable width: float,

  /**
    wrapMode copied from baseTexture
   */
  mutable wrapMode: int
};

/**
  creates a new glTexture
 */
[@bs.module "pixi.js"][@bs.new]
external create: unit => t = "GLTexture";