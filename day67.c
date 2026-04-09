#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int node, int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, V);
        }
    }

    stack[++top] = node; // push after visiting all neighbors
}

void topoSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V);
        }
    }

    // Print in reverse order of stack
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int V = 6;

    // Initialize graph (example DAG)
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Edges: u -> v
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topoSort(V);

    return 0;
}
