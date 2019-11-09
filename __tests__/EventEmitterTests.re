open Jest;

open EventEmitter;

describe("EventEmitter", () => {
  open Expect;

  test("create", () => {
    let _eventEmitter = create();
    expect(true) |> toBe(true)
  });

  test("on symbol", () => {
    let eventEmitter = create();
    let symbol = Symbol.create("testEvent");
    eventEmitter |. on(~event=`Symbol(symbol), ~fn=() => (), ()) |> ignore;
    expect(eventEmitter|.listenerCount(~event=`Symbol(symbol))) |> toBe(1)
  });  

  test("on string", () => {
    let eventEmitter = create();
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    expect(eventEmitter|.listenerCount(~event=`String("testEvent"))) |> toBe(1)
  });  

  test("addListener", () => {
    let eventEmitter = create();
    eventEmitter |. addListener(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    expect(eventEmitter|.listenerCount(~event=`String("testEvent"))) |> toBe(1)
  });

  test("eventNames", () => {
    let eventEmitter = create();
    eventEmitter |. addListener(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    expect(eventEmitter|.eventNames) |> toEqual([|"testEvent"|])
  });

  test("eventNames met", () => {
    let eventEmitter = create();
    eventEmitter |. addListener(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    expect(eventEmitter##eventNames()) |> toEqual([|"testEvent"|])
  });

  test("listeners", () => {
    let eventEmitter = create();
    eventEmitter |. addListener(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    let listeners = eventEmitter |. listeners(~event=`String("testEvent"));
    expect(listeners|.Array.length) |> toEqual(1)
  });

  test("listeners met", () => {
    let eventEmitter = create();
    eventEmitter |. addListener(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    let listeners = eventEmitter##listeners("testEvent");
    expect(listeners|.Array.length) |> toEqual(1)
  });

  test("listenerCount", () => {
    let eventEmitter = create();
    let symbol = Symbol.create("testEvent");
    eventEmitter |. on(~event=`Symbol(symbol), ~fn=() => (), ()) |> ignore;
    expect(eventEmitter|.listenerCount(~event=`Symbol(symbol))) |> toBe(1)
  });

  test("listenerCount met", () => {
    let eventEmitter = create();
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    expect(eventEmitter##listenerCount("testEvent")) |> toBe(1)
  });

  testPromise("emit", () => {
    let eventEmitter = create();
    let promise = Js.Promise.make((~resolve, ~reject) => {
      eventEmitter |. on(~event=`String("testEvent"), ~fn=() => resolve(. expect(true) |> toBe(true)), ()) |> ignore;
    })

    eventEmitter |. emit(~event=`String("testEvent")) |> ignore;
    promise
  });

  testPromise("emit met", () => {
    let eventEmitter = create();
    let promise = Js.Promise.make((~resolve, ~reject) => {
      eventEmitter |. on(~event=`String("testEvent"), ~fn=() => resolve(. expect(true) |> toBe(true)), ()) |> ignore;
    })

    eventEmitter##emit("testEvent") |> ignore;
    promise
  });

  test("removeListener", () => {
    let eventEmitter = create();
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter |. removeListener(~event=`String("testEvent"), ()) |> ignore;
    expect(eventEmitter##listenerCount("testEvent")) |> toBe(0)
  });

  test("removeListener met", () => {
    let eventEmitter = create();
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter##removeListener("testEvent", Js.Undefined.empty, Js.Undefined.empty, Js.Undefined.empty) |> ignore;
    expect(eventEmitter##listenerCount("testEvent")) |> toBe(0)
  });

  test("off", () => {
    let eventEmitter = create();
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter |. removeListener(~event=`String("testEvent"), ()) |> ignore;
    expect(eventEmitter##listenerCount("testEvent")) |> toBe(0)
  });

  test("off met", () => {
    let eventEmitter = create();
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter##off("testEvent", Js.Undefined.empty, Js.Undefined.empty, Js.Undefined.empty) |> ignore;
    expect(eventEmitter##listenerCount("testEvent")) |> toBe(0)
  });

  test("removeAllListeners", () => {
    let eventEmitter = create();
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter |. removeAllListeners(()) |> ignore;
    expect(eventEmitter##listenerCount("testEvent")) |> toBe(0)
  });

  test("removeAllListeners met", () => {
    let eventEmitter = create();
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter |. on(~event=`String("testEvent"), ~fn=() => (), ()) |> ignore;
    eventEmitter##removeAllListeners(Js.Undefined.empty) |> ignore;
    expect(eventEmitter##listenerCount("testEvent")) |> toBe(0)
  });

  ()
});