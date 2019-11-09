open Jest;

open Rectangle;

describe("Rectangle", () => {
  open Expect;

  let rect = create(~x=5.0, ~y=5.0, ~width=1.0, ~height=1.0, ());
  test("getX getY getWidth getHeight", () => 
    expect(
      rect|.getX == 5.0 
      && rect|.getY == 5.0
      && rect|.getWidth == 1.0 
      && rect|.getHeight == 1.0
    ) |> toBe(true)
  );

  test("setX setY setWidth setHeight", () => {
    let rect = create(());
    rect|.setX(1.0);
    rect|.setY(1.0);
    rect|.setWidth(10.0);
    rect|.setHeight(10.0);
    expect(
      rect|.getX == 1.0 
      && rect|.getY == 1.0
      && rect|.getWidth == 10.0 
      && rect|.getHeight == 10.0
    ) |> toBe(true)
  });

  test("x y width height", () => 
    expect(
      rect##x == 5.0 
      && rect##y == 5.0
      && rect##width == 1.0 
      && rect##height == 1.0
    ) |> toBe(true)
  );

  test("getLeft getTop getBottom getRight", () => {
    expect(
      rect|.getLeft == 5.0
      && rect|.getTop == 5.0
      && rect|.getRight == 6.0
      && rect|.getBottom == 6.0
    ) |> toBe(true)
  });

  test("left top bottom right", () => {
    expect(
      rect##left == 5.0
      && rect##top == 5.0
      && rect##right == 6.0
      && rect##bottom == 6.0
    ) |> toBe(true)
  });

  test("getType", () => 
    expect(rect|.getType) |> toEqual(SHAPES.Rect)
  );

  test("empty", () => 
    expect(
      empty##left == 0.0
      && empty##top == 0.0
      && empty##right == 0.0
      && empty##bottom == 0.0
    ) |> toBe(true)
  );

  test("ceil", () => {
    let rect = create(~x=4.9, ~y=4.9, ~width=1.0, ~height=1.0, ());
    let ceiled = rect|.ceil(~resolution=1.0, ~eps=0.001, ());
    expect(
      ceiled|.getX == 4.0 
      && ceiled|.getY == 4.0
      && ceiled|.getWidth == 2.0 
      && ceiled|.getHeight == 2.0
    ) |> toBe(true)
  });

  test("ceil met", () => {
    let rect = create(~x=4.9, ~y=4.9, ~width=1.0, ~height=1.0, ());
    let ceiled = rect##ceil(Js.Undefined.return(1.0), Js.Undefined.return(0.001));
    expect(
      ceiled|.getX == 4.0 
      && ceiled|.getY == 4.0
      && ceiled|.getWidth == 2.0 
      && ceiled|.getHeight == 2.0
    ) |> toBe(true)
  });

  test("clone", () => {
    let cloned = rect|.clone;
    expect(
      cloned|.getX == 5.0 
      && cloned|.getY == 5.0
      && cloned|.getWidth == 1.0 
      && cloned|.getHeight == 1.0
    ) |> toBe(true)
  });

  test("clone met", () => {
    let cloned = rect##clone();
    expect(
      cloned|.getX == 5.0 
      && cloned|.getY == 5.0
      && cloned|.getWidth == 1.0 
      && cloned|.getHeight == 1.0
    ) |> toBe(true)
  });

  test("contains", () => 
    expect(rect|.contains(~x=5.0, ~y=5.0)) |> toBe(true)
  );

  test("contains met", () => 
    expect(rect##contains(5.0, 5.0)) |> toBe(true)
  );

  test("copyFrom", () => {
    let r1 = create(());
    r1|.copyFrom(~rectangle=rect) |> ignore;
    expect(
      rect|.getX == (r1|.getX)
      && rect|.getY == (r1|.getY)
      && rect|.getWidth == (r1|.getWidth)
      && rect|.getHeight == (r1|.getHeight)
    ) |> toBe(true)
  });

  test("copyFrom met", () => {
    let r1 = create(());
    r1##copyFrom(rect) |> ignore;
    expect(
      rect|.getX == (r1|.getX)
      && rect|.getY == (r1|.getY)
      && rect|.getWidth == (r1|.getWidth)
      && rect|.getHeight == (r1|.getHeight)
    ) |> toBe(true)
  });

  test("copyTo", () => {
    let r1 = create(());
    rect|.copyTo(~rectangle=r1) |> ignore;
    expect(
      rect|.getX == (r1|.getX)
      && rect|.getY == (r1|.getY)
      && rect|.getWidth == (r1|.getWidth)
      && rect|.getHeight == (r1|.getHeight)
    ) |> toBe(true)
  });

  test("copyTo met", () => {
    let r1 = create(());
    rect##copyTo(r1) |> ignore;
    expect(
      rect|.getX == (r1|.getX)
      && rect|.getY == (r1|.getY)
      && rect|.getWidth == (r1|.getWidth)
      && rect|.getHeight == (r1|.getHeight)
    ) |> toBe(true)
  });

  test("enlarge", () => {
    let r1 = create(~x=0.0, ~y=0.0, ~width=1.0, ~height=1.0, ());
    r1|.enlarge(~rectangle=rect) |> ignore;
    expect(
      r1|.getRight == 6.0 &&
      r1|.getBottom == 6.0
    ) |> toBe(true)
  });

  test("enlarge met", () => {
    let r1 = create(~x=0.0, ~y=0.0, ~width=1.0, ~height=1.0, ());
    r1##enlarge(rect) |> ignore;
    expect(
      r1|.getRight == 6.0 &&
      r1|.getBottom == 6.0
    ) |> toBe(true)
  });

  test("fit", () => {
    let r1 = create(~x=0.0, ~y=0.0, ~width=10.0, ~height=10.0, ());
    r1|.fit(~rectangle=rect) |> ignore;
    expect(
      r1|.getRight == 6.0 &&
      r1|.getBottom == 6.0
    ) |> toBe(true)
  });

  test("fit met", () => {
    let r1 = create(~x=0.0, ~y=0.0, ~width=10.0, ~height=10.0, ());
    r1##fit(rect) |> ignore;
    expect(
      r1|.getRight == 6.0 &&
      r1|.getBottom == 6.0
    ) |> toBe(true)
  });

  test("pad", () => {
    let r1 = create(~x=0.0, ~y=0.0, ~width=1.0, ~height=1.0, ());
    r1|.pad(~paddingX=5.0, ~paddingY=5.0, ()) |> ignore;
    expect(
      r1|.getRight == 6.0 &&
      r1|.getBottom == 6.0
    ) |> toBe(true)
  });

  test("pad met", () => {
    let r1 = create(~x=0.0, ~y=0.0, ~width=1.0, ~height=1.0, ());
    r1##pad(Js.Undefined.empty, Js.Undefined.return(5.0)) |> ignore;
    expect(
      r1|.getRight == 1.0 &&
      r1|.getBottom == 6.0
    ) |> toBe(true)
  });

  ()
});