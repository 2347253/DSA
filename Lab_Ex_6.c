#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct PlayerData {
    int skillLevel;
};

void quickSort(struct PlayerData arr[], int low, int high, int* quickComparisons);
void bubbleSort(struct PlayerData arr[], int size, int* bubbleComparisons);

int partition(struct PlayerData arr[], int low, int high, int* quickComparisons);

void swap(struct PlayerData* a, struct PlayerData* b);

void generateRandomData(struct PlayerData arr[], int size);

void writeDataToFile(struct PlayerData arr[], int size, const char* filename);
void readDataFromFile(struct PlayerData arr[], int size, const char* filename);

void printArray(struct PlayerData arr[], int size);

int main() {
    const int size = 5;
    int i;
    struct PlayerData playerDataQuick[size];
    struct PlayerData playerDataBubble[size];

    generateRandomData(playerDataQuick, size);

    for ( i = 0; i < size; i++) {
        playerDataBubble[i] = playerDataQuick[i];
    }

    // Display original data
    printf("Original Player Data: ");
    printArray(playerDataQuick, size);

    // Sort the player data using Quick Sort
    int quickComparisons = 0;
    quickSort(playerDataQuick, 0, size - 1, &quickComparisons);

    printf("\nSorted Player Data (Quick Sort): ");
    printArray(playerDataQuick, size);
    printf("Number of comparisons (Quick Sort): %d\n", quickComparisons);

    // Sort the player data using Bubble Sort
    int bubbleComparisons = 0;
    bubbleSort(playerDataBubble, size, &bubbleComparisons);

    printf("\nSorted Player Data (Bubble Sort): ");
    printArray(playerDataBubble, size);
    printf("Number of comparisons (Bubble Sort): %d\n", bubbleComparisons);

    // Check and display which sort was better
    if (quickComparisons < bubbleComparisons) {
        printf("\nQuick Sort performed better than Bubble Sort in terms of comparisons.\n");
    } else if (quickComparisons > bubbleComparisons) {
        printf("\nBubble Sort performed better than Quick Sort in terms of comparisons.\n");
    } else {
        printf("\nThe number of comparisons made by Quick Sort and Bubble Sort is equal.\n");
    }

    return 0;
}

// Quick Sort implementation
void quickSort(struct PlayerData arr[], int low, int high, int* quickComparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, quickComparisons);

        quickSort(arr, low, pi - 1, quickComparisons);
        quickSort(arr, pi + 1, high, quickComparisons);
    }
}

// Bubble Sort implementation
void bubbleSort(struct PlayerData arr[], int size, int* bubbleComparisons) {
	int i,j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            (*bubbleComparisons)++;
            if (arr[j].skillLevel > arr[j + 1].skillLevel) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Partition function for Quick Sort
int partition(struct PlayerData arr[], int low, int high, int* quickComparisons) {
    int pivot = arr[high].skillLevel;
    int i = (low - 1);
    int j;

    for ( j = low; j <= high - 1; j++) {
        (*quickComparisons)++;
        if (arr[j].skillLevel < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(struct PlayerData* a, struct PlayerData* b) {
    struct PlayerData temp = *a;
    *a = *b;
    *b = temp;
}

// Generate random numerical data for player skill levels
void generateRandomData(struct PlayerData arr[], int size) {
	int i;
    srand(time(NULL));
    for ( i = 0; i < size; i++) {
        arr[i].skillLevel = rand() % 100; // Assuming a range of 0 to 99 for player skill levels
    }
}

// Write data to a file using structures
void writeDataToFile(struct PlayerData arr[], int size, const char* filename) {
	int i;
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        for ( i = 0; i < size; i++) {
            fprintf(file, "%d\n", arr[i].skillLevel);
        }
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}

// Read data from a file using structures
void readDataFromFile(struct PlayerData arr[], int size, const char* filename) {
	int i;
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        for ( i = 0; i < size; i++) {
            fscanf(file, "%d", &arr[i].skillLevel);
        }
        fclose(file);
    } else {
        printf("Error opening file for reading.\n");
    }
}

// Print array elements
void printArray(struct PlayerData arr[], int size) {
	int i;
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i].skillLevel);
    }
    printf("\n");
}
