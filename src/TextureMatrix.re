//FIXME: will need to rewrite this through class for recursive textureMatrix - texture to work
type opaqueTexture;

/**
  Class controls uv mapping from Texture normal space to BaseTexture normal space.
  Takes trim and rotate into account. May contain clamp settings for Meshes and TilingSprite.
  Can be used in Texture uvMatrix field, or separately, you can use different clamp settings on the same texture. 
  If you want to add support for texture region of certain feature or filter, that's what you're looking for.
  Takes track of Texture changes through _lastTextureID private field. 
  Use update() method call to track it from outside.
 */
[@bs.deriving abstract]
type t = {
  /**
    Changes frame clamping Works with TilingSprite and Mesh Change to -0.5 to add a pixel to the edge, 
    recommended for transparent trimmed textures in atlas
   */
  mutable clampMargin: float,

  /**
    Changes frame clamping Works with TilingSprite and Mesh Change to 1.5 
    if you texture has repeated right and bottom lines, 
    that leads to smoother borders
   */
  mutable clampOffset: float,

  /**
    If texture size is the same as baseTexture
   */
  isSimple: bool,

  /**
    Matrix operation that converts texture region coords to texture coords
   */
  mapCoord: Matrix.t,

  /**
    texture property  
   */
  mutable texture: opaqueTexture,

  /**
    Clamp region for normalized coords, left-top pixel center in xy , 
    bottom-right in zw. Calculated based on clampOffset.
   */
  uClampFrame: Js.Typed_array.Float32Array.t,

  /**
    Normalized clamp offset. Calculated based on clampOffset.    
   */
  uClampOffset: Js.Typed_array.Float32Array.t
};

[@bs.module "pixi.js"][@bs.new]
external create: (~texture: opaqueTexture, ~clampMargin: float=?, unit) => t = "TextureMatrix";

/**
  Multiplies uvs array to transform

    @param uvs Float32Array mesh uvs
    @param out Float32Array output
    @return output
 */
[@bs.send]
external multiplyUvs: (t, ~uvs: Js.Typed_array.Float32Array.t, ~out: Js.Typed_array.Float32Array.t=?, unit) => Js.Typed_array.Float32Array.t = "multiplyUvs";

/**
  updates matrices if texture was changed

    @param forceUpdate if true, matrices will be updated any case
    @return whether or not it was updated
 */
[@bs.send]
external update: (t, ~forceUpdate: bool=?, unit) => bool = "update";