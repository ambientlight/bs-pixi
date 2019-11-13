/**
  Base resource class for textures that manages validation and uploading, depending on its type.
  Uploading of a base texture to the GPU is required.
 */
type t = Js.t(C.resource);

/**
  creates new resource

    @param width width of the resource
    @param height height of the resource
 */
[@bs.module "pixi.js"][@bs.scope "resources"][@bs.new]
external create: (~width: float=?, ~height: float=?, unit) => t = "Resource";

/**
  if resource has been destroyed
 */
[@bs.get] external getDestroyed: Js.t(#C.resource) => bool = "destroyed";

/**
  the height of the resource.
 */
[@bs.get] external getHeight: Js.t(#C.resource) => float = "height";

/**
  has been validated
 */
[@bs.get] external getValid: Js.t(#C.resource) => bool = "valid";

/**
  the width of the resource.
 */
[@bs.get] external getWidth: Js.t(#C.resource) => float = "width";

/**
  bind to a parent BaseTexture

    @param baseTexture parent texture
 */
[@bs.send]
external bind: (Js.t(#C.resource), ~baseTexture: Js.t(#C.baseTexture)) => unit = "bind";

/**
  Call when destroying resource, unbind any BaseTexture object before calling this method, 
  as reference counts are maintained internally
 */
[@bs.send]
external destroy: Js.t(#C.resource) => unit = "destroy";

/**
  trigger a resize event

    @param width X dimension
    @param width Y dimension
 */
[@bs.send]
external resize: (Js.t(#C.resource), ~width: float, ~height: float, unit) => unit = "resize";

/**
  set the style, optional to override

    @param renderer yeah, renderer!
    @param baseTexture the texture
    @param glTexture texture instance for this webgl context
    @return true if success
 */
[@bs.send]
external style: (Js.t(#C.resource), ~renderer: Js.t(#Renderer._t), ~baseTexture: Js.t(#C.baseTexture), ~glTexture: GLTexture.t) => bool = "style";

/**
  unbind to a parent BaseTexture

    @param baseTexture parent texture
 */
[@bs.send]
external unbind: (Js.t(#C.resource), ~baseTexture: Js.t(#C.baseTexture)) => unit = "unbind";

/**
  has been updated trigger event
 */
[@bs.send]
external update: Js.t(#C.resource) => unit = "update";

/**
  uploads the texture or returns false if it cant for some reason. Override this.

    @param renderer yeah, renderer!
    @param baseTexture the texture
    @param gTexture texture instance of this webgl context
 */
[@bs.send]
external upload: (Js.t(#C.resource), ~renderer: Js.t(#Renderer._t), ~baseTexture: Js.t(#C.baseTexture), ~glTexture: GLTexture.t) => bool = "upload";