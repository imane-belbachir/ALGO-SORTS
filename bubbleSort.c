/*Bubble Sort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random arrays
int* generateRandomArray(int size) {
    srand(time(NULL)); // Seed the random number generator
    int* arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random integers between 0 and 9999
    }
    return arr;
}

// Performance measurement function
double measureSortTime(void (*sortFunction)(int*, int), int* arr, int size) {
    clock_t start, end;
    
    // Create a copy of the array to preserve the original
    int* arrCopy = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }
    
    start = clock();
    
    // Call the sorting function
    sortFunction(arrCopy, size);
    
    end = clock();
    
    // Free the copy
    free(arrCopy);
    
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Array sizes to test
    int sizes[] = {100, 500, 1000, 5000, 10000,100000,105000,};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Bubble Sort Performance Measurement\n");
    printf("-----------------------------------\n");
    
    // Test for multiple array sizes
    for (int s = 0; s < num_sizes; s++) {
        int size = sizes[s];
        
        // Generate random array
        int* randomArray = generateRandomArray(size);
        
        // Measure sorting time
        double sortTime = measureSortTime(bubbleSort, randomArray, size);
        
        // Print results
        printf("Array Size: %d\n", size);
        printf("Sorting Time: %f seconds\n", sortTime);
        
        // Optional: Print the first 10 elements before and after sorting
        if (size <= 100) {
            printf("First 10 elements before sorting: ");
            for (int i = 0; i < 10 && i < size; i++)
                printf("%d ", randomArray[i]);
            printf("\n");
            
            bubbleSort(randomArray, size);
            
            printf("First 10 elements after sorting: ");
            for (int i = 0; i < 10 && i < size; i++)
                printf("%d ", randomArray[i]);
            printf("\n");
        }
        
        printf("\n");
        
        // Free the dynamically allocated array
        free(randomArray);
    }
    
    return 0;
}
