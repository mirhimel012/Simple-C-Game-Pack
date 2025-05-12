#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void playGuessingGame();
void playAdventureGame();
void playTriviaQuizGame();

int main() {
    int choice;

    do {
        printf("\nChoose a game:\n");
        printf("1. Guessing Game\n");
        printf("2. Text-based Adventure Game\n");
        printf("3. Trivia Quiz Game\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                playGuessingGame();
                break;
            case 2:
                playAdventureGame();
                break;
            case 3:
                playTriviaQuizGame();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Enter a number 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to generate random number
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Guessing Game function
void playGuessingGame() {
    srand(time(NULL));
    int numberToGuess = generateRandomNumber(1, 100);
    int guess, attempts = 0;

    printf("Welcome to the Guessing Game!\n");
    printf("Guess a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < numberToGuess) {
            printf("Too low!\n");
        } else if (guess > numberToGuess) {
            printf("Too high!\n");
        } else {
            printf("Correct! You guessed it in %d attempts.\n", attempts);
        }
    } while (guess != numberToGuess);
}


void showIntro() {
    printf("Welcome to the Adventure Game!\n");
    printf("You're in a dark forest with 3 paths.\n");
}

void pathChoice() {
    char choice[20];
    printf("Choose a path (left/right/straight): ");
    scanf("%s", choice);

    if (strcmp(choice, "left") == 0) {
        printf("A wild wolf appears! You lose.\n");
    } else if (strcmp(choice, "right") == 0) {
        printf("A peaceful clearing! You win.\n");
    } else if (strcmp(choice, "straight") == 0) {
        printf("A rickety bridge appears. Cross or turn back? (cross/turn back): ");
        scanf("%s", choice);
        if (strcmp(choice, "cross") == 0) {
            printf("The bridge breaks. You lose!\n");
        } else if (strcmp(choice, "turn back") == 0) {
            printf("You find another path and escape safely. You win!\n");
        } else {
            printf("Invalid choice. Game over.\n");
        }
    } else {
        printf("Invalid choice. Game over.\n");
    }
}

void playAdventureGame() {
    showIntro();
    pathChoice();
}
