type t = [
  | `Point(Point.t)
  | `ObservablePoint(ObservablePoint.t)
];

[@bs.send]
external copyPointFrom: (
  Point.t, 
  [@bs.unwrap] [`Point(Point.t) | `ObservablePoint(ObservablePoint.t)]
) => Point.t = "copyFrom";

[@bs.send]
external copyObservablePointFrom: (
  ObservablePoint.t, 
  [@bs.unwrap] [`Point(Point.t) | `ObservablePoint(ObservablePoint.t)]
) => ObservablePoint.t = "copyFrom";

[@bs.send]
external _observablePointEquals: (
  ObservablePoint.t,
  [@bs.unwrap] [`Point(Point.t) | `ObservablePoint(ObservablePoint.t)]
) => bool = "equals";

[@bs.send]
external _pointEquals: (
  Point.t,
  [@bs.unwrap] [`Point(Point.t) | `ObservablePoint(ObservablePoint.t)]
) => bool = "equals";

[@bs.send]
external _copyPointToPoint: (Point.t, Point.t) => Point.t = "copyTo";
[@bs.send]
external _copyPointToObservablePoint: (Point.t, ObservablePoint.t) => ObservablePoint.t = "copyTo";
[@bs.send]
external _copyObservablePointToPoint: (ObservablePoint.t, Point.t) => Point.t = "copyTo";
[@bs.send]
external _copyObservablePointToObservablePoint: (ObservablePoint.t, ObservablePoint.t) => ObservablePoint.t = "copyTo";


let equals = (lhs: t, rhs: t) => 
  switch(lhs){
  | `ObservablePoint(point) => point |. _observablePointEquals(rhs)
  | `Point(point) => point |. _pointEquals(rhs)
  };

let copyFrom = (lhs: t, rhs: t): t => 
  switch(lhs){
  | `ObservablePoint(point) =>  `ObservablePoint(point |. copyObservablePointFrom(rhs))
  | `Point(point) => `Point(point |. copyPointFrom(rhs))
  }; 

let copyTo = (lhs: t, rhs: t): t => 
  switch(lhs, rhs){
    | (`ObservablePoint(lhsPoint), `ObservablePoint(rhsPoint)) => `ObservablePoint(lhsPoint |. _copyObservablePointToObservablePoint(rhsPoint))
    | (`ObservablePoint(lhsPoint), `Point(rhsPoint)) => `Point(lhsPoint |. _copyObservablePointToPoint(rhsPoint))
    | (`Point(lhsPoint), `ObservablePoint(rhsPoint)) => `ObservablePoint(lhsPoint |. _copyPointToObservablePoint(rhsPoint))
    | (`Point(lhsPoint), `Point(rhsPoint)) => `Point(lhsPoint |. _copyPointToPoint(rhsPoint))
    };