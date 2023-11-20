#include <stdio.h>

void recursiveSegregate(int[], int);
void iterativeSegregate(int[], int);
void printArray(int[], int);
void swap(int *, int *);

int main() {
    int arr1[] = {3, 6, 5, 4, 7, 2, 9};
    int arr2[] = {7, 4, 3, 9, 8, 2, 6};
    int n = 7;

    printf("First Array: ");
    printArray(arr1, n);

    recursiveSegregate(arr1, n);

    printf("\nAfter Segregation using Recursion: ");
    printArray(arr1, n);

    printf("\n\nSecond Array: ");
    printArray(arr2, n);

    iterativeSegregate(arr2, n);

    printf("\nAfter Segregation using Iteration: ");
    printArray(arr2, n);

    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recursiveSegregate(int arr[], int n) {
    if (n == 0) {
        return;
    } else if (arr[n - 1] % 2 != 0) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] % 2 == 0) {
                swap(&arr[i], &arr[n - 1]);
                recursiveSegregate(arr, n - 1);
            }
        }
    } else {
        recursiveSegregate(arr, n - 1);
    }
}

void iterativeSegregate(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        while (arr[left] % 2 != 0 && left < right) {
            left++;
        }

        while (arr[right] % 2 == 0 && left < right) {
            right--;
        }

        if (left < right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

