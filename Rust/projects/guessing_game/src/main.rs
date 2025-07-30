use rand::Rng;
use std::cmp::Ordering; // The Ordering type is another enum and has the variants Less, Greater, and Equal.
use std::io; // Imports io from the standard libary // Imports random number implemented

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1..=100);
    // Generator that is local to the current thread of execution and is seeded by the operating
    // system.
    // 1..=100 is a range expression, start..=end, that is inclusive both ways

    println!("Please input your guess.");

    // mut makes it mutable (default is immutable)
    // String::new() is a new string instance
    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess) // Passes the reference of mutable, add appends to it
        .expect("Failed to read line");
    // .read_line also returns a Result value, which is called an enumeration, or enum, where
    // it is a type that can have multiple states, each state being called a variant
    // .expect will crash if Result returns Err() and display the error message, and if Ok() is
    // recieved will return the value of Ok. You will recieve a warning if the .expect isn't
    // there

    println!("The secret number is: {secret_number}");

    println!("You guessed: {guess}");
    // You can print the same thing using println!("You guessed: {}", guess);

    match guess.cmp(&secret_number) {
        Ordering::Less => println!("Too small!"),
        Ordering::Greater => println!("Too big!"),
        Ordering::Equal => println!("You win!"),
    }
}
