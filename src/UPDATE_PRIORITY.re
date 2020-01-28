/**
  Represents the update priorities used by internal 
  PIXI classes when registered with the PIXI.Ticker object. 
  Higher priority items are updated first and lower priority items, such as render, should go later.
 */
[@bs.deriving jsConverter]
type t = 
  | [@bs.as -50] Utility
  | [@bs.as -25] Low
  | [@bs.as 0] Normal
  | [@bs.as 25] High
  | [@bs.as 50] Interaction;

/**
  Lowest priority used for PIXI.prepare.BasePrepare utility.
 */
let utility = -50; 

/**
  Low priority used for PIXI.Application rendering.
 */
let low = -25;

/**
  Default priority for ticker events, see PIXI.Ticker#add.
 */
let normal = 0;

/**
  High priority updating, PIXI.VideoBaseTexture and PIXI.AnimatedSprite
 */
let high = 25;

/**
  Highest priority, used for PIXI.interaction.InteractionManager
 */
let interaction = 50;