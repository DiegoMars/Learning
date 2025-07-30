use rand::Rng;
use std::cmp::Ordering; // The Ordering type is another enum and has the variants Less, Greater, and Equal.
use std::io; // Imports io from the standard libary // Imports random number implemented

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1..=100);
    // Generator that is local to the current thread of execution and is seeded by the operating
    // system.
    // 1..=100 is a range expression, start..=end, that is inclusive both ways

    loop {
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

        // let guess: u32 = guess.trim().parse().expect("Please type a number!");
        // We are making an unsigned 32-bit number, parsing the string into a number
        // trim() removes the whitespce from guess, which would have the \n since the user presses
        // enter when putting in the string. This is required to make a u32 variable
        // parse() converts a string into a number

        println!("You guessed: {guess}");
        // You can print the same thing using println!("You guessed: {}", guess);

        let guess: u32 = guess.trim().parse().expect("Please type a number!");

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
        // match guess.cmp(&secret_number) {
        //     // I think cmp could be compare
        //     Ordering::Less => println!("Too small!"),
        //     Ordering::Greater => println!("Too big!"),
        //     Ordering::Equal => println!("You win!"),
        // }
        // Match does something according to what variant is returned
        // Each outcome is called an arm, and runs if what is returned matches that arm
    }
}
