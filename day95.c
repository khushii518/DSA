#include <stdio.h>
#include <stdlib.h>

// Insertion sort for individual buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    // create buckets
    float **buckets = (float **)malloc(n * sizeof(float *));
    int *count = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float)); // max possible
    }

    // distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        buckets[idx][count[idx]++] = arr[i];
    }

    // sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], count[i]);
    }

    // concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // free memory
    for (int i = 0; i < n; i++)
        free(buckets[i]);
    free(buckets);
    free(count);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}
