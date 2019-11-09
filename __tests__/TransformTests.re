open Jest;

open Transform;

describe("Transform", () => {
  open Expect;

  test("check whether setters are actually there", () => {
    let transform = create();
    transform |. setLocalTransform(Matrix.create());
    transform |. setPivot(ObservablePoint.create(~cb=() => (), ()));
    transform |. setPosition(ObservablePoint.create(~cb=() => (), ()));
    transform |. setRotation(0.0);
    transform |. setScale(0.0);
    transform |. setSkew(0.0);
    transform |. setWorldTransform(Matrix.create());
    expect(true) |> toBe(true)
  });

  ()
});