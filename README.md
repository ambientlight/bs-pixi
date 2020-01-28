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

[PIXI.js](https://github.com/pixijs) relies heavily on inheritance, which in the context of bucklescript bindings is often realized via [functors](https://reasonml.github.io/docs/en/module#module-functions-functors) where module containing subclass functionality would "spread" the implementation of the ancestor module (closest is mixin) - see [Extending Modules](https://reasonml.github.io/docs/en/module#extending-modules). This is often referred to as **implementation inheritance**. One example is in [bs-webapi-incubator](https://github.com/reasonml-community/bs-webapi-incubator#implementation-inheritance). In addition to this approach here we bind directly to javascript classes via bucklescript supported `class type` bindings, with most apis accepting all structural subtypes:

```ocaml
[@bs.send]
external addChild: (Js.t(#C.displayObject), ~child: Js.t(#C.displayObject as 'a)) => Js.t('a) = "addChild";
```

`#` denotes structural subtype, so when we see `Js.t(#C.displayObjects)` we can feed any js object types that are structural subtypes of displayObject directly without upcasting to a type which is defined in a module where `addChild` is defined. Also this allows us to utilize model functions as well as class methods for the same functionality like:

```ocaml
let point = PIXI.Point.create(~x=1.0, ~y=5.0, ());
let x = point##x;
let x = point |. PIXI.Point.getX;
```

Although using class methods for anything slightly more complex as simple accessors is not really practical, as `[@bs]` class methods do not support currying, labeled and optional parameters, feel free to use it if you feel comfortable with it, as in next example.

## Example

```reason
let app = PIXI.Application.create(~options=PIXI.Application.createApplicationOptions(
  ~width=800,
  ~height=600,
  ~backgroundColor=int_of_string("0x1099bb"),
  ~resolution=DomRe.window |. Obj.magic |. Js.Dict.unsafeGet("devicePixelRatio"), ()), 
  ());

Webapi.Dom.document 
|> Webapi.Dom.Document.asHtmlDocument 
|. Belt.Option.flatMap(document => document |> Webapi.Dom.HtmlDocument.body)
|. Belt.Option.map(body => body |> Webapi.Dom.Element.appendChild(app##view))
|> ignore;

let container = PIXI.Container.create();
app##stage |. PIXI.Container.addChild(container);

let texture = PIXI.Texture.from(~source=`String("https://pixijs.io/examples/examples/assets/bunny.png"), ());

for (i in 0 to 24) {
  let bunny = PIXI.Sprite.create(texture);
  bunny##anchor##set(0.5, 0.5);
  bunny |. PIXI.Sprite.setX(float_of_int(i mod 5 * 40));
  bunny |. PIXI.Sprite.setY(floor(float_of_int(i) /. 5.) *. 40.);
  container |. PIXI.Container.addChild(bunny) |> ignore;
};

container##pivot##x #= (container##width /. 2.);
container##pivot##y #= (container##height /. 2.);

app##ticker |. PIXI.Ticker.add(delta => {
  container |. PIXI.Container.setRotation(container##rotation -. 0.01 *. delta);
}, ());
```

## Contributing

Any contribution is greatly appreciated. Take a look at [CONTRIBUTING.md](https://github.com/ambientlight/bs-pixi/blob/master/CONTRIBUTING.md). Feel free to reach out in [issues](https://github.com/ambientlight/bs-pixi/issues) for any questions.
