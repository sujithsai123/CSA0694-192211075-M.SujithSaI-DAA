#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n, num, pos;

    // Read the size of the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Read the elements of the list
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the number to be inserted
    printf("Enter the number to be inserted: ");
    scanf("%d", &num);

    // Read the position where the number is to be inserted
    printf("Enter the position where the number is to be inserted (1 to %d): ", n + 1);
    scanf("%d", &pos);

    // Validate the position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Please enter a position between 1 and %d\n", n + 1);
    } else {
        // Move elements to the right to create space for the new element
        for (int i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }

        // Insert the new element
        arr[pos - 1] = num;
        n++; // Increase the size of the list

        // Print the updated list
        printf("The updated list is:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
