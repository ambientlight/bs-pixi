/**
  A Texture stores the information that represents an image. 
  All textures have a base texture, which contains information about the source. 
  Therefore you can have many textures all using a single BaseTexture
 */
type t = Js.t(C.baseTexture);

[@bs.obj] external _createOptions: (
  ~mipmap: int=?,
  ~anisotropicLevel: int=?,
  ~wrapMode: int=?,
  ~scaleMode: int=?,
  ~format: int=?,
  ~_type: int=?,
  ~target: int=?,
  ~alphaMode: int=?,
  ~width: float=?,
  ~height: float=?,
  ~resolution: float=?,
  ~resourceOptions: Js.t({.})=?,
  unit
) => _ = "";

/**
  create collection of options for base texture creation

    @param mipmap If mipmapping is enabled for texture
    @param anisotropicLevel Anisotropic filtering level of texture
    @param wrapMode Wrap mode for textures
    @param scaleMode Default scale mode, linear, nearest
    @param format GL format type
    @param _type GL data type
    @param target GL texture target
    @param alphaMode Pre multiply the image alpha
    @param width Width of the texture
    @param height Height of the texture
    @param resolution Resolution of the base texture
    @param resourceOptions Optional resource options
 */
let createOptions = (
  ~mipmap=?,
  ~anisotropicLevel=?,
  ~wrapMode=?,
  ~scaleMode=?,
  ~format=?,
  ~_type=?,
  ~target=?,
  ~alphaMode=?,
  ~width=?,
  ~height=?,
  ~resolution=?,
  ~resourceOptions=?,
  _unit: unit
) => _createOptions(
  ~mipmap =? mipmap |. Belt.Option.map(mipmap => mipmap |. MIPMAP_MODES.tToJs),
  ~anisotropicLevel?,
  ~wrapMode =? wrapMode |. Belt.Option.map(wrapMode => wrapMode |. WRAP_MODES.tToJs),
  ~scaleMode =? scaleMode |. Belt.Option.map(scaleMode => scaleMode |. SCALE_MODES.tToJs),
  ~format =? format |. Belt.Option.map(format => format |. FORMATS.tToJs),
  ~_type =? _type |. Belt.Option.map(_type => _type |. TYPES.tToJs),
  ~target =? target |. Belt.Option.map(target => target |. TARGETS.tToJs),
  ~alphaMode =? alphaMode |. Belt.Option.map(alphaMode => alphaMode |. ALPHA_MODES.tToJs),
  ~width?,
  ~height?,
  ~resolution?,
  ~resourceOptions?,
  ()
);

/**
  creates a new base texture

    @param resource The current resource to use, for things that aren't Resource objects, will be converted into a Resource.
    @param options collection of options
 */
[@bs.module "pixi.js"][@bs.new]
external create: (
  ~resource: [@bs.unwrap] [
    | `Resource(Resource.t) 
    | `String(string)
    | `HTMLImageElement(Webapi.Dom.HtmlImageElement.t)
    | `HTMLCanvasElement(Webapi.Dom.Element.t)
    | `HTMLVideoElement(Webapi.Dom.Element.t)
  ]=?,
  ~options: 'a,
  unit
) => t = "BaseTexture";