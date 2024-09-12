#include <stdio.h>

// Function to find the minimum and maximum values in an array
void findMinMax(int arr[], int n, int minMax[]) {
    minMax[0] = arr[0]; // min
    minMax[1] = arr[0]; // max

    for (int i = 1; i < n; i++) {
        if (arr[i] < minMax[0]) {
            minMax[0] = arr[i];
        }
        if (arr[i] > minMax[1]) {
            minMax[1] = arr[i];
        }
    }
}

// Function to print the sequence from min to max
void printSequence(int min, int max) {
    for (int i = min; i <= max; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n;

    // Read the size of the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int arr[n];

    // Read the elements of the list
    printf("Enter the elements of the list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minMax[2];
    
    // Find the minimum and maximum values in the list
    findMinMax(arr, n, minMax);

    // Print the sequence from minimum to maximum value
    printf("The sequence from minimum to maximum value is: ");
    printSequence(minMax[0], minMax[1]);

    return 0;
}
