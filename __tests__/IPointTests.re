open Jest;
open IPoint;

describe("IPoint", () => {
  open Expect;

  let point = Point.create();
  let obsPoint = ObservablePoint.create(~cb=() => (), ());

  test("IPoint equals", () => 
    expect(equals(`Point(point), `ObservablePoint(obsPoint)))
    |> toBe(true)
  );

  test("IPoint copyFrom", () => {
    let t = Point.create(~x=10.0, ~y=1.0, ());
    let target = copyFrom(`Point(t), `ObservablePoint(obsPoint));
    let isPoint = switch(target){ | `Point(_) => true | _ => false };

    expect(t##x == obsPoint##x && t##y == obsPoint##y && isPoint)
    |> toBe(true)
  });

  test("IPoint copyTo", () => {
    let obsT = ObservablePoint.create(~cb=() => (), ~x=10.0, ~y=1.0, ());
    let target = copyTo(`Point(point), `ObservablePoint(obsT));
    let isObsPoint = switch(target){ | `ObservablePoint(_) => true | _ => false };

    expect(obsT##x == point##x && obsT##y == point##y && isObsPoint)
    |> toBe(true)
  });

  ()
})