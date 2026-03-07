#include <stdio.h>
#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = value;
}

void display(Queue *q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

int main() {
    int n, x;
    Queue q;

    init(&q);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    display(&q);

    return 0;
}
