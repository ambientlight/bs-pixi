[@bs.deriving jsConverter]
type t = 
  | [@bs.as 5121] UnsignedByte
  | [@bs.as 5123] UnsignedShort
  | [@bs.as 33635] UnsignedShort_5_6_5
  | [@bs.as 32819] UnsignedShort_4_4_4_4
  | [@bs.as 32820] UnsignedShort_5_5_5_1
  | [@bs.as 5126] Float
  | [@bs.as 36193] HalfFloat;

let unsignedByte = 5121;
let unsignedShort = 5123;
let unsignedShort_5_6_5 = 33635;
let unsignedShort_4_4_4_4 = 32819;
let unsignedShort_5_5_5_1 = 32820;
let float = 5126;
let halfFloat = 36193;