class type _t = [@bs] {
  inherit C.container;

  /**
    The blend mode to be applied to the Mesh. Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode.
   */
  [@bs.set] pub blendMode: int;

  /**
    The way the Mesh should be drawn, can be any of the PIXI.DRAW_MODES constants.
   */
  [@bs.set] pub drawMode: int;

  /**
    Includes vertex positions, face indices, normals, colors, UVs, and custom attributes within buffers, reducing the cost of passing all this data to the GPU. 
    Can be shared between multiple Mesh objects.
   */
  pub geometry: Geometry.t;

  /**
    Alias for PIXI.Mesh#shader.
   */
  [@bs.set] pub material: MeshMaterial.t;

  /**
    If true PixiJS will Math.floor() x/y values when rendering, stopping pixel interpolation. 
    Advantages can include sharper image quality (like text) and faster rendering on canvas. 
    The main disadvantage is movement of objects may appear less smooth. 
    To set the global default, change PIXI.settings.ROUND_PIXELS
   */
  [@bs.set] pub roundPixels: bool;

  /**
    Represents the vertex and fragment shaders that processes the geometry and runs on the GPU. 
    Can be shared between multiple Mesh objects.
   */
  [@bs.set] pub shader: Shader.t;

  /**
    How much of the geometry to draw, by default 0 renders everything.s
   */
  [@bs.set] pub size: float;

  /**
    Typically the index of the IndexBuffer where to start drawing.
   */
  [@bs.set] pub start: int;

  /**
    Represents the WebGL state the Mesh required to render, excludes shader and geometry. 
    E.g., blend mode, culling, depth testing, direction of rendering triangles, backface, etc.
   */
  [@bs.set] pub state: State.t;

  /**
    The texture that the Mesh uses.
   */
  [@bs.set] pub texture: Texture.t;

  /**
    The multiply tint applied to the Mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
   */
  [@bs.set] pub tint: int;

  /**
    To change mesh uv's, change its uvBuffer data and increment its _updateID.
   */
  pub uvBuffer: Buffer.t;

  /**
    To change mesh vertices, change its uvBuffer data and increment its _updateID.
    Incrementing _updateID is optional because most of Mesh objects do it anyway.
   */
  pub verticesBuffer: Buffer.t;

  /**
    Updates uv field based on from geometry uv's or batchUvs
   */
  pub calculateUvs: unit => unit;

  /**
    Updates vertexData field based on transform and vertices
   */
  pub calculateVertices: unit => unit;

  /**
    Tests if a point is inside this mesh. Works only for PIXI.DRAW_MODES.TRIANGLES.
   */
  pub containsPoint: Point.t => bool;
};

/**
  Base mesh class.
  This class empowers you to have maximum flexibility to render any kind of WebGL visuals you can think of. This class assumes a certain level of WebGL knowledge. If you know a bit this should abstract enough away to make you life easier!
  Pretty much ALL WebGL can be broken down into the following:

  Geometry - The structure and data for the mesh. This can include anything from positions, uvs, normals, colors etc..
  Shader - This is the shader that PixiJS will render the geometry with (attributes in the shader must match the geometry)
  State - This is the state of WebGL required to render the mesh.
  Through a combination of the above elements you can render anything you want, 2D or 3D!
 */
type t = Js.t(_t);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external _create: (~geometry: Geometry.t, ~shader: [@bs.unwrap] [`Shader(Shader.t) | `MeshMaterial(MeshMaterial.t)], ~state: State.t=?, ~drawMode: int=?, unit) => Js.t(#_t) = "Mesh";

  /**
    creates a new mesh instance

      @param geometry the geometry the mesh will use
      @param shader the shader the mesh will use
      @param state the state that the WebGL context is required to be in to render the mesh if no state is provided, uses PIXI.State.for2d to create a 2D state for PixiJS.
      @param drawMode the drawMode, can be any of the PIXI.DRAW_MODES consts
   */
  let create = (
    ~geometry: Geometry.t,
    ~shader, 
    ~state: option(State.t)=?, 
    ~drawMode: option(DRAW_MODES.t)=?, 
    ()
  ) => _create(~geometry, ~shader, ~state?, ~drawMode=?switch(drawMode){ | Some(mode) => Some(DRAW_MODES.tToJs(mode)) | _ => None }, ());

  /**
    The maximum number of vertices to consider batchable. Generally, the complexity of the geometry.
   */
  [@bs.val][@bs.module "pixi.js"][@bs.scope "Mesh"]
  external batchableSize: int = "BATCHABLE_SIZE";

  /**
    The maximum number of vertices to consider batchable. Generally, the complexity of the geometry.
   */
  let getBlendMode: Js.t(#_t) => BLEND_MODES.t = entity => BLEND_MODES.tFromJs(entity##blendMode) |. Belt.Option.getExn;
  
  /**
    The way the Mesh should be drawn, can be any of the PIXI.DRAW_MODES constants.
   */
  let getDrawMode: Js.t(#_t) => DRAW_MODES.t = entity => DRAW_MODES.tFromJs(entity##drawMode) |. Belt.Option.getExn;
  
  /**
    The blend mode to be applied to the Mesh. Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode.
   */
  let setBlendMode = (entity: Js.t(#_t), blendMode: BLEND_MODES.t) => { entity##blendMode #= (blendMode |. BLEND_MODES.tToJs) };
  
  /**
    The blend mode to be applied to the Mesh. Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode
   */
  let setDrawMode = (entity: Js.t(#_t), drawMode: DRAW_MODES.t) => { entity##drawMode #= (drawMode |. DRAW_MODES.tToJs) };

  /**
    Includes vertex positions, face indices, normals, colors, UVs, and custom attributes within buffers, reducing the cost of passing all this data to the GPU. 
    Can be shared between multiple Mesh objects.
   */
  [@bs.get] external getGeometry: Js.t(#_t) => Js.t(#Geometry._t) = "geometry";

  /**
    Alias for PIXI.Mesh#shader.
   */
  [@bs.get] external getMaterial: Js.t(#_t) => Js.t(#MeshMaterial._t) = "material";

  /**
    Alias for PIXI.Mesh#shader.
   */
  [@bs.set] external setMaterial: (Js.t(#_t), Js.t(#MeshMaterial._t)) => unit = "material";

  /**
    If true PixiJS will Math.floor() x/y values when rendering, stopping pixel interpolation. 
    Advantages can include sharper image quality (like text) and faster rendering on canvas. 
    The main disadvantage is movement of objects may appear less smooth. 
    To set the global default, change PIXI.settings.ROUND_PIXELS
   */
  [@bs.get] external getRoundPixels: Js.t(#_t) => bool = "roundPixels";

  /**
    If true PixiJS will Math.floor() x/y values when rendering, stopping pixel interpolation. 
    Advantages can include sharper image quality (like text) and faster rendering on canvas. 
    The main disadvantage is movement of objects may appear less smooth. 
    To set the global default, change PIXI.settings.ROUND_PIXELS
   */
  [@bs.set] external setRoundPixels: (Js.t(#_t), bool) => unit = "roundPixels";

  /**
    Represents the vertex and fragment shaders that processes the geometry and runs on the GPU. 
    Can be shared between multiple Mesh objects.
   */
  [@bs.get] external getShader: Js.t(#_t) => Js.t(#Shader._t) = "shader";

  /**
    Represents the vertex and fragment shaders that processes the geometry and runs on the GPU. 
    Can be shared between multiple Mesh objects.
   */
  [@bs.set] external setShader: (Js.t(#_t), Js.t(#Shader._t)) => unit = "shader";

  /**
    How much of the geometry to draw, by default 0 renders everything.
   */
  [@bs.get] external getSize: Js.t(#_t) => float = "size";

  /**
    How much of the geometry to draw, by default 0 renders everything.
   */
  [@bs.set] external setSize: (Js.t(#_t), float) => unit = "size";

  /**
    Typically the index of the IndexBuffer where to start drawing.
   */
  [@bs.get] external getStart: Js.t(#_t) => int = "start";

  /**
    Typically the index of the IndexBuffer where to start drawing.
   */
  [@bs.set] external setStart: (Js.t(#_t), int) => unit = "start";

  /**
    Represents the WebGL state the Mesh required to render, excludes shader and geometry. 
    E.g., blend mode, culling, depth testing, direction of rendering triangles, backface, etc.
   */
  [@bs.get] external getState: Js.t(#_t) => Js.t(#State._t) = "state";

  /**
    Represents the WebGL state the Mesh required to render, excludes shader and geometry. 
    E.g., blend mode, culling, depth testing, direction of rendering triangles, backface, etc.
   */
  [@bs.set] external setState: (Js.t(#_t), Js.t(#State._t)) => unit = "state";

  /**
    The texture that the Mesh uses.
   */
  [@bs.get] external getTexture: Js.t(#_t) => Js.t(#Texture._t) = "texture";

  /**
    The texture that the Mesh uses.
   */
  [@bs.set] external setTexture: (Js.t(#_t),Js.t(#Texture._t)) => unit = "texture";

  /**
    The multiply tint applied to the Mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
   */
  [@bs.get] external getTint: Js.t(#_t) => int = "tint";

  /**
    The multiply tint applied to the Mesh. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
   */
  [@bs.set] external setTint: (Js.t(#_t), int) => unit = "tint";

  /**
    To change mesh uv's, change its uvBuffer data and increment its _updateID.
   */
  [@bs.get] external getUvBuffer: Js.t(#_t) => Js.t(#Buffer._t) = "uvBuffer";

  /**
    To change mesh vertices, change its uvBuffer data and increment its _updateID.
    Incrementing _updateID is optional because most of Mesh objects do it anyway.
   */
  [@bs.get] external getVerticesBuffer: Js.t(#_t) => Js.t(#Buffer._t) = "verticesBuffer";

  /**
    Updates uv field based on from geometry uv's or batchUvs
   */
  [@bs.send]
  external calculateUvs: Js.t(#_t) => unit = "calculateUvs";

  /**
    Updates vertexData field based on transform and vertices
   */
  [@bs.send]
  external calculateVertices: Js.t(#_t) => unit = "calculateVertices";

  /**
    Tests if a point is inside this mesh. Works only for PIXI.DRAW_MODES.TRIANGLES.
   */
  [@bs.send]
  external containsPoint: (Js.t(#_t), ~point: Point.t) => bool = "containsPoints";

  /**
    Destroys the Mesh object.
   */
  [@bs.send]
  external destroy: (Js.t(#_t), ~options: Js.t({ . children: bool })=?, unit) => unit = "destroy";
};

include EventEmitter.Impl;
include DisplayObject.Impl;
include Container.Impl;
include Impl;