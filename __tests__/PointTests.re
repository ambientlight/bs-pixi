open Jest;
open Point;

describe("Point", () => {
  open Expect;
  let point = create(~x=1.0, ~y=5.0, ());
  let other = create(~x=16.0, ~y=4.0, ());

  test("Point x", () => 
    expect(point##x) |> toEqual(1.0)
  );

  test("Point y", () => 
    expect(point##y) |> toEqual(5.0)
  );

  test("Point clone met", () => {
    let clone = point##clone();
    expect(clone##x == point##x && clone##y == clone##y) 
    |> toBe(true)
  });

  test("Point copyFrom met", () => {
    let point = create();
    point##copyFrom(other) |> ignore;
    expect(point##x == other##x && point##y == other##y) 
    |> toBe(true)
  });

  test("Point copyTo met", () => {
    let other = create();
    point##copyTo(other) |> ignore;
    expect(other##x == point##x && other##y == point##y) |> toBe(true)
  });

  test("Point equals met", () => 
    expect(point##equals(other)) |> toBe(false)
  );

  test("Point set met", () => {
    let other = create(~x=10.0, ~y=9.0, ());
    other##set(0.0, 0.0);
    expect(other##x == 0.0 && other##y == 0.0) |> toBe(true);
  });

  test("Point getX", () => 
    expect(point |. getX) |> toEqual(1.0)
  );

  test("Point getY", () => 
    expect(point |. getY) |> toEqual(5.0)
  );

  test("Point setX", () => {
    let point = create();
    point |. setX(16.0);
    expect(point |. getX) |> toEqual(16.0);
  });

  test("Point setY", () => {
    let point = create();
    point |. setY(20.0);
    expect(point |. getY) |> toEqual(20.0);
  });

  test("Point clone", () => {
    let clone = point|.clone;
    expect((clone|.getX) == (point|.getX) && (clone|.getY) == (clone|.getY))
    |> toBe(true)
  });

  test("Point copyFrom", () => {
    let point = create();
    point|.copyFrom(~p=other) |> ignore;
    expect(point##x == other##x && point##y == other##y) 
    |> toBe(true)
  });

  test("Point copyTo", () => {
    let other = create();
    point|.copyTo(~p=other) |> ignore;
    expect((other|.getX) == (point|.getX) && (other|.getY) == (point|.getY)) |> toBe(true)
  });

  test("Point equals", () => 
    expect(point|.equals(~p=other)) |> toBe(false)
  );

  test("Point set", () => {
    let p1 = create(~x=10.0, ~y=9.0, ());
    let p2 = create(~x=10.0, ~y=9.0, ());
    let p3 = create(~x=10.0, ~y=9.0, ());
    p1|.set(~x=0.0, ());
    p2|.set(~y=0.0, ());
    p3|.set(~x=0.0, ~y=0.0, ());
    expect(
      p1##x == 0.0 &&
      p2##y == 0.0 &&
      p3##x == 0.0 && p3##y == 0.0) 
    |> toBe(true);
  });

  ()
});