type t;

[@bs.val][@bs.scope "Object"]
external _defineSymbol: ('a, t, 'b) => unit = "defineProperty"; 

let create: string => t = [%raw {|
  function(key){ return Symbol(key) }
|}];

let getValue = (obj, symbol: t) => Js.Dict.unsafeGet(Obj.magic(obj), Obj.magic(symbol));
let setValue = (obj, symbol, value) => _defineSymbol(obj, symbol, [%bs.obj {
  value: value,
  writable: false
}]);