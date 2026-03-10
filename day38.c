#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void init(Deque *dq){
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

int empty(Deque *dq){
    return dq->size == 0;
}

int size(Deque *dq){
    return dq->size;
}

void push_front(Deque *dq, int val){
    if(dq->size == MAX){
        printf("Deque Full\n");
        return;
    }

    if(empty(dq)){
        dq->front = dq->rear = 0;
    }
    else{
        dq->front = (dq->front - 1 + MAX) % MAX;
    }

    dq->arr[dq->front] = val;
    dq->size++;
}

void push_back(Deque *dq, int val){
    if(dq->size == MAX){
        printf("Deque Full\n");
        return;
    }

    if(empty(dq)){
        dq->front = dq->rear = 0;
    }
    else{
        dq->rear = (dq->rear + 1) % MAX;
    }

    dq->arr[dq->rear] = val;
    dq->size++;
}

int pop_front(Deque *dq){
    if(empty(dq))
        return -1;

    int val = dq->arr[dq->front];

    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    }
    else{
        dq->front = (dq->front + 1) % MAX;
    }

    dq->size--;
    return val;
}

int pop_back(Deque *dq){
    if(empty(dq))
        return -1;

    int val = dq->arr[dq->rear];

    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    }
    else{
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }

    dq->size--;
    return val;
}

int front(Deque *dq){
    if(empty(dq)) return -1;
    return dq->arr[dq->front];
}

int back(Deque *dq){
    if(empty(dq)) return -1;
    return dq->arr[dq->rear];
}

void clear(Deque *dq){
    dq->front = dq->rear = -1;
    dq->size = 0;
}

void reverse(Deque *dq){
    int i = dq->front, j = dq->rear;

    for(int c=0;c<dq->size/2;c++){
        int temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;

        i = (i+1)%MAX;
        j = (j-1+MAX)%MAX;
    }
}

void display(Deque *dq){
    if(empty(dq)){
        printf("Deque Empty\n");
        return;
    }

    int i = dq->front;
    for(int c=0;c<dq->size;c++){
        printf("%d ", dq->arr[i]);
        i = (i+1)%MAX;
    }
    printf("\n");
}

int main(){

    Deque dq;
    init(&dq);

    push_back(&dq,10);
    push_back(&dq,20);
    push_front(&dq,5);

    display(&dq);

    printf("Front: %d\n",front(&dq));
    printf("Back: %d\n",back(&dq));

    printf("Pop Front: %d\n",pop_front(&dq));
    printf("Pop Back: %d\n",pop_back(&dq));

    display(&dq);

    return 0;
}
