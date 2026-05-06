function makeRectangle(w, h) {
  // this = {}
  return {
    'width': w,
    'height': h
  }
}

let rectangleGetArea = function() {
  return this.width * this.height;
}

// Doing it this way makes it so that you only need to
// write it once, and you also get the added benefit
// of saving memory
// let rectanglePrototype = {
//   'getArea' : function() {
//     return this.width * this.height;
//   },
//   'getWidth' : function() {
//     return this.width;
//   }
// }

// Doing it this way give the "Rectangle" thing in front of the object
Rectangle.prototype.getArea = function() {
  return this.width * this.height;
}
Rectangle.prototype.getWidth = function() {
  return this.width;
}

// Constructor
// Doing it this way removes the "Rectangle" thing in front of the object
function Rectangle(w, h) {
  // this = {}
  this.width = w;
  this.height = h;
  // this.getArea = function() {
  //   return this.width * this.height;
  // }
  // You would call this like how you would any other
  // fuction, like:
  //  let rec1 = new Rectangle(3,4);
  //  rec1.getArea();
  // this.getArea = rectangleGetArea;  // This is also valid, and also prevents from making a bunch of
  //                                   // functions that does the same thing, since doing it the other
  //                                   // way creates a new fuction in memory for every instance of rectangle
  // this.__proto__ = rectanglePrototype;

  // return = this
}
// If there is no explicit return, it will return this.
// In that case, width and height would now be in scope.
// this refers to the global object when not in a function
// When using 'let' to initialize a variable, it will not
// go into the global object, but rather a scoped object.
