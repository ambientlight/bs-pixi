/**
  Resource type for HTMLVideoElement.
 */
type t = Js.t(C1.resource);

[@bs.deriving abstract]
type sourceObject = {
  src: string,
  mime: string,
};

[@bs.obj]
external createVideoResourceOptions:
  (
    ~autoLoad: bool=?,
    ~autoPlay: bool=?,
    ~updateFPS: int=?,
    ~crossorigin: bool=?,
    unit
  ) =>
  _ =
  "";

module Impl = {
  [@bs.module "pixi.js"] [@bs.scope "resources"] [@bs.new]
  external _create:
    (
      ~source: [@bs.unwrap] [
                 | `HTMLVideoElement(Webapi.Dom.Element.t)
                 | `String(string)
                 | `Object(array(sourceObject))
               ],
      ~options: 'a=?,
      unit
    ) =>
    t =
    "VideoResource";

  /**
    creates new video resource

      @param source The source of the resource
  */
  let create = (~source, ~options=createVideoResourceOptions(), ()) =>
    _create(~source, ~options, ());

  /**
    When set to true will automatically play videos used by this texture once they are loaded. If false, it will not modify the playing state.
  */
  [@bs.get]
  external getAutoPlay: Js.t(#C1.resource) => bool = "autoPlay";

  /**
    How many times a second to update the texture from the video. Leave at 0 to update at every render. A lower fps can help performance, as updating the texture at 60fps on a 30ps video may not be efficient.
  */
  [@bs.get]
  external getUpdateFPS: Js.t(#C1.resource) => int = "updateFPS";
};

include BaseImageResource.Impl;
include Resource.Impl;
include Impl;
