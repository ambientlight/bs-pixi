Any contribution is greatly appreciated. Feel free to reach out in [issues](https://github.com/ambientlight/bs-pixi/issues) for any questions.

```sh
git clone https://github.com/ambientlight/bs-pixi.git
cd bs-pixi
npm install
npm run build
npm run test
```

You can also generate docs via [bsdoc](https://github.com/reuniverse/bsdoc). If you have forked this repo, the pushes to master should spin the github actions workflow that rebuild the github pages docs with workflow available at [deploy_docs.yml](https://github.com/ambientlight/bs-pixi/blob/master/.github/workflows/deploy_docs.yml). (You will need to set `GH_PAGES_TOKEN` for github pages deployment to work).

If you want to generate docs in local make sure you have [bsdoc](https://github.com/reuniverse/bsdoc) built against ocaml version matching the ocaml version used in your `bs-platform` (`4.02.3+buckle-master` for bs-platform@5.2.1).

```
opam switch 4.02.3+buckle-master
```

For osx, you can use the npm installation of bsdoc(corresponds to bs-platform 6), but for linux-based distros, you would need to build bsdoc from source for now.

## Bugs

Bug reports or are suggestions are welcome. When filing a bug, try to include as much information as you can. Details like these are incredibly useful: 

* A reproducible test case or series of steps
* Anything unusual about your environment or deployment

## Guidelines
For now those guidelines are still pretty experimental and I am open for any inputs here, feel free to discuss this in issues.


1. pixi's entities are modeled class based Js.t for polymorphism with apis consuming subtypes seemlessly
    ```ocaml
    class type displayObject = [@bs] {
        inherit EventEmitter._t;
    }
    ```

2. methods are both available as object methods as well as module-level functions
3. module level functionality for types that have subtypes should be implemented inside a module `Impl` that would be spreaded inside this and all subtype modules with `include Impl`. (like in [Implementation Inheritance](https://github.com/reasonml-community/bs-webapi-incubator#implementation-inheritance))

4. object methods with arguments labeled as optionals are wrapped into `Js.Undefined.t` except bool types (usually false is often the default).
5. polymorphic parameter types utilize `[@bs.unwrap]`, class-level methods that don't support `[@bs.unwrap]` should be documented with `@see` that recommend and reference a corresponding module-level binding.
6. polymorphic return types are explictly unwrapped usually with wrapped-up instanceof calls. Like:
    ```ocaml
    let getDrawableSource: Js.t(#C1.baseTexture) => ICanvasImageSource.t = baseTexture => { 
        let drawableSource = baseTexture |. _getDrawableSource;

        module Internal {
            type constructor;
            [@bs.val] external htmlImageElement: constructor = "HTMLImageElement";
            [@bs.val] external htmlCanvasElement: constructor = "HTMLCanvasElement";
            [@bs.val] external htmlVideoElement: constructor = "HTMLVideoElement";
            [@bs.val] external imageBitmap: constructor = "ImageBitmap";

            let instanceOf: ('a, constructor) => bool = [%bs.raw {|function(x,y) {return +(x instanceof y)}|}];
        };

        if(Internal.instanceOf(drawableSource, Internal.htmlImageElement)){
            `HTMLImageElement(drawableSource |> Obj.magic)
        } else if (Internal.instanceOf(drawableSource, Internal.htmlCanvasElement)) {
            `HTMLCanvasElement(drawableSource)
        } else if (Internal.instanceOf(drawableSource, Internal.htmlVideoElement)) {
            `HTMLVideoElement(drawableSource)
        } else if (Internal.instanceOf(drawableSource, Internal.imageBitmap)){
            `ImageBitmap(drawableSource |> Obj.magic)
        } else {
            raise(Failure("Unrecognized drawable source"))
        }
    };
    ```

6. To avoid creating `[@bs.deriving abstract]` types for various constructor types, [external function](https://bucklescript.github.io/docs/en/object-2#function) that would evaluate to `Js.t` object is used. Take a look at **createOptions** in [BaseTexture.re](https://github.com/ambientlight/bs-pixi/blob/master/src/BaseTexture.re). To have this type then constraint in constructor(create) function, a `createOptions` calls is passed as a default value for `~options` parameter like:
    ```ocaml
    let create = (~resource, ~options=createOptions(()), ()) => _create(~resource, ~options, ());
    ```