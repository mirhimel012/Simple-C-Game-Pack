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
