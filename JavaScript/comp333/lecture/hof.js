function printSome(arr, operation) {
  for (let index = 0; index < arr.length; index++) {
    let elem = arr[index];
    if (operation(elem)) { // Here, a function is treated like data
      console.log(elem);
    }
  }
}

function printAll(arr) {
  // for (let index = 0; index < arr.length; index++) {
  //   let elem = arr[index];
  //   console.log(elem);
  // }
  printSome(arr, () => true); // This is called an arrow function
}
// While these are kind of free (as in, passing a function), there
// is extra memory being allocated. One place where this happens
// is when a variable from an outer conext is used (the functions
// that do this are called closures), so the value needs to be
// copied in an extra spot, creating some overhead.
function printLessThan(arr, value) { // The value here is an outer context
  printSome(arr, 
    function(e) {
      return e < value; // value is copied here
    }
  );
}
function printLessThanFive(arr) {
  printLessThan(arr, 5);
}
function printLessThanTen(arr) {
  printLessThan(arr, 10);
}
function printGreaterThan(arr, value) {
  // printSome(arr, (e) => e > value);
  printSome(arr,
    function(e) {
      return e > value;
    }
  );
}
