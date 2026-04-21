#include <stdio.h>
#include <limits.h>

#define MAX 105
#define INF 1000000000

int main() {
    int n;
    scanf("%d", &n);

    int dist[MAX][MAX];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            if (i != j && dist[i][j] == -1)
                dist[i][j] = INF;
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1");
            else
                printf("%d", dist[i][j]);

            if (j < n - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
