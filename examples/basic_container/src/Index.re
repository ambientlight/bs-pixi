open PIXI;

let app = Application.create(~options=Application.createApplicationOptions(
  ~width=800.,
  ~height=600.,
  ~backgroundColor=int_of_string("0x1099bb"),
  ~resolution=DomRe.window |. Obj.magic |. Js.Dict.unsafeGet("devicePixelRatio"), ()), 
  ());

Webapi.Dom.document 
|> Webapi.Dom.Document.asHtmlDocument 
|. Belt.Option.flatMap(document => document |> Webapi.Dom.HtmlDocument.body)
|. Belt.Option.map(body => body |> Webapi.Dom.Element.appendChild(app##view))
|> ignore;

let container = Container.create();

app 
|. Application.getStage 
|. Container.addChild(container);

// Create a new texture
let texture = Texture.from(~source=`String("https://pixijs.io/examples/examples/assets/bunny.png"), ());

// Create a 5x5 grid of bunnies
Belt.Array.range(0, 24)
|. Belt.Array.forEach(i => {
  let bunny = Sprite.create(texture);
  bunny##anchor##set(0.5, 0.5);
  bunny |. Sprite.setX(float_of_int((i mod 5) * 40));
  bunny |. Sprite.setY(floor(float_of_int(i) /. 5.) *. 40.);
  container |. Container.addChild(bunny) |> ignore;
});

container |. Container.setX(app##screen##width /. 2.);
container |. Container.setY(app##screen##height /. 2.);

// Center bunny sprite in local container coordinates
container##pivot##x #= (container##width /. 2.);
container##pivot##y #= (container##height /. 2.);

// Listen for animate update
app
|. Application.getTicker
|. Ticker.add(delta => {
  // rotate the container!
  // use delta to create frame-independent transform
  container |. Container.setRotation(container##rotation -. 0.01 *. delta);
}, ());