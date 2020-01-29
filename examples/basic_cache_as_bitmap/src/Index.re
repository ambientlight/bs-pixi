open PIXI;

let app = Application.create();

Webapi.Dom.document 
|> Webapi.Dom.Document.asHtmlDocument 
|. Belt.Option.flatMap(document => document |> Webapi.Dom.HtmlDocument.body)
|. Belt.Option.map(body => body |> Webapi.Dom.Element.appendChild(app##view)) |> ignore;

let alienFrames = [|
  "eggHead.png",
  "flowerTop.png",
  "helmlok.png",
  "skully.png",
|];

let count = ref(0.);

// create an empty container
let alienContainer = Container.create();
alienContainer |. Container.setX(400.);
alienContainer |. Container.setY(300.)

// make the stage interactive
app##stage##interactive #= true;
app
|. Application.getStage
|. Container.addChild(alienContainer);

let aliens: ref(array(Sprite.t)) = ref([||]);
let onAssetLoaded = (loader: Loader.t, resourceDict: Js.Dict.t(Loader.Resource.t)) => {
  // add a bunch of aliens with textures from image paths
  aliens := Belt.Array.range(0, 99)
  |> Array.map(i => {
    let frameName = alienFrames[i mod 4];

    // create an alien using the frame name..
    let alien = Sprite.from(~source=`String(frameName), ());
    alien |. Sprite.setTint(int_of_float(float_of_string("0xFFFFFF") *. Js.Math.random()));

    /*
     * fun fact for the day :)
     * another way of doing the above would be
     * var texture = PIXI.Texture.from(frameName);
     * var alien = new PIXI.Sprite(texture);
     */
    alien |. Sprite.setX(Js.Math.random() *. 800. -. 600.);
    alien |. Sprite.setY(Js.Math.random() *. 600. -. 300.);
    alien##anchor##x #= 0.5;
    alien##anchor##y #= 0.5;
    alienContainer |. Container.addChild(alien)
  });

  app |. Application.start;
};

let onClick = _event => {
  alienContainer |. Container.setCacheAsBitmap(!alienContainer##cacheAsBitmap);
};

app |. Application.stop;
app
|. Application.getLoader
|. Loader.add(`Name("spritesheet"), ~url="https://pixijs.io/examples/examples/assets/spritesheet/monsters.json", ())
|. Loader.load(~cb=onAssetLoaded, ());

app
|. Application.getStage
|. Container.on(~event=`String("pointertap"), ~fn=onClick, ());

// Listen for animate update
app
|. Application.getTicker
|. Ticker.add(_delta => {
  aliens^
  |. Belt.Array.forEach(alien => alien |. Sprite.setRotation(alien##rotation +. 0.1));

  count := count^ +. 0.01;
  alienContainer##scale##x #= Js.Math.sin(count^);
  alienContainer##scale##y #= Js.Math.cos(count^);
  alienContainer |. Container.setRotation(alienContainer##rotation +. 0.01);
}, ());