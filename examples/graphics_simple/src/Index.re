open PIXI;

let app = Application.create(~options=Application.createApplicationOptions(
  ~antialias=true, ()), 
  ());

Webapi.Dom.document 
|> Webapi.Dom.Document.asHtmlDocument 
|. Belt.Option.flatMap(document => document |> Webapi.Dom.HtmlDocument.body)
|. Belt.Option.map(body => body |> Webapi.Dom.Element.appendChild(app##view))
|> ignore;

let graphics = Graphics.({
  create()
  // rectangle
  |. beginFill(~color=int_of_string("0xDE3249"), ())
  |. drawRect(~x=50., ~y=50., ~width=100., ~height=100.)
  |. endFill
  // rectangle + line style 1
  |. lineStyle(~width=2., ~color=int_of_string("0xFEEB77"), ~alpha=1., ())
  |. beginFill(~color=int_of_string("0x650A5A"), ())
  |. drawRect(~x=200., ~y=50., ~width=100., ~height=100.)
  |. endFill
  // rectangle + line style 2
  |. lineStyle(~width=10., ~color=int_of_string("0xFFBD01"), ~alpha=1., ())
  |. beginFill(~color=int_of_string("0xC34288"), ())
  |. drawRect(~x=350., ~y=50., ~width=100., ~height=100.)
  |. endFill
  // rectangle 2
  |. lineStyle(~width=2., ~color=int_of_string("0xFFFFFF"), ~alpha=1., ())
  |. beginFill(~color=int_of_string("0xAA4F08"), ())
  |. drawRect(~x=530., ~y=50., ~width=140., ~height=100.)
  |. endFill
  // circle
  // draw a circle, set the lineStyle to zero so the circle doesn't have an outline
  |. lineStyle(~width=0., ()) 
  |. beginFill(~color=int_of_string("0xDE3249"), ~alpha=1., ())
  |. drawCircle(~x=100., ~y=250., ~radius=50.)
  |. endFill
  // circle + line style 1
  |. lineStyle(~width=2., ~color=int_of_string("0xFEEB77"), ~alpha=1., ())
  |. beginFill(~color=int_of_string("0x650A5A"), ~alpha=1., ())
  |. drawCircle(~x=250., ~y=250., ~radius=50.)
  |. endFill
  // circle + line style 2
  |. lineStyle(~width=10., ~color=int_of_string("0xFFBD01"), ~alpha=1., ())
  |. beginFill(~color=int_of_string("0xC34288"), ~alpha=1., ())
  |. drawCircle(~x=400., ~y=250., ~radius=50.)
  |. endFill
  // ellipse + line style 2
  |. lineStyle(~width=10., ~color=int_of_string("0xFFFFFF"), ~alpha=1., ())
  |. beginFill(~color=int_of_string("0xAA4F08"), ~alpha=1., ())
  |. drawEllipse(~x=600., ~y=250., ~width=80., ~height=50.)
  |. endFill
  // draw a shape
  |. beginFill(~color=int_of_string("0xFF3300"), ())
  |. lineStyle(~width=4., ~color=int_of_string("0xffd900"), ~alpha=1., ())
  |. moveTo(~x=50., ~y=350.)
  |. lineTo(~x=250., ~y=350.)
  |. lineTo(~x=100., ~y=400.)
  |. lineTo(~x=50., ~y=350.)
  |. closePath
  |. endFill
  // draw a rounded rectangle
  |. lineStyle(~width=2., ~color=int_of_string("0xFF00FF"), ~alpha=1., ())
  |. beginFill(~color=int_of_string("0x650A5A"), ~alpha=0.25, ())
  |. drawRoundedRect(~x=50., ~y=440., ~width=100., ~height=100., ~radius=16.)
  |. endFill
  // draw star
  |. lineStyle(~width=2., ~color=int_of_string("0xFFFFFF"), ())
  |. beginFill(~color=int_of_string("0x35CC5A"), ~alpha=1., ())
  |. drawStar(~x=360., ~y=370., ~points=5, ~radius=50., ())
  |. endFill
  // draw star 2
  |. lineStyle(~width=2., ~color=int_of_string("0xFFFFFF"), ())
  |. beginFill(~color=int_of_string("0xFFCC5A"), ~alpha=1., ())
  |. drawStar(~x=280., ~y=510., ~points=7, ~radius=50., ())
  |. endFill
  // draw star 3
  |. lineStyle(~width=4., ~color=int_of_string("0xFFFFFF"), ())
  |. beginFill(~color=int_of_string("0x55335A"), ~alpha=1., ())
  |. drawStar(~x=470., ~y=450., ~points=4, ~radius=50., ())
  |. endFill
  // drawPolygon
  |. lineStyle(~width=0., ())
  |. beginFill(~color=int_of_string("0x3500FA"), ~alpha=1., ())
  |. drawPolygon(`Array([|600., 370., 700., 460., 780., 420., 730., 570., 590., 520.|]))
  |. endFill
});

app
|. Application.getStage
|. Container.addChild(graphics);