class type _t = [@bs] {
  /** 
    Number of instances in this geometry, pass it to GeometrySystem.draw() 
   */
  pub instanceCount: int;

  /**
    Count of existing (not destroyed) meshes that reference this geometry
   */
  pub refCount: int;

  /** 
    Adds an attribute to the geometry 
   */
  pub addAttribute: (string, Js.Undefined.t(Buffer.t), Js.Undefined.t(int), Js.Undefined.t(bool), Js.Undefined.t(int), Js.Undefined.t(int), Js.Undefined.t(int)) => Js.t(_t);
  
  /**
    Adds an index buffer to the geometry The index buffer contains integers, 
    three for each triangle in the geometry, which reference the various attribute buffers (position, colour, UV coordinates, other UV coordinates, normal, …). 
    There is only ONE index buffer.
   */
  pub addIndex: Js.Undefined.t(Buffer.t) => Js.t(_t);

  /**
    returns a clone of the geometry
   */
  pub clone: unit => Js.t(_t);

  /**
    Destroys the geometry.
   */
  pub destroy: unit => unit;

  /**
    disposes WebGL resources that are connected to this geometry
   */
  pub dispose: unit => unit;

  /**
    returns the requested attribute
   */
  pub getAttribute: string => Attribute.t;

  /**
    returns the requested buffer
   */
  pub getBuffer: string => Buffer.t;

  /**
    returns the index buffer
   */
  pub getIndex: unit => Buffer.t;

  /**
    this function modifies the structure so that all current attributes become interleaved into a single buffer 
    This can be useful if your model remains static as it offers a little performance boost
   */
  pub interleave: unit => Js.t(_t); 
};

/**
  The Geometry represents a model. It consists of two components:

  GeometryStyle - The structure of the model such as the attributes layout
  GeometryData - the data of the model - this consists of buffers. This can include anything from positions, uvs, normals, colors etc.
  Geometry can be defined without passing in a style or data if required (thats how I prefer!)
 */
type t = Js.t(_t);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: (~buffers: array(Buffer.t)=?, ~attributes: Js.t({..})=?, unit) => t = "Geometry";

  /**
    merges an array of geometries 
    into a new single one geometry attribute styles must match for this operation to work
   */
  [@bs.val][@bs.module "pixi.js"][@bs.scope "Geometry"]
  external merge: (~geometries: array(t)) => t = "merge";

  /** 
    Number of instances in this geometry, pass it to GeometrySystem.draw() 
   */
  [@bs.get] external getInstanceCount: Js.t(#_t) => int = "instanceCount";

  /**
    Count of existing (not destroyed) meshes that reference this geometry
   */
  [@bs.get] external getRefCount: Js.t(#_t) => int = "refCount";

  [@bs.send]
  external _addAttribute: (t, 
    ~id: string, 
    ~buffer: Buffer.t=?, 
    ~size: int=?, 
    ~normalized: bool=?, 
    ~_type: int=?,
    ~stride: int=?, 
    ~start: int=?, 
    unit) => t = "addAttribute";

  /**
    Adds an attribute to the geometry

      @param id the name of the attribute (matching up to a shader)
      @param buffer the buffer that holds the data of the attribute . You can also provide an Array and a buffer will be created from it.
      @param size the size of the attribute. If you have 2 floats per vertex (eg position x and y) this would be 2
      @param normalized should the data be normalized.
      @param type what type of number is the attribute. Check {PIXI.TYPES} to see the ones available
      @param stride How far apart (in floats) the start of each value is. (used for interleaving data)
      @param start How far into the array to start reading values (used for interleaving data)
   */
  let addAttribute = (
    t, 
    ~id: string, 
    ~buffer: option(Buffer.t)=?, 
    ~size: option(TYPES.t)=?, 
    ~normalized: option(bool)=?, 
    ~_type: option(int)=?, 
    ~stride: option(int)=?, 
    ~start: option(int)=?, 
    ()
  ) => _addAttribute(t, ~id, ~buffer?, ~size=?switch(size){ | Some(size) => Some(TYPES.tToJs(size)) | _ => None }, ~normalized?, ~_type?, ~stride?, ~start?, ());

  /**
    Adds an index buffer to the geometry The index buffer contains integers, three for each triangle in the geometry, 
    which reference the various attribute buffers (position, colour, UV coordinates, other UV coordinates, normal, …). 
    There is only ONE index buffer.
   */
  [@bs.send]
  external addIndex: (t, ~buffer: Buffer.t=?, unit) => t = "addIndex";

  /**
    returns a clone of the geometry
   */
  [@bs.send]
  external clone: t => t = "clone";

  /**
    Destroys the geometry.
   */
  [@bs.send]
  external destroy: t => unit = "destroy";

  /**
    disposes WebGL resources that are connected to this geometry
   */
  [@bs.send]
  external dispose: t => unit = "dispose";

  /**
    returns the requested attribute
   */
  [@bs.send]
  external getAttribute: (t, ~id: string) => Attribute.t = "getAttribute";

  /**
    returns the requested buffer
   */
  [@bs.send]
  external getBuffer: (t, ~id: string) => Buffer.t = "getBuffer";

  /**
    returns the index buffer
   */
  [@bs.send]
  external getIndex: t => Buffer.t = "getIndex";

  /**
    this function modifies the structure so that all current attributes become interleaved into a single buffer 
    This can be useful if your model remains static as it offers a little performance boost
   */
  [@bs.send]
  external interleave: t => t = "interleave";
}

include Impl;