#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX], front = 0, rear = -1;
void enqueue(int x) {
    queue[++rear] = x;
}
int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front > rear;
}
void topologicalSort(int V, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }
    int count = 0;
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;
        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}
