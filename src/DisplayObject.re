/**
  The base class for all objects that are rendered on the screen.
  This is an abstract class and should not be used on its own; rather it should be extended
 */
type t = Js.t(C.displayObject);

[@bs.module "pixi.js"][@bs.new]
external create: unit => t = "DisplayObject";