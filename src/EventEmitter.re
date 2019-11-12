class type _t = [@bs] {
  /**
    an array listing the events for which the emitter has registered listeners
   */
  pub eventNames: unit => array(string);

  /**
    listeners registered for a given event

      @deprecated Consider using EventEmitter.listeners if Symbol support needed
      @see </bs-pixi/PIXI/EventEmitter-PIXI/#val-listeners> EventEmitter.listeners
      @param event The event name
   */
  pub listeners: string => array(Js.t({..}) => unit);

  /**
    the number of listeners listening to a given event

      @deprecated Consider using EventEmitter.listeners if Symbol support needed.
      @see </bs-pixi/PIXI/EventEmitter-PIXI/#val-listenerCount> EventEmitter.listenerCount
      @param event The event name
      @return the number of listeners listening to a given event
   */
  pub listenerCount: string => int;

  /**
    Calls each of the listeners registered for a given event

      @deprecated Consider using EventEmitter.emit if Symbol support needed.
      @see </bs-pixi/PIXI/EventEmitter-PIXI/#val-listenerCount> EventEmitter.emit
      @param event The event name
      @return true if the event had listeners, else false
   */
  pub emit: string => bool;

  /**
    Add a listener for a given event

      @deprecated Consider using EventEmitter.on
      @see </bs-pixi/PIXI/EventEmitter-PIXI/#val-on> EventEmitter.on
      @param event The event name
      @param fn The listener function
      @param context (optional)The context to invoke the listener with
      @return itself
  */

  pub on: (string, Js.t({..}) => unit, Js.Undefined.t(Js.t({..}))) => Js.t(_t);

  /**
    Add a listener for a given event

      @deprecated Consider using EventEmitter.on
      @see </bs-pixi/PIXI/EventEmitter-PIXI/#val-on> EventEmitter.on
      @param event The event name
      @param fn The listener function
      @param context (optional)The context to invoke the listener with
      @return itself
   */
  pub addListener: (string, Js.t({..}) => unit, Js.Undefined.t(Js.t({..}))) => Js.t(_t);

  /**
    Add a one-time listner for a given event

      @deprecated Consider using EventEmitter.on
      @see </bs-pixi/PIXI/EventEmitter-PIXI/#val-once> EventEmitter.on
      @param event The event name
      @param fn The listener function
      @param context (optional)The context to invoke the listener with
      @return itself
   */
  pub once: (string, Js.t({..}) => unit, Js.Undefined.t(Js.t({..}))) => Js.t(_t);

  /**
    Remove the listeners of a given even

      @deprecated Consider using EventEmitter.removeListener
      @see </bs-pixi/PIXI/EventEmitter-PIXI/#val-removeListener> EventEmitter.removeListener
      @param event The event name
      @param fn (optional) Only remove the listeners that match this function
      @param context (optional) Only remove the listeners that have this context
      @param once (optional) Only remove one-time listeners
      @return itself
   */
  pub removeListener: (string, Js.Undefined.t(Js.t({..}) => unit), Js.Undefined.t(Js.t({..})), Js.Undefined.t(bool)) => Js.t(_t);

  /**
    Remove the listeners of a given even

      @deprecated Consider using EventEmitter.removeListener
      @see </bs-pixi/PIXI/EventEmitter-PIXI/#val-removeListener> EventEmitter.removeListener
      @param event The event name
      @param fn (optional) Only remove the listeners that match this function
      @param context (optional) Only remove the listeners that have this context
      @param once (optional) Only remove one-time listeners
      @return itself
   */
  pub off: (string, Js.Undefined.t(Js.t({..}) => unit), Js.Undefined.t(Js.t({..})), Js.Undefined.t(bool)) => Js.t(_t);
  
  /**
    Remove all listeners, or those of the specified event

      @deprecated Consider using EventEmitter.removeAllListeners if Symbol support is needed
      @see </bs-pixi/PIXI/EventEmitter-PIXI/#val-removeAllListeners> EventEmitter.removeAllListeners
      @param event The event name
      @return itself
   */
  pub removeAllListeners: Js.Undefined.t(string) => Js.t(_t);
};

/**
  A high performance event emitter
 */
type t = Js.t(_t);

[@bs.module][@bs.new]
external create: unit => Js.t(#_t) = "eventemitter3";

/**
  an array listing the events for which the emitter has registered listeners
 */
[@bs.send]
external eventNames: Js.t(#_t) => array(string) = "eventNames";

/**
  listeners registered for a given event

    @param event The event name
    @return listeners registered for a given event
  */
[@bs.send]
external listeners: (Js.t(#_t), ~event: [@bs.unwrap] [`String(string) | `Symbol(Symbol.t)]) => array(Js.t({..}) => unit) = "listeners"; 

/**
  the number of listeners listening to a given event

    @param event The event name
    @return the number of listeners listening to a given event
  */
[@bs.send]
external listenerCount: (Js.t(#_t), ~event: [@bs.unwrap] [`String(string) | `Symbol(Symbol.t)]) => int = "listenerCount";

/**
  Calls each of the listeners registered for a given event

    @param event The event name
    @return true if the event had listeners, else false
 */
[@bs.send]
external emit: (Js.t(#_t), ~event: [@bs.unwrap] [`String(string) | `Symbol(Symbol.t)]) => bool = "emit";

/**
  Add a listener for a given event

    @param event The event name
    @param fn The listener function
    @param context (optional)The context to invoke the listener with
    @return itself
*/
[@bs.send]
external on: (
  Js.t(#_t as 'a), 
  ~event: [@bs.unwrap] [`String(string) | `Symbol(Symbol.t)], 
  ~fn: 'b => unit, 
  ~context: 'c=?, unit)
    => Js.t('a) = "on";

/**
  Add a listener for a given event

    @param event The event name
    @param fn The listener function
    @param context (optional)The context to invoke the listener with
    @return itself
*/
[@bs.send]
external addListener: (
  Js.t(#_t as 'a), 
  ~event: [@bs.unwrap] [`String(string) | `Symbol(Symbol.t)], 
  ~fn: 'b => unit, 
  ~context: 'c=?, unit) 
    => Js.t('a) = "addListener";

 /**
  Add a one-time listner for a given event

    @param event The event name
    @param fn The listener function
    @param context (optional)The context to invoke the listener with
    @return itself
  */
[@bs.send]
external once: (
  Js.t(#_t as 'a), 
  ~event: [@bs.unwrap] [`String(string) | `Symbol(Symbol.t)], 
  ~fn: 'b => unit, 
  ~context: 'c=?, unit) 
    => Js.t('a) = "once";

/**
  Remove the listeners of a given even

    @param event The event name
    @param fn (optional) Only remove the listeners that match this function
    @param context (optional) Only remove the listeners that have this context
    @param once (optional) Only remove one-time listeners
    @return itself
  */
[@bs.send]
external removeListener: (
  Js.t(#_t as 'a),
  ~event: [@bs.unwrap] [`String(string) | `Symbol(Symbol.t)],
  ~fn: (Js.t({..}) => unit)=?, 
  ~context: Js.t({..})=?, 
  ~once: bool=?, unit) 
    => Js.t('a) = "removeListener";

/**
  Remove the listeners of a given even

    @param event The event name
    @param fn (optional) Only remove the listeners that match this function
    @param context (optional) Only remove the listeners that have this context
    @param once (optional) Only remove one-time listeners
    @return itself
  */
[@bs.send]
external off: (
  Js.t(#_t as 'a), 
  ~event: [@bs.unwrap] [`String(string) | `Symbol(Symbol.t)],
  ~fn: (Js.t({..}) => unit)=?, 
  ~context: Js.t({..})=?, 
  ~once: bool=?, unit) 
    => Js.t('a) = "off";

/**
  Remove all listeners, or those of the specified event

    @param event The event name
    @return itself
  */
[@bs.send]
external removeAllListeners: (Js.t(#_t as 'a), ~event: [@bs.unwrap] [`String(string) | `Symbol(Symbol.t)]=?, unit) => Js.t('a) = "removeAllListeners";
