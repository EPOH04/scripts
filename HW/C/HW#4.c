#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_WORDS 6
#define WORD_LENGTH 2

// Function to generate a random letter
char randomLetter() {
    return 'a' + rand() % 26;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // List of target words
    const char* targetWords[NUM_WORDS] = {"at", "is", "he", "we", "up", "on"};

    char currentWord[WORD_LENGTH + 1] = {0}; // +1 for null terminator
    int letterCount = 0;

    while (1) {
        // Generate a random letter
        char letter = randomLetter();
        printf("%c", letter);

        // Append the letter to the current word
        currentWord[0] = currentWord[1];
        currentWord[1] = letter;
        currentWord[2] = '\0';

        // Increment the letter count
        letterCount++;

        // Check if the current word matches any of the target words
        for (int i = 0; i < NUM_WORDS; i++) {
            if (strcmp(currentWord, targetWords[i]) == 0) {
                printf("\n\nMatch found: %s\n", currentWord);
                printf("Total number of letters typed: %d\n", letterCount);
                return 0;
            }
        }
    }

    return 0;
}