#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void BFS(int n, int adj[n][n], int s) {
    int visited[n];
    
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, s;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter source: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(n, adj, s);

    return 0;
}
