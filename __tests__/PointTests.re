open Jest;
open Point;

describe("Point", () => {
  open Expect;
  let point = create(~x=1.0, ~y=5.0, ());
  
  test("Point x", () => 
    expect(point##x) |> toEqual(1.0)
  );

  test("Point y", () => 
    expect(point##y) |> toEqual(5.0)
  );

  test("Point getX", () => 
    expect(point |. getX) |> toEqual(1.0)
  );

  test("Point getY", () => 
    expect(point |. getY) |> toEqual(5.0)
  );

  ()
});