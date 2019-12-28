/**
  Contains declaration of co-dependent class types.
 */

class type displayObject = [@bs] {
  inherit EventEmitter._t;

  /**
    Flag for if the object is accessible. If true AccessibilityManager will overlay a shadow div with attributes set
   */
  [@bs.set] pub accessible: bool;

  /**
    Setting to false will prevent any children inside this container to be accessible. Defaults to true
   */
  [@bs.set] pub accessibleChildren: bool;

  /**
    Sets the aria-label attribute of the shadow div
   */
  [@bs.set] pub accessibleHint: string;

  /**
    Sets the title attribute of the shadow div 
    If accessibleTitle AND accessibleHint has not been this will default to 'displayObject [tabIndex]'
   */
  [@bs.set] pub accessibleTitle: Js.Nullable.t(string);

  /**
    Specify the type of div the accessible layer is. 
    Screen readers treat the element differently depending on this type. Defaults to button.
   */
  [@bs.set] pub accessibleType: string;

  /**
    The opacity of the object.
   */
  [@bs.set] pub alpha: float;

  /**
    The angle of the object in degrees. 
    'rotation' and 'angle' have the same effect on a display object; rotation is in radians, angle is in degrees
   */
  [@bs.set] pub angle: float;

  /**
    If enabled, the mouse cursor use the pointer behavior when hovered over the displayObject 
    if it is interactive Setting this changes the 'cursor' property to 'pointer'.
   */
  [@bs.set] pub buttonMode: bool;

  /**
    Set this to true if you want this display object to be cached as a bitmap. 
    This basically takes a snap shot of the display object as it is at that moment. 
    It can provide a performance benefit for complex static displayObjects. 
    To remove simply set this property to false

    IMPORTANT GOTCHA - Make sure that all your textures are preloaded 
    BEFORE setting this property to true as it will take a snapshot of what is currently there. 
    If the textures have not loaded then they will not appear.
   */
  [@bs.set] pub cacheAsBitmap: bool;

  /**
    This defines what cursor mode is used when the mouse cursor is hovered over the displayObject.
   */
  [@bs.set] pub cursor: string;

  /**
    The area the filter is applied to. 
    This is used as more of an optimization rather than figuring out 
    the dimensions of the displayObject each frame you can set this rectangle.

    Also works as an interaction mask.
   */
  [@bs.set] pub filterArea: Js.Nullable.t(Rectangle.t);

  /**
    Sets the filters for the displayObject.

    IMPORTANT: This is a WebGL only feature and will be ignored by the canvas renderer. 
    To remove filters simply set this property to 'null'.    
   */
  [@bs.set] pub filters: Js.Nullable.t(array(Filter.t));

  /**
    Interaction shape. Children will be hit first, then this shape will be checked. 
    Setting this will cause this shape to be checked in hit tests rather than the displayObject's bounds.
   */
  [@bs.set] pub hitArea: Js.t({..});

  /**
    Enable interaction events for the DisplayObject. 
    Touch, pointer and mouse events will not be emitted unless interactive is set to true.
   */
  [@bs.set] pub interactive: bool;

  /**
    Does any other displayObject use this object as a mask?
   */
  pub isMask: bool;

  /**
    used to fast check if a sprite is.. a sprite!
   */
  pub isSprite: bool;

  /**
    Current transform of the object based on local factors: position, scale, other stuff.
   */
  pub localTransform: Matrix.t;

  /**
    Sets a mask for the displayObject. A mask is an object that limits the visibility of an object 
    to the shape of the mask applied to it. 
    In PixiJS a regular mask must be a PIXI.Graphics or a PIXI.Sprite object. 
    This allows for much faster masking in canvas as it utilities shape clipping. 
    To remove a mask, set this property to null.

    For sprite mask both alpha and red channel are used. Black mask is the same as transparent mask.

      @deprecated consider using PIXI.DisplayObject.getMask for PIXI.Graphics | PIXI.Sprite | null support
      @see </bs-pixi/PIXI/DisplayObject-PIXI/#val-getMask> DisplayObject.getMask 
   */
  /* TODO: PIXI.Graphics | PIXI.Sprite | null */
  [@bs.set] pub mask: Js.t({..});

  /**
    The instance name of the object.
   */
  [@bs.set][@bs.get nullable] pub name: string;

  /** 
    The display object container that contains this display object.
   */
  pub parent: Js.t(container);

  /* TODO: IPoint.t */
  /**
    The pivot point of the displayObject that it rotates around. Assignment by value since pixi-v4.
   */
  [@bs.set] pub pivot: Point.t;

  /**
    The coordinate of the object relative to the local coordinates of the parent. 
    Assignment by value since pixi-v4.
   */
  [@bs.set] pub position: Point.t;

  /**
    Can this object be rendered, if false the object will not be drawn but the updateTransform methods will still be called.
    Only affects recursive calls from parent. You can ask for bounds manually.
   */
  [@bs.set] pub renderable: bool;

  /**
    The rotation of the object in radians. 
    'rotation' and 'angle' have the same effect on a display object; rotation is in radians, angle is in degrees.
   */
  [@bs.set] pub rotation: float;

  /* TODO: IPoint.t */
  /**
    The scale factor of the object. Assignment by value since pixi-v4.
   */
  [@bs.set] pub scale: Point.t;

  /**
    The skew factor for the object in radians. Assignment by value since pixi-v4.
   */
  [@bs.set] pub skew: ObservablePoint.t;

  /**
    World transform and local transform of this object. 
    This will become read-only later, please do not assign anything there unless you know what are you doing.
   */
  [@bs.set] pub transform: Transform.t;

  /**
    The visibility of the object. If false the object will not be drawn, and the updateTransform function will not be called.
    Only affects recursive calls from parent. You can ask for bounds or call updateTransform manually.
   */
  [@bs.set] pub visible: bool;

  /**
    The multiplied alpha of the displayObject.
   */
  pub worldAlpha: float;

  /**
    Current transform of the object based on world (parent) factors.
   */
  pub worldTransform: Matrix.t;

  /**
    Indicates if the object is globally visible.
   */
  pub worldVisible: bool;
  
  /**
    The position of the displayObject on the x axis relative to the local coordinates of the parent. 
    An alias to position.x
   */
  [@bs.set] pub x: float;

  /**
    The position of the displayObject on the y axis relative to the local coordinates of the parent. 
    An alias to position.y
   */
  [@bs.set] pub y: float;
  
  /**
    The zIndex of the displayObject. 
    If a container has the sortableChildren property set to true, children will be 
    automatically sorted by zIndex value; a higher value will mean it will be moved towards the end of the array, 
    and thus rendered on top of other displayObjects within the same container.
   */
  [@bs.set] pub zIndex: int;
  
  /**
    Recursively updates transform of all objects from the root to this one internal function for toLocal()
   */
  pub _recursivePostUpdateTransform: unit => unit;

  /**
    Base destroy method for generic display objects. 
    This will automatically remove the display object from its parent Container 
    as well as remove all current event listeners and internal references. 
    Do not use a DisplayObject after calling destroy().
   */
  pub destroy: unit => unit;

  /**
    Retrieves the bounds of the displayObject as a rectangle object.

      @param skipUpdate Setting to true will stop the transforms of the scene graph from being updated. 
        This means the calculation returned MAY be out of date BUT will give you a nice performance boost.
      @param rect Optional rectangle to store the result of the bounds calculation.
   */
  pub getBounds: (bool, Js.Undefined.t(Rectangle.t)) => Rectangle.t;

  /**
    Returns the global position of the displayObject. 
    Does not depend on object scale, rotation and pivot.
   */
  pub getGlobalPosition: (Point.t, bool) => Point.t;

  /**
    Retrieves the local bounds of the displayObject as a rectangle object
   */
  pub getLocalBounds: Js.Undefined.t(Rectangle.t) => Rectangle.t;

  // TODO: Renderer.t
  // pub render: Renderer.t => unit;

  //NOTE: setParent is in Container.t
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
  pub setTransform: (float, float, float, float, float, float, float, float, float) => Js.t(displayObject);

  /* TODO: IPoint.t */
  /**
    Calculates the global position of the display object

      @param position The world origin to calculate from
      @param from (optional) The DisplayObject to calculate the global position from
      @param point (optional) A Point object in which to store the value, optional (otherwise will create a new Point)
      @param skipUpdate Should we skip the update transform
      @return A point object representing the position of this object
   */
  pub toGlobal: (Point.t, Js.Undefined.t(Point.t), bool) => Point.t;
  /* TODO: IPoint.t */

  /**
    Calculates the local position of the display object relative to another point

      @param position The world origin to calculate from
      @param from (optional) The DisplayObject to calculate the global position from
      @param point (optional) A Point object in which to store the value, optional (otherwise will create a new Point)
      @param skipUpdate Should we skip the update transform
      @return A point object representing the position of this object
   */
  pub toLocal: (Point.t, Js.Undefined.t(Js.t(displayObject)), Js.Undefined.t(Point.t), bool) => Point.t;

  /**
    Updates the object transform for rendering
   */
  pub updateTransform: unit => unit;
} and container = [@bs] {
  inherit displayObject;

};