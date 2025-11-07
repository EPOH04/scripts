#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a valid hexadecimal number
int isvalidHex(const char* str) {
    // Check if the string is NULL or empty
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }

    // Skip the "0x" or "0X" prefix if present
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        str += 2;  // Move the pointer past the "0x" or "0X"
    }

    // If the string is empty after skipping "0x" or "0X", it's invalid
    if (strlen(str) == 0) {
        return 0;
    }

    // Check if all characters in the string are valid hexadecimal digits
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isxdigit(str[i])) {
            return 0;  // Return 0 if any character is not a valid hexadecimal digit
        }
    }

    // All characters are valid hexadecimal digits
    return 1;
}

// Main function to test isvalidHex()
int main() {
    // Test cases
    char *test1 = "0x1a3F";
    char *test2 = "0Xabc";
    char *test3 = "123G";
    char *test4 = "0x123Z";
    char *test5 = "abcd";

    // Testing the function with various inputs
    printf("Test 1: %s\n", test1);
    printf("Valid Hex: %d\n", isvalidHex(test1));  // Expected output: 1

    printf("Test 2: %s\n", test2);
    printf("Valid Hex: %d\n", isvalidHex(test2));  // Expected output: 1

    printf("Test 3: %s\n", test3);
    printf("Valid Hex: %d\n", isvalidHex(test3));  // Expected output: 0

    printf("Test 4: %s\n", test4);
    printf("Valid Hex: %d\n", isvalidHex(test4));  // Expected output: 0

    printf("Test 5: %s\n", test5);
    printf("Valid Hex: %d\n", isvalidHex(test5));  // Expected output: 1

    return 0;
}
