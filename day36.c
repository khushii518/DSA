#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    
    scanf("%d", &n);
    
    int *queue = (int*)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    for(int i = 0; i < m; i++) {
        int temp = queue[front];      // dequeue
        front = (front + 1) % n;

        rear = (rear + 1) % n;        // enqueue again
        queue[rear] = temp;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", queue[(front + i) % n]);
    }

    free(queue);
    return 0;
}
