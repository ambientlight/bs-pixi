class type _t = [@bs] {
  /**
    Activates blending of the computed fragment color values
   */
  [@bs.set] pub blend: bool;

  /**
    The blend mode to be applied when this state is set. 
    Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode
    Setting this mode to anything other than NO_BLEND will automatically switch blending on

      @deprecated consider using State.getBlendMode instead
      @see </bs-pixi/PIXI/State-PIXI/#val-getBlendMode> State.getBlendMode
   */
  [@bs.set] pub blendMode: int;

  /**
    Specifies whether or not front or back-facing polygons can be culled
   */
  [@bs.set] pub clockwiseFrontFace: bool;

  /**
    Activates culling of polygons
   */
  [@bs.set] pub culling: bool;

  /**
    Activates culling of polygons
   */
  [@bs.set] pub depthTest: bool;

  /**
    Activates adding an offset to depth values of polygon's fragments
   */
  [@bs.set] pub offsets: bool;

  /**
    The polygon offset. 
    Setting this property to anything other than 0 will automatically enable polygon offset fill
   */
  [@bs.set] pub polygonOffset: float;
};

/**
  This is a WebGL state, and is is passed The WebGL StateManager.
  Each mesh rendered may require WebGL to be in a different state. 
  For example you may want different blend mode or to enable polygon offsets
 */
type t = Js.t(_t);

module Impl {
  /**
    Activates blending of the computed fragment color values
  */
  [@bs.get] external getBlend: Js.t(#_t) => bool = "blend";

  /**
    Activates blending of the computed fragment color values
  */
  [@bs.set] external setBlend: (Js.t(#_t), bool) => unit = "blend";

  [@bs.get] external _getBlendMode: Js.t(#_t) => int = "blendMode";
  [@bs.set] external _setBlendMode: (Js.t(#_t), int) => unit = "blendMode";

  /**
    The blend mode to be applied when this state is set. 
    Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode. 
    Setting this mode to anything other than NO_BLEND will automatically switch blending on.
  */
  let getBlendMode = state => state |. _getBlendMode |. BLEND_MODES.tFromJs |. Belt.Option.getExn;

  /**
    The blend mode to be applied when this state is set. 
    Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode. 
    Setting this mode to anything other than NO_BLEND will automatically switch blending on.
  */
  let setBlendMode = (state, blendMode) => state |. _setBlendMode(BLEND_MODES.tToJs(blendMode));

  /**
    Specifies whether or not front or back-facing polygons can be culled
  */
  [@bs.get] external getClockwiseFrontFace: Js.t(#_t) => bool = "clockwiseFrontFace";

  /**
    Specifies whether or not front or back-facing polygons can be culled.
  */
  [@bs.set] external setClockwiseFrontFace: (Js.t(#_t), bool) => unit = "clockwiseFrontFace";

  /**
    Activates culling of polygons
  */
  [@bs.get] external getCulling: Js.t(#_t) => bool = "culling";

  /**
    Activates culling of polygons
  */
  [@bs.set] external setCulling: (Js.t(#_t), bool) => unit = "culling";

  /**
    Activates depth comparisons and updates to the depth buffer
  */
  [@bs.get] external getDepthTest: Js.t(#_t) => bool = "depthTest";

  /**
    Activates depth comparisons and updates to the depth buffer
  */
  [@bs.set] external setDepthTest: (Js.t(#_t), bool) => unit = "depthTest";

  /**
    Activates adding an offset to depth values of polygon's fragments
  */
  [@bs.get] external getOffsets: Js.t(#_t) => bool = "offsets";

  /**
    Activates adding an offset to depth values of polygon's fragments
  */
  [@bs.set] external setOffsets: (Js.t(#_t), bool) => unit = "offsets";

  /**
    The polygon offset. 
    Setting this property to anything other than 0 will automatically enable polygon offset fill
  */
  [@bs.get] external getPolygonOffset: Js.t(#_t) => bool = "polygonOffset";

  /**
    The polygon offset. 
    Setting this property to anything other than 0 will automatically enable polygon offset fill
  */
  [@bs.set] external setPolygonOffset: (Js.t(#_t), bool) => unit = "polygonOffset";
}

include Impl;