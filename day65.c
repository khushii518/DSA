#include <stdio.h>
#include <stdbool.h>

#define MAX 100005

int adj[MAX][100];   // adjacency list (simple version)
int size[MAX];
bool visited[MAX];

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle detected
        }
    }
    return false;
}

int main() {
    int V, E;

    // Input number of vertices and edges
    scanf("%d %d", &V, &E);

    int edges[E][2];

    // Input edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // Initialize
    for (int i = 0; i < V; i++) {
        size[i] = 0;
        visited[i] = false;
    }

    // Build adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    // Check for cycle in all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
