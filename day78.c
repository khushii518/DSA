#include <stdio.h>
#include <limits.h>

#define MAX 105

int graph[MAX][MAX];
int selected[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph with 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int totalWeight = 0;
    selected[1] = 1;   // Start from node 1

    for (int edgeCount = 0; edgeCount < n - 1; edgeCount++) {
        int min = INT_MAX;
        int x = 0, y = 0;

        for (int i = 1; i <= n; i++) {
            if (selected[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        selected[y] = 1;
        totalWeight += min;
    }

    printf("%d\n", totalWeight);

    return 0;
}
