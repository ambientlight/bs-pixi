/**
  used to resolve dependency cycle
  src/C-PIXI.cmj -> src/Filter-PIXI.cmj -> src/RenderTexture-PIXI.cmj -> src/BaseRenderTexture-PIXI.cmj -> src/MaskData-PIXI.cmj -> src/C-PIXI.cmj

  until this is resolved,
  feel free to force cast it with Obj.magic to DisplayObject.t or any structural subtype of Js.t(#C.displayObject)
 */
type displayObjectOpaque;

class type _t = [@bs] {
  /**
    Scissor operation above the mask in stack. 
    Null if _scissorCounter is zero, rectangle instance if positive.
   */
  [@bs.set] pub _scissorRect: Rectangle.t;

  /**
    Whether we know the mask type beforehand
   */
  [@bs.set] pub autoDetect: bool;

  /**
    Indicator of the type
   */
  [@bs.set] pub isMaskData: bool;

  /**
    Which element we use to mask
   */
  [@bs.set] pub maskObject: displayObjectOpaque;

  /**
    Whether it belongs to MaskSystem pool
   */
  [@bs.set] pub pooled: bool;

  // for type see MaskData.getType

  /**
    copies counters from maskData above, called from pushMask()

      @param maskAbove
   */
  pub copyCountersOrReset: Js.Nullable.t(Js.t(_t)) => unit;

  /**
    resets the mask data after popMask()
   */
  pub reset: unit => unit;
};

/**
  Component for masked elements
  Holds mask mode and temporary data about current mask
 */
type t = Js.t(_t);

module Impl {
  /**
    Create MaskData

      @param maskObject object that describes the mask
  */
  [@bs.module "pixi.js"][@bs.new]
  external create: (~maskObject: displayObjectOpaque=?, unit) => t = "MaskData";

  /**
    Scissor operation above the mask in stack. 
    Null if _scissorCounter is zero, rectangle instance if positive.
  */
  [@bs.get] external get_scissorRect: Js.t(#_t) => Js.t(#Rectangle._t) = "_scissorRect";

  /**
    Scissor operation above the mask in stack. 
    Null if _scissorCounter is zero, rectangle instance if positive.
  */
  [@bs.set] external set_scissorRect: (Js.t(#_t), Js.t(#Rectangle._t)) => unit = "_scissorRect";

  /**
    Whether we know the mask type beforehand
  */
  [@bs.get] external getAutoDetect: Js.t(#_t) => bool = "autoDetect";

  /**
    Whether we know the mask type beforehand
  */
  [@bs.set] external setAutoDetect: (Js.t(#_t), bool) => unit = "autoDetect";

  /**
    Indicator of the type
  */
  [@bs.get] external getIsMaskData: Js.t(#_t) => bool = "isMaskData";

  /**
    Indicator of the type
  */
  [@bs.set] external setIsMaskData: (Js.t(#_t), bool) => unit = "isMaskData";

  /**
    Which element we use to mask
  */
  [@bs.get] external getMaskObject: Js.t(#_t) => displayObjectOpaque = "maskObject";

  /**
    Which element we use to mask
  */
  [@bs.set] external setMaskObject: (Js.t(#_t), displayObjectOpaque) => unit = "maskObject";

  /**
    Whether it belongs to MaskSystem pool
  */
  [@bs.get] external getPooled: Js.t(#_t) => bool = "pooled";

  /**
    Whether it belongs to MaskSystem pool
  */
  [@bs.set] external setPooled: (Js.t(#_t), bool) => unit = "pooled";


  [@bs.get] external _getType: Js.t(#_t) => int = "type";

  /**
    Mask type
  */
  let getType = maskData => maskData |. _getType |. MASK_TYPES.tFromJs |. Belt.Option.getExn;

  [@bs.set] external _setType: (Js.t(#_t), int) => unit = "type";

  /**
    Mask type
  */
  let setType = (maskData, maskType) => maskData |. _setType(maskType |. MASK_TYPES.tToJs);

  /**
    copies counters from maskData above, called from pushMask()

      @param maskAbove
  */
  [@bs.send]
  external copyCountersOrReset: (Js.t(#_t), ~maskAbove: Js.Nullable.t(Js.t(#_t))) => unit = "copyCountersOrReset";

  /**
    resets the mask data after popMask()
  */
  [@bs.send]
  external reset: Js.t(#_t) => unit = "reset";
}

include Impl;