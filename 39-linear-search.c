#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index of the key if found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int arr[] = {12, 45, 67, 23, 56, 34, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, index;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform linear search
    index = linearSearch(arr, n, key);

    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
