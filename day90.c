#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (currentTime + arr[i] > maxTime) {
            painters++;
            currentTime = arr[i];

            if (painters > k)
                return 0;
        } else {
            currentTime += arr[i];
        }
    }
    return 1;
}

int minTime(int arr[], int n, int k) {
    int low = arr[0], high = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1;   // try better (smaller time)
        } else {
            low = mid + 1;    // increase allowed time
        }
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));
    return 0;
}
