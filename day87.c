#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == x) {
            printf("%d", mid);
            return 0;
        }
        else if(arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("-1");

    return 0;
}
