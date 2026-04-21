#include <stdio.h>
#include <limits.h>

#define MAX 105
#define INF INT_MAX

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph
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
        graph[v][u] = w;   // remove this line if directed graph
    }

    int source;
    scanf("%d", &source);

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra Algorithm
    for (int count = 1; count <= n; count++) {
        int u = -1;
        int minDist = INF;

        // Find unvisited node with minimum distance
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output distances
    for (int i = 1; i <= n; i++) {
        printf("%d", dist[i]);
        if (i < n) printf(" ");
    }

    printf("\n");

    return 0;
}
