#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS to detect cycle
bool dfs(int node, int** adj, int* adjSize, int* visited, int* recStack) {
    
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int nei = adj[node][i];

        if (!visited[nei]) {
            if (dfs(nei, adj, adjSize, visited, recStack))
                return true;
        }
        else if (recStack[nei]) {
            return true; // cycle found
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int)); // worst case
    }

    // input edges (u → v)
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    int* visited = (int*)calloc(V, sizeof(int));
    int* recStack = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
