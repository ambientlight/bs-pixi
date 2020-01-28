class type _t = [@bs] {
  inherit Shader._t;

  /**
    This gets automatically set by the object using this.
   */
  [@bs.set] pub alpha: float;

  /**
    true if shader can be batch with the renderer's batch system.
   */
  [@bs.set] pub batchable: bool;
  
  /**
    Renderer plugin for batching
   */
  [@bs.set] pub pluginName: string;

  /**
    Reference to the texture being rendered.
   */
  [@bs.set] pub texture: Texture.t;

  /**
    Multiply tint for the material.
   */
  [@bs.set] pub tint: int;

  /**
    TextureMatrix instance for this Mesh, used to track Texture changes
   */
  pub uvMatrix: TextureMatrix.t;

  /**
    Gets called automatically by the Mesh. Intended to be overridden for custom MeshMaterial objects.
   */
  pub update: unit => unit;
};

[@bs.obj]
external createMeshMaterialOptions: (
  ~alpha: int=?,
  ~tint: int=?,
  ~pluginName: string=?,
  ~program: Program.t=?,
  ~uniforms: Js.t({..})=?,
  unit
) => _ = "";

/** Slightly opinionated default shader for PixiJS 2D objects. */
type t = Js.t(_t);

module Impl {

  [@bs.module "pixi.js"][@bs.new]
  external _create: (~uSampler: Texture.t, ~options: 'a=?, unit) => t = "MeshMaterial";

  let create = (~uSampler, ~options=createMeshMaterialOptions(()), ()) => _create(~uSampler, ~options, ());

  /**
    This gets automatically set by the object using this.
   */
  [@bs.get] external getAlpha: Js.t(#_t) => float = "alpha";

  /**
    This gets automatically set by the object using this.
   */
  [@bs.set] external setAlpha: (Js.t(#_t), float) => unit = "alpha";

  /**
    true if shader can be batch with the renderer's batch system.
   */
  [@bs.get] external getBatchable: Js.t(#_t) => bool = "batchable";

  /**
    true if shader can be batch with the renderer's batch system.
   */
  [@bs.set] external setBatchable: (Js.t(#_t), bool) => unit = "batchable";

  /**
    Renderer plugin for batching
   */
  [@bs.get] external getPluginName: Js.t(#_t) => string = "pluginName";

  /**
    Renderer plugin for batching
   */
  [@bs.set] external setPluginName: (Js.t(#_t), string) => unit = "pluginName";

  /**
    Reference to the texture being rendered.
   */
  [@bs.get] external getTexture: Js.t(#_t) => string = "texture";

  /**
    Reference to the texture being rendered.
   */
  [@bs.set] external setTexture: (Js.t(#_t), string) => unit = "texture";

  /**
    Multiply tint for the material.
   */
  [@bs.get] external getTint: Js.t(#_t) => int = "tint";

  /**
    Multiply tint for the material.
   */
  [@bs.set] external setTint: (Js.t(#_t), int) => unit = "tint";

  /**
    TextureMatrix instance for this Mesh, used to track Texture changes
   */
  [@bs.get] external getUVMatrix: Js.t(#_t) => TextureMatrix.t = "uvMatrix";

  /**
    Gets called automatically by the Mesh. Intended to be overridden for custom MeshMaterial objects.
   */
  [@bs.send]
  external update: t => unit = "update";
};

include Shader.Impl;
include Impl;