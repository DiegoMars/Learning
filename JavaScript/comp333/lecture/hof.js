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

function callMe(foo) {
  foo();
}

function indirectIf(b, f1, f2) {
  if (b) {
    f1();
  } else {
    f2();
  }
}

function indirectWhile(f1, f2) {
  if (f1()){
    f2();
    indirectWhile(f1, f2);
  }
}

function add(a, b) { return a + b; }
function sub(a, b) { return a - b; }

function delayedAdd(x) {
  return function(y) {
    return x + y;
  };
}

function withAdd(fun, val) {
  return function(val1, val2) {
    return fun(val1, val2) + val;
  };
}

// Debugging function
// function debug(...) {...}
// function add(x,y) {return x+y;}
// let debugAdd = debug(add);
// let result = debugAll(2, 3);
//    First: 2
//    Second: 3
//    Return Value: 5
//  console.log(result); // 5
//  
//  Prof mentioned how debuggers sort of work this way where a
//  function is passed to the debugging function so you can, well,
//  debug
// f(p1, p2)
function debug(f) {
  return function(p1, p2) {
    console.log("p1: " + p1);
    console.log("p2: " + p2);
    let val = f(p1,p2);
    console.log("return: " + val);
    return val;
  }
}

