/*Gnome sort*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Gnome Sort
void gnomeSort(int arr[], int n) {
    int index = 0;
    while (index < n) {
        if (index == 0 || arr[index] >= arr[index - 1]) {
            index++;
        } else {
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
        }
    }
}

// Function to generate random arrays
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }
}

int main() {
    int sizes[] = {100, 500, 1000, 5000, 10000, 50000,100000,105000};  // Array sizes
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("N\tT(n) Experimental (seconds)\n");

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        generateRandomArray(arr, n);

        clock_t start = clock();
        gnomeSort(arr, n);
        clock_t end = clock();

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, timeTaken);

        free(arr);
    }

    return 0;
}
