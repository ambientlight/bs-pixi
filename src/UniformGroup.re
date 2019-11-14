[@bs.deriving abstract]
type t = {
  /**
    dirty version
   */
  mutable dirtyId: int,

  /**
    Its a group and not a single uniforms
   */
  group: bool,

  /**
    unique id
   */
  mutable id: int,

  /**
    Uniforms wont be changed after creation
   */
  static: bool,

  /**
    uniform values
   */
  uniforms: Js.t({.})
};