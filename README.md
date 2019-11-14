# bs-pixi
BuckleScript bindings for [PIXI v5](https://github.com/pixijs) - experimental (Work in progress)

Refer to [documentation](https://ambientlight.github.io/bs-pixi) for existing coverage.

## Installation

```bash
npm install bs-pixi
```

## About Bindings

You would commonly see javascript classes represented as anonymous types on reason side where functionality is available as module level functions. Here, in addition to module-level bindings, you can also access object members, since we bind directly to javascript classes as bucklescript `class type` bindings. The next two calls are equivalent:

```ocaml
let point = PIXI.Point.create(~x=1.0, ~y=5.0, ());
// as object members
let x = point##x;
// as module level functions
let x = point |. PIXI.Point.getX;
```

But please note there are few limitations when using js-object methods: no support for overloaded method args, labeled optional args, currying, you will  see optionals arguments wrapped into `Js.Undefined.t` for this reason. So documentation will explicitly recommend you to use module-level conterpart.