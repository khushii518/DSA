#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

void mergeIntervals(int intervals[][2], int n) {
    if (n == 0) return;

    // sort by start time
    qsort(intervals, n, sizeof(intervals[0]), compare);

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= end) {
            // overlap → extend
            if (intervals[i][1] > end)
                end = intervals[i][1];
        } else {
            // no overlap → print current
            printf("%d %d\n", start, end);
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // print last interval
    printf("%d %d\n", start, end);
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    mergeIntervals(intervals, n);
    return 0;
}
