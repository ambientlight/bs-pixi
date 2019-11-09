open Jest;
open ObservablePoint;

describe("ObservablePoint", () => {
  open Expect;
  let point = create(~cb=() => (), ~x=1.0, ~y=5.0, ());
  let other = create(~cb=() => (), ~x=16.0, ~y=4.0, ());

  test("ObservablePoint x", () => 
    expect(point##x) |> toEqual(1.0)
  );

  test("ObservablePoint y", () => 
    expect(point##y) |> toEqual(5.0)
  );

  test("ObservablePoint clone met", () => {
    let clone = point##clone(Js.Null.empty, Js.Null.empty);
    expect(clone##x == point##x && clone##y == clone##y) 
    |> toBe(true)
  });

  test("ObservablePoint copyFrom met", () => {
    let point = create(~cb=() => (), ());
    point##copyFrom(other) |> ignore;
    expect(point##x == other##x && point##y == other##y) 
    |> toBe(true)
  });

  test("ObservablePoint copyTo met", () => {
    let other = create(~cb=() => (), ());
    point##copyTo(other) |> ignore;
    expect(other##x == point##x && other##y == point##y) |> toBe(true)
  });

  test("ObservablePoint equals met", () => 
    expect(point##equals(other)) |> toBe(false)
  );

  test("ObservablePoint set met", () => {
    let other = create(~cb=() => (), ~x=10.0, ~y=9.0, ());
    other##set(0.0, 0.0);
    expect(other##x == 0.0 && other##y == 0.0) |> toBe(true);
  });

  test("ObservablePoint getX", () => 
    expect(point |. getX) |> toEqual(1.0)
  );

  test("ObservablePoint getY", () => 
    expect(point |. getY) |> toEqual(5.0)
  );

  test("ObservablePoint setX", () => {
    let point = create(~cb=() => (), ());
    point |. setX(16.0);
    expect(point |. getX) |> toEqual(16.0);
  });

  test("ObservablePoint setY", () => {
    let point = create(~cb=() => (), ());
    point |. setY(20.0);
    expect(point |. getY) |> toEqual(20.0);
  });

  test("ObservablePoint clone", () => {
    let clone = point|.clone(());
    expect((clone|.getX) == (point|.getX) && (clone|.getY) == (clone|.getY))
    |> toBe(true)
  });

  test("ObservablePoint copyFrom", () => {
    let point = create(~cb=() => (), ());
    point|.copyFrom(~p=other) |> ignore;
    expect(point##x == other##x && point##y == other##y) 
    |> toBe(true)
  });

  test("ObservablePoint copyTo", () => {
    let other = create(~cb=() => (), ());
    point|.copyTo(~p=other) |> ignore;
    expect((other|.getX) == (point|.getX) && (other|.getY) == (point|.getY)) |> toBe(true)
  });

  test("ObservablePoint equals", () => 
    expect(point|.equals(~p=other)) |> toBe(false)
  );

  test("ObservablePoint set", () => {
    let p1 = create(~cb=() => (), ~x=10.0, ~y=9.0, ());
    let p2 = create(~cb=() => (), ~x=10.0, ~y=9.0, ());
    let p3 = create(~cb=() => (), ~x=10.0, ~y=9.0, ());
    p1|.set(~x=0.0, ());
    p2|.set(~y=0.0, ());
    p3|.set(~x=0.0, ~y=0.0, ());
    expect(
      p1##x == 0.0 &&
      p2##y == 0.0 &&
      p3##x == 0.0 && p3##y == 0.0) 
    |> toBe(true);
  });

  testPromise("ObservablePoint callback", ~timeout=100, () => 
    Js.Promise.make((~resolve, ~reject) => {
      let point = create(~cb=() => resolve(. expect(true) |> toBe(true)), ());
      point|.set(~x=1.0, ());
    })
  );

  ()
});