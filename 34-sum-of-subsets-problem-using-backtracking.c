#include <stdio.h>

#define MAX 100

void sumOfSubsets(int arr[], int subset[], int n, int sum, int curr_sum, int start) {
    if (curr_sum == sum) {
        // Print the current subset
        printf("{ ");
        for (int i = 0; i < n; i++) {
            if (subset[i] == 1) {
                printf("%d ", arr[i]);
            }
        }
        printf("}\n");
        return;
    }

    if (start == n || curr_sum > sum) {
        return;
    }

    // Include the current element in the subset
    subset[start] = 1;
    sumOfSubsets(arr, subset, n, sum, curr_sum + arr[start], start + 1);

    // Exclude the current element from the subset
    subset[start] = 0;
    sumOfSubsets(arr, subset, n, sum, curr_sum, start + 1);
}

int main() {
    int n, sum;
    int arr[MAX], subset[MAX] = {0};

    // Read the size of the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    // Read the elements of the set
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the required sum
    printf("Enter the required sum: ");
    scanf("%d", &sum);

    // Find and print all subsets with the given sum
    printf("Subsets with sum %d are:\n", sum);
    sumOfSubsets(arr, subset, n, sum, 0, 0);

    return 0;
}
