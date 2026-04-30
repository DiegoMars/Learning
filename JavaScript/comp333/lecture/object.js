function makeRectangle(w, h) {
  // this = {}
  return {
    'width': w,
    'height': h
  }
}

// Constructor
function Rectangle(w, h) {
  // this = {}
  this.width = w;
  this.height = h;
  // return = this
}
// If there is no explicit return, it will return this.
// In that case, width and height would now be in scope.
// this refers to the global object when not in a function
// When using 'let' to initialize a variable, it will not
// go into the global object, but rather a scoped object.
