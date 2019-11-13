[@bs.deriving jsConverter]
type t = 
  | [@bs.as 0] NoPremultipliedAlpha
  | [@bs.as 1] PremultiplyOnUpload
  | [@bs.as 2] PremultipliedAlpha;

/**
  Source is not premultiplied, leave it like that. 
  Option for compressed and data textures that are created from typed arrays
 */
let noPremultipliedAlpha = 0;

/**
  Source is not premultiplied, premultiply on upload. Default option, used for all loaded images
 */
let premultiplyOnUpload = 1;

/**
  Source is already premultiplied Example: spine atlases with _pma suffix
 */
let premultipliedAlpha = 2;

/**
  Alias for NO_PREMULTIPLIED_ALPHA
 */
let npm = noPremultipliedAlpha;

/**
  Default option, alias for PREMULTIPLY_ON_UPLOAD
 */
let unpack = premultiplyOnUpload;

/**
  Alias for PREMULTIPLIED_ALPHA
 */
let pma = premultipliedAlpha;