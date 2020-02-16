open Jest;

describe("Resource", () => {
  open Resource;
  open Expect;

  describe("Resource creation", () => {
    let resource = create(~width=100., ~height=200., ());

    test("check whether width is accurate", () => {
      expect(resource |> getWidth) |> toBe(100.)
    });

    test("check whether height is accurate", () => {
      expect(resource |> getHeight) |> toBe(200.)
    });
  });

  ();
});
describe("BaseImageResource", () => {
  open BaseImageResource;
  open Expect;

  describe("Image Resource creation", () => {
    let img = Webapi.Dom.document |> Webapi.Dom.Document.createElement("img");
    let imgElement = Webapi.Dom.HtmlImageElement.ofElement(img);
    switch (imgElement) {
    | None => ignore()
    | Some(imgElement) =>
      let resource = create(~source=`HTMLImageElement(imgElement), ());

      test("check whether width is accurate", () => {
        expect(resource |> getWidth) |> toBe(0.)
      });

      test("check whether height is accurate", () => {
        expect(resource |> getHeight) |> toBe(0.)
      });

      test("check whether source is accurate", () => {
        expect(resource |> getSource) |> toBe(img)
      });
    };
  });

  describe("Video Resource creation", () => {
    let video =
      Webapi.Dom.document |> Webapi.Dom.Document.createElement("video");

    let resource = create(~source=`HTMLVideoElement(video), ());

    test("check whether width is accurate", () => {
      expect(resource |> getWidth) |> toBe(0.)
    });

    test("check whether height is accurate", () => {
      expect(resource |> getHeight) |> toBe(0.)
    });

    test("check whether source is accurate", () => {
      expect(resource |> getSource) |> toBe(video)
    });
  });

  ();
});

describe("VideoResource", () => {
  open VideoResource;
  open Expect;

  describe("VideoResource creation as string", () => {
    let resource =
      create(
        ~source=`String("http://google.nl"),
        ~options=
          createVideoResourceOptions(
            ~autoLoad=false,
            ~autoPlay=false,
            ~updateFPS=30,
            ~crossorigin=true,
            (),
          ),
        (),
      );

    test("check whether width is accurate", () => {
      expect(resource |> getWidth) |> toBe(0.)
    });
    test("check whether height is accurate", () => {
      expect(resource |> getHeight) |> toBe(0.)
    });
    test("check whether autoPlay is accurate", () => {
      expect(resource |> getAutoPlay) |> toBe(false)
    });
    test("check whether updateFPS is accurate", () => {
      expect(resource |> getUpdateFPS) |> toBe(30)
    });
  });

  describe("VideoResource creation as object", () => {
    let resource =
      create(
        ~source=`Object([|{src: "http://google.nl", mime: "video/mp4"}|]),
        ~options=
          createVideoResourceOptions(
            ~autoLoad=false,
            ~autoPlay=false,
            ~updateFPS=30,
            ~crossorigin=true,
            (),
          ),
        (),
      );

    test("check whether width is accurate", () => {
      expect(resource |> getWidth) |> toBe(0.)
    });
    test("check whether height is accurate", () => {
      expect(resource |> getHeight) |> toBe(0.)
    });
    test("check whether autoPlay is accurate", () => {
      expect(resource |> getAutoPlay) |> toBe(false)
    });
    test("check whether updateFPS is accurate", () => {
      expect(resource |> getUpdateFPS) |> toBe(30)
    });
  });

  ();
});
