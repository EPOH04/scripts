#include <stdio.h>

#define N 4 // You can change N to the desired matrix size

// Function to calculate the sum of elements in the upper triangle (including the main diagonal)
int sumUpperTriangle(int a[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

// Function to calculate the sum of elements in the lower triangle (including the main diagonal)
int sumLowerTriangle(int a[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

// Main function to test the above functions
int main() {
    // Example matrix (4x4)
    int matrix[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Calculate sum of upper triangle
    int upperSum = sumUpperTriangle(matrix);
    printf("Sum of upper triangle: %d\n", upperSum);

    // Calculate sum of lower triangle
    int lowerSum = sumLowerTriangle(matrix);
    printf("Sum of lower triangle: %d\n", lowerSum);

    return 0;
}
