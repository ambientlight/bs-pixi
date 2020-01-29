class type _t = [@bs] {
  inherit C.container;

  /**
    The anchor sets the origin point of the text. The default value is taken from the Texture and passed to the constructor. 
    The default is (0,0), this means the text's origin is the top left.
    Setting the anchor to (0.5,0.5) means the text's origin is centered.
    Setting the anchor to (1,1) would mean the text's origin point will be the bottom right corner.
   */
  [@bs.set] pub anchor: ObservablePoint.t;

  /**
    The blend mode to be applied to the sprite. 
    Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode.
   */
  [@bs.set] pub blendMode: int;

  /** 
    Plugin that is responsible for rendering this element. 
    Allows to customize the rendering process without overriding '_render' & '_renderCanvas' methods. 
  */
  [@bs.set] pub pluginName: string;

  /**
    If true PixiJS will Math.floor() x/y values when rendering, stopping pixel interpolation. 
    Advantages can include sharper image quality (like text) and faster rendering on canvas. 
    The main disadvantage is movement of objects may appear less smooth. 
    To set the global default, change PIXI.settings.ROUND_PIXELS
   */
  [@bs.set] pub roundPixels: bool;

  /**
    The shader that will be used to render the sprite. 
    Set to null to remove a current shader.
   */
  [@bs.set] pub shader: Js.t(#Shader._t);

  /** The texture that the sprite is using */
  [@bs.set] pub texture: Js.t(#Texture._t);

  /** The tint applied to the sprite. This is a hex value. A value of 0xFFFFFF will remove any tint effect. */
  [@bs.set] pub tint: int;

  /** 
    calculates worldTransform * vertices for a non texture with a trim. 
    store it in vertexTrimmedData This is used to ensure that the true width and height of a trimmed texture is respected 
   */
  pub calculateTrimmedVertices: unit => unit;

  /**
    calculates worldTransform * vertices, store it in vertexData
   */
  pub calculateVertices: unit => unit;

  /** Tests if a point is inside this sprite */
  pub containsPoint: Point.t => bool;


};

/** The Sprite object is the base for all textured objects that are rendered to the screen */
type t = Js.t(_t);

[@bs.module "pixi.js"][@bs.scope "Sprite"]
external _from: (
  ~source: [@bs.unwrap][
    | `String(string)
    | `HTMLCanvasElement(Webapi.Dom.HtmlElement.t)
    | `HTMLVideoElement(Webapi.Dom.HtmlElement.t)],
  ~options: 'a,
  unit
) => t = "from";

/**
  Helper function that creates a new sprite based on the source you provide. 
  The source can be - frame id, image url, video url, canvas element, video element, base texture
*/
let from = (~source, ~options=BaseTexture._createOptions(()), ()) => _from(~source, ~options, ());

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: Texture.t => t = "Sprite";

  /**
    The anchor sets the origin point of the text. The default value is taken from the Texture and passed to the constructor. 
    The default is (0,0), this means the text's origin is the top left.
    Setting the anchor to (0.5,0.5) means the text's origin is centered.
    Setting the anchor to (1,1) would mean the text's origin point will be the bottom right corner.
   */
  [@bs.get] external getAnchor: Js.t(#_t) => ObservablePoint.t = "anchor";

  /**
    The anchor sets the origin point of the text. The default value is taken from the Texture and passed to the constructor. 
    The default is (0,0), this means the text's origin is the top left.
    Setting the anchor to (0.5,0.5) means the text's origin is centered.
    Setting the anchor to (1,1) would mean the text's origin point will be the bottom right corner.
   */
  [@bs.set] external setAnchor: (Js.t(#_t), ObservablePoint.t) => unit = "anchor";

  [@bs.get] external _getBlendMode: Js.t(#_t) => int = "blendMode";
  
  /**
    The blend mode to be applied to the sprite. 
    Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode.
   */
  let getBlendMode = sprite => sprite |> _getBlendMode |> BLEND_MODES.tFromJs |> Belt.Option.getExn;

  [@bs.set] external _setBlendMode: (Js.t(#_t), int) => unit = "blendMode";

  /**
    The blend mode to be applied to the sprite. 
    Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode.
   */
  let setBlendMode = (sprite, blendMode) => sprite |. _setBlendMode(BLEND_MODES.tToJs(blendMode));

  /**
    Plugin that is responsible for rendering this element. 
    Allows to customize the rendering process without overriding '_render' & '_renderCanvas' methods.
   */
  [@bs.get] external getPluginName: Js.t(#_t) => string = "pluginName";

  /**
    Plugin that is responsible for rendering this element. 
    Allows to customize the rendering process without overriding '_render' & '_renderCanvas' methods.
   */
  [@bs.set] external setPluginName: (Js.t(#_t), string) => unit = "pluginName";

  /**
    If true PixiJS will Math.floor() x/y values when rendering, stopping pixel interpolation. 
    Advantages can include sharper image quality (like text) and faster rendering on canvas. 
    The main disadvantage is movement of objects may appear less smooth. 
    To set the global default, change PIXI.settings.ROUND_PIXELS
   */
  [@bs.get] external getRoundPixels: Js.t(#_t) => bool = "roundPixels";

  /**
    If true PixiJS will Math.floor() x/y values when rendering, stopping pixel interpolation. 
    Advantages can include sharper image quality (like text) and faster rendering on canvas. 
    The main disadvantage is movement of objects may appear less smooth. 
    To set the global default, change PIXI.settings.ROUND_PIXELS
   */
  [@bs.set] external setRoundPixels: (Js.t(#_t), bool) => unit = "roundPixels";

  /**
    The shader that will be used to render the sprite. 
    Set to null to remove a current shader.
   */
  [@bs.get] external getShader: Js.t(#_t) => Js.t(#Shader._t) = "shader";

  /**
    The shader that will be used to render the sprite. 
    Set to null to remove a current shader.
   */
  [@bs.set] external setShader: (Js.t(#_t), Js.t(#Shader._t)) => unit = "shader";

  /**
    The texture that the sprite is using
   */
  [@bs.get] external getTexture: Js.t(#_t) => Js.t(#Texture._t) = "texture"; 

  /**
    The texture that the sprite is using
   */ 
  [@bs.set] external setTexture: (Js.t(#_t), Js.t(#Texture._t)) => unit = "texture";

  /** 
    The tint applied to the sprite. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
   */
  [@bs.get] external getTint: Js.t(#_t) => int = "tint"; 

  /** 
    The tint applied to the sprite. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
   */
  [@bs.set] external setTint: (Js.t(#_t), int) => unit = "tint";

  /** 
    calculates worldTransform * vertices for a non texture with a trim. 
    store it in vertexTrimmedData This is used to ensure that the true width and height of a trimmed texture is respected 
   */
  [@bs.send] external calculateTrimmedVertices: Js.t(#_t) => unit = "calculateTrimmedVertices";

  /**
    calculates worldTransform * vertices, store it in vertexData
   */
  [@bs.send] external calculateVertices: Js.t(#_t) => unit = "calculateVertices";

  /** Tests if a point is inside this sprite */
  [@bs.send] external containsPoint: (Js.t(#_t), Point.t) => bool = "containsPoint";
}

include EventEmitter.Impl;
include DisplayObject.Impl;
include Container.Impl;
include Impl;