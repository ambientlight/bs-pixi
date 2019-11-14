/**
  used to resolve dependency cycle
  dependency cycle: src/C-PIXI.cmj -> src/Filter-PIXI.cmj -> src/RenderTexture-PIXI.cmj -> src/BaseRenderTexture-PIXI.cmj -> src/C1-PIXI.cmj -> src/Renderer-PIXI.cmj -> src/Extract-PIXI.cmj -> src/DisplayObject-PIXI.cmj-> src/C-PIXI.cmj

  FIXME: until this is resolved,
  feel free to force cast it with Obj.magic to DisplayObject.t or any structural subtype of Js.t(#C.displayObject)
 */
type displayObjectOpaque;

/**
 * used to resolve dependency cycle
  dependency cycle: src/RenderTexture-PIXI.cmj -> src/BaseRenderTexture-PIXI.cmj -> src/C1-PIXI.cmj -> src/Renderer-PIXI.cmj -> src/Extract-PIXI.cmj -> src/RenderTexture-PIXI.cmj.

  FIXME: until this is resolved,
  feel free to force cast it with Obj.magic to RenderTexture.t or any structural subtype of Js.t(#RenderTexture._t)
 */
type renderTextureOpaque;

/**
  FIXME: dependency cycle
 */
type rendererOpaque;

module Extract {
  /**
    The extract manager provides functionality to export content from the renderers.
    An instance of this class is automatically created by default, 
    and can be found at renderer.plugins.extract
   */
  type t;

  /**
    creates a new extract instance
    
      @param renderer a reference to the current renderer
   */
  [@bs.module "pixi.js"][@bs.scope "extract"][@bs.new]
  external create: (~renderer: rendererOpaque) => t = "Extract";

  /**
    Will return a a base64 encoded string of this target. 
    It works by calling Extract.getCanvas and then running toDataURL on that

      @param target A displayObject or renderTexture to convert. If left empty will use the main renderer
      @param format Image format, e.g. "image/jpeg" or "image/webp"
      @param quality JPEG or Webp compression from 0 to 1. Default is 0.92
      @return A base64 encoded string of the texture.
   */
  [@bs.send]
  external base64: (
    t, 
    ~target: [@bs.unwrap][`DisplayObject(displayObjectOpaque) | `RenderTexture(renderTextureOpaque)]=?, 
    ~quality: float=?, unit) => string = "base64";

  /**
    Creates a Canvas element, renders this target to it and then returns it

      @param target A displayObject or renderTexture to convert. If left empty will use the main renderer
      @return A Canvas element with the texture rendered on
   */
  [@bs.send]
  external canvas: (
    t,
    ~target: [@bs.unwrap][`DisplayObject(displayObjectOpaque) | `RenderTexture(renderTextureOpaque)]
  ) => Webapi.Dom.HtmlElement.t = "canvas";

  /**
    Destroys the extract
   */
  [@bs.send] external destroy: t => unit = "destroy";

  /**
    Will return a HTML Image of the target

      @param target A displayObject or renderTexture to convert. If left empty will use the main renderer
      @param format Image format, e.g. "image/jpeg" or "image/webp"
      @param quality JPEG or Webp compression from 0 to 1. Default is 0.92
      @return HTML Image of the target
   */
  [@bs.send]
  external image: (
    t, 
    ~target: [@bs.unwrap][`DisplayObject(displayObjectOpaque) | `RenderTexture(renderTextureOpaque)]=?,
    ~format: string=?,
    ~quality: float=?, unit) => Webapi.Dom.HtmlImageElement.t = "image";

  /**
    Will return a one-dimensional array containing the pixel data of the entire texture in RGBA order, 
    with integer values between 0 and 255 (included)

      @param target A displayObject or renderTexture to convert. If left empty will use the main renderer
      @return one-dimensional array containing the pixel data of the entire texture
   */
  [@bs.send]
  external pixels: (
    t,
    ~target: [@bs.unwrap][`DisplayObject(displayObjectOpaque) | `RenderTexture(renderTextureOpaque)]
  ) => Js.Typed_array.Uint8Array.t = "pixels";
};