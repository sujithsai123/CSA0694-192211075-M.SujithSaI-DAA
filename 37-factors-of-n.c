#include <stdio.h>

// Function to print all factors of n
void printFactors(int n) {
    printf("Factors of %d are: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;

    // Read input from user
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Call function to print factors
    printFactors(n);

    return 0;
}
