#include <stdio.h>

int main() {
    int arr[1000];
    int n = 0;

    // Read all integers until EOF
    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }

    int prefix[1000];
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefix[i] = arr[i];
        if (i > 0)
            prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < n; i++) {
        if (prefix[i] == 0)
            maxLen = i + 1;

        for (int j = i + 1; j < n; j++) {
            if (prefix[j] == prefix[i]) {
                int len = j - i;
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    printf("%d\n", maxLen);

    return 0;
}
