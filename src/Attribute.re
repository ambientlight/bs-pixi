class type _t = {
  /** Destroys the Attribute */
  pub destroy: unit => unit;
};

/**
  Holds the information for a single attribute structure required to render geometry.
  This does not contain the actual data, but instead has a buffer id that maps to a PIXI.Buffer 
  This can include anything from positions, uvs, normals, colors etc.
 */
type t = Js.t(_t);

[@bs.module "pixi.js"][@bs.new]
external create: (
  ~buffer: string=?, 
  ~size: int=?, 
  ~normalized: bool=?, 
  ~_type: int=?, 
  ~stride: int=?, 
  ~start: int=?, 
  unit) => t = "Attribute";

/**
  Helper function that creates an Attribute based on the information provided
 */
[@bs.module "pixi.js"][@bs.scope "Attribute"]
external from: ( 
  ~buffer: string=?, 
  ~size: int=?, 
  ~stride: int=?, 
  ~start: int=?, 
  ~_type: int=?,
  ~stride: int=?, 
  unit) => t = "from";

/**
  Destroys the Attribute
 */
[@bs.send]
external destroy: Js.t(#_t) => unit = "destroy";