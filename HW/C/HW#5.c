#include <stdio.h>

// Function to calculate x^n using recursion
float pxn(int x, int n) {
    if (n == 0) return 1;
    else if (n < 0) return 1 / pxn(x, -n);
    else return x * pxn(x, n - 1);
}

// Function to calculate n! using recursion
float fac(int n) {
    if (n <= 1) return 1;
    else return n * fac(n - 1);
}

// Function to calculate sin(x) using the series expansion
float sinxm(int x, int m) {
    if (m == 0) return x;
    else {
        float term = (-1) * pow(-1, m) * pxn(x, 2 * m + 1) / fac(2 * m + 1);
        return term + sinxm(x, m - 1);
    }
}

int main() {
    int x;
    float result;

    printf("Enter the value of x: ");
    scanf("%f", &x);

    result = sinxm(x, 9);
    printf("sin(%f) = %f\n", x, result);

    return 0;
}