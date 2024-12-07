#include <stdio.h>
#include <time.h>
#include "randomNumber.h" // Ensure this file is in the same directory

// Function to validate user input
int getValidInput() {
    int guess;
    int valid = 0;
    while (!valid) {
        printf("Enter your guess (1-100): ");
        if (scanf("%d", &guess) == 1 && guess >= 1 && guess <= 100) {
            valid = 1; // Input is valid
        } else {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }
    return guess;
}

// Main function
int main() {
    // I have used ChatGPT to generate this code for Professor Sugivan Ratneswarran's PRG155 class

    int target = GenerateRandomNumber(100); // Generate a random target number
    int guess;
    char name[50];

    // Welcome message
    printf("Welcome to the Guessing Game!\n");
    printf("Enter your first and last name: ");
    scanf("%s", name);

    printf("Hello, %s! Try to guess the number I've chosen (1-100).\n", name);

    // Game loop
    do {
        guess = getValidInput();
        if (guess < target) {
            printf("Too low, %s! Try again.\n", name);
        } else if (guess > target) {
            printf("Too high, %s! Try again.\n", name);
        } else {
            printf("Congratulations, %s! You guessed it right!\n", name);
            break;
        }
    } while (1);

    // Replay option
    char playAgain;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y') {
        printf("Starting a new game...\n");
        main(); // Restart the game
    } else {
        printf("Thanks for playing, %s! Goodbye!\n", name);
    }

    return 0;
}
