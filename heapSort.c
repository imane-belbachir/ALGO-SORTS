/*Heap sort*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]); // Swap root and largest

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Heapify the root element to maintain the heap property
        heapify(arr, i, 0);
    }
}

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

// Performance measurement function for HeapSort
double measureSortTime(int* arr, int size) {
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
    heapSort(arrCopy, size);
    clock_t end = clock();

    free(arrCopy);

    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Function to print the first 10 elements of an array
void printFirstTenElements(int arr[], int size) {
    printf("First 10 elements: ");
    for (int i = 0; i < 10 && i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Seed the random number generator once
    srand(time(NULL));

    // Handle the case for an array size of 10
    int size = 10;

    // Generate random array of size 10
    int* randomArray = generateRandomArray(size);
    if (!randomArray) return 1;

   

    // Measure sorting time for larger arrays
    int sizes[] = {100, 500, 1000, 5000, 10000, 100000, 105000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
  
    printf("\n                    PERFORMANCE OF HEAP SORT  \n");

    for (int s = 0; s < num_sizes; s++) {
        size = sizes[s];
        printf("________________________\n");
        printf("Array Size: %d\n", size);

        // Generate random array for performance measurement
        int* randomArray = generateRandomArray(size);
        if (!randomArray) continue;

        // Measure sorting time
        double sortTime = measureSortTime(randomArray, size);
        printf("Sorting Time: %f seconds\n", sortTime);

        // Optional: Print first 10 elements before and after sorting
        if (size == 100) {
            printf("First 10 elements before sorting: ");
            printFirstTenElements(randomArray, size);

            // Sort the array
            heapSort(randomArray, size);

            printf("First 10 elements after sorting: ");
            printFirstTenElements(randomArray, size);
        }

        free(randomArray); // Free dynamically allocated array
        printf("\n");
    }

    // Free dynamically allocated memory for size 10
    free(randomArray);

    return 0;
}
