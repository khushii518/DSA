//Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, k, i;
    int found_index = -1;
    int comparisons = 0;
    if (scanf("%d", &n) != 1) return 1;
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) return 1;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found_index = i;
            break;
        }
    }
    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
    free(arr);
    return 0;
}
