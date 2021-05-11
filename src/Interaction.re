//TODO: InteractionManager.t
module InteractionManager = {
  type t;
};

module InteractionData = {
  type t;

  /**
    Indicates which button was pressed on the mouse or pointer device to trigger the event.
  */
  [@bs.get]
  external getButton: Js.t(t) => int = "button";

  /**
    Indicates which buttons are pressed on the mouse or pointer device when the event is triggered.
  */
  [@bs.get]
  external getButtons: Js.t(t) => int = "buttons";

  /**
    This point stores the global coords of where the touch/mouse event happened
  */
  [@bs.get]
  external getGlobal: Js.t(t) => Point.t = "global";

  /**
    The height of the pointer's contact along the y-axis, measured in CSS pixels. radiusY of TouchEvents will be represented by this value.
  */
  [@bs.get]
  external getHeight: Js.t(t) => float = "height";

  /**
    Unique identifier for this interaction
  */
  [@bs.get]
  external getIdentifier: Js.t(t) => float = "identifier";

  /**
    Indicates whether or not the pointer device that created the event is the primary pointer.
  */
  [@bs.get]
  external getIsPrimary: Js.t(t) => bool = "isPrimary";

  /**
    When passed to an event handler, this will be the original DOM Event that was captured
  */
  [@bs.get]
  external getOriginalEvent: Js.t(t) => Webapi.Dom.UiEvent.t =
    "originalEvent";

  /**
    The unique identifier of the pointer. It will be the same as identifier.
  */
  [@bs.get]
  external getPointerId: Js.t(t) => float = "pointerId";

  /**
    The type of pointer that triggered the event.
  */
  [@bs.get]
  external getPointerType: Js.t(t) => string = "pointerType";

  /**
    Pressure applied by the pointing device during the event. A Touch's force property will be represented by this value.
  */
  [@bs.get]
  external getPressure: Js.t(t) => float = "pressure";

  /**
    From TouchEvents (not PointerEvents triggered by touches), the rotationAngle of the Touch.
  */
  [@bs.get]
  external getRotationAngle: Js.t(t) => float = "rotationAngle";

  /**
    Barrel pressure on a stylus pointer.
  */
  [@bs.get]
  external getTangentialPressure: Js.t(t) => float = "tangentialPressure";

  /**
    The target Sprite that was interacted with
  */
  [@bs.get]
  external getTarget: Js.t(t) => Sprite.t = "target";

  /**
    The angle, in degrees, between the pointer device and the screen.
  */
  [@bs.get]
  external getTiltX: Js.t(t) => float = "tiltX";

  /**
    The angle, in degrees, between the pointer device and the screen.
  */
  [@bs.get]
  external getTiltY: Js.t(t) => float = "tiltY";

  /**
    Twist of a stylus pointer.
  */
  [@bs.get]
  external getTwist: Js.t(t) => float = "twist";

  /**
    The width of the pointer's contact along the x-axis, measured in CSS pixels. radiusX of TouchEvents will be represented by this value.
  */
  [@bs.get]
  external getWidth: Js.t(t) => float = "width";

  /**
    Copies properties from normalized event data.
  */
  [@bs.send]
  external copyEvent: (Js.t(t), ~event: Webapi.Dom.UiEvent.t, unit) => unit =
    "copyEvent";

  /**
    This will return the local coordinates of the specified displayObject for this InteractionData
  */
  [@bs.send]
  external getLocalPosition:
    (
      Js.t(t),
      ~displayObject: C.displayObject,
      ~point: Point.t=?,
      ~globalPos: Point.t=?,
      unit
    ) =>
    Point.t =
    "getLocalPosition";

  /**
    Resets the data for pooling.
  */
  [@bs.send]
  external reset: Js.t(t) => unit = "reset";
};
