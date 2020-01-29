open PIXI;

let app = Application.create(~options=Application.createApplicationOptions(
  ~backgroundColor=int_of_string("0x1099bb"), ()), 
  ());

Webapi.Dom.document 
|> Webapi.Dom.Document.asHtmlDocument 
|. Belt.Option.flatMap(document => document |> Webapi.Dom.HtmlDocument.body)
|. Belt.Option.map(body => body |> Webapi.Dom.Element.appendChild(app##view))
|> ignore;

let basicText = Text.create(~text="Basic text in pixi", ());
basicText |. Text.setX(50.);
basicText |. Text.setY(100.);

app
|. Application.getStage
|. Container.addChild(basicText);

let style = TextStyle.create(~style=TextStyle.createStyleOptions(
  ~fontFamily=[|"Arial"|],
  ~fontSize=36.,
  ~fontStyle="italic",
  ~fontWeight="bold",
  ~fill=[|"#ffffff", "#00ff99"|] |> Obj.magic,
  ~stroke=int_of_string("0x4a1850"),
  ~strokeThickness=5.,
  ~dropShadow=true,
  ~dropShadowColor=int_of_string("0x000000"),
  ~dropShadowBlur=4.,
  ~dropShadowAngle=Js.Math._PI /. 6.,
  ~dropShadowDistance=6.,
  ~wordWrap=true,
  ~wordWrapWidth=440.,
  ()), ());

let richText = Text.create(~text="Rich text with a lot of options and across multiple lines", ~style, ());
richText |. Text.setX(50.);
richText |. Text.setY(250.);
app
|. Application.getStage
|. Container.addChild(richText);