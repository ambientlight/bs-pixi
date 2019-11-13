/**
  NOTE: this should be later exposed as part of bs-webapi 
  in Webapi.Canvas.ImageBitmap
 */
type imageBitmap;

type t = [
  | `HTMLImageElement(Webapi.Dom.HtmlImageElement.t)
  | `HTMLCanvasElement(Webapi.Dom.HtmlElement.t)
  | `HTMLVideoElement(Webapi.Dom.HtmlElement.t)
  | `ImageBitmap(imageBitmap)
];