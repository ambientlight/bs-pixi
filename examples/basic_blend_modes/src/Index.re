open PIXI;

type dudeMeta = {
  mutable direction: float,
  mutable turningSpeed: float,
  mutable speed: float
};

let app = Application.create();

Webapi.Dom.document 
|> Webapi.Dom.Document.asHtmlDocument 
|. Belt.Option.flatMap(document => document |> Webapi.Dom.HtmlDocument.body)
|. Belt.Option.map(body => body |> Webapi.Dom.Element.appendChild(app##view)) |> ignore;

let background = Sprite.from(~source=`String("https://pixijs.io/examples/examples/assets/bg_rotate.jpg"), ());
background |. Sprite.setWidth(app##screen##width);
background |. Sprite.setHeight(app##screen##height);
app 
|. Application.getStage 
|. Container.addChild(background) |> ignore;

let dudes: array(Sprite.t) = Belt.Array.range(0, 19)
|> Array.map(_i => {
  // create a new Sprite that uses the image name that we just generated as its source
  let dude = Sprite.from(~source=`String("https://pixijs.io/examples/examples/assets/flowerTop.png"), ());
  // set the anchor point so the texture is centerd on the sprite
  dude##anchor##set(0.5, 0.5);
  
  // set a random scale for the dude - no point them all being the same size!
  dude##scale##set(0.8 +. Js.Math.random() *. 0.3, 0.8 +. Js.Math.random() *. 0.3);

  // finally lets set the dude to be at a random position..
  dude |. Sprite.setX(Js.Math.random() *. app##screen##width);
  dude |. Sprite.setY(Js.Math.random() *. app##screen##height);

  // The important bit of this example, this is how you change the default blend mode of the sprite
  dude |. Sprite.setBlendMode(BLEND_MODES.Add)

  dude |. Sprite.setTint(int_of_float(float_of_string("0xFFFFFF") *. Js.Math.random()));
  app |. Application.getStage |. Container.addChild(dude)
});

let metas = Belt.Array.range(0, 19)
|> Array.map(_i => {
  // create some extra properties that will control movement
  // create a random direction in radians. This is a number between 0 and PI*2 
  // which is the equivalent of 0 - 360 degrees
  direction: Js.Math.random() *. Js.Math._PI,

  // this number will be used to modify the direction of the dude over time
  turningSpeed: Js.Math.random() -. 0.8,

  // create a random speed for the dude between 0 - 2
  speed: 2. +. Js.Math.random() *. 2.
});

let dudesBoundsPadding = 180.;
let dudeBounds = PIXI.Rectangle.create(
  ~x=-.dudesBoundsPadding,
  ~y=-.dudesBoundsPadding,
  ~width=app##screen##width +. dudesBoundsPadding *. 2.,
  ~height=app##screen##height +. dudesBoundsPadding *. 2.,
  ()
);

// Listen for animate update
app
|. Application.getTicker
|. Ticker.add(_delta => 
  // iterate through the dudes and update their position
  dudes
  |. Belt.Array.forEachWithIndex((i, dude) => {
    metas[i].direction = metas[i].direction +. metas[i].turningSpeed *. 0.1;
    dude |. Sprite.setX(dude##x +. Js.Math.sin(metas[i].direction) *. metas[i].speed);
    dude |. Sprite.setY(dude##y +. Js.Math.cos(metas[i].direction) *. metas[i].speed);
    dude |. Sprite.setRotation(-.metas[i].direction -. Js.Math._PI /. 2.);

    // wrap the dudes by testing their bounds...
    if(dude##x < dudeBounds##x){
      dude |. Sprite.setX(dude##x +. dudeBounds##width);
    } else if(dude##x > dudeBounds##x +. dudeBounds##width) {
      dude |. Sprite.setX(dude##x -. dudeBounds##width)
    };
    
    if(dude##y < dudeBounds##y){
      dude |. Sprite.setY(dude##y +. dudeBounds##height);
    } else if(dude##y > dudeBounds##y +. dudeBounds##height) {
      dude |. Sprite.setY(dude##y -. dudeBounds##height)
    };
  }), ());