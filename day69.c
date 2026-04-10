#define MAX 1001
#define INF 1000000000

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Add edge u → v
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap
typedef struct {
    int node, dist;
} Pair;

typedef struct {
    Pair arr[10001];
    int size;
} Heap;

void swap(Pair* a, Pair* b) {
    Pair t = *a;
    *a = *b;
    *b = t;
}

void push(Heap* h, int node, int dist) {
    int i = ++h->size;
    h->arr[i] = (Pair){node, dist};

    while (i > 1 && h->arr[i].dist < h->arr[i/2].dist) {
        swap(&h->arr[i], &h->arr[i/2]);
        i /= 2;
    }
}

Pair pop(Heap* h) {
    Pair top = h->arr[1];
    h->arr[1] = h->arr[h->size--];

    int i = 1;
    while (2*i <= h->size) {
        int smallest = i;
        int l = 2*i, r = 2*i+1;

        if (l <= h->size && h->arr[l].dist < h->arr[smallest].dist)
            smallest = l;
        if (r <= h->size && h->arr[r].dist < h->arr[smallest].dist)
            smallest = r;

        if (smallest == i) break;

        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }

    return top;
}

// Dijkstra
void dijkstra(int n, int src, int dist[]) {
    for (int i = 1; i <= n; i++) dist[i] = INF;

    Heap h = {0};
    dist[src] = 0;
    push(&h, src, 0);

    while (h.size > 0) {
        Pair cur = pop(&h);
        int u = cur.node;

        if (cur.dist > dist[u]) continue;

        for (Node* temp = adj[u]; temp != NULL; temp = temp->next) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
        }
    }
}
