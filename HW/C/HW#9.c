#include <stdio.h>
#include <ctype.h>

int count_uppercase(const char *line) {
    int count = 0;
    while (*line) {
        if (isupper(*line)) {
            count++;
        }
        line++;
    }
    return count;
}

int main() {
    FILE *inputFile, *outputFile1, *outputFile2;
    char line[121]; // buffer to read each line (max 120 characters + null terminator)
    
    // Open the input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the two output files
    outputFile1 = fopen("output1.txt", "w");
    outputFile2 = fopen("output2.txt", "w");
    if (outputFile1 == NULL || outputFile2 == NULL) {
        printf("Error opening output files.\n");
        fclose(inputFile);
        return 1;
    }

    // Read lines from the input file
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        int uppercaseCount = count_uppercase(line);
        
        // Check if the count of uppercase letters is divisible by 3
        if (uppercaseCount % 3 == 0) {
            fputs(line, outputFile1); // Write to output1.txt
        } else {
            fputs(line, outputFile2); // Write to output2.txt
        }
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile1);
    fclose(outputFile2);

    printf("Program executed successfully.\n");

    return 0;
}
