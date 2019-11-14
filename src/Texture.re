class type _t = [@bs] {
  inherit EventEmitter._t;

  /**
    This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering, 
    irrespective of the actual frame size or placement 
    (which can be influenced by trimmed texture atlases)
   */
  [@bs.set] pub _frame: Rectangle.t;

  /**
    The base texture that this texture uses.
   */
  [@bs.set] pub baseTexture: BaseTexture.t;
  
  /**
    Anchor point that is used as default if sprite is created with this texture. 
    Changing the defaultAnchor at a later point of time will not update Sprite's anchor point.
   */
  [@bs.set] pub defaultAnchor: Point.t;

  /**
    The frame specifies the region of the base texture that this texture uses. 
    Please call updateUvs() after you change coordinates of frame manually.
   */
  [@bs.set] pub frame: Rectangle.t;

  /**
    The height of the Texture in pixels
   */
  pub height: float;

  /**
    Does this Texture have any frame data assigned to it?
    This mode is enabled automatically if no frame was passed inside constructor.
    In this mode texture is subscribed to baseTexture events, and fires update on any change.
    Beware, after loading or resize of baseTexture event can fired two times! If you want more control, subscribe on baseTexture itself.
    Any assignment of frame switches off noFrame mode.
   */
  [@bs.set] pub noFrame: bool;

  /**
    This is the area of original texture, before it was put in atlas
   */
  [@bs.set] pub orig: Rectangle.t;

  /**
    This will let a renderer know that a texture has been updated (used mainly for WebGL uv updates)
   */
  [@bs.set] pub requiresUpdate: bool;

  /**
    Returns resolution of baseTexture
   */
  pub resolution: float;

  /**
    Indicates whether the texture is rotated inside the atlas set to 2 to compensate for texture packer 
    rotation set to 6 to compensate for spine packer rotation can be used to rotate or mirror sprites 
    See PIXI.groupD8 for explanation
   */
  [@bs.set] pub rotate: float;

  /**
    The ids under which this Texture has been added to the texture cache. 
    This is automatically set as long as Texture.addToCache is used, but may not be set 
    if a Texture is added directly to the TextureCache array.
   */
  [@bs.set] pub textureCacheIds: array(string);

  /**
    This is the trimmed area of original texture,
    before it was put in atlas Please call updateUvs() after you change coordinates of trim manually.
   */
  [@bs.set] pub trim: Rectangle.t;

  /**
    Default TextureMatrix instance for this texture By default that object is not created because its heavy
   */
  [@bs.set] pub uvMatrix: TextureMatrix.t;

  /**
    This will let the renderer know if the texture is valid. If it's not then it cannot be rendered
   */
  [@bs.set] pub valid: bool;
  
  /**
    The width of the Texture in pixels.
   */
  pub width: float;

  /**
    Creates a new texture object that acts the same as this one
   */
  pub clone: unit => unit;

  /**
    Destroys this texture
   */
  pub destroy: bool => unit;

  /**
    Updates this texture on the gpu.
    Calls the TextureResource update.
    If you adjusted frame manually, please call updateUvs() instead.
   */
  pub update: unit => unit;

  /**
    Updates the internal WebGL UV cache. 
    Use it after you change frame or trim of the texture. 
    Call it after changing the frame
   */
  pub updateUvs: unit => unit;
};

type t = Js.t(_t);

/**
  An empty texture, used often to not have to create multiple empty textures. 
  Can not be destroyed.
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Texture"]
external empty: Js.t(#_t) = "EMPTY";

/**
  A white texture of 16x16 size, used for graphics and other things Can not be destroyed.
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Texture"]
external white: Js.t(#_t) = "WHITE";

/**
  creates new texture

    @param baseTexture The base texture source to create the texture from
    @param frame The rectangle frame of the texture to show
    @param orig The area of original texture
    @param trim Trimmed rectangle of original texture
    @param rotate indicates how the texture was rotated by texture packer
    @param achor Default anchor point used for sprite placement / rotation
 */
[@bs.module "pixi.js"][@bs.new]
external create: (
  ~baseTexture: BaseTexture.t, 
  ~frame: Rectangle.t=?, 
  ~orig: Rectangle.t=?, 
  ~trim: Rectangle.t=?, 
  ~rotate: float=?, 
  ~anchor: Point.t=?, unit) => Js.t(#_t) = "Texture";

/**
  This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering, 
  irrespective of the actual frame size or placement 
  (which can be influenced by trimmed texture atlases)    
 */
[@bs.get] external get_frame: Js.t(#_t) => Js.t(#Rectangle._t) = "_frame";

/**
  This is the area of the BaseTexture image to actually copy to the Canvas / WebGL when rendering, 
  irrespective of the actual frame size or placement 
  (which can be influenced by trimmed texture atlases)    
 */
[@bs.set] external set_frame: (Js.t(#_t), Js.t(#Rectangle._t)) => unit = "_frame";

/**
  The base texture that this texture uses
 */
[@bs.get] external getBaseTexture: Js.t(#_t) => Js.t(#C1.baseTexture) = "baseTexture";

/**
  The base texture that this texture uses
 */
[@bs.set] external setBaseTexture: (Js.t(#_t), Js.t(#C1.baseTexture)) => unit = "baseTexture";

/**
  Anchor point that is used as default if sprite is created with this texture. 
  Changing the defaultAnchor at a later point of time will not update Sprite's anchor point.
 */
[@bs.get] external getDefaultAnchor: Js.t(#_t) => Js.t(#Point._t) = "defaultAnchor";

/**
  Anchor point that is used as default if sprite is created with this texture. 
  Changing the defaultAnchor at a later point of time will not update Sprite's anchor point.
 */
[@bs.set] external setDefaultAnchor: (Js.t(#_t), Js.t(#Point._t)) => unit = "defaultAnchor";

/**
  The frame specifies the region of the base texture that this texture uses. 
  Please call updateUvs() after you change coordinates of frame manually.
 */
[@bs.get] external getFrame: Js.t(#_t) => Js.t(#Rectangle._t) = "frame";

/**
  The frame specifies the region of the base texture that this texture uses. 
  Please call updateUvs() after you change coordinates of frame manually.
 */
[@bs.set] external setFrame: (Js.t(#_t), Js.t(#Rectangle._t)) => unit = "frame";

/**
  The height of the Texture in pixels
 */
[@bs.get] external getHeight: Js.t(#_t) => float = "height";

/**
  The height of the Texture in pixels
 */
[@bs.set] external setHeight: (Js.t(#_t), float) => unit = "height";

/**
  Does this Texture have any frame data assigned to it?
  This mode is enabled automatically if no frame was passed inside constructor.
  In this mode texture is subscribed to baseTexture events, and fires update on any change.
  Beware, after loading or resize of baseTexture event can fired two times! If you want more control, subscribe on baseTexture itself.
  Any assignment of frame switches off noFrame mode.
 */
[@bs.get] external getNoFrame: Js.t(#_t) => bool = "noFrame";

/**
  Does this Texture have any frame data assigned to it?
  This mode is enabled automatically if no frame was passed inside constructor.
  In this mode texture is subscribed to baseTexture events, and fires update on any change.
  Beware, after loading or resize of baseTexture event can fired two times! If you want more control, subscribe on baseTexture itself.
  Any assignment of frame switches off noFrame mode.
 */
[@bs.set] external setNoFrame: (Js.t(#_t), bool) => unit = "noFrame";

/**
  This is the area of original texture, before it was put in atlas
 */
[@bs.get] external getOrig: Js.t(#_t) => Js.t(#Rectangle._t) = "orig";

/**
  This is the area of original texture, before it was put in atlas
 */
[@bs.set] external setOrig: (Js.t(#_t), Js.t(#Rectangle._t)) => unit = "orig";

/**
  This will let a renderer know that a texture has been updated (used mainly for WebGL uv updates)
 */
[@bs.get] external getRequiresUpdate: Js.t(#_t) => Js.t(#Rectangle._t) = "requiresUpdate";

/**
  This will let a renderer know that a texture has been updated (used mainly for WebGL uv updates)
 */
[@bs.set] external setRequiresUpdate: (Js.t(#_t), Js.t(#Rectangle._t)) => unit = "requiresUpdate";

/**
  Returns resolution of baseTexture
 */
[@bs.get] external getResolution: Js.t(#_t) => float = "resolution";

/**
  Returns resolution of baseTexture
 */
[@bs.set] external setResolution: (Js.t(#_t), float) => unit = "resolution";

/**
  Indicates whether the texture is rotated inside the atlas set to 2 to compensate for texture packer 
  rotation set to 6 to compensate for spine packer rotation can be used to rotate or mirror sprites 
  See PIXI.groupD8 for explanation
 */
[@bs.get] external getRotate: Js.t(#_t) => float = "rotate";

/**
  Indicates whether the texture is rotated inside the atlas set to 2 to compensate for texture packer 
  rotation set to 6 to compensate for spine packer rotation can be used to rotate or mirror sprites 
  See PIXI.groupD8 for explanation
 */
[@bs.set] external setRotate: (Js.t(#_t), float) => unit = "rotate";

/**
  The ids under which this Texture has been added to the texture cache. 
  This is automatically set as long as Texture.addToCache is used, but may not be set 
  if a Texture is added directly to the TextureCache array
 */
[@bs.get] external getTextureCacheIds: Js.t(#_t) => array(string) = "textureCacheIds";

/**
  The ids under which this Texture has been added to the texture cache. 
  This is automatically set as long as Texture.addToCache is used, but may not be set 
  if a Texture is added directly to the TextureCache array.
 */
[@bs.set] external setTextureCacheIds: (Js.t(#_t), array(string)) => unit = "textureCacheIds";

/**
  This is the trimmed area of original texture,
  before it was put in atlas Please call updateUvs() after you change coordinates of trim manually
 */
[@bs.get] external getTrim: Js.t(#_t) => Js.t(#Rectangle._t) = "trim";

/**
  This is the trimmed area of original texture,
  before it was put in atlas Please call updateUvs() after you change coordinates of trim manually
 */
[@bs.set] external setTrim: (Js.t(#_t), Js.t(#Rectangle._t)) => unit = "trim";

/**
  Default TextureMatrix instance for this texture By default that object is not created because its heavy
 */
[@bs.get] external getUvMatrix: Js.t(#_t) => TextureMatrix.t = "uvMatrix";

/**
  Default TextureMatrix instance for this texture By default that object is not created because its heavy
 */
[@bs.set] external setUvMatrix: (Js.t(#_t), TextureMatrix.t) => unit = "uvMatrix";

/**
  This will let the renderer know if the texture is valid. If it's not then it cannot be rendered
 */
[@bs.get] external getValid: Js.t(#_t) => float = "valid";

/**
  This will let the renderer know if the texture is valid. If it's not then it cannot be rendered.
 */
[@bs.set] external setValid: (Js.t(#_t), float) => unit = "valid";

/**
  The width of the Texture in pixels
 */
[@bs.get] external getWidth: Js.t(#_t) => float = "width";

/**
  The width of the Texture in pixels
 */
[@bs.set] external setWidth: (Js.t(#_t), float) => unit = "width";

/**
  Adds a Texture to the global TextureCache. This cache is shared across the whole PIXI object.

    @param texture The Texture to add to the cache
    @param id The id that the Texture will be stored against
 */
[@bs.module "pixi.js"][@bs.scope "Texture"]
external addToCache: (~texture: Js.t(#_t), ~id: string) => unit = "addToCache";

/**
  Helper function that creates a new Texture based on the source you provide. 
  The source can be - frame id, image url, video url, canvas element, video element, base texture
    
    @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-createOptions> BaseTexture.createOptions
    @param source Source to create texture from
    @param options options
    @param strict Enforce strict-mode, see PIXI.settings.STRICT_TEXTURE_CACHE
    @return The newly created texture
 */
[@bs.module "pixi.js"][@bs.scope "Texture"]
external from: (
  ~source: [@bs.unwrap][
  | `String(string)
  | `HtmlImageElement(Webapi.Dom.HtmlImageElement.t)
  | `HtmlCanvasElement(Webapi.Dom.HtmlElement.t)
  | `HtmlVideoElement(Webapi.Dom.HtmlElement.t)
  | `BaseTexture(BaseTexture.t)]=?, 
  ~options: 'a=?, 
  ~strict: bool=?, unit) => Js.t(#_t) = "from";

/**
  Create a new Texture with a BufferResource from a Float32Array. 
  RGBA values are floats from 0 to 1.

    @see </bs-pixi/PIXI/BaseTexture-PIXI/#val-createOptions> BaseTexture.createOptions
    @param buffer The optional array to use, if no data is provided, a new Float32Array is created
    @param width Width of the resource
    @param height Height of the resource
    @param options See PIXI.BaseTexture's constructor for options
    @return The newly created texture
 */
[@bs.module "pixi.js"][@bs.scope "Texture"]
external fromBuffer: (
  ~buffer: [@bs.unwrap] [
    | `Float32Array(Js.Typed_array.Float32Array.t) 
    | `UInt8Array(Js.Typed_array.Uint8Array.t)], 
  ~width: float, 
  ~height: float, 
  ~options: 'a=?, unit) => Js.t(#_t) = "fromBuffer";

/**
  Create a texture from a source and add to the cache

    @param source Create a texture from a source and add to the cache.
    @param imageUrl File name of texture, for cache and resolving resolution
    @param name Human readable name for the texture cache. If no name is specified, only imageUrl will be used as the cache ID.
    @return output texture
 */
[@bs.module "pixi.js"][@bs.scope "Texture"]
external fromLoader: (
  ~source: [@bs.unwrap] [
    | `HTMLImageElement(Webapi.Dom.HtmlImageElement.t)
    | `HTMLCanvasElement(Webapi.Dom.HtmlElement.t)
  ], 
  ~imageUrl: string, 
  ~name: string=?, unit) => Js.t(#_t) = "fromLoader";

/**
  Remove a Texture from the global TextureCache

    @param texture id of a Texture to be removed, or a Texture instance itself
    @return The Texture that was removed
 */
[@bs.module "pixi.js"][@bs.scope "Texture"]
external removeFromCache: (~texture: [@bs.unwrap] [`Texture(t) | `String(string)]) => Js.Nullable.t(Js.t(#_t)) = "removeFromCache";

/**
  Creates a new texture object that acts the same as this one

    @return the new texture
 */
[@bs.send]
external clone: Js.t(#_t) => unit = "clone";

/**
  Destroys this texture

    @param destroyBase Whether to destroy the base texture as well
 */
[@bs.send]
external destroy: (Js.t(#_t), ~destroyBase: bool=?, unit) => unit = "destroy";

/**
  Updates this texture on the gpu. Calls the TextureResource update.
  If you adjusted frame manually, please call updateUvs() instead.
 */
[@bs.send]
external update: Js.t(#_t) => unit = "update";

/**
  Updates the internal WebGL UV cache. 
  Use it after you change frame or trim of the texture. Call it after changing the frame
 */
[@bs.send]
external updateUvs: Js.t(#_t) => unit = "updateUvs";