class type _t = [@bs] {
  inherit C.container;

  /** 
    The blend mode to be applied to the graphic shape. 
    Apply a value of PIXI.BLEND_MODES.NORMAL to reset the blend mode. 
  */
  [@bs.set] pub blendMode: int;

  /**
    The current fill style.
   */
  pub fill: FillStyle.t;

  /**
    Includes vertex positions, face indices, normals, colors, UVs, and custom attributes within buffers, reducing the cost of passing all this data to the GPU. 
    Can be shared between multiple Mesh or Graphics objects.
   */
  pub geometry: GraphicsGeometry.t;

  /**
    The current line style.
   */
  pub line: LineStyle.t;

  /**
    Renderer plugin for batching
   */
  [@bs.set] pub pluginName: string;

  /**
    Represents the vertex and fragment shaders that processes the geometry and runs on the GPU. 
    Can be shared between multiple Graphics objects.
   */
  [@bs.set] pub shader: Js.t(#Shader._t);

  /**
    Represents the WebGL state the Graphics required to render, excludes shader and geometry. 
    E.g., blend mode, culling, depth testing, direction of rendering triangles, backface, etc.
   */  
  [@bs.set] pub state: State.t;

  /**
    The tint applied to the graphic shape. This is a hex value. A value of 0xFFFFFF will remove any tint effect.
   */
  [@bs.set] pub tint: int;  
};

/**
  The Graphics class contains methods used to draw primitive shapes such as lines, circles and rectangles to the display, and to color and fill them.
  Note that because Graphics can share a GraphicsGeometry with other instances, 
  it is necessary to call destroy() to properly dereference the underlying GraphicsGeometry and avoid a memory leak. 
  Alternatively, keep using the same Graphics instance and call clear() between redraws.
 */
type t = Js.t(_t);

[@bs.obj]
external beginTextureFillOptions: (
  ~texture: Js.t(#Texture._t)=?,
  ~color: int=?,
  ~alpha: float=?,
  ~matrix: Js.t(#Matrix._t)=?,
  unit
) => _ = "";

[@bs.obj]
external lineStyleOptions: (
  ~width: float=?,
  ~color: int=?,
  ~alpha: float=?,
  ~alignnment: float=?,
  ~native: bool=?,
  unit
) => _ = "";

[@bs.obj]
external lineTextureStyleOptions: (
  ~width: float=?,
  ~texture: Texture.t=?,
  ~color: int=?,
  ~alpha: float=?,
  ~matrix: Matrix.t=?,
  ~alignment: float=?,
  ~native: bool=?,
  unit
) => _ = "";

module Impl {
  [@bs.module "pixi.js"][@bs.new]
  external create: (~geometry: GraphicsGeometry.t=?, unit) => t = "Graphics";

  /**
    The arc method creates an arc/curve (used to create circles, or parts of circles).

      @param cx The x-coordinate of the center of the circle
      @param cy The y-coordinate of the center of the circle
      @param radius The radius of the circle
      @param startAngle The starting angle, in radians (0 is at the 3 o'clock position of the arc's circle)
      @param endAngle The ending angle, in radians
      @param anticlockwise Specifies whether the drawing should be counter-clockwise or clockwise. False is default, and indicates clockwise, while true indicates counter-clockwise.
   */
  [@bs.send]
  external arc: (Js.t(#_t as 'a), ~cx: float, ~cy: float, ~radius: float, ~startAngle: float, ~endAngle: float, ~anticlockwise:bool=?, unit) => Js.t('a) = "arc";

  /**
    The arcTo() method creates an arc/curve between two tangents on the canvas.

      @param x1 The x-coordinate of the first tangent point of the arc
      @param y1 The y-coordinate of the first tangent point of the arc
      @param x2 The x-coordinate of the end of the arc
      @param y2 The y-coordinate of the end of the arc
      @param radius The radius of the arc
   */
  [@bs.send]
  external arcTo: (Js.t(#_t as 'a), ~x1: float, ~y1: float, ~x2: float, ~y2: float, ~radius: float) => Js.t('a) = "arcTo";

  /**
    Specifies a simple one-color fill that subsequent calls to other Graphics methods (such as lineTo() or drawCircle()) use when drawing.

      @param color the color of the fill
      @param alpha the alpha of the fill
   */
  [@bs.send]
  external beginFill: (Js.t(#_t as 'a), ~color: int=?, ~alpha: float=?, unit) => Js.t('a) = "beginFill";

  [@bs.send]
  external beginHole: Js.t(#_t as 'a) => Js.t('a) = "beginHole";

  [@bs.send]
  external _beginTextureFill: (Js.t(#_t as 'a), ~options: 'o, unit) => Js.t('a) = "beginTextureFill";

  /**
    Begin the texture fill

      @param options use Graphics.beginTextureFillOptions
   */
  let beginTextureFill = (graphics, ~options=beginTextureFillOptions(()), ()) => graphics |. _beginTextureFill(~options, ());

  /**
    Calculate the points for a bezier curve and then draws it.

      @param cpX Control point x
      @param cpY Control point y
      @param cpX2 Second control point X
      @param cpY2 Second control point Y
      @param toX Destination point x
      @param toY Destination point y
   */
  [@bs.send]
  external bezierCurveTo: (Js.t(#_t as 'a), ~cpX: float, ~cpY: float, ~cpX2: float, ~cpY2: float, ~toX: float, ~toY: float) => Js.t('a) = "bezierCurveTo";

  /**
    Clears the graphics that were drawn to this Graphics object, and resets fill and line style settings.
   */
  [@bs.send]
  external clear: Js.t(#_t as 'a) => Js.t('a) = "clear";

  /**
    Creates a new Graphics object with the same values as this one. 
    Note that the only the properties of the object are cloned, not its transform (position,scale,etc)
   */
  [@bs.send]
  external clone: Js.t(#_t as 'a) => Js.t('a) = "clone";

  /**
    Closes the current path.
   */
  [@bs.send]
  external closePath: Js.t(#_t as 'a) => Js.t('a) = "closePath";

  /**
    Tests if a point is inside this graphics object

      @param point point to test
   */
  [@bs.send]
  external containsPoint: (Js.t(#_t), Point.t) => bool = "containsPoint"; 

  /**
    Draws a circle.

      @param x The X coordinate of the center of the circle
      @param y The Y coordinate of the center of the circle
      @param radius The radius of the circle
   */
  [@bs.send]
  external drawCircle: (Js.t(#_t as 'a), ~x: float, ~y: float, ~radius: float) => Js.t('a) = "drawCircle";

  /**
    Draws an ellipse.

      @param x The X coordinate of the center of the ellipse
      @param y The Y coordinate of the center of the ellipse
      @param width The half width of the ellipse
      @param height The half height of the ellipse
   */
  [@bs.send]
  external drawEllipse: (Js.t(#_t as 'a), ~x: float, ~y: float, ~width: float, ~height: float) => Js.t('a) = "drawEllipse";

  /**
    Draws a polygon using the given path.

      @param The path data used to construct the polygon.
   */
  [@bs.send]
  external drawPolygon: (Js.t(#_t as 'a), [@bs.unwrap][
    | `Array(array(float)) 
    | `Point(array(Point.t))
    | `Polygon(Polygon.t)
  ]) => Js.t('a) = "drawPolygon"; 

  /**
    Draws a rectangle shape.

      @param x The X coord of the top-left of the rectangle
      @param y The Y coord of the top-left of the rectangle
      @param width The width of the rectangle
      @param height The height of the rectangle
   */
  [@bs.send]
  external drawRect: (Js.t(#_t as 'a), ~x: float, ~y: float, ~width: float, ~height: float) => Js.t('a) = "drawRect";

  /**
    Draws a rectangle shape.

      @param x The X coord of the top-left of the rectangle
      @param y The Y coord of the top-left of the rectangle
      @param width The width of the rectangle
      @param height The height of the rectangle
      @param radius Radius of the rectangle corners
   */
  [@bs.send]
  external drawRoundedRect: (Js.t(#_t as 'a), ~x: float, ~y: float, ~width: float, ~height: float, ~radius: float) => Js.t('a) = "drawRoundedRect";

  /**
    Draw any shape.

      @param shape shape to draw
   */
  [@bs.send]
  external drawShape: (Js.t(#_t as 'a), [@bs.unwrap][
    | `Circle(Js.t(#Circle._t))
    | `Ellipse(Js.t(#Ellipse._t))
    | `Polygon(Js.t(#Polygon._t))
    | `Rectangle(Js.t(#Rectangle._t))
    | `RoundedRectangle(Js.t(#RoundedRectangle._t))
  ]) => Js.t('a) = "drawShape";

  /**
    Draw a star shape with an arbitrary number of points.

      @param x Center X position of the star
      @param y Center Y position of the star
      @param points The number of points of the star, must be > 1
      @param radius The outer radius of the star
      @param innerRadius The inner radius between points, default half radius
      @param rotation The rotation of the star in radians, where 0 is vertical
   */
  [@bs.send]
  external drawStar: (Js.t(#_t as 'a), ~x: float, ~y: float, ~points: int, ~radius: float, ~innerRadius: float=?, ~rotation: float=?, unit) => Js.t('a) = "drawStar";

  /**
    Applies a fill to the lines and shapes that were added since the last call to the beginFill() method.
   */
  [@bs.send]
  external endFill: Js.t(#_t as 'a) => Js.t('a) = "endFill";

  /**
    End adding holes to the last draw shape
   */
  [@bs.send]
  external endHole: Js.t(#_t as 'a) => Js.t('a) = "endHole";

  /**
    Generates a canvas texture. 
    Only available with pixi.js-legacy bundle or the @pixi/canvas-graphics package.
   */
  [@bs.send]
  external generateCanvasTexture: (Js.t(#_t), ~scaleMode: float, ~resolution: float) => Texture.t = "generateCanvasTexture";

  /**
    True if graphics consists of one rectangle, and thus, can be drawn like a Sprite and masked with gl.scissor.
   */
  [@bs.send]
  external isFastRect: Js.t(#_t) => bool = "isFastRect";

  /**
    Specifies the line style used for subsequent calls to Graphics methods such as the lineTo() method or the drawCircle() method.
   */
  [@bs.send]
  external lineStyle: (Js.t(#_t as 'a), ~width: float=?, ~color: int=?, ~alpha: float=?, ~alignment: float=?, ~native: bool=?, unit) => Js.t('a) = "lineStyle";

  [@bs.send]
  external _lineStyleWithOptions: (Js.t(#_t as 'a), ~options:'o=?, unit) => Js.t('a) = "lineStyle";

  /**
    Specifies the line style used for subsequent calls to Graphics methods such 
    as the lineTo() method or the drawCircle() method.
   */
  let lineStyleWithOptions = (graphics, ~options=lineStyleOptions(()), ()) => graphics |. _lineStyleWithOptions(~options, ());

  [@bs.send] external _lineTextureStyle: (Js.t(#_t as 'a), ~options: 'o=?, unit) => Js.t('a) = "lineTextureStyle";

  /**
    Like line style but support texture for line fill.
   */
  let lineTextureStyle = (graphics, ~options=lineTextureStyleOptions(()), ()) => graphics |. _lineTextureStyle(~options, ());

  /**
    Draws a line using the current line style from the current drawing position to (x, y); 
    The current drawing position is then set to (x, y).

      @param x the X coordinate to draw to
      @param y the Y coordinate to draw to
   */
  [@bs.send]
  external lineTo: (Js.t(#_t as 'a), ~x: float, ~y: float) => Js.t('a) = "lineTo";

  /**
    Moves the current drawing position to x, y.

      @param x the X coordinate to move to
      @param y the Y coordinate to move to
   */
  [@bs.send]
  external moveTo: (Js.t(#_t as 'a), ~x: float, ~y: float) => Js.t('a) = "moveTo";

  /**
    Calculate the points for a quadratic bezier curve and then draws it.

      @param cpX Control point x
      @param cpY Control point y
      @param toX Destination point x
      @param toY Destination point y
   */
  [@bs.send]
  external quadraticCurveTo: (Js.t(#_t as 'a), ~cpX: float, ~cpY: float, ~toX: float, ~toY: float) => Js.t('a) = "quadraticCurveTo";

  /**
    Apply a matrix to the positional data.

      @param matrix Matrix to use for transform current shape.
   */
  [@bs.send]
  external setMatrix: (Js.t(#_t as 'a), Js.t(#Matrix._t)) => Js.t('a) = "setMatrix";
}

include EventEmitter.Impl;
include DisplayObject.Impl;
include Container.Impl;
include Impl;