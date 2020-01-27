class type _t = [@bs] {
  /**
    Program that the shader uses
   */
  [@bs.set] pub program: Program.t;

  /**
    Shader uniform values, shortcut for uniformGroup.uniforms
   */
  pub uniforms: Js.t({..});
};

/**
  A helper class for shaders
 */
type t = Js.t(_t);

module Impl {
  /**
    creates a new shader

      @param program The program the shader will use
      @param uniforms Custom uniforms to use to augment the built-in ones
  */
  [@bs.module "pixi.js"][@bs.new]
  external create: (~program: Js.t(#Program._t)=?, ~uniforms: 'a=?, unit) => Js.t(#_t) = "Shader";

  /**
    Program that the shader uses
  */
  [@bs.get] external getProgram: Js.t(#_t) => Js.t(#Program._t) = "program";

  /**
    Program that the shader uses
  */
  [@bs.set] external setProgram: (Js.t(#_t), Js.t(#Program._t)) => unit = "program";

  /**
    Shader uniform values, shortcut for uniformGroup.uniforms
  */
  [@bs.get] external getUniforms: Js.t(#_t) => 'a = "uniforms";

  /**
    A short hand function to create a shader based of a vertex and fragment shader

      @param vertexSrc The source of the vertex shader
      @param fragmentSrc The source of the fragment shader.
      @param uniforms Custom uniforms to use to augment the built-in ones
      @return a shiny new Pixi shader
  */
  [@bs.module "pixi.js"][@bs.scope "Shader"]
  external from: (~vertexSrc: string=?, ~fragmentSrc: string=?, ~uniforms: 'a=?, unit) => Js.t(#_t) = "from";
}

include Impl;