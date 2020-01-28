
/**
  A Container represents a collection of display objects.
  It is the base class of all display objects that act as a container for other objects (like Sprites).
 */
type t = Js.t(C.container);

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: unit => t = "Container";

  [@bs.obj] external createDestroyOptions: (
    ~children: bool=?,
    ~texture: bool=?,
    ~baseTexture: bool=?,
    unit
  ) => _ = "";

  /**
    The array of children of this container.
   */
  [@bs.get] external getChildren: (Js.t(#C.container)) => array(Js.t(C.displayObject)) = "getChildren";

  /**
    The height of the Container, setting this will actually modify the scale to achieve the value set
   */
  [@bs.get] external getHeight: Js.t(#C.container) => float = "height";

  /**
    The height of the Container, setting this will actually modify the scale to achieve the value set
  */
  [@bs.set] external setHeight: (Js.t(#C.container), float) => unit = "height";

  /**
    Determines if the children to the displayObject can be clicked/touched 
    Setting this to false allows PixiJS to bypass a recursive hitTest function
   */
  [@bs.get] external getInteractiveChildren: Js.t(#C.container) => bool = "interactiveChildren";

  /**
    Determines if the children to the displayObject can be clicked/touched 
    Setting this to false allows PixiJS to bypass a recursive hitTest function
   */
  [@bs.set] external setInteractiveChildren: (Js.t(#C.container), bool) => unit = "interactiveChildren";

  /**
    If set to true, the container will sort its children by zIndex value when updateTransform() is called, 
    or manually if sortChildren() is called.
    This actually changes the order of elements in the array, so should be treated as a basic solution 
    that is not performant compared to other solutions, such as @link https://github.com/pixijs/pixi-display

    Also be aware of that this may not work nicely with the addChildAt() function, 
    as the zIndex sorting may cause the child to automatically sorted to another position.
   */
  [@bs.get] external getSortableChildren: Js.t(#C.container) => bool = "sortableChildren";

  /**
    If set to true, the container will sort its children by zIndex value when updateTransform() is called, 
    or manually if sortChildren() is called.
    This actually changes the order of elements in the array, so should be treated as a basic solution 
    that is not performant compared to other solutions, such as @link https://github.com/pixijs/pixi-display

    Also be aware of that this may not work nicely with the addChildAt() function, 
    as the zIndex sorting may cause the child to automatically sorted to another position.
   */
  [@bs.set] external setSortableChildren: (Js.t(#C.container), bool) => unit = "sortableChildren";

  /**
    Should children be sorted by zIndex at the next updateTransform call. 
    Will get automatically set to true if a new child is added, or if a child's zIndex changes.
   */
  [@bs.get] external getSortDirty: Js.t(#C.container) => bool = "sortDirty";

  /**
    Should children be sorted by zIndex at the next updateTransform call. 
    Will get automatically set to true if a new child is added, or if a child's zIndex changes.
   */
  [@bs.set] external setSortDirty: (Js.t(#C.container), bool) => unit = "sortDirty";

  /**
    The width of the Container, setting this will actually modify the scale to achieve the value set
   */
  [@bs.get] external getWidth: Js.t(#C.container) => float = "width";

  /**
    The width of the Container, setting this will actually modify the scale to achieve the value set
  */
  [@bs.set] external setWidth: (Js.t(#C.container), float) => unit = "width";

  /**
    Adds one or more children to the container.
    Multiple items can be added like so: myContainer.addChild(thingOne, thingTwo, thingThree)
   */
  [@bs.send] external addChild: (Js.t(#C.container), Js.t(#C.displayObject as 'a)) => Js.t('a) = "addChild";
  
  /**
    Adds a child to the container at a specified index. 
    If the index is out of bounds an error will be thrown
   */
  [@bs.send] external addChildAt: (Js.t(#C.container), Js.t(#C.displayObject as 'a), ~index: int) => Js.t('a) = "addChildAt";

  /**
    Recalculates the bounds of the container.
   */
  [@bs.send] external calculateBounds: Js.t(#C.container) => unit = "calculateBounds";

  /**
    Removes all internal references and listeners as well as removes children from the display list. 
    Do not use a Container after calling destroy.
   */
  [@bs.send]
  external _destroy: (
    Js.t(#C.container), 
    ~options: 'a=?, 
    unit
  ) => unit = "destroy";

  let destroy = (container, ~options = createDestroyOptions(()), ()) => _destroy(container, ~options, ());

  /**
    Returns the child at the specified index
   */
  [@bs.send] external getChildAt: (Js.t(#C.container), int) => Js.t(#C.displayObject) = "getChildAt";

  /**
    Returns the display object in the container.
   */
  [@bs.send] external getChildByName: (Js.t(#C.container), string) => Js.t(#C.displayObject) = "getChildByName";

  /**
    Returns the index position of a child DisplayObject instance
   */
  [@bs.send] external getChildIndex: (Js.t(#C.container), Js.t(#C.displayObject)) => int = "getChildIndex";

  /**
    Removes one or more children from the container.
   */
  [@bs.send] external removeChild: (Js.t(#C.container), Js.t(#C.displayObject as 'a)) => Js.t('a) = "removeChild";

  /**
    Removes a child from the specified index position.
   */
  [@bs.send] external removeChildAt: (Js.t(#C.container), int) => Js.t(#C.displayObject) = "removeChildAt";

  /**
    Removes all children from this container that are within the begin and end indexes.
   */
  [@bs.send] external removeChildren: (Js.t(#C.container), ~beginIndex: int=?, ~endIndex: int=?, unit) => array(Js.t(#C.displayObject)) = "removeChildren";

  /**
    Renders the object using the Canvas renderer
   */
  //TODO: CanvasRenderer
  [@bs.send] external renderCanvas: (Js.t(#C.container), Js.t(#AbstractRenderer._t)) => unit = "renderCanvas";

  /**
    Changes the position of an existing child in the display object container
   */
  [@bs.send] external setChildIndex: (Js.t(#C.container), int) => unit = "setChildIndex";

  /**
    Sorts children by zIndex. Previous order is mantained for 2 children with the same zIndex.
   */
  [@bs.send] external sortChildren: Js.t(#C.container) => unit = "sortChildren";

  /**
    Swaps the position of 2 Display Objects within this container.
   */
  [@bs.send] external swapChildren: (Js.t(#C.container), Js.t(#C.displayObject), Js.t(#C.displayObject)) => unit = "swapChildren";
};

include EventEmitter.Impl;
include DisplayObject.Impl;
include Impl;