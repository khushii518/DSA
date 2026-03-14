#include <stdio.h>

#define MAX 100

/* Stack */
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}


/* Queue */
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front > rear;
}


int main() {
    int n, x;

    scanf("%d", &n);

    /* Read queue elements */
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    /* Step 1: Move queue → stack */
    while(!isQueueEmpty()) {
        push(dequeue());
    }

    /* Step 2: Move stack → queue */
    while(!isStackEmpty()) {
        enqueue(pop());
    }

    /* Print reversed queue */
    while(!isQueueEmpty()) {
        printf("%d ", dequeue());
    }

    return 0;
}
