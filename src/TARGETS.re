[@bs.deriving jsConverter]
type t = 
  | [@bs.as 3553] Texture2d
  | [@bs.as 34067] TextureCubeMap
  | [@bs.as 35866] Texture2dArray
  | [@bs.as 34069] TextureCubeMapPositiveX
  | [@bs.as 34070] TextureCubeMapNegativeX
  | [@bs.as 34071] TextureCubeMapPositiveY
  | [@bs.as 34072] TextureCubeMapNegativeY
  | [@bs.as 34073] TextureCubeMapPositiveZ
  | [@bs.as 34074] TextureCubeMapNegativeZ;

let texture2d = 3553;
let textureCubeMap = 34067;
let texture2dArray = 35866;
let textureCubeMapPositiveX = 34069;
let textureCubeMapNegativeX = 34070;
let textureCubeMapPositiveY = 34071;
let textureCubeMapNegativeY = 34072;
let textureCubeMapPositiveZ = 34073;
let textureCubeMapNegativeZ = 34074;