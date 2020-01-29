let app = PIXI.Application.create(
  ~options=PIXI.Application.createApplicationOptions(~transparent=true, ()), 
  ());

Webapi.Dom.document 
|> Webapi.Dom.Document.asHtmlDocument 
|. Belt.Option.flatMap(document => document |> Webapi.Dom.HtmlDocument.body)
|. Belt.Option.map(body => body |> Webapi.Dom.Element.appendChild(app##view))
|> ignore;

// create a new Sprite from an image path.
let bunny = PIXI.Sprite.from(~source=`String("https://pixijs.io/examples/examples/assets/bunny.png"), ());
bunny##anchor##set(0.5, 0.5);

// move the sprite to the center of the screen
bunny |. PIXI.Sprite.setX(app##screen##width /. 2.);
bunny |. PIXI.Sprite.setY(app##screen##height /. 2.);

app |. PIXI.Application.getStage |. PIXI.Container.addChild(bunny);

// Listen for animate update
app
|. PIXI.Application.getTicker
|. PIXI.Ticker.add(_delta => {
  // just for fun, let's rotate mr rabbit a little
  bunny |. PIXI.Container.setRotation(bunny##rotation +. 0.1);
}, ());