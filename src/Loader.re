//TODO: complete Loader

module Resource {
  type t;
};

//TODO: Loader
class type _t = [@bs] {
  /**
    The base url for all resources loaded by this loader.
    Any trailing slashes are trimmed off.
   */
  [@bs.set] pub baseUrl: string

  /**
    The number of resources to load concurrently.
   */
  [@bs.set] pub concurrency: int

  /**
    All the resources for this loader keyed by name, or URL if no name was given. 
   */
  [@bs.set] pub resources: Js.Dict.t(Resource.t)

  /**
    A querystring to append to every URL added to the loader.
   */
  [@bs.set] pub defaultQueryString: string

  /**
   Loading state of the loader, true if it is currently loading resources.
   */
  [@bs.set] pub loading: bool

  /**
    The progress percent of the loader going through the queue.
   */
  [@bs.set] pub progress: float
};

type t = Js.t(_t);
type onCompleteSignal = (t, Js.Dict.t(Resource.t)) => unit;

type _nextFn = unit => unit
type middlewareFn = (Resource.t, _nextFn) => unit;
type urlResolverFn('a) = (string, ~parsed: 'a) => string;

[@bs.deriving abstract]
type addOptions = {
  /**
    The url to load the resource from.
   */
  [@bs.optional] url: string,

  /**
    A base url to use for just this resource load.
   */
  [@bs.optional] baseUrl: string,

  /**
    The name of the resource to load, if not passed the url is used.
   */
  [@bs.optional] name: string,

  /**
    Callback to add an an onComplete signal listener.
   */
  [@bs.optional] onComplete: onCompleteSignal,

  /**
    Parent resource this newly added resource is a child of.
   */
  [@bs.optional] parentResource: Resource.t
};

module Impl {

  /**
    creates a new resource loader
    
    @param baseUrl The base url for all resources loaded by this loader.
    @param concurrency The number of resources to load concurrently.
   */
  [@bs.module "resource-loader"][@bs.new]
  external create: (~baseUrl: string, ~concurrency: int=?, unit) => t = "Loader";

  /**
    Sets up a middleware function that will run *after* the
    resource is loaded.
   
    You can optionally specify a priority for this middleware
    which will determine the order middleware functions are run.
    A lower priority value will make the function run earlier.
    That is, priority 30 is run before priority 50.
   */
  [@bs.module "resource-loader"][@bs.scope "Loader"]
  external useStatic: (middlewareFn, ~priority: int=?, unit) => t = "use";

  /**
    The base url for all resources loaded by this loader.
    Any trailing slashes are trimmed off.
   */
  [@bs.get] external getBaseUrl: Js.t(#_t) => string = "baseUrl";

  /**
    The base url for all resources loaded by this loader.
    Any trailing slashes are trimmed off.
   */
  [@bs.set] external setBaseUrl: (Js.t(#_t), string) => unit = "baseUrl";

  /**
    The number of resources to load concurrently.
   */
  [@bs.get] external getConcurrency: Js.t(#_t) => int = "concurrency";

  /**
    The number of resources to load concurrently.
   */
  [@bs.set] external setConcurrency: (Js.t(#_t), int) => unit = "concurrency";

  /**
    All the resources for this loader keyed by name, or URL if no name was given. 
   */
  [@bs.get] external getResources: Js.t(#_t) => Js.Dict.t(Resource.t) = "resources";

  /**
    All the resources for this loader keyed by name, or URL if no name was given. 
   */
  [@bs.set] external setResources: (Js.t(#_t), Js.Dict.t(Resource.t)) => unit = "resources";

  /**
    A querystring to append to every URL added to the loader.
   */
  [@bs.get] external getDefaultQueryString: Js.t(#_t) => string = "defaultQueryString";

  /**
    A querystring to append to every URL added to the loader.
   */
  [@bs.set] external setDefaultQueryString: (Js.t(#_t), string) => unit = "defaultQueryString";

  /**
    Loading state of the loader, true if it is currently loading resources.
   */
  [@bs.get] external getLoading: Js.t(#_t) => bool = "loading";

  /**
    Loading state of the loader, true if it is currently loading resources.
   */
  [@bs.set] external setLoading: (Js.t(#_t), bool) => unit = "loading";

  /**
    The progress percent of the loader going through the queue.
   */
  [@bs.get] external getProgress: Js.t(#_t) => float = "progress";

  /**
    The progress percent of the loader going through the queue.
   */
  [@bs.set] external setProgress: (Js.t(#_t), float) => unit = "progress";

  /** 
    adds a resource to loader queue 
   */
  [@bs.send] external addUrl: (Js.t(#_t as 'a), string) => Js.t('a) = "add";

  /**
    adds a resource to loader queue
   */
  [@bs.send] external add: (
    Js.t(#_t as 'a), 
    [@bs.unwrap][
      | `Name(string)
      | `Options(addOptions)
      | `UrlArrays(string)
      | `OptionsArray(addOptions)], 
    ~url: string=?, 
    unit) => Js.t('a) = "add";

  /**
    Sets up a middleware function that will run *after* the
    resource is loaded.

    You can optionally specify a priority for this middleware
    which will determine the order middleware functions are run.
    A lower priority value will make the function run earlier.
    That is, priority 30 is run before priority 50
   */
  [@bs.send] external use: (Js.t(#_t as 'a), ~fn: middlewareFn, ~priority: int=?, unit) => Js.t('a) = "use";

  /**
    Resets the queue of the loader to prepare for a new load.
   */
  [@bs.send] external reset: Js.t(#_t as 'a) => Js.t('a) = "reset";

  /**
    Starts loading the queued resources.
   */
  [@bs.send] external load: (Js.t(#_t as 'a), ~cb: onCompleteSignal=?, unit) => Js.t('a) = "load";

  /**
    Add a function that can be used to modify the url just prior
    to `baseUrl` and `defaultQueryString` being applied
   */
  [@bs.send] external addUrlResolver: (Js.t(#_t as 'a), urlResolverFn('b)) => Js.t('a) = "addUrlResolver";
}

include Impl;