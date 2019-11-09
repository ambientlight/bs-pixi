/**
  IPoint object represents either Point or ObservablePoint
 */
type t = [
  | `Point(Point.t)
  | `ObservablePoint(ObservablePoint.t)
];

/**
  Copies x and y from second into the first point
    
    @param p1 The point to copy into
    @param p2 The point to copy from
    @return First point with values updated
 */
let copyFrom: (t, t) => t;

/**
  Copies x and y into from first to second point
    
    @param p1 The point to copy from
    @param p2 The point to copy into
    @return Second point with values updated
 */
let copyTo: (t, t) => t;

/**
  Returns true if a given point is equal to other point

    @param p1 first point 
    @param p2 The point to check
    @return Whether the first point equal to second point
 */
let equals: (t, t) => bool;