#include <stdio.h>
#include <string.h>

// Function to convert uppercase to lowercase using bitwise operations
char upperToLower(char c) {
    return c | 32;  // 'A' to 'Z' have 5th bit (binary) different from 'a' to 'z'
}

// Function to convert lowercase to uppercase using bitwise operations
char lowerToUpper(char c) {
    return c & ~32; // Clear the 5th bit to convert to uppercase
}

// Function to toggle the case of all characters in a string
void toggleCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = lowerToUpper(str[i]);
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = upperToLower(str[i]);
        }
        // Characters other than alphabet remain unchanged
    }
}

int main() {
    char str[] = "tu@kmiNi123";  // Sample input string

    printf("Input: %s\n", str);

    toggleCase(str);  // Toggle the case of the input string

    printf("Output: %s\n", str);  // Print the output string

    return 0;
}
