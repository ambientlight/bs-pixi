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

  /**
    The area the filter is applied to. This is used as more of an optimization rather than figuring out the dimensions of the displayObject each frame you can set this rectangle.
    Also works as an interaction mask.
   */
  [@bs.get] external getFilterArea: Js.t(#C.displayObject) => Js.Nullable.t(Js.t(#Rectangle._t)) = "filterArea";

  /**
    The area the filter is applied to. This is used as more of an optimization rather than figuring out the dimensions of the displayObject each frame you can set this rectangle.
    Also works as an interaction mask.
   */
  [@bs.set] external setFilterArea: (Js.t(#C.displayObject), Js.Nullable.t(Js.t(#Rectangle._t))) => unit = "filterArea";

  /**
    Sets the filters for the displayObject.

    IMPORTANT: This is a WebGL only feature and will be ignored by the canvas renderer. 
    To remove filters simply set this property to 'null'.    
   */
  [@bs.get] external getFilters: Js.t(#C.displayObject) => Js.Nullable.t(array(Filter.t)) = "filters";

  /**
    Sets the filters for the displayObject.

    IMPORTANT: This is a WebGL only feature and will be ignored by the canvas renderer. 
    To remove filters simply set this property to 'null'.    
   */
  [@bs.set] external setFilters: (Js.t(#C.displayObject), Js.Nullable.t(array(Filter.t))) => unit = "filters";

  /**
    Interaction shape. Children will be hit first, then this shape will be checked. 
    Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
   */
  //TODO: implement IHitArea
  [@bs.get] external getHitArea: Js.t(#C.displayObject) => 'hitArea = "hitArea";

  /**
    Interaction shape. Children will be hit first, then this shape will be checked. 
    Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
   */
  //TODO: implement IHitArea
  [@bs.set] external setHitArea: (Js.t(#C.displayObject), 'hitArea) => unit = "hitArea";

  /**
    Enable interaction events for the DisplayObject. 
    Touch, pointer and mouse events will not be emitted unless interactive is set to true.
   */
  [@bs.get] external getInteractive: Js.t(#C.displayObject) => bool = "interactive";

  /**
    Enable interaction events for the DisplayObject. 
    Touch, pointer and mouse events will not be emitted unless interactive is set to true.
   */
  [@bs.set] external setInteractive: (Js.t(#C.displayObject), bool) => unit = "interactive";

  /**
    Does any other displayObject use this object as a mask?
   */
  [@bs.get] external getIsMask: Js.t(#C.displayObject) => bool = "isMask";

  /**
    used to fast check if a sprite is.. a sprite!
   */
  [@bs.get] external getIsSprite: Js.t(#C.displayObject) => bool = "isSprite";

  /**
    Current transform of the object based on local factors: position, scale, other stuff.
   */
  [@bs.get] external getLocalTransform: Js.t(#C.displayObject) => Js.t(#Matrix._t) = "localTransform";

  /**
    Sets a mask for the displayObject. A mask is an object that limits the visibility of an object 
    to the shape of the mask applied to it. 
    In PixiJS a regular mask must be a PIXI.Graphics or a PIXI.Sprite object. 
    This allows for much faster masking in canvas as it utilities shape clipping. 
    To remove a mask, set this property to null.

    For sprite mask both alpha and red channel are used. Black mask is the same as transparent mask.
   */
  /* TODO: PIXI.Graphics | PIXI.Sprite | null */
  [@bs.get] external getMask: Js.t(#C.displayObject) => 'mask = "mask";

  /**
    Sets a mask for the displayObject. A mask is an object that limits the visibility of an object 
    to the shape of the mask applied to it. 
    In PixiJS a regular mask must be a PIXI.Graphics or a PIXI.Sprite object. 
    This allows for much faster masking in canvas as it utilities shape clipping. 
    To remove a mask, set this property to null.

    For sprite mask both alpha and red channel are used. Black mask is the same as transparent mask.
   */
  /* TODO: PIXI.Graphics | PIXI.Sprite | null */
  [@bs.set] external setMask: (Js.t(#C.displayObject), 'mask) => unit = "mask";

  /**
    The instance name of the object.
   */
  [@bs.get] external getName: Js.t(#C.displayObject) => Js.Nullable.t(string) = "name";

  /**
    The instance name of the object.
   */
  [@bs.set] external setName: (Js.t(#C.displayObject), Js.Nullable.t(string)) => unit = "name";

  /**
    The display object container that contains this display object.
   */
  [@bs.get] external getParent: Js.t(#C.displayObject) => Js.Nullable.t(#C.container) = "parent";

  /**
    The pivot point of the displayObject that it rotates around. Assignment by value since pixi-v4.
   */
  [@bs.get] external getPivot: Js.t(#C.displayObject) => Js.t(#ObservablePoint._t) = "pivot";

  /**
    The pivot point of the displayObject that it rotates around. Assignment by value since pixi-v4.
   */
  [@bs.set] external setPivot: (Js.t(#C.displayObject), Js.t(#ObservablePoint._t)) => unit = "pivot";

  /**
    The coordinate of the object relative to the local coordinates of the parent. 
    Assignment by value since pixi-v4.
   */
  [@bs.get] external getPosition: Js.t(#C.displayObject) => Js.t(#ObservablePoint._t) = "position";

  /**
    The coordinate of the object relative to the local coordinates of the parent. 
    Assignment by value since pixi-v4.
   */
  [@bs.set] external setPosition: (Js.t(#C.displayObject), Js.t(#ObservablePoint._t)) => unit = "position";

  /**
    Can this object be rendered, if false the object will not be drawn but the updateTransform methods will still be called.
    Only affects recursive calls from parent. You can ask for bounds manually.
   */
  [@bs.get] external getRenderable: Js.t(#C.displayObject) => bool = "renderable";

  /**
    Can this object be rendered, if false the object will not be drawn but the updateTransform methods will still be called.
    Only affects recursive calls from parent. You can ask for bounds manually.
   */
  [@bs.set] external setRenderable: (Js.t(#C.displayObject), bool) => unit = "renderable";

  /**
    The rotation of the object in radians. 
    'rotation' and 'angle' have the same effect on a display object; rotation is in radians, angle is in degrees.
   */
  [@bs.get] external getRotation: Js.t(#C.displayObject) => float = "rotation";

  /**
    The rotation of the object in radians. 
    'rotation' and 'angle' have the same effect on a display object; rotation is in radians, angle is in degrees.
   */
  [@bs.set] external setRotation: (Js.t(#C.displayObject), float) => unit = "rotation";

  /**
    The scale factor of the object. Assignment by value since pixi-v4.
   */
  [@bs.get] external getScale: Js.t(#C.displayObject) => Js.t(#ObservablePoint._t) = "scale";

  /**
    The scale factor of the object. Assignment by value since pixi-v4.
   */
  [@bs.set] external setScale: (Js.t(#C.displayObject), Js.t(#ObservablePoint._t)) => unit = "scale";

  /**
    The skew factor for the object in radians. Assignment by value since pixi-v4.
   */
  [@bs.get] external getSkew: Js.t(#C.displayObject) => Js.t(#ObservablePoint._t) = "skew";

  /**
    The skew factor for the object in radians. Assignment by value since pixi-v4.
   */
  [@bs.set] external setSkew: (Js.t(#C.displayObject), Js.t(#ObservablePoint._t)) => unit = "skew";

  /**
    World transform and local transform of this object. 
    This will become read-only later, please do not assign anything there unless you know what are you doing.
   */
  [@bs.get] external getTransform: Js.t(#C.displayObject) => Js.t(#Transform._t) = "transform";

  /**
    World transform and local transform of this object. 
    This will become read-only later, please do not assign anything there unless you know what are you doing.
   */
  [@bs.set] external setTransform: (Js.t(#C.displayObject), Js.t(#Transform._t)) => unit = "transform";

  /**
    The visibility of the object. If false the object will not be drawn, and the updateTransform function will not be called.
    Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually.
   */
  [@bs.get] external getVisible: Js.t(#C.displayObject) => bool = "visible";

  /**
    The visibility of the object. If false the object will not be drawn, and the updateTransform function will not be called.
    Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually.
   */
  [@bs.set] external setVisible: (Js.t(#C.displayObject), bool) => unit = "visible";

  /**
    The multiplied alpha of the displayObject.
   */
  [@bs.get] external getWorldAlpha: Js.t(#C.displayObject) => float = "worldAlpha";

  /**
    Current transform of the object based on world (parent) factors.
   */
  [@bs.get] external getWorldTransform: Js.t(#C.displayObject) => Js.t(#Matrix._t) = "worldTransform";

  /**
    Indicates if the object is globally visible.
   */
  [@bs.get] external getWorldVisible: Js.t(#C.displayObject) => bool = "worldVisible";

  /**
    The position of the displayObject on the x axis relative to the local coordinates of the parent. 
    An alias to position.x
  */
  [@bs.get] external getX: Js.t(#C.displayObject) => float = "x";

  /**
    The position of the displayObject on the x axis relative to the local coordinates of the parent. 
    An alias to position.x
  */
  [@bs.set] external setX: (Js.t(#C.displayObject), float) => unit = "x";

  /**
    The position of the displayObject on the y axis relative to the local coordinates of the parent. 
    An alias to position.y
  */
  [@bs.get] external getY: Js.t(#C.displayObject) => float = "y";

  /**
    The position of the displayObject on the y axis relative to the local coordinates of the parent. 
    An alias to position.y
  */
  [@bs.set] external setY: (Js.t(#C.displayObject), float) => unit = "y";

  /**
    The zIndex of the displayObject. 
    If a container has the sortableChildren property set to true, children will be 
    automatically sorted by zIndex value; a higher value will mean it will be moved towards the end of the array, 
    and thus rendered on top of other displayObjects within the same container.
  */
  [@bs.get] external getZIndex: Js.t(#C.displayObject) => float = "zIndex";

  /**
    The zIndex of the displayObject. 
    If a container has the sortableChildren property set to true, children will be 
    automatically sorted by zIndex value; a higher value will mean it will be moved towards the end of the array, 
    and thus rendered on top of other displayObjects within the same container.
  */
  [@bs.set] external setZIndex: (Js.t(#C.displayObject), float) => unit = "zIndex";

  /**
    Recursively updates transform of all objects from the root to this one internal function for toLocal()
   */
  [@bs.send] external _recursivePostUpdateTransform: Js.t(#C.displayObject) => unit = "_recursivePostUpdateTransform";

  /**
    Base destroy method for generic display objects. 
    This will automatically remove the display object from its parent Container 
    as well as remove all current event listeners and internal references. 
    Do not use a DisplayObject after calling destroy().
   */
  [@bs.send] external destroy: Js.t(#C.displayObject) => unit = "destroy";

  /**
    Retrieves the bounds of the displayObject as a rectangle object.

      @param skipUpdate Setting to true will stop the transforms of the scene graph from being updated. 
        This means the calculation returned MAY be out of date BUT will give you a nice performance boost.
      @param rect Optional rectangle to store the result of the bounds calculation.
   */
  [@bs.send] external getBounds: (Js.t(#C.displayObject), ~skipUpdate: bool=?, ~rect: Js.t(#Rectangle._t)=?, unit) => Js.t(#Rectangle._t) = "getBounds";

  /**
    Returns the global position of the displayObject. 
    Does not depend on object scale, rotation and pivot.
   */
  [@bs.send] external getGlobalPosition: (Js.t(#C.displayObject), ~point: Js.t(#Point._t)=?, ~skipUpdate: bool=?, unit) => Js.t(#Point._t) = "getGlobaPosition";

  /**
    Retrieves the local bounds of the displayObject as a rectangle object
   */
  [@bs.send] external getLocalBounds: (Js.t(#C.displayObject), ~rectangle: Js.t(#Rectangle._t)=?, unit) => Js.t(#Rectangle._t) = "getLocalBounds";

  /**
    Set the parent Container of this DisplayObject.
   */
  [@bs.send] external setContainer: (Js.t(#C.displayObject), Js.t(#C.container as 'a)) => Js.t('a) = "setContainer";

  /**
    Convenience function to set the position, scale, skew and pivot at once.

      @param x Position on the x axis
      @param y Position on the y axis
      @param pivotX Pivot on the x axis
      @param pivotY Pivot on the y axis
      @param scaleX Scale on the x axis
      @param scaleY Scale on the y axis
      @param rotation rotation in radians
      @param skewX Skew on the x axis
      @param skewY Skew on the y axis
      @param pivotX The X pivot value
      @param pivotY The Y pivot value
      @return This display object
   */
  [@bs.send]
  external setTransform: (Js.t(#C.displayObject), ~x: float=?, ~y: float=?, ~scaleX: float=?, ~scaleY: float=?, ~rotation: float=?, ~skewX: float=?, ~skewY: float=?, ~pivotX: float=?, ~pivotY: float=?, unit) => t = "setTransform";  

  /**
    Calculates the global position of the display object.
   */
  [@bs.send]
  external toGlobal: (Js.t(#C.displayObject), ~position: [@bs.unwrap] [`Point(Point.t) | `ObservablePoint(ObservablePoint.t)], ~point: Point.t=?, ~skipUpdate: bool=?, unit) => Point.t = "toGlobal";

  /**
    Calculates the local position of the display object relative to another point.
   */
  [@bs.send]
  external toLocal: (Js.t(#C.displayObject), ~position: [@bs.unwrap] [`Point(Point.t) | `ObservablePoint(ObservablePoint.t)], ~from: t=?, ~point:Point.t=?, ~skipUpdate: bool=?, unit) => Point.t = "toLocal";

  /**
    Updates the object transform for rendering.
   */
  [@bs.send]
  external updateTransform: Js.t(#C.displayObject) => unit = "updateTransform";
}

include EventEmitter.Impl;
include Impl;