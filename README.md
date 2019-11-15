# bs-pixi
BuckleScript bindings for [PIXI v5](https://github.com/pixijs) - experimental (Work in progress)

Refer to [documentation](https://ambientlight.github.io/bs-pixi) for existing coverage.
Examples will be added very soon.

## Installation

```bash
npm install bs-pixi
```

And add `bs-pixi` into `bs-dependencies` in your project `bsconfig.json`.

## About Bindings

[PIXI.js](https://github.com/pixijs) relies heavily on inheritance, which in the context of bucklescript bindings is often realized via [functors](https://reasonml.github.io/docs/en/module#module-functions-functors) where module containing subclass functionality would "spread" the implementation of the ancestor module (closest is mixin) - see [Extending Modules](https://reasonml.github.io/docs/en/module#extending-modules). This is often referred to as **implementation inheritance**. One example is in [bs-webapi-incubator](https://github.com/reasonml-community/bs-webapi-incubator#implementation-inheritance). In contrast to this approach where javascript classes are represented as anonymous types on reason side (and functionality available as module level functions) here we bind directly to javascript classes via bucklescript supported `class type` bindings, where ocaml class types are wrapped into `Js.t` and inheritance is realized via ocaml build-in OOP inheritance that results in a subclass type being structural subtype of an ancestor, this is not exactly one-to-one to the way inheritance works in javascript but it allows us to write more or less clean bindings. There are few limitations when it comes to using js-object methods though: no support for overloaded method args(`[@bs.unwrap]`), currying, labeled optional args, for this reason all functionality is also available on module level, so feel free to use any way that fits your workflow, 

```ocaml
let point = PIXI.Point.create(~x=1.0, ~y=5.0, ());
let x = point##x;
let x = point |. PIXI.Point.getX;
```

but I would recommend you to use class-level bindings for accessors, module-level functions are generally preferred for anything else, they also support feeding objects of subtypes which comes handy. 
Example:

```ocaml
[@bs.send]
external addChild: (Js.t(#C.displayObject), ~child: Js.t(#C.displayObject as 'a)) => Js.t('a) = "addChild";
```

(\# denotes structural subtype, so when you see Js.t(#C.displayObjects) you can feed any js object types that are structural subtypes of displayObject directly without upcasting. such as `Container.t` or `Sprite.t`)

## Contributing

Any contribution is greatly appreciated. Take a look at [CONTRIBUTING.md](https://github.com/ambientlight/bs-pixi/blob/master/CONTRIBUTING.md) Feel free to reach out in [issues](https://github.com/ambientlight/bs-pixi/issues) for any questions.