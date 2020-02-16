/**
  Base for all the image/canvas resources
 */
type t = Js.t(C1.resource);

module Impl = {
  [@bs.module "pixi.js"] [@bs.scope "resources"] [@bs.new]
  external _create:
    (
      ~source: [@bs.unwrap] [
                 | `HTMLImageElement(Webapi.Dom.HtmlImageElement.t)
                 | `HTMLCanvasElement(Webapi.Dom.Element.t)
                 | `HTMLVideoElement(Webapi.Dom.Element.t)
               ]
    ) =>
    t =
    "BaseImageResource";

  /**
    creates new base image resource

      @param source The source of the resource
  */
  let create = (~source, ()) => _create(~source);

  /**
    The source element
  */
  [@bs.get]
  external getSource: Js.t(#C1.resource) => Webapi.Dom.Element.t = "source";
};

include Resource.Impl;
include Impl;
