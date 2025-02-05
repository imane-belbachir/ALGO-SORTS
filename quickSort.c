/*Quick sort */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Function to generate random arrays
int* generateRandomArray(int size) {
    if (size <= 0) {
        printf("Error: Invalid array size.\n");
        return NULL;
    }
    int* arr = malloc(size * sizeof(int));
    if (!arr) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random integers between 0 and 9999
    }
    return arr;
}

// Performance measurement function
double measureSortTime(void (*sortFunction)(int*, int, int), int* arr, int size) {
    if (!arr || size <= 0) {
        printf("Error: Invalid array or size.\n");
        return -1.0;
    }

    int* arrCopy = malloc(size * sizeof(int));
    if (!arrCopy) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the array to preserve the original
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }

    clock_t start = clock();
    sortFunction(arrCopy, 0, size - 1);
    clock_t end = clock();

    free(arrCopy);

    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Seed the random number generator once
    srand(time(NULL));

    // Test array sizes
    int sizes[] = {1000, 5000, 10000, 100000,105000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Quick Sort Performance Measurement\n");
    printf("-----------------------------------\n");

    for (int s = 0; s < num_sizes; s++) {
        int size = sizes[s];
        printf("Array Size: %d\n", size);

        // Generate random array
        int* randomArray = generateRandomArray(size);
        if (!randomArray) continue;

        // Measure sorting time
        double sortTime = measureSortTime(quickSort, randomArray, size);
        printf("Sorting Time: %f seconds\n", sortTime);

        // Optional: Validate sorting for smaller arrays
        if (size <= 1000) {
            printf("First 10 elements before sorting: ");
            for (int i = 0; i < 10 && i < size; i++) {
                printf("%d ", randomArray[i]);
            }
            printf("\n");

            // Sort the array
            quickSort(randomArray, 0, size - 1);

            printf("First 10 elements after sorting: ");
            for (int i = 0; i < 10 && i < size; i++) {
                printf("%d ", randomArray[i]);
            }
            printf("\n");
        }

        free(randomArray); // Free dynamically allocated array
        printf("\n");
    }

    return 0;
}
