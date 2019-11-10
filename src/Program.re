class type _t = [@bs] {
  /**
    The fragment shader
   */
  [@bs.set] pub fragmentSrc: string;

  /**
    The vertex shader.
   */
  [@bs.set] pub vertexSrc: string;
};

/**
  Helper class to create a shader program
 */
type t = Js.t(_t);

/**
  creates a new shader program

    @param vertexSrc The source of the vertex shader
    @param fragmentSrc The source of the fragment shader.
    @param name Name for shader
 */
[@bs.module "pixi.js"][@bs.new]
external create: (~vertexSrc: string=?, ~fragmentSrc: string=?, ~name: string=?, unit) => t = "Program";

/**
  The default fragment shader source
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Program"]
external defaultFragmentSrc: string = "defaultFragmentSrc";

/**
  The default vertex shader source
 */
[@bs.val][@bs.module "pixi.js"][@bs.scope "Program"]
external defaultVertexSrc: string = "defaultVertexSrc";

/**
  The fragment shader
 */
[@bs.get] external getFragmentSrc: Js.t(#_t) => string = "fragmentSrc";

/**
  The fragment shader
 */
[@bs.set] external setFragmentSrc: (Js.t(#_t), string) => unit = "fragmentSrc";

/**
  The vertex shader
 */
[@bs.get] external getVertexSrc: Js.t(#_t) => string = "vertexSrc";

/**
  The vertex shader
 */
[@bs.set] external setVertexSrc: (Js.t(#_t), string) => unit = "vertexSrc";

/**
  A short hand function to create a program based of a vertex and 
  fragment shader this method will also check to see if there is a cached program

    @param vertexSrc The source of the vertex shader
    @param fragmentSrc The source of the fragment shader.
    @param name Name for shader
    @return a shiny new Pixi shader!
 */
[@bs.module "pixi.js"][@bs.scope "Program"]
external from: (~vertexSrc: string=?, ~fragmentSrc: string=?, ~uniforms: Js.t({..})=?, unit) => t = "from";