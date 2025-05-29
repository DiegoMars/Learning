// Oooooo it downloaded the treesitter thing for javascript automatically
// Very nice kickstart
//
// This is just some reference like for variables, operators, etc

let name = "John";
var surname = "Doe"; 	// These 2 ways of initializing are valid, but "let" is
											// used more I think, and var is older
name = "Diego" // Don't need an initializer to rename variables

console.log(name); // Prints to terminal (or console idk the name)
console.log(surname);

const pi = 3.14; // Same as const in python

console.log((4 + 6) / 10);  // This should work as expected

// In javascript, strings are the same with '', "", and ``.
// But with backticks, you can put stuff in them, like in pythong with f"Stuff"
console.log(`Here is pi: ${pi}`);

// Look up falsy and truthy stuff stuff

if (false){ // In lower case
	console.log(`Here is pi: ${pi}`);
} else {
	console.log(`Here is pi: nvm`)
}

// Ternary operator
let booleanThing = false;
console.log(booleanThing ? "This is true" : "This is false");
// I just learned that js does the semicolons for you, but it is still best
// practice to do it yourself

// Sample function
booleanThing
function foo(ting) {
	return ting + " Thing";
}
console.log(foo("Idk"));

// Function Declaration
function sum(a, b) {
  return a + b;
}
// Function Expression
let sum2 = function(a, b) {
  return a + b;
};
// A Function Expression is created when the execution reaches it and is usable
// only from that moment.

// Arrow functions 
let sum3 = (a, b) => a + b;
/* This arrow function is a shorter form of:

let sum = function(a, b) {
  return a + b;
};
*/
console.log( sum3(1, 2) ); // 3

// Some array stuff
console.log("Map demo below:")
const arr = [1, 2, 3, 4, 5];
const mappedArr = arr.map((num) => num + 1); // Arrow function
																						 // map runs every element through
																						 // through a specified function
console.log(mappedArr); // Outputs [2, 3, 4, 5, 6]
// Note that this does not override the original array

// This demonstrates the filter function, which returns an array only if the
// element mapped through the function is truw
console.log("Filter demo below:")
function isOdd(num) {
  return num % 2 !== 0;
}
const arr2 = [1, 2, 3, 4, 5];
const oddNums = arr2.filter(isOdd);
console.log(oddNums); // Outputs [1, 3, 5];
console.log(arr2); // Outputs [1, 2, 3, 4, 5], original array is not affected

// Demonstration of the reduce function
console.log("Reduce demo below:")
const arr3 = [1, 2, 3, 4, 5];
const productOfAllNums = arr3.reduce((total, currentItem) => {
  return total * currentItem;
}, 1);
console.log(productOfAllNums); // Outputs 120;
console.log(arr3); // Outputs [1, 2, 3, 4, 5]
