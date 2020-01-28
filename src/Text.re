class type _t = [@bs] {
  inherit Sprite._t;

  /**
    The canvas element that everything is drawn to
   */
  [@bs.set] pub canvas: Webapi.Dom.HtmlElement.t;

  /**
    The canvas 2d context that everything is drawn with
   */
  [@bs.set] pub context: Webapi.Canvas.Canvas2d.t;

  /**
    The resolution / device pixel ratio of the canvas. 
    This is set to automatically match the renderer resolution by default, but can be overridden by setting manually.
   */
  [@bs.set] pub resolution: float;

  /**
    Set the style of the text. Set up an event listener to listen for changes on the style object and mark the text as dirty.
   */
  [@bs.set] pub style: TextStyle.t;

  /**
    Set the copy for the text object. To split a line you can use '\n'.
   */
  [@bs.set] pub text: string;
};

/**
  A Text Object will create a line or multiple lines of text.
  The text is created using the Canvas API.
  The primary advantage of this class over BitmapText is that you have great control over the style of the next, 
  which you can change at runtime.
  
  The primary disadvantages is that each piece of text has it's own texture, which can use more memory. 
  When text changes, this texture has to be re-generated and re-uploaded to the GPU, taking up time.
  
  To split a line you can use '\n' in your text string, or, on the style object, 
  change its wordWrap property to true and and give the wordWrapWidth property a value.
 */
type t = Js.t(_t);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: (~text: string, ~style: TextStyle.t=?, ~canvas: Webapi.Dom.HtmlElement.t=?, unit) => t = "Text";

  /**
    The canvas element that everything is drawn to
   */
  [@bs.get] external getCanvas: Js.t(#_t) => Webapi.Dom.HtmlElement.t = "canvas";

  /**
    The canvas element that everything is drawn to
   */
  [@bs.set] external setCanvas: (Js.t(#_t), Webapi.Dom.HtmlElement.t) => unit = "canvas";

  /**
   The canvas 2d context that everything is drawn with
   */
  [@bs.get] external getContext: Js.t(#_t) => Webapi.Canvas.Canvas2d.t = "context";

  /**
    The canvas 2d context that everything is drawn with
   */
  [@bs.set] external setContext: (Js.t(#_t), Webapi.Canvas.Canvas2d.t) => unit = "context";

  /**
    The resolution / device pixel ratio of the canvas. 
    This is set to automatically match the renderer resolution by default, but can be overridden by setting manually.
   */
  [@bs.get] external getResolution: Js.t(#_t) => float = "resolution";

  /**
    The resolution / device pixel ratio of the canvas. 
    This is set to automatically match the renderer resolution by default, but can be overridden by setting manually.
   */
  [@bs.set] external setResolution: (Js.t(#_t), float) => unit = "resolution";

  /**
    Set the style of the text. Set up an event listener to listen for changes on the style object and mark the text as dirty.
   */
  [@bs.get] external getStyle: Js.t(#_t) => TextStyle.t = "style";

  /**
    Set the style of the text. Set up an event listener to listen for changes on the style object and mark the text as dirty.
   */
  [@bs.set] external setStyle: (Js.t(#_t), TextStyle.t) => unit = "style";

  /**
    Set the copy for the text object. To split a line you can use '\n'.
   */
  [@bs.get] external getText: Js.t(#_t) => string = "text";

  /**
    Set the copy for the text object. To split a line you can use '\n'.
   */
  [@bs.set] external setText: (Js.t(#_t), string) => unit = "text";
}

include EventEmitter.Impl;
include DisplayObject.Impl;
include Container.Impl;
include Sprite.Impl;
include Impl;