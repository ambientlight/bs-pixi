/**
  The base class for all objects that are rendered on the screen.
  This is an abstract class and should not be used on its own; rather it should be extended
 */
type t = Js.t(C.displayObject);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: unit => t = "DisplayObject";

  /**
    Flag for if the object is accessible. If true AccessibilityManager will overlay a shadow div with attributes set
  */
  [@bs.get] external getAccessible: Js.t(#C.displayObject) => bool = "accessible";

  /**
    Flag for if the object is accessible. If true AccessibilityManager will overlay a shadow div with attributes set
  */
  [@bs.set] external setAccessible: (Js.t(#C.displayObject), bool) => unit = "accessible";

  /**
    Setting to false will prevent any children inside this container to be accessible. Defaults to true
  */
  [@bs.get] external getAccessibleChildren: Js.t(#C.displayObject) => bool = "accessibleChildren";

  /**
    Setting to false will prevent any children inside this container to be accessible. Defaults to true
  */
  [@bs.set] external setAccessibleChildren: (Js.t(#C.displayObject), bool) => unit = "accessibleChildren";

  /**
    Sets the aria-label attribute of the shadow div
  */
  [@bs.get] external getAccessibleHint: Js.t(#C.displayObject) => string = "accessibleHint";

  /**
    Sets the aria-label attribute of the shadow div
  */
  [@bs.set] external setAccessibleHint: (Js.t(#C.displayObject), string) => unit = "accessibleHint";

  /**
    Sets the title attribute of the shadow div 
    If accessibleTitle AND accessibleHint has not been this will default to 'displayObject [tabIndex]'
  */
  [@bs.get] external getAccessibleTitle: Js.t(#C.displayObject) => Js.Nullable.t(string) = "accessibleTitle";

  /**
    Sets the title attribute of the shadow div 
    If accessibleTitle AND accessibleHint has not been this will default to 'displayObject [tabIndex]'
  */
  [@bs.set] external setAccessibleTitle: (Js.t(#C.displayObject),Js.Nullable.t(string)) => unit = "accessibleTitle";

  /**
    Specify the type of div the accessible layer is. 
    Screen readers treat the element differently depending on this type. Defaults to button.
  */
  [@bs.get] external getAccessibleType: Js.t(#C.displayObject) => string = "accessibleType";
      
  /**
    Specify the type of div the accessible layer is. 
    Screen readers treat the element differently depending on this type. Defaults to button.
  */
  [@bs.set] external setAccessibleType: (Js.t(#C.displayObject), string) => unit = "accessibleType";

  /**
    The opacity of the object
  */
  [@bs.get] external getAlpha: Js.t(#C.displayObject) => float = "alpha";

  /**
    The opacity of the object
  */
  [@bs.set] external setAlpha: (Js.t(#C.displayObject), float) => unit = "alpha";

  /**
    The angle of the object in degrees. 
    'rotation' and 'angle' have the same effect on a display object; rotation is in radians, angle is in degrees
  */
  [@bs.get] external getAngle: Js.t(#C.displayObject) => float = "angle";

  /**
    The angle of the object in degrees. 
    'rotation' and 'angle' have the same effect on a display object; rotation is in radians, angle is in degrees
  */
  [@bs.set] external setAngle: (Js.t(#C.displayObject), float) => unit = "angle";

  /**
    If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject 
    if it is interactive Setting this changes the 'cursor' property to 'pointer'.
  */
  [@bs.get] external getButtonMode: Js.t(#C.displayObject) => bool = "buttonMode";

  /**
    If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject 
    if it is interactive Setting this changes the 'cursor' property to 'pointer'.
  */
  [@bs.set] external setButtonMode: (Js.t(#C.displayObject), bool) => unit = "buttonMode";

  /**
    Set this to true if you want this display object to be cached as a bitmap. 
    This basically takes a snap shot of the display object as it is at that moment. 
    It can provide a performance benefit for complex static displayObjects. 
    To remove simply set this property to false
    
    IMPORTANT GOTCHA - Make sure that all your textures are preloaded 
    BEFORE setting this property to true as it will take a snapshot of what is currently there. 
    If the textures have not loaded then they will not appear.
  */
  [@bs.get] external getCacheAsBitmap: Js.t(#C.displayObject) => bool = "cacheAsBitmap";

  /**
    Set this to true if you want this display object to be cached as a bitmap. 
    This basically takes a snap shot of the display object as it is at that moment. 
    It can provide a performance benefit for complex static displayObjects. 
    To remove simply set this property to false
    
    IMPORTANT GOTCHA - Make sure that all your textures are preloaded 
    BEFORE setting this property to true as it will take a snapshot of what is currently there. 
    If the textures have not loaded then they will not appear.
  */
  [@bs.set] external setCacheAsBitmap: (Js.t(#C.displayObject), bool) => unit = "cacheAsBitmap";

  /**
    The area the filter is applied to. 
    This is used as more of an optimization rather than figuring out 
    the dimensions of the displayObject each frame you can set this rectangle.
    Also works as an interaction mask.
  */
  [@bs.get] external getCursor: Js.t(#C.displayObject) => string = "cursor";

  /**
    The area the filter is applied to. 
    This is used as more of an optimization rather than figuring out 
    the dimensions of the displayObject each frame you can set this rectangle.
    Also works as an interaction mask.
  */
  [@bs.set] external setCursor: (Js.t(#C.displayObject), string) => unit = "cursor";
}

include EventEmitter.Impl;
include Impl;