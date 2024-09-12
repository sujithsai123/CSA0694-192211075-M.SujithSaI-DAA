#include <stdio.h>
#include <stdlib.h>

// Function to calculate binomial coefficient using dynamic programming
int binomialCoefficient(int n, int k) {
    int i, j;

    // Create an array to store results of subproblems
    int *C = (int *)malloc((k + 1) * sizeof(int));
    for (i = 0; i <= k; i++) {
        C[i] = 0;
    }
    C[0] = 1;  // Base case: C(n, 0) = 1

    // Calculate binomial coefficient in bottom-up manner
    for (i = 1; i <= n; i++) {
        for (j = (i < k ? i : k); j > 0; j--) {
            C[j] += C[j - 1];
        }
    }

    int result = C[k];

    // Free allocated memory
    free(C);

    return result;
}

int main() {
    int n, k;

    // Input values for n and k
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);

    if (k > n) {
        printf("Invalid input: k should be less than or equal to n.\n");
        return 1;
    }

    int result = binomialCoefficient(n, k);
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, result);

    return 0;
}
