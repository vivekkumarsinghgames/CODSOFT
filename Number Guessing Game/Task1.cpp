#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "I'm thinking of a number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n";

    // Loop until the user guesses the correct number
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number in " 
                      << attempts << " tries!\n";
        }
    } while (guess != secretNumber);

    return 0;
}
