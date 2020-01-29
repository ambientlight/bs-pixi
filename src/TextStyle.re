
[@bs.obj] external createStyleOptions: (
  ~align: string=?,
  ~breakWords: bool=?,
  ~dropShadow: bool=?,
  ~dropShadowAlpha: float=?,
  ~dropShadowAngle: float=?,
  ~dropShadowBlur: float=?,
  ~dropShadowColor: int=?,
  ~dropShadowDistance: float=?,
  ~fill: int=?,
  ~fontFamily: array(string)=?,
  ~fontSize: float=?,
  ~fontStyle: string=?,
  ~fontVariant: string=?,
  ~fontWeight: string=?,
  ~leading: float=?,
  ~letterSpacing: float=?,
  ~lineJoin: string=?,
  ~miterLimit: float=?,
  ~padding: float=?,
  ~stroke: int=?,
  ~strokeThickness: float=?,
  ~trim: bool=?,
  ~textBaseline: string=?,
  ~whiteSpace: string=?,
  ~wordWrap: bool=?,
  ~wordWrapWidth: float=?,
  unit
) => _ = "";

[@bs.deriving abstract]
type t = {
  [@bs.optional] align: string,
  [@bs.optional] breakWords: bool,
  [@bs.optional] dropShadow: bool,
  [@bs.optional] dropShadowAlpha: float,
  [@bs.optional] dropShadowAngle: float,
  [@bs.optional] dropShadowBlur: float,
  [@bs.optional] dropShadowColor: int,
  [@bs.optional] dropShadowDistance: float,
  [@bs.optional] fill: int,
  [@bs.optional] fontFamily: array(string),
  [@bs.optional] fontSize: float,
  [@bs.optional] fontStyle: string,
  [@bs.optional] fontVariant: string,
  [@bs.optional] fontWeight: string,
  [@bs.optional] leading: float,
  [@bs.optional] letterSpacing: float,
  [@bs.optional] lineJoin: string,
  [@bs.optional] miterLimit: float,
  [@bs.optional] padding: float,
  [@bs.optional] stroke: int,
  [@bs.optional] strokeThickness: float,
  [@bs.optional] trim: bool,
  [@bs.optional] textBaseline: string,
  [@bs.optional] whiteSpace: string,
  [@bs.optional] wordWrap: bool,
  [@bs.optional] wordWrapWidth: float,

  clone: unit => t,
  reset: unit => unit,
  toFontSize: unit => string
};

[@bs.module "pixi.js"][@bs.new]
external _create: ('a) => t = "TextStyle";

let create = (~style = createStyleOptions(()), ()) => _create(style);