// Players generally sit in a circle. The player designated to go first says 
// the number "one", and the players then count upwards in turn. However, any 
// number divisible by three is replaced by the word fizz and any number 
// divisible by five is replaced by the word buzz. Numbers divisible by both 
// three and five (i.e. divisible by fifteen) become fizz buzz. A player who 
// hesitates or makes a mistake is eliminated.

let answer = parseInt(prompt("Please enter the number you would like to FizzBuzz up to: "));
// parseInt is seems like it is the typecaster from python, and prompt is like
// the input function

// The same as cpp it looks like
for (let i = 1; i <= answer; i++) {
  if (i % 15 == 0) {
    console.log("FizzBuzz");
  } else if (i % 3 == 0) {
    console.log("Fizz");
  } else if (i % 5 == 0) {
    console.log("Buzz");
  } else {
    console.log(i)
  }
}
